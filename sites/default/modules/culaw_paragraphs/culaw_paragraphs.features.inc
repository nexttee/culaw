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
    'cta_card' => array(
      'name' => 'CTA Card',
      'bundle' => 'cta_card',
      'locked' => '1',
    ),
    'feed_card' => array(
      'name' => 'Feed Card',
      'bundle' => 'feed_card',
      'locked' => '1',
    ),
    'media_card' => array(
      'name' => 'Media Card',
      'bundle' => 'media_card',
      'locked' => '1',
    ),
    'navigation_row' => array(
      'name' => 'Navigation Row',
      'bundle' => 'navigation_row',
      'locked' => '1',
    ),
    'quick_links_card' => array(
      'name' => 'Quick Links Card',
      'bundle' => 'quick_links_card',
      'locked' => '1',
    ),
    'row_with_columns' => array(
      'name' => 'Layout Row',
      'bundle' => 'row_with_columns',
      'locked' => '1',
    ),
    'section_navigation_card' => array(
      'name' => 'Section Navigation Card',
      'bundle' => 'section_navigation_card',
      'locked' => '1',
    ),
    'social_media_card' => array(
      'name' => 'Social Media Card',
      'bundle' => 'social_media_card',
      'locked' => '1',
    ),
    'sticky_navigation_card' => array(
      'name' => 'Sticky Navigation Card',
      'bundle' => 'sticky_navigation_card',
      'locked' => '1',
    ),
    'text_card' => array(
      'name' => 'Text Card',
      'bundle' => 'text_card',
      'locked' => '1',
    ),
  );
  return $items;
}
