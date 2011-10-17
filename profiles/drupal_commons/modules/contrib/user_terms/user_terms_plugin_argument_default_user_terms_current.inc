<?php
/**
 * Taxonomy default arguments based on current user
 */

class user_terms_plugin_argument_default_user_terms_current extends views_plugin_argument_default_current_user {

  function option_definition() {
    $options = parent::option_definition();

    $options['limit'] = array('default' => FALSE);
    $options['vids'] = array('default' => NULL);

    return $options;
  }

  function options_form(&$form, &$form_state) {
    $form['limit'] = array(
      '#type' => 'checkbox',
      '#title' => t('Limit terms by vocabulary'),
      '#default_value'=> $this->options['limit'],
      '#process' => array('expand_checkboxes', 'views_process_dependency'),
      '#dependency' => array(
        'edit-options-argument-default-taxonomy-tid-node' => array(1),
      ),
    );

    $options = array();
    $vocabularies = taxonomy_get_vocabularies();
    foreach ($vocabularies as $voc) {
      $options[$voc->vid] = check_plain($voc->name);
    }

    $form['vids'] = array(
      '#prefix' => '<div><div id="edit-options-vids">',
      '#suffix' => '</div></div>',
      '#type' => 'checkboxes',
      '#title' => t('Vocabularies'),
      '#options' => $options,
      '#default_value' => $this->options['vids'],
      '#process' => array('expand_checkboxes', 'views_process_dependency'),
      '#dependency' => array(
        //'edit-options-argument-default-taxonomy-tid-limit' => array(1),
        'edit-options-argument-default-taxonomy-tid-node' => array(1),
      ),
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
      if (!empty($this->options['limit'])) {
        $tids = array();
        // filter by vid
        foreach ($user->user_terms as $tid => $term) {
          if (!empty($this->options['vids'][$term->vid])) {
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

