<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function jrst_job_postings_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function jrst_job_postings_node_info() {
  $items = array(
    'job_posting' => array(
      'name' => t('Job Posting'),
      'module' => 'features',
      'description' => t('A posted listing for an academic job.'),
      'has_title' => '1',
      'title_label' => t('Position'),
      'has_body' => '1',
      'body_label' => t('Description'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function jrst_job_postings_views_api() {
  return array(
    'api' => '2',
  );
}
