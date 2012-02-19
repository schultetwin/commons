<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function journal_article_jrst_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
  elseif ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => 1);
  }
  elseif ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => 2);
  }
  elseif ($module == "mailhandler" && $api == "mailhandler_mailbox") {
    return array("version" => 1);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function journal_article_jrst_imagecache_default_presets() {
  $items = array(
    'issue_cover_small' => array(
      'presetname' => 'issue_cover_small',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '33%',
            'height' => '33%',
            'upscale' => 0,
          ),
        ),
      ),
    ),
    'issue_main_page' => array(
      'presetname' => 'issue_main_page',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale_and_crop',
          'data' => array(
            'width' => '300',
            'height' => '350',
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_node_info().
 */
function journal_article_jrst_node_info() {
  $items = array(
    'article' => array(
      'name' => t('Article'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Abstract'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'issue' => array(
      'name' => t('Journal Issue'),
      'module' => 'features',
      'description' => t('A issue is a collection of articles published on a somewhat regular schedule'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function journal_article_jrst_views_api() {
  return array(
    'api' => '2',
  );
}
