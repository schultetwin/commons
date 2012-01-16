<?php

class jrst_view_feedback_link_field_handler extends views_handler_field_custom {
  function render($values) {
    if (user_access('administer support overview')) {
      return l(t('Bugs'), 'support/tickets/jrst');
    }
  }
}