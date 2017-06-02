<?php
/**
 * @file
 * cls_events_calendar.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function cls_events_calendar_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'events_addthis_block_social_widget_settings';
  $strongarm->value = array(
    'share_services' => 'compact',
    'buttons_size' => 'addthis_16x16_style',
    'counter_orientation' => 'horizontal',
    'extra_css' => '',
  );
  $export['events_addthis_block_social_widget_settings'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'events_addthis_block_social_widget_type';
  $strongarm->value = 'addthis_basic_toolbox';
  $export['events_addthis_block_social_widget_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'events_addthis_block_widget_settings';
  $strongarm->value = array(
    'share_services' => 'print',
    'buttons_size' => 'addthis_16x16_style',
    'counter_orientation' => 'horizontal',
    'extra_css' => '',
  );
  $export['events_addthis_block_widget_settings'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'events_addthis_block_widget_type';
  $strongarm->value = 'addthis_basic_toolbox';
  $export['events_addthis_block_widget_type'] = $strongarm;

  return $export;
}
