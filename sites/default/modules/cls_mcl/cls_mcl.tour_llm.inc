<?php

/**
 * @file
 * Functions related to new My Columbia Law guide/tour.
 */

function cls_mcl_tour_llm_welcome_page() {
  drupal_add_css(drupal_get_path('module', 'cls_mcl') . '/css/tour_llm.css', array('every_page' => FALSE));
  return theme('tour_llm_welcome');
}

function cls_mcl_tour_llm_curriculum_page() {
  drupal_add_css(drupal_get_path('module', 'cls_mcl') . '/css/tour_llm.css', array('every_page' => FALSE));
  drupal_add_css(drupal_get_path('module', 'cls_mcl') . '/js/toggle/toggle-style.css', array('every_page' => FALSE));
  drupal_add_js(drupal_get_path('module', 'cls_mcl') . '/js/toggle/javascript.js');
  return theme('tour_llm_curriculum', array('form' => drupal_get_form('cls_mcl_tour_llm_curriculum_page_form')));
}

function cls_mcl_tour_llm_curriculum_page_form() {
  $form['program_study'] = array(
    '#type' => 'checkbox',
    '#title' => t('Program of Study'),
    '#default_value' => TRUE,
  );
  $form['intro_courses'] = array(
    '#type' => 'checkbox',
    '#title' => t('Introductory Courses'),
    '#default_value' => TRUE,
  );
  $form['cross_reg'] = array(
    '#type' => 'checkbox',
    '#title' => t('Cross-Registration'),
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

function cls_mcl_tour_llm_curriculum_page_form_submit($form, &$form_state) {
  
  $_SESSION['mcl_tour']['program_study'] = $form_state['values']['program_study'];
  $_SESSION['mcl_tour']['intro_courses'] = $form_state['values']['intro_courses'];
  $_SESSION['mcl_tour']['cross_reg'] = $form_state['values']['cross_reg'];
  
  if ($_SESSION['mcl_tour']['program_study']===1) {
    drupal_goto('admissions/graduate-legal-studies/my-columbia-llm/tour/curriculum/program-of-study');
  }
  else if ($_SESSION['mcl_tour']['intro_courses']===1) {
    drupal_goto('admissions/graduate-legal-studies/my-columbia-llm/tour/curriculum/introductory-courses');
  }
  else if ($_SESSION['mcl_tour']['cross_reg']===1) {
    drupal_goto('admissions/graduate-legal-studies/my-columbia-llm/tour/curriculum/cross-registration');
  }
  else {
    drupal_goto('admissions/graduate-legal-studies/my-columbia-llm/tour/academic-experience');
  }
  
}

function cls_mcl_tour_llm_curriculum_intro_courses_page() {
  drupal_add_css(drupal_get_path('module', 'cls_mcl') . '/css/tour_llm.css', array('every_page' => FALSE));
  return theme('tour_llm_curriculum_intro_courses');
}

function cls_mcl_tour_llm_curriculum_courses_study_page() {
  drupal_add_css(drupal_get_path('module', 'cls_mcl') . '/css/tour_llm.css', array('every_page' => FALSE));
  return theme('tour_llm_curriculum_courses_study');
}

function cls_mcl_tour_llm_curriculum_cross_reg_page() {
  drupal_add_css(drupal_get_path('module', 'cls_mcl') . '/css/tour_llm.css', array('every_page' => FALSE));
  return theme('tour_llm_curriculum_cross_reg');
}

function cls_mcl_tour_llm_academic_experience_page() {
  drupal_add_css(drupal_get_path('module', 'cls_mcl') . '/css/tour_llm.css', array('every_page' => FALSE));
  drupal_add_css(drupal_get_path('module', 'cls_mcl') . '/js/toggle/toggle-style.css', array('every_page' => FALSE));
  drupal_add_js(drupal_get_path('module', 'cls_mcl') . '/js/toggle/javascript.js');
  return theme('tour_llm_academic_experience', array('form' => drupal_get_form('cls_mcl_tour_llm_academic_experience_page_form')));
}

function cls_mcl_tour_llm_academic_experience_page_form() {
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
    '#title' => t('Pro Bono'),
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

function cls_mcl_tour_llm_academic_experience_page_form_submit($form, &$form_state) {
  
  $_SESSION['mcl_tour']['centers'] = $form_state['values']['centers'];
  $_SESSION['mcl_tour']['clinics'] = $form_state['values']['clinics'];
  $_SESSION['mcl_tour']['journals'] = $form_state['values']['journals'];
  $_SESSION['mcl_tour']['pro_bono'] = $form_state['values']['pro_bono'];
  
  if ($_SESSION['mcl_tour']['centers']===1) {
    drupal_goto('admissions/graduate-legal-studies/my-columbia-llm/tour/academic-experience/centers-programs');
  }
  else if ($_SESSION['mcl_tour']['clinics']===1) {
    drupal_goto('admissions/graduate-legal-studies/my-columbia-llm/tour/academic-experience/clinics-externships');
  }
  else if ($_SESSION['mcl_tour']['journals']===1) {
    drupal_goto('admissions/graduate-legal-studies/my-columbia-llm/tour/academic-experience/journals');
  }
  else if ($_SESSION['mcl_tour']['pro_bono']===1) {
    drupal_goto('admissions/graduate-legal-studies/my-columbia-llm/tour/academic-experience/pro-bono');
  }
  else {
    drupal_goto('admissions/graduate-legal-studies/my-columbia-llm/tour/student-life');
  }
  
}

function cls_mcl_tour_llm_academic_experience_centers_page() {
  drupal_add_css(drupal_get_path('module', 'cls_mcl') . '/css/tour_llm.css', array('every_page' => FALSE));
  return theme('tour_llm_academic_experience_centers');
}

function cls_mcl_tour_llm_academic_experience_clinics_page() {
  drupal_add_css(drupal_get_path('module', 'cls_mcl') . '/css/tour_llm.css', array('every_page' => FALSE));
  return theme('tour_llm_academic_experience_clinics');
}

function cls_mcl_tour_llm_academic_experience_journals_page() {
  drupal_add_css(drupal_get_path('module', 'cls_mcl') . '/css/tour_llm.css', array('every_page' => FALSE));
  return theme('tour_llm_academic_experience_journals');
}

function cls_mcl_tour_llm_academic_experience_pro_bono_page() {
  drupal_add_css(drupal_get_path('module', 'cls_mcl') . '/css/tour_llm.css', array('every_page' => FALSE));
  return theme('tour_llm_academic_experience_pro_bono');
}

function cls_mcl_tour_llm_student_life_page() {
  drupal_add_css(drupal_get_path('module', 'cls_mcl') . '/css/tour_llm.css', array('every_page' => FALSE));
  drupal_add_css(drupal_get_path('module', 'cls_mcl') . '/js/toggle/toggle-style.css', array('every_page' => FALSE));
  drupal_add_js(drupal_get_path('module', 'cls_mcl') . '/js/toggle/javascript.js');
  return theme('tour_llm_student_life', array('form' => drupal_get_form('cls_mcl_tour_llm_student_life_page_form')));
}

function cls_mcl_tour_llm_student_life_page_form() {
  global $user;

  // Display login form:
  $form['orgs'] = array(
    '#type' => 'checkbox',
    '#title' => t('Student Organizations'),
    '#default_value' => TRUE,
  );
  $form['nyc'] = array(
    '#type' => 'checkbox',
    '#title' => t('New York City and Morningside Heights'),
    '#default_value' => TRUE,
  );
  $form['alumni'] = array(
    '#type' => 'checkbox',
    '#title' => t('Alumni Community'),
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

function cls_mcl_tour_llm_student_life_page_form_submit($form, &$form_state) {
  
  $_SESSION['mcl_tour']['orgs'] = $form_state['values']['orgs'];
  $_SESSION['mcl_tour']['nyc'] = $form_state['values']['nyc'];
  $_SESSION['mcl_tour']['alumni'] = $form_state['values']['alumni'];
  
  if ($_SESSION['mcl_tour']['orgs']===1) {
    drupal_goto('admissions/graduate-legal-studies/my-columbia-llm/tour/student-life/organizations');
  }
  else if ($_SESSION['mcl_tour']['nyc']===1) {
    drupal_goto('admissions/graduate-legal-studies/my-columbia-llm/tour/student-life/nyc');
  }
  else if ($_SESSION['mcl_tour']['alumni']===1) {
    drupal_goto('admissions/graduate-legal-studies/my-columbia-llm/tour/student-life/alumni');
  }
  else {
    drupal_goto('admissions/graduate-legal-studies/my-columbia-llm/tour/thanks');
  }
  
}

function cls_mcl_tour_llm_student_life_orgs_page() {
  drupal_add_css(drupal_get_path('module', 'cls_mcl') . '/css/tour_llm.css', array('every_page' => FALSE));
  return theme('tour_llm_student_life_orgs');
}

function cls_mcl_tour_llm_student_life_nyc_page() {
  drupal_add_css(drupal_get_path('module', 'cls_mcl') . '/css/tour_llm.css', array('every_page' => FALSE));
  return theme('tour_llm_student_life_nyc');
}

function cls_mcl_tour_llm_student_life_alumni_page() {
  drupal_add_css(drupal_get_path('module', 'cls_mcl') . '/css/tour_llm.css', array('every_page' => FALSE));
  return theme('tour_llm_student_life_alumni');
}

function cls_mcl_tour_llm_thanks_page() {
  module_load_include('inc', 'cls_mcl', 'cls_mcl.profile_update');
  drupal_add_css(drupal_get_path('module', 'cls_mcl') . '/css/tour_llm.css', array('every_page' => FALSE));
  return theme('tour_llm_thanks', array('form' => drupal_get_form('cls_mcl_llm_interest_update_form', 'my_columbia_llm')));
}
