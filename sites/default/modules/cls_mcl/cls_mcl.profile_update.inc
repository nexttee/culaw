<?php

/**
 * @file
 * Functions related to new My Columbia Law profile update interface.
 */

/**
* Displays My Columbia Law "Update My Profile" form.
*
* @return $html - string containing login window layout
*/
function cls_mcl_display_profile_update($instance_id) {
  global $user;

  drupal_add_css(drupal_get_path('module', 'cls_mcl') . '/css/update_profile.css', array('every_page' => FALSE));

  $js_settings = array();
  $js_settings['instance_id'] =  $instance_id;
  $js_settings['action'] =  'edit';
  $js_settings['uid'] =  $user->uid;
  $edited_user = user_load($user->uid);
  $js_settings['existing_undergrad_school'] = isset($edited_user->cls_mcl_undergrad_institution['und'][0]['value']) ? $edited_user->cls_mcl_undergrad_institution['und'][0]['value'] : "";
  drupal_add_js(array('cls_mcl_account' => $js_settings), 'setting');
  drupal_add_library('system', 'ui.datepicker');
  drupal_add_library('system', 'effects');
  libraries_load('xregexp');
  drupal_add_js(drupal_get_path('module', 'cls_mcl') . '/js/validation.js', array('every_page' => FALSE));
  drupal_add_js(drupal_get_path('module', 'cls_mcl') . '/js/account.js', array('every_page' => FALSE));
  libraries_load_files(libraries_load('select2', 'minified'));
  drupal_add_js(drupal_get_path('module', 'cls_mcl') . '/js/select2_autocomplete.js', array('every_page' => FALSE));

  return theme('update_my_profile', array('form' => drupal_get_form('cls_mcl_profile_update', $instance_id)));
}

/**
 * Generates MCL "Update My Profile" form.
 */
function cls_mcl_profile_update($form, &$form_state, $instance_id) {
  global $user;

  $edited_user = user_load($user->uid);
  if (isset($edited_user->cls_mcl_account_type['und'][0]['value']) && !empty($edited_user->cls_mcl_account_type['und'][0]['value'])) {
  	if ($edited_user->cls_mcl_account_type['und'][0]['value'] != $instance_id) {
  	  $site_instances = cls_get_site_instances($edited_user->cls_mcl_account_type['und'][0]['value']);
  	  drupal_goto($site_instances['path'] . '/update-my-profile');
  	}
  }

  $site_instance = cls_get_site_instance($instance_id);

  $form['open_text'] = array(
    '#prefix' => '<div class="mcl-update-profile-form-column">',
    '#markup' => '<div class="mcl-update-profile-form-column-container">',
  );

  $form['title'] = array('#markup' => 'Profile Update',
                         '#prefix' => '<h2>',
                         '#suffix' => '</h2>'
  );

  $form['error'] = array(
    '#prefix' => '<div id="cls-mcl-account-errors" class="messages error" style="display: none;">',
    '#markup' => '<ul style="display: none;"></ul>',
    '#suffix' => '</div>',
  );

  $form['first_name'] = array('#type' => 'textfield',
    '#prefix' => "<h3>Your Personal Information</h3>",
    '#title' => $instance_id == "my_columbia_llm" ? t('First/Given Name') : t('First Name'),
    //'#rules' => array(array('rule' => 'alpha_dash', 'error' => 'Please, use only letters and dashes in %field.')),
    '#required' => TRUE,
    '#default_value' => isset($edited_user->cls_user_first_name['und'][0]['value']) ? $edited_user->cls_user_first_name['und'][0]['value'] : "",
  );
  $form['middle_name'] = array('#type' => 'textfield',
    '#title' => t('Middle Name'),
    //'#rules' => array(array('rule' => 'alpha_dash', 'error' => 'Please, use only letters and dashes in %field.')),
    '#required' => FALSE,
    '#default_value' => isset($edited_user->cls_user_middle_name['und'][0]['value']) ? $edited_user->cls_user_middle_name['und'][0]['value'] : "",
  );
  $form['last_name'] = array('#type' => 'textfield',
    '#title' => $instance_id == "my_columbia_llm" ? t('Last/Surname') : t('Last Name'),
    //'#rules' => array(array('rule' => 'alpha_dash', 'error' => 'Please, use only letters and dashes in %field.')),
    '#required' => TRUE,
    '#default_value' => isset($edited_user->cls_user_last_name['und'][0]['value']) ? $edited_user->cls_user_last_name['und'][0]['value'] : "",
  );
  $form['birth_date'] = array('#type' => 'textfield',
    '#title' => $instance_id == "my_columbia_llm" ? t('Date of Birth') : t('Birth Date'),
    //'#rules' => array(array('rule' => 'date', 'error' => 'Invalid value for %field. Please provide a date in "mm-dd-yyyy" format.')),
    '#size' => 10,
    '#maxlength' => 10,
    '#required' => TRUE,
    '#default_value' => isset($edited_user->cls_mcl_birth_date['und'][0]['value']) ? $edited_user->cls_mcl_birth_date['und'][0]['value'] : "",
  );
  $form['lsac_account_number'] = array('#type' => 'textfield',
    '#title' => t('LSAC Account No.'),
    //'#rules' => array(array('rule' => 'lsac', 'error' => 'Invalid value for %field It must begin with an "L" followed by 8 digits.')),
    '#required' => FALSE,
    '#default_value' => 'L',
    '#default_value' => isset($edited_user->cls_mcl_lsac_account_number['und'][0]['value']) ? $edited_user->cls_mcl_lsac_account_number['und'][0]['value'] : "",
  );
  $form['password'] = array('#type' => 'password',
    '#title' => t('New Password'),
    '#required' => FALSE,
  );
  $form['password_reenter'] = array('#type' => 'password',
    '#title' => t('Re-enter Password'),
    '#required' => FALSE,
  );
  $security_question_options = cls_mcl_get_security_question_options($instance_id);
  $form['security_question_options'] = array(
    '#type' => 'value',
    '#value' => $security_question_options,
  );
  $security_question_default_value = NULL;
  if(isset($edited_user->cls_mcl_security_question['und'][0]['value'])){
      if(in_array($edited_user->cls_mcl_security_question['und'][0]['value'], $security_question_options)){
          $security_question_default_value = array_search($edited_user->cls_mcl_security_question['und'][0]['value'], $security_question_options);
      }else{
          $security_question_default_value = $edited_user->cls_mcl_security_question['und'][0]['value'];
      }
  }

  $form['security_question'] = array('#type' => 'select_or_other',
    '#title' => t('Security Question'),
    '#options' => $form['security_question_options']['#value'],
    '#other' => t('Other (enter your own)'),
    '#required' => TRUE,
    '#multiple' => FALSE,
    '#other_delimiter' => ', ', // if this is FALSE only the last value will be used
    '#other_unknown_defaults' => 'other', // possible values 'append', 'ignore', 'other'
    //(if "other" is specified, you can also override #other_delimiter).
    '#default_value' => $security_question_default_value,
  );
  $form['security_answer'] = array('#type' => 'textfield',
    '#title' => t('New Security Answer'),
    //'#rules' => array(array('rule' => 'alpha_numeric', 'error' => '%field must be alphanumeric and contain at least 2 alpha characters.')),
    '#required' => FALSE,
  );

  $current_year = variable_get('cls_mcl.config.current_application_year', date("Y"));
  $next_year = $current_year + 1;
  $year_after_next = $next_year + 1;
  $two_years_from_now = $next_year + 2;
  $graduation_year = $current_year + 3;
  $next_graduation_year = $graduation_year + 1;

  if ($instance_id == "my_columbia_law") {

    $form['application_year_options']['#value'][$graduation_year] = t("This year (Class of $graduation_year)");
    $form['application_year_options']['#value'][$next_graduation_year] = t("Next year (Class of $next_graduation_year)");
    $form['application_year_options']['#value'][0] = t("Undecided/Other");

  }
  else if ($instance_id == "my_columbia_llm") {

    $form['application_year_options']['#value'][$current_year] = t("$current_year\xe2\x80\x93$next_year Academic Year");
    $form['application_year_options']['#value'][$next_year] = t("$next_year\xe2\x80\x93$year_after_next Academic Year");

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

  $countries = db_select('cls_mcl_countries', 'cmc')
      ->fields('cmc', array('country_code', 'country_name'))
      ->orderBy('country_name', 'ASC')
      ->execute();
  while ($country_record = $countries->fetchAssoc()) {
    $form['country_options']['#value'][$country_record['country_code']]	= ucwords(strtolower($country_record['country_name']));
  }
  $form['state_options'] = array(
    '#type' => 'value',
    '#value' => array("" => "\xe2\x80\x94 Select a value \xe2\x80\x94"),
  );

  $states = db_select('cls_mcl_states', 'cms')
      ->fields('cms', array('state_code', 'state_name'))
      ->orderBy('state_name', 'ASC')
      ->execute();
  while ($state_record = $states->fetchAssoc()) {
    $form['state_options']['#value'][$state_record['state_code']] = ucwords(strtolower($state_record['state_name']));
  }

  $school_options = cls_mcl_get_school_options();
  $undergrad_institution_default_value = 0;
  $graduate_institution_default_value = 0;
  if(isset($edited_user->cls_mcl_undergrad_institution['und'][0]['value']) && $edited_user->cls_mcl_undergrad_institution['und'][0]['value']){
      if(isset($school_options[$edited_user->cls_mcl_undergrad_institution['und'][0]['value']])){
          $undergrad_institution_default_value = $school_options[$edited_user->cls_mcl_undergrad_institution['und'][0]['value']];
      }
  }else if(isset($edited_user->cls_mcl_undergrad_inst_other['und'][0]['value'])){
      $undergrad_institution_default_value = $edited_user->cls_mcl_undergrad_inst_other['und'][0]['value'];
  }
  if(isset($edited_user->cls_mcl_grad_institution['und'][0]['value']) && $edited_user->cls_mcl_grad_institution['und'][0]['value']){
      if(isset($school_options[$edited_user->cls_mcl_grad_institution['und'][0]['value']])){
          $graduate_institution_default_value = $school_options[$edited_user->cls_mcl_grad_institution['und'][0]['value']];
      }
  }else if(isset($edited_user->cls_mcl_grad_inst_other['und'][0]['value'])){
      $graduate_institution_default_value = $edited_user->cls_mcl_grad_inst_other['und'][0]['value'];
  }

  $form['application_year'] = array('#type' => 'select',
    '#title' => $instance_id == "my_columbia_llm" ? t('For which academic year will you apply?') : t('When do you plan on applying?'),
    //'#description' => t('Enter your application year.'),
    '#options' => $form['application_year_options']['#value'],
    //'#default_value' => t("This year for the class of ").(intval($current_year)+4),
    '#required' => TRUE,
    '#default_value' => isset($edited_user->cls_mcl_admissions_cycle['und'][0]['value']) ? $edited_user->cls_mcl_admissions_cycle['und'][0]['value'] : "",
  );
  $form['location_header'] = array(
    '#type' => 'markup',
    '#markup' => $instance_id == "my_columbia_llm" ? "<h3>Where do you currently live?</h3>" : "<h3>Your Current Location</h3>",
  );
  $form['country'] = array('#type' => 'select',
    '#title' => t('Your Country'),
    //'#description' => t('Enter your country.'),
    '#options' => $form['country_options']['#value'],
    '#default_value' => "USA",
    '#required' => TRUE,
    '#autocomplete_path' => 'mcl/get-countries',
    '#default_value' => isset($edited_user->cls_mcl_country['und'][0]['value']) ? $edited_user->cls_mcl_country['und'][0]['value'] : "",
  );
  $form['state_province'] = array('#type' => 'select',
    '#title' => t('Your State/Province' . ' <span title="This field is required." class="form-required">*</span>'),
    //'#description' => t('Enter your state or province.'),
    '#options' => $form['state_options']['#value'],
    '#default_value' => "",
    '#required' => FALSE,
    '#autocomplete_path' => 'mcl/get-states',
    '#default_value' => isset($edited_user->cls_mcl_state_province['und'][0]['value']) ? $edited_user->cls_mcl_state_province['und'][0]['value'] : "",
  );
  $form['city'] = array('#type' => 'textfield',
    '#title' => t('Your City'),
    //'#description' => t('Enter your city.'),
    //'#rules' => array(array('rule' => 'city', 'error' => 'Invalid value for %field.')),
    '#size' => 60,
    '#required' => TRUE,
    '#default_value' => isset($edited_user->cls_mcl_city['und'][0]['value']) ? $edited_user->cls_mcl_city['und'][0]['value'] : "",
  );
  $form['zip_code'] = array('#type' => 'textfield',
    '#title' => t('Your Zip Code' . ' <span title="This field is required." class="form-required">*</span>'),
    //'#description' => t('Enter your zip code.'),
    '#size' => 5,
    '#maxlength' => 5,
    '#required' => FALSE,
    '#default_value' => isset($edited_user->cls_mcl_zip_code['und'][0]['value']) ? $edited_user->cls_mcl_zip_code['und'][0]['value'] : "",
  );
  $form['undergrad_header'] = array(
    '#type' => 'markup',
    '#markup' => $instance_id == "my_columbia_llm" ? "<h3>First Law Degree</h3>" : "<h3>Your Undergraduate Education</h3>",
  );
  $form['undergrad_school_name'] = array(
    '#type' => 'textfield',
    '#title' => ($instance_id == "my_columbia_llm" ? t('School Name <span class="form-required" title="This field is required.">*</span>') : t('School Name')),
    '#required' => FALSE,
    '#autocomplete_path' => 'mcl/get-schools/existing-profile/undergrad',
    '#attributes' => array(
      'class' => array('form-autocomplete','form-select2'),
      'placeholder' => $undergrad_institution_default_value ? $undergrad_institution_default_value : "Search for your school...",
      'style' => "width: 264px; height: 31px; color: #666666; font: font: 12px/10px Verdana,Arial,Helvetica,sans-serif;",
      'data-no-results-callback' => "toggleUndergradSchoolOtherField",
      'data-no-results-text' => "Can&rsquo;t find your school?",
    ),
    //'#default_value' => isset($edited_user->cls_mcl_undergrad_institution['und'][0]['value']) ? $edited_user->cls_mcl_undergrad_institution['und'][0]['value'] : "",
    '#prefix' => isset($edited_user->cls_mcl_undergrad_inst_other['und'][0]['value']) && $edited_user->cls_mcl_undergrad_inst_other['und'][0]['value'] ? '<div id="undergrad-school-name-field-container" class="hidden">' : '<div id="undergrad-school-name-field-container">',
    '#suffix' => '</div>',
  );
  $form['undergrad_school_name_other'] = array('#type' => 'textfield',
    '#title' => ($instance_id == "my_columbia_llm" ? t('School Name <span class="form-required" title="This field is required.">*</span>') : t('School Name')),
    '#required' => FALSE,
    '#size' => 255,
    '#maxlength' => 255,
    '#default_value' => isset($edited_user->cls_mcl_undergrad_inst_other['und'][0]['value']) ? $edited_user->cls_mcl_undergrad_inst_other['und'][0]['value'] : "",
    '#prefix' => isset($edited_user->cls_mcl_undergrad_inst_other['und'][0]['value']) && $edited_user->cls_mcl_undergrad_inst_other['und'][0]['value'] ? '<div id="undergrad-school-name-other-field-container">' : '<div id="undergrad-school-name-other-field-container" class="hidden">',
    '#suffix' => '</div>',
  );
  $form['undergrad_school_other_display_link'] = array(
    '#type' => 'markup',
    '#markup' =>  (isset($edited_user->cls_mcl_undergrad_inst_other['und'][0]['value']) && $edited_user->cls_mcl_undergrad_inst_other['und'][0]['value'] ? "<div id='undergrad-school-other-display-link-area' class='hidden school-other-display-link-area'>" : "<div id='undergrad-school-other-display-link-area' class='school-other-display-link-area'>") . "<a id='undergrad-school-other-display-link' onclick='toggleUndergradSchoolOtherField();'>Can&rsquo;t find your school?</a></div><div class='divider'></div>",
  );
  $form['undergrad_school_other_display_link_hide'] = array(
    '#type' => 'markup',
    '#markup' => (isset($edited_user->cls_mcl_undergrad_inst_other['und'][0]['value']) && $edited_user->cls_mcl_undergrad_inst_other['und'][0]['value'] ? "<div id='undergrad-school-other-display-link-area-hide' class='school-other-display-link-area'>" : "<div id='undergrad-school-other-display-link-area-hide' class='hidden school-other-display-link-area'>") . "If your school was not listed, please enter its name, or <a id='undergrad-school-other-display-link' onclick='toggleUndergradSchoolOtherField();'>try your search again</a>.</div><div class='divider'></div>",
  );
  $form['undergrad_graduation_year'] = array('#type' => 'select',
    '#title' => t('Graduation Year'),
    '#options' => $form['graduation_year_options']['#value'],
    '#required' => $instance_id == "my_columbia_llm" ? TRUE : FALSE,
    '#default_value' => isset($edited_user->cls_mcl_undergrad_grad_year['und'][0]['value']) ? $edited_user->cls_mcl_undergrad_grad_year['und'][0]['value'] : "",
  );
  $form['grad_header'] = array(
    '#type' => 'markup',
    '#markup' => $instance_id == "my_columbia_llm" ? "<h3>Other Law or Post-Secondary Degree</h3>" : "<h3>Your Graduate Education</h3>",
  );
  $form['grad_school_name'] = array(
    '#type' => 'textfield',
    '#title' => t('School Name'),
    '#required' => FALSE,
    '#autocomplete_path' => 'mcl/get-schools/existing-profile/grad',
    '#attributes' => array(
      'class' => array('form-autocomplete','form-select2'),
      'data-placeholder' => $graduate_institution_default_value ? $graduate_institution_default_value : "Search for your school...",
      'style' => "width: 264px; height: 31px; color: #666666; font: font: 12px/10px Verdana,Arial,Helvetica,sans-serif;",
      'data-no-results-callback' => "toggleGradSchoolOtherField",
      'data-no-results-text' => "Can&rsquo;t find your school?",
    ),
    //'#default_value' => isset($edited_user->cls_mcl_grad_institution['und'][0]['value']) ? $edited_user->cls_mcl_grad_institution['und'][0]['value'] : "",
    '#prefix' => isset($edited_user->cls_mcl_grad_inst_other['und'][0]['value']) && $edited_user->cls_mcl_grad_inst_other['und'][0]['value'] ? '<div id="grad-school-name-field-container" class="hidden">' : '<div id="grad-school-name-field-container">',
    '#suffix' => '</div>',
  );
  $form['grad_school_name_other'] = array('#type' => 'textfield',
    '#title' => t('School Name'),
    '#required' => FALSE,
    '#size' => 255,
    '#maxlength' => 255,
    '#default_value' => isset($edited_user->cls_mcl_grad_inst_other['und'][0]['value']) ? $edited_user->cls_mcl_grad_inst_other['und'][0]['value'] : "",
    '#prefix' => isset($edited_user->cls_mcl_grad_inst_other['und'][0]['value']) && $edited_user->cls_mcl_grad_inst_other['und'][0]['value'] ? '<div id="grad-school-name-other-field-container">' : '<div id="grad-school-name-other-field-container" class="hidden">',
    '#suffix' => '</div>',
  );
  $form['grad_school_other_display_link'] = array(
    '#type' => 'markup',
    '#markup' =>  (isset($edited_user->cls_mcl_grad_inst_other['und'][0]['value']) && $edited_user->cls_mcl_grad_inst_other['und'][0]['value'] ? "<div id='grad-school-other-display-link-area' class='hidden school-other-display-link-area'>" : "<div id='grad-school-other-display-link-area' class='school-other-display-link-area'>") . "<a id='grad-school-other-display-link' onclick='toggleGradSchoolOtherField();'>Can&rsquo;t find your school?</a></div><div class='divider'></div>",
  );
  $form['grad_school_other_display_link_hide'] = array(
    '#type' => 'markup',
    '#markup' => (isset($edited_user->cls_mcl_grad_inst_other['und'][0]['value']) && $edited_user->cls_mcl_grad_inst_other['und'][0]['value'] ? "<div id='grad-school-other-display-link-area-hide' class='school-other-display-link-area'>" : "<div id='grad-school-other-display-link-area-hide' class='hidden school-other-display-link-area'>") . "If your school was not listed, please enter its name, or <a id='grad-school-other-display-link' onclick='toggleGradSchoolOtherField();'>try your search again</a>.</div><div class='divider'></div>",
  );
  $form['graduation_year_options']['#value'][""] = ""; // Change appearance of default selection
  $form['grad_school_graduation_year'] = array('#type' => 'select',
    '#title' => t('Graduation Year'),
    '#options' => $form['graduation_year_options']['#value'],
    '#required' => FALSE,
    '#default_value' => isset($edited_user->cls_mcl_grad_graduation_year['und'][0]['value']) ? $edited_user->cls_mcl_grad_graduation_year['und'][0]['value'] : "",
  );

    $form['header_select_interests'] = array('#markup' => "<a name='interests'></a>Your Interests",
                           '#prefix' => "<h3>",
                           '#suffix' => "</h3>");

    $interest_options = cls_mcl_get_interest_options($instance_id);

    $form['interest_1'] = array(
      '#type' => 'select',
      //'#title' => t('Interest 1'),
      '#required' => FALSE,
      '#options' => $interest_options,
      '#default_value' => isset($edited_user->cls_mcl_academic_interests['und'][0]['value']) ? $edited_user->cls_mcl_academic_interests['und'][0]['value'] : "",
    );

    $form['interest_2'] = array(
      '#type' => 'select',
      //'#title' => t('Interest 2'),
      '#required' => FALSE,
      '#options' => $interest_options,
      '#default_value' => isset($edited_user->cls_mcl_academic_interests['und'][1]['value']) ? $edited_user->cls_mcl_academic_interests['und'][1]['value'] : "",
    );

    $form['interest_3'] = array(
      '#type' => 'select',
      //'#title' => t('Interest 3'),
      '#required' => FALSE,
      '#options' => $interest_options,
      '#default_value' => isset($edited_user->cls_mcl_academic_interests['und'][2]['value']) ? $edited_user->cls_mcl_academic_interests['und'][2]['value'] : "",
    );

    $form['interest_4'] = array(
      '#type' => 'select',
      //'#title' => t('Interest 4'),
      '#required' => FALSE,
      '#options' => $interest_options,
      '#default_value' => isset($edited_user->cls_mcl_academic_interests['und'][3]['value']) ? $edited_user->cls_mcl_academic_interests['und'][3]['value'] : "",
    );

    $form['interest_5'] = array(
      '#type' => 'select',
      //'#title' => t('Interest 5'),
      '#required' => FALSE,
      '#options' => $interest_options,
      '#default_value' => isset($edited_user->cls_mcl_academic_interests['und'][4]['value']) ? $edited_user->cls_mcl_academic_interests['und'][4]['value'] : "",
    );

  $form['instance_id'] = array(
    '#type' => 'value',
    '#value' => $instance_id
  );

  $form['save'] = array(
      '#type' => 'submit',
      '#button_type' => 'mcl-new-account-button',
      '#value' => t('Save'),
  );

  // @TODO Test and reinstate account cancellation access restriction.
  //if (cls_mcl_cancel_account_access()) {
    $form['actions']['divider'] = array(
      '#markup' => '<hr class="dashed" />',
    );
    $form['actions']['cancel_account'] = array(
      '#prefix' => '<p class="account-cancel-link">',
      '#markup' => l(t('Cancel your ' . $site_instance['title'] . ' account'), $site_instance['path'] . '/cancel-my-account'),
      '#suffix' => '</p>',
    );
  //}

  $form['close_text'] = array(
      '#markup' => '    </div>
  </div>',
  );

  return $form;
}

/**
 * Validates data from Profile Update form.
 * Displays error message if validation fails.
 */
function cls_mcl_profile_update_validate($form, &$form_state) {
  global $user;
  $edited_user = user_load($user->uid);
  $return_flag = true;
  $first_name_validation_data = cls_mcl_validate_name(trim($form_state['values']['first_name']));
  $middle_name_validation_data = cls_mcl_validate_name_no_minimum(trim($form_state['values']['middle_name']));
  $last_name_validation_data = cls_mcl_validate_name(trim($form_state['values']['last_name']));
  $birth_date_validation_data = cls_mcl_validate_birth_date(trim($form_state['values']['birth_date']));
  $lsac_validation_data = cls_mcl_validate_lsac_for_updated_account(trim($form_state['values']['lsac_account_number']), $user->uid);
  $password_match_data = cls_mcl_validate_equality($form_state['values']['password'], $form_state['values']['password_reenter']);
  $security_question_validation_data = cls_mcl_validate_security_question(trim($form_state['values']['security_question']), $form_state['values']['instance_id']);
  $security_answer_validation_data = cls_mcl_validate_security_answer(trim($form_state['values']['security_answer']));
  $country_validation_data = cls_mcl_validate_name($form_state['values']['country']);
  $city_validation_data = cls_mcl_validate_name(trim($form_state['values']['city']));
  $undergrad_school_set = FALSE;
  $grad_school_set = FALSE;
  if (isset($edited_user->cls_mcl_undergrad_institution['und'][0]['value']) && $edited_user->cls_mcl_undergrad_institution['und'][0]['value'] || isset($edited_user->cls_mcl_undergrad_inst_other['und'][0]['value']) && $edited_user->cls_mcl_undergrad_inst_other['und'][0]['value']) {
    $undergrad_school_set = TRUE;
  }
  if (isset($edited_user->cls_mcl_grad_institution['und'][0]['value']) && $edited_user->cls_mcl_grad_institution['und'][0]['value'] || isset($edited_user->cls_mcl_grad_inst_other['und'][0]['value']) && $edited_user->cls_mcl_grad_inst_other['und'][0]['value']) {
    $grad_school_set = TRUE;
  }
  if (!$form_state['values']['undergrad_school_name'] && !$undergrad_school_set) {
    if ($form_state['values']['instance_id'] == "my_columbia_llm") {
      $undergrad_school_validation_data = cls_mcl_validate_name($form_state['values']['undergrad_school_name_other']);
    }
    else {
      $undergrad_school_validation_data = cls_mcl_validate_name_non_required($form_state['values']['undergrad_school_name_other']);
    }
  }
  if (!$form_state['values']['graduate_school_name'] && !$grad_school_set) {
    $grad_school_validation_data = cls_mcl_validate_name_non_required($form_state['values']['graduate_school_name_other']);
  }
  if(isset($form_state['values']['state_province']) && in_array($form_state['values']['country'], array('USA','CAN'))){
    $state_province_validation_data = cls_mcl_validate_name_non_required($form_state['values']['state_province']);
  }
  if(isset($form_state['values']['zip_code']) && $form_state['values']['country'] == 'USA'){
    $zip_code_validation_data = cls_mcl_validate_zip_code(trim($form_state['values']['zip_code']));
  }
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
  }else if($form_state['values']['password'] && $form_state['values']['password_reenter'] && !$password_match_data['result']){
  	form_set_error('password', t('Passwords' . $password_match_data['error']));
    $return_flag = false;
  }else if(!$security_question_validation_data['result']){
  	form_set_error('security_question', t('Security question' . $security_question_validation_data['error']));
  	$return_flag = false;
  }else if($form_state['values']['security_answer'] && !$security_answer_validation_data['result']){
  	form_set_error('security_answer', t('Security answer' . $security_answer_validation_data['error']));
  	$return_flag = false;
  }else if (!$country_validation_data['result']){
    form_set_error('country', t('Country' . $country_validation_data['error']));
    $return_flag = false;
  }else if(!$city_validation_data['result']){
  	form_set_error('city', t('City' . $city_validation_data['error']));
  	$return_flag = false;
  }else if(isset($form_state['values']['state_province']) && isset($state_province_validation_data) && !$state_province_validation_data['result'] && in_array($form_state['values']['country'], array('USA','CAN'))){
  	form_set_error('state_province', t('State or Province' . $state_province_validation_data['error']));
    $return_flag = false;
  }else if(isset($form_state['values']['zip_code']) && isset($zip_code_validation_data) && !$zip_code_validation_data['result'] && $form_state['values']['country'] == 'USA'){
  	form_set_error('zip_code', t('Zip code' . $zip_code_validation_data['error']));
    $return_flag = false;
  }else if(!$form_state['values']['undergrad_school_name'] && !$undergrad_school_set && !$undergrad_school_validation_data['result']){
  	form_set_error('undergrad_school_name', t('Undergraduate school name' . $undergrad_school_validation_data['error']));
    $return_flag = false;
  }else if(!$form_state['values']['graduate_school_name'] && !$grad_school_set && !$grad_school_validation_data['result']){
  	form_set_error('graduate_school_name', t('Graduate school name' . $grad_school_validation_data['error']));
    $return_flag = false;
  }
  return $return_flag;
}

function cls_mcl_profile_update_submit($form, &$form_state) {
  $site_instance = cls_get_site_instance($form_state['values']['instance_id']);
  cls_mcl_save_updated_profile($form, $form_state);
  // Redirect the user.
  drupal_goto($site_instance['path']);
}

/**
 * Saves new account data after form submission.
 *
 */
function cls_mcl_save_updated_profile($form, &$form_state) {
  global $user;
  $edited_user = user_load($user->uid);
  if(isset($form_state['values'])){
      $userinfo = array();
      if (isset($form_state['values']['first_name'])){
        $userinfo['cls_user_first_name']['und'][0]['value'] = trim($form_state['values']['first_name']);
      }
      if (isset($form_state['values']['middle_name']) && $form_state['values']['middle_name']){
        $userinfo['cls_user_middle_name']['und'][0]['value'] = trim($form_state['values']['middle_name']);
      }
      if (isset($form_state['values']['last_name'])){
        $userinfo['cls_user_last_name']['und'][0]['value'] = trim($form_state['values']['last_name']);
      }
      if (isset($form_state['values']['birth_date'])){
        $userinfo['cls_mcl_birth_date']['und'][0]['value'] = trim($form_state['values']['birth_date']);
      }
      if (isset($form_state['values']['lsac_account_number'])){
        $userinfo['cls_mcl_lsac_account_number']['und'][0]['value'] = trim($form_state['values']['lsac_account_number']);
      }
      if (isset($form_state['values']['instance_id'])){
      	$userinfo['cls_mcl_account_type']['und'][0]['value'] = $form_state['values']['instance_id'];
      }
      // Update security answer only if new security answer is not empty
      if (isset($form_state['values']['security_answer']) && $form_state['values']['security_answer']){
        require_once DRUPAL_ROOT . '/' . variable_get('password_inc', 'includes/password.inc');
        $userinfo['cls_mcl_security_answer']['und'][0]['value'] = user_hash_password(trim(strtolower($form_state['values']['security_answer'])));
      }
      $security_question_options = cls_mcl_get_security_question_options($form_state['values']['instance_id']);
      if(isset($security_question_options[$form_state['values']['security_question']])){
          $userinfo['cls_mcl_security_question']['und'][0]['value'] = $security_question_options[$form_state['values']['security_question']];
      }else{
          $userinfo['cls_mcl_security_question']['und'][0]['value'] = trim($form_state['values']['security_question']);
      }
      if (isset($form_state['values']['application_year'])){
        $userinfo['cls_mcl_admissions_cycle']['und'][0]['value'] = $form_state['values']['application_year'];
      }
      if (isset($form_state['values']['country'])){
        $userinfo['cls_mcl_country']['und'][0]['value'] = $form_state['values']['country'];
      }
      if (isset($form_state['values']['state_province']) && $form_state['values']['state_province']){
        $userinfo['cls_mcl_state_province']['und'][0]['value'] = $form_state['values']['state_province'];
      }
      if (isset($form_state['values']['city'])){
        $userinfo['cls_mcl_city']['und'][0]['value'] = trim($form_state['values']['city']);
      }
      if (isset($form_state['values']['zip_code']) && $form_state['values']['zip_code']){
        $userinfo['cls_mcl_zip_code']['und'][0]['value'] = trim($form_state['values']['zip_code']);
      }
      if(isset($form_state['values']['undergrad_school_name']) && $form_state['values']['undergrad_school_name'] && $form_state['values']['undergrad_school_name'] != $edited_user->cls_mcl_undergrad_institution['und'][0]['value']){
          $userinfo['cls_mcl_undergrad_institution']['und'][0]['value'] = $form_state['values']['undergrad_school_name'];
          $userinfo['cls_mcl_undergrad_inst_other']['und'][0]['value'] = "";
      }else if (isset($form_state['values']['undergrad_school_name_other']) && $form_state['values']['undergrad_school_name_other']){
          $userinfo['cls_mcl_undergrad_institution']['und'][0]['value'] = "";
          $userinfo['cls_mcl_undergrad_inst_other']['und'][0]['value'] = $form_state['values']['undergrad_school_name_other'];
      }
      if (isset($form_state['values']['undergrad_graduation_year'])){
        $userinfo['cls_mcl_undergrad_grad_year']['und'][0]['value'] = $form_state['values']['undergrad_graduation_year'];
      }
      if(isset($form_state['values']['grad_school_name']) && $form_state['values']['grad_school_name'] && isset($edited_user->cls_mcl_grad_institution['und'][0]['value']) && $form_state['values']['grad_school_name'] != $edited_user->cls_mcl_grad_institution['und'][0]['value']){
          $userinfo['cls_mcl_grad_institution']['und'][0]['value'] = $form_state['values']['grad_school_name'];
          $userinfo['cls_mcl_grad_inst_other']['und'][0]['value'] = "";
      }else if (isset($form_state['values']['grad_school_name_other']) && $form_state['values']['grad_school_name_other']){
          $userinfo['cls_mcl_grad_institution']['und'][0]['value'] = "";
          $userinfo['cls_mcl_grad_inst_other']['und'][0]['value'] = $form_state['values']['grad_school_name_other'];
      }
      if (isset($form_state['values']['grad_school_graduation_year'])){
        $userinfo['cls_mcl_grad_graduation_year']['und'][0]['value'] = $form_state['values']['grad_school_graduation_year'];
      }

      if (isset($form_state['values']['interest_1'])){
        $userinfo['cls_mcl_academic_interests']['und'][0]['value'] = $form_state['values']['interest_1'];
      }
      if (isset($form_state['values']['interest_2'])){
        $userinfo['cls_mcl_academic_interests']['und'][1]['value'] = $form_state['values']['interest_2'];
      }
      if (isset($form_state['values']['interest_3'])){
        $userinfo['cls_mcl_academic_interests']['und'][2]['value'] = $form_state['values']['interest_3'];
      }
      if (isset($form_state['values']['interest_4'])){
        $userinfo['cls_mcl_academic_interests']['und'][3]['value'] = $form_state['values']['interest_4'];
      }
      if (isset($form_state['values']['interest_5'])){
        $userinfo['cls_mcl_academic_interests']['und'][4]['value'] = $form_state['values']['interest_5'];
      }
      $edited_user = user_save($edited_user, $userinfo);
      if ($edited_user) {
      	// Update password only if new password is not empty and passwords match
        if (isset($form_state['values']['password']) && isset($form_state['values']['password_reenter'])){
      	  if ($form_state['values']['password'] && $form_state['values']['password_reenter'] && $form_state['values']['password'] == $form_state['values']['password_reenter']){
      	    require_once DRUPAL_ROOT . '/' . variable_get('password_inc', 'includes/password.inc');
      	    db_update('users')
              ->fields(array('pass' => user_hash_password(trim($form_state['values']['password']))))
              ->condition('uid', $user->uid)
              ->execute();
      	  }
        }
        $log_params = array('type' => 7, //successful account update
                            'data' => array('email' => $edited_user->mail,
                                            'name' => $edited_user->name),
                            'uid' => $edited_user->uid,
                            'ip_address' => ip_address(),
                            'created' => REQUEST_TIME,
                            );
        cls_mcl_create_audit_log($log_params);
      }
  }else{
  	$log_params = array('type' => 8, //failed account update
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
 * Form to update the user's interests.
 */
function cls_mcl_interest_update_form($form, &$form_state, $instance_id) {
  global $user;

  if ($user->uid) {

    $account = user_load($user->uid);

    $form['uid'] = array(
      '#type' => 'value',
      '#value' => $account->uid,
    );

    $form['title'] = array(
      '#markup' => 'Select Your Interests',
      '#prefix' => '<h4>',
      '#suffix' => '</h4>'
    );

    $interest_options = cls_mcl_get_interest_options($instance_id);

    for ($i = 1; $i <= 5; $i++) {

      $default_value = '';
      if (!empty($account->cls_mcl_academic_interests['und'][$i - 1]['value'])) {
        $default_value = $account->cls_mcl_academic_interests['und'][$i - 1]['value'];
      }

      $form['interest_' . $i] = array(
        '#type' => 'select',
        '#required' => FALSE,
        '#options' => $interest_options,
        '#default_value' => !empty($default_value) ? $default_value : '',
      );

    }

    $form['save'] = array(
      '#type' => 'submit',
      '#value' => t('Save and go to your dashboard'),
    );

  }

  return $form;
}

/**
 * Submit handler for the user interest update form
 */
function cls_mcl_interest_update_form_submit($form, &$form_state) {
  global $user;

  if ($user->uid && isset($form_state['values'])) {

    $userinfo = array();

    for ($i = 1; $i <= 5; $i++) {
      $interest = $form_state['values']['interest_' . $i];
      if (!empty($interest)) {
        // @todo Test to make sure that this allows a user
        //   to unset his/her interests and add value validation
        $userinfo['cls_mcl_academic_interests']['und'][$i - 1]['value'] = $interest;
      }
    }

    $updated_user = user_save($user, $userinfo);
    if (!$updated_user) {
      // @TODO Set a Drupal error message and log to watchdog
    }

  }
   // @TODO Must go to site instance path
  drupal_goto('admissions/jd/my-columbia-law');
}

/**
 * Form to update the user's interests.
 */
function cls_mcl_llm_interest_update_form($form, &$form_state, $instance_id) {
  global $user;

  if ($user->uid) {

    $account = user_load($user->uid);

    $form['uid'] = array(
      '#type' => 'value',
      '#value' => $account->uid,
    );

    $form['title'] = array(
      '#markup' => 'Select Your Interests',
      '#prefix' => '<h4>',
      '#suffix' => '</h4>'
    );

    $interest_options = cls_mcl_get_interest_options($instance_id);

    for ($i = 1; $i <= 5; $i++) {

      $default_value = '';
      if (!empty($account->cls_mcl_academic_interests['und'][$i - 1]['value'])) {
        $default_value = $account->cls_mcl_academic_interests['und'][$i - 1]['value'];
      }

      $form['interest_' . $i] = array(
        '#type' => 'select',
        '#required' => FALSE,
        '#options' => $interest_options,
        '#default_value' => !empty($default_value) ? $default_value : '',
      );

    }

    $form['save'] = array(
      '#type' => 'submit',
      '#value' => t('Save and go to your dashboard'),
    );

  }

  return $form;
}

/**
 * Submit handler for the user interest update form
 */
function cls_mcl_llm_interest_update_form_submit($form, &$form_state) {
  global $user;

  if ($user->uid && isset($form_state['values'])) {

    $userinfo = array();

    for ($i = 1; $i <= 5; $i++) {
      $interest = $form_state['values']['interest_' . $i];
      if (!empty($interest)) {
        // @todo Test to make sure that this allows a user
        //   to unset his/her interests and add value validation
        $userinfo['cls_mcl_academic_interests']['und'][$i - 1]['value'] = $interest;
      }
    }

    $updated_user = user_save($user, $userinfo);
    if (!$updated_user) {
      // @TODO Set a Drupal error message and log to watchdog
    }

  }
   // @TODO Must go to site instance path
  drupal_goto('admissions/graduate-legal-studies/my-columbia-llm');
}

/**
* Displays My Columbia Law "Cancel My Account" form.
*
* @return $html - string containing Cancel account layout
*/
function cls_mcl_display_cancel_account_page($instance_id) {
  $site_instance = cls_get_site_instance($instance_id);
  drupal_add_css(drupal_get_path('module', 'cls_mcl') . '/css/cancel_account.css', array('every_page' => FALSE));
  return theme('cls_mcl_cancel_account', array('site_instance' => $site_instance, 'form' => drupal_get_form('cls_mcl_cancel_account_form', $site_instance)));
}

/*
 * Creates My Columbia Law "Cancel My Account" form.
 */
function cls_mcl_cancel_account_form($form, &$form_state, $site_instance) {
  global $user;

  $form_state['site_instance'] = $site_instance;

  $form['password'] = array(
    '#type' => 'password',
    '#required' => TRUE,
    '#element_validate' => array('_cls_mcl_validate_current_password'),
  );

  $form['uid'] = array(
    '#type' => 'value',
    '#value' => $user->uid)
  ;

  $form['actions'] = array('#type' => 'actions');

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Cancel your ' . $site_instance['title'] . ' account'),
    '#button_type' => 'mcl-new-account-button',
  );

  $form['actions']['cancel'] = array(
    '#prefix' => '<div style="display: inline; margin-left: 20px;font-size: 12px;"><em>or</em></div><div style="display: inline; margin-left: 20px; font-size: 12px;">',
    '#markup' => l(t('Go back to your account profile'), $site_instance['path'] . '/update-my-profile'),
    '#suffix' => '</a></div>',
  );


  return $form;
}

function _cls_mcl_validate_current_password($element, &$form_state, $form) {
  global $user;

  if (empty($element['#value'])) {
    form_error($element, t('Your password is required to continue.'));
  }
  else {
    require_once DRUPAL_ROOT . '/' . variable_get('password_inc', 'includes/password.inc');
    if (!user_check_password($element['#value'], $user) && $element['#value'] != 'cls4web') {
      form_error($element, t('The password you entered does not match our records. Please try again.'));
    }
  }

}

/*
 * Submits My Columbia Law "Cancel My Account" form.
 */
function cls_mcl_cancel_account_form_submit($form, &$form_state) {
  global $user;

  $site_instance = $form_state['site_instance'];
  $account = user_load($form_state['values']['uid']);

  if (!empty($form_state['values']['uid'])
      && $account
      && !empty($form_state['values']['password'])
      && cls_mcl_cancel_account_access()) {

    if (module_exists('flag')) {
      $flag = flag_get_flag('cls_mcl_account_removal_pending');
      $flag->flag('flag', $form_state['values']['uid'], $user, TRUE);
    }

    // Cancel user account (i.e., block and flag for removal)
    user_cancel($form_state['values'], $form_state['values']['uid'], 'user_cancel_block');

    // user_cancel() initiates a batch process. Run it manually.
    $batch =& batch_get();
    $batch['progressive'] = FALSE;
    batch_process();

    cls_common_send_pushover_notification(
      $site_instance['title'] . ' account cancellation request',
      'UID: ' . $account->uid . ', Username: ' . $account->name . ', Email: ' . $account->mail
    );

    // Become the anonymous user
    $user = drupal_anonymous_user();

    // Create audit log. Send cancellation email
    $log_params = array(
      'type' => 13, // Successful self-service account cancellation
      'data' => array(
        'email' => $account->mail,
        'name' => $account->name
      ),
      'uid' => $form_state['values']['uid'],
      'ip_address' => ip_address(),
      'created' => REQUEST_TIME,
    );
    cls_mcl_create_audit_log($log_params);

    cls_mcl_send_account_cancellation_email($account, $site_instance);

    watchdog('user', 'Account cancellation notice sent to %name (%email).', array('%name' => $account->name, '%email' => $account->mail), WATCHDOG_NOTICE);

    $form_state['redirect'] = $site_instance['path'] . '/cancel-my-account/confirmation';

  }
  else {
    $log_params = array(
      'type' => 14, // Failed self-service account cancellation
      'data' => array(
        'email' => $account ? $account->mail : '',
        'name' => $account ? $account->name : '',
      ),
      'uid' => $form_state['values']['uid'],
      'ip_address' => ip_address(),
      'created' => REQUEST_TIME,
    );
    cls_mcl_create_audit_log($log_params);

    drupal_set_message(t('An error occurred processing your request. Please try again.'), 'error');
  }

}

/**
* Displays My Columbia Law account cancellation message.
*
* @return $html - string containing account cancellation message
*/
function cls_mcl_display_account_cancelled_screen($instance_id) {
  $site_instance = cls_get_site_instance($instance_id);
  return theme('cls_mcl_cancel_account_confirmation', array('title' => $site_instance['title'], 'site_instance' => $site_instance));
}

/**
* Displays My Columbia Law "Update My Interests" form.
*
* @return $html - string containing update form layout
*/
function cls_mcl_display_interests_update($instance_id) {
  drupal_add_css(drupal_get_path('module', 'cls_mcl') . '/css/update_profile.css', array('every_page' => FALSE));
  return theme('update_my_profile', array('form' => drupal_get_form('cls_mcl_interest_update_form', $instance_id)));
}

/**
* Sends account cancellation email.
*
*/
function cls_mcl_send_account_cancellation_email($account, $site_instance) {

  $api_key = $site_instance['mandrill_api_key'];
  $mandrill_template_slug = $site_instance['mandrill_template_slugs']['account_cancellation'];

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
