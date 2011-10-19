<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function jrst_paths_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_rules_defaults().
 */
function jrst_paths_rules_defaults() {
  return array(
    'rules' => array(
      'rules_change_path_when_wiley_id_isset' => array(
        '#type' => 'rule',
        '#set' => 'event_node_update',
        '#label' => 'Change path when Wiley ID Isset',
        '#active' => 1,
        '#weight' => '8',
        '#categories' => array(
          '0' => 'Path Setting',
          'jrst_paths' => 'jrst_paths',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#type' => 'condition',
            '#settings' => array(
              'type' => array(
                'article' => 'article',
              ),
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#name' => 'rules_condition_content_is_type',
            '#info' => array(
              'label' => 'Updated content is Article',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Node',
            ),
            '#weight' => 0,
          ),
          '1' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Check if content workflow state is Published',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Node',
                ),
              ),
              'module' => 'Workflow',
            ),
            '#name' => 'workflow_check_state',
            '#settings' => array(
              'state' => array(
                '11' => '11',
              ),
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#type' => 'condition',
          ),
          '2' => array(
            '#settings' => array(
              'field_name' => 'field_article_wiley_id',
              '#argument map' => array(
                'node' => 'node',
              ),
              'value' => array(
                '0' => array(
                  'value' => '',
                ),
              ),
              'code' => '',
              'vars' => array(),
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'code' => array(
                    '0' => ':global',
                  ),
                  'value|0|value' => array(
                    '0' => ':global',
                  ),
                ),
              ),
            ),
            '#type' => 'condition',
            '#name' => 'content_rules_field_has_value',
            '#info' => array(
              'label' => 'Updated content\'s field \'field_article_wiley_id\' has value',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'eval input' => array(
                '0' => 'code',
                '1' => 'value|0|value',
              ),
              'module' => 'CCK',
            ),
            '#weight' => 0,
            '#negate' => 1,
          ),
          '3' => array(
            '#negate' => 1,
            '#weight' => 0,
            '#info' => array(
              'label' => 'Path has alias(es)',
              'module' => 'Path',
              'eval input' => array(
                '0' => 'src',
              ),
            ),
            '#name' => 'rules_condition_url_has_alias',
            '#settings' => array(
              'src' => 'article/[node:field_article_wiley_id-raw]',
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'src' => array(
                    '0' => 'node',
                    '1' => ':global',
                  ),
                ),
              ),
            ),
            '#type' => 'condition',
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#type' => 'action',
            '#settings' => array(
              'dst' => 'article/[node:field_article_wiley_id-raw]',
              'replace' => '-',
              '#argument map' => array(
                'node' => 'node',
              ),
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'dst' => array(
                    '0' => 'node',
                    '1' => ':global',
                  ),
                ),
              ),
            ),
            '#name' => 'rules_action_node_path_alias',
            '#info' => array(
              'label' => 'Create or delete updated content\'s URL alias',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Path',
              'eval input' => array(
                '0' => 'dst',
              ),
            ),
            '#weight' => 0,
          ),
        ),
        '#version' => 6003,
      ),
    ),
  );
}
