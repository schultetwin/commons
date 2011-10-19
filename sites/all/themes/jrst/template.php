<?php


function jrst_preprocess_node(&$vars) {
  $flag_link = flag_create_link('follow', $vars['node']->nid);
  if (!empty($flag_link)) {
    $vars['node_top'] .= '<div class="jrst-notification-follow">';
    $vars['node_top'] .= $flag_link;
    $vars['node_top'] .= '</div>';
  }

  if ($vars['node']->type == 'article') {
    unset($vars['submitted']);
  }
}
