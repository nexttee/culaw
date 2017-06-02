<?php
/**
 * @file
 * cls_events_calendar.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function cls_events_calendar_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'events_calendar_blocks';
  $context->description = 'This context places calendar block and exposed filter on events page.';
  $context->tag = 'events, calendar';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'events' => 'events',
        'events/*' => 'events/*',
      ),
    ),
    'theme' => array(
      'values' => array(
        'culaw' => 'culaw',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'cls_core-calendar_navigation' => array(
          'module' => 'cls_core',
          'delta' => 'calendar_navigation',
          'region' => 'content',
          'weight' => '-10',
        ),
        'cls_core-event_title_search_block' => array(
          'module' => 'cls_core',
          'delta' => 'event_title_search_block',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'views-law_school_events-block_1' => array(
          'module' => 'views',
          'delta' => 'law_school_events-block_1',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'cls_core-event_category_search_block' => array(
          'module' => 'cls_core',
          'delta' => 'event_category_search_block',
          'region' => 'sidebar_second',
          'weight' => '-6',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('This context places calendar block and exposed filter on events page.');
  t('events, calendar');
  $export['events_calendar_blocks'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'events_page_calendar_link';
  $context->description = 'This context places "Law school Event Calendar", "Upcoming events" links block on event detail pages.';
  $context->tag = 'events, calendar';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'calendar' => 'calendar',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'theme' => array(
      'values' => array(
        'culaw' => 'culaw',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'cls_events_calendar-events_calendar_date_block' => array(
          'module' => 'cls_events_calendar',
          'delta' => 'events_calendar_date_block',
          'region' => 'featured',
          'weight' => '-10',
        ),
        'cls_events_calendar-law_school_events_link' => array(
          'module' => 'cls_events_calendar',
          'delta' => 'law_school_events_link',
          'region' => 'sub_featured',
          'weight' => '-10',
        ),
        'cls_events_calendar-events_date_location_block' => array(
          'module' => 'cls_events_calendar',
          'delta' => 'events_date_location_block',
          'region' => 'content_top',
          'weight' => '-10',
        ),
        'views-48b7aed817411c0c769ffac5574efa9f' => array(
          'module' => 'views',
          'delta' => '48b7aed817411c0c769ffac5574efa9f',
          'region' => 'sub_content',
          'weight' => '-10',
        ),
        'cls_events_calendar-law_school_events_link_bottom' => array(
          'module' => 'cls_events_calendar',
          'delta' => 'law_school_events_link_bottom',
          'region' => 'sub_content',
          'weight' => '-9',
        ),
        'cls_events_calendar-events_add_to_calendar' => array(
          'module' => 'cls_events_calendar',
          'delta' => 'events_add_to_calendar',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'cls_events_calendar-events_addthis_print_block' => array(
          'module' => 'cls_events_calendar',
          'delta' => 'events_addthis_print_block',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'cls_events_calendar-events_addthis_social_block' => array(
          'module' => 'cls_events_calendar',
          'delta' => 'events_addthis_social_block',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('This context places "Law school Event Calendar", "Upcoming events" links block on event detail pages.');
  t('events, calendar');
  $export['events_page_calendar_link'] = $context;

  return $export;
}
