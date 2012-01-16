<?php

/**
 * Implementation of hook_views_handlers().
 */
function jrst_fb_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'jrst_fb') . '/views/',
    ),
    'handlers' => array(
      'jrst_feedback_link_field_handler' => array(
        'parent' => 'views_handler_field_custom'
      ),
      'jrst_view_feedback_link_field_handler' => array(
        'parent' => 'views_handler_field_custom'
      ),
    ),
  );
}

/**
 * Implementation of hook_views_data().
 */
function jrst_fb_views_data() {
  $data['users']['jrst_feedback'] = array(
    'title' => t('User Feedback Link'),
    'help' => t('A link for users to leave feedback'),
    'field' => array(
      'handler' => 'jrst_feedback_link_field_handler',
    ),
  );
  $data['users']['jrst_view_issues'] = array(
    'title' => t('JRST Admin View Issues'),
    'help' => t('For user with proper permissions, view feedback'),
    'field' => array(
      'handler' => 'jrst_view_feedback_link_field_handler',
    ),
  );

  return $data;
}

