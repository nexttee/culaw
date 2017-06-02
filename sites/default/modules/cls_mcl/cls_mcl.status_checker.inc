<?php

/**
 * @file
 * Functions related to My Columbia Law status checker.
 */

/**
* Displays My Columbia Law Status Checker form for users withour accounts.
*
* @return $html - string containing the form output.
*/
function cls_mcl_display_status_checker_form() {
  drupal_add_css(drupal_get_path('module', 'cls_mcl') . '/css/check_status.css', array('every_page' => FALSE));
  return theme('status_checker_form', array('form' => drupal_get_form('cls_mcl_check_status_form')));
}

/**
* Displays My Columbia Law Status Checker results.
*
* @return $html - string containing the resulting HTML output.
*/
function cls_mcl_display_applicant_status_data(){
  drupal_add_css(drupal_get_path('module', 'cls_mcl') . '/css/check_status.css', array('every_page' => FALSE));
  return theme('status_checker_result', array('html' => cls_mcl_get_applicant_data()));
}

/**
 * Checks the status of My Columbia Law application.
 */
function cls_mcl_check_application_status() {
  global $user;
  
  unset($_SESSION['Applicant']);
  
  if ($user->uid) {
    //Get LSAC for current user account
    //Get Applicant from aces2_record based on LSAC number, first and last name and DOB from current account
    //Display Applicant's status data

    if($loaded_user = user_load($user->uid)){
        $lsac = isset($loaded_user->cls_mcl_lsac_account_number['und'][0]['value']) ? $loaded_user->cls_mcl_lsac_account_number['und'][0]['value'] : "";
        $first_name = isset($loaded_user->cls_user_first_name['und'][0]['value']) ? $loaded_user->cls_user_first_name['und'][0]['value'] : "";
        $last_name = isset($loaded_user->cls_user_last_name['und'][0]['value']) ? $loaded_user->cls_user_last_name['und'][0]['value'] : "";
        $birth_date = isset($loaded_user->cls_mcl_birth_date['und'][0]['value']) ? $loaded_user->cls_mcl_birth_date['und'][0]['value'] : "";
        if($birth_date){
          $birth_date_arr = explode('-', $birth_date);
      	  if(!empty($birth_date_arr) && isset($birth_date_arr[0]) && isset($birth_date_arr[1]) && isset($birth_date_arr[2])){
      	   $birth_date = $birth_date_arr[1] . "-" . $birth_date_arr[0] . "-" . $birth_date_arr[2];
      	  }
      	  $birth_date = date('Y-m-d', strtotime($birth_date));
        }
        
    
        $current_year = variable_get('cls_mcl.config.current_application_year', date("Y"));

        if(!empty($birth_date) && !empty($lsac) 
            && !empty($first_name) && !empty($last_name) 
            && !empty($current_year)) {
            //$cls_aces2_applicant = cls_aces2_applicant_load_by_status_checker_criteria('1', $current_year, $lsac, $first_name, $last_name, $birth_date);
            $cls_aces2_applicant = cls_aces2_api_jd_applicant_load_by_status_checker_criteria(
              $current_year, $lsac, $first_name, $last_name, $birth_date);
            
            if ($cls_aces2_applicant) {
               //Applicant has been found. Set Applicant data to session
               $_SESSION['Applicant'] = $cls_aces2_applicant;
            }
        }
        if (!isset($_SESSION['Applicant'])) {
          $log_params = array('type' => 12, //failed status check: applicant does not exist
                              'data' => array('email' => isset($user->mail) ? $user->mail : '',
                                              'name' => isset($user->name) ? $user->name : '',
                                              'lsac' => $lsac,
                                              'first_name' => $first_name,
                                              'last_name' => $last_name,
                                              'dob' => $birth_date,
                                              ),
                              'uid' => $user->uid,
                              'ip_address' => ip_address(),
                              'created' => REQUEST_TIME,
                              );
          cls_mcl_create_audit_log($log_params);
        }
        
                
        return cls_mcl_display_applicant_status_data();
    }


  }

  else {
    //Display form containing the search criteria
    //Upon form submission, display status data
    //for Applicant that matches the search criteria
    return cls_mcl_display_status_checker_form();
  }

}

function cls_mcl_check_status_form($form, &$form_state) {
  global $base_url;
  
  unset($_SESSION['Applicant']);
  
  $head_js = array(
    '#type' => 'markup',
    '#markup' => '<script language="javascript" type="text/javascript">var base_url = "' . $base_url . '";</script>',
  );
  drupal_add_html_head($head_js, 'cls_mcl');
  drupal_add_library('system', 'ui.datepicker');
  drupal_add_css(drupal_get_path('module', 'jquery_ui') . "/jquery.ui/themes/base/jquery-ui.css");
  drupal_add_js(drupal_get_path('module', 'cls_mcl') . '/js/status_checker.js');

  $form['title'] = array('#markup' => "Check Application Status",
                         '#prefix' => "<h2>",
                         '#suffix' => "</h2>");
  $form['instructions'] = array('#markup' => 'To simplify the process of checking the status of your application, <a href="' . base_path() . 'admissions/jd/my-columbia-law/get-started">create a personalized &ldquo;My Columbia Law&rdquo; account</a> or <a href="' . base_path() . 'admissions/jd/my-columbia-law">log in to your existing account</a>.',
                         '#prefix' => "<p id='mcl-status-checker-form-instructions'>",
                         '#suffix' => "</p>");
  $form['instructions_two'] = array('#markup' => "To check your application status without creating a &ldquo;My Columbia Law&rdquo; account, please provide the following information*:",
                         '#prefix' => "<p id='mcl-status-checker-form-instructions'>",
                         '#suffix' => "</p>");
  $form['first_name'] = array('#type' => 'textfield',
    '#title' => t('First Name'),
    '#description' => t(''),
    //'#rules' => array(array('rule' => 'alpha_dash', 'error' => 'Please, use only letters and dashes in %field.')),
    '#required' => TRUE,
  );
  $form['last_name'] = array('#type' => 'textfield',
    '#title' => t('Last Name'),
    '#description' => t(''),
    //'#rules' => array(array('rule' => 'alpha_dash', 'error' => 'Please, use only letters and dashes in %field.')),
    '#required' => TRUE,
  );
  $form['birth_date'] = array('#type' => 'textfield',
    '#title' => t('Date of Birth'),
    '#description' => t('(MM-DD-YYYY)'),
    //'#rules' => array(array('rule' => 'date', 'error' => 'Invalid value for %field. Please provide a date in "mm-dd-yyyy" format.')),
    '#size' => 10,
    '#maxlength' => 10,
    '#required' => TRUE,
    //'#widget' => array('type' =>'date_select'),
  );
  $form['lsac_account_number'] = array('#type' => 'textfield',
    '#title' => t('LSAC Account Number'),
    '#description' => t('e.g., L48061473'),
    //'#rules' => array(array('rule' => 'lsac', 'error' => 'Invalid value for %field. It must begin with an "L" followed by 8 digits.')),
    '#required' => TRUE,
    '#default_value' => 'L',
  );
  $form['footnote'] = array('#markup' => "*All responses must exactly match the information you previously provided on your application for admission.",
                         '#prefix' => "<hr class='dashed' /><p id='mcl-status-checker-form-footnote'>",
                         '#suffix' => "</p>");
  $form['original_url'] = array(
    '#type' => 'value',
    '#value' => request_uri(),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#button_type' => 'mcl-submit-button',
    '#value' => t('Submit'),
    '#submit' => array('cls_mcl_check_status_form_submit'),
  );
  $form['reset'] = array('#markup' => "<input id='edit-reset' onclick='clearAll();' class='form-mcl-reset-button' type='button' value='Reset' name='reset' />",
                         '#prefix' => "<div>",
                         '#suffix' => "</div>");

  return $form;
}

/**
 * Validates data from Status Check form.
 * Displays error message if validation fails.
 */
function cls_mcl_check_status_form_validate($form, &$form_state) {
  $first_name_validation_data = cls_mcl_validate_name(trim($form_state['values']['first_name']));
  $last_name_validation_data = cls_mcl_validate_name(trim($form_state['values']['last_name']));
  $birth_date_validation_data = cls_mcl_validate_birth_date(trim($form_state['values']['birth_date']));
  $lsac_validation_data = cls_mcl_validate_lsac(trim($form_state['values']['lsac_account_number']));
  $return_flag = true;
  if (!$first_name_validation_data['result']){
    form_set_error('first_name', t('First name' . $first_name_validation_data['error']));
    $return_flag = false;
  }else if(!$last_name_validation_data['result']){
  	form_set_error('last_name', t('Last name' . $last_name_validation_data['error']));
  	$return_flag = false;
  }else if(!$birth_date_validation_data['result']){
  	form_set_error('birth_date', t('Birth date' . $birth_date_validation_data['error']));
    $return_flag = false;
  }else if(!$lsac_validation_data['result']){
  	form_set_error('lsac', t('LSAC account number' . $lsac_validation_data['error']));
    $return_flag = false;
  }
  return $return_flag;
}

function cls_mcl_check_status_form_submit($form, &$form_state) {
  global $user;
  $clicked = $form_state['clicked_button']['#value'];

  switch ($clicked) {
    case 'Submit':
    default:
      if(isset($form_state['values']['birth_date'])){
        $birth_date_arr = explode('-', $form_state['values']['birth_date']);
      	 if(!empty($birth_date_arr) && isset($birth_date_arr[0]) && isset($birth_date_arr[1]) && isset($birth_date_arr[2])){
      	   $form_state['values']['birth_date'] = $birth_date_arr[1] . "-" . $birth_date_arr[0] . "-" . $birth_date_arr[2];
      	 }
      	 $form_state['values']['birth_date'] = date('Y-m-d', strtotime($form_state['values']['birth_date']));
      }
      $current_year = variable_get('cls_mcl.config.current_application_year', date("Y"));
      

      if(isset($form_state['values']['lsac_account_number']) && !empty($form_state['values']['lsac_account_number'])
          && isset($form_state['values']['birth_date']) && !empty($form_state['values']['birth_date'])
          && isset($form_state['values']['first_name']) && !empty($form_state['values']['first_name'])
          && isset($form_state['values']['last_name']) && !empty($form_state['values']['last_name'])        
          && !empty($current_year)) {

            //$cls_aces2_applicant = cls_aces2_applicant_load_by_status_checker_criteria('1', $current_year, $form_state['values']['lsac_account_number'], $form_state['values']['first_name'], $form_state['values']['last_name'], $form_state['values']['birth_date']);
            $cls_aces2_applicant = cls_aces2_api_jd_applicant_load_by_status_checker_criteria(
              $current_year, 
              $form_state['values']['lsac_account_number'], 
              $form_state['values']['first_name'], 
              $form_state['values']['last_name'], 
              $form_state['values']['birth_date']);
      }
      if (isset($cls_aces2_applicant) && cls_aces2_applicant) {
      	 //Applicant has been found. Set Applicant data to session and go to display URL
        $_SESSION['Applicant'] = $cls_aces2_applicant;
      }else{
      	$log_params = array('type' => 11, //failed status check: applicant cannot be found
                            'data' => array('email' => isset($user->mail) ? $user->mail : '',
                                            'name' => isset($user->name) ? $user->name : '',
                                            'lsac' => $form_state['values']['lsac_account_number'],
                                            'first_name' => $form_state['values']['first_name'],
                                            'last_name' => $form_state['values']['last_name'],
                                            'dob' => $form_state['values']['birth_date']),
                            'uid' => $user->uid,
                            'ip_address' => ip_address(),
                            'created' => REQUEST_TIME,
                            );
        cls_mcl_create_audit_log($log_params);
        unset($_SESSION['Applicant']);
      }
      if($form_state['values']['original_url'] == '/admissions/jd/my-columbia-law/check-application-status') {
        drupal_goto('admissions/jd/my-columbia-law/display-application-status');
      }
      else {
        drupal_goto('admissions/jd/apply/display-application-status');
      }
  }
  return;
}

function cls_mcl_get_applicant_data(){
  global $user;
  global $base_url;
  $header = '<tr><td colspan=4><h2>Check Application Status</h2></td></tr>';
  $rows = "";
  if(isset($_SESSION['Applicant'])){
  	$Applicant = $_SESSION['Applicant'];
  	$all_components_received = true;

    //echo $Applicant->application_type;
    if(isset($Applicant->application_type) && in_array(trim(strtolower($Applicant->application_type)), array('transfer', 'visiting'))){
      // Transfer applicants
      $rows .= '<tr><td colspan=2>Application Form:</td>';
      if(isset($Applicant->application_signed) && trim($Applicant->application_signed) == 'Y'){
        $rows .= '<td colspan=2><img src="'.$base_url.'/sites/all/modules/custom/cls_mcl/images/received_checkbox.gif" width="15" align="absmiddle" style="float: left;">&nbsp;&nbsp;Received';
      }else{
      	$rows .= '<td colspan=2><img src="'.$base_url.'/sites/all/modules/custom/cls_mcl/images/empty_checkbox.gif" width="15" align="absmiddle" style="float: left;">';
        $all_components_received = false;
      }
      $rows .= '<tr><td colspan=2>Personal Statement/Essay:</td>';
      if(isset($Applicant->personal_statement_received) && trim($Applicant->personal_statement_received) == 'Y'){
        $rows .= '<td colspan=2><img src="'.$base_url.'/sites/all/modules/custom/cls_mcl/images/received_checkbox.gif" width="15" align="absmiddle" style="float: left;">&nbsp;&nbsp;Received';
      }else{
      	$rows .= '<td colspan=2><img src="'.$base_url.'/sites/all/modules/custom/cls_mcl/images/empty_checkbox.gif" width="15" align="absmiddle" style="float: left;">';
        $all_components_received = false;
      }
      $rows .= '<tr><td colspan=2>Résumé:</td>';
      if(isset($Applicant->resume_on_file) && trim($Applicant->resume_on_file) == 'Y'){
        $rows .= '<td colspan=2><img src="'.$base_url.'/sites/all/modules/custom/cls_mcl/images/received_checkbox.gif" width="15" align="absmiddle" style="float: left;">&nbsp;&nbsp;Received';
      }else{
      	$rows .= '<td colspan=2><img src="'.$base_url.'/sites/all/modules/custom/cls_mcl/images/empty_checkbox.gif" width="15" align="absmiddle" style="float: left;">';
        $all_components_received = false;
      }
      $rows .= '<tr><td colspan=2>CAS Report:</td>';
      if(isset($Applicant->lsdas_received_date) && !empty($Applicant->lsdas_received_date)){
        // 'Complete' or 'Complete and copy requested from LSAC'
        $rows .= '<td colspan=2><img src="'.$base_url.'/sites/all/modules/custom/cls_mcl/images/received_checkbox.gif" width="15" align="absmiddle" style="float: left;">&nbsp;&nbsp;' . (isset($Applicant->completed_date) && $Applicant->completed_date ? 'Received' : 'Complete and copy requested from CAS');
      }else{
      	$rows .= '<td colspan=2><img src="'.$base_url.'/sites/all/modules/custom/cls_mcl/images/empty_checkbox.gif" width="15" align="absmiddle" style="float: left;">';
        $all_components_received = false;
      }
      $rows .= '<tr><td colspan=2>Transcripts (including first-year law school grades):</td>';
      if(isset($Applicant->final_transcript) && trim($Applicant->final_transcript) == 'Y'){
        $rows .= '<td colspan=2><img src="'.$base_url.'/sites/all/modules/custom/cls_mcl/images/received_checkbox.gif" width="15" align="absmiddle" style="float: left;">&nbsp;&nbsp;Received';
      }else{
      	$rows .= '<td colspan=2><img src="'.$base_url.'/sites/all/modules/custom/cls_mcl/images/empty_checkbox.gif" width="15" align="absmiddle" style="float: left;">';
        $all_components_received = false;
      }
      $rows .= '<tr><td colspan=2>Application Fee:</td>';
      if(isset($Applicant->application_fee_received) && trim($Applicant->application_fee_received) == 'Y'){
        $rows .= '<td colspan=2><img src="'.$base_url.'/sites/all/modules/custom/cls_mcl/images/received_checkbox.gif" width="15" align="absmiddle" style="float: left;">&nbsp;&nbsp;Received';
      }else{
      	$rows .= '<td colspan=2><img src="'.$base_url.'/sites/all/modules/custom/cls_mcl/images/empty_checkbox.gif" width="15" align="absmiddle" style="float: left;">';
        $all_components_received = false;
      }
      $rows .= '<tr><td colspan=2>Dean\'s Appraisal/Certification:</td>';
      if(isset($Applicant->dean_certification) && trim($Applicant->dean_certification) == 'Yes'){
        $rows .= '<td colspan=2><img src="'.$base_url.'/sites/all/modules/custom/cls_mcl/images/received_checkbox.gif" width="15" align="absmiddle" style="float: left;">&nbsp;&nbsp;Received';
      }else{
      	$rows .= '<td colspan=2><img src="'.$base_url.'/sites/all/modules/custom/cls_mcl/images/empty_checkbox.gif" width="15" align="absmiddle" style="float: left;">';
        $all_components_received = false;
      }
      $rows .= '<tr><td colspan=2>Recommendation Letters:</td>';
      if(isset($Applicant->recommenders) && sizeof($Applicant->recommenders) >= 2){
        $rows .= '<td colspan=2><img src="'.$base_url.'/sites/all/modules/custom/cls_mcl/images/received_checkbox.gif" width="15" align="absmiddle" style="float: left;">&nbsp;&nbsp;Complete';
      }else{
      	$rows .= '<td colspan=2><img src="'.$base_url.'/sites/all/modules/custom/cls_mcl/images/empty_checkbox.gif" width="15" align="absmiddle" style="float: left;">';
        $all_components_received = false;
      }
      if(isset($Applicant->recommenders) && sizeof($Applicant->recommenders) > 0){
        foreach($Applicant->recommenders as $recommender){
          $rows .= '<tr><td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;'.$recommender.'</td><td><img src="'.$base_url.'/sites/all/modules/custom/cls_mcl/images/received_checkbox.gif" width="15" align="absmiddle" style="float: left;">&nbsp;&nbsp;Received<td colspan=2>';
        }
      }
      if(isset($Applicant->completed_date) && !empty($Applicant->completed_date)){
        $text = '<p><b>Application Status:  Complete</b><br/><br/>
Your application is now complete and has been forwarded to the Admissions
Committee for review. Applications are reviewed on a rolling basis, generally in the order in which they are completed.
<br>Please note that decisions will not be available online; rather, all applicants will receive their decision by mail or email.</br>
<br/><br/>
Thank you for your continued interest in Columbia Law School.';
        $log_params = array('type' => 9, //successful status check: application complete
                            'data' => array('email' => isset($user->mail) ? $user->mail : '',
                                            'name' => isset($user->name) ? $user->name : '',
                                            'lsac' => $Applicant->lsac_account_number,
                                            'first_name' => $Applicant->first_name,
                                            'last_name' => $Applicant->last_name,
                                            'dob' => $Applicant->birth_date),
                            'uid' => $user->uid,
                            'ip_address' => ip_address(),
                            'created' => REQUEST_TIME,
                            );
        cls_mcl_create_audit_log($log_params);
      }else{
      	if($all_components_received){
      	  $text = '<p><b>Application Status:  Completion Pending</b><br/><br/>
We have received all the above components of your application and are in the
process of compiling them for completion.
<p>We kindly ask that you allow at least two weeks from the date of your last submission for completion to
occur.  After your file is rendered &ldquo;Complete,&rdquo; you will receive notification of this update by email.
<br>However, if you have not yet submitted a Dean&rsquo;s Certification form or its equivalent from the law school
from which you are transferring, as well as any undergraduate, graduate, and professional institution(s) at
which you matriculated toward a degree, your file will remain pending completion until we receive those documents.
<br/><br/>
Thank you for your continued interest in Columbia Law School.';
      	}else{
      	  $text = '<b>Application Status:  Incomplete</b><br/><br/>
Kindly note that the application components listed and unchecked above have
not yet been received or processed by our Office.
<p>If, however, you have already submitted the above-listed unchecked documents,
we ask that you allow at least 2 weeks from the date of submission for our staff to process
the materials and update your status.
In addition, please be advised that all applicants must submit a Dean&rsquo;s Certification
form or its equivalent from the law school from which you are transferring, as well as
any undergraduate, graduate, and professional institution(s) at which you matriculated toward a degree.
<br/><br/>
If it has been more than 3 weeks since your last submission and you believe
that your application should now be &ldquo;Complete,&rdquo; you may contact the Office of
Admissions at <a href="mailto:admissions@law.columbia.edu">admissions@law.columbia.edu</a>
to request detailed information
about the status of materials received to date.  It typically takes our
staff 3-5 business days to respond to such requests.
<br/><br/>
Thank you for your continued interest in Columbia Law School.';
      	}
        $log_params = array('type' => 10, //successful status check: application incomplete
                            'data' => array('email' => isset($user->mail) ? $user->mail : '',
                                            'name' => isset($user->name) ? $user->name : '',
                                            'lsac' => $Applicant->lsac_account_number,
                                            'first_name' => $Applicant->first_name,
                                            'last_name' => $Applicant->last_name,
                                            'dob' => $Applicant->birth_date),
                            'uid' => $user->uid,
                            'ip_address' => ip_address(),
                            'created' => REQUEST_TIME,
                            );
        cls_mcl_create_audit_log($log_params);
      }
    }
    else {
      // All other applicants
      $rows .= '<tr><td colspan=2>Application Form:</td>';
      if(isset($Applicant->application_signed) && trim($Applicant->application_signed) == 'Y'){
        $rows .= '<td colspan=2><img src="'.$base_url.'/sites/all/modules/custom/cls_mcl/images/received_checkbox.gif" width="15" align="absmiddle" style="float: left;">&nbsp;&nbsp;Received';
      }else{
      	$rows .= '<td colspan=2><img src="'.$base_url.'/sites/all/modules/custom/cls_mcl/images/empty_checkbox.gif" width="15" align="absmiddle" style="float: left;">';
        $all_components_received = false;
      }
      $rows .= '<tr><td colspan=2>Personal Statement/Essay:</td>';
      if(isset($Applicant->personal_statement_received) && trim($Applicant->personal_statement_received) == 'Y'){
        $rows .= '<td colspan=2><img src="'.$base_url.'/sites/all/modules/custom/cls_mcl/images/received_checkbox.gif" width="15" align="absmiddle" style="float: left;">&nbsp;&nbsp;Received';
      }else{
      	$rows .= '<td colspan=2><img src="'.$base_url.'/sites/all/modules/custom/cls_mcl/images/empty_checkbox.gif" width="15" align="absmiddle" style="float: left;">';
        $all_components_received = false;
      }
      $rows .= '<tr><td colspan=2>Résumé:</td>';
      if(isset($Applicant->resume_on_file) && trim($Applicant->resume_on_file) == 'Y'){
        $rows .= '<td colspan=2><img src="'.$base_url.'/sites/all/modules/custom/cls_mcl/images/received_checkbox.gif" width="15" align="absmiddle" style="float: left;">&nbsp;&nbsp;Received';
      }else{
      	$rows .= '<td colspan=2><img src="'.$base_url.'/sites/all/modules/custom/cls_mcl/images/empty_checkbox.gif" width="15" align="absmiddle" style="float: left;">';
        $all_components_received = false;
      }
      $rows .= '<tr><td colspan=2>CAS Report:</td>';
      if(isset($Applicant->lsdas_received_date) && !empty($Applicant->lsdas_received_date)){
        // 'Complete' or 'Complete and copy requested from LSAC'
        $rows .= '<td colspan=2><img src="'.$base_url.'/sites/all/modules/custom/cls_mcl/images/received_checkbox.gif" width="15" align="absmiddle" style="float: left;">&nbsp;&nbsp;' . (isset($Applicant->completed_date) && $Applicant->completed_date ? 'Received' : 'Complete and copy requested from CAS');
      }else{
      	$rows .= '<td colspan=2><img src="'.$base_url.'/sites/all/modules/custom/cls_mcl/images/empty_checkbox.gif" width="15" align="absmiddle" style="float: left;">';
        $all_components_received = false;
      }
      $rows .= '<tr><td colspan=2>Application Fee:</td>';
      if(isset($Applicant->application_fee_received) && trim($Applicant->application_fee_received) == 'Y'){
        $rows .= '<td colspan=2><img src="'.$base_url.'/sites/all/modules/custom/cls_mcl/images/received_checkbox.gif" width="15" align="absmiddle" style="float: left;">&nbsp;&nbsp;Received';
      }else{
      	$rows .= '<td colspan=2><img src="'.$base_url.'/sites/all/modules/custom/cls_mcl/images/empty_checkbox.gif" width="15" align="absmiddle" style="float: left;">';
        $all_components_received = false;
      }
      $rows .= '<tr><td colspan=2>Recommendation Letters:</td>';
      if(isset($Applicant->recommenders) && sizeof($Applicant->recommenders) >= 2){
        $rows .= '<td colspan=2><img src="'.$base_url.'/sites/all/modules/custom/cls_mcl/images/received_checkbox.gif" width="15" align="absmiddle" style="float: left;">&nbsp;&nbsp;Complete';
      }else{
      	$rows .= '<td colspan=2><img src="'.$base_url.'/sites/all/modules/custom/cls_mcl/images/empty_checkbox.gif" width="15" align="absmiddle" style="float: left;">';
        $all_components_received = false;
      }
      if(isset($Applicant->recommenders) && sizeof($Applicant->recommenders) > 0){
        foreach($Applicant->recommenders as $recommender){
          $rows .= '<tr><td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;'.$recommender.'</td><td><img src="'.$base_url.'/sites/all/modules/custom/cls_mcl/images/received_checkbox.gif" width="15" align="absmiddle" style="float: left;">&nbsp;&nbsp;Received<td colspan=2>';
        }
      }
      if(isset($Applicant->completed_date) && !empty($Applicant->completed_date)){
        $text = '<p><b>Application Status:  Complete</b><br/><br/>
        Your application is now complete and has been forwarded to the Admissions Committee for review. Applications are reviewed on a rolling basis, generally in the order in which they are completed. If you have applied to our first-year class as a Regular Decision applicant, we will endeavor to provide you with a final decision no later than the end of April, provided your application was completed by February 15, our regular decision application deadline.
        <br/><br/>
        Please note that once an application is rendered "Complete" per the status checker and accompanying email, no further updates will be communicated via the status checker. Additionally, admissions decisions will not be available online; rather, all applicants will receive their final decisions by mail.
        <br/><br/>
        If you have any questions or concerns regarding your application components, please send an email to admissions@law.columbia.edu.
        <br/><br/>
        Thank you for your continued interest in Columbia Law School.';
        $log_params = array('type' => 9, //successful status check: application complete
                            'data' => array('email' => isset($user->mail) ? $user->mail : '',
                                            'name' => isset($user->name) ? $user->name : '',
                                            'lsac' => $Applicant->lsac_account_number,
                                            'first_name' => $Applicant->first_name,
                                            'last_name' => $Applicant->last_name,
                                            'dob' => $Applicant->birth_date),
                            'uid' => $user->uid,
                            'ip_address' => ip_address(),
                            'created' => REQUEST_TIME,
                            );
        cls_mcl_create_audit_log($log_params);
      }else{
        if($all_components_received){
          $text = '<b>Application Status:  Completion Pending</b><br/><br/>
We have received all the components of your application and are in the
process of compiling them for completion.  We kindly ask that you allow at
least two weeks from the date of your last submission for completion to
occur.  After your file is &ldquo;Complete,&rdquo; you will receive notification of this
update by email.
<br/><br/>
Thank you for your continued interest in Columbia Law School.';
        }else{
          $text = '<b>Application Status:  Incomplete</b><br/><br/>
Kindly note that the application components listed and unchecked above have
not yet been received or processed by our Office.  If, however, you have
already submitted the above-listed unchecked documents, we ask that you
allow at least 2 weeks from the date of submission for our staff to process
the materials and update your status.
<br/><br/>
If it has been more than 3 weeks since your last submission and you believe
that your application should now be &ldquo;Complete,&rdquo; you may contact the Office of
Admissions at <a href="mailto:admissions@law.columbia.edu">admissions@law.columbia.edu</a>
to request detailed information
about the status of materials received to date.  It typically takes our
staff 3-5 business days to respond to such requests.
<br/><br/>
Thank you for your continued interest in Columbia Law School.';
        }
        $log_params = array('type' => 10, //successful status check: application incomplete
                            'data' => array('email' => isset($user->mail) ? $user->mail : '',
                                            'name' => isset($user->name) ? $user->name : '',
                                            'lsac' => $Applicant->lsac_account_number,
                                            'first_name' => $Applicant->first_name,
                                            'last_name' => $Applicant->last_name,
                                            'dob' => $Applicant->birth_date),
                            'uid' => $user->uid,
                            'ip_address' => ip_address(),
                            'created' => REQUEST_TIME,
                            );
        cls_mcl_create_audit_log($log_params);
      }
    }
    $table = "<table>". $header . $rows . "</table>";
    return $table.'<br /><br />'.$text;
  }else{
    $rows .= '<tr><td><p>We cannot check the status of your application for admission because
the information you provided does not match any records in our database.

<p>In order for us to successfully check your application status, your first and
last names, LSAC Account Number, and date of birth must exactly match the
information you provided on your application for admission.

<p>Please go back to the previous page and ensure that the information
 you provided is exactly what you submitted on your application for admission.

<p><b>Please note that it takes up to two weeks for new application submissions to
be processed and entered into our database.  If you recently submitted an application
for admission, please try again after at least two weeks have passed.</b>

<p>Please contact the <a href="mailto:admissions@law.columbia.edu">Office of Admissions</a> if you continue to have difficulty with checking your application status.';
    $table = "<table>". $header . $rows . "</table>";
    return $table;
  }
}

function cls_mcl_get_applicant_status($Applicant){
    $all_components_received = true;
    //echo $Applicant->application_type;
    if(isset($Applicant->application_type) && in_array(trim(strtolower($Applicant->application_type)), array('transfer', 'visiting'))){
      // Transfer applicants
      if(!isset($Applicant->final_transcript) || !$Applicant->final_transcript){
        $all_components_received = false;
      }
      if(!isset($Applicant->dean_certification) || !$Applicant->dean_certification){
        $all_components_received = false;
      }
    }
    // All applicants
    if(!isset($Applicant->application_fee_received) || !$Applicant->application_fee_received){
      $all_components_received = false;
    }
    if(!isset($Applicant->personal_statement_received) || !$Applicant->personal_statement_received){
      $all_components_received = false;
    }
    if(!isset($Applicant->resume_on_file) || !$Applicant->resume_on_file){
      $all_components_received = false;
    }
    if(!isset($Applicant->lsdas_received_date)){
      $all_components_received = false;
    }
    if(!isset($Applicant->recommenders) || sizeof($Applicant->recommenders) < 2){
      $all_components_received = false;
    }
    if(!isset($Applicant->completed_date) || !$Applicant->completed_date){

    }
    return $all_components_received;
}
