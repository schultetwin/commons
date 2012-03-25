<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function jrst_custom_profile_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'jrst-profile-global';
  $context->description = 'User profile about page when viewed by any user';
  $context->tag = 'Profile';
  $context->conditions = array();
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'commons_profile-image_links' => array(
          'module' => 'commons_profile',
          'delta' => 'image_links',
          'region' => 'sidebar_first',
          'weight' => 0,
        ),
        'views-de49b4060a46244663d71ca8265300bc' => array(
          'module' => 'views',
          'delta' => 'de49b4060a46244663d71ca8265300bc',
          'region' => 'sidebar_last',
          'weight' => 0,
        ),
        'views-jrst_user_terms_profile-block_1' => array(
          'module' => 'views',
          'delta' => 'jrst_user_terms_profile-block_1',
          'region' => 'sidebar_last',
          'weight' => 1,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Profile');
  t('User profile about page when viewed by any user');

  $export['jrst-profile-global'] = $context;
  return $export;
}
