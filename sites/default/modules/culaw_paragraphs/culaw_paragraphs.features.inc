<?php
/**
 * @file
 * culaw_paragraphs.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function culaw_paragraphs_ctools_plugin_api($module = NULL, $api = NULL) {
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
function culaw_paragraphs_node_info() {
  $items = array(
    'landing_page' => array(
      'name' => t('Landing Page'),
      'base' => 'node_content',
      'description' => t('Used for created flexible content layouts.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_paragraphs_info().
 */
function culaw_paragraphs_paragraphs_info() {
  $items = array(
    'media_card' => array(
      'name' => 'Media Card',
      'bundle' => 'media_card',
      'locked' => '1',
    ),
    'row_with_columns' => array(
      'name' => 'Row with Columns',
      'bundle' => 'row_with_columns',
      'locked' => '1',
    ),
  );
  return $items;
}
