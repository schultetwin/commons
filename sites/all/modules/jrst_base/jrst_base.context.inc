<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function jrst_base_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'jrst_global';
  $context->description = 'Show on every page';
  $context->tag = 'Sitewide';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-user_meta-block_1' => array(
          'module' => 'views',
          'delta' => 'user_meta-block_1',
          'region' => 'header',
          'weight' => 0,
        ),
        'jrst_custom-jrst_user_login' => array(
          'module' => 'jrst_custom',
          'delta' => 'jrst_user_login',
          'region' => 'header',
          'weight' => 1,
        ),
        'block-3' => array(
          'module' => 'block',
          'delta' => '3',
          'region' => 'footer',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Show on every page');
  t('Sitewide');

  $export['jrst_global'] = $context;
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'jrst_global_authenticated';
  $context->description = 'Show on every page';
  $context->tag = 'Sitewide';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
    'user' => array(
      'values' => array(
        'authenticated user' => 'authenticated user',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Show on every page');
  t('Sitewide');

  $export['jrst_global_authenticated'] = $context;
  return $export;
}
