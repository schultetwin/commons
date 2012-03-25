<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function jrst_job_postings_user_default_permissions() {
  $permissions = array();

  // Exported permission: create job_posting content
  $permissions['create job_posting content'] = array(
    'name' => 'create job_posting content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'editor',
      '2' => 'jrst staff',
      '3' => 'site admin',
    ),
  );

  // Exported permission: delete any job_posting content
  $permissions['delete any job_posting content'] = array(
    'name' => 'delete any job_posting content',
    'roles' => array(
      '0' => 'editor',
      '1' => 'jrst staff',
      '2' => 'site admin',
    ),
  );

  // Exported permission: delete own job_posting content
  $permissions['delete own job_posting content'] = array(
    'name' => 'delete own job_posting content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'site admin',
    ),
  );

  // Exported permission: edit any job_posting content
  $permissions['edit any job_posting content'] = array(
    'name' => 'edit any job_posting content',
    'roles' => array(
      '0' => 'editor',
      '1' => 'jrst staff',
      '2' => 'site admin',
    ),
  );

  // Exported permission: edit own job_posting content
  $permissions['edit own job_posting content'] = array(
    'name' => 'edit own job_posting content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'editor',
      '2' => 'jrst staff',
      '3' => 'site admin',
    ),
  );

  // Exported permission: view comments for: job_posting
  $permissions['view comments for: job_posting'] = array(
    'name' => 'view comments for: job_posting',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'site admin',
    ),
  );

  return $permissions;
}
