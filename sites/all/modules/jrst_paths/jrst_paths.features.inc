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
  return array();
}
