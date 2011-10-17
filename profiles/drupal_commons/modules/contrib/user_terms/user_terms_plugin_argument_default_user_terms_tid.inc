<?php

/**
 * Class that defines default argument of taxonomy terms by user. It looks in the url,
 * as well as at node authors if that option is selected.
 */
class user_terms_plugin_argument_default_user_terms_tid extends views_plugin_argument_default_user {
  var $option_name = 'default_argument_user_terms_tid';

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