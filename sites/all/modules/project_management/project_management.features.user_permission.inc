<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function project_management_user_default_permissions() {
  $permissions = array();

  // Exported permission: access issue statistics
  $permissions['access issue statistics'] = array(
    'name' => 'access issue statistics',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: access own project issues
  $permissions['access own project issues'] = array(
    'name' => 'access own project issues',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: access own projects
  $permissions['access own projects'] = array(
    'name' => 'access own projects',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: access project issues
  $permissions['access project issues'] = array(
    'name' => 'access project issues',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: access projects
  $permissions['access projects'] = array(
    'name' => 'access projects',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: administer projects
  $permissions['administer projects'] = array(
    'name' => 'administer projects',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: assign and be assigned project issues
  $permissions['assign and be assigned project issues'] = array(
    'name' => 'assign and be assigned project issues',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: browse project listings
  $permissions['browse project listings'] = array(
    'name' => 'browse project listings',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: create full projects
  $permissions['create full projects'] = array(
    'name' => 'create full projects',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: create project issues
  $permissions['create project issues'] = array(
    'name' => 'create project issues',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: create sandbox projects
  $permissions['create sandbox projects'] = array(
    'name' => 'create sandbox projects',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: delete any projects
  $permissions['delete any projects'] = array(
    'name' => 'delete any projects',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: delete own projects
  $permissions['delete own projects'] = array(
    'name' => 'delete own projects',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: edit any project issues
  $permissions['edit any project issues'] = array(
    'name' => 'edit any project issues',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: edit own project issues
  $permissions['edit own project issues'] = array(
    'name' => 'edit own project issues',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: set issue status active
  $permissions['set issue status active'] = array(
    'name' => 'set issue status active',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: set issue status duplicate
  $permissions['set issue status duplicate'] = array(
    'name' => 'set issue status duplicate',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: set issue status fixed
  $permissions['set issue status fixed'] = array(
    'name' => 'set issue status fixed',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: set issue status needs review
  $permissions['set issue status needs review'] = array(
    'name' => 'set issue status needs review',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: set issue status needs work
  $permissions['set issue status needs work'] = array(
    'name' => 'set issue status needs work',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: set issue status postponed
  $permissions['set issue status postponed'] = array(
    'name' => 'set issue status postponed',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: set issue status ready to commit
  $permissions['set issue status ready to commit'] = array(
    'name' => 'set issue status ready to commit',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  return $permissions;
}
