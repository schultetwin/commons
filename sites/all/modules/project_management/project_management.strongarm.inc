<?php

/**
 * Implementation of hook_strongarm().
 */
function project_management_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'project_directory_issues';
  $strongarm->value = 'issues';

  $export['project_directory_issues'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'project_issue_auto_close_days';
  $strongarm->value = '14';

  $export['project_issue_auto_close_days'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'project_issue_autocomplete';
  $strongarm->value = '0';

  $export['project_issue_autocomplete'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'project_issue_default_components';
  $strongarm->value = 'Code
Miscellaneous
User interface';

  $export['project_issue_default_components'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'project_issue_default_state';
  $strongarm->value = '1';

  $export['project_issue_default_state'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'project_issue_followup_user';
  $strongarm->value = '';

  $export['project_issue_followup_user'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'project_issue_reply_to';
  $strongarm->value = '0';

  $export['project_issue_reply_to'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'project_issue_show_comment_signatures';
  $strongarm->value = 0;

  $export['project_issue_show_comment_signatures'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'project_issue_site_help';
  $strongarm->value = '';

  $export['project_issue_site_help'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'project_vocabulary';
  $strongarm->value = '8';

  $export['project_vocabulary'] = $strongarm;
  return $export;
}
