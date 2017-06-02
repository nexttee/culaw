<?php

/**
 * @file
 * Functions related to My Columbia Law password change.
 */

/**
 * Generates password change form.
 */
function cls_mcl_password_change($form, &$form_state, $instance_id) {
  global $user;
  $edited_user = user_load($user->uid);
  if (isset($edited_user->cls_mcl_account_type['und'][0]['value']) && !empty($edited_user->cls_mcl_account_type['und'][0]['value'])) {
  	if ($edited_user->cls_mcl_account_type['und'][0]['value'] != $instance_id) {
  	  $site_instances = cls_get_site_instances($edited_user->cls_mcl_account_type['und'][0]['value']);
  	  drupal_goto($site_instances['path'] . '/change-my-password');
  	}
  }
  $form['password'] = array('#type' => 'password',
    '#title' => t('New Password'),
    '#required' => TRUE,
  );
  $form['password_reenter'] = array('#type' => 'password',
    '#title' => t('Re-enter Password'),
    '#required' => TRUE,
  );
  $form['uid'] = array('#type' => 'value',
    '#value' => $user->uid,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  return $form;
}

/**
 * Validates data in password change form.
 * Displays error message if validation fails.
 */
function cls_mcl_password_change_validate($form, &$form_state) {
  $password_match_data = cls_mcl_validate_equality($form_state['values']['password'], $form_state['values']['password_reenter']);
  $return_flag = true;
  if(!trim($form_state['values']['password'])){
  	form_set_error('password', t('Password is required.'));
    $return_flag = false;
  }else if(!trim($form_state['values']['password_reenter'])){
  	form_set_error('password_reenter', t('"Re-enter password" field is required.'));
    $return_flag = false;
  }else if(!$password_match_data['result']){
  	form_set_error('password', t('Passwords' . $password_match_data['error']));
    $return_flag = false;
  }
  return $return_flag;
}

/**
 * Submit handler for the password change form.
 */
function cls_mcl_password_change_submit($form, &$form_state) {
  global $user;
  if(isset($form_state['values']['password']) && isset($form_state['values']['uid'])){
  	//Become the admin
  	$old_state = drupal_save_session();
    drupal_save_session(FALSE);
    $edited_user = user_load($form_state['values']['uid']);
    $user = user_load(1);
  	$user_info = array('pass' => $form_state['values']['password']);
  	$edited_user = user_save($edited_user, $user_info);
  	if($edited_user){
  	  $user = $edited_user;
  	  drupal_set_message(t('Your password has been successfully changed.'));
  	  if (cls_mcl_check_password($form_state['values']['password'], $user->pass)){
  	    $log_params = array('type' => 3, //successful password reset
                            'data' => array('email' => $user->mail,
                                            'name' => $user->name),
                            'uid' => $user->uid,
                            'ip_address' => ip_address(),
                            'created' => REQUEST_TIME,
                            );
        cls_mcl_create_audit_log($log_params);
  	  }
  	  else {
  	  	$user = drupal_anonymous_user();
  	  	$form_state['redirect'] = "admissions/jd/my-columbia-law";
  	  	$_SESSION['messages']['error'][] = t('Error: Password reset has failed.');
  	    $log_params = array('type' => 4, //failed password reset
                            'data' => array('email' => $user->mail,
                                            'name' => $user->name),
                            'uid' => $user->uid,
                            'ip_address' => ip_address(),
                            'created' => REQUEST_TIME,
                            );
        cls_mcl_create_audit_log($log_params);
  	  }
  	}else{
  	  $user = drupal_anonymous_user();	
  	  $form_state['redirect'] = "admissions/jd/my-columbia-law";
  	  $_SESSION['messages']['error'][] = t('Error: Your password has not been updated.');
  	  $log_params = array('type' => 4, //failed password reset
                          'data' => array('email' => $user->mail,
                                          'name' => $user->name),
                          'uid' => $user->uid,
                          'ip_address' => ip_address(),
                          'created' => REQUEST_TIME,
                          );
      cls_mcl_create_audit_log($log_params);
  	}
    drupal_save_session($old_state);
  }
}

/**
* Displays My Columbia Law password change form.
*
* @return $html - string containing password change layout
*/
function cls_mcl_display_password_change($instance_id) {
  if(cls_mcl_display_password_change_access()){
    return theme('password_change', array('title' => "My Columbia Law",
                                'instance_id' => $instance_id,
                                'form' => drupal_get_form('cls_mcl_password_change', $instance_id)));
  }else{
    return theme('password_recovery', array('title' => "My Columbia Law",
                                'instance_id' => $instance_id,
                                'form' => drupal_get_form('cls_mcl_password_recovery', $instance_id)));
  }
}

/**
* Displays My Columbia Law password change success message.
*
* @return $html - string containing password change success message layout
*/
function cls_mcl_display_password_change_screen($instance = 1) {
  return theme('password_change_success', array('title' => "My Columbia Law"));
}
