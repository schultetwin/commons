<?php

/**
 * Implementation of hook_user_default_roles().
 */
function jrst_base_user_default_roles() {
  $roles = array();

  // Exported role: PAC-NARSTBoD
  $roles['PAC-NARSTBoD'] = array(
    'name' => 'PAC-NARSTBoD',
  );

  // Exported role: anonymous user
  $roles['anonymous user'] = array(
    'name' => 'anonymous user',
  );

  // Exported role: authenticated user
  $roles['authenticated user'] = array(
    'name' => 'authenticated user',
  );

  // Exported role: editor
  $roles['editor'] = array(
    'name' => 'editor',
  );

  // Exported role: jrst staff
  $roles['jrst staff'] = array(
    'name' => 'jrst staff',
  );

  // Exported role: narst staff
  $roles['narst staff'] = array(
    'name' => 'narst staff',
  );

  return $roles;
}
