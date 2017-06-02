<?php

/**
 * @file
 * Functions related to My Columbia Law dashboard.
 */

define('CLS_MCL_APP_STATUS_CODE_NOT_FOUND', 0);
define('CLS_MCL_APP_STATUS_CODE_INCOMPLETE', 1);
define('CLS_MCL_APP_STATUS_CODE_PENDING_COMPLETE', 2);
define('CLS_MCL_APP_STATUS_CODE_COMPLETE', 3);

function cls_mcl_dashboard_page($instance_id) {
  global $user;

  $site_instance = cls_get_site_instance($instance_id);

  drupal_add_css(drupal_get_path('module', 'cls_mcl') . '/css/dashboard.css', array('every_page' => FALSE));
  drupal_add_library('system', 'ui.tabs');
  drupal_add_js(drupal_get_path('module', 'cls_mcl') . '/js/dashboard.js', array('scope' => 'footer', 'every_page' => FALSE));

  // @TODO Replace with contrib module that provides custom 403 pages/modules.
  if (isset($_GET['asw403msg']) && $_GET['asw403msg'] == 1) {
    drupal_set_message(t('Browsing the Admitted Student Website requires an activated admitted student account. If you are currently logged into My Columbia Law and you are an admitted student, please <a href="@url">logout and successfully activate your admitted student account</a>.', array('@url' => url('user/logout', array('query' => array('destination' => 'admissions/jd/admitted/activate'))))), 'warning');
  }

  $current_user = user_load($user->uid);
  $account = entity_metadata_wrapper('user', $current_user);

  $title = 'My Dashboard';
  $first_name = $account->cls_user_first_name->value();
  if (!empty($first_name)) {
    if (substr($first_name, -1) == 's') {
      $title = $first_name . '&rsquo; Dashboard';
    }
    else {
      $title = $first_name . '&rsquo;s Dashboard';
    }
  }

  // We won't be needing this snippet of code for fetching interest courses
  /*
  $course_category_excludes = array();
  if (!empty($site_instance['interest_visibility_codes'])) {
    $query = db_select('cls_mcl_interest_type', 'cmit')
        ->fields('cmit', array('id', 'title'));
    $query->orderBy('title', 'ASC');
    $query->condition('visible', $site_instance['interest_visibility_codes'], 'NOT IN');
    $instance_interests = $query->execute();
    while ($instance_interest_record = $instance_interests->fetchAssoc()) {
      $course_category_excludes[] = $instance_interest_record['id'];
    }
  }

  $course_category_excludes_views_argument = implode('+', $course_category_excludes);
  */

  $interest_areas = array();
  $legacy_interest_areas = array();
  foreach ($account->cls_mcl_academic_interests as $interest_area) {
    $interest_area = $interest_area->value();
    if (!empty($interest_area)) {
      $cls_mcl_interest_type = cls_mcl_interest_type_load(intval($interest_area));
      if (!empty($cls_mcl_interest_type->old_mcl_id)) {
        $interest_areas[] = $cls_mcl_interest_type->old_mcl_id;
      }
      if (!empty($cls_mcl_interest_type->rtsb_id)) {
        $legacy_interest_areas[] = $cls_mcl_interest_type->rtsb_id;
      }
    }
  }

  $corresponding_interest_courses_and_faculty = _cls_mcl_fetch_corresponding_interest_courses_and_faculty($interest_areas, $instance_id);

  $interest_area_views_argument = implode(',', $interest_areas);
  $legacy_interest_area_views_argument = implode(',', $legacy_interest_areas);

  $account_admissions_cycle = $account->cls_mcl_admissions_cycle->value();

  $account_in_current_admissions_cycle = FALSE;
  $current_admissions_cycle_year = variable_get('cls_mcl.config.current_application_year', date("Y")) + 3;
  if ($account_admissions_cycle == strval($current_admissions_cycle_year)) {
    $account_in_current_admissions_cycle = TRUE;
  }

  // @todo Replace with actual function
  $account_application_status = CLS_MCL_APP_STATUS_CODE_NOT_FOUND;

  $account_application_found = FALSE;
  if ($account_application_status != CLS_MCL_APP_STATUS_CODE_NOT_FOUND) {
    $account_application_found = TRUE;
  }

  if ($instance_id == 'my_columbia_llm' && cls_mcl_llm_status_access_callback()) {
    $account_application_found = TRUE;
    $account_application_status = 1;
    $account_in_current_admissions_cycle = TRUE;
  }

  $account_zip_code = $account->cls_mcl_zip_code->value();
  $account_education_1 = $account->cls_mcl_undergrad_institution->value();
  $account_education_2 = $account->cls_mcl_grad_institution->value();

  $events_postal_code_proximity = 'US_00000_0';
  if (!empty($account_zip_code)) {
    $events_postal_code_proximity = 'US_' . $account_zip_code . '_100';
  }

  $show_upcoming_events_view = FALSE;
  if (!empty($account_zip_code) ||
    !empty($account_education_1) ||
    !empty($account_education_2)
  ) {
    $show_upcoming_events_view = TRUE;
  }

  return theme(
    'cls_mcl_dashboard',
    array(
      //'current_user' => $current_user,
      'title' => $title,
      'interest_area_courses' => $corresponding_interest_courses_and_faculty['courses'],
      'interest_area_faculty' => $corresponding_interest_courses_and_faculty['instructors'],
      'interest_area_views_argument' => $interest_area_views_argument,
      'legacy_interest_area_views_argument' => $legacy_interest_area_views_argument,
      //'account_admissions_cycle' => $account_admissions_cycle,
      //'account_application_status' => $account_application_status,
      'account_in_current_admissions_cycle' => $account_in_current_admissions_cycle,
      'account_application_found' => $account_application_found,
      'events_postal_code_proximity' => $events_postal_code_proximity,
      'show_upcoming_events_view' => $show_upcoming_events_view,
      'instance_id' => $instance_id,
      'instance_path' => $site_instance['path'],
      'courses_custom_link_1_path' => $site_instance['dashboard_courses_custom_link_1_path'],
      'courses_custom_link_1_title' => $site_instance['dashboard_courses_custom_link_1_title'],
      'courses_custom_link_2_path' => $site_instance['dashboard_courses_custom_link_2_path'],
      'courses_custom_link_2_title' => $site_instance['dashboard_courses_custom_link_2_title'],
      'faculty_custom_link_1_path' => $site_instance['dashboard_faculty_custom_link_1_path'],
      'faculty_custom_link_1_title' => $site_instance['dashboard_faculty_custom_link_1_title'],
      'viewbook_path' => $site_instance['dashboard_viewbook_path'],
      'viewbook_title' => $site_instance['dashboard_viewbook_title'],
      'status_checker_path' => $site_instance['dashboard_status_checker_path'],
      'apply_path' => $site_instance['dashboard_apply_path'],
      'visit_path' => $site_instance['dashboard_visit_path'],
      'tour_path' => base_path() . $site_instance['tour_path'],
      'tour_title' => $site_instance['tour_title'],
    )
  );

}

function cls_mcl_dashboard_redirect($instance_id) {
  $site_instance = cls_get_site_instance($instance_id);
  drupal_goto($site_instance['path'], array(), 301);
}

function _cls_mcl_fetch_corresponding_interest_courses_and_faculty($category_ids, $instance_id) {
  $prepared_data = array();

  if (isset($category_ids)) {
    if (module_exists('cls_rest_api')) {
      $client_id = variable_get('cls_client_id');
      $client_secret = variable_get('cls_client_secret');
      $client = cls_rest_api_make_api_request($client_id, $client_secret);
      $endpoint_base_url = cls_rest_api_get_endpoint_base_url();

      $academic_year_id = variable_get('cls_curriculum_guide_default_year');

      $data = array();

      if (count($category_ids) > 0) {
        $data = array(
          "courseCategory" => $category_ids
        );
      }
      else{
        $curriculum_level = ($instance_id == 'my_columbia_law') ? 'Foundation' : 'Upperclass';
        // $course_type = ($instance_id == 'my_columbia_law') ? NULL : array(12);
        $data = array(
          "curriculumLevel" => $curriculum_level,
          "courseType" => array(12)
        );
      }

      $response = $client->fetch($endpoint_base_url.'/public/curriculum/academicYear/'.$academic_year_id.'/courses-offered/search', json_encode($data), 'POST', array('Content-Type' => 'application/json'));

      if (isset($response['result']) && $response['code'] == 200) {
        $result = $response['result'];
        $courses = $result['courses'];
        $instructors = $result['allInstructors'];

        foreach ($courses as $course) {
          $object = array();
          $course_name = ucwords(strtolower($course['academicYearCourse']['bulletinName']));
          $course_name = truncate_utf8($course_name, 40, TRUE, TRUE);
          $object['name'] = $course_name;
          $object['course_number'] = $course['academicYearCourse']['clsCourse']['universityCourse']['number'];

          if (count($course['instructors']) > 0) {
            $instructor_array = array();
            foreach($course['instructors'] as $instructor){
              $f_name = $instructor['firstName'];
              $f_initial = substr($f_name, 0, 1);
              $l_name = $instructor['lastName'];
              $instructor_array[] = $f_initial . ". " . $l_name;
            }
            $instructor_string = (count($instructor_array) > 0) ? implode(", ", $instructor_array) : NULL;
            $instructor_string = isset($instructor_string) ? truncate_utf8($instructor_string, 80, TRUE, TRUE) : NULL;

            if (strpos($instructor_string, '...') !== false) {
              $search = strrchr($instructor_string, ",");
              $instructor_string = str_replace($search, '...', $instructor_string);
            }

            $object['instructors'] = $instructor_string;
          }

          $prepared_data['courses'][] = $object;
        }

        foreach ($instructors as $instructor) {
          if (isset($instructor['login'])) {
            $cas_name = $instructor['login'];

            $user_data = db_query(
              "SELECT u.uid FROM {cas_user} cu INNER JOIN {users} u ON u.uid = cu.uid WHERE cu.cas_name = :cas_name",
                  array(':cas_name' => $cas_name)
              )->fetchObject();

            if (isset($user_data->uid) && $user_data->uid) {
              $drupal_user = user_load($user_data->uid);
            }

            if ($drupal_user) {
              $profile = array();

              $profile['path'] = '/' . drupal_get_path_alias('user/' . $drupal_user->uid);
              $profile['photo_url'] = isset($drupal_user->field_faculty_profile_image['und'][0]['uri']) ? $drupal_user->field_faculty_profile_image['und'][0]['uri'] : NULL;
              $profile['title'] = isset($drupal_user->cls_user_title['und'][0]['value']) ? $drupal_user->cls_user_title['und'][0]['value'] : NULL;

              $name_array = array();
              if (isset($drupal_user->cls_user_first_name['und'][0]['value'])) {
                $name_array[] = $drupal_user->cls_user_first_name['und'][0]['value'];
              }
              if (isset($drupal_user->cls_user_middle_name['und'][0]['value'])) {
                $name_array[] = $drupal_user->cls_user_middle_name['und'][0]['value'];
              }
              if (isset($drupal_user->cls_user_last_name['und'][0]['value'])) {
                $name_array[] = $drupal_user->cls_user_last_name['und'][0]['value'];
              }
              if (isset($drupal_user->cls_user_suffix['und'][0]['value'])) {
                $name_array[] = $drupal_user->cls_user_suffix['und'][0]['value'];
              }
              $profile['name'] = (count($name_array) > 0) ? implode(" ", $name_array) : NULL;

              $prepared_data['instructors'][] = $profile;
            }
          }
        }

        shuffle($prepared_data['courses']);
        shuffle($prepared_data['instructors']);
      }
    }
  }

  return $prepared_data;
}
