<?php

function cls_curriculum_guide_instructor_page_callback($id){
  _cls_curriculum_guide_add_assets();

  $client_id = variable_get('cls_client_id');
  $client_secret = variable_get('cls_client_secret');
  $client = cls_rest_api_make_api_request($client_id, $client_secret);
  $api_data = _cls_curriculum_guide_fetch_sections_by_instructor($client, $id);
  $instructor_data = _cls_curriculum_guide_prepare_instructor_data($client, $id);
  $default_year = intval(variable_get('cls_curriculum_guide_default_year'));
  $section_data = _cls_curriculum_guide_prepare_instructor_section_data($api_data, $default_year);

  return theme('cls_curriculum_guide_instructor_page', array(
      'name' => $instructor_data['name'],
      'title' => $instructor_data['title'],
      'profile_url' => $instructor_data['profile_url'],
      'photo_url' => $instructor_data['photo_url'],
      'sections' => $section_data,
    )
  );
}

function _cls_curriculum_guide_prepare_instructor_section_data($data, $academic_year_id){
  $prepared_data = array();

  foreach($data as $section){
    if($section['academic_year_id'] == $academic_year_id){
      $object = array(
        'id' => $section['id'],
        'course_number' => $section['course_number'],
        'section' => 'Section' . ' ' . $section['section'],
        'semester' => $section['semester'],
        'name' => $section['name'],
        'instructors' => $section['instructors'],
        'description' => views_trim_text(array('max_length' => 200,'word_boundary' => TRUE,'ellipsis' => TRUE), strip_tags(str_replace('&', '&amp;', $section['description']))),
        'points' => intval($section['points']) . ' pts.',
      );
      $prepared_data[] = $object;
    }
  }

  if(count($prepared_data) > 0){
    $prepared_data = array_chunk($prepared_data, 4);
  }

  return $prepared_data;
}

function cls_curriculum_guide_instructor_ajax_sections_callback($instructor_id, $academic_year_id){
  $client_id = variable_get('cls_client_id');
  $client_secret = variable_get('cls_client_secret');
  $client = cls_rest_api_make_api_request($client_id, $client_secret);
  $data = _cls_curriculum_guide_fetch_sections_by_instructor($client, $instructor_id);
  $section_data = _cls_curriculum_guide_prepare_instructor_section_data($data, $academic_year_id);

  print theme('cls_curriculum_guide_instructor_ajax_sections',
    array(
      'sections' => $section_data,
    )
  );
}
