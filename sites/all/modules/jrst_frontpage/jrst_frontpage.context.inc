<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function jrst_frontpage_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'jrst_front_page_all';
  $context->description = 'Front page for All Users';
  $context->tag = 'JRST';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-jrst_hot_discuscussions-block_1' => array(
          'module' => 'views',
          'delta' => 'jrst_hot_discuscussions-block_1',
          'region' => 'sidebar_last',
          'weight' => 0,
        ),
        'views-ab9065cf107bb52fcf5d4f1319e52c8f' => array(
          'module' => 'views',
          'delta' => 'ab9065cf107bb52fcf5d4f1319e52c8f',
          'region' => 'sidebar_last',
          'weight' => 1,
        ),
        'views-jrst_frontpage_poll-block_1' => array(
          'module' => 'views',
          'delta' => 'jrst_frontpage_poll-block_1',
          'region' => 'sidebar_last',
          'weight' => 2,
        ),
        'views-frontpage_jrst_notices-block_2' => array(
          'module' => 'views',
          'delta' => 'frontpage_jrst_notices-block_2',
          'region' => 'content_bottom',
          'weight' => 0,
        ),
        'views-frontpage_jrst_notices-block_1' => array(
          'module' => 'views',
          'delta' => 'frontpage_jrst_notices-block_1',
          'region' => 'content_bottom',
          'weight' => 1,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Front page for All Users');
  t('JRST');

  $export['jrst_front_page_all'] = $context;
  return $export;
}
