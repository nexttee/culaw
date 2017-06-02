<?php
/**
 * @file
 * Add migration support to cls_calendar feature module.
 */

/**
 * Implements hook_migrate_api().
 */
function cls_calendar_migrate_api() {
  $api = array(
    'api' => 2,
    'migrations' => array(
      'RtsbCalendarCategory' => array(
        'class_name' => 'RtsbCategoryMigration',
        'group_name' => 'rtsb_taxonomy',
        'parent_id' => 1516,
        'vocabulary' => 'calendar_categories',
      ),
      'RtsbCalendarUnit' => array(
        'class_name' => 'RtsbCategoryMigration',
        'group_name' => 'rtsb_taxonomy',
        'parent_id' => 6211,
        'vocabulary' => 'calendar_units',
      ),
      'RtsbCalendar' => array(
        'class_name' => 'RtsbCalendarMigration',
        'group_name' => 'rtsb_content',
        'dependencies' => array(
          'RtsbCalendarCategory',
          'RtsbCalendarUnit',
          'RtsbCalendarLoad',
        ),
        'object_type' => 'rt_events',
        'owner_module' => 'calendar',
        'default_status' => 0,
      ),
    ),
  );

  return $api;
}

