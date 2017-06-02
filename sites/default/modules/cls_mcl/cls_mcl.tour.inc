<?php

/**
 * @file
 * Functions related to new My Columbia Law guide/tour.
 */

function cls_mcl_display_tour_welcome() {
  drupal_add_css(drupal_get_path('module', 'cls_mcl') . '/css/tour.css', array('every_page' => FALSE));
  //return theme('new_account', array('form' => drupal_get_form('cls_mcl_new_account')));
  return theme('tour_welcome');
}

function cls_mcl_display_tour_first_year() {
  drupal_add_css(drupal_get_path('module', 'cls_mcl') . '/css/tour.css', array('every_page' => FALSE));
  drupal_add_css(drupal_get_path('module', 'cls_mcl') . '/js/toggle/toggle-style.css', array('every_page' => FALSE));
  drupal_add_js(drupal_get_path('module', 'cls_mcl') . '/js/toggle/javascript.js');
  return theme('tour_first_year', array('form' => drupal_get_form('cls_mcl_display_tour_first_year_form')));
}

function cls_mcl_display_tour_first_year_form() {
  global $user;

  // Display login form:
  $form['electives'] = array(
    '#type' => 'checkbox',
    '#title' => t('First-year Electives'),
    '#default_value' => TRUE,
  );
  $form['joint_degrees'] = array(
    '#type' => 'checkbox',
    '#title' => t('Joint Degrees'),
    '#default_value' => TRUE,
  );
  $form['moot_court'] = array(
    '#type' => 'checkbox',
    '#title' => t('Moot Court'),
    '#default_value' => TRUE,
  );
  $form['student_orgs'] = array(
    '#type' => 'checkbox',
    '#title' => t('Student Organizations'),
    '#default_value' => TRUE,
  );
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Continue with the tour'),
    '#button_type' => 'continue-with-the-tour',
  );

  return $form;
}

function cls_mcl_display_tour_first_year_form_submit($form, &$form_state) {
  
  $_SESSION['mcl_tour']['electives'] = $form_state['values']['electives'];
  $_SESSION['mcl_tour']['joint_degrees'] = $form_state['values']['joint_degrees'];
  $_SESSION['mcl_tour']['moot_court'] = $form_state['values']['moot_court'];
  $_SESSION['mcl_tour']['student_orgs'] = $form_state['values']['student_orgs'];
  
  if ($_SESSION['mcl_tour']['electives']===1) {
    drupal_goto('admissions/jd/my-columbia-law/experience/first-year/electives');
  }
  else if ($_SESSION['mcl_tour']['joint_degrees']===1) {
    drupal_goto('admissions/jd/my-columbia-law/experience/first-year/joint-degrees');
  }
  else if ($_SESSION['mcl_tour']['moot_court']===1) {
    drupal_goto('admissions/jd/my-columbia-law/experience/first-year/moot-court');
  }
  else if ($_SESSION['mcl_tour']['student_orgs']===1) {
    drupal_goto('admissions/jd/my-columbia-law/experience/first-year/student-orgs');
  }
  else {
    drupal_goto('admissions/jd/my-columbia-law/experience/second-third-years');
  }
  
}

function cls_mcl_display_tour_first_year_electives() {
  drupal_add_css(drupal_get_path('module', 'cls_mcl') . '/css/tour.css', array('every_page' => FALSE));
  return theme('tour_first_year_electives');
}

function cls_mcl_display_tour_first_year_joint_degrees() {
  drupal_add_css(drupal_get_path('module', 'cls_mcl') . '/css/tour.css', array('every_page' => FALSE));
  return theme('tour_first_year_joint_degrees');
}

function cls_mcl_display_tour_first_year_moot_court() {
  drupal_add_css(drupal_get_path('module', 'cls_mcl') . '/css/tour.css', array('every_page' => FALSE));
  return theme('tour_first_year_moot_court');
}

function cls_mcl_display_tour_first_year_student_orgs() {
  drupal_add_css(drupal_get_path('module', 'cls_mcl') . '/css/tour.css', array('every_page' => FALSE));
  return theme('tour_first_year_student_orgs');
}

function cls_mcl_display_tour_second_third_year() {
  drupal_add_css(drupal_get_path('module', 'cls_mcl') . '/css/tour.css', array('every_page' => FALSE));
  drupal_add_css(drupal_get_path('module', 'cls_mcl') . '/js/toggle/toggle-style.css', array('every_page' => FALSE));
  drupal_add_js(drupal_get_path('module', 'cls_mcl') . '/js/toggle/javascript.js');
  return theme('tour_second_third_year', array('form' => drupal_get_form('cls_mcl_display_tour_second_third_year_form')));
}

function cls_mcl_display_tour_second_third_year_form() {
  global $user;

  // Display login form:
  $form['centers'] = array(
    '#type' => 'checkbox',
    '#title' => t('Centers and Programs'),
    '#default_value' => TRUE,
  );
  $form['clinics'] = array(
    '#type' => 'checkbox',
    '#title' => t('Clinics and Externships'),
    '#default_value' => TRUE,
  );
  $form['journals'] = array(
    '#type' => 'checkbox',
    '#title' => t('Journals'),
    '#default_value' => TRUE,
  );
  $form['pro_bono'] = array(
    '#type' => 'checkbox',
    '#title' => t('Pro-Bono'),
    '#default_value' => TRUE,
  );
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Continue with the tour'),
    '#button_type' => 'continue-with-the-tour',
  );

  return $form;
}

function cls_mcl_display_tour_second_third_year_form_submit($form, &$form_state) {
  
  $_SESSION['mcl_tour']['centers'] = $form_state['values']['centers'];
  $_SESSION['mcl_tour']['clinics'] = $form_state['values']['clinics'];
  $_SESSION['mcl_tour']['journals'] = $form_state['values']['journals'];
  $_SESSION['mcl_tour']['pro_bono'] = $form_state['values']['pro_bono'];
  
  if ($_SESSION['mcl_tour']['centers']===1) {
    drupal_goto('admissions/jd/my-columbia-law/experience/second-third-years/centers-programs');
  }
  else if ($_SESSION['mcl_tour']['clinics']===1) {
    drupal_goto('admissions/jd/my-columbia-law/experience/second-third-years/clinics-externships');
  }
  else if ($_SESSION['mcl_tour']['journals']===1) {
    drupal_goto('admissions/jd/my-columbia-law/experience/second-third-years/journals');
  }
  else if ($_SESSION['mcl_tour']['pro_bono']===1) {
    drupal_goto('admissions/jd/my-columbia-law/experience/second-third-years/pro-bono');
  }
  else {
    drupal_goto('admissions/jd/my-columbia-law/experience/end');
  }
  
}

function cls_mcl_display_tour_second_third_year_centers() {
  drupal_add_css(drupal_get_path('module', 'cls_mcl') . '/css/tour.css', array('every_page' => FALSE));
  return theme('tour_second_third_year_centers');
}

function cls_mcl_display_tour_second_third_year_clinics() {
  drupal_add_css(drupal_get_path('module', 'cls_mcl') . '/css/tour.css', array('every_page' => FALSE));
  return theme('tour_second_third_year_clinics');
}

function cls_mcl_display_tour_second_third_year_journals() {
  drupal_add_css(drupal_get_path('module', 'cls_mcl') . '/css/tour.css', array('every_page' => FALSE));
  return theme('tour_second_third_year_journals');
}

function cls_mcl_display_tour_second_third_year_pro_bono() {
  drupal_add_css(drupal_get_path('module', 'cls_mcl') . '/css/tour.css', array('every_page' => FALSE));
  return theme('tour_second_third_year_pro_bono');
}

function cls_mcl_display_tour_end() {
  module_load_include('inc', 'cls_mcl', 'cls_mcl.profile_update');
  drupal_add_css(drupal_get_path('module', 'cls_mcl') . '/css/tour.css', array('every_page' => FALSE));
  return theme('tour_end', array('form' => drupal_get_form('cls_mcl_interest_update_form', 'my_columbia_law')));
}
