<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function protected_file_downloads_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "features_override" && $api == "features_override") {
    return array("version" => 1);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}
