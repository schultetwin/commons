<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function jrst_position_application_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function jrst_position_application_node_info() {
  $items = array(
    'application' => array(
      'name' => t('Application'),
      'module' => 'features',
      'description' => t('You may apply for one or multiple positions through this single application. Simply select the applications that you wish to apply for. You should include information in your application addressing all desired qualifications, which can be viewed be clicking the links below.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
    'position' => array(
      'name' => t('Position'),
      'module' => 'features',
      'description' => t('A position that people can apply for.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Qualifications'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function jrst_position_application_views_api() {
  return array(
    'api' => '2',
  );
}
