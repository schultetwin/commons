<?php

/**
 * Implementation of hook_content_default_fields().
 */
function jrst_overrides_content_default_fields() {
  $fields = array();

  // Exported field: field_event_attachments
  $fields['event-field_event_attachments'] = array(
    'field_name' => 'field_event_attachments',
    'type_name' => 'event',
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
    'multiple' => '1',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'filefield_private_downloads' => 0,
    'filefield_private_content_disposition' => '',
    'widget' => array(
      'file_extensions' => 'txt pdf doc docx xlsx xls png jpg',
      'file_path' => 'events/attachments',
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
        'imagecache_member_list_image' => 0,
        'imagecache_profile_pictures' => 0,
        'imagecache_Small' => 0,
        'imagecache_user_picture_meta' => 0,
      ),
      'insert_default' => 'auto',
      'insert_class' => '',
      'insert_width' => '',
      'label' => 'Attachments',
      'weight' => '-2',
      'description' => 'Upload files for this event. As an example, you may upload an agenda for a meeting.',
      'type' => 'filefield_widget',
      'module' => 'filefield',
      'roles' => array(
        '1' => 0,
        '2' => 0,
        '6' => 0,
        '3' => 0,
        '4' => 0,
        '7' => 0,
        '8' => 0,
        '5' => 0,
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Attachments');

  return $fields;
}
