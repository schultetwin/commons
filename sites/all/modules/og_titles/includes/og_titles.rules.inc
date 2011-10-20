<?php
/**
 * @file
 * Rules integration for the og module.
 */

/**
 * Implementation of hook_rules_event_info().
 */
function og_titles_rules_event_info() {
  return array(
    'og_titles_save' => array(
      'label' => t('User got title'),
      'help' => t("A user got a title in a group."),
      'arguments' => og_titles_rules_events_hook_og_arguments(),
      'module' => 'OG Titles',
    ),
 );
}

/**
 * Describes the arguments available for the groupadmin_hook().
 *
 * We pass uid and gid to rules so that the argument handlers can
 * load the full variables, but we hide them from the interface.
 */
function og_titles_rules_events_hook_og_arguments() {
  return array(
    'uid' => array(
      'type' => 'number',
      'hidden' => TRUE,
    ),
    'gid' => array(
      'type' => 'number',
      'hidden' => TRUE,
    ),
    'title' => array(
      'type' => 'string',
      'label' => t('Usertitle'),
    ),
    'account' => array(
      'type' => 'user',
      'label' => t('User that got promoted in the group'),
      'handler' => 'og_titles_rules_events_argument_og_user',
    ),
    'group' => array(
      'type' => 'node',
      'label' => t('Group'),
      'handler' => 'og_titles_rules_events_argument_og_node',
    ),
  ) + rules_events_global_user_argument();
}

/**
 * Handler to get the user.
 */
function og_titles_rules_events_argument_og_user($uid, $gid) {
  return user_load(array('uid' => $uid));
}

/**
 * Handler to get the group node.
 */
function og_titles_rules_events_argument_og_node($uid, $gid) {
  return node_load($gid);
}
