<?php

/**
 * @file
 * Functions related to My Columbia Law password recovery.
 */

/**
 * Describes password recovery steps.
 */ 
function cls_mcl_password_recovery_steps() {
  return array(
      1 => array(
        'form' => 'cls_mcl_password_recovery_step_1',
      ),
      2 => array(
        'form' => 'cls_mcl_password_recovery_step_2',
      ),
      3 => array(
        'form' => 'cls_mcl_password_recovery_step_3',
      ),
    );
} 

/**
 * Generates MCL password recovery form.
 */
function cls_mcl_password_recovery($form, &$form_state, $instance_id) {
  global $user;

  if (empty($form_state['step'])) {
    $form_state['step'] = 1;
    $form_state['step_information'] = cls_mcl_password_recovery_steps();
  }
  $step = &$form_state['step'];
 
  $form = $form_state['step_information'][$step]['form']($form, $form_state, $instance_id);
 
  if ($step < count($form_state['step_information'])) {
    $form['next'] = array(
      '#type' => 'submit',
      '#value' => t('Proceed'),
      '#name' => 'next',
      '#button_type' => 'mcl-submit-button',
      '#submit' => array('cls_mcl_password_recovery_next_submit'),
    );
  }
  else {
  	// If there are no more steps, use the default submit handler.
  	$form['submit'] = array(
      '#type' => 'submit',
      '#button_type' => 'mcl-submit-button',
      '#value' => t('Change Your Password'),
      '#submit' => array('cls_mcl_password_recovery_submit'),
    );
  }
 
  $form['next']['#validate'] = array();
  if (function_exists($form_state['step_information'][$step]['form'] . '_validate')) {
    $form['next']['#validate'] = array($form_state['step_information'][$step]['form'] . '_validate');
  }
  if (isset($form['#validate'])) {
    $form['next']['#validate'] = array_merge($form['next']['#validate'], $form['#validate']);
    unset($form['#validate']);
  }
 
  if (function_exists($form_state['step_information'][$step]['form'] . '_submit')) {
    $form['next']['#submit'] = array_merge($form_state['step_information'][$step]['form'] . '_submit', $form['next']['#submit']);
  }
  if (isset($form['#submit'])) {
    $form['next']['#submit'] = array_merge($form['#submit'], $form['next']['#submit']);
    unset($form['#submit']);
  }
 
  return $form;
}

/**
 * Submit handler for "Next" button.
 *
 * @param $form
 * @param $form_state
 */
function cls_mcl_password_recovery_next_submit($form, &$form_state) {		
  $current_step = &$form_state['step'];
  $form_state['step_information'][$current_step]['stored_values'] = $form_state['values'];
  if ($current_step < count($form_state['step_information'])) {
    $current_step++;
    if (!empty($form_state['step_information'][$current_step]['stored_values'])) {
      $form_state['values'] = $form_state['step_information'][$current_step]['stored_values'];
    }
    else {
      $form_state['values'] = array();
    }
    $form_state['rebuild'] = TRUE;
    return;
  }
}

/**
 * Generates Step 1 of password recovery form.
 */
function cls_mcl_password_recovery_step_1(&$form, &$form_state, $instance_id) {

  $form['name'] = array('#type' => 'textfield',
    '#title' => t('Please Enter Your Email Address'),
    '#size' => 60,
    '#maxlength' => USERNAME_MAX_LENGTH,
    '#required' => TRUE,
  );
  $form['instance_id'] = array(
    '#type' => 'value',
    '#value' => $instance_id
  );
  return $form;
}

/**
 * Validates data from Step 1 of the password recovery form.
 * Displays error message if validation fails.
 */
function cls_mcl_password_recovery_step_1_validate($form, &$form_state, $instance_id) {
  $email_validation_data = cls_mcl_validate_email_existence($form_state['values']['name'], $form_state['values']['instance_id']);
  if (!$email_validation_data['result']){
    form_set_error('email', t('Email' . $email_validation_data['error']));
    $log_params = array('type' => 4, //failed password reset attempt
                        'data' => array('email' => $form_state['values']['name']),
                        'uid' => '',
                        'ip_address' => ip_address(),
                        'created' => REQUEST_TIME,
                        );
    cls_mcl_create_audit_log($log_params);
    return false;
  }
  return true;
}

/**
 * Generates Step 2 of password recovery form.
 */
function cls_mcl_password_recovery_step_2(&$form, &$form_state) {
  //print_r( $form_state['step_information'][1]['stored_values']);
  if(isset($form_state['step_information'][1]['stored_values']['name'])){
    $edited_user = user_load_by_name($form_state['step_information'][1]['stored_values']['name']);
    //print_r($edited_user->cls_mcl_security_question['und'][0]['value']);
    if($edited_user && $edited_user->cls_mcl_security_question['und'][0]['value'] && $edited_user->cls_mcl_security_answer['und'][0]['value']){
      $form['security_question'] = array('#markup' => $edited_user->cls_mcl_security_question['und'][0]['value'],
                         '#prefix' => "<p id='mcl-password-recovery-security-question'><strong>Your Security Question:</strong> ",
                         '#suffix' => "</p>");                        
      $form['security_answer'] = array('#type' => 'textfield',
        '#title' => t('Please Enter Your Security Answer'),
        '#size' => 100,
        '#maxlength' => 100,
        '#required' => TRUE,
      );
      $form['uid'] = array('#type' => 'value',
        '#value' => $edited_user->uid,
      );
    }
  }
  if(!isset($form['security_question']) || !isset($form['security_answer'])) {
    $form['error_text'] = array('#markup' => "Sorry, we were unable to find your account data. Please contact the site administrator for help.",
                         '#prefix' => "<p id='mcl-password-recovery-error-text'>",
                         '#suffix' => "</p>");
  }
  return $form;
}

/**
 * Validates data from Step 2 of the password recovery form.
 * Displays error message if validation fails.
 */
function cls_mcl_password_recovery_step_2_validate($form, &$form_state) {
  $security_answer_validation_data = cls_mcl_validate_security_answer_correctness($form_state['values']['security_answer'], $form_state['values']['uid']);
  if (!$security_answer_validation_data['result']){
    form_set_error('security_answer', t('Security Answer' . $security_answer_validation_data['error']));
    $log_params = array('type' => 4, //failed password reset attempt
                        'data' => array('email' => $form_state['step_information'][1]['stored_values']['name'],
                                        'security_answer' => $form_state['values']['security_answer']),
                        'uid' => '',
                        'ip_address' => ip_address(),
                        'created' => REQUEST_TIME,
                        );
    cls_mcl_create_audit_log($log_params);
    return false;
  }
  return true;
}

/**
 * Generates Step 3 of password recovery form.
 */
function cls_mcl_password_recovery_step_3(&$form, &$form_state) {

  $form['password'] = array('#type' => 'password',
    '#title' => t('New Password'),
    '#required' => TRUE,
  );
  $form['password_reenter'] = array('#type' => 'password',
    '#title' => t('Re-enter Password'),
    '#required' => TRUE,
  );
  if(isset($form_state['step_information'][2]['stored_values']['uid'])){
  	$form['uid'] = array('#type' => 'value',
        '#value' => $form_state['step_information'][2]['stored_values']['uid'],
      );
  }
  return $form;
}

/**
 * Validates data from Step 3 of the password recovery form.
 * Displays error message if validation fails.
 */
function cls_mcl_password_recovery_validate($form, &$form_state) {
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
  }else if(!$form_state['values']['uid']){
    form_set_error('uid', t('Sorry, we were unable to find your account data. Please contact the site administrator for help.'));
    $return_flag = false;
  }
  return $return_flag;
}

/**
 * Submit handler for the password recovery form.
 */
function cls_mcl_password_recovery_submit($form, &$form_state) {
  global $user;
  if(isset($form_state['values']['password']) && $form_state['values']['uid']){
  	//Become the admin
  	$old_state = drupal_save_session();
    drupal_save_session(FALSE);
    $user = user_load(1);
    $edited_user = user_load($form_state['values']['uid']);
  	$user_info = array('pass' => $form_state['values']['password']);  	
  	$instance_id = isset($edited_user->cls_mcl_account_type['und'][0]['value']) && !empty($edited_user->cls_mcl_account_type['und'][0]['value']) ? $edited_user->cls_mcl_account_type['und'][0]['value'] : "my_columbia_law";
  	$site_instance = cls_get_site_instance($instance_id);
  	$admitted_site_instance_id = $instance_id == "my_columbia_llm" ? "gls" : "jd";
  	$admitted_site_instance = cls_admissions_admitted_get_site_instance($admitted_site_instance_id);
    $role_prospective = $admitted_site_instance['role_prospective'];
    $role_deposited = $admitted_site_instance['role_deposited'];
    $edited_user = user_save($edited_user, $user_info);
  	if($edited_user){
  	  if (cls_aces2_applicant_load_by_program_email_status(1, $form_state['step_information'][1]['stored_values']['name'], "Deposit") && !in_array($role_deposited, $edited_user->roles)) {
        cls_common_user_add_role_by_name($role_deposited, $edited_user->uid);
      }
      else {
        //cls_common_user_add_role_by_name($role_prospective, $edited_user->uid);
      }
  	  $user = $edited_user;
      $query_array = drupal_get_query_parameters($_GET);
    	if (!empty($query_array['admitted'])) {
      	$form_state['redirect'] = array(
      	   $site_instance['path'] . '/password-recovery/confirmation',
           array('query' => array('admitted' => '1'))
        );
    	}
    	else {
      	$form_state['redirect'] = $site_instance['path'] . '/password-recovery/confirmation';
    	}
  	  user_login_finalize($form_state);
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
  	  $form_state['redirect'] = $site_instance['path'];
  	  $log_params = array('type' => 4, //failed password reset
                          'data' => array('email' => $user->mail,
                                          'name' => $user->name),
                          'uid' => $user->uid,
                          'ip_address' => ip_address(),
                          'created' => REQUEST_TIME,
                          );
      cls_mcl_create_audit_log($log_params);
  	  module_invoke_all('user_logout', $user);
  	}
    drupal_save_session($old_state);
  }
}

/**
* Displays My Columbia Law password recovery form.
*
* @return $html - string containing password recovery window layout
*/
function cls_mcl_display_password_recovery($instance_id) {
  global $user;
  if(!$user->uid){
    $site_instance = cls_get_site_instance($instance_id);
    
  	//drupal_add_css(drupal_get_path('module', 'cls_mcl') . '/css/login.css', array('every_page' => FALSE));
    return theme('password_recovery', array('title' => "My Columbia Law",
                                'path' => $site_instance['path'],
                                'instance_id' => $instance_id,
                                'form' => drupal_get_form('cls_mcl_password_recovery', $instance_id)));
  }
  else{
  	$site_instances = cls_get_site_instances($instance_id);
  	$query_array = drupal_get_query_parameters($_GET);
  	if (!empty($query_array['admitted'])) {
    	drupal_goto($site_instances['admitted_path']);
  	}
  	else {
    	drupal_goto($site_instances['path'] . '/dashboard');
  	}
  }
}

function cls_mcl_display_password_recovery_confirmation($instance_id) {
  $site_instance = cls_get_site_instance($instance_id);
	if (!empty($query_array['admitted'])) {
	  $link_text = 'Continue to the admitted student site';
  	$path = $site_instance['admitted_path'];
	}
	else {
	  $link_text = 'Continue to your dashboard';
  	$path = $site_instance['path'] . '/dashboard';
	}
  return theme('cls_mcl_password_recovery_confirmation', array(
      'title' => "My Columbia Law",
      'path' => $path,
      'instance_id' => $instance_id,
      'link_text' => $link_text
    )
  );
}
