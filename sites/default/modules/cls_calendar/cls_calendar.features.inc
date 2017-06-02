<?php
/**
 * @file
 * cls_calendar.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cls_calendar_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function cls_calendar_node_info() {
  $items = array(
    'calendar' => array(
      'name' => t('Calendar'),
      'base' => 'node_content',
      'description' => t('<p>Use Calendar for the Law School\'s Calendar (LawCal) content.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
