<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function jrst_position_application_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function jrst_position_application_node_info() {
  $items = array(
    'application' => array(
      'name' => t('Application'),
      'module' => 'features',
      'description' => t('You may apply for one or multiple positions through this single application. Simply select the applications that you wish to apply for. You should include information in your application addressing all desired qualifications, which can be viewed be clicking the links below.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Cover Letter'),
      'min_word_count' => '0',
      'help' => t('Thank you for your interesting in applying to serve NARST.  To complete the application, first enter the position(s) you wish to apply for, ordering them according to your preference (list first choice first, etc.).  Then attach a cover letter and a short form CV as described. If you have any difficulty with the site, please contact Bob Geier (<A HREF="mailto:bobgeier@msu.edu">bobgeier@msu.edu</A>, 734-904-2984) for assistance.'),
    ),
    'position' => array(
      'name' => t('Position'),
      'module' => 'features',
      'description' => t('A position that people can apply for.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Brief Description'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_rules_defaults().
 */
function jrst_position_application_rules_defaults() {
  return array(
    'rules' => array(
      'rules_send_thank_you_email_for_application' => array(
        '#type' => 'rule',
        '#set' => 'event_node_insert',
        '#label' => 'Send thank you email for application',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'jrst_app',
          'jrst_position_application' => 'jrst_position_application',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#weight' => 0,
            '#type' => 'condition',
            '#settings' => array(
              'type' => array(
                'application' => 'application',
              ),
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#name' => 'rules_condition_content_is_type',
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
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#type' => 'action',
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
            '#name' => 'rules_action_mail_to_user',
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
function jrst_position_application_views_api() {
  return array(
    'api' => '2',
  );
}
