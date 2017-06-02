<?php

// @TODO All of the AJAX functions need to return the proper application/json
//   content header--please implement by returning drupal_json_output()
//   You will then be able to remove the exit() calls. FYI: In the future,
//   if you do need to exit, please use drupal_exit() to do it safely.
//   (The standard PHP exit function is untestable and does not conform
//   to Drupal coding standards).

/**
* Implementation of hook_fapi_validation_rules
*/
function cls_mcl_fapi_validation_rules() {
  return array(
    'lsac' => array(
      'callback' => 'cls_mcl_validation_rule_lsac',
      'error_msg' => 'Invalid value for %field. It must begin with an "L" followed by 8 digits.'
    ),
    'city' => array(
      'callback' => 'cls_mcl_validation_rule_city',
      'error_msg' => 'Invalid value for %field.'
    ),
    'security_answer' => array(
      'callback' => 'cls_mcl_validation_rule_security_answer',
      'error_msg' => 'Invalid value for %field.'
    ),
    'date' => array(
      'callback' => 'cls_mcl_validation_rule_date',
      'error_msg' => 'Invalid value for %field.'
    ),
  );
}

//////////////////////////////////////////////
// Validations for Status Checker
//////////////////////////////////////////////

function cls_mcl_validate_name($value, $instance_id){
  if(trim($value) == ''){
    return array('result' => FALSE, 'error' => ' is required.');
  }else if ($instance_id === 'my_columbia_law' && !cls_mcl_validation_rule_alpha_dash($value)){
    return array('result' => FALSE, 'error' => ' can only contain letters, dashes and spaces.');
  }else if ($instance_id === 'my_columbia_llm' && !cls_mcl_validation_rule_alpha_dash_unicode($value)){
    return array('result' => FALSE, 'error' => ' can only contain letters, dashes and spaces.');
  }
  return array('result' => TRUE, 'error' => '');
}

function cls_mcl_validate_birth_date($value){
  if(trim($value) == ''){
    return array('result' => FALSE, 'error' => ' is required.');
  }else if (!cls_mcl_validation_rule_date($value)){
    return array('result' => FALSE, 'error' => ' has invalid format.');
  }else {
  	$date_arr = explode("-", $value);
  	if(is_array($date_arr) && !empty($date_arr) && isset($date_arr[2])){
  	  if (intval(date("Y")) - intval($date_arr[2]) < 13){
  	    return array('result' => FALSE, 'error' => ' must be at least 13 years ago.');
  	  }else if (intval($date_arr[2]) < 1900){
  	    return array('result' => FALSE, 'error' => ' must be later than the year 1900.');
  	  }
  	}
  }
  return array('result' => TRUE, 'error' => '');
}

function cls_mcl_validate_lsac($value){
  if(trim($value) == ''){
    return array('result' => FALSE, 'error' => ' is required.');
  }else if (!cls_mcl_validation_rule_lsac($value)){
    return array('result' => FALSE, 'error' => ' has invalid format.');
  }
  return array('result' => TRUE, 'error' => '');
}

//////////////////////////////////////////////
// Validations for New Accounts
//////////////////////////////////////////////

function cls_mcl_validate_name_non_required($value, $instance_id){
  if((strlen(trim($value)) > 0) && (strlen(trim($value)) < 2)){
    return array('result' => FALSE, 'error' => ' must contain at least two characters.');
  }else if ($instance_id === 'my_columbia_law' && !cls_mcl_validation_rule_alpha_dash($value)){
    return array('result' => FALSE, 'error' => ' can only contain letters, dashes and spaces.');
  }else if ($instance_id === 'my_columbia_llm' && !cls_mcl_validation_rule_alpha_dash_unicode($value)){
    return array('result' => FALSE, 'error' => ' can only contain letters, dashes and spaces.');
  }
  return array('result' => TRUE, 'error' => '');
}

function cls_mcl_validate_name_no_minimum($value, $instance_id){
  if ($instance_id === 'my_columbia_law' && !cls_mcl_validation_rule_alpha_dash($value)){
    return array('result' => FALSE, 'error' => ' can only contain letters, dashes and spaces.');
  }
  else if ($instance_id === 'my_columbia_llm' && !cls_mcl_validation_rule_alpha_dash_unicode($value)){
    return array('result' => FALSE, 'error' => ' can only contain letters, dashes and spaces.');
  }
  return array('result' => TRUE, 'error' => '');
}

function cls_mcl_validate_lsac_for_new_account($value){
  if (!cls_mcl_validation_rule_lsac($value)){
    return array('result' => FALSE, 'error' => ' has invalid format.');
  }else {
  	  $lsac_query = db_select('field_data_cls_mcl_lsac_account_number', 'lsac');
      $result = $lsac_query
            ->fields('lsac', array('cls_mcl_lsac_account_number_value'))
            ->condition('cls_mcl_lsac_account_number_value', $value)
            ->condition('entity_type', 'user')
            ->execute();
      if ($record = $result->fetchAssoc()) {
          if($record['cls_mcl_lsac_account_number_value']){
              return array('result' => FALSE, 'error' => ' already exists.');
          }
      }
  }
  return array('result' => TRUE, 'error' => '');
}

function cls_mcl_validate_email($value){
  if(trim($value) == ''){
    return array('result' => FALSE, 'error' => ' is required.');
  }else if (!cls_mcl_validation_rule_email(trim($value))){
    return array('result' => FALSE, 'error' => ' has invalid format.');
  }else {
    if ($check_user = user_load_by_name(trim($value))){
      return array('result' => FALSE, 'error' => ' already exists.');
    }
  }
  return array('result' => TRUE, 'error' => '');
}

function cls_mcl_validate_email_existence($value, $instance_id){
  global $user;
  if(trim($value) == ''){
    return array('result' => FALSE, 'error' => ' is required.', 'user' => NULL);
  }else if (!cls_mcl_validation_rule_email(trim($value))){
    return array('result' => FALSE, 'error' => ' is invalid.', 'user' => NULL);
  }else {
    if ($check_user = user_load_by_name(trim($value))){
      $form_state['uid'] = $check_user->uid;
      $form_state['user_type'] = 'drupal_user';
      return array('result' => TRUE, 'error' => '', 'user' => $check_user);
    }
    else {
      $remote_user_query = db_select('cls_mcl_remote_users', 'cmru');
      $result = $remote_user_query
        ->fields('cmru', array('remote_user_id', 'login', 'password', 'first_name', 'last_name', 'middle_name', 'security_question', 'security_answer', 'gender', 'birth_date', 'study_begin_year', 'lsac_account_number', 'interest_id', 'ssn', 'street_1', 'street_2', 'city', 'state_code', 'country_code', 'zip_code'))
        ->condition('login', $value)
        ->execute();
      if ($record = $result->fetchAssoc()) {
        //Create new Drupal user
        $original_user = $user;
        $old_state = drupal_save_session();
        drupal_save_session(FALSE);
        //Become the admin
        $user = user_load(1);
        $userinfo = array(
          'name' => $record['login'],
          'pass' => user_password(),
          'mail' => $record['login'],
          'signature_format' => 'filtered_html',
          'init' => $record['login'],
          'status' => 1,
        );
        $site_instance = cls_get_site_instance($instance_id);
  	    $admitted_site_instance_id = $instance_id == "my_columbia_llm" ? "gls" : "jd";
  	    $admitted_site_instance = cls_admissions_admitted_get_site_instance($admitted_site_instance_id);
        $role_prospective = $admitted_site_instance['role_prospective'];
        $role_deposited = $admitted_site_instance['role_deposited'];

        $userinfo['cls_mcl_remote_user_id']['und'][0]['value'] = $record['remote_user_id'];
        $userinfo['cls_user_first_name']['und'][0]['value'] = $record['first_name'];
        $userinfo['cls_user_middle_name']['und'][0]['value'] = $record['middle_name'];
        $userinfo['cls_user_last_name']['und'][0]['value'] = $record['last_name'];
        $userinfo['cls_mcl_birth_date']['und'][0]['value'] = $record['birth_date'];
        $userinfo['cls_mcl_security_question']['und'][0]['value'] = $record['security_question'];
        $userinfo['cls_mcl_security_answer']['und'][0]['value'] = $record['security_answer'];
        $userinfo['cls_mcl_study_begin_year']['und'][0]['value'] = $record['study_begin_year'];
        $userinfo['cls_mcl_lsac_account_number']['und'][0]['value'] = $record['lsac_account_number'];
        $userinfo['cls_mcl_street_1']['und'][0]['value'] = $record['street_1'];
        $userinfo['cls_mcl_street_2']['und'][0]['value'] = $record['street_2'];
        $userinfo['cls_mcl_city']['und'][0]['value'] = $record['city'];
        $userinfo['cls_mcl_state_code']['und'][0]['value'] = $record['state_code'];
        $userinfo['cls_mcl_country_code']['und'][0]['value'] = $record['country_code'];
        $userinfo['cls_mcl_zip_code']['und'][0]['value'] = $record['zip_code'];

        $remote_user_school_query = db_select('cls_mcl_remote_user_school', 'cmrus');
        $result = $remote_user_school_query
          ->fields('cmrus', array('remote_user_id', 'school_id', 'type', 'user_specified', 'degree', 'grad_date', 'major', 'minor', 'second_major'))
          ->condition('remote_user_id', $record['remote_user_id'])
          ->execute();
        if ($school_record = $result->fetchAssoc()) {
          if($school_record['type'] == 'U'){
            if(isset($school_record['user_specified']) && !is_null($school_record['user_specified'])){
              $userinfo['cls_mcl_undergrad_inst_other']['und'][0]['value'] = $school_record['user_specified'];
              $userinfo['cls_mcl_undergrad_institution']['und'][0]['value'] = $school_record['school_id'];
            }else{
              $userinfo['cls_mcl_undergrad_institution']['und'][0]['value'] = $school_record['school_id'];
            }
            $userinfo['cls_mcl_undergrad_grad_year']['und'][0]['value'] = $school_record['grad_name'];
          }else if($school_record['type'] == 'G') {
            if(isset($school_record['user_specified']) && !is_null($school_record['user_specified'])){
              $userinfo['cls_mcl_grad_inst_other']['und'][0]['value'] = $school_record['user_specified'];
              $userinfo['cls_mcl_grad_institution']['und'][0]['value'] = $school_record['school_id'];
            }else{
              $userinfo['cls_mcl_grad_institution']['und'][0]['value'] = $school_record['school_id'];
            }
            $userinfo['cls_mcl_grad_graduation_year']['und'][0]['value'] = $school_record['grad_name'];
          }
        }

        $loaded_user = user_load_by_name($record['login']);
        if ($loaded_user){
          drupal_save_session($old_state);
          $form_state['uid'] = $loaded_user->uid;
          $form_state['user_type'] = 'drupal_user';
          return array('result' => TRUE, 'error' => '', 'user' => $loaded_user);
        }else{
          // This needs to happen in Step 2
          $new_user = user_save('', $userinfo);
          db_update('users')
            ->fields(array('pass' => $record['password']))
            ->condition('uid', $new_user->uid)
            ->execute();
          if ($new_user && cls_aces2_applicant_load_by_program_email_status(1, $record['login'], "Deposit")) {
            cls_common_user_add_role_by_name($role_deposited, $new_user->uid);
          }
          else if ($new_user) {
          	cls_common_user_add_role_by_name($role_prospective, $new_user->uid);
          }
          $user = drupal_anonymous_user();
          drupal_save_session($old_state);
          $form_state['uid'] = $new_user->uid;
          $form_state['user_type'] = 'remote_user';
          return array('result' => TRUE, 'error' => '', 'user' => $new_user);
        }
      }
      return array('result' => FALSE, 'error' => ' does not exist.');
    }
  }
}

function cls_mcl_validate_security_question($value, $instance_id){
  if(trim($value) == ''){
    return array('result' => FALSE, 'error' => ' is required.');
  }else if(is_numeric($value)){
    $security_question_options = cls_mcl_get_security_question_options($instance_id);
    $value = isset($security_question_options[$value]) ? $security_question_options[$value] : "";
  }
  if (!cls_mcl_validation_rule_security_question($value)){
    return array('result' => FALSE, 'error' => ' has invalid format.');
  }
  return array('result' => TRUE, 'error' => '');
}

function cls_mcl_validate_security_answer($value){
  if(trim($value) == ''){
    return array('result' => FALSE, 'error' => ' is required.');
  }else if (!cls_mcl_validation_rule_security_answer($value)){
    return array('result' => FALSE, 'error' => ' has invalid format.');
  }
  return array('result' => TRUE, 'error' => '');
}

function cls_mcl_validate_security_answer_correctness($value, $uid){
  if(trim($value) == ''){
    return array('result' => FALSE, 'error' => ' is required.');
  }else if (!cls_mcl_validation_rule_security_answer($value)){
    return array('result' => FALSE, 'error' => ' is invalid.');
  }else{
    $edited_user = user_load($uid);
    if($edited_user && isset($edited_user->cls_mcl_security_answer['und'][0]['value']) && cls_mcl_check_password(trim(strtolower($value)), $edited_user->cls_mcl_security_answer['und'][0]['value'])){
      return array('result' => TRUE, 'error' => '');
    }
    return array('result' => FALSE, 'error' => ' does not match our records.');
  }

}

function cls_mcl_validate_zip_code($value){
  if(trim($value) == ''){
    return array('result' => FALSE, 'error' => ' is required if country is USA.');
  }if (!cls_mcl_validation_rule_zip_code($value)){
    return array('result' => FALSE, 'error' => ' has invalid format.');
  }
  return array('result' => TRUE, 'error' => '');
}

//////////////////////////////////////////////
// Validations for updated accounts
//////////////////////////////////////////////

function cls_mcl_validate_lsac_for_updated_account($value, $uid){
  if (!cls_mcl_validation_rule_lsac($value)){
    return array('result' => FALSE, 'error' => ' has invalid format.');
  }
  else {
    $lsac_query = db_select('field_data_cls_mcl_lsac_account_number', 'lsac');
    $result = $lsac_query
                ->fields('lsac', array('cls_mcl_lsac_account_number_value', 'entity_id'))
                ->condition('cls_mcl_lsac_account_number_value', $value)
                ->condition('entity_type', 'user')
                ->execute();
    if ($record = $result->fetchAssoc()) {
        if($record['cls_mcl_lsac_account_number_value'] && $record['entity_id'] != $uid){
        	// This LSAC account number does not belong to current user
            return array('result' => FALSE, 'error' => ' belongs to another user.');
        }
    }
  }
  return array('result' => TRUE, 'error' => '');
}

function cls_mcl_validate_security_answer_non_required($value){
  if (!cls_mcl_validation_rule_security_answer($value)){
    return array('result' => FALSE, 'error' => ' has invalid format.');
  }
  return array('result' => TRUE, 'error' => '');
}

//////////////////////////////////////////////
// Common validations
//////////////////////////////////////////////

function cls_mcl_validation_rule_alpha_dash($value) {
  if (preg_match('/[^A-Za-z\'\-\.\-\s]/', $value)) {
    return FALSE;
  }
  else {
    return TRUE;
  }
}

function cls_mcl_validation_rule_alpha_dash_unicode($value) {
  if (preg_match('/[^\p{L}\'\-\.\-\s]/u', $value)) {
    return FALSE;
  }
  else {
    return TRUE;
  }
}

function cls_mcl_validation_rule_alpha_numeric($value) {
  if (preg_match('/^([A-Z|a-z|0-9|\-|\.|\'|\s]{1,})?$/', $value)) {
    return TRUE;
  }
  else {
    return FALSE;
  }
}

function cls_mcl_validation_rule_lsac($value) {
  if (preg_match('/^([L]{1}[0-9]{8})?$/', $value)) {
    return TRUE;
  }
  else {
    return FALSE;
  }
}

function cls_mcl_validation_rule_date($value) {
  if (preg_match('/^[0-1]?[0-9]{1}[\-]{1}[0-3]?[0-9]{1}[\-]{1}[1-2]{1}[0-9]{3}$/', $value)) {
    return TRUE;
  }
  else {
    return FALSE;
  }
}

function cls_mcl_validation_rule_email($value){
  if (preg_match('/^[A-Z|a-z|0-9|\-|\_|\.]{1,}[@]{1}[A-Z|a-z|0-9|\-|\_|\.]{1,}[\.][A-Z|a-z]{2,4}$/', $value)) {
    return TRUE;
  }
  else {
    return FALSE;
  }
}

function cls_mcl_validation_rule_security_question($value) {
  $value = trim($value);
  if (preg_match('/^[A-Z|a-z]{3,}([A-Z|a-z|0-9|\-|\_|\.|\,|\:|\;|\'|\"|\/|\!|\?|\@|\#|\$|\%|\(|\)||\=|\+|\s]{1,})?$/', $value)) {
    return TRUE;
  }
  return FALSE;
}

function cls_mcl_validation_rule_security_answer($value) {
  $value = trim($value);
  if ($value == "Your Answer") {
    return FALSE;
  }
  else if (preg_match('/^([A-Z|a-z]{2,}([A-Z|a-z|0-9|\-|\_|\.|\,|\:|\;|\'|\"|\/|\!|\?|\@|\#|\$|\%|\(|\)||\=|\+|\s]{1,})?)?$/', $value)) {
    return TRUE;
  }
  return FALSE;
}

function cls_mcl_validation_rule_zip_code($value) {
  if (preg_match('/^[0-9]{5}$/', $value)) {
    return TRUE;
  }
  else {
    return FALSE;
  }
}

function cls_mcl_validation_rule_city($value) {
  if (preg_match('/^[A-Z|a-z|\-|\.|\s]{2,}$/', $value)) {
    return TRUE;
  }
  else {
    return FALSE;
  }
}

function cls_mcl_validate_equality($value1, $value2){
  if(trim($value1) != trim($value2)){
    return array('result' => FALSE, 'error' => ' do not match.');
  }
  return array('result' => TRUE, 'error' => '');
}

//////////////////////////////////////////////
// AJAX Validation functions.
//////////////////////////////////////////////

/**
 * Validates date in $_POST['birth_date'] variable.
 * Used with AJAX.
 */
function cls_mcl_validate_birth_date_ajax() {
  $params = $_POST;
  if (isset($params['birth_date'])) {
  	$validation_data = cls_mcl_validate_birth_date($params['birth_date']);
  	echo json_encode($validation_data);
  	exit();
  }
  echo json_encode(array('result' => false, 'error' => ' Wrong parameters passed to birth date validation function.'));
  exit();
}

/**
 * Validates LSAC account number in $_POST['lsac'] variable.
 * Used with AJAX.
 */
function cls_mcl_validate_lsac_account_number_ajax() {
  $params = $_POST;
  if (isset($params['lsac'])) {
  	$validation_data = cls_mcl_validate_lsac($params['lsac']);
  	echo json_encode($validation_data);
  	exit();
  }
  echo json_encode(array('result' => false, 'error' => ' Wrong parameters passed to LSAC validation function.'));
  exit();
}

/**
 * Validates LSAC account number in $_POST['lsac'] variable for new accounts.
 * Allows LSAC number to be empty.
 * Used with AJAX.
 */
function cls_mcl_validate_lsac_account_number_for_new_account_ajax() {
  $params = $_POST;
  if (isset($params['lsac'])) {
  	$validation_data = cls_mcl_validate_lsac_for_new_account($params['lsac']);
  	echo json_encode($validation_data);
  	exit();
  }
  echo json_encode(array('result' => false, 'error' => ' Wrong parameters passed to LSAC validation function.'));
  exit();
}

/**
 * Validates LSAC account number in $_POST['lsac'] variable for updated accounts.
 * Allows LSAC number to be empty or to exist.
 * Used with AJAX.
 */
function cls_mcl_validate_lsac_account_number_for_updated_account_ajax() {
  $params = $_POST;
  if (isset($params['lsac']) && isset($params['uid'])) {
  	$validation_data = cls_mcl_validate_lsac_for_updated_account($params['lsac'], $params['uid']);
  	echo json_encode($validation_data);
  	exit();
  }
  echo json_encode(array('result' => false, 'error' => ' Wrong parameters passed to LSAC validation function.'));
  exit();
}

/**
 * Validates name in $_POST['name'] variable.
 * Used with AJAX.
 */
function cls_mcl_validate_name_ajax() {
  $params = $_POST;
  if (isset($params['name'])) {
  	$validation_data = cls_mcl_validate_name($params['name']);
  	echo json_encode($validation_data);
  	exit();
  }
  echo json_encode(array('result' => false, 'error' => ' Wrong parameters passed to name validation function.'));
  exit();
}

/**
 * Validates non-required name in $_POST['name'] variable.
 * Used with AJAX.
 */
function cls_mcl_validate_name_non_required_ajax() {
  $params = $_POST;
  if (isset($params['name'])) {
  	$validation_data = cls_mcl_validate_name_non_required($params['name']);
  	echo json_encode($validation_data);
  	exit();
  }
  echo json_encode(array('result' => false, 'error' => ' Wrong parameters passed to name validation function.'));
  exit();
}

/**
 * Validates email in $_POST['email'] variable.
 * Used with AJAX.
 */
function cls_mcl_validate_email_ajax() {
  $params = $_POST;
  if (isset($params['email'])) {
  	$validation_data = cls_mcl_validate_email($params['email']);
  	echo json_encode($validation_data);
  	exit();
  }
  echo json_encode(array('result' => false, 'error' => ' Wrong parameters passed to email validation function.'));
  exit();
}

/**
 * Validates security answer in $_POST['security_answer'] variable.
 * Used with AJAX.
 */
function cls_mcl_validate_security_answer_ajax() {
  $params = $_POST;
  if (isset($params['security_answer'])) {
  	$validation_data = cls_mcl_validate_security_answer($params['security_answer']);
  	echo json_encode($validation_data);
  	exit();
  }
  echo json_encode(array('result' => false, 'error' => ' Wrong parameters passed to security answer validation function.'));
  exit();
}

/**
 * Validates security answer in $_POST['security_answer'] variable.
 * Allows security answer to be empty.
 * Used with AJAX.
 */
function cls_mcl_validate_security_answer_non_required_ajax() {
  $params = $_POST;
  if (isset($params['security_answer'])) {
  	$validation_data = cls_mcl_validate_security_answer_non_required($params['security_answer']);
  	echo json_encode($validation_data);
  	exit();
  }
  echo json_encode(array('result' => false, 'error' => ' Wrong parameters passed to security answer validation function.'));
  exit();
}

/**
 * Validates zip code in $_POST['zip_code'] variable.
 * Used with AJAX.
 */
function cls_mcl_validate_zip_code_ajax() {
  $params = $_POST;
  if (isset($params['zip_code'])) {
  	$validation_data = cls_mcl_validate_zip_code($params['zip_code']);
  	echo json_encode($validation_data);
  	exit();
  }
  echo json_encode(array('result' => false, 'error' => ' Wrong parameters passed to zip code validation function.'));
  exit();
}

/**
 * Validates the equality of values in $_POST['value1'] and $_POST['value2'] variables.
 * Used with AJAX.
 */
function cls_mcl_validate_equality_ajax() {
  $params = $_POST;
  if (isset($params['value1']) && isset($params['value2'])) {
  	$validation_data = cls_mcl_validate_equality($params['value1'], $params['value2']);
  	echo json_encode($validation_data);
  	exit();
  }
  echo json_encode(array('result' => false, 'error' => ' Wrong parameters passed to equality validation function.'));
  exit();
}
