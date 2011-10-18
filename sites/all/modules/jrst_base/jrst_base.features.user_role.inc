<?php

/**
 * Implementation of hook_user_default_roles().
 */
function jrst_base_user_default_roles() {
  $roles = array();

  // Exported role: anonymous user
  $roles['anonymous user'] = array(
    'name' => 'anonymous user',
  );

  // Exported role: associate editor
  $roles['associate editor'] = array(
    'name' => 'associate editor',
  );

  // Exported role: authenticated user
  $roles['authenticated user'] = array(
    'name' => 'authenticated user',
  );

  // Exported role: eb_member
  $roles['eb_member'] = array(
    'name' => 'eb_member',
  );

  // Exported role: editor
  $roles['editor'] = array(
    'name' => 'editor',
  );

  // Exported role: reviewer
  $roles['reviewer'] = array(
    'name' => 'reviewer',
  );

  return $roles;
}
