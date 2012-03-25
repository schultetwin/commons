<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function jrst_base_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
  elseif ($module == "features_override" && $api == "features_override") {
    return array("version" => 1);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function jrst_base_node_info() {
  $items = array(
    'book' => array(
      'name' => t('Book page'),
      'module' => 'features',
      'description' => t('A <em>book page</em> is a page of content, organized into a collection of related entries collectively known as a <em>book</em>. A <em>book page</em> automatically displays links to adjacent pages, providing a simple navigation system for organizing and reviewing structured content.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'webform' => array(
      'name' => t('Webform'),
      'module' => 'features',
      'description' => t('Create a new form or questionnaire accessible to users. Submission results and statistics are recorded and accessible to privileged users.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_rules_defaults().
 */
function jrst_base_rules_defaults() {
  return array(
    'rules' => array(
      'rules_auto_follow_by_comment' => array(
        '#type' => 'rule',
        '#set' => 'event_comment_insert',
        '#label' => 'Auto Follow By Comment',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'jrst_base',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#weight' => 0,
            '#negate' => 1,
            '#info' => array(
              'label' => 'Flag "Follow/Unfollow" is flagged, for commented content',
              'base' => 'flag_rules_condition_flagged',
              'label callback' => 'flag_rules_condition_flagged_label',
              'arguments' => array(
                'flag' => array(
                  'type' => 'flag',
                  'label' => 'Flag',
                  'flag_type' => 'node',
                ),
                'object' => array(
                  'type' => 'node',
                  'label' => 'Flagged content',
                ),
                'user' => array(
                  'type' => 'user',
                  'label' => 'User on whose behalf to check',
                  'description' => 'For non-global flags, this is the user on whose behalf the flag is checked.',
                ),
              ),
              'module' => 'Flag',
            ),
            '#name' => 'flag_rules_condition_flagged_node',
            '#type' => 'condition',
            '#settings' => array(
              'flag' => 'follow',
              '#argument map' => array(
                'object' => 'node',
                'user' => 'comment_author',
              ),
            ),
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#type' => 'action',
            '#settings' => array(
              'flag' => 'follow',
              'permission_check' => 1,
              '#argument map' => array(
                'object' => 'node',
                'flagging_user' => 'comment_author',
              ),
            ),
            '#name' => 'flag_rules_action_flag_node',
            '#info' => array(
              'label' => 'Flag commented content, under "Follow/Unfollow"',
              'base' => 'flag_rules_action_flag',
              'label callback' => 'flag_rules_action_flag_label',
              'arguments' => array(
                'flag' => array(
                  'type' => 'flag',
                  'label' => 'Flag',
                  'flag_type' => 'node',
                ),
                'object' => array(
                  'type' => 'node',
                  'label' => 'Flagged content',
                ),
                'flagging_user' => array(
                  'type' => 'user',
                  'label' => 'User on whose behalf to flag',
                  'description' => 'For non-global flags, this is the user on whose behalf to flag the object. In addition, if checked below, the access permissions to the flag are checked against this user.',
                ),
              ),
              'module' => 'Flag',
            ),
            '#weight' => 0,
          ),
        ),
        '#version' => 6003,
      ),
    ),
  );
}

/**
 * Implementation of hook_views_api().
 */
function jrst_base_views_api() {
  return array(
    'api' => '2',
  );
}
