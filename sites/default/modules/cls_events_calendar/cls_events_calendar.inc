<?php
/**
 * @file
 * This contains implementation of various functions used in module.
 */
/**
 * Returns a list of all eligible entities to use with Add to Cal, along with their eligible fields and matching view modes.
 *
 * Output structure: [$entity_name][$field_name][$view_mode_name]
 *
 * @return array
 */
function cls_events_calendar_get_addtocal_entities() {
  $entities = field_info_instances();
  $entity_info = array();

  foreach ($entities as $entity_name => $entity) {
    foreach ($entity as $bundle_name => $bundle) {
      foreach ($bundle as $field_name => $field) {
        foreach ($field['display'] as $display_name => $display) {
          if ($bundle_name == 'calendar') {
            if (!array_key_exists($entity_name, $entity_info)) {
              $entity_info[$entity_name] = array(
                $field_name => array(
                  $display_name,
                ),
              );
            } else if (!array_key_exists($field_name, $entity_info[$entity_name])) {
              $entity_info[$entity_name][$field_name] = array(
                $display_name,
              );
            } else if (!array_key_exists($display_name, $entity_info[$entity_name][$field_name])) {
              $entity_info[$entity_name][$field_name][] = $display_name;
            }
          }
        }
      }
    }
  }
  return $entity_info;
}

/**
 * Outputs an ICS file containing event information for the selected entity.
 * Called by hook_menu.
 *
 * @param $entity
 * @param $field_name
 * @param $view_mode
 */
function cls_events_calendar_download_ics($entity, $field_name, $view_mode) {
  drupal_add_http_header('Content-Type', 'application/calendar; charset=utf-8');

  // Set the filename.
  $filename = preg_replace('/[\x00-\x1F]/u', '_', strip_tags($entity->title));
  drupal_add_http_header('Content-Disposition', 'attachment; filename="' . $filename . '.ics"');

  // Get entity type from the current path
  $entity_type = arg(0);

  // Get the entity_id.
  list($entity_id) = entity_extract_ids($entity_type, $entity);

  // Get query.
  $query = drupal_get_query_parameters();

  // Get display and info.
  $info = cls_events_calendar_extract_event_info($entity_type, $entity, $entity_id, $field_name);

  $url = isset($query['url']) ? $query['url'] : '';
  $description = $info['description'];
  $location = $info['location'];
  $title = $info['title'];

  $dates = field_get_items($entity_type, $entity, $field_name);
  $start_date = $dates[0]['value'];
  if (array_key_exists('value2', $dates[0])) {
    $end_date = $dates[0]['value2'];
  } else {
    $end_date = $start_date;
  }
  $rfc_dates = cls_events_calendar_rfc_3339_date($start_date, $end_date, $info['timezone']);

  echo 'BEGIN:VCALENDAR
VERSION:2.0
PRODID:-//hacksw/handcal//NONSGML v1.0//EN
BEGIN:VEVENT
UID:' . $entity_type . '-' . $entity_id . '@' . $_SERVER['HTTP_HOST'] . '
DTSTAMP:' . $rfc_dates['start'] . '
DTSTART:' . $rfc_dates['start'] . '
DTEND:' . $rfc_dates['end'] . '
SUMMARY:' . check_plain($title) . '
DESCRIPTION: ' . $description . ' - ' . url($url, array('absolute' => TRUE)) . '
LOCATION:' . $location . '
END:VEVENT
END:VCALENDAR';

  drupal_exit();
}

/**
 * Redirects to a Google Calendar event.
 * Called by hook_menu().
 *
 * @param $entity
 * @param $field_name
 * @param $view_mode
 */
function cls_events_calendar_google_link($entity, $field_name, $view_mode) {
  // Get entity type from the current path
  $entity_type = arg(0);

  list($entity_id) = entity_extract_ids($entity_type, $entity);
  $info = cls_events_calendar_extract_event_info($entity_type, $entity, $entity_id, $field_name);

  $rfc_dates = cls_events_calendar_rfc_3339_date($info['start'], $info['end'], $info['timezone']);

  $google_url = url('http://www.google.com/calendar/event', array(
    'query' => array(
      'action' => 'TEMPLATE',
      'text' => $info['title'],
      'dates' => $rfc_dates['both'],
      'sprop' => 'website:' . $_SERVER['HTTP_HOST'],
      'location' => $info['location'],
      'details' => $info['description'],
      'website' => url($info['url'], array('absolute' => TRUE))
    ),
  ));

  drupal_goto($google_url);
}

/**
 * Redirects to a Yahoo Calendar event.
 * Called by hook_menu().
 *
 * @param $entity
 * @param $field_name
 * @param $view_mode
 */
function cls_events_calendar_yahoo_link($entity, $field_name, $view_mode) {

  // Get entity type from the current path
  $entity_type = arg(0);

  list($entity_id) = entity_extract_ids($entity_type, $entity);
  $info = cls_events_calendar_extract_event_info($entity_type, $entity, $entity_id, $field_name);

  $rfc_dates = cls_events_calendar_rfc_3339_date($info['start'], $info['end'], $info['timezone']);

  $yahoo_url = url('http://calendar.yahoo.com/', array(
    'query' => array(
      'v' => 60,
      'TITLE' => $info['title'],
      'ST' => $rfc_dates['local_start'],
      'ET' => $rfc_dates['local_end'],
      'URL' => $_SERVER['HTTP_HOST'],
      'in_loc' => $info['location'],
      'desc' => $info['description'],
    ),
  ));

  drupal_goto($yahoo_url);
}

/**
 * Extract event related information to pass into calendar's required fields.
 */
function cls_events_calendar_extract_event_info($entity_type, $entity, $entity_id, $field_name) {
  $dates = field_get_items($entity_type, $entity, $field_name);

  $start_date = $dates[0]['value'];

  if (array_key_exists('value2', $dates[0])) {
    $end_date = $dates[0]['value2'];
  } else {
    $end_date = $start_date;
  }

  $timezone = $dates[0]['timezone_db'];

  $location = field_get_items($entity_type, $entity, 'field_location_name');
  $description = field_get_items($entity_type, $entity, 'field_event_description');

  if (strlen($description[0]['value']) > 1024) {
    $description = truncate_utf8($description[0]['value'], 1024, TRUE, TRUE);
  }
  else {
    $description = $description[0]['value'];
  }

  $uri = entity_uri($entity_type, $entity);
  $url = $uri['path'];

  return array(
    'title' => check_plain($entity->title),
    'start' => $start_date,
    'end' => $end_date,
    'timezone' => $timezone,
    'location' => $location[0]['value'],
    'description' => $description,
    'entity_id' => $entity_id,
    'entity_type' => $entity_type,
    'url' => $url,
  );
}

/**
 * Format date in required date format.
 */
function cls_events_calendar_rfc_3339_date($start, $end, $timezone) {
  if (!$end) {
    $end = $start;
  }

  $tz_utc = new DateTimeZone('UTC');
  $tz = new DateTimeZone($timezone);

  $startDate = new DateTime($start, $tz);
  $startDate->setTimezone($tz_utc);

  $endDate = new DateTime($end, $tz);
  $endDate->setTimezone($tz_utc);

  $start_timestamp = $startDate->getTimestamp();
  $end_timestamp = $endDate->getTimestamp();

  $diff_timestamp = $end_timestamp - $start_timestamp;

  $start_date = gmdate('Ymd', $start_timestamp) . 'T' . gmdate('His', $start_timestamp) . 'Z';
  $local_start_date = date('Ymd', $start_timestamp) . 'T' . date('His', $start_timestamp) . '';
  $end_date = gmdate('Ymd', $end_timestamp) . 'T' . gmdate('His', $end_timestamp) . 'Z';
  $local_end_date = date('Ymd', $end_timestamp) . 'T' . date('His', $end_timestamp) . '';

  $diff_hours = str_pad(round(($diff_timestamp / 60) / 60), 2, '0', STR_PAD_LEFT);
  $diff_minutes = str_pad(abs(round($diff_timestamp / 60) - ($diff_hours * 60)), 2, '0', STR_PAD_LEFT);

  return array(
    'start' => $start_date,
    'end' => $end_date,
    'both' => $start_date . '/' . $end_date,
    'local_start' => $local_start_date,
    'local_end' => $local_end_date,
  );
}
