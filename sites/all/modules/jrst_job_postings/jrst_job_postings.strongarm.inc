<?php

/**
 * Implementation of hook_strongarm().
 */
function jrst_job_postings_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_job_posting';
  $strongarm->value = '0';

  $export['ant_job_posting'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_pattern_job_posting';
  $strongarm->value = '';

  $export['ant_pattern_job_posting'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_php_job_posting';
  $strongarm->value = 0;

  $export['ant_php_job_posting'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_job_posting';
  $strongarm->value = 0;

  $export['comment_anonymous_job_posting'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_job_posting';
  $strongarm->value = '3';

  $export['comment_controls_job_posting'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_job_posting';
  $strongarm->value = '4';

  $export['comment_default_mode_job_posting'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_job_posting';
  $strongarm->value = '1';

  $export['comment_default_order_job_posting'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_job_posting';
  $strongarm->value = '50';

  $export['comment_default_per_page_job_posting'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_job_posting';
  $strongarm->value = '0';

  $export['comment_form_location_job_posting'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_job_posting';
  $strongarm->value = '0';

  $export['comment_job_posting'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_job_posting';
  $strongarm->value = '1';

  $export['comment_preview_job_posting'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_job_posting';
  $strongarm->value = '1';

  $export['comment_subject_field_job_posting'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_upload_images_job_posting';
  $strongarm->value = 'none';

  $export['comment_upload_images_job_posting'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_upload_job_posting';
  $strongarm->value = '0';

  $export['comment_upload_job_posting'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_job_posting';
  $strongarm->value = array(
    'title' => '-5',
    'body_field' => '0',
    'revision_information' => '4',
    'author' => '5',
    'options' => '6',
    'comment_settings' => '8',
    'menu' => '2',
    'path' => '9',
    'attachments' => '7',
    'workflow' => '3',
  );

  $export['content_extra_weights_job_posting'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date:job_posting:full:field_position_deadline_fromto';
  $strongarm->value = 'both';

  $export['date:job_posting:full:field_position_deadline_fromto'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date:job_posting:full:field_position_deadline_multiple_from';
  $strongarm->value = '';

  $export['date:job_posting:full:field_position_deadline_multiple_from'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date:job_posting:full:field_position_deadline_multiple_number';
  $strongarm->value = '';

  $export['date:job_posting:full:field_position_deadline_multiple_number'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date:job_posting:full:field_position_deadline_multiple_to';
  $strongarm->value = '';

  $export['date:job_posting:full:field_position_deadline_multiple_to'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date:job_posting:full:field_position_deadline_show_repeat_rule';
  $strongarm->value = 'show';

  $export['date:job_posting:full:field_position_deadline_show_repeat_rule'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date:job_posting:teaser:field_position_deadline_fromto';
  $strongarm->value = 'both';

  $export['date:job_posting:teaser:field_position_deadline_fromto'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date:job_posting:teaser:field_position_deadline_multiple_from';
  $strongarm->value = '';

  $export['date:job_posting:teaser:field_position_deadline_multiple_from'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date:job_posting:teaser:field_position_deadline_multiple_number';
  $strongarm->value = '';

  $export['date:job_posting:teaser:field_position_deadline_multiple_number'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date:job_posting:teaser:field_position_deadline_multiple_to';
  $strongarm->value = '';

  $export['date:job_posting:teaser:field_position_deadline_multiple_to'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date:job_posting:teaser:field_position_deadline_show_repeat_rule';
  $strongarm->value = 'show';

  $export['date:job_posting:teaser:field_position_deadline_show_repeat_rule'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'enable_revisions_page_job_posting';
  $strongarm->value = 0;

  $export['enable_revisions_page_job_posting'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_job_posting';
  $strongarm->value = array(
    0 => 'status',
  );

  $export['node_options_job_posting'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_content_type_usage_job_posting';
  $strongarm->value = 'omitted';

  $export['og_content_type_usage_job_posting'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_max_groups_job_posting';
  $strongarm->value = '';

  $export['og_max_groups_job_posting'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_job_posting_pattern';
  $strongarm->value = '';

  $export['pathauto_node_job_posting_pattern'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_diff_inline_job_posting';
  $strongarm->value = 0;

  $export['show_diff_inline_job_posting'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_preview_changes_job_posting';
  $strongarm->value = 0;

  $export['show_preview_changes_job_posting'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unique_field_comp_job_posting';
  $strongarm->value = 'each';

  $export['unique_field_comp_job_posting'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unique_field_fields_job_posting';
  $strongarm->value = array();

  $export['unique_field_fields_job_posting'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unique_field_scope_job_posting';
  $strongarm->value = 'type';

  $export['unique_field_scope_job_posting'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unique_field_show_matches_job_posting';
  $strongarm->value = array();

  $export['unique_field_show_matches_job_posting'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_job_posting';
  $strongarm->value = '1';

  $export['upload_job_posting'] = $strongarm;
  return $export;
}
