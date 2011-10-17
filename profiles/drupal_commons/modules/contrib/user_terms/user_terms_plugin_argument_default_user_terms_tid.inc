<?php

/**
 * Class that defines default argument of taxonomy terms by user. It looks in the url,
 * as well as at node authors if that option is selected.
 */
class user_terms_plugin_argument_default_user_terms_tid extends views_plugin_argument_default_user {
  var $option_name = 'default_argument_user_terms_tid';

  function option_definition() {
    $options = parent::option_definition();

    $options['limit'] = array('default' => FALSE);
    $options['vids'] = array('default' => NULL);
    $options['node_check'] = array('default' => NULL);

    return $options;
  }

  function argument_form(&$form, &$form_state) {
    $form[$this->option_name]['node_check'] = array(
      '#type' => 'checkbox',
      '#title' => t('Also look for a node and use the node author'),
      '#default_value' => !empty($this->argument->options[$this->option_name]['node_check']),
      '#process' => array('views_process_dependency'),
      '#dependency' => array(
        'radio:options[default_action]' => array('default'),
        'radio:options[default_argument_type]' => array($this->id)
      ),
      '#dependency_count' => 2,
    );

    
    $form[$this->option_name]['limit'] = array(
      '#type' => 'checkbox',
      '#title' => t('Limit terms by vocabulary'),
      '#default_value'=> !empty($this->argument->options[$this->option_name]['limit']),
      '#process' => array('expand_checkboxes', 'views_process_dependency'),
      '#dependency' => array(
        'radio:options[default_action]' => array('default'),
        'radio:options[default_argument_type]' => array($this->id)
      ),
       '#dependency_count' => 2,
    );

    $options = array();
    $vocabularies = taxonomy_get_vocabularies();
    foreach ($vocabularies as $voc) {
      $options[$voc->vid] = check_plain($voc->name);
    }

    $form[$this->option_name]['vids'] = array(
      '#prefix' => '<div><div id="edit-options-default-argument-user-terms-tid-vids">',
      '#suffix' => '</div></div>',
      '#type' => 'checkboxes',
      '#title' => t('Vocabularies'),
      '#options' => $options,
      '#default_value' => isset($this->argument->options[$this->option_name]['vids']) ? $this->argument->options[$this->option_name]['vids'] : array(),
      '#process' => array('expand_checkboxes', 'views_process_dependency'),
      '#dependency' => array(
        'radio:options[default_action]' => array('default'),
        'radio:options[default_argument_type]' => array($this->id),
        'edit-options-default-argument-user-terms-tid-limit' => array(TRUE),
      ),
      '#dependency_count' => 3,
    );
  }

  function options_submit(&$form, &$form_state, &$options) {
    // Clear checkbox values.
    $options['vids'] = array_filter($options['vids']);
  }


  function get_argument() {
    foreach (range(1, 3) as $i) {
      $user = menu_get_object('user', $i);
      if (!empty($user)) {
        $uid = $user->uid;
      }
    }

    foreach (range(1, 3) as $i) {
      $user = menu_get_object('user_uid_optional', $i);
      if (!empty($user)) {
        $uid = $user->uid;
      }
    }

    if (!empty($this->argument->options[$this->option_name]['check_node'])) {
      foreach (range(1, 3) as $i) {
        $node = menu_get_object('node', $i);
        if (!empty($node)) {
          $uid = $node->uid;
        }
      }
    }

    if (arg(0) == 'user' && is_numeric(arg(1))) {
      $uid = arg(1);
    }

    if (arg(0) == 'node' && is_numeric(arg(1))) {
      $node = node_load(arg(1));
      if ($node) {
        $uid = $node->uid;
      }
    }

    if (isset($uid) && $uid != 0) {
      $account = user_load($uid);
      if (!empty($account->user_terms)) {
        if (!empty($this->argument->options[$this->option_name]['limit'])) {
          $tids = array();
          // filter by vid
          foreach ($account->user_terms as $tid => $term) {
            if (!empty($this->argument->options[$this->option_name]['vids'][$term['vid']])) {
              $tids[] = $tid;
            }
          }
          return implode("+", $tids);
        }
        // Return all tids.
        else {
          return implode("+", array_keys($account->user_terms));
        }
      }
    }
  }
}