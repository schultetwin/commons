<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function jrst_base_user_default_permissions() {
  $permissions = array();

  // Exported permission: Allow Reordering
  $permissions['Allow Reordering'] = array(
    'name' => 'Allow Reordering',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: Use PHP input for field settings (dangerous - grant with care)
  $permissions['Use PHP input for field settings (dangerous - grant with care)'] = array(
    'name' => 'Use PHP input for field settings (dangerous - grant with care)',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: access backup and migrate
  $permissions['access backup and migrate'] = array(
    'name' => 'access backup and migrate',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: access backup files
  $permissions['access backup files'] = array(
    'name' => 'access backup files',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: access devel information
  $permissions['access devel information'] = array(
    'name' => 'access devel information',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: access own webform results
  $permissions['access own webform results'] = array(
    'name' => 'access own webform results',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'site admin',
    ),
  );

  // Exported permission: access own webform submissions
  $permissions['access own webform submissions'] = array(
    'name' => 'access own webform submissions',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'site admin',
    ),
  );

  // Exported permission: access printer-friendly version
  $permissions['access printer-friendly version'] = array(
    'name' => 'access printer-friendly version',
    'roles' => array(
      '0' => 'PAC-NARSTBoD',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'site admin',
    ),
  );

  // Exported permission: access site-wide contact form
  $permissions['access site-wide contact form'] = array(
    'name' => 'access site-wide contact form',
    'roles' => array(
      '0' => 'PAC-NARSTBoD',
      '1' => 'authenticated user',
      '2' => 'site admin',
    ),
  );

  // Exported permission: access workflow summary views
  $permissions['access workflow summary views'] = array(
    'name' => 'access workflow summary views',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: add content to books
  $permissions['add content to books'] = array(
    'name' => 'add content to books',
    'roles' => array(
      '0' => 'editor',
      '1' => 'jrst staff',
      '2' => 'site admin',
    ),
  );

  // Exported permission: administer CAPTCHA settings
  $permissions['administer CAPTCHA settings'] = array(
    'name' => 'administer CAPTCHA settings',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: administer backup and migrate
  $permissions['administer backup and migrate'] = array(
    'name' => 'administer backup and migrate',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: administer book outlines
  $permissions['administer book outlines'] = array(
    'name' => 'administer book outlines',
    'roles' => array(
      '0' => 'editor',
      '1' => 'jrst staff',
      '2' => 'site admin',
    ),
  );

  // Exported permission: administer chart
  $permissions['administer chart'] = array(
    'name' => 'administer chart',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: administer custom breadcrumbs
  $permissions['administer custom breadcrumbs'] = array(
    'name' => 'administer custom breadcrumbs',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: administer feeds
  $permissions['administer feeds'] = array(
    'name' => 'administer feeds',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: administer feeds_tamper
  $permissions['administer feeds_tamper'] = array(
    'name' => 'administer feeds_tamper',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: administer mailhandler
  $permissions['administer mailhandler'] = array(
    'name' => 'administer mailhandler',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: administer user locations
  $permissions['administer user locations'] = array(
    'name' => 'administer user locations',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: administer workflow
  $permissions['administer workflow'] = array(
    'name' => 'administer workflow',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: bypass requirement that fields are unique
  $permissions['bypass requirement that fields are unique'] = array(
    'name' => 'bypass requirement that fields are unique',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: create book content
  $permissions['create book content'] = array(
    'name' => 'create book content',
    'roles' => array(
      '0' => 'editor',
      '1' => 'jrst staff',
      '2' => 'site admin',
    ),
  );

  // Exported permission: create new books
  $permissions['create new books'] = array(
    'name' => 'create new books',
    'roles' => array(
      '0' => 'editor',
      '1' => 'jrst staff',
      '2' => 'site admin',
    ),
  );

  // Exported permission: create url aliases
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      '0' => 'editor',
      '1' => 'jrst staff',
      '2' => 'site admin',
    ),
  );

  // Exported permission: create webform content
  $permissions['create webform content'] = array(
    'name' => 'create webform content',
    'roles' => array(
      '0' => 'editor',
      '1' => 'jrst staff',
      '2' => 'site admin',
    ),
  );

  // Exported permission: delete all webform submissions
  $permissions['delete all webform submissions'] = array(
    'name' => 'delete all webform submissions',
    'roles' => array(
      '0' => 'editor',
      '1' => 'jrst staff',
      '2' => 'site admin',
    ),
  );

  // Exported permission: delete any book content
  $permissions['delete any book content'] = array(
    'name' => 'delete any book content',
    'roles' => array(
      '0' => 'editor',
      '1' => 'jrst staff',
      '2' => 'site admin',
    ),
  );

  // Exported permission: delete any webform content
  $permissions['delete any webform content'] = array(
    'name' => 'delete any webform content',
    'roles' => array(
      '0' => 'editor',
      '1' => 'jrst staff',
      '2' => 'site admin',
    ),
  );

  // Exported permission: delete backup files
  $permissions['delete backup files'] = array(
    'name' => 'delete backup files',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: delete own book content
  $permissions['delete own book content'] = array(
    'name' => 'delete own book content',
    'roles' => array(
      '0' => 'editor',
      '1' => 'jrst staff',
      '2' => 'site admin',
    ),
  );

  // Exported permission: delete own webform content
  $permissions['delete own webform content'] = array(
    'name' => 'delete own webform content',
    'roles' => array(
      '0' => 'editor',
      '1' => 'jrst staff',
      '2' => 'site admin',
    ),
  );

  // Exported permission: delete own webform submissions
  $permissions['delete own webform submissions'] = array(
    'name' => 'delete own webform submissions',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'site admin',
    ),
  );

  // Exported permission: designate fields as unique
  $permissions['designate fields as unique'] = array(
    'name' => 'designate fields as unique',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: display source code
  $permissions['display source code'] = array(
    'name' => 'display source code',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: edit all webform submissions
  $permissions['edit all webform submissions'] = array(
    'name' => 'edit all webform submissions',
    'roles' => array(
      '0' => 'editor',
      '1' => 'jrst staff',
      '2' => 'site admin',
    ),
  );

  // Exported permission: edit any book content
  $permissions['edit any book content'] = array(
    'name' => 'edit any book content',
    'roles' => array(
      '0' => 'editor',
      '1' => 'jrst staff',
      '2' => 'site admin',
    ),
  );

  // Exported permission: edit any webform content
  $permissions['edit any webform content'] = array(
    'name' => 'edit any webform content',
    'roles' => array(
      '0' => 'editor',
      '1' => 'jrst staff',
      '2' => 'site admin',
    ),
  );

  // Exported permission: edit field_poll_body
  $permissions['edit field_poll_body'] = array(
    'name' => 'edit field_poll_body',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'site admin',
    ),
  );

  // Exported permission: edit own book content
  $permissions['edit own book content'] = array(
    'name' => 'edit own book content',
    'roles' => array(
      '0' => 'editor',
      '1' => 'jrst staff',
      '2' => 'site admin',
    ),
  );

  // Exported permission: edit own webform content
  $permissions['edit own webform content'] = array(
    'name' => 'edit own webform content',
    'roles' => array(
      '0' => 'editor',
      '1' => 'jrst staff',
      '2' => 'site admin',
    ),
  );

  // Exported permission: edit own webform submissions
  $permissions['edit own webform submissions'] = array(
    'name' => 'edit own webform submissions',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'site admin',
    ),
  );

  // Exported permission: execute php code
  $permissions['execute php code'] = array(
    'name' => 'execute php code',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: force password change
  $permissions['force password change'] = array(
    'name' => 'force password change',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: manage all groups titles
  $permissions['manage all groups titles'] = array(
    'name' => 'manage all groups titles',
    'roles' => array(
      '0' => 'editor',
      '1' => 'jrst staff',
      '2' => 'site admin',
    ),
  );

  // Exported permission: manage own og title
  $permissions['manage own og title'] = array(
    'name' => 'manage own og title',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'editor',
      '2' => 'jrst staff',
      '3' => 'site admin',
    ),
  );

  // Exported permission: notify of path changes
  $permissions['notify of path changes'] = array(
    'name' => 'notify of path changes',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: perform backup
  $permissions['perform backup'] = array(
    'name' => 'perform backup',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: restore from backup
  $permissions['restore from backup'] = array(
    'name' => 'restore from backup',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: schedule workflow transitions
  $permissions['schedule workflow transitions'] = array(
    'name' => 'schedule workflow transitions',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: set own user location
  $permissions['set own user location'] = array(
    'name' => 'set own user location',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'site admin',
    ),
  );

  // Exported permission: skip CAPTCHA
  $permissions['skip CAPTCHA'] = array(
    'name' => 'skip CAPTCHA',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'site admin',
    ),
  );

  // Exported permission: submit latitude/longitude
  $permissions['submit latitude/longitude'] = array(
    'name' => 'submit latitude/longitude',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'site admin',
    ),
  );

  // Exported permission: switch users
  $permissions['switch users'] = array(
    'name' => 'switch users',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: tamper mail_impor
  $permissions['tamper mail_impor'] = array(
    'name' => 'tamper mail_impor',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: unblock expired accounts
  $permissions['unblock expired accounts'] = array(
    'name' => 'unblock expired accounts',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: upload files
  $permissions['upload files'] = array(
    'name' => 'upload files',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: upload files to comments
  $permissions['upload files to comments'] = array(
    'name' => 'upload files to comments',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: use PHP for title patterns
  $permissions['use PHP for title patterns'] = array(
    'name' => 'use PHP for title patterns',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: use default thumbnail
  $permissions['use default thumbnail'] = array(
    'name' => 'use default thumbnail',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: use php in custom breadcrumbs
  $permissions['use php in custom breadcrumbs'] = array(
    'name' => 'use php in custom breadcrumbs',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: use realname
  $permissions['use realname'] = array(
    'name' => 'use realname',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'site admin',
    ),
  );

  // Exported permission: view all user locations
  $permissions['view all user locations'] = array(
    'name' => 'view all user locations',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'site admin',
    ),
  );

  // Exported permission: view date repeats
  $permissions['view date repeats'] = array(
    'name' => 'view date repeats',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'site admin',
    ),
  );

  // Exported permission: view field_poll_body
  $permissions['view field_poll_body'] = array(
    'name' => 'view field_poll_body',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'site admin',
    ),
  );

  // Exported permission: view files uploaded to comments
  $permissions['view files uploaded to comments'] = array(
    'name' => 'view files uploaded to comments',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: view imagecache group_images_featured
  $permissions['view imagecache group_images_featured'] = array(
    'name' => 'view imagecache group_images_featured',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'site admin',
    ),
  );

  // Exported permission: view imagecache group_images_medium
  $permissions['view imagecache group_images_medium'] = array(
    'name' => 'view imagecache group_images_medium',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'site admin',
    ),
  );

  // Exported permission: view location directory
  $permissions['view location directory'] = array(
    'name' => 'view location directory',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: view node location table
  $permissions['view node location table'] = array(
    'name' => 'view node location table',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: view own user location
  $permissions['view own user location'] = array(
    'name' => 'view own user location',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
      '2' => 'site admin',
    ),
  );

  // Exported permission: view uploaded files
  $permissions['view uploaded files'] = array(
    'name' => 'view uploaded files',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  // Exported permission: view user location table
  $permissions['view user location table'] = array(
    'name' => 'view user location table',
    'roles' => array(
      '0' => 'site admin',
    ),
  );

  return $permissions;
}
