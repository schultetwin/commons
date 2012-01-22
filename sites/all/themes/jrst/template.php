<?php


function jrst_preprocess_node(&$vars) {
  $flag_link = flag_create_link('follow', $vars['node']->nid);
  if (!empty($flag_link)) {
    $vars['node_top'] .= '<div class="jrst-notification-follow">';
    $vars['node_top'] .= $flag_link;
    $vars['node_top'] .= '</div>';
  }
  $remove = array('article', 'issue', 'webform', 'position');

  if (in_array($vars['type'], $remove)) {
    unset($vars['submitted']);
  }
  if ($vars['#node']->type == 'issue' && $vars['#node']->field_issue_special[0]['value']) {
    $vars['special_date'] = $vars['#node']->field_issue_pub_date[0]['view'];
  }
}

function jrst_preprocess_comment($vars) {
  if ($vars['node']->type == 'article') {
    

  }
}

function jrst_preprocess_maintenance_page(&$vars) {
  template_preprocess_maintenance_page($vars);
}