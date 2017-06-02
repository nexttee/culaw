<?php

/**
 * @file
 * Functions related to new My Columbia Law account creation.
 */

/**
* Displays My Columbia Law New Account ("Getting Started") form.
*
* @return $html - string containing login window layout
*/
function cls_mcl_display_new_account_form($instance_id) {
  global $user;

  // If we are already logged on, go to the default page.
  if ($user->uid) {
    $site_instance = cls_get_site_instance($instance_id);
    drupal_goto($site_instance['path']);
  }

  drupal_add_css(drupal_get_path('module', 'cls_mcl') . '/css/getting_started.css', array('every_page' => FALSE));
  cls_common_add_body_class('cls-mcl-getting-started');

  $js_settings = array();
  $js_settings['instance_id'] =  $instance_id;
  $js_settings['action'] =  'create';
  $js_settings['uid'] =  0;
  drupal_add_js(array('cls_mcl_account' => $js_settings), 'setting');
  drupal_add_library('system', 'ui.datepicker');
  drupal_add_library('system', 'effects');
  libraries_load('xregexp');
  drupal_add_js(drupal_get_path('module', 'cls_mcl') . '/js/validation.js', array('every_page' => FALSE));
  drupal_add_js(drupal_get_path('module', 'cls_mcl') . '/js/account.js', array('every_page' => FALSE));

  return theme('new_account', array('form' => drupal_get_form('cls_mcl_new_account', $instance_id)));
}

function cls_mcl_new_account_steps() {
  return array(
      1 => array(
        'form' => 'cls_mcl_new_account_step_1',
      ),
      2 => array(
        'form' => 'cls_mcl_new_account_step_2',
      ),
    );
}

/**
 * Generates MCL New Account form.
 */
function cls_mcl_new_account($form, &$form_state, $instance_id) {
  if (empty($form_state['step'])) {
    $form_state['step'] = 1;
    $form_state['step_information'] = cls_mcl_new_account_steps();
  }
  $step = &$form_state['step'];

  // Call the function named in $form_state['step_information'] to get the form elements to display for this step.
  $form = $form_state['step_information'][$step]['form']($form, $form_state, $instance_id);

  $form['next']['#validate'] = array();
  // Include each validation function defined for the different steps.
  // First, look for functions that match the form_id_validate naming convention.
  if (function_exists($form_state['step_information'][$step]['form'] . '_validate')) {
    $form['next']['#validate'] = array($form_state['step_information'][$step]['form'] . '_validate');
  }
  // Next, merge in any other validate functions defined by child form.
  if (isset($form['#validate'])) {
    $form['next']['#validate'] = array_merge($form['next']['#validate'], $form['#validate']);
    unset($form['#validate']);
  }

  // Do the same thing for #submit handlers.
  // First, look for functions that match the form_id_submit naming convention.
  if (function_exists($form_state['step_information'][$step]['form'] . '_submit')) {
    $form['next']['#submit'] = array_merge($form_state['step_information'][$step]['form'] . '_submit', $form['next']['#submit']);
  }
  // Next, merge in any other submit functions defined by child form.
  if (isset($form['#submit'])) {
    // Form-specific handlers should be merged in first, before $form_state['values] are cleared.
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
function cls_mcl_new_account_next_submit($form, &$form_state) {
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
    $form_state['rebuild'] = TRUE;  // Force rebuild with next step.
    return;
  }
}

function cls_mcl_new_account_step_1(&$form, &$form_state, $instance_id) {

  $form['open_text'] = array(
    '#prefix' => '<div class="mcl-new-account-form-column">',
    '#markup' => '<div class="mcl-new-account-form-column-container">',
  );

  $form['title'] = array('#markup' => 'Getting Started',
                         '#prefix' => '<h2>',
                         '#suffix' => '</h2>');

  $form['error'] = array(
    '#prefix' => '<div id="cls-mcl-account-errors" class="messages error" style="">',
    '#markup' => '<ul style=""></ul>',
    '#suffix' => '</div>',
  );

  $form['first_name'] = array('#type' => 'textfield',
    '#prefix' => "<h3>Your Personal Information</h3>",
    '#title' => $instance_id == "my_columbia_llm" ? t('First/Given Name') : t('First Name'),
    //'#rules' => array(array('rule' => 'alpha_dash', 'error' => 'Please, use only letters and dashes in %field.')),
    '#required' => TRUE,
  );
  $form['middle_name'] = array('#type' => 'textfield',
    '#title' => t('Middle Name'),
    //'#rules' => array(array('rule' => 'alpha_dash', 'error' => 'Please, use only letters and dashes in %field.')),
    '#required' => FALSE,
  );
  $form['last_name'] = array('#type' => 'textfield',
    '#title' => $instance_id == "my_columbia_llm" ? t('Last/Surname') : t('Last Name'),
    //'#rules' => array(array('rule' => 'alpha_dash', 'error' => 'Please, use only letters and dashes in %field.')),
    '#required' => TRUE,
  );
  $form['birth_date'] = array('#type' => 'textfield',
    '#title' => $instance_id == "my_columbia_llm" ? t('Date of Birth') : t('Birth Date'),
    //'#rules' => array(array('rule' => 'date', 'error' => 'Invalid value for %field. Please provide a date in "mm-dd-yyyy" format.')),
    '#size' => 10,
    '#maxlength' => 10,
    '#required' => TRUE,
  );
  $form['lsac_account_number'] = array('#type' => 'textfield',
    '#title' => t('LSAC Account No.'),
    //'#rules' => array(array('rule' => 'lsac', 'error' => 'Invalid value for %field It must begin with an "L" followed by 8 digits.')),
    '#required' => FALSE,
    '#default_value' => '',
  );
  $form['email'] = array('#type' => 'textfield',
    '#prefix' => '<h3>'.t('Your Account Details').'</h3>',
    '#title' => t('Email'),
    //'#rules' => array('email'),
    '#required' => TRUE,
  );
  $form['email_reenter'] = array('#type' => 'textfield',
    '#title' => t('Re-enter Email'),
    //'#rules' => array('email'),
    '#required' => TRUE,
  );
  $form['password'] = array('#type' => 'password',
    '#title' => t('New Password'),
    '#required' => TRUE,
  );
  $form['password_reenter'] = array('#type' => 'password',
    '#title' => t('Re-enter Password'),
    '#required' => TRUE,
  );
  $form['security_question_options'] = array(
    '#type' => 'value',
    '#value' => cls_mcl_get_security_question_options($instance_id),
  );
  $form['security_question'] = array('#type' => 'select_or_other',
    '#title' => t('Security Question'),
    '#options' => $form['security_question_options']['#value'],
    '#default_value' => array(""),
    '#other' => t('Other (enter your own)'),
    '#required' => TRUE,
    '#multiple' => FALSE,
    '#other_delimiter' => ', ', // if this is FALSE only the last value will be used
    '#other_unknown_defaults' => 'other', // possible values 'append', 'ignore', 'other'
    //(if "other" is specified, you can also override #other_delimiter).
  );
  $form['security_answer'] = array('#type' => 'textfield',
    '#title' => t('Security Answer'),
    //'#rules' => array(array('rule' => 'alpha_numeric', 'error' => '%field must be alphanumeric and contain at least 2 alpha characters.')),
    '#required' => TRUE,
    //'#default_value' => 'Your Answer',
  );

  $form['instance_id'] = array(
    '#type' => 'value',
    '#value' => $instance_id
  );

    $form['next'] = array(
      '#type' => 'submit',
      '#value' => t('Next'),
      '#name' => 'next',
      '#button_type' => 'mcl-new-account-button',
      '#submit' => array('cls_mcl_new_account_next_submit'),
    );

  if ($instance_id == 'my_columbia_law') {

   $form['close_text'] = array(
      '#markup' => '    </div>
  </div>
  <div class="mcl-new-account-form-instructions-column">
    <p class="introduction">My Columbia Law is the best way for prospective students to explore the many resources available at the Law School through an experience tailored specifically to&nbsp;you.</p>
    <p class="introduction">My Columbia Law details what you can expect in your first, second and third years, including student life, clinics, externships, and the breadth of Columbia Law School&rsquo;s course offerings.</p>
    <p class="introduction">For applicants, My Columbia Law syncs with your application and features an integrated online status checker.</p>
    <p class="introduction">Whether you are just exploring the idea of law school or are ready to apply, let My&nbsp;Columbia Law be your guide.</p>
  </div>',
  );

  }
  else if ($instance_id == 'my_columbia_llm') {
    $form['close_text'] = array(
      '#markup' => '    </div>
  </div>
  <div class="mcl-new-account-form-instructions-column">
    <p class="introduction">My Columbia LL.M. is a great way for prospective LL.M. students to explore the many resources available at Columbia Law School through an experience tailored specifically to you.</p>
    <p class="introduction">My Columbia LL.M. introduces you to what you can expect during the LL.M. program, including student life, clinics, research opportunities, and the breadth of our course&nbsp;offerings.</p>
    <p class="introduction">Once you submit an application to us, through LSAC, My Columbia LL.M. will sync with your application and provide a link to LSAC&rsquo;s status&nbsp;checker.</p>
    <p class="introduction">Whether you are just considering the idea of pursuing an LL.M. degree or you are ready to apply, let My Columbia LL.M. be your guide.</p>
  </div>',
  );
  }


  return $form;
}

/**
 * Validates data from Step 1 of the New Account form.
 * Displays error message if validation fails.
 */
function cls_mcl_new_account_step_1_validate($form, &$form_state) {
  $first_name_validation_data = cls_mcl_validate_name(trim($form_state['values']['first_name']), $form_state['values']['instance_id']);
  $middle_name_validation_data = cls_mcl_validate_name_no_minimum(trim($form_state['values']['middle_name']), $form_state['values']['instance_id']);
  $last_name_validation_data = cls_mcl_validate_name(trim($form_state['values']['last_name']), $form_state['values']['instance_id']);
  $birth_date_validation_data = cls_mcl_validate_birth_date(trim($form_state['values']['birth_date']));
  $lsac_validation_data = cls_mcl_validate_lsac_for_new_account(trim($form_state['values']['lsac_account_number']));
  $email_validation_data = cls_mcl_validate_email(trim($form_state['values']['email']));
  $email_reenter_validation_data = cls_mcl_validate_email(trim($form_state['values']['email_reenter']));
  $email_match_data = cls_mcl_validate_equality($form_state['values']['email'], $form_state['values']['email_reenter']);
  $password_match_data = cls_mcl_validate_equality($form_state['values']['password'], $form_state['values']['password_reenter']);
  $security_question_validation_data = cls_mcl_validate_security_question(trim($form_state['values']['security_question']), $form_state['values']['instance_id']);
  $security_answer_validation_data = cls_mcl_validate_security_answer(trim($form_state['values']['security_answer']));
  $return_flag = true;
  if (!$first_name_validation_data['result']){
    form_set_error('first_name', t('First name' . $first_name_validation_data['error']));
    $return_flag = false;
  }else if(!$middle_name_validation_data['result']){
  	form_set_error('middle_name', t('Middle name' . $middle_name_validation_data['error']));
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
  }else if(!$email_validation_data['result']){
  	form_set_error('email', t('Email' . $email_validation_data['error']));
    $return_flag = false;
  }else if(!$email_reenter_validation_data['result']){
  	form_set_error('email_reenter', t('"Re-enter email"' . $email_reenter_validation_data['error']));
    $return_flag = false;
  }else if(!$email_match_data['result']){
  	form_set_error('email', t('Emails' . $email_match_data['error']));
    $return_flag = false;
  }else if(!trim($form_state['values']['password'])){
  	form_set_error('password', t('Password is required.'));
    $return_flag = false;
  }else if(!trim($form_state['values']['password_reenter'])){
  	form_set_error('password_reenter', t('"Re-enter password" field is required.'));
    $return_flag = false;
  }else if(!$password_match_data['result']){
  	form_set_error('password', t('Passwords' . $password_match_data['error']));
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

function cls_mcl_new_account_step_2(&$form, &$form_state, $instance_id)  {

  libraries_load_files(libraries_load('select2', 'minified'));
  drupal_add_js(drupal_get_path('module', 'cls_mcl') . '/js/select2_autocomplete.js', array('every_page' => FALSE));

  $form['open_text'] = array(
      '#markup' => '<div class="mcl-new-account-form-column">
    <div class="mcl-new-account-form-column-container"><!-- Serverside errors should go here -->',
  );

  $current_year = variable_get('cls_mcl.config.current_application_year', date("Y"));
  $form['application_year_options'] = array(
    '#type' => 'value',
  );

  $next_year = $current_year + 1;
  $year_after_next = $next_year + 1;
  $two_years_after_next = $next_year + 2;
  $graduation_year = $current_year + 3;
  $next_graduation_year = $graduation_year + 1;

  if ($instance_id == "my_columbia_law") {

  	$form['application_year_options']['#value'] = array("" => "");
    $form['application_year_options']['#value'][$graduation_year] = t("This year (Class of $graduation_year)");
    $form['application_year_options']['#value'][$next_graduation_year] = t("Next year (Class of $next_graduation_year)");
    $form['application_year_options']['#value'][0] = t("Undecided/Other");

  }
  else if ($instance_id == "my_columbia_llm") {
    $form['application_year_options']['#value'][$current_year] = t("$current_year\xe2\x80\x93$next_year Academic Year");
    $form['application_year_options']['#value'][$next_year] = t("$next_year\xe2\x80\x93$year_after_next Academic Year");
    $form['application_year_options']['#value'][$year_after_next] = t("$year_after_next\xe2\x80\x93$two_years_after_next Academic Year");
  }

  $form['graduation_year_options'] = array(
    '#type' => 'value',
    '#value' => array('' => $instance_id == 'my_columbia_llm' ? t("\xe2\x80\x94 Select your graduation year \xe2\x80\x94") : ''),
  );

  for ($i = -10; $i < 51; $i++){
    $form['graduation_year_options']['#value'][intval($current_year)-$i] = (intval($current_year)-$i);
  }

  $form['country_options'] = array(
    '#type' => 'value',
    '#value' => array("" => t("\xe2\x80\x94 Select your country \xe2\x80\x94")),
  );

  $country_options = cls_mcl_get_country_options();
  $form['country_options']['#value'] = array_merge($form['country_options']['#value'], $country_options);

  $form['state_options'] = array(
    '#type' => 'value',
    '#value' => array("" => "\xe2\x80\x94 Select a value \xe2\x80\x94"),
  );

  $state_options = cls_mcl_get_state_options();
  $form['state_options']['#value'] = array_merge($form['state_options']['#value'], $state_options);

  $form['title'] = array('#markup' => "Tell us about yourself",
                         '#prefix' => "<h2>",
                         '#suffix' => "</h2>");

  $form['error'] = array(
    '#prefix' => '<div id="cls-mcl-account-errors" class="messages error" style="display: none;">',
    '#markup' => '<ul style="display: none;"></ul>',
    '#suffix' => '</div>',
  );

  $form['application_year'] = array('#type' => 'select',
    '#title' => $instance_id == "my_columbia_llm" ? t('For which academic year will you apply?') : t('When do you plan on applying?'),
    //'#description' => t('Enter your application year.'),
    '#options' => $form['application_year_options']['#value'],
    '#default_value' => t("This year for the class of ").(intval($current_year)+4),
    '#required' => TRUE,
  );
  $form['location_header'] = array(
    '#type' => 'markup',
    '#markup' => $instance_id == "my_columbia_llm" ? "<h3>Where do you currently live?</h3>" : "<h3>Your Current Location</h3>",
  );
  $form['country'] = array('#type' => 'select',
    '#title' => $instance_id == "my_columbia_llm" ?  t('Country') : t('Your Country'),
    //'#description' => t('Enter your country.'),
    '#options' => $form['country_options']['#value'],
    '#default_value' => $instance_id == "my_columbia_llm" ? "" : "USA",
    '#required' => TRUE,
    '#autocomplete_path' => 'mcl/get-countries',
  );
  $form['state_province'] = array('#type' => 'select',
    '#title' => ($instance_id == "my_columbia_llm" ? t('State/Province') : t('Your State/Province')) . t(' <span title="This field is required." class="form-required">*</span>'),
    //'#description' => t('Enter your state or province.'),
    '#options' => $form['state_options']['#value'],
    '#default_value' => "",
    '#required' => FALSE,
    '#autocomplete_path' => 'mcl/get-states',
  );
  $form['city'] = array('#type' => 'textfield',
    '#title' => $instance_id == "my_columbia_llm" ? t('City') : t('Your City'),
    //'#description' => t('Enter your city.'),
    //'#rules' => array(array('rule' => 'city', 'error' => 'Invalid value for %field.')),
    '#size' => 60,
    '#required' => TRUE,
  );
  $form['zip_code'] = array('#type' => 'textfield',
    '#title' => ($instance_id == "my_columbia_llm" ? t('ZIP Code') : t('Your ZIP Code') ) . t(' <span title="This field is required." class="form-required">*</span>'),
    //'#description' => t('Enter your zip code.'),
    '#size' => 5,
    '#maxlength' => 5,
    '#required' => FALSE,
  );
  $form['undergrad_header'] = array(
    '#type' => 'markup',
    '#markup' => $instance_id == "my_columbia_llm" ? "<h3>First Law Degree</h3>" : "<h3>Your Undergraduate Education</h3>",
  );
  $form['undergrad_school_name'] = array(
    '#type' => 'textfield',
    '#title' => $instance_id == "my_columbia_llm" ? t('School Name <span class="form-required" title="This - field is required.">*</span>') : t('School Name'),
    '#required' => FALSE,
    '#autocomplete_path' => 'mcl/get-schools/' . $instance_id,
    '#attributes' => array(
      'class' => array('form-autocomplete','form-select2'),
      'data-placeholder' => "Search for your school...",
      'style' => "width: 264px; height: 31px; color: #666666; font: font: 12px/10px Verdana,Arial,Helvetica,sans-serif;",
      'data-no-results-callback' => "toggleUndergradSchoolOtherField",
      'data-no-results-text' => "Can&rsquo;t find your school?",
    ),
    '#default_value' => '',
    '#prefix' => '<div id="undergrad-school-name-field-container">',
    '#suffix' => '</div>',
  );
  $form['undergrad_school_name_other'] = array('#type' => 'textfield',
    '#title' => t('School Name <span class="form-required" title="This field is required.">*</span>'),
    '#required' => FALSE,
    '#size' => 255,
    '#maxlength' => 255,
    '#default_value' => "",
    '#prefix' => '<div id="undergrad-school-name-other-field-container" class="hidden">',
    '#suffix' => '</div>',
  );
  $form['undergrad_school_other_display_link'] = array(
    '#type' => 'markup',
    '#markup' => "<div id='undergrad-school-other-display-link-area' class=\"school-other-display-link-area\"><a id='undergrad-school-other-display-link' onclick='toggleUndergradSchoolOtherField();'>Can&rsquo;t find your school?</a></div><div class='divider'></div>",
  );
  $form['undergrad_school_other_display_link_hide'] = array(
    '#type' => 'markup',
    '#markup' => "<div id='undergrad-school-other-display-link-area-hide' class=\"hidden school-other-display-link-area\">If your school was not listed, please enter its name, or <a id='undergrad-school-other-display-link' onclick='toggleUndergradSchoolOtherField();'>try your search again</a>.</div><div class='divider'></div>",
  );
  $form['undergrad_graduation_year'] = array('#type' => 'select',
    '#title' => t('Graduation Year'),
    '#options' => $form['graduation_year_options']['#value'],
    '#default_value' => '',
    '#required' => $instance_id == "my_columbia_llm" ? TRUE : FALSE,
  );
  $form['grad_header'] = array(
    '#type' => 'markup',
    '#markup' => $instance_id == "my_columbia_llm" ? "<h3>Other Law or Post-Secondary Degree</h3>" : "<h3>Your Graduate Education</h3>",
  );
  $form['grad_school_name'] = array(
    '#type' => 'textfield',
    '#title' => t('School Name'),
    '#required' => FALSE,
    '#autocomplete_path' => 'mcl/get-schools/' . $instance_id,
    '#attributes' => array(
      'class' => array('form-autocomplete','form-select2'),
      'data-placeholder' => "Search for your school...",
      'style' => "width: 264px; height: 31px; color: #666666; font: font: 12px/10px Verdana,Arial,Helvetica,sans-serif;",
      'data-no-results-callback' => "toggleGradSchoolOtherField",
      'data-no-results-text' => "Can&rsquo;t find your school?",
    ),
    '#default_value' => '',
    '#prefix' => '<div id="undergrad-school-name-field-container">',
    '#suffix' => '</div>',
  );
  $form['grad_school_name_other'] = array('#type' => 'textfield',
    '#title' => t('School Name'),
    '#required' => FALSE,
    '#size' => 255,
    '#maxlength' => 255,
    '#default_value' => "",
    '#prefix' => '<div id="grad-school-name-other-field-container" class="hidden">',
    '#suffix' => '</div>',
  );
  $form['grad_school_other_display_link'] = array(
    '#type' => 'markup',
    '#markup' => "<div id='grad-school-other-display-link-area' class=\"school-other-display-link-area\"><a id='grad-school-other-display-link' onclick='toggleGradSchoolOtherField();'>Can&rsquo;t find your school?</a></div><div class='divider'></div>",
  );
  $form['grad_school_other_display_link_hide'] = array(
    '#type' => 'markup',
    '#markup' => "<div id='grad-school-other-display-link-area-hide' class=\"hidden school-other-display-link-area\">If your school was not listed, please enter its name, or <a id='grad-school-other-display-link' onclick='toggleGradSchoolOtherField();'>try your search again</a>.</div><div class='divider'></div>",
  );
  $form['grad_school_graduation_year'] = array('#type' => 'select',
    '#title' => t('Graduation Year'),
    '#options' => $form['graduation_year_options']['#value'],
    '#default_value' => '',
    '#required' => FALSE,
  );
    $form['learn_more'] = array(
      '#type' => 'submit',
      '#button_type' => 'mcl-new-account-button',
      '#value' => t('Create your account'),
    );

    if ($instance_id == 'my_columbia_llm') {
      $form['close_text'] = array(
        '#markup' => '    </div>
    </div>
    <div class="mcl-new-account-form-instructions-column">
      <img src="' . base_path() . drupal_get_path('module', 'cls_mcl') . '/images/registration-page-two-llm.jpg" width="420" height="420" />
    </div>',
  );
    }
    else {
      $form['close_text'] = array(
        '#markup' => '    </div>
    </div>
    <div class="mcl-new-account-form-instructions-column">
      <img src="' . base_path() . drupal_get_path('module', 'cls_mcl') . '/images/get-started-2.jpg" width="420" height="420" />
    </div>',
    );
    }

  return $form;
}

/**
 * Validates data from Step 2 of the New Account form.
 * Displays error message if validation fails.
 */
function cls_mcl_new_account_validate($form, &$form_state) {
  $country_validation_data = cls_mcl_validate_name($form_state['values']['country']);
  $city_validation_data = cls_mcl_validate_name(trim($form_state['values']['city']));
  if (!$form_state['values']['undergrad_school_name']) {
    if ($form_state['step_information'][1]['stored_values']['instance_id'] == "my_columbia_llm") {
      $undergrad_school_validation_data = cls_mcl_validate_name(trim($form_state['values']['undergrad_school_name_other']));
    }
    else {
      $undergrad_school_validation_data = cls_mcl_validate_name_non_required(trim($form_state['values']['undergrad_school_name_other']));
    }
  }
  if (!$form_state['values']['grad_school_name']) {
    $grad_school_validation_data = cls_mcl_validate_name_non_required(trim($form_state['values']['grad_school_name_other']));
  }
  if(isset($form_state['values']['state_province']) && in_array($form_state['values']['country'], array('USA','CAN'))){
    $state_province_validation_data = cls_mcl_validate_name_non_required($form_state['values']['state_province']);
  }
  if(isset($form_state['values']['zip_code']) && $form_state['values']['country'] == 'USA'){
    $zip_code_validation_data = cls_mcl_validate_zip_code(trim($form_state['values']['zip_code']));
  }
  $return_flag = true;
  if (!$country_validation_data['result']){
    form_set_error('country', t('Country' . $country_validation_data['error']));
    $return_flag = false;
  }else if(!$city_validation_data['result']){
  	form_set_error('city', t('City' . $city_validation_data['error']));
  	$return_flag = false;
  }else if(isset($form_state['values']['state_province']) && in_array($form_state['values']['country'], array('USA','CAN')) && !$state_province_validation_data['result']){
  	form_set_error('state_province', t('State or Province' . $state_province_validation_data['error']));
    $return_flag = false;
  }else if(isset($form_state['values']['zip_code']) && $form_state['values']['country'] == 'USA' && !$zip_code_validation_data['result']){
  	form_set_error('zip_code', t('Zip code' . $zip_code_validation_data['error']));
    $return_flag = false;
  }else if(!$form_state['values']['undergrad_school_name'] && !$undergrad_school_validation_data['result']){
  	form_set_error('undergrad_school_name', t('Undergraduate school name' . $undergrad_school_validation_data['error']));
    $return_flag = false;
  }else if(!$form_state['values']['grad_school_name'] && !$grad_school_validation_data['result']){
  	form_set_error('grad_school_name', t('Graduate school name' . $grad_school_validation_data['error']));
    $return_flag = false;
  }
  return $return_flag;
}

function cls_mcl_new_account_submit($form, &$form_state) {
  $current_step = &$form_state['step'];
  $form_state['step_information'][$current_step]['stored_values'] = $form_state['values'];
  cls_mcl_new_account_save($form, $form_state);
  // Redirect the new user.
  $site_instance = cls_get_site_instance($form_state['step_information'][1]['stored_values']['instance_id']);
  drupal_goto($site_instance['tour_path']);
}

/**
 * Submit handler for the New Account form (with Skip Tour option).
 *
 */
function cls_mcl_new_account_skip_tour_submit($form, &$form_state) {
  $current_step = &$form_state['step'];
  $form_state['step_information'][$current_step]['stored_values'] = $form_state['values'];
  cls_mcl_new_account_save($form, $form_state);
  $site_instance = cls_get_site_instance($form_state['step_information'][1]['stored_values']['instance_id']);
  drupal_goto($site_instance['path']);
}

/**
 * Saves new account data after form submission.
 *
 */
function cls_mcl_new_account_save($form, &$form_state) {
  global $user;
  if(isset($form_state['step_information'][1]['stored_values']) && isset($form_state['step_information'][2]['stored_values'])){
    if($form_state['step_information'][1]['stored_values']['email'] && $form_state['step_information'][1]['stored_values']['password']){
      require_once DRUPAL_ROOT . '/' . variable_get('password_inc', 'includes/password.inc');
      // Create a new Drupal user
      $userinfo = array(
          'name' => $form_state['step_information'][1]['stored_values']['email'],
          'pass' => $form_state['step_information'][1]['stored_values']['password'],
          'mail' => $form_state['step_information'][1]['stored_values']['email'],
          'signature_format' => 'filtered_html',
          'init' => $form_state['step_information'][1]['stored_values']['email'],
          'status' => 1,
      );
      $site_instance = cls_get_site_instance($form_state['step_information'][1]['stored_values']['instance_id']);
  	  $admitted_site_instance_id = $form_state['step_information'][1]['stored_values']['instance_id'] == "my_columbia_llm" ? "gls" : "jd";
  	  $admitted_site_instance = cls_admissions_admitted_get_site_instance($admitted_site_instance_id);
      $role_prospective = $admitted_site_instance['role_prospective'];
      $role_deposited = $admitted_site_instance['role_deposited'];

      $userinfo['cls_user_first_name']['und'][0]['value'] = trim($form_state['step_information'][1]['stored_values']['first_name']);
      $userinfo['cls_user_middle_name']['und'][0]['value'] = trim($form_state['step_information'][1]['stored_values']['middle_name']);
      $userinfo['cls_user_last_name']['und'][0]['value'] = trim($form_state['step_information'][1]['stored_values']['last_name']);
      $userinfo['cls_mcl_birth_date']['und'][0]['value'] = trim($form_state['step_information'][1]['stored_values']['birth_date']);
      $userinfo['cls_mcl_account_type']['und'][0]['value'] = $form_state['step_information'][1]['stored_values']['instance_id'];
      $security_question_options = cls_mcl_get_security_question_options($form_state['step_information'][1]['stored_values']['instance_id']);
      if(isset($security_question_options[$form_state['step_information'][1]['stored_values']['security_question']])){
          $userinfo['cls_mcl_security_question']['und'][0]['value'] = $security_question_options[$form_state['step_information'][1]['stored_values']['security_question']];
      }else{
          $userinfo['cls_mcl_security_question']['und'][0]['value'] = trim($form_state['step_information'][1]['stored_values']['security_question']);
      }
      $userinfo['cls_mcl_security_answer']['und'][0]['value'] = user_hash_password(trim(strtolower($form_state['step_information'][1]['stored_values']['security_answer'])));
      $userinfo['cls_mcl_lsac_account_number']['und'][0]['value'] = trim($form_state['step_information'][1]['stored_values']['lsac_account_number']);
      $userinfo['cls_mcl_admissions_cycle']['und'][0]['value'] = $form_state['step_information'][2]['stored_values']['application_year'];
      $userinfo['cls_mcl_country']['und'][0]['value'] = $form_state['step_information'][2]['stored_values']['country'];
      $userinfo['cls_mcl_state_province']['und'][0]['value'] = $form_state['step_information'][2]['stored_values']['state_province'];
      $userinfo['cls_mcl_city']['und'][0]['value'] = trim($form_state['step_information'][2]['stored_values']['city']);
      $userinfo['cls_mcl_zip_code']['und'][0]['value'] = trim($form_state['step_information'][2]['stored_values']['zip_code']);
      if(isset($form_state['step_information'][2]['stored_values']['undergrad_school_name']) && $form_state['step_information'][2]['stored_values']['undergrad_school_name']){
          $userinfo['cls_mcl_undergrad_institution']['und'][0]['value'] = $form_state['step_information'][2]['stored_values']['undergrad_school_name'];
      }else if (isset($form_state['step_information'][2]['stored_values']['undergrad_school_name_other']) && $form_state['step_information'][2]['stored_values']['undergrad_school_name_other']){
          $userinfo['cls_mcl_undergrad_inst_other']['und'][0]['value'] = $form_state['step_information'][2]['stored_values']['undergrad_school_name_other'];
      }
      $userinfo['cls_mcl_undergrad_grad_year']['und'][0]['value'] = $form_state['step_information'][2]['stored_values']['undergrad_graduation_year'];
      if(isset($form_state['step_information'][2]['stored_values']['grad_school_name']) && $form_state['step_information'][2]['stored_values']['grad_school_name']){
          $userinfo['cls_mcl_grad_institution']['und'][0]['value'] = $form_state['step_information'][2]['stored_values']['grad_school_name'];
      }else if (isset($form_state['step_information'][2]['stored_values']['grad_school_name_other']) && $form_state['step_information'][2]['stored_values']['grad_school_name_other']){
          $userinfo['cls_mcl_grad_inst_other']['und'][0]['value'] = $form_state['step_information'][2]['stored_values']['grad_school_name_other'];
      }
      $userinfo['cls_mcl_grad_graduation_year']['und'][0]['value'] = $form_state['step_information'][2]['stored_values']['grad_school_graduation_year'];
      $loaded_user = user_load_by_name($form_state['step_information'][1]['stored_values']['email']);
      if ($loaded_user){
        $user = $loaded_user;
        drupal_session_regenerate();
        $log_params = array('type' => 6, //failed account creation
                            'data' => array('email' => $user->mail,
                                            'name' => $user->name),
                            'uid' => $user->uid,
                            'ip_address' => ip_address(),
                            'created' => REQUEST_TIME,
                            );
        cls_mcl_create_audit_log($log_params);
      }else{
        $new_user = user_save('', $userinfo);
        if($new_user){
          if (cls_aces2_applicant_load_by_program_email_status(1, $form_state['step_information'][1]['stored_values']['email'], "Deposit")) {
            cls_common_user_add_role_by_name($role_deposited, $new_user->uid);
          }
          else {
          	cls_common_user_add_role_by_name($role_prospective, $new_user->uid);
          }
          $user = user_load($new_user->uid);
          drupal_session_regenerate();
          $log_params = array('type' => 5, //successful account creation
                        'data' => array('email' => $user->mail,
                                        'name' => $user->name),
                        'uid' => $user->uid,
                        'ip_address' => ip_address(),
                         'created' => REQUEST_TIME,
                        );
          cls_mcl_create_audit_log($log_params);
          cls_mcl_send_new_account_email($user, $form_state['step_information'][1]['stored_values']['instance_id']);
        }
      }
    }
  }else{
  	$log_params = array('type' => 6, //failed account creation
                        'data' => array('email' => $user->mail,
                                        'name' => $user->name),
                        'uid' => $user->uid,
                        'ip_address' => ip_address(),
                        'created' => REQUEST_TIME,
                        );
    cls_mcl_create_audit_log($log_params);
    // @TODO Does this path exist? Either way, we should change to some kind of
    //   error page instead within the context of the site instance.
    drupal_goto('user-not-saved');
  }
}

/**
  * Sends out new account email.
  *
  * @param user $account - newly created account
  *
  * @return array $result - array returned by the Mandrill::call() function.
*/
function cls_mcl_send_new_account_email($account, $instance_id) {

  $site_instance = cls_get_site_instance($instance_id);

  $api_key = $site_instance['mandrill_api_key'];
  $mandrill_template_slug = $site_instance['mandrill_template_slugs']['new_account'];

  $first_name = $account->cls_user_first_name['und'][0]['value'];
  $last_name = $account->cls_user_last_name['und'][0]['value'];

  $message_options = array(
    'to_email' => $account->mail,
    'to_name' => $first_name . ' ' . $last_name,
    'track_opens' => TRUE,
    'track_clicks' => TRUE,
    'url_strip_qs' => TRUE,
  );

  $merge_variables = array(
    'NAME' => $first_name . ' ' . $last_name,
    'USER_NAME' => !empty($account->name) ? $account->name : 'your email address',
  );

  // Force production mode and use the template defaults for
  // subject, from_name, and from_email message options.
  // @TODO Make this a module variable for this individual variable
  return cls_mandrill_integration_send_template_email($mandrill_template_slug, $message_options, $merge_variables, array(), $api_key, array('force_production_mode' => FALSE, 'use_template_defaults' => TRUE));

}
