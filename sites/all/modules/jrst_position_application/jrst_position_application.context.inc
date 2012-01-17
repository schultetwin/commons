<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function jrst_position_application_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'jrst_position_app';
  $context->description = '';
  $context->tag = 'JRST';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'position' => 'position',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        'opportunities/positions' => 'opportunities/positions',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'jrst_custom-jrst_position_app' => array(
          'module' => 'jrst_custom',
          'delta' => 'jrst_position_app',
          'region' => 'sidebar_last',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('JRST');

  $export['jrst_position_app'] = $context;
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'jrst_position_app_ajax';
  $context->description = '';
  $context->tag = 'JRST';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'application' => 'application',
      ),
      'options' => array(
        'node_form' => '2',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-positions_open-block_1' => array(
          'module' => 'views',
          'delta' => 'positions_open-block_1',
          'region' => 'sidebar_last',
          'weight' => 0,
        ),
        'views-jrst_app_pos_info-block_1' => array(
          'module' => 'views',
          'delta' => 'jrst_app_pos_info-block_1',
          'region' => 'sidebar_last',
          'weight' => 1,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('JRST');

  $export['jrst_position_app_ajax'] = $context;
  return $export;
}
