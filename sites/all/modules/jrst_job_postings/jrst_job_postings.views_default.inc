<?php

/**
 * Implementation of hook_views_default_views().
 */
function jrst_job_postings_views_default_views() {
  $views = array();

  // Exported view: job_posting
  $view = new view;
  $view->name = 'job_posting';
  $view->description = 'Job Posting Search';
  $view->tag = '';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('filters', array(
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'job_posting' => 'job_posting',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
    ),
    'field_position_deadline_value' => array(
      'operator' => '>=',
      'value' => array(
        'value' => NULL,
        'min' => NULL,
        'max' => NULL,
        'default_date' => 'now + 1 month',
        'default_to_date' => '',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'date_fields' => array(
        'node_data_field_position_deadline.field_position_deadline_value' => 'node_data_field_position_deadline.field_position_deadline_value',
      ),
      'date_method' => 'OR',
      'granularity' => 'day',
      'form_type' => 'date_select',
      'default_date' => 'now + 1 month',
      'default_to_date' => '',
      'year_range' => '-0:+3',
      'id' => 'field_position_deadline_value',
      'table' => 'node_data_field_position_deadline',
      'field' => 'field_position_deadline_value',
      'relationship' => 'none',
    ),
    'field_position_type_value' => array(
      'operator' => '=',
      'value' => '',
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'field_position_type_value_op',
        'identifier' => 'field_position_type_value',
        'label' => 'Position Type',
        'optional' => 1,
        'remember' => 1,
      ),
      'case' => 1,
      'id' => 'field_position_type_value',
      'table' => 'node_data_field_position_type',
      'field' => 'field_position_type_value',
      'relationship' => 'none',
    ),
    'status' => array(
      'operator' => '=',
      'value' => '1',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status',
      'table' => 'node',
      'field' => 'status',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('title', 'Job Postings');
  $handler->override_option('header', 'Search through jobs that are available online.');
  $handler->override_option('header_format', '1');
  $handler->override_option('header_empty', 1);
  $handler->override_option('empty', 'No available jobs');
  $handler->override_option('empty_format', '1');
  $handler->override_option('row_plugin', 'node');
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->override_option('path', 'opportunities/jobpostings');
  $handler->override_option('menu', array(
    'type' => 'default tab',
    'title' => 'Job Postings',
    'description' => '',
    'weight' => '50',
    'name' => 'primary-links',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'normal',
    'title' => 'Opportunities',
    'description' => '',
    'weight' => '0',
    'name' => 'primary-links',
  ));

  $views[$view->name] = $view;

  return $views;
}
