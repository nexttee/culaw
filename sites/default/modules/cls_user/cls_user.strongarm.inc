<?php
/**
 * @file
 * cls_user.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function cls_user_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_current_student_type_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_current_student_type_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_faculty_profile_element_types_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_faculty_profile_element_types_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_prospective_student_type_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_prospective_student_type_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_year_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_year_pattern'] = $strongarm;

  return $export;
}
