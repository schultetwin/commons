<?php
/**
 * @file Features support.
 * Workflow Features integration.
 */


/**
 * Implementation of hook_features_export_options().
 */
function dy_workflow_features_export_options() {
	$workflow = workflow_get_all();
	$options = array();
	foreach($workflow as $key => $name){
		$options[$name] = $name;
	}
	
	return $options;
}

/**
 * Implementation of hook_features_export().
 */
function dy_workflow_features_export($data, &$export, $module_name = '') {
	// The filter_default_formats() hook integration is provided by the
	// features module so we need to add it as a dependency.
	$export['dependencies']['features'] = 'features';
	$export['dependencies']['workflow'] = 'workflow';
	
	$states = array();
	foreach($data as $wid){
		$states = _dy_workflow_get_states($wid) + $states;
	}
	
	foreach($states as $state){
		$state_export[$state->state_name] = $state->workflow_name .': '.$state->state_name;
	}
		
	$transitions = _dy_workflow_get_transitions($states);
	$access = _dy_workflow_get_workflow_access($states);
		
	foreach($data as $w_name){
		$export['features']['dy_workflow'][$w_name] = $w_name;
		$export['features']['dy_workflow_enable']['Yes'] = t('Yes');
	}
	
  return array();
}

/**
 * Implementation of hook_features_export_render().
 */
function dy_workflow_features_export_render($module, $data) {
	$code = array();
	$code[] = '  $workflow = array();';
	$code[] = '';

	$states = array();
	foreach($data as $w_name){
		$states = _dy_workflow_get_states($w_name) + $states;
		
		$workflow_name = features_var_export($w_name);
		$type_map = _dy_workflow_get_type_map($w_name);	//TODO: Change the type to array map 
		if(count($type_map)>0){
			$types = features_var_export($type_map, '  ');
			$code[] = "  // Exported workflow type map: {$w_name}";
			$code[] = "  \$workflow[{$workflow_name}]['type_map'] = {$types};";
			$code[] = "";
		}
	}
	
	foreach($states as $state){
		$state_export[$state->state_name] = $state->workflow_name .': '.$state->state_name;
	}
		
	$transitions = _dy_workflow_get_transitions($states);
	$access = _dy_workflow_get_workflow_access($states);
	

	foreach($states as $sid => $state){
		$workflow['workflow_name'] = $state->workflow_name;
		$workflow['state_name'] = $state->state_name;
		$workflow['transitions'] = $transitions['transition'][$sid];
		$workflow['access'] = $access['access'][$sid];
		
		$workflow_name = features_var_export($state->workflow_name);
		$workflow_state_name = features_var_export($state->state_name);
		$workflow_export = features_var_export($workflow, '  ');
		$code[] = "  // Exported workflow states: {$state->workflow_name} - {$state->state_name}";
		$code[] = "  \$workflow[{$workflow_name}][{$workflow_state_name}] = {$workflow_export};";
		$code[] = "";		
	}

	$code[] = '  return $workflow;';
  $code = implode("\n", $code);
  return array('features_default_workflow' => $code);
}

/**
 * Implementation of hook_features_export_revert().
 */
function dy_workflow_features_revert($module) {
  dy_workflow_features_rebuild($module);
}

/**
 * Implementation of hook_features_rebuild().
 */
function dy_workflow_features_rebuild($module) {
	if ($defaults = features_get_default('dy_workflow', $module)) {
		foreach($defaults as $w_name => $states){
			$wid = db_result(db_query("SELECT wid FROM {workflows} WHERE name = '%s'", $w_name));
			
			if(empty($wid)){
				//TODO: Add new workflow first
			}
			
			if(!empty($wid)){
				unset($states['type_map']);
				_dy_workflow_add_new_states($wid, $w_name, $states);
			}
		}
	}
}

/**
 * Implementation of hook_features_export_options().
 */
function dy_workflow_field_features_export_options() {
	$workflow = workflow_get_all();
	$options = array();
	foreach($workflow as $key => $name){
		$options[$name] = $name;
	}
	
	return $options;
}

/**
 * Implementation of hook_features_export().
 */
function dy_workflow_field_features_export($data, &$export, $module_name = '') {
	// The filter_default_formats() hook integration is provided by the
	// features module so we need to add it as a dependency.
	$export['dependencies']['features'] = 'features';
	$export['dependencies']['workflow_fields'] = 'workflow_fields';
			
	$states = array();
	foreach($data as $w_name){
		$export['features']['dy_workflow_field'][$w_name] = $w_name;

		$states = _dy_workflow_get_states($w_name) + $states;
	}

  return array();
}

/**
 * Implementation of hook_features_export_render().
 */
function dy_workflow_field_features_export_render($module, $data) {
	$code = array();
	$code[] = '  $workflow_field = array();';
	$code[] = '';

	$states = array();
	foreach($data as $w_name){
		$states = _dy_workflow_get_states($w_name) + $states;
	}
	
	$workflow_field_access = _dy_workflow_field_get_fields_access($states);

	foreach($states as $sid => $state){
		$workflow_field = $workflow_field_access['field_access'][$sid];
		
		$workflow_name = features_var_export($state->workflow_name);
		$workflow_state_name = features_var_export($state->state_name);
		$workflow_field_export = features_var_export($workflow_field, '  ');
		$code[] = "  // Exported workflow field: {$state->workflow_name} - {$state->state_name}";
		$code[] = "  \$workflow_field[{$workflow_name}][{$workflow_state_name}] = {$workflow_field_export};";
		$code[] = "";		
	}
	
	$code[] = '  return $workflow_field;';
  $code = implode("\n", $code);
  return array('features_default_workflowfield' => $code);
}

/**
 * Implementation of hook_features_export_revert().
 */
function dy_workflow_field_features_revert($module) {
  dy_workflow_field_features_rebuild($module);
}

/**
 * Implementation of hook_features_rebuild().
 */
function dy_workflow_field_features_rebuild($module) {
	if ($defaults = features_get_default('dy_workflow_field', $module)) {
		foreach($defaults as $w_name => $states){
			$wid = db_result(db_query("SELECT wid FROM {workflows} WHERE name = '%s'", $w_name));
			
			if(empty($wid)){
				//TODO: Add new workflow first
			}
			
			if(!empty($wid)){
				_dy_workflow_field_add_new_access($wid, $w_name, $states, TRUE);
			}
		}
	}
}

function dy_workflow_enable_features_export($data, &$export, $module_name = '') {
//
}

function dy_workflow_enable_features_export_render($module, $data) {
	$enable = array_pop($data);
	if($enable == 'Yes') {		
		$code[] = "  // Import the workflow when enable the module";
		$code[] = "  workflow_features_enable_feature();";
		$code[] = "";
		
		$code[] = '  return array();';
	  $code = implode("\n", $code);
	  return array('enable' => $code);
	}
}

function _dy_workflow_get_states($w_name){
	$all_workflow = workflow_get_all();
	$wid = array_search($w_name, $all_workflow);
	
	//$workflow_name = workflow_get_name($wid);
	$states = workflow_get_states($wid);
	$states_name = array();
	if(!is_array($states)){
		return $states_name;
	}
	
	foreach($states as $sid => $state){
		//$states_name[$sid] = $workflow_name .': '.$state;
		$states_name[$sid] = (object)array('workflow_name'=>$w_name, 'state_name'=>$state);
	}
	return $states_name;
}

function _dy_workflow_get_transitions($states = array()){
	$all_states = workflow_get_states();
	$all_roles = user_roles();

	$sids = implode(',', array_keys($states));
	$result = db_query("SELECT * FROM {workflow_transitions} WHERE sid in (%s)", empty($sids) ? 0 : $sids);
	
	while($state = db_fetch_object($result)){
		$roles = array_filter(explode(',', $state->roles));
		foreach($roles as &$role){
			$role = !empty($all_roles[$role]) ? $all_roles[$role] : $role;
		}
		
		$transitions[$state->sid][$states[$state->sid]->state_name][$states[$state->target_sid]->state_name] = array_fill_keys($roles, 1);
		
		$transitions_export[$states[$state->sid]->state_name] = $all_states[$state->sid] .' -> '. $all_states[$state->target_sid] .' | '. implode(',', $roles);
	}
	
	return array('transition'=>$transitions, 'export'=>$transitions_export);
}

function _dy_workflow_get_workflow_access($states = array()){
	$all_states = workflow_get_states();
	$all_roles = user_roles();
	$all_roles[-1] = 'author';
	
	if(module_exists('workflow_access')){
		$sids = implode(',', array_keys($states));
		$result = db_query("SELECT * FROM {workflow_access} WHERE sid in (%s)", empty($sids) ? 0 : $sids);
		
		while($state = db_fetch_object($result)){
			$access[$state->sid][$states[$state->sid]->state_name][$all_roles[$state->rid]] = array('grant_view'=>$state->grant_view, 'grant_update'=>$state->grant_update, 'grant_delete'=>$state->grant_delete);
			
			$role = str_replace(' ', '_', $all_roles[$state->rid]);
			$access_export[$states[$state->sid]->state_name.'-'.$role] = $all_states[$state->sid] .' | '. $all_roles[$state->rid] . ' | ' . 'View:' . $state->grant_view . ', Edit:' . $state->grant_edit . ', '. 'Delete:' . $state->grant_delete; 
		}
	}
	
	return array('access'=>$access, 'export'=>$access_export);
}

function _dy_workflow_get_type_map($w_name){
	$all_workflow = workflow_get_all();
	$wid = array_search($w_name, $all_workflow);
	
	$type_map = array();
	$result = db_query("SELECT type FROM {workflow_type_map} WHERE wid = %d", $wid);
	while($type = db_fetch_object($result)){
		$type_map[$type->type] = $type->type;
	}

	return $type_map;


	if(is_array($type_map)){
		return $type_map;
	}else{
		return array();
	}
	
}

function _dy_workflow_user_roles($reset = FALSE){
	static $roles;
	
	if(!$reset) {
		return $roles;
	}
	
	$roles = user_roles();
	$roles['author'] = 'author';
	
	return $roles;
}

function _dy_workflow_add_new_states($wid, $w_name, $states){
	$default_states_name = array_keys($states);
	$current_states_name = workflow_get_states($wid);
	$current_states_sid = array_keys($current_states_name);
	
	//Delete old states
	db_query('DELETE ws, wt, wa FROM {workflow_states} AS ws LEFT JOIN {workflow_transitions} AS wt ON ws.sid = wt.sid LEFT JOIN {workflow_access} AS wa ON ws.sid = wa.sid WHERE  ws.sid IN (%s)', implode(',', $current_states_sid));
	
	//Add new states
	foreach($default_states_name as $state_name){
		if($state_name == '(creation)'){
			$c_state = array(
				'wid' => $wid,
				'state' => $state_name,
				'sysid' => WORKFLOW_CREATION,
				'weight' => WORKFLOW_CREATION_DEFAULT_WEIGHT
			);
		}else{
			$c_state = array(
				'wid' => $wid,
				'state' => $state_name,
				'sysid' => 0,
				'weight' => 0
			);
		}
		
		workflow_state_save($c_state);
	}
	
	//Get new states
	$current_states_name = workflow_get_states($wid);
	foreach($current_states_name as $sid => $state_name){
		$new_states[$state_name] = $sid; 
	}
	
	foreach($states as $state){
		//Add new transitions & access
		$transitions = array();
		if(is_array($state['transitions'])){
			foreach($state['transitions'] as $from => $to_data){
				foreach ($to_data as $to => $role_data) {
					$new_role_data = array();
					$roles = _dy_workflow_user_roles(TRUE);
					foreach($role_data as $role_name => $cando){
						if(($rid = array_search($role_name, $roles)) !== FALSE){
							$new_role_data[$rid] = 1;
						}else{
							//TODO: Add this part for not exist this role, need add role
						}
					}
					$transitions[$new_states[$from]][$new_states[$to]] = $new_role_data;
				}
			}
		}
		workflow_update_transitions($transitions);
		
		//Add new workflow access
		$workflow_access = array();
		if(!is_array($state['access'])){
			continue;
		}
		$state_access = array_pop($state['access']);
		$roles = _dy_workflow_user_roles(TRUE);
		if(is_array($state_access)){
			foreach($state_access as $role_name => $access){
				$workflow_access = $access;
				$workflow_access['sid'] = $new_states[$state['state_name']];
	
				if(($rid = array_search($role_name, $roles)) !== FALSE){
					$workflow_access['rid'] = $role_name == 'author' ? -1 : $rid;
				}else{
					//TODO: add new role;
				}
				
				extract($workflow_access);
				db_query("INSERT INTO {workflow_access} (sid, rid, grant_view, grant_update, grant_delete) VALUES (%d, %d, %d, %d, %d)", $sid, $rid, $grant_view, $grant_update, $grant_delete);
			}
		}
	}
}

function _dy_workflow_field_get_fields_access($states = array()){
	$all_states = workflow_get_states();
	$all_roles = user_roles();
	$all_roles[-1] = 'author';
	
	if(module_exists('workflow_fields')){
		$sids = implode(',', array_keys($states));
		$result = db_query("SELECT * FROM {workflow_fields} WHERE sid in (%s)", empty($sids) ? 0 : $sids);
		
		while($state = db_fetch_object($result)){
			$visible_roles = explode(',', $state->visible_roles);
			array_walk($visible_roles, '_dy_workflow_field_get_role_name', $all_roles);
			$editable_roles = explode(',', $state->editable_roles);
			array_walk($editable_roles, '_dy_workflow_field_get_role_name', $all_roles);
	
			$field_access[$state->sid][$state->type][$state->name/*field_name*/] = array('visible_roles'=>implode(',', array_filter($visible_roles)), 'editable_roles'=>implode(',', array_filter($editable_roles)));
		}
	}
	
	return array('field_access'=>$field_access, 'export'=>$field_access_export);
}

function _dy_workflow_field_get_role_name(&$item, $key, $all_roles){
	if(substr($item, 0, 5) == 'field') return $item;
	$item = $all_roles[$item];
}

function _dy_workflow_field_get_role_rid(&$item, $key, $all_role_rids){
	if(substr($item, 0, 5) == 'field') return $item;
	$item = $all_role_rids[$item];
}

function _dy_workflow_field_add_new_access($wid, $w_name, $states, $reset = FALSE){
//	$default_states_name = array_keys($states);
	$current_states_name = workflow_get_states($wid);
	$current_states_sid = array_keys($current_states_name);

	if($reset){
		//Delete old states
		db_query('DELETE FROM {workflow_fields} WHERE sid IN (%s)', implode(',', $current_states_sid));
	}else{
		$sids = array();
		foreach($states as $state_name => $state){
			$sids[] = array_search($state_name, $current_states_name); 
		}
		$sids = array_filter($sids);
		db_query('DELETE FROM {workflow_fields} WHERE sid IN (%s)', count($sids) > 0 ? implode(',', $sids) : 0);
	}

	$all_roles = user_roles();
	$all_roles[-1] = 'author';

	foreach($all_roles as $rid => $r_name){
		$all_role_rids[$r_name] = $rid;
	}

	foreach($states as $state_name => $state){
		$sid = array_search($state_name, $current_states_name);
		foreach($state as $ct_name => $fields){
			foreach($fields as $field_name => $access){
				$visible_roles = explode(',', $access['visible_roles']);
				$editable_roles = explode(',', $access['editable_roles']);

				array_walk($visible_roles, _dy_workflow_field_get_role_rid, $all_role_rids);
				array_walk($editable_roles, _dy_workflow_field_get_role_rid, $all_role_rids);

				db_query("INSERT INTO {workflow_fields} (sid, name, type, visible_roles, editable_roles) VALUES (%d, '%s', '%s', '%s', '%s')", $sid, $field_name, $ct_name, implode(',', $visible_roles), implode(',', $editable_roles));
			}
		}
	}
}


