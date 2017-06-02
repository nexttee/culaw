<?php

function cls_curriculum_guide_homepage_callback(){
  _cls_curriculum_guide_add_assets();

  $client_id = variable_get('cls_client_id');
  $client_secret = variable_get('cls_client_secret');
  $client = cls_rest_api_make_api_request($client_id, $client_secret);
  $prepared_data = _cls_curriculum_guide_fetch_course_spotlight($client);

  return theme('cls_curriculum_guide_homepage',
    array(
      'course_spotlight' => $prepared_data['course_spotlight'],
      'related_offerings' => $prepared_data['related_offerings'],
    )
  );
}

function _cls_curriculum_guide_fetch_course_spotlight($client){

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'cls_cg_offering')
        ->fieldCondition('field_is_featured', 'value', 1, '=')
        ->addTag('random')
        ->range(0,1);
  $result = $query->execute();
  $result = array_keys($result['cls_cg_offering']);

  $prepared_data = array();

  if(isset($result[0])){
    $course_spotlight = _cls_curriculum_guide_fetch_course_offering_data($client, $result[0]);
    $related_offerings = array();
    if(!empty($course_spotlight['related_ids'])){
      foreach($course_spotlight['related_ids'] as $related_id){
        $related_offerings[] = _cls_curriculum_guide_fetch_course_offering_data($client, $related_id);
      }
    }

    $prepared_data = array(
      'course_spotlight' => $course_spotlight,
      'related_offerings' => $related_offerings,
    );
  }

  return $prepared_data;
}
