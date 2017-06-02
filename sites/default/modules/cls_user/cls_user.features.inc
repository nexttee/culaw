<?php
/**
 * @file
 * cls_user.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cls_user_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function cls_user_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function cls_user_image_default_styles() {
  $styles = array();

  // Exported image style: faculty_details_300x360.
  $styles['faculty_details_300x360'] = array(
    'name' => 'faculty_details_300x360',
    'label' => 'Faculty_details_300x360',
    'effects' => array(
      16 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 300,
          'height' => 360,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_paragraphs_info().
 */
function cls_user_paragraphs_info() {
  $items = array(
    'faculty_profile_elements' => array(
      'name' => 'Faculty Profile Elements',
      'bundle' => 'faculty_profile_elements',
      'locked' => '1',
    ),
  );
  return $items;
}
