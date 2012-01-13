<?php

/**
 * Implementation of hook_content_default_fields().
 */
function jrst_frontpage_content_default_fields() {
  $fields = array();

  // Exported field: field_notice_highlighted
  $fields['notice-field_notice_highlighted'] = array(
    'field_name' => 'field_notice_highlighted',
    'type_name' => 'notice',
    'display_settings' => array(
      'weight' => '-2',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => 'normal|Normal
highlighted|Highlighted',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => 'normal',
        ),
      ),
      'default_value_php' => NULL,
      'roles' => array(
        '1' => 0,
        '2' => 0,
        '6' => 0,
        '7' => 0,
        '5' => 0,
      ),
      'label' => 'Highlighted',
      'weight' => '-2',
      'description' => 'A notice marked as "highlighted" will appear highlighted on the front page.',
      'type' => 'optionwidgets_onoff',
      'module' => 'optionwidgets',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Highlighted');

  return $fields;
}
