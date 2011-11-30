<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function jrst_feedback_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer support
  $permissions['administer support'] = array(
    'name' => 'administer support',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: administer support overview
  $permissions['administer support overview'] = array(
    'name' => 'administer support overview',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: bulk add issues
  $permissions['bulk add issues'] = array(
    'name' => 'bulk add issues',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: can administer state
  $permissions['can administer state'] = array(
    'name' => 'can administer state',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: can assign tickets to any user
  $permissions['can assign tickets to any user'] = array(
    'name' => 'can assign tickets to any user',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: can assign tickets to self
  $permissions['can assign tickets to self'] = array(
    'name' => 'can assign tickets to self',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: can select client
  $permissions['can select client'] = array(
    'name' => 'can select client',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: can select priority
  $permissions['can select priority'] = array(
    'name' => 'can select priority',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: can select state
  $permissions['can select state'] = array(
    'name' => 'can select state',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: can subscribe other users to notifications
  $permissions['can subscribe other users to notifications'] = array(
    'name' => 'can subscribe other users to notifications',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: can suppress notification
  $permissions['can suppress notification'] = array(
    'name' => 'can suppress notification',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: create tickets
  $permissions['create tickets'] = array(
    'name' => 'create tickets',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'site admin',
    ),
  );

  // Exported permission: delete any ticket
  $permissions['delete any ticket'] = array(
    'name' => 'delete any ticket',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: delete own tickets
  $permissions['delete own tickets'] = array(
    'name' => 'delete own tickets',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: download mail via support/fetch
  $permissions['download mail via support/fetch'] = array(
    'name' => 'download mail via support/fetch',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: edit any ticket
  $permissions['edit any ticket'] = array(
    'name' => 'edit any ticket',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: edit multiple tickets
  $permissions['edit multiple tickets'] = array(
    'name' => 'edit multiple tickets',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: edit own tickets
  $permissions['edit own tickets'] = array(
    'name' => 'edit own tickets',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'site admin',
    ),
  );

  // Exported permission: jrst give site feedback
  $permissions['jrst give site feedback'] = array(
    'name' => 'jrst give site feedback',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: move ticket
  $permissions['move ticket'] = array(
    'name' => 'move ticket',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: view client overview
  $permissions['view client overview'] = array(
    'name' => 'view client overview',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: view other users tickets
  $permissions['view other users tickets'] = array(
    'name' => 'view other users tickets',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: view user overview
  $permissions['view user overview'] = array(
    'name' => 'view user overview',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  return $permissions;
}
