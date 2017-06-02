<?php
/**
 * @file
 * cls_faculty.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cls_faculty_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_views_api().
 */
function cls_faculty_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function cls_faculty_image_default_styles() {
  $styles = array();

  // Exported image style: faculty_profile_90x110.
  $styles['faculty_profile_90x110'] = array(
    'name' => 'faculty_profile_90x110',
    'label' => 'Faculty Profile 90x110',
    'effects' => array(
      15 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 90,
          'height' => 110,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
