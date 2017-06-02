<?php
/**
 * @file
 * This file contains field declaration for views form.
 */
/**
 * Implements hook_views_data().
 */
function cls_events_calendar_views_data() {
  $data = array();
  $data['cls_events_calendar']['table']['group'] = t('CLS Event Calendar');
  $data['cls_events_calendar']['table']['join'] = array(
    // #global let's it appear all the time.
    '#global' => array(),
  );
  $data['cls_events_calendar']['add_to_calendar'] = array(
    'title' => t('Add to Calendar Links'),
    'help' => t('Displays add to calendar links for specified date field.'),
    'field' => array(
      'handler' => 'views_handler_add_to_calendar',
    ),
  );
  return $data;
}
