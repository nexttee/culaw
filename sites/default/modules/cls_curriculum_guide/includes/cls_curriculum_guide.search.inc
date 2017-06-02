<?php

function cls_curriculum_guide_search_page_callback(){

  _cls_curriculum_guide_add_assets();

  $client_id = variable_get('cls_client_id');
  $client_secret = variable_get('cls_client_secret');
  $client = cls_rest_api_make_api_request($client_id, $client_secret);
  $prepared_data = _cls_curriculum_guide_fetch_search_form_data($client);

  $selected_years = array_filter(variable_get('cls_curriculum_guide_selected_years', array()));
  $academic_years = _cls_curriculum_guide_get_academic_year_data_by_ids($client, $selected_years);

  $search_any_year_string = '';
  $count = 0;
  foreach($academic_years as $year){
    if($count !== count($academic_years) - 1){
      $search_any_year_string .= $year['id'] . ',';
    }else{
      $search_any_year_string .= $year['id'];
    }
    $count++;
  }

  $selected_tags = array_filter(variable_get('cls_curriculum_guide_tags', array()));
  $selected_tags = _cls_curriculum_guide_get_tag_data_by_ids($client, $selected_tags);

  $points = _cls_curriculum_guide_get_course_points();

  return theme('cls_curriculum_guide_search_page', array(
      'academic_years' => $academic_years,
      'search_any_year_string' => $search_any_year_string,
      'curriculum_levels' => $prepared_data['curriculum_levels'],
      'evaluation_methods' => $prepared_data['evaluation_methods'],
      'course_types' => $prepared_data['course_types'],
      'categories' => $prepared_data['course_categories'],
      'tags' => $selected_tags,
      'instructors' => $prepared_data['instructors'],
      'weekdays' => $prepared_data['weekdays'],
      'hours' => $prepared_data['hours'],
      'points' => $points,
    )
  );
}

function _cls_curriculum_guide_fetch_search_form_data($client){
  $default_year = intval(variable_get('cls_curriculum_guide_default_year'));
  $prepared_data = _cls_curriculum_guide_fetch_search_form_dictionaries_by_academic_year($client, $default_year);

  return $prepared_data;
}

function cls_curriculum_guide_search_results_download_callback($render_type = 'xlsx'){
  set_time_limit(0);

  $client_id = variable_get('cls_client_id');
  $client_secret = variable_get('cls_client_secret');
  $client = cls_rest_api_make_api_request($client_id, $client_secret);
  $qp = _cls_curriculum_guide_get_query_parameters();

  $results = _cls_curriculum_guide_fetch_search_results($client, $qp);
  $prepared_data = _cls_curriculum_guide_prepare_search_results_data($client, $results);

  if($render_type == 'xlsx'){
    _cls_curriculum_guide_prepare_excel_content_for_browser($prepared_data);
  }
}

function cls_curriculum_guide_search_results_callback(){
  _cls_curriculum_guide_add_assets();

  $client_id = variable_get('cls_client_id');
  $client_secret = variable_get('cls_client_secret');
  $client = cls_rest_api_make_api_request($client_id, $client_secret);
  $qp = _cls_curriculum_guide_get_query_parameters();

  $results = _cls_curriculum_guide_fetch_search_results($client, $qp);

  $prepared_data = array();

  if($results['code'] == 200){
    foreach($results['result'] as $result){
      $number_section = str_replace(' ', '', $result['courseCode']);
      $number_section = str_replace('LAW-', '', $number_section);
      $section = array(
        'id' => $result['id'],
        'number_section' => $number_section,
        'term' => $result['term']['yearTerm'],
        'name' => $result['sectionName'],
        'type' => ucwords(strtolower($result['academicYearCourse']['clsCourse']['courseType']['name'])),
        'points' => number_format($result['jdPoints'], 1),
      );
      $prepared_data[] = $section;
    }
  }

  $result_count = count($prepared_data);
  $extra = ($result_count != 1) ? 's' : '';
  $result_count_text = 'We found ' . $result_count . ' course' . $extra;

  return theme('cls_curriculum_guide_search_results_page', array(
      'sections' => $prepared_data,
      'result_count' => $result_count,
      'result_count_text' => $result_count_text,
    )
  );
}

function cls_curriculum_guide_ajax_search_results_batch_callback(){

  if( isset($_POST["ids"]) ) {
    $ids = $_POST["ids"];

    $data = array(
              'courseIds' => $ids,
              'courseData' => array('courseDescription', 'schedules', 'instructors')
            );

    $client_id = variable_get('cls_client_id');
    $client_secret = variable_get('cls_client_secret');
    $client = cls_rest_api_make_api_request($client_id, $client_secret);
    $endpoint_base_url = cls_rest_api_get_endpoint_base_url();
    $response = $client->fetch($endpoint_base_url.'/public/curriculum/courses/details', json_encode($data), 'POST', array('Content-Type' => 'application/json'));

    $prepared_data = array();

    if($response['code'] == 200){
      $object = array();
      foreach ($response['result'] as $result){
        $formatted_locations = array();
        $formatted_schedules = array();

        foreach($result['schedules'] as $schedule){
          $days = $schedule['weekdays'];
          $meet_time = $schedule['meetTime'];

          if($schedule['buildingCode'] !== 'TBA'){
            $formatted_locations[] = $schedule['buildingCode'] . ' ' . $schedule['classRoom'];
          }else{
            $formatted_locations[] = 'T.B.A.';
          }

          $formatted_schedules[] = $days . ' ' . $meet_time;
        }

        $object['id'] = $result['course']['id'];
        $instructors = _cls_curriculum_guide_get_instructors_for_search_page($result['instructors']);

        $instructors_string = '';
        if(count($instructors) > 0){
          foreach($instructors as $instructor){
            $instructors_string .= $instructor['name'] . '<br>';
          }
        }

        $object['instructors'] = $instructors_string;
        $object['schedule'] = count($formatted_schedules) > 0 ? implode('<br>', $formatted_schedules) : '';
        $object['location'] = count($formatted_locations) > 0 ? implode('<br>', $formatted_locations) : '';
        $prepared_data[] = $object;
      }

    }

    echo json_encode($prepared_data);
  }

}

function cls_curriculum_guide_ajax_search_results_course_details_callback($section_id, $type){
  _cls_curriculum_guide_add_assets();

  $client_id = variable_get('cls_client_id');
  $client_secret = variable_get('cls_client_secret');
  $client = cls_rest_api_make_api_request($client_id, $client_secret);

  $section_details = _cls_curriculum_guide_fetch_section_details($client, $section_id, TRUE);

  if($type == 'details'){
    $instructors = '';
    if(count($section_details['instructors']) > 0){
      foreach($section_details['instructors'] as $instructor){
        $instructors .= $instructor['name'] . '<br>';
      }
    }

    $schedules = count($section_details['schedules']) > 0 ? implode('<br>', $section_details['schedules']) : '';
    $locations = count($section_details['locations']) > 0 ? implode('<br>', $section_details['locations']) : '';

    echo '<table class="inner"><tr><td class="instructors">'.$instructors.'</td><td class="schedules">'.$schedules.'</td><td class="locations">'.$locations.'</td></tr></table>';
  }
  else{
    $description = isset($section_details['description']) ? $section_details['description'] : '';
    echo $description;
  }
}

function _cls_curriculum_guide_prepare_excel_content_for_browser($prepared_data){
  set_time_limit(0);

  $file_content = '';
  $header_row = "\"Number and Section\"\t\"Term\"\t\"Name\"\t\"Instructors\"\t\"Schedule\"\t\"Location\"\t\"Type\"\t\"Points\"";
  $begin = "\n";

  $file_content .= $header_row;

  foreach($prepared_data as $section){
    $instructors_array = array();
    foreach($section['instructors'] as $instructor){
      $instructors_array[] = $instructor['name'];
    }

    $instructors = implode(", ", $instructors_array);
    $schedules = implode(", ", $section['schedules']);
    $locations = implode(", ", $section['locations']);
    $file_content .= $begin . $section['number_section'] . "\t" . $section['term'] . "\t" . $section['name'] . "\t" . $instructors . "\t" . $schedules . "\t" . $locations . "\t" . $section['type'] . "\t" . $section['points'];
  }

  $file_content = decode_entities($file_content);

  // Write the data to a temporary file.
  $temp_name = drupal_tempnam('temporary://', 'cls_curriculum_guide_download_tsv_');

  if(file_put_contents($temp_name, $file_content) === FALSE){
    drupal_set_message(t('The file could not be created.'), 'error');
    return FALSE;
  }

  try{
    if(($library = libraries_load('PHPExcel')) && !empty($library['loaded'])){
      PHPExcel_Cell::setValueBinder(new PHPExcel_Cell_AdvancedValueBinder());
      $objReader = PHPExcel_IOFactory::createReader('CSV');
      $objReader->setDelimiter("\t");
      $objPHPExcel = $objReader->load($temp_name);
      $objPHPExcel->getProperties()->setCreator("Columbia Law School");
      $objPHPExcel->getProperties()->setLastModifiedBy("Columbia Law School");
      $objPHPExcel->getProperties()->setTitle("Course Search Results");
      $objPHPExcel->getProperties()->setSubject("Course Search Results");
      $objPHPExcel->getActiveSheet()->setTitle('Course Search Results');
      $objPHPExcel->getDefaultStyle()->getFont()->setSize(12);
      $objPHPExcel->getActiveSheet()->getStyle("A1:H1")->applyFromArray(array("font" => array( "bold" => true)));
      $objPHPExcel->getActiveSheet()->getColumnDimension("A")->setAutoSize(true);
      $objPHPExcel->getActiveSheet()->getColumnDimension("B")->setAutoSize(true);
      $objPHPExcel->getActiveSheet()->getColumnDimension("C")->setAutoSize(true);
      $objPHPExcel->getActiveSheet()->getColumnDimension("D")->setAutoSize(true);
      $objPHPExcel->getActiveSheet()->getColumnDimension("E")->setAutoSize(true);
      $objPHPExcel->getActiveSheet()->getColumnDimension("F")->setAutoSize(true);
      $objPHPExcel->getActiveSheet()->getColumnDimension("G")->setAutoSize(true);
      $objPHPExcel->getActiveSheet()->getColumnDimension("H")->setAutoSize(true);

      $objWriter = new PHPExcel_Writer_Excel2007($objPHPExcel);
      $objWriter->setOffice2003Compatibility(true);
      $filename = 'course-search-results.xlsx';
      $xlsx_temp_name = tempnam(file_directory_temp(), 'cls_courses_download_xlsx_');
      $objWriter->save($xlsx_temp_name);
      $file_scheme_uri = 'temporary://' . drupal_basename($xlsx_temp_name);
      $http_headers = array(
        'Pragma' => 'public',
        'Expires' => '0',
        'Cache-Control' => 'must-revalidate, post-check=0, pre-check=0',
        'Content-Type' => 'application/vnd.openxmlformats-officedocument.spreadsheetml.sheet',
        'Content-Disposition' => 'attachment; filename=course-search-results.xlsx;',
        'Content-Transfer-Encoding' => 'binary',
        'Content-Length' => filesize($file_scheme_uri)
      );
      file_transfer($file_scheme_uri, $http_headers);
    }
  }
  catch(Exception $e){
    return 'Caught exception: ' . $e->getMessage();
  }

}

function cls_curriculum_guide_ajax_instructors_callback($academic_year_id){
  $client_id = variable_get('cls_client_id');
  $client_secret = variable_get('cls_client_secret');
  $client = cls_rest_api_make_api_request($client_id, $client_secret);

  $dictionaries = _cls_curriculum_guide_fetch_search_form_dictionaries_by_academic_year($client, $academic_year_id);
  $instructors = $dictionaries['instructors'];

  print theme('cls_curriculum_guide_ajax_instructors',
    array(
      'instructors' => $instructors,
    )
  );
}

function cls_curriculum_guide_ajax_categories_callback($academic_year_id){
  $client_id = variable_get('cls_client_id');
  $client_secret = variable_get('cls_client_secret');
  $client = cls_rest_api_make_api_request($client_id, $client_secret);
  $dictionaries = _cls_curriculum_guide_fetch_search_form_dictionaries_by_academic_year($client, $academic_year_id);
  $categories = $dictionaries['course_categories'];

  print theme('cls_curriculum_guide_ajax_categories',
    array(
      'categories' => $categories,
    )
  );
}
