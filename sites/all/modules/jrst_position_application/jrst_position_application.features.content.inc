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
      'weight' => '-1',
      'parent' => 'group_application',
      'label' => array(
        'format' => 'inline',
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
      'file_extensions' => 'txt doc docx pdf pages odt',
      'file_path' => 'applications/[user]/cv',
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
        'imagecache_issue_cover_small' => 0,
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
        '7' => 0,
        '8' => 0,
        '9' => 0,
        '5' => 0,
      ),
      'label' => 'Curriculum vitae',
      'weight' => '-1',
      'description' => '<br> Your application requires a cover letter describing your reasons for applying for the position(s), your vision for the NARST group you are applying for, and any other information you feel is relevant.  <br><br> You may attach your cover letter here, or type out your cover letter in the space below. ',
      'type' => 'filefield_widget',
      'module' => 'filefield',
    ),
  );

  // Exported field: field_app_position
  $fields['application-field_app_position'] = array(
    'field_name' => 'field_app_position',
    'type_name' => 'application',
    'display_settings' => array(
      'weight' => '-3',
      'parent' => 'group_app_position',
      'label' => array(
        'format' => 'above',
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
      'book' => 0,
      'discussion' => 0,
      'document' => 0,
      'event' => 0,
      'group' => 0,
      'job_posting' => 0,
      'issue' => 0,
      'notice' => 0,
      'page' => 0,
      'podcast' => 0,
      'poll' => 0,
      'position' => 0,
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
        '7' => 0,
        '8' => 0,
        '9' => 0,
        '5' => 0,
      ),
      'asm_settings' => array(
        'asm_enable' => 1,
        'add_item_target' => 'bottom',
        'sortable' => 1,
        'animate' => 0,
        'highlight' => 0,
      ),
      'label' => 'Position',
      'weight' => '-3',
      'description' => 'Select the positions you wish to apply for, ordering them in your preferred order.  Select a position from the drop down select list.  Continue to add more positions by selecting more positions from the select list.  You may drag the positions in the order you wish them to appear. ',
      'type' => 'nodereference_select',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_app_resume
  $fields['application-field_app_resume'] = array(
    'field_name' => 'field_app_resume',
    'type_name' => 'application',
    'display_settings' => array(
      'weight' => 0,
      'parent' => 'group_application',
      'label' => array(
        'format' => 'inline',
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
      'file_extensions' => 'txt doc docx pdf pages odt',
      'file_path' => 'applications/[user]',
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
        'imagecache_issue_cover_small' => 0,
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
        '7' => 0,
        '8' => 0,
        '9' => 0,
        '5' => 0,
      ),
      'label' => 'Cover Letter Upload',
      'weight' => 0,
      'description' => 'If you did not upload a cover letter, please type in your cover letter below.  Please note that if you cut and paste from Microsoft Word, you should click on <img src="http://ejrst.net/sites/default/files/Wordclip.png"> and follow the instructions to paste, to avoid garbage that Microsoft Word occasionally adds when you paste.',
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
        'exclude' => 1,
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

  // Exported field: field_position_qualifications
  $fields['position-field_position_qualifications'] = array(
    'field_name' => 'field_position_qualifications',
    'type_name' => 'position',
    'display_settings' => array(
      'weight' => '-1',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '5' => array(
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
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '1',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => '6',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_position_qualifications][0][value',
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
      'label' => 'Preferred Qualifications',
      'weight' => '-1',
      'description' => 'Enter a description of the qualifications for this position',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Closing Date');
  t('Cover Letter Upload');
  t('Curriculum vitae');
  t('Position');
  t('Preferred Qualifications');

  return $fields;
}
