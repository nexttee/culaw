<?php

function cls_curriculum_guide_section_page_callback($section_id){
  _cls_curriculum_guide_add_assets();

  $client_id = variable_get('cls_client_id');
  $client_secret = variable_get('cls_client_secret');
  $client = cls_rest_api_make_api_request($client_id, $client_secret);
  $data = _cls_curriculum_guide_fetch_section_details($client, $section_id, false, true);

  $course_code = $data['course_code'];
  $calendar_year = $data['course_calendar_year'];
  $cu_term_number = $data['course_cu_term_number'];

  $textbook_url = 'https://courseworks.columbia.edu/tbook-tool/viewTextbook.vtb?courseId='. $course_code . '_' . $calendar_year . '_' . $cu_term_number;

  return theme('cls_curriculum_guide_section_page', array(
      'name' => $data['name'],
      'course_number' => $data['course_number'],
      'section' => $data['section'],
      'semester' => $data['semester'],
      'schedules' => $data['schedules'],
      'locations' => $data['locations'],
      'instructors' => $data['instructors'],
      'description' => $data['description'],
      'points' => $data['points'],
      'method' => $data['method'],
      'course_type' => $data['course_type'],
      'level' => $data['level'],
      'textbook_url' => $textbook_url,
      'jd_writing_credit_description' => $data['jd_writing_credit_description'],
      'registration_limitations' => $data['registration_limitations'],
      'instructor_prerequistes' => $data['instructor_prerequistes'],
      'instructor_corequisites' => $data['instructor_corequisites'],
      'recommended_courses' => $data['recommended_courses'],
      'goals' => $data['goals'],
      'categories' => $data['categories'],
      'other_sections' => $data['other_sections'],
    )
  );
}
