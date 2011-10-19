<?php

/**
 * Implementation of hook_views_default_views().
 */
function jrst_frontpage_views_default_views() {
  $views = array();

  // Exported view: frontpage_issue_showcase
  $view = new view;
  $view->name = 'frontpage_issue_showcase';
  $view->description = 'Node for current issue';
  $view->tag = '';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'title' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 1,
        'max_length' => '50',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
    ),
    'field_article_author_uid' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'label_type' => 'none',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_article_author_uid',
      'table' => 'node_data_field_article_author',
      'field' => 'field_article_author_uid',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'php' => array(
      'exposed' => FALSE,
      'order' => 'DESC',
      'identifier' => 'unsorted',
      'use_php_setup' => 0,
      'php_setup' => '',
      'php_sort' => '',
      'sql_sort' => 'global $user;
$account = user_load($user->uid);
$args = $account->terms;
if (!empty($args)) {
  $args = implode(\', \', $args);
  $order = \'(SELECT COUNT(*) FROM {node} n
    LEFT JOIN {term_node} tn ON n.vid = tn.vid
    WHERE node.nid = n.nid AND tn.tid IN (\' . $args . \')
    GROUP BY n.nid) \' . strtoupper($handler->options[\'order\']);
  return $order;
}',
      'id' => 'php',
      'table' => 'views',
      'field' => 'php',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'comment_count' => array(
      'exposed' => FALSE,
      'order' => 'DESC',
      'identifier' => 'unsorted',
      'id' => 'comment_count',
      'table' => 'node_comment_statistics',
      'field' => 'comment_count',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('arguments', array(
    'field_article_issue_nid' => array(
      'default_action' => 'not found',
      'style_plugin' => 'default_summary',
      'style_options' => array(),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => '',
      'breadcrumb' => '',
      'default_argument_type' => 'fixed',
      'default_argument' => '',
      'validate_type' => 'node',
      'validate_fail' => 'not found',
      'break_phrase' => 0,
      'not' => 0,
      'id' => 'field_article_issue_nid',
      'table' => 'node_data_field_article_issue',
      'field' => 'field_article_issue_nid',
      'validate_user_argument_type' => 'uid',
      'validate_user_roles' => array(
        '2' => 0,
        '6' => 0,
        '3' => 0,
        '4' => 0,
        '9' => 0,
        '7' => 0,
        '8' => 0,
        '5' => 0,
      ),
      'relationship' => 'none',
      'default_options_div_prefix' => '',
      'default_argument_fixed' => '',
      'default_argument_user' => 0,
      'default_argument_user_terms_current' => array(
        'limit' => 0,
        'vids' => array(
          '3' => 0,
          '4' => 0,
          '2' => 0,
          '5' => 0,
          '6' => 0,
          '1' => 0,
        ),
      ),
      'default_argument_user_terms_tid' => array(
        'node_check' => 0,
        'limit' => 0,
        'vids' => array(
          '3' => 0,
          '4' => 0,
          '2' => 0,
          '5' => 0,
          '6' => 0,
          '1' => 0,
        ),
      ),
      'default_argument_php' => '',
      'validate_argument_node_type' => array(
        'issue' => 'issue',
        'blog' => 0,
        'poll' => 0,
        'discussion' => 0,
        'document' => 0,
        'event' => 0,
        'wiki' => 0,
        'article' => 0,
        'podcast' => 0,
        'group' => 0,
        'notice' => 0,
        'page' => 0,
        'webform' => 0,
      ),
      'validate_argument_node_access' => 0,
      'validate_argument_nid_type' => 'nid',
      'validate_argument_vocabulary' => array(
        '3' => 0,
        '4' => 0,
        '2' => 0,
        '5' => 0,
        '6' => 0,
        '1' => 0,
      ),
      'validate_argument_type' => 'tid',
      'validate_argument_transform' => 0,
      'validate_user_restrict_roles' => 0,
      'validate_argument_node_flag_name' => '*relationship*',
      'validate_argument_node_flag_test' => 'flaggable',
      'validate_argument_node_flag_id_type' => 'id',
      'validate_argument_user_flag_name' => '*relationship*',
      'validate_argument_user_flag_test' => 'flaggable',
      'validate_argument_user_flag_id_type' => 'id',
      'validate_argument_is_member' => 'OG_VIEWS_DO_NOT_VALIDATE_MEMBERSHIP',
      'validate_argument_group_node_type' => array(
        'group' => 0,
      ),
      'validate_argument_php' => '',
    ),
  ));
  $handler->override_option('filters', array(
    'status' => array(
      'operator' => '=',
      'value' => '1',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status',
      'table' => 'node',
      'field' => 'status',
      'relationship' => 'none',
    ),
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'article' => 'article',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
    ),
    'sid' => array(
      'operator' => 'in',
      'value' => array(
        '11' => '11',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'sid',
      'table' => 'workflow_node',
      'field' => 'sid',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('title', 'Articles');
  $handler->override_option('items_per_page', 3);
  $handler->override_option('row_options', array(
    'inline' => array(
      'title' => 'title',
      'field_article_author_uid' => 'field_article_author_uid',
    ),
    'separator' => ' - ',
    'hide_empty' => 0,
  ));
  $handler = $view->new_display('block', 'Inline On Frontpage', 'block_1');
  $handler->override_option('block_description', '');
  $handler->override_option('block_caching', -1);

  $views[$view->name] = $view;

  // Exported view: frontpage_jrst
  $view = new view;
  $view->name = 'frontpage_jrst';
  $view->description = 'Main Content of Frontpage';
  $view->tag = 'JRST';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'nid' => array(
      'label' => 'Nid',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'exclude' => 0,
      'id' => 'nid',
      'table' => 'node',
      'field' => 'nid',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Override',
      ),
    ),
    'field_issue_cover_fid' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'label_type' => 'none',
      'format' => 'Featured_default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_issue_cover_fid',
      'table' => 'node_data_field_issue_cover',
      'field' => 'field_issue_cover_fid',
      'relationship' => 'none',
    ),
    'title' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => 'articles/issues/[nid]',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'field_issue_pub_date_value' => array(
      'exposed' => FALSE,
      'order' => 'DESC',
      'identifier' => 'unsorted',
      'delta' => -1,
      'id' => 'field_issue_pub_date_value',
      'table' => 'node_data_field_issue_pub_date',
      'field' => 'field_issue_pub_date_value',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Override',
      ),
    ),
  ));
  $handler->override_option('filters', array(
    'status' => array(
      'operator' => '=',
      'value' => '1',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status',
      'table' => 'node',
      'field' => 'status',
      'relationship' => 'none',
    ),
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'issue' => 'issue',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
    ),
    'field_issue_pub_date_value' => array(
      'operator' => '<=',
      'value' => array(
        'value' => NULL,
        'min' => NULL,
        'max' => NULL,
        'default_date' => 'now',
        'default_to_date' => '',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'date_fields' => array(
        'node_data_field_issue_pub_date.field_issue_pub_date_value' => 'node_data_field_issue_pub_date.field_issue_pub_date_value',
      ),
      'date_method' => 'OR',
      'granularity' => 'month',
      'form_type' => 'date_select',
      'default_date' => 'now',
      'default_to_date' => '',
      'year_range' => '-3:+3',
      'id' => 'field_issue_pub_date_value',
      'table' => 'node_data_field_issue_pub_date',
      'field' => 'field_issue_pub_date_value',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('items_per_page', 5);
  $handler->override_option('style_plugin', 'slideshow');
  $handler->override_option('style_options', array(
    'type' => 'ul',
    'mode' => 'views_slideshow_singleframe',
    'views_slideshow_singleframe-prefix' => '',
    'views_slideshow_singleframe' => array(
      'timeout' => '5000',
      'delay' => '0',
      'speed' => '700',
      'start_paused' => 1,
      'fixed_height' => '1',
      'random' => '0',
      'pause' => '1',
      'pause_on_click' => '0',
      'pause_when_hidden' => 0,
      'pause_when_hidden_type' => 'full',
      'amount_allowed_visible' => '',
      'remember_slide' => 0,
      'remember_slide_days' => '1',
      'controls' => '1',
      'pager' => '2',
      'pager_type' => 'Numbered',
      'pager_hover' => '1',
      'pager_click_to_page' => 0,
      'image_count' => '0',
      'items_per_slide' => '1',
      'effect' => 'scrollHorz',
      'sync' => '1',
      'nowrap' => '0',
      'advanced' => '',
      'ie' => array(
        'cleartype' => 'true',
        'cleartypenobg' => 'false',
      ),
    ),
  ));
  $handler->override_option('row_options', array(
    'inline' => array(
      'field_issue_cover_fid' => 'field_issue_cover_fid',
      'title' => 'title',
      'body' => 'body',
    ),
    'separator' => ' ',
    'hide_empty' => 0,
  ));
  $handler = $view->new_display('page', 'Main Content', 'page_1');
  $handler->override_option('path', 'home');
  $handler->override_option('menu', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));

  $views[$view->name] = $view;

  // Exported view: frontpage_jrst_notices
  $view = new view;
  $view->name = 'frontpage_jrst_notices';
  $view->description = 'List of recent notices';
  $view->tag = 'JRST';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('sorts', array(
    'created' => array(
      'exposed' => FALSE,
      'order' => 'DESC',
      'identifier' => 'unsorted',
      'granularity' => 'second',
      'id' => 'created',
      'table' => 'node',
      'field' => 'created',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'notice' => 'notice',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
    ),
    'status' => array(
      'operator' => '=',
      'value' => '1',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status',
      'table' => 'node',
      'field' => 'status',
      'relationship' => 'none',
    ),
    'date_filter' => array(
      'operator' => '>=',
      'value' => array(
        'value' => NULL,
        'min' => NULL,
        'max' => NULL,
        'default_date' => 'now -1 month',
        'default_to_date' => '',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'date_fields' => array(
        'node.changed' => 'node.changed',
      ),
      'date_method' => 'OR',
      'granularity' => 'day',
      'form_type' => 'date_select',
      'default_date' => 'now -1 month',
      'default_to_date' => '',
      'year_range' => '-3:+3',
      'id' => 'date_filter',
      'table' => 'node',
      'field' => 'date_filter',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('title', 'Recent Notices');
  $handler->override_option('empty', 'No Notices in the Last Month');
  $handler->override_option('empty_format', '1');
  $handler->override_option('items_per_page', 2);
  $handler->override_option('row_plugin', 'node');
  $handler->override_option('row_options', array(
    'relationship' => 'none',
    'build_mode' => 'teaser',
    'links' => 0,
    'comments' => 0,
  ));
  $handler = $view->new_display('block', 'Frontpage Notices', 'block_1');
  $handler->override_option('block_description', '');
  $handler->override_option('block_caching', -1);

  $views[$view->name] = $view;

  // Exported view: jrst_frontpage_poll
  $view = new view;
  $view->name = 'jrst_frontpage_poll';
  $view->description = 'View that contains the frontpage poll';
  $view->tag = '';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('sorts', array(
    'created' => array(
      'exposed' => FALSE,
      'order' => 'DESC',
      'identifier' => 'unsorted',
      'granularity' => 'second',
      'id' => 'created',
      'table' => 'node',
      'field' => 'created',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'field_featured_content_value_many_to_one' => array(
      'operator' => 'or',
      'value' => array(
        'Featured' => 'Featured',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'field_featured_content_value_many_to_one',
      'table' => 'node_data_field_featured_content',
      'field' => 'field_featured_content_value_many_to_one',
      'relationship' => 'none',
      'reduce_duplicates' => 0,
    ),
    'status' => array(
      'operator' => '=',
      'value' => '1',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status',
      'table' => 'node',
      'field' => 'status',
      'relationship' => 'none',
    ),
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'poll' => 'poll',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
    ),
    'active' => array(
      'operator' => '=',
      'value' => '1',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'active',
      'table' => 'poll',
      'field' => 'active',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('title', 'Featured Poll');
  $handler->override_option('items_per_page', 1);
  $handler->override_option('row_plugin', 'node');
  $handler->override_option('row_options', array(
    'relationship' => 'none',
    'build_mode' => 'teaser',
    'links' => 0,
    'comments' => 0,
  ));
  $handler = $view->new_display('block', 'JRST Frontpage Poll', 'block_1');
  $handler->override_option('block_description', '');
  $handler->override_option('block_caching', -1);

  $views[$view->name] = $view;

  // Exported view: jrst_hot_discuscussions
  $view = new view;
  $view->name = 'jrst_hot_discuscussions';
  $view->description = 'List of recently updated discussions';
  $view->tag = 'JRST';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('relationships', array(
    'field_discussion_article_nid' => array(
      'label' => 'Article',
      'required' => 0,
      'delta' => -1,
      'id' => 'field_discussion_article_nid',
      'table' => 'node_data_field_discussion_article',
      'field' => 'field_discussion_article_nid',
      'relationship' => 'none',
    ),
    'vid' => array(
      'label' => 'node',
      'required' => 0,
      'id' => 'vid',
      'table' => 'term_node',
      'field' => 'vid',
      'relationship' => 'field_discussion_article_nid',
    ),
  ));
  $handler->override_option('fields', array(
    'title' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
    ),
    'timestamp' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'comments' => 0,
      'exclude' => 0,
      'id' => 'timestamp',
      'table' => 'history_user',
      'field' => 'timestamp',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'last_updated' => array(
      'exposed' => FALSE,
      'order' => 'DESC',
      'identifier' => 'unsorted',
      'granularity' => 'day',
      'id' => 'last_updated',
      'table' => 'node_comment_statistics',
      'field' => 'last_updated',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Override',
      ),
    ),
    'php' => array(
      'exposed' => FALSE,
      'order' => 'DESC',
      'identifier' => 'unsorted',
      'use_php_setup' => 0,
      'php_setup' => '',
      'php_sort' => '',
      'sql_sort' => 'global $user;
if ($user->uid != 0) {
  $user = user_load($user->uid);
  if (!empty($user->terms)) {
    $args = implode(\',\', array_keys($user->user_terms));
    $order = \'(SELECT COUNT(*) FROM {node} n
      LEFT JOIN {term_node} tn ON n.vid = tn.vid
      WHERE node_node_data_field_discussion_article.nid = n.nid AND tn.tid IN (\' . $args . \')
      GROUP BY n.nid) \' . strtoupper($handler->options[\'order\']);
    return $order;
  }
}',
      'id' => 'php',
      'table' => 'views',
      'field' => 'php',
      'relationship' => 'none',
    ),
    'comment_count' => array(
      'exposed' => FALSE,
      'order' => 'DESC',
      'identifier' => 'unsorted',
      'id' => 'comment_count',
      'table' => 'node_comment_statistics',
      'field' => 'comment_count',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'discussion' => 'discussion',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('title', 'Active Discussions');
  $handler->override_option('use_pager', 'mini');
  $handler->override_option('use_more', 1);
  $handler->override_option('use_more_always', 0);
  $handler->override_option('style_plugin', 'list');
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->override_option('path', 'discussions/popular');
  $handler->override_option('menu', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->override_option('items_per_page', 5);
  $handler->override_option('use_pager', '0');
  $handler->override_option('block_description', '');
  $handler->override_option('block_caching', -1);

  $views[$view->name] = $view;

  // Exported view: recently_approved_articles
  $view = new view;
  $view->name = 'recently_approved_articles';
  $view->description = 'Recently Approved Articles';
  $view->tag = '';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'title' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 1,
        'max_length' => '70',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'stamp' => array(
      'exposed' => FALSE,
      'order' => 'DESC',
      'identifier' => 'unsorted',
      'granularity' => 'second',
      'id' => 'stamp',
      'table' => 'workflow_node',
      'field' => 'stamp',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'status' => array(
      'operator' => '=',
      'value' => '1',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status',
      'table' => 'node',
      'field' => 'status',
      'relationship' => 'none',
    ),
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'article' => 'article',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
    ),
    'sid' => array(
      'operator' => 'in',
      'value' => array(
        '11' => '11',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'sid',
      'table' => 'workflow_node',
      'field' => 'sid',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('title', 'Recent Articles');
  $handler->override_option('items_per_page', 3);
  $handler->override_option('style_plugin', 'list');
  $handler = $view->new_display('block', 'Frontpage Recent Articles', 'block_1');
  $handler->override_option('block_description', '');
  $handler->override_option('block_caching', -1);

  $views[$view->name] = $view;

  return $views;
}
