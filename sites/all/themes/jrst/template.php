<?php


function jrst_preprocess_node(&$vars) {
  if ($vars['node']->type == 'article') {
    unset($vars['submitted']);
  }
  $flag_link = flag_create_link('follow', $vars['node']->nid);
  if (!empty($flag_link)) {
    $vars['node_top'] .= '<div class="jrst-notification-follow">';
    $vars['node_top'] .= $flag_link;
    $vars['node_top'] .= '</div>';
  }
  if ($vars['submitted']) {
    // Load the node author
    $author = user_load($vars['node']->uid);

    // Author picture
    if (theme_get_setting('toggle_node_user_picture')) {
      $picture = $vars['picture'];
      unset($vars['picture']);
      $submitted = ($author->uid && user_access('access user profiles')) ? l($picture, "user/{$author->uid}", array('html' => TRUE)) : $picture;
    }

    // Author information
    $submitted .= '<span class="submitted-by">';
    $submitted .= t('Submitted by !name', array('!name' => theme('username', $author)));
    $submitted .= '</span>';

    // User points
    if ($author->uid && module_exists('userpoints')) {
      $points = userpoints_get_current_points($author->uid);
      $submitted .= '<span class="userpoints-value" title="' . t('!val user points', array('!val' => $points)) . '">';
      $submitted .= "({$points})";
      $submitted .= '</span>';
    }

    // User badges
    if ($author->uid && module_exists('user_badges')) {
      if (is_array($author->badges)) {
        foreach ($author->badges as $badge) {
          $badges[] = theme('user_badge', $badge, $author);
        }
      }

      if (!empty($badges)) {
        $submitted .= theme('user_badge_group', $badges);
      }
    }

    // Created time
    $submitted .= '<span class="submitted-on">';
    $submitted .= format_date($vars['node']->created);
    $submitted .= '</span>';

    $vars['submitted'] = $submitted;
  }
}
