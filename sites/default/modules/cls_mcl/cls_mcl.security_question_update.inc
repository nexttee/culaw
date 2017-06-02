<?php

/**
 * @file
 * Functions related to My Columbia Law security question update.
 */

/**
 * Generates security question update form.
 */
function cls_mcl_security_question_update($form, &$form_state, $instance_id) {
  global $user;	
  
  $edited_user = user_load($user->uid);
  if (isset($edited_user->cls_mcl_account_type['und'][0]['value']) && !empty($edited_user->cls_mcl_account_type['und'][0]['value'])) {
  	if ($edited_user->cls_mcl_account_type['und'][0]['value'] != $instance_id) {
  	  $site_instances = cls_get_site_instances($edited_user->cls_mcl_account_type['und'][0]['value']);
  	  drupal_goto($site_instances['path'] . '/update-security-question');
  	}
  }
  $security_question_options = cls_mcl_get_security_question_options($instance_id);
  if(isset($edited_user->cls_mcl_security_question['und'][0]['value'])){
      if(in_array($edited_user->cls_mcl_security_question['und'][0]['value'], $security_question_options)){	  
          $security_question_default_value = array_search($edited_user->cls_mcl_security_question['und'][0]['value'], $security_question_options); 
      }else{
          $security_question_default_value = $edited_user->cls_mcl_security_question['und'][0]['value'];
      }
  }
  $form['error'] = array(
    '#prefix' => '<div id="cls-mcl-account-errors" class="messages error" style="display: none;">',
    '#markup' => '<ul style="display: none;"></ul>',
    '#suffix' => '</div>',
  );	
  $form['security_question_options'] = array(
    '#type' => 'value',
    '#value' => cls_mcl_get_security_question_options($instance_id),
  );
  $form['security_question'] = array('#type' => 'select_or_other',
    '#title' => t('Security Question'),
    '#options' => $form['security_question_options']['#value'],
    '#other' => t('Other (please type your own security question)'),
    '#default_value' => array($security_question_default_value),
    '#required' => TRUE,
    '#multiple' => FALSE,
    '#other_delimiter' => ', ',
    '#other_unknown_defaults' => 'other',
  );
  $form['security_answer'] = array('#type' => 'textfield',
    '#title' => t('Security Answer'),
    '#required' => TRUE,
  );
  $form['instance_id'] = array(
    '#type' => 'value',
    '#value' => $instance_id
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  return $form;
}

/**
 * Validates data in security question update form.
 * Displays error message if validation fails.
 */
function cls_mcl_security_question_update_validate($form, &$form_state) {
  $security_question_validation_data = cls_mcl_validate_security_question(trim($form_state['values']['security_question']), $form_state['values']['instance_id']);
  $security_answer_validation_data = cls_mcl_validate_security_answer(trim($form_state['values']['security_answer']));
  $return_flag = true;
  if(isset($form_state['values']['security_question']) && $form_state['values']['security_question'] == ""){
  	form_set_error('security_question', t('Security question is required'));
  	$return_flag = false;
  }else if(isset($form_state['values']['security_question']) && $form_state['values']['security_question'] == "select_or_other" && $form_state['values']['security_question_other'] == ""){
  	form_set_error('security_question', t('Security question is required'));
  	$return_flag = false;
  }else if(!$security_question_validation_data['result']){
  	form_set_error('security_question', t('Security question' . $security_question_validation_data['error']));
  	$return_flag = false;
  }else if(!$security_answer_validation_data['result']){
  	form_set_error('security_answer', t('Security answer' . $security_answer_validation_data['error']));
  	$return_flag = false;
  }
  return $return_flag;
}

/**
 * Submit handler for the security question update form.
 */
function cls_mcl_security_question_update_submit($form, &$form_state) {
  global $user;
  if(isset($form_state['values'])){
    require_once DRUPAL_ROOT . '/' . variable_get('password_inc', 'includes/password.inc');
    // Update Drupal user
    $edited_user = $user;
    $old_state = drupal_save_session();
    drupal_save_session(FALSE);
    //Become the admin
    $user = user_load(1);
    $userinfo = array();	
	$security_question_options = cls_mcl_get_security_question_options($form_state['values']['instance_id']);
    if(isset($security_question_options[$form_state['values']['security_question']])){
      $userinfo['cls_mcl_security_question']['und'][0]['value'] = $security_question_options[$form_state['values']['security_question']]; 
    }else{
      $userinfo['cls_mcl_security_question']['und'][0]['value'] = trim($form_state['values']['security_question']);
    }
    $userinfo['cls_mcl_security_answer']['und'][0]['value'] = user_hash_password(trim(strtolower($form_state['values']['security_answer'])));
	$edited_user = user_save($edited_user, $userinfo);
	if ($edited_user) {
	  drupal_set_message(t('Your security question and/or answer has been successfully changed.'));
      $log_params = array('type' => 7, //successful account update
                          'data' => array('email' => $edited_user->mail,
                                          'name' => $edited_user->name),
                          'uid' => $edited_user->uid,
                          'ip_address' => ip_address(),
                          'created' => REQUEST_TIME,
                          );
      $user = $edited_user;
    } else {
      $_SESSION['messages']['error'][] = t('Error: Your security question and/or answer have not been updated.');
      $log_params = array('type' => 8, //failed account update
                        'data' => array('email' => $user->mail,
                                        'name' => $user->name),
                        'uid' => $user->uid,
                        'ip_address' => ip_address(),
                        'created' => REQUEST_TIME,
                        );
    }
    cls_mcl_create_audit_log($log_params);
    drupal_save_session($old_state);
  }else {
  	$_SESSION['messages']['error'][] = t('Error: Required values were missing in the submitted form.');
  	$log_params = array('type' => 8, //failed account update
                        'data' => array('email' => $user->mail,
                                        'name' => $user->name),
                        'uid' => $user->uid,
                        'ip_address' => ip_address(),
                        'created' => REQUEST_TIME,
                        );
    cls_mcl_create_audit_log($log_params);
  }
}

/**
* Displays My Columbia Law security question update form.
*
* @return $html - string containing security question update layout
*/
function cls_mcl_display_security_question_update($instance_id) {
  global $user;

  $js_settings = array();
  $js_settings['instance_id'] = $instance_id;
  $js_settings['action'] = 'edit_security_question';
  $js_settings['uid'] = $user->uid;
  drupal_add_js(array('cls_mcl_account' => $js_settings), 'setting');
  drupal_add_library('system', 'effects');
  drupal_add_js('misc/chosen/chosen.jquery.min.js', array('every_page' => FALSE));
  drupal_add_js(drupal_get_path('module', 'cls_mcl') . '/js/validation.js', array('every_page' => FALSE));
  drupal_add_js(drupal_get_path('module', 'cls_mcl') . '/js/account.js', array('every_page' => FALSE));

  if(cls_mcl_display_password_change_access()){
    return theme('security_question_update', array(
        'title' => "My Columbia Law",
        'instance_id' => $instance_id,
        'form' => drupal_get_form('cls_mcl_security_question_update', $instance_id)
    ));
  }
}

/**
* Displays My Columbia Law security question update success message.
*
* @return $html - string containing security question update success message layout
*/
function cls_mcl_display_account_update_screen($instance = 1) {
  return theme('account_update_success', array('title' => "My Columbia Law"));
}
