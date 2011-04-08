<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function commons_invite_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'context_ui-profile-profile-me-invite';
  $context->description = 'Add invite sender to your own profile';
  $context->tag = 'Profile';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        'context_ui-profile-profile-me' => 'context_ui-profile-profile-me',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'invite-0' => array(
          'module' => 'invite',
          'delta' => 0,
          'region' => 'sidebar_first',
          'weight' => 3,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Add invite sender to your own profile');
  t('Profile');

  $export['context_ui-profile-profile-me-invite'] = $context;
  return $export;
}