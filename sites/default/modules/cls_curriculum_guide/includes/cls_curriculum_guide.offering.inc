<?php

function cls_curriculum_guide_offering_page_callback($course_offering_number){
  _cls_curriculum_guide_add_assets();

  $client_id = variable_get('cls_client_id');
  $client_secret = variable_get('cls_client_secret');
  $client = cls_rest_api_make_api_request($client_id, $client_secret);
  $prepared_data = _cls_curriculum_guide_prepare_offering_page_data($client, $course_offering_number);

  return theme('cls_curriculum_guide_offering_page', array(
      'offering' => $prepared_data['offering'],
      'type' => $prepared_data['type'],
      'level' => $prepared_data['level'],
      'categories' => $prepared_data['categories'],
      'sections' => $prepared_data['sections'],
      'academic_years' => $prepared_data['academic_years'],
    )
  );
}

function _cls_curriculum_guide_prepare_offering_page_data($client, $course_offering_number){
  $offering = array();
  $prepared_data = array();
  $offering_numbers = array();
  $type = '';
  $level = '';
  $categories = array();
  $offering_numbers[] = $course_offering_number;
  $qp = array(
    'courseNumber' => $offering_numbers,
  );

  $offering = _cls_curriculum_guide_load_offering_by_course_number($client, $course_offering_number);

  if(isset($course_offering_number)) drupal_set_title(t($course_offering_number));

  $api_results = _cls_curriculum_guide_fetch_search_results($client, $qp);
  $sections = _cls_curriculum_guide_prepare_search_results_data($client, $api_results);

  $selected_years = array_filter(variable_get('cls_curriculum_guide_selected_years', array()));
  $academic_years = _cls_curriculum_guide_get_academic_year_data_by_ids($client, $selected_years);

  if(isset($sections[0])){
    $type = $sections[0]['type'];
    $level = $sections[0]['level'];
    $categories = $sections[0]['categories'];
  }

  $prepared_data = array(
    'offering' => $offering,
    'type' => $type,
    'level' => $level,
    'categories' => $categories,
    'sections' => $sections,
    'academic_years' => $academic_years,
  );

  return $prepared_data;
}

function cls_curriculum_guide_offering_ajax_sections_callback($course_offering_number, $academic_year_id){
  $client_id = variable_get('cls_client_id');
  $client_secret = variable_get('cls_client_secret');
  $client = cls_rest_api_make_api_request($client_id, $client_secret);

  $years = array();
  $offering_numbers = array();
  $offering_numbers[] = $course_offering_number;
  $years[] = $academic_year_id;
  $qp = array(
    'schoolYear' => $years,
    'courseNumber' => $offering_numbers,
  );

  $api_results = _cls_curriculum_guide_fetch_search_results($client, $qp);
  $sections = _cls_curriculum_guide_prepare_search_results_data($client, $api_results);

  print theme('cls_curriculum_guide_offering_ajax_sections', array('sections' => $sections));
}
