<?php


class jrst_feedback_link_field_handler extends views_handler_field_custom {
  function render($values) {
    return l(t('Give Feedback'), 'feedback/add', array('query' => drupal_get_destination()));
  }
}
