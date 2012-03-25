<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function jrst_position_application_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_app_position
  $groups['application-group_app_position'] = array(
    'group_type' => 'standard',
    'type_name' => 'application',
    'group_name' => 'group_app_position',
    'label' => 'Position',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '-4',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'description' => '',
        '5' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '-4',
    'fields' => array(
      '0' => 'field_app_position',
    ),
  );

  // Exported group: group_application
  $groups['application-group_application'] = array(
    'group_type' => 'standard',
    'type_name' => 'application',
    'group_name' => 'group_application',
    'label' => 'Application Materials',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => 'Please attach a short form (2 page) CV listing your relevant experience for the position(s) below.',
      ),
      'display' => array(
        'weight' => '-2',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'description' => '',
        '5' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
    ),
    'weight' => '-3',
    'fields' => array(
      '0' => 'field_app_cv',
      '1' => 'field_app_resume',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Application Materials');
  t('Position');

  return $groups;
}
