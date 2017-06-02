<?php
/**
 * @file
 * cls_events_calendar.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function cls_events_calendar_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'events_calendar';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Events Calendar Quicktabs';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'law_school_events',
      'display' => 'events_day_block',
      'args' => '',
      'title' => 'Day',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'law_school_events',
      'display' => 'events_week_block',
      'args' => '',
      'title' => 'Week',
      'weight' => '-99',
      'type' => 'view',
    ),
    2 => array(
      'vid' => 'law_school_events',
      'display' => 'events_month_block',
      'args' => '%1',
      'title' => 'Month',
      'weight' => '-98',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Day');
  t('Events Calendar Quicktabs');
  t('Month');
  t('Week');

  $export['events_calendar'] = $quicktabs;

  return $export;
}
