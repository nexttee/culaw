<?php

/**
 * Outputs a form to roll back a list of deposited students based on their LSAC numbers.
 */
function cls_mcl_student_role_bulk_update() {

  drupal_set_title(t('Enter a batch of students\' UID\'s, names or LSAC account numbers to update'));
  drupal_add_css(drupal_get_path('module', 'cls_mcl') . '/css/bulk_update.css', array('every_page' => FALSE));

  $output = theme('bulk_update', array('form' => drupal_get_form('cls_mcl_student_role_update_form')));

  return $output;
}

/**
 * cls_mcl_deposited_student_roll_back Form.
 */
function cls_mcl_student_role_update_form($form, &$form_state) {

  drupal_add_js(drupal_get_path('module', 'cls_mcl') . '/js/bulk_update.js', array('every_page' => FALSE));

  $form['update_type'] = array('#type' => 'select',
    '#title' => t('Which action do you wish to perform?'),
    '#options' => array('Cancel' => t('Cancel'),
                        'Downgrade' => t('Downgrade')),
    '#default_value' => 'Downgrade',
    '#required' => TRUE,
  );
  
  $roles_array = user_roles();
  $anon_index = array_search("anonymous user", $roles_array);
  unset($roles_array[$anon_index]); // Removes "anonymous user"
  $auth_index = array_search("authenticated user", $roles_array);
  unset($roles_array[$auth_index]); // Removes "authenticated user"
  //$roles_array['All'] = t('All Roles');
  
  $form['roles_to_remove'] = array(
    '#type' => 'select',
    '#title' => 'Roles to remove:',
    '#options' => $roles_array,
    '#required' => TRUE,
    '#multiple' => TRUE,
    '#default_value' => array(),
  );
  
  $form['divider'] = array(
    '#type' => 'markup',
    '#markup' => '<div style="clear: both;"></div>',
  );
  
  $form['account_id_type'] = array('#type' => 'select',
    '#title' => t('Account Identifier:'),
    '#options' => array('LSAC' => t('LSAC account number'),
                        'Username' => t('User name'),
                        'UID' => t('UID')),
    '#default_value' => 'LSAC',
    '#required' => TRUE,
  );

  $form['account_ids'] = array(
    '#type' => 'textarea',
    '#title' => t('UID(s), name(s) or LSAC Account Number(s) (one per line)'),
    '#required' => TRUE,
    '#default_value' => '',
    '#rows' => 15,
    '#cols' => 64,
  );
  
  //array_pop($roles_array); // Removes "All Roles"
  
  $form['roles_to_add'] = array(
    '#type' => 'select',
    '#title' => t('Roles to add (Optional):'),
    '#options' => $roles_array,
    '#default_value' => '',
    '#required' => FALSE,
    '#multiple' => TRUE,
  );

  $form['divider2'] = array(
    '#type' => 'markup',
    '#markup' => '<div style="clear: both;"></div>',
  );

  $submit = array();
  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions'] = array(
    '#weight' => 100,
  );

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Process users'),
    '#submit' => $submit + array('cls_mcl_student_role_update_form_submit'),
  );

  return $form;
}

/**
 * cls_mcl_deposited_student_roll_back Form validation.
 */
function cls_mcl_student_role_update_form_validate($form, &$form_state) {
  if (!isset($form_state['values']['update_type']) || $form_state['values']['update_type'] == '') {
    form_set_error('update_type', t('Update type must be selected.'));
    return false;
  }
  if (!isset($form_state['values']['roles_to_remove']) || $form_state['values']['roles_to_remove'] == '') {
    form_set_error('roles_to_remove', t('Roles to Remove must be selected.'));
    return false;
  }
  if (!isset($form_state['values']['account_id_type']) || $form_state['values']['account_id_type'] == '') {
    form_set_error('account_id_type', t('Account Identifier must be selected.'));
    return false;
  }
  if (!isset($form_state['values']['account_ids']) || trim($form_state['values']['account_ids']) == '') {
    form_set_error('account_ids', t('List of Account Identifiers cannot be empty.'));
    return false;
  }
  return _cls_mcl_validate_bulk_update_account_identifiers($form_state['values']['account_id_type'], $form_state['values']['account_ids']);
}

function _cls_mcl_validate_bulk_update_account_identifiers($account_id_type, $account_ids) {
  $return_flag = true;
  $account_ids = explode("\n", trim($account_ids));  
  if ($account_id_type == 'LSAC') {
    foreach ($account_ids as $key => $lsac) {
      $lsac = trim($lsac);
      $lsac_validation_data = cls_mcl_validate_lsac($lsac);
      if(!$lsac_validation_data['result']){
  	    form_set_error('lsac', t('LSAC account number ' . $lsac . $lsac_validation_data['error']));
        $return_flag = false;
      }
    } 
  }
  else if ($account_id_type == 'Username') {
    foreach ($account_ids as $key => $username) {
      $username = trim($username);
      if (!empty($username)) {
        if(!cls_mcl_validation_rule_email($username) && !cls_mcl_validation_rule_alpha_dash($username)){
  	      form_set_error('user_name', t('User name ' . $username . ' is not in the right format.'));
          $return_flag = false;
        }
      }
      else {
        form_set_error('user_name', t('User name cannot be empty.'));
        $return_flag = false;
      }
    }
  }
  else if ($account_id_type == 'UID') {
    foreach ($account_ids as $key => $uid) {
      $uid = trim($uid);
      if (empty($uid) || !is_numeric($uid)) {
        form_set_error('uid', t('User ID ' . $uid . ' is not in the right format.'));
        $return_flag = false;  
      }
    }
  }
  return $return_flag;
}

/**
 * cls_mcl_deposited_student_roll_back Form submit handler.
 */
function cls_mcl_student_role_update_form_submit($form, &$form_state) {
  
  $account_ids = explode("\n", $form_state['values']['account_ids']);
  
  if ($form_state['values']['account_id_type'] == 'LSAC') {
    foreach ($account_ids as $key => $lsac) {
      $lsac = trim($lsac);

      if (!empty($lsac)) {
      
        // 1. Look up user by LSAC number
        // 2. Get all of this user's roles
        // 3. Remove "Deposited User" role, add "Admitted Student" role (if not already present).
      
        $user_query = db_select('field_data_cls_mcl_lsac_account_number', 'f');
        $result = $user_query
          ->fields('f', array('cls_mcl_lsac_account_number_value', 'entity_id'))
          ->condition('cls_mcl_lsac_account_number_value', $lsac)
          ->condition('entity_type', 'user')
          ->execute();

        if ($record = $result->fetchAssoc()) {
          if($record['cls_mcl_lsac_account_number_value'] && $record['entity_id']){
          
            $edited_user = user_load($record['entity_id']);
          
            if ($edited_user) {
              if ($form_state['values']['update_type'] == 'Cancel') {
              	// Remove all roles and don't add any	
                $edited_user = _cls_mcl_update_student_roles($edited_user, array('All'));
                // Deactivate the user
                // Verify that this is the requirement. 
                // Otherwise, delete user and reassign his content
                user_cancel($form_state['values'], $edited_user->uid, 'user_cancel_block');
                drupal_set_message(t('User account(s) were cancelled successfully.'));
              }
              else if ($form_state['values']['update_type'] == 'Downgrade') {
                $edited_user = _cls_mcl_update_student_roles($edited_user, $form_state['values']['roles_to_remove'], $form_state['values']['roles_to_add']);
                drupal_set_message(t('User account(s) were downgraded successfully.'));
              }         
            
            }
          }
        }
        if (empty($record) || !isset($record['entity_id']) || empty($record['entity_id'])) {
          form_set_error('lsac', t('No user with this LSAC account number exists: ') . $lsac);
        }
    	
      }
    } 
  }
  else if ($form_state['values']['account_id_type'] == 'Username') {
    foreach ($account_ids as $key => $username) {
      $username = trim($username);

      if (!empty($username)) {
      
        // 1. Load user by name
        // 2. Get all of this user's roles
        // 3. Remove "Deposited User" role, add "Admitted Student" role (if not already present).
          
        $edited_user = user_load_by_name($username);
          
          if ($edited_user) {
          	if ($form_state['values']['update_type'] == 'Cancel') {
              // Remove all roles and don't add any	
              $edited_user = _cls_mcl_update_student_roles($edited_user, array('All'));
              // Deactivate the user
              user_cancel($form_state['values'], $edited_user->uid, 'user_cancel_block');
              drupal_set_message(t('User account(s) were cancelled successfully.'));
            }
            else if ($form_state['values']['update_type'] == 'Downgrade') {
              $edited_user = _cls_mcl_update_student_roles($edited_user, $form_state['values']['roles_to_remove'], $form_state['values']['roles_to_add']);
              drupal_set_message(t('User account(s) were downgraded successfully.'));
            }         
            
          }
          else {
            form_set_error('user_name', t('No user with this user name exists: ') . $username);
          }
    	
      }
    }
  }
  else if ($form_state['values']['account_id_type'] == 'UID') {
    foreach ($account_ids as $key => $uid) {
      $uid = trim($uid);

      if (!empty($uid)) {
      
        // 1. Load user by UID
        // 2. Get all of this user's roles
        // 3. Remove "Deposited User" role, add "Admitted Student" role (if not already present).
          
        $edited_user = user_load($uid);
          
          if ($edited_user) {
            if ($form_state['values']['update_type'] == 'Cancel') {
              // Remove all roles and don't add any	
              $edited_user = _cls_mcl_update_student_roles($edited_user, array('All'));
              // Deactivate the user
              user_cancel($form_state['values'], $edited_user->uid, 'user_cancel_block');
              drupal_set_message(t('User account(s) were cancelled successfully.'));
            }
            else if ($form_state['values']['update_type'] == 'Downgrade') {
              $edited_user = _cls_mcl_update_student_roles($edited_user, $form_state['values']['roles_to_remove'], $form_state['values']['roles_to_add']);
              drupal_set_message(t('User account(s) were downgraded successfully.'));
            }         
            
          }
          else {
            form_set_error('uid', t('No user with this uid exists: ') . $uid);
          }
          
      }
    }
  }
  
}

/**
 * Function to remove and add specified roles from/to the provided user. 
 */
function _cls_mcl_update_student_roles($edited_user, $roles_to_remove=array(), $roles_to_add=array()) {
  $user_info = array();
  $user_info['roles'] = $edited_user->roles;
  
  if (in_array('All', $roles_to_remove)) {
  	// Remove all roles except "authenticated user"
    $user_info['roles'] = array(2 => 'authenticated user');
  }
  else if (!empty($roles_to_remove)) {
  	foreach ($roles_to_remove as $rid) {
  	  if (array_key_exists($rid, $user_info['roles'])) {
  	    unset($user_info['roles'][$rid]);
  	  }
  	}
  }
            
  if (!empty($roles_to_add)) {
    // There are some roles to add
    // Get names of roles to be added
    $role_query = db_select('role', 'r')
        ->fields('r', array('rid', 'name'))
        ->condition('r.rid', $roles_to_add, 'IN');
    $role_result = $role_query->execute();
    while ($role_record = $role_result->fetchAssoc()) {
      // Assign specified role to updated user
  	  $user_info['roles'][$role_record['rid']] = $role_record['name'];
    }
        
  }
    
  $edited_user = user_save($edited_user, $user_info);
          
  return $edited_user;
}