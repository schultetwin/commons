<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function jrst_pm_user_default_permissions() {
  $permissions = array();

  // Exported permission: access jrst tickets
  $permissions['access jrst tickets'] = array(
    'name' => 'access jrst tickets',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  return $permissions;
}
