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
          $nid = db_result(db_query("SELECT nid FROM {feeds_node_item} WHERE feed_nid = %d AND guid = '%s'", $source->feed_nid, $value));
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