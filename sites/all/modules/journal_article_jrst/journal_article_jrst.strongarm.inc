<?php

/**
 * Implementation of hook_strongarm().
 */
function journal_article_jrst_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_article';
  $strongarm->value = '0';

  $export['ant_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_issue';
  $strongarm->value = '2';

  $export['ant_issue'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_pattern_article';
  $strongarm->value = '';

  $export['ant_pattern_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_pattern_issue';
  $strongarm->value = '[field_issue_pub_date-month] [field_issue_pub_date-yyyy]';

  $export['ant_pattern_issue'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_php_article';
  $strongarm->value = 0;

  $export['ant_php_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_php_issue';
  $strongarm->value = 0;

  $export['ant_php_issue'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_article';
  $strongarm->value = 0;

  $export['comment_anonymous_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_issue';
  $strongarm->value = 0;

  $export['comment_anonymous_issue'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_article';
  $strongarm->value = '2';

  $export['comment_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_article';
  $strongarm->value = '3';

  $export['comment_controls_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_issue';
  $strongarm->value = '3';

  $export['comment_controls_issue'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_article';
  $strongarm->value = '4';

  $export['comment_default_mode_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_issue';
  $strongarm->value = '4';

  $export['comment_default_mode_issue'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_article';
  $strongarm->value = '2';

  $export['comment_default_order_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_issue';
  $strongarm->value = '1';

  $export['comment_default_order_issue'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_article';
  $strongarm->value = '50';

  $export['comment_default_per_page_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_issue';
  $strongarm->value = '50';

  $export['comment_default_per_page_issue'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_driven:enforce_new_revision';
  $strongarm->value = 1;

  $export['comment_driven:enforce_new_revision'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_driven:inspect_links';
  $strongarm->value = 1;

  $export['comment_driven:inspect_links'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_driven:node_form_bellow';
  $strongarm->value = 0;

  $export['comment_driven:node_form_bellow'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_driven:theme_support';
  $strongarm->value = 'default';

  $export['comment_driven:theme_support'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_driven:type:article:driven_props';
  $strongarm->value = array(
    'enabled' => 1,
    'cck' => array(
      'field_article_decision' => array(
        'enabled' => 1,
        'behaviors' => array(
          'driven_acp' => array(
            'acp' => 'grant_all_roles',
            'roles' => array(
              5 => 0,
            ),
          ),
        ),
      ),
      'field_article_resubmit' => array(
        'enabled' => 0,
        'behaviors' => array(
          'driven_acp' => array(
            'acp' => 'grant_all_roles',
            'roles' => array(
              5 => 0,
            ),
          ),
        ),
      ),
      'field_article_status' => array(
        'enabled' => 1,
        'behaviors' => array(
          'driven_acp' => array(
            'acp' => 'grant_all_roles',
            'roles' => array(
              5 => 0,
            ),
          ),
        ),
      ),
      'field_article_decision_date' => array(
        'enabled' => 0,
        'behaviors' => array(
          'driven_acp' => array(
            'acp' => 'grant_all_roles',
            'roles' => array(
              5 => 0,
            ),
          ),
        ),
      ),
      'field_article_editor' => array(
        'enabled' => 1,
        'behaviors' => array(
          'driven_acp' => array(
            'acp' => 'grant_all_roles',
            'roles' => array(
              5 => 0,
            ),
          ),
        ),
      ),
      'field_article_editor_projection' => array(
        'enabled' => 0,
        'behaviors' => array(
          'driven_acp' => array(
            'acp' => 'grant_all_roles',
            'roles' => array(
              5 => 0,
            ),
          ),
        ),
      ),
      'field_article_assoc_editor' => array(
        'enabled' => 1,
        'behaviors' => array(
          'driven_acp' => array(
            'acp' => 'grant_all_roles',
            'roles' => array(
              5 => 0,
            ),
          ),
        ),
      ),
      'field_article_issue' => array(
        'enabled' => 0,
        'behaviors' => array(
          'driven_acp' => array(
            'acp' => 'grant_all_roles',
            'roles' => array(
              5 => 0,
            ),
          ),
        ),
      ),
      'field_article_author' => array(
        'enabled' => 0,
        'behaviors' => array(
          'driven_acp' => array(
            'acp' => 'grant_all_roles',
            'roles' => array(
              5 => 0,
            ),
          ),
        ),
      ),
      'field_article_eb_reviewer' => array(
        'enabled' => 1,
        'behaviors' => array(
          'driven_acp' => array(
            'acp' => 'grant_all_roles',
            'roles' => array(
              5 => 0,
            ),
          ),
        ),
      ),
      'field_article_coauthor' => array(
        'enabled' => 0,
        'behaviors' => array(
          'driven_acp' => array(
            'acp' => 'grant_all_roles',
            'roles' => array(
              5 => 0,
            ),
          ),
          'driven_cck_producer_consumer' => array(
            'in_out' => 'none',
            'roles' => array(
              1 => 0,
              2 => 0,
              6 => 0,
              3 => 0,
              4 => 0,
              9 => 0,
              7 => 0,
              8 => 0,
              5 => 0,
            ),
          ),
        ),
      ),
      'field_article_eb_confirm' => array(
        'enabled' => 0,
        'behaviors' => array(
          'driven_acp' => array(
            'acp' => 'grant_all_roles',
            'roles' => array(
              5 => 0,
            ),
          ),
        ),
      ),
      'field_article_available_date' => array(
        'enabled' => FALSE,
      ),
      'field_article_manuscript_upload' => array(
        'enabled' => 0,
        'behaviors' => array(
          'driven_acp' => array(
            'acp' => 'grant_all_roles',
            'roles' => array(
              5 => 0,
            ),
          ),
        ),
      ),
      'field_article_scholarone_id' => array(
        'enabled' => 0,
        'behaviors' => array(
          'driven_acp' => array(
            'acp' => 'grant_all_roles',
            'roles' => array(
              5 => 0,
            ),
          ),
        ),
      ),
      'field_article_previous_article' => array(
        'enabled' => 0,
        'behaviors' => array(
          'driven_acp' => array(
            'acp' => 'grant_all_roles',
            'roles' => array(
              5 => 0,
            ),
          ),
        ),
      ),
      'field_article_wiley_id' => array(
        'enabled' => 0,
        'behaviors' => array(
          'driven_acp' => array(
            'acp' => 'grant_all_roles',
            'roles' => array(
              5 => 0,
            ),
          ),
        ),
      ),
      'field_article_special_issue' => array(
        'enabled' => 0,
        'behaviors' => array(
          'driven_acp' => array(
            'acp' => 'grant_all_roles',
            'roles' => array(
              5 => 0,
            ),
          ),
        ),
      ),
      'field_article_type' => array(
        'enabled' => 0,
        'behaviors' => array(
          'driven_acp' => array(
            'acp' => 'grant_all_roles',
            'roles' => array(
              5 => 0,
            ),
          ),
        ),
      ),
      'field_article_submitted_date' => array(
        'enabled' => 0,
        'behaviors' => array(
          'driven_acp' => array(
            'acp' => 'grant_all_roles',
            'roles' => array(
              5 => 0,
            ),
          ),
        ),
      ),
      'field_article_preprod_author' => array(
        'enabled' => 0,
        'behaviors' => array(
          'driven_acp' => array(
            'acp' => 'grant_all_roles',
            'roles' => array(
              5 => 0,
            ),
          ),
        ),
      ),
      'field_article_country' => array(
        'enabled' => 0,
        'behaviors' => array(
          'driven_acp' => array(
            'acp' => 'grant_all_roles',
            'roles' => array(
              5 => 0,
            ),
          ),
        ),
      ),
    ),
    'node' => array(
      'title' => array(
        'enabled' => 0,
        'behaviors' => array(
          'driven_acp' => array(
            'acp' => 'grant_all_roles',
            'roles' => array(
              5 => 0,
            ),
          ),
        ),
      ),
      'body_field:bundled' => array(
        'enabled' => 0,
        'behaviors' => array(
          'driven_acp' => array(
            'acp' => 'grant_all_roles',
            'roles' => array(
              5 => 0,
            ),
          ),
        ),
      ),
      'options:status' => array(
        'enabled' => 0,
        'behaviors' => array(
          'driven_acp' => array(
            'acp' => 'grant_all_roles',
            'roles' => array(
              5 => 0,
            ),
          ),
        ),
      ),
      'options:promote' => array(
        'enabled' => 0,
        'behaviors' => array(
          'driven_acp' => array(
            'acp' => 'grant_all_roles',
            'roles' => array(
              5 => 0,
            ),
          ),
        ),
      ),
      'options:sticky' => array(
        'enabled' => 0,
        'behaviors' => array(
          'driven_acp' => array(
            'acp' => 'grant_all_roles',
            'roles' => array(
              5 => 0,
            ),
          ),
        ),
      ),
      'comment_settings:comment' => array(
        'enabled' => 0,
        'behaviors' => array(
          'driven_acp' => array(
            'acp' => 'grant_all_roles',
            'roles' => array(
              5 => 0,
            ),
          ),
        ),
      ),
      'author:name' => array(
        'enabled' => 0,
        'behaviors' => array(
          'driven_acp' => array(
            'acp' => 'grant_all_roles',
            'roles' => array(
              5 => 0,
            ),
          ),
        ),
      ),
      'author:date' => array(
        'enabled' => 0,
        'behaviors' => array(
          'driven_acp' => array(
            'acp' => 'grant_all_roles',
            'roles' => array(
              5 => 0,
            ),
          ),
        ),
      ),
    ),
    'workflow' => array(
      'workflow:' => array(
        'enabled' => 0,
        'behaviors' => array(
          'driven_acp' => array(
            'acp' => 'grant_all_roles',
            'roles' => array(
              5 => 0,
            ),
          ),
        ),
      ),
      'workflow:bundled_schedule' => array(
        'enabled' => 0,
        'behaviors' => array(
          'driven_acp' => array(
            'acp' => 'grant_all_roles',
            'roles' => array(
              5 => 0,
            ),
          ),
        ),
      ),
      'workflow:workflow_comment' => array(
        'enabled' => 0,
        'behaviors' => array(
          'driven_acp' => array(
            'acp' => 'grant_all_roles',
            'roles' => array(
              5 => 0,
            ),
          ),
        ),
      ),
    ),
  );

  $export['comment_driven:type:article:driven_props'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_driven:type:article:settings';
  $strongarm->value = array(
    'empty_comment' => 1,
    'fieldset:collapsed' => 0,
    'fieldset:title' => 'Driven Article',
    'live_render' => '0',
  );

  $export['comment_driven:type:article:settings'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_article';
  $strongarm->value = '1';

  $export['comment_form_location_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_issue';
  $strongarm->value = '0';

  $export['comment_form_location_issue'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_issue';
  $strongarm->value = '0';

  $export['comment_issue'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_article';
  $strongarm->value = '0';

  $export['comment_preview_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_issue';
  $strongarm->value = '1';

  $export['comment_preview_issue'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_article';
  $strongarm->value = '1';

  $export['comment_subject_field_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_issue';
  $strongarm->value = '1';

  $export['comment_subject_field_issue'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_article';
  $strongarm->value = array(
    'title' => '31',
    'body_field' => '32',
    'revision_information' => '40',
    'author' => '38',
    'options' => '41',
    'comment_settings' => '43',
    'menu' => '39',
    'taxonomy' => '37',
    'path' => '42',
    'workflow' => '30',
  );

  $export['content_extra_weights_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_issue';
  $strongarm->value = array(
    'title' => '-5',
    'body_field' => '1',
    'revision_information' => '4',
    'author' => '2',
    'options' => '5',
    'comment_settings' => '7',
    'menu' => '3',
    'path' => '6',
    'attachments' => '8',
  );

  $export['content_extra_weights_issue'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date:article:full:field_article_decision_date_fromto';
  $strongarm->value = 'both';

  $export['date:article:full:field_article_decision_date_fromto'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date:article:full:field_article_decision_date_multiple_from';
  $strongarm->value = '';

  $export['date:article:full:field_article_decision_date_multiple_from'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date:article:full:field_article_decision_date_multiple_number';
  $strongarm->value = '';

  $export['date:article:full:field_article_decision_date_multiple_number'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date:article:full:field_article_decision_date_multiple_to';
  $strongarm->value = '';

  $export['date:article:full:field_article_decision_date_multiple_to'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date:article:full:field_article_decision_date_show_repeat_rule';
  $strongarm->value = 'show';

  $export['date:article:full:field_article_decision_date_show_repeat_rule'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date:article:full:field_article_submitted_date_fromto';
  $strongarm->value = 'both';

  $export['date:article:full:field_article_submitted_date_fromto'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date:article:full:field_article_submitted_date_multiple_from';
  $strongarm->value = '';

  $export['date:article:full:field_article_submitted_date_multiple_from'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date:article:full:field_article_submitted_date_multiple_number';
  $strongarm->value = '';

  $export['date:article:full:field_article_submitted_date_multiple_number'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date:article:full:field_article_submitted_date_multiple_to';
  $strongarm->value = '';

  $export['date:article:full:field_article_submitted_date_multiple_to'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date:article:full:field_article_submitted_date_show_repeat_rule';
  $strongarm->value = 'show';

  $export['date:article:full:field_article_submitted_date_show_repeat_rule'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date:article:teaser:field_article_decision_date_fromto';
  $strongarm->value = 'both';

  $export['date:article:teaser:field_article_decision_date_fromto'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date:article:teaser:field_article_decision_date_multiple_from';
  $strongarm->value = '';

  $export['date:article:teaser:field_article_decision_date_multiple_from'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date:article:teaser:field_article_decision_date_multiple_number';
  $strongarm->value = '';

  $export['date:article:teaser:field_article_decision_date_multiple_number'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date:article:teaser:field_article_decision_date_multiple_to';
  $strongarm->value = '';

  $export['date:article:teaser:field_article_decision_date_multiple_to'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date:article:teaser:field_article_decision_date_show_repeat_rule';
  $strongarm->value = 'show';

  $export['date:article:teaser:field_article_decision_date_show_repeat_rule'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date:article:teaser:field_article_submitted_date_fromto';
  $strongarm->value = 'both';

  $export['date:article:teaser:field_article_submitted_date_fromto'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date:article:teaser:field_article_submitted_date_multiple_from';
  $strongarm->value = '';

  $export['date:article:teaser:field_article_submitted_date_multiple_from'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date:article:teaser:field_article_submitted_date_multiple_number';
  $strongarm->value = '';

  $export['date:article:teaser:field_article_submitted_date_multiple_number'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date:article:teaser:field_article_submitted_date_multiple_to';
  $strongarm->value = '';

  $export['date:article:teaser:field_article_submitted_date_multiple_to'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date:article:teaser:field_article_submitted_date_show_repeat_rule';
  $strongarm->value = 'show';

  $export['date:article:teaser:field_article_submitted_date_show_repeat_rule'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'enable_revisions_page_article_import';
  $strongarm->value = 1;

  $export['enable_revisions_page_article_import'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_article';
  $strongarm->value = array(
    0 => 'status',
  );

  $export['node_options_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_issue';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );

  $export['node_options_issue'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_content_type_usage_article';
  $strongarm->value = 'omitted';

  $export['og_content_type_usage_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_content_type_usage_issue';
  $strongarm->value = 'omitted';

  $export['og_content_type_usage_issue'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_max_groups_article';
  $strongarm->value = '';

  $export['og_max_groups_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'og_max_groups_issue';
  $strongarm->value = '';

  $export['og_max_groups_issue'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_diff_inline_article';
  $strongarm->value = 0;

  $export['show_diff_inline_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_diff_inline_issue';
  $strongarm->value = 0;

  $export['show_diff_inline_issue'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_preview_changes_article';
  $strongarm->value = 1;

  $export['show_preview_changes_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'show_preview_changes_issue';
  $strongarm->value = 1;

  $export['show_preview_changes_issue'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'skinr_settings_article';
  $strongarm->value = array(
    0 => 'comment_group',
    1 => 'node_group',
  );

  $export['skinr_settings_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'skinr_settings_issue';
  $strongarm->value = array(
    0 => 'comment_group',
    1 => 'node_group',
  );

  $export['skinr_settings_issue'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unique_field_comp_article';
  $strongarm->value = 'each';

  $export['unique_field_comp_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unique_field_fields_article';
  $strongarm->value = array(
    0 => 'field_article_wiley_id',
  );

  $export['unique_field_fields_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unique_field_scope_article';
  $strongarm->value = 'type';

  $export['unique_field_scope_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'unique_field_show_matches_article';
  $strongarm->value = array();

  $export['unique_field_show_matches_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_article';
  $strongarm->value = '0';

  $export['upload_article'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_issue';
  $strongarm->value = '1';

  $export['upload_issue'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workflow_article';
  $strongarm->value = array(
    0 => 'node',
  );

  $export['workflow_article'] = $strongarm;
  return $export;
}
