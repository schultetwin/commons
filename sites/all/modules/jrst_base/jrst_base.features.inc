<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function jrst_base_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "features_override" && $api == "features_override") {
    return array("version" => 1);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_rules_defaults().
 */
function jrst_base_rules_defaults() {
  return array(
    'rules' => array(
      'rules_article_approval' => array(
        '#type' => 'rule',
        '#set' => 'event_workflow_state_changed',
        '#label' => 'Article Approval',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'JRST',
          'jrst_base' => 'jrst_base',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#info' => array(
              'label' => 'Check if content workflow state is Approved',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Node',
                ),
              ),
              'module' => 'Workflow',
            ),
            '#name' => 'workflow_check_state',
            '#settings' => array(
              'state' => array(
                '3' => '3',
              ),
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#type' => 'condition',
            '#weight' => 0,
          ),
          '1' => array(
            '#type' => 'condition',
            '#settings' => array(
              'from_state' => array(
                '2' => '2',
              ),
              'to_state' => array(
                '3' => '3',
              ),
              '#argument map' => array(
                'old_state' => 'old_state',
                'new_state' => 'new_state',
              ),
            ),
            '#name' => 'workflow_check_transition',
            '#info' => array(
              'label' => 'Check workflow transition from Review to Approved',
              'arguments' => array(
                'old_state' => array(
                  'type' => 'workflow_state',
                  'label' => 'Old workflow state',
                ),
                'new_state' => array(
                  'type' => 'workflow_state',
                  'label' => 'New workflow state',
                ),
              ),
              'module' => 'Workflow',
            ),
            '#weight' => 0,
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Publish Updated content',
              'module' => 'Node',
              'arguments' => array(
                'node' => array(
                  'label' => 'Content',
                  'type' => 'node',
                ),
              ),
              'base' => 'rules_core_action_execute',
              'action_name' => 'node_publish_action',
              'configurable' => FALSE,
              'label callback' => 'rules_core_node_label_callback',
              'label_skeleton' => 'Publish @node',
            ),
            '#name' => 'rules_core_node_publish_action',
            '#settings' => array(
              'auto_save' => 1,
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#type' => 'action',
          ),
          '1' => array(
            '#type' => 'action',
            '#settings' => array(
              'title' => 'Discussion for [node:title]',
              'type' => 'discussion',
              'node_access' => 0,
              '#argument map' => array(
                'author' => 'author',
                'node_added' => 'node_added',
              ),
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'title' => array(
                    '0' => 'node',
                    '1' => ':global',
                  ),
                ),
              ),
            ),
            '#name' => 'rules_action_add_node',
            '#info' => array(
              'label' => 'Add new content',
              'arguments' => array(
                'author' => array(
                  'type' => 'user',
                  'label' => 'User, who is set as author',
                ),
                'title' => array(
                  'type' => 'string',
                  'label' => 'Title',
                  'description' => 'The title of the newly created content.',
                ),
              ),
              'new variables' => array(
                'node_added' => array(
                  'label' => 'new content of type discussion',
                  'type' => 'node',
                  'save' => TRUE,
                  'label callback' => 'rules_action_add_node_variable_label',
                ),
              ),
              'module' => 'Node',
            ),
            '#weight' => 0,
          ),
          '2' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Populate new content of type discussion\'s field \'field_discussion_article\'',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'eval input' => array(
                '0' => 'code',
                '1' => 'value|0|nid',
              ),
              'module' => 'CCK',
            ),
            '#name' => 'content_rules_action_populate_field',
            '#settings' => array(
              'field_name' => 'field_discussion_article',
              '#argument map' => array(
                'node' => 'node_added',
              ),
              'value' => array(
                '0' => array(
                  'nid' => '',
                ),
              ),
              'code' => 'return array(
  0 => array(\'nid\' => $node->nid),
);',
              'vars' => array(
                '0' => 'node',
              ),
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'code' => array(
                    '0' => ':global',
                  ),
                  'value|0|nid' => array(
                    '0' => ':global',
                  ),
                ),
              ),
            ),
            '#type' => 'action',
          ),
          '3' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Execute custom PHP code',
              'module' => 'PHP',
              'eval input' => array(
                '0' => 'code',
              ),
            ),
            '#name' => 'rules_action_custom_php',
            '#settings' => array(
              'code' => '$node->comment = 0;
return array("node" => $node);',
              'vars' => array(
                '0' => 'node',
              ),
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'code' => array(
                    '0' => ':global',
                  ),
                ),
              ),
            ),
            '#type' => 'action',
          ),
        ),
        '#version' => 6003,
      ),
      'rules_send_thank_you_email_for_application' => array(
        '#type' => 'rule',
        '#set' => 'event_node_insert',
        '#label' => 'Send thank you email for application',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'JRST',
          'jrst_base' => 'jrst_base',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#info' => array(
              'label' => 'Created content is Application',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Node',
            ),
            '#name' => 'rules_condition_content_is_type',
            '#settings' => array(
              'type' => array(
                'application' => 'application',
              ),
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#type' => 'condition',
            '#weight' => 0,
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Send a mail to a user',
              'arguments' => array(
                'user' => array(
                  'type' => 'user',
                  'label' => 'Recipient',
                ),
              ),
              'module' => 'System',
              'eval input' => array(
                '0' => 'subject',
                '1' => 'message',
                '2' => 'from',
              ),
            ),
            '#name' => 'rules_action_mail_to_user',
            '#settings' => array(
              'from' => '',
              'subject' => '[eJRST] Thank you for your Committee Application',
              'message' => 'Dear [author:realname],

Thank you for putting yourself forward for committee work on behalf of NARST. We have received your self-nomination application, and will be reviewing it in the weeks ahead.  Please expect to hear from the NARST leadership before the Annual Conference in Indianapolis.

If at any point you change your mind (or want to sign up for more!) you may edit your application by going to: [node:node-url], or by logging on to the eJRST.net site and looking under "My eJRST".  You can also just submit a new application and that will work as well.

Thanks again for your willingness to serve in this important way.

',
              '#argument map' => array(
                'user' => 'author',
              ),
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'subject' => array(
                    '0' => ':global',
                  ),
                  'message' => array(
                    '0' => 'node',
                    '1' => 'author',
                    '2' => ':global',
                  ),
                  'from' => array(
                    '0' => ':global',
                  ),
                ),
              ),
            ),
            '#type' => 'action',
          ),
        ),
        '#version' => 6003,
      ),
      'rules_article_has_been_accepted' => array(
        '#type' => 'rule',
        '#set' => 'event_node_update',
        '#label' => 'Article has been accepted',
        '#active' => 1,
        '#weight' => '-3',
        '#categories' => array(
          '0' => 'JRST',
          'jrst_base' => 'jrst_base',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#weight' => -6,
            '#info' => array(
              'label' => 'Updated content is published',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Node',
            ),
            '#name' => 'rules_condition_content_is_published',
            '#settings' => array(
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#type' => 'condition',
          ),
          '1' => array(
            '#type' => 'condition',
            '#settings' => array(
              'type' => array(
                'article' => 'article',
              ),
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#name' => 'rules_condition_content_is_type',
            '#info' => array(
              'label' => 'Updated content is Article',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Node',
            ),
            '#weight' => -3,
          ),
          '2' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Check if content workflow state is (creation), EB Review, Review, Decision',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Node',
                ),
              ),
              'module' => 'Workflow',
            ),
            '#name' => 'workflow_check_state',
            '#settings' => array(
              'state' => array(
                '1' => '1',
                '5' => '5',
                '2' => '2',
                '6' => '6',
              ),
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#type' => 'condition',
          ),
          '3' => array(
            '#weight' => 0,
            '#type' => 'condition',
            '#settings' => array(
              'field_name' => 'field_article_decision',
              '#argument map' => array(
                'node' => 'node',
              ),
              'value' => array(
                '0' => array(
                  'value' => 'Accept',
                ),
              ),
              'code' => '',
              'vars' => array(),
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'code' => array(
                    '0' => ':global',
                  ),
                  'value|0|value' => array(
                    '0' => ':global',
                  ),
                ),
              ),
            ),
            '#name' => 'content_rules_field_has_value',
            '#info' => array(
              'label' => 'Updated content\'s field \'field_article_decision\' has value',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'eval input' => array(
                '0' => 'code',
                '1' => 'value|0|value',
              ),
              'module' => 'CCK',
            ),
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'module' => 'Workflow',
              'arguments' => array(
                'node' => array(
                  'label' => 'Content',
                  'type' => 'node',
                ),
              ),
              'label' => 'Change workflow state of content to new state',
              'base' => 'rules_core_action_execute',
              'action_name' => 'workflow_select_given_state_action',
              'configurable' => TRUE,
            ),
            '#name' => 'rules_core_workflow_select_given_state_action',
            '#settings' => array(
              'target_sid' => '4',
              'state_name' => 'Published',
              'force' => 1,
              'workflow_comment' => 'User manually updated article decision, so %title to %state.',
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#type' => 'action',
          ),
        ),
        '#version' => 6003,
      ),
      'rules_auto_follow_by_author' => array(
        '#type' => 'rule',
        '#set' => 'event_node_presave',
        '#label' => 'Auto Follow By Author',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'JRST',
          'jrst_base' => 'jrst_base',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#weight' => 0,
            '#negate' => 1,
            '#info' => array(
              'label' => 'Article Has No Author',
              'label callback' => FALSE,
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'eval input' => array(
                '0' => 'code',
                '1' => 'value|0|uid',
              ),
              'module' => 'CCK',
            ),
            '#name' => 'content_rules_field_has_value',
            '#settings' => array(
              'field_name' => 'field_article_author',
              '#argument map' => array(
                'node' => 'node',
              ),
              'value' => array(
                '0' => array(
                  'uid' => '',
                ),
              ),
              'code' => '',
              'vars' => array(),
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'code' => array(
                    '0' => ':global',
                  ),
                  'value|0|uid' => array(
                    '0' => ':global',
                  ),
                ),
              ),
            ),
            '#type' => 'condition',
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#type' => 'action',
            '#settings' => array(
              'field' => 'field_article_author',
              '#argument map' => array(
                'node' => 'node',
                'referenced_user' => 'article_author',
              ),
            ),
            '#name' => 'userreference_rules_action_load',
            '#info' => array(
              'label' => 'Load referenced Author',
              'label callback' => FALSE,
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content containing the user reference field',
                ),
              ),
              'new variables' => array(
                'article_author' => array(
                  'label' => 'Article Author',
                  'label callback' => FALSE,
                  'type' => 'user',
                ),
              ),
              'module' => 'CCK',
            ),
            '#weight' => 0,
          ),
          '1' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Flag saved content, under "Follow/Unfollow"',
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
            '#name' => 'flag_rules_action_flag_node',
            '#settings' => array(
              'flag' => 'follow',
              'permission_check' => 1,
              '#argument map' => array(
                'object' => 'node',
                'flagging_user' => 'article_author',
              ),
            ),
            '#type' => 'action',
          ),
        ),
        '#version' => 6003,
      ),
      'rules_auto_follow_by_comment' => array(
        '#type' => 'rule',
        '#set' => 'event_comment_insert',
        '#label' => 'Auto Follow By Comment',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'JRST',
          'jrst_base' => 'jrst_base',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#settings' => array(
              'flag' => 'follow',
              '#argument map' => array(
                'object' => 'node',
                'user' => 'comment_author',
              ),
            ),
            '#type' => 'condition',
            '#name' => 'flag_rules_condition_flagged_node',
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
            '#weight' => 0,
            '#negate' => 1,
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#weight' => 0,
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
            '#name' => 'flag_rules_action_flag_node',
            '#settings' => array(
              'flag' => 'follow',
              'permission_check' => 1,
              '#argument map' => array(
                'object' => 'node',
                'flagging_user' => 'comment_author',
              ),
            ),
            '#type' => 'action',
          ),
        ),
        '#version' => 6003,
      ),
      'rules_auto_follow_by_creation' => array(
        '#type' => 'rule',
        '#set' => 'event_node_insert',
        '#label' => 'Auto Follow By Creation',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'JRST',
          'jrst_base' => 'jrst_base',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#type' => 'condition',
            '#settings' => array(
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#name' => 'rules_condition_content_is_new',
            '#info' => array(
              'label' => 'Created content is new',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Node',
            ),
            '#weight' => 0,
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Flag created content, under "Follow/Unfollow"',
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
            '#name' => 'flag_rules_action_flag_node',
            '#settings' => array(
              'flag' => 'follow',
              'permission_check' => 1,
              '#argument map' => array(
                'object' => 'node',
                'flagging_user' => 'author',
              ),
            ),
            '#type' => 'action',
          ),
        ),
        '#version' => 6003,
      ),
      'rules_decision_is_made' => array(
        '#type' => 'rule',
        '#set' => 'event_node_update',
        '#label' => 'Decision is made',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'JRST',
          'jrst_base' => 'jrst_base',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#type' => 'condition',
            '#settings' => array(
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#name' => 'rules_condition_content_is_published',
            '#info' => array(
              'label' => 'Updated content is published',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Node',
            ),
            '#weight' => -7,
          ),
          '1' => array(
            '#weight' => -5,
            '#info' => array(
              'label' => 'Updated content is Article',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Node',
            ),
            '#name' => 'rules_condition_content_is_type',
            '#settings' => array(
              'type' => array(
                'article' => 'article',
              ),
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#type' => 'condition',
          ),
          '3' => array(
            '#type' => 'condition',
            '#settings' => array(
              'state' => array(
                '1' => '1',
                '5' => '5',
                '2' => '2',
              ),
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#name' => 'workflow_check_state',
            '#info' => array(
              'label' => 'Check if content workflow state is (creation), EB Review, Review',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Node',
                ),
              ),
              'module' => 'Workflow',
            ),
            '#weight' => -2,
          ),
          '2' => array(
            '#negate' => 1,
            '#weight' => 5,
            '#info' => array(
              'label' => 'Updated content\'s field \'field_article_decision\' has value',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'eval input' => array(
                '0' => 'code',
                '1' => 'value|0|value',
              ),
              'module' => 'CCK',
            ),
            '#name' => 'content_rules_field_has_value',
            '#settings' => array(
              'field_name' => 'field_article_decision',
              '#argument map' => array(
                'node' => 'node',
              ),
              'value' => array(
                '0' => array(
                  'value' => '',
                ),
              ),
              'code' => '',
              'vars' => array(),
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'code' => array(
                    '0' => ':global',
                  ),
                  'value|0|value' => array(
                    '0' => ':global',
                  ),
                ),
              ),
            ),
            '#type' => 'condition',
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'module' => 'Workflow',
              'arguments' => array(
                'node' => array(
                  'label' => 'Content',
                  'type' => 'node',
                ),
              ),
              'label' => 'Change workflow state of content to new state',
              'base' => 'rules_core_action_execute',
              'action_name' => 'workflow_select_given_state_action',
              'configurable' => TRUE,
            ),
            '#name' => 'rules_core_workflow_select_given_state_action',
            '#settings' => array(
              'target_sid' => '6',
              'state_name' => 'Decision',
              'force' => 1,
              'workflow_comment' => 'Decision detected, so assigning %title to %state.',
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#type' => 'action',
          ),
        ),
        '#version' => 6003,
      ),
      'rules_send_mail_when_eb_reviewer_assigned' => array(
        '#type' => 'rule',
        '#set' => 'event_node_update',
        '#label' => 'Send mail when eb reviewer assigned',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'JRST',
          'jrst_base' => 'jrst_base',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#type' => 'condition',
            '#settings' => array(
              'type' => array(
                'article' => 'article',
              ),
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#name' => 'rules_condition_content_is_type',
            '#info' => array(
              'label' => 'Updated content is Article',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Node',
            ),
            '#weight' => -4,
          ),
          '3' => array(
            '#weight' => -1,
            '#info' => array(
              'label' => 'Check if content workflow state is (creation), Review',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Node',
                ),
              ),
              'module' => 'Workflow',
            ),
            '#name' => 'workflow_check_state',
            '#settings' => array(
              'state' => array(
                '1' => '1',
                '2' => '2',
              ),
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#type' => 'condition',
          ),
          '1' => array(
            '#type' => 'condition',
            '#settings' => array(
              'field_name' => 'field_article_eb_reviewer',
              '#argument map' => array(
                'node' => 'node',
                'node_unchanged' => 'node_unchanged',
              ),
            ),
            '#name' => 'content_rules_field_changed',
            '#info' => array(
              'label' => 'Updated content\'s field \'field_article_eb_reviewer\' has been changed',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content containing changes',
                ),
                'node_unchanged' => array(
                  'type' => 'node',
                  'label' => 'Content not containing changes',
                ),
              ),
              'module' => 'CCK',
            ),
            '#weight' => 0,
          ),
          '2' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Updated content\'s field \'field_article_eb_confirm\' has value',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'eval input' => array(
                '0' => 'code',
              ),
              'module' => 'CCK',
            ),
            '#name' => 'content_rules_field_has_value',
            '#settings' => array(
              'field_name' => 'field_article_eb_confirm',
              '#argument map' => array(
                'node' => 'node',
              ),
              'value' => array(
                '0' => array(
                  'value' => 0,
                ),
              ),
              'code' => '',
              'vars' => array(),
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'code' => array(
                    '0' => ':global',
                  ),
                ),
              ),
            ),
            '#type' => 'condition',
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#type' => 'action',
            '#settings' => array(
              'field' => 'field_article_eb_reviewer',
              '#argument map' => array(
                'node' => 'node',
                'referenced_user' => 'referenced_user',
              ),
            ),
            '#name' => 'userreference_rules_action_load',
            '#info' => array(
              'label' => 'Load a referenced user',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content containing the user reference field',
                ),
              ),
              'new variables' => array(
                'referenced_user' => array(
                  'type' => 'user',
                  'label' => 'Referenced user',
                ),
              ),
              'module' => 'CCK',
            ),
            '#weight' => 0,
          ),
          '1' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Send a mail to a user',
              'arguments' => array(
                'user' => array(
                  'type' => 'user',
                  'label' => 'Recipient',
                ),
              ),
              'module' => 'System',
              'eval input' => array(
                '0' => 'subject',
                '1' => 'message',
                '2' => 'from',
              ),
            ),
            '#name' => 'rules_action_mail_to_user',
            '#settings' => array(
              'from' => '',
              'subject' => 'EJRST Review Request for [node:title]',
              'message' => '<?php global $base_url; ?>

Hi [referenced_user:realname],

We have assigned you to review [node:title] for JRST. To download the article, go to <a href="<?php print $base_url;?>/node/[node:nid]"><?php print $base_url;?>/node/[node:nid]</a>. By viewing this page you are accepting your appoint as a reviewer to this article. To reject your appointment, click <a href="<?php print $base_url;?>/node/[node:nid]/reject">here</a>.

Thank you,
JRST Editors',
              '#argument map' => array(
                'user' => 'referenced_user',
              ),
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'subject' => array(
                    '0' => 'node',
                    '1' => ':global',
                  ),
                  'message' => array(
                    '0' => 'referenced_user',
                    '1' => 'node',
                    '2' => ':global',
                  ),
                  'from' => array(
                    '0' => ':global',
                  ),
                ),
                'rules_input_evaluator_php' => array(
                  'message' => array(),
                ),
              ),
            ),
            '#type' => 'action',
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
