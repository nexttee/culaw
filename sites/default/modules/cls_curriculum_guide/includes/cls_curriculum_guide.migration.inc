<?php

function cls_curriculum_guide_migration_page(){
  set_time_limit(0);

  echo 'Creating entities...'. '</br>';

  $data = db_select('cls_courses_course', 'c')
          ->fields('c')
          ->execute()
          ->fetchAll();

  foreach($data as $offering){
    $name = trim($offering->name);
    $course_number = trim($offering->number);
    $description = $offering->offering_description;
    $is_featured = intval($offering->featured);
    $image_url = $offering->image_url;
    $image_url = (basename($image_url) !== 'www.law.columbia.edu') ? $image_url : null;
    $featured_color = (basename($image_url) !== 'www.law.columbia.edu') ? trim($offering->featured_color) : null;

    if($image_url !== null){
      $image = file_get_contents($image_url);
      $destination = 'public://cg_images/' . basename($image_url);
      $file = file_save_data($image, $destination, FILE_EXISTS_REPLACE);
      if (is_object($file)) {
        $file->status = 1;
        $file = file_save($file);
      }
    }else{
      $file = array();
    }

    $entity = entity_create('cls_cg_offering', array(
      'uid' => 1,
      'type' => 'cls_cg_offering',
      'name' => $name,
      'course_offering_number' => $course_number,
      'field_image' => array(LANGUAGE_NONE => array(0 => (array)$file)),
      'field_offering_description' => array(LANGUAGE_NONE => array(0 => array('value' => $description))),
      'field_is_featured' => array(LANGUAGE_NONE => array(0 => array('value' => $is_featured))),
      'field_featured_bg_color' => array(LANGUAGE_NONE => array(0 => array('value' => $featured_color)))
    ))->save();

    echo 'Entity created: ' . $course_number . '</br>';
  }

  echo 'Finished creating entities' . '</br>';

  echo 'Attaching recommended courses to entities' . '</br>';

  $result = db_query('SELECT c.number, c.related_courses
    FROM {cls_courses_course} c
    WHERE c.related_courses != :comma
    AND c.related_courses != :empty',
    array(':comma' => ",,", ':empty' => '')
  );

  foreach($result as $record){
    $related_courses = trim($record->related_courses, ',');
    $related_courses = explode(",", $related_courses);
    $related_courses_ids = cls_cg_offering_load_by_course_number($related_courses);

    $array = array();
    $array[] = trim($record->number);
    $current_entity_id = cls_cg_offering_load_by_course_number($array);
    $current_entity = entity_load('cls_cg_offering', $current_entity_id);
    $current_entity = reset($current_entity);

    $entity_wrapper = entity_metadata_wrapper('cls_cg_offering', $current_entity);
    $entity_wrapper->field_recommended_offerings->set($related_courses_ids);
    $entity_wrapper->save();

    echo 'Recommended courses added to course: ' . $current_entity->name . '</br>';
  }

  echo 'Finished attaching recommended courses to entities' . '</br>';

}

function cls_cg_offering_load_by_course_number($numbers){
  $query = new EntityFieldQuery();
  $result = $query->entityCondition('entity_type', 'cls_cg_offering')
                  ->propertyCondition('course_offering_number', $numbers, 'IN')
                  ->execute();
  $ids = array_keys($result['cls_cg_offering']);
  return $ids;
}
