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
  return $export;
}
