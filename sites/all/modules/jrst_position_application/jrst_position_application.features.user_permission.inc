<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function jrst_position_application_user_default_permissions() {
  $permissions = array();

  // Exported permission: create application content
  $permissions['create application content'] = array(
    'name' => 'create application content',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: create position content
  $permissions['create position content'] = array(
    'name' => 'create position content',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: delete any application content
  $permissions['delete any application content'] = array(
    'name' => 'delete any application content',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: delete any position content
  $permissions['delete any position content'] = array(
    'name' => 'delete any position content',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: delete own application content
  $permissions['delete own application content'] = array(
    'name' => 'delete own application content',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: delete own position content
  $permissions['delete own position content'] = array(
    'name' => 'delete own position content',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: edit any application content
  $permissions['edit any application content'] = array(
    'name' => 'edit any application content',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: edit any position content
  $permissions['edit any position content'] = array(
    'name' => 'edit any position content',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: edit field_app_cv
  $permissions['edit field_app_cv'] = array(
    'name' => 'edit field_app_cv',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: edit field_app_position
  $permissions['edit field_app_position'] = array(
    'name' => 'edit field_app_position',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: edit field_app_resume
  $permissions['edit field_app_resume'] = array(
    'name' => 'edit field_app_resume',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: edit field_position_close_date
  $permissions['edit field_position_close_date'] = array(
    'name' => 'edit field_position_close_date',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: edit field_position_contact
  $permissions['edit field_position_contact'] = array(
    'name' => 'edit field_position_contact',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: edit field_position_deadline
  $permissions['edit field_position_deadline'] = array(
    'name' => 'edit field_position_deadline',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: edit field_position_group
  $permissions['edit field_position_group'] = array(
    'name' => 'edit field_position_group',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: edit field_position_time
  $permissions['edit field_position_time'] = array(
    'name' => 'edit field_position_time',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'site admin',
    ),
  );

  // Exported permission: edit field_position_type
  $permissions['edit field_position_type'] = array(
    'name' => 'edit field_position_type',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'site admin',
    ),
  );

  // Exported permission: edit field_position_website
  $permissions['edit field_position_website'] = array(
    'name' => 'edit field_position_website',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'site admin',
    ),
  );

  // Exported permission: edit own application content
  $permissions['edit own application content'] = array(
    'name' => 'edit own application content',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: edit own position content
  $permissions['edit own position content'] = array(
    'name' => 'edit own position content',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: view field_app_cv
  $permissions['view field_app_cv'] = array(
    'name' => 'view field_app_cv',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: view field_app_position
  $permissions['view field_app_position'] = array(
    'name' => 'view field_app_position',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: view field_app_resume
  $permissions['view field_app_resume'] = array(
    'name' => 'view field_app_resume',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: view field_position_close_date
  $permissions['view field_position_close_date'] = array(
    'name' => 'view field_position_close_date',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: view field_position_contact
  $permissions['view field_position_contact'] = array(
    'name' => 'view field_position_contact',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: view field_position_deadline
  $permissions['view field_position_deadline'] = array(
    'name' => 'view field_position_deadline',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: view field_position_group
  $permissions['view field_position_group'] = array(
    'name' => 'view field_position_group',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: view field_position_type
  $permissions['view field_position_type'] = array(
    'name' => 'view field_position_type',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'site admin',
    ),
  );

  return $permissions;
}
