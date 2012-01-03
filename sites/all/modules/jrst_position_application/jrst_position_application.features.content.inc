<?php

/**
 * Implementation of hook_content_default_fields().
 */
function jrst_position_application_content_default_fields() {
  $fields = array();

  // Exported field: field_app_cv
  $fields['application-field_app_cv'] = array(
    'field_name' => 'field_app_cv',
    'type_name' => 'application',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
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
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'filefield_private_downloads' => 0,
    'filefield_private_content_disposition' => '',
    'widget' => array(
      'file_extensions' => 'pdf txt doc docx',
      'file_path' => '[user]/[date-in-tz]/cv',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'insert' => 0,
      'insert_styles' => array(
        'auto' => 0,
        'link' => 0,
        'image' => 0,
        'imagecache_Featured' => 0,
        'imagecache_group_images' => 0,
        'imagecache_group_images_featured' => 0,
        'imagecache_group_images_medium' => 0,
        'imagecache_group_images_showcase' => 0,
        'imagecache_group_images_thumb' => 0,
        'imagecache_issue_main_page' => 0,
        'imagecache_member_list_image' => 0,
        'imagecache_profile_pictures' => 0,
        'imagecache_Small' => 0,
        'imagecache_user_picture_meta' => 0,
      ),
      'insert_default' => 'auto',
      'insert_class' => '',
      'insert_width' => '',
      'label' => 'Curriculum vitae',
      'weight' => '-2',
      'description' => '',
      'type' => 'filefield_widget',
      'module' => 'filefield',
      'roles' => array(
        '1' => 0,
        '2' => 0,
        '6' => 0,
        '7' => 0,
        '5' => 0,
      ),
    ),
  );

  // Exported field: field_app_position
  $fields['application-field_app_position'] = array(
    'field_name' => 'field_app_position',
    'type_name' => 'application',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
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
    'type' => 'nodereference',
    'required' => '1',
    'multiple' => '1',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'application' => 0,
      'article' => 0,
      'blog' => 0,
      'discussion' => 0,
      'document' => 0,
      'event' => 0,
      'group' => 0,
      'project_issue' => 0,
      'job_posting' => 0,
      'issue' => 0,
      'notice' => 0,
      'page' => 0,
      'podcast' => 0,
      'poll' => 0,
      'position' => 0,
      'project_project' => 0,
      'support_ticket' => 0,
      'webform' => 0,
      'wiki' => 0,
    ),
    'advanced_view' => 'positions_open',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'nid' => '',
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
      'label' => 'Position',
      'weight' => '-4',
      'description' => 'Select the positions you wish to apply for.',
      'type' => 'nodereference_buttons',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_app_resume
  $fields['application-field_app_resume'] = array(
    'field_name' => 'field_app_resume',
    'type_name' => 'application',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
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
    'type' => 'filefield',
    'required' => '1',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'filefield_private_downloads' => 0,
    'filefield_private_content_disposition' => '',
    'widget' => array(
      'file_extensions' => 'pdf txt doc docx',
      'file_path' => '[user]/[date-in-tz]/resume',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'insert' => 0,
      'insert_styles' => array(
        'auto' => 0,
        'link' => 0,
        'image' => 0,
        'imagecache_Featured' => 0,
        'imagecache_group_images' => 0,
        'imagecache_group_images_featured' => 0,
        'imagecache_group_images_medium' => 0,
        'imagecache_group_images_showcase' => 0,
        'imagecache_group_images_thumb' => 0,
        'imagecache_issue_main_page' => 0,
        'imagecache_member_list_image' => 0,
        'imagecache_profile_pictures' => 0,
        'imagecache_Small' => 0,
        'imagecache_user_picture_meta' => 0,
      ),
      'insert_default' => 'auto',
      'insert_class' => '',
      'insert_width' => '',
      'roles' => array(
        '1' => 0,
        '2' => 0,
        '6' => 0,
        '7' => 0,
        '5' => 0,
      ),
      'label' => 'Resume',
      'weight' => '-3',
      'description' => 'Upload your pdf',
      'type' => 'filefield_widget',
      'module' => 'filefield',
    ),
  );

  // Exported field: field_position_close_date
  $fields['position-field_position_close_date'] = array(
    'field_name' => 'field_position_close_date',
    'type_name' => 'position',
    'display_settings' => array(
      'weight' => '-4',
      'parent' => '',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
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
    'type' => 'date',
    'required' => '0',
    'multiple' => '0',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
      'month' => 'month',
      'day' => 'day',
    ),
    'timezone_db' => '',
    'tz_handling' => 'none',
    'todate' => '',
    'repeat' => 0,
    'repeat_collapsed' => '',
    'default_format' => 'medium',
    'widget' => array(
      'default_value' => 'blank',
      'default_value_code' => '',
      'default_value2' => 'same',
      'default_value_code2' => '',
      'input_format' => 'm/d/Y - H:i',
      'input_format_custom' => '',
      'increment' => '1',
      'text_parts' => array(),
      'year_range' => '-1:+10',
      'label_position' => 'above',
      'roles' => array(
        '1' => 0,
        '2' => 0,
        '6' => 0,
        '7' => 0,
        '5' => 0,
      ),
      'label' => 'Closing Date',
      'weight' => '-4',
      'description' => '',
      'type' => 'date_popup',
      'module' => 'date',
    ),
  );

  // Exported field: field_position_group
  $fields['position-field_position_group'] = array(
    'field_name' => 'field_position_group',
    'type_name' => 'position',
    'display_settings' => array(
      'weight' => '-3',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
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
    'type' => 'nodereference',
    'required' => '0',
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'group' => 'group',
      'application' => 0,
      'article' => 0,
      'blog' => 0,
      'discussion' => 0,
      'document' => 0,
      'event' => 0,
      'project_issue' => 0,
      'job_posting' => 0,
      'issue' => 0,
      'notice' => 0,
      'page' => 0,
      'podcast' => 0,
      'poll' => 0,
      'position' => 0,
      'project_project' => 0,
      'support_ticket' => 0,
      'webform' => 0,
      'wiki' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'nid' => '',
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
      'label' => 'Group',
      'weight' => '-3',
      'description' => '(Optional) If this position is part of a group you may select that group here.',
      'type' => 'nodereference_select',
      'module' => 'nodereference',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Closing Date');
  t('Curriculum vitae');
  t('Group');
  t('Position');
  t('Resume');

  return $fields;
}
