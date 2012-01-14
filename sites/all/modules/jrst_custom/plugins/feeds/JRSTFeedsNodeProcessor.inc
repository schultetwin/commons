<?php

/**
 * @file
 * Class definition of FeedsNodeProcessor.
 */

/**
 * Creates nodes from feed items.
 */
class JRSTFeedsNodeProcessor extends FeedsNodeProcessor {

  /**
   * Implementation of FeedsProcessor::process().
   */
  public function process(FeedsImportBatch $batch, FeedsSource $source) {

    // Keep track of processed items in this pass, set total number of items.
    $processed = 0;
    if (!$batch->getTotal(FEEDS_PROCESSING)) {
      $batch->setTotal(FEEDS_PROCESSING, count($batch->items));
    }

    while ($item = $batch->shiftItem()) {

      // Create/update if item does not exist or update existing is enabled.
      if (!($nid = $this->existingItemId($batch, $source)) || ($this->config['update_existing'] != FEEDS_SKIP_EXISTING)) {
        // Only proceed if item has actually changed.
        $hash = $this->hash($item);
        if (empty($nid) || $hash == $this->getHash($nid)) {
          continue;
        }

        $node = $this->buildNode($nid, $source->feed_nid);
        $node->feeds_node_item->hash = $hash;

        // Map and save node. If errors occur don't stop but report them.
        try {
          $this->map($batch, $node);
          if ($this->config['authorize']) {
            if (empty($node->nid)) {
              $op = 'create';
            }
            else {
              $op = 'update';
            }
            $account = user_load($node->uid);
            if (!node_access($op, $node, $account)) {
              throw new Exception('User ' . $account->uid . ' not authorized to ' . $op . ' content type ' . $node->type);
            }
          }
          node_save($node);
          if (!empty($nid)) {
            $batch->updated++;
          }
          else {
            $batch->created++;
          }
        }
        catch (Exception $e) {
          drupal_set_message($e->getMessage(), 'warning');
          watchdog('feeds', $e->getMessage(), array(), WATCHDOG_WARNING);
        }
      }

      $processed++;
      if ($processed >= variable_get('feeds_node_batch_size', FEEDS_NODE_BATCH_SIZE)) {
        $batch->setProgress(FEEDS_PROCESSING, $batch->created + $batch->updated);
        return;
      }
    }

    // Set messages.
    if ($batch->created) {
      drupal_set_message(format_plural($batch->created, 'Created @number @type node.', 'Created @number @type nodes.', array('@number' => $batch->created, '@type' => node_get_types('name', $this->config['content_type']))));
    }
    elseif ($batch->updated) {
      drupal_set_message(format_plural($batch->updated, 'Updated @number @type node.', 'Updated @number @type nodes.', array('@number' => $batch->updated, '@type' => node_get_types('name', $this->config['content_type']))));
    }
    else {
      drupal_set_message(t('There is no new content.'));
    }
    $batch->setProgress(FEEDS_PROCESSING, FEEDS_BATCH_COMPLETE);
  }

  /**
   * Get nid of an existing feed item node if available.
   */
  protected function existingItemId(FeedsImportBatch $batch, FeedsSource $source) {

    // Iterate through all unique targets and test whether they do already
    // exist in the database.
    foreach ($this->uniqueTargets($batch) as $target => $value) {
      switch ($target) {
        case 'nid':
          $nid = db_result(db_query("SELECT nid FROM {node} WHERE nid = %d", $value));
          break;
        case 'url':
          $nid = db_result(db_query("SELECT nid FROM {feeds_node_item} WHERE feed_nid = %d AND id = '%s' AND url = '%s'", $source->feed_nid, $source->id, $value));
          break;
        case 'guid':
          $nid = db_result(db_query("SELECT nid FROM {feeds_node_item} WHERE guid = '%s'", $value));
          break;
      }
      if ($nid) {
        // Return with the first nid found.
        return $nid;
      }
    }
    return 0;
  }
}
