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

    return $options;
  }

  function argument_form(&$form, &$form_state) {
    parent::argument_form($form, $form_state);
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
      '#prefix' => '<div><div id="edit-options-vids">',
      '#suffix' => '</div></div>',
      '#type' => 'checkboxes',
      '#title' => t('Vocabularies'),
      '#options' => $options,
      '#default_value' => isset($this->argument->options[$this->option_name]['vids']) ? $this->argument->options[$this->option_name]['vids'] : array(),
      '#process' => array('expand_checkboxes', 'views_process_dependency'),
      '#dependency' => array(
        'radio:options[default_action]' => array('default'),
        'radio:options[default_argument_type]' => array($this->id)
      ),
      '#dependency_count' => 2,
    );
  }

  function options_submit(&$form, &$form_state, &$options) {
    // Clear checkbox values.
    $options['vids'] = array_filter($options['vids']);
  }


  function get_argument() {
    $uid = parent::get_argument();
    $user = user_load($uid);
    if (!empty($user->user_terms)) {
      if (!empty($this->argument->options[$this->option_name]['limit'])) {
        $tids = array();
        // filter by vid
        foreach ($user->user_terms as $tid => $term) {
          if (!empty($this->argument->options[$this->option_name]['vids'][$term['vid']])) {
            $tids[] = $tid;
          }
        }
        return implode("+", $tids);
      }
      // Return all tids.
      else {
        return implode("+", array_keys($user->user_terms));
      }
    }
  }
}