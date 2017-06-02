<?php

$view = new view();
$view->name = 'cls_mcl_dashboard_events';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'My Columbia Law: Dashboard: Events';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'My Columbia Law: Dashboard: Events';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['query_comment'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '3';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'fields';
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['content'] = '<p style="font-size: 14px;">Our Admissions Officers may be coming to a campus or conference near you. Visit <a href="/admissions/jd/visit/on-the-road">Columbia on the Road</a> to find out more.</p>';
$handler->display->display_options['empty']['area']['format'] = 'full_html';
/* Field: Content: Start and End Dates */
$handler->display->display_options['fields']['cls_mcl_event_datetime_1']['id'] = 'cls_mcl_event_datetime_1';
$handler->display->display_options['fields']['cls_mcl_event_datetime_1']['table'] = 'field_data_cls_mcl_event_datetime';
$handler->display->display_options['fields']['cls_mcl_event_datetime_1']['field'] = 'cls_mcl_event_datetime';
$handler->display->display_options['fields']['cls_mcl_event_datetime_1']['label'] = '';
$handler->display->display_options['fields']['cls_mcl_event_datetime_1']['exclude'] = TRUE;
$handler->display->display_options['fields']['cls_mcl_event_datetime_1']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['cls_mcl_event_datetime_1']['settings'] = array(
  'format_type' => 'short_month',
  'fromto' => 'value',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
);
/* Field: Content: Start and End Dates */
$handler->display->display_options['fields']['cls_mcl_event_datetime_2']['id'] = 'cls_mcl_event_datetime_2';
$handler->display->display_options['fields']['cls_mcl_event_datetime_2']['table'] = 'field_data_cls_mcl_event_datetime';
$handler->display->display_options['fields']['cls_mcl_event_datetime_2']['field'] = 'cls_mcl_event_datetime';
$handler->display->display_options['fields']['cls_mcl_event_datetime_2']['label'] = '';
$handler->display->display_options['fields']['cls_mcl_event_datetime_2']['exclude'] = TRUE;
$handler->display->display_options['fields']['cls_mcl_event_datetime_2']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['cls_mcl_event_datetime_2']['settings'] = array(
  'format_type' => 'day',
  'fromto' => 'value',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
);
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['label'] = '';
$handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="fourcol alpha omega">
<div class="calendar-item">
<div class="icon">
<div class="month">[cls_mcl_event_datetime_1]</div>
<div class="day">[cls_mcl_event_datetime_2]</div>
</div>';
$handler->display->display_options['fields']['nothing']['element_type'] = '0';
$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
/* Field: Content: URL */
$handler->display->display_options['fields']['cls_mcl_event_url_1']['id'] = 'cls_mcl_event_url_1';
$handler->display->display_options['fields']['cls_mcl_event_url_1']['table'] = 'field_data_cls_mcl_event_url';
$handler->display->display_options['fields']['cls_mcl_event_url_1']['field'] = 'cls_mcl_event_url';
$handler->display->display_options['fields']['cls_mcl_event_url_1']['label'] = '';
$handler->display->display_options['fields']['cls_mcl_event_url_1']['exclude'] = TRUE;
$handler->display->display_options['fields']['cls_mcl_event_url_1']['element_label_colon'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['path'] = '[cls_mcl_event_url_1]';
$handler->display->display_options['fields']['title']['alter']['absolute'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['external'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['target'] = '_blank';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_type'] = 'h5';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Location: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'location';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['label'] = '';
$handler->display->display_options['fields']['name']['exclude'] = TRUE;
$handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['name']['alter']['text'] = '[name]<br />';
$handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['name']['hide_empty'] = TRUE;
/* Field: Location: Street */
$handler->display->display_options['fields']['street']['id'] = 'street';
$handler->display->display_options['fields']['street']['table'] = 'location';
$handler->display->display_options['fields']['street']['field'] = 'street';
$handler->display->display_options['fields']['street']['label'] = '';
$handler->display->display_options['fields']['street']['exclude'] = TRUE;
$handler->display->display_options['fields']['street']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['street']['alter']['text'] = '[street]<br />';
$handler->display->display_options['fields']['street']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['street']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['street']['hide_empty'] = TRUE;
/* Field: Location: City */
$handler->display->display_options['fields']['city']['id'] = 'city';
$handler->display->display_options['fields']['city']['table'] = 'location';
$handler->display->display_options['fields']['city']['field'] = 'city';
$handler->display->display_options['fields']['city']['label'] = '';
$handler->display->display_options['fields']['city']['exclude'] = TRUE;
$handler->display->display_options['fields']['city']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['city']['alter']['text'] = '[city], ';
$handler->display->display_options['fields']['city']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['city']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['city']['hide_empty'] = TRUE;
/* Field: Location: Province */
$handler->display->display_options['fields']['province']['id'] = 'province';
$handler->display->display_options['fields']['province']['table'] = 'location';
$handler->display->display_options['fields']['province']['field'] = 'province';
$handler->display->display_options['fields']['province']['label'] = '';
$handler->display->display_options['fields']['province']['exclude'] = TRUE;
$handler->display->display_options['fields']['province']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['province']['alter']['text'] = '[city] [province]';
$handler->display->display_options['fields']['province']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['province']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['province']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['province']['style'] = 'code';
/* Field: Location: Postal Code */
$handler->display->display_options['fields']['postal_code']['id'] = 'postal_code';
$handler->display->display_options['fields']['postal_code']['table'] = 'location';
$handler->display->display_options['fields']['postal_code']['field'] = 'postal_code';
$handler->display->display_options['fields']['postal_code']['label'] = '';
$handler->display->display_options['fields']['postal_code']['exclude'] = TRUE;
$handler->display->display_options['fields']['postal_code']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['postal_code']['alter']['text'] = ' [postal_code]';
$handler->display->display_options['fields']['postal_code']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['postal_code']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['postal_code']['hide_empty'] = TRUE;
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
$handler->display->display_options['fields']['nothing_2']['table'] = 'views';
$handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing_2']['label'] = '';
$handler->display->display_options['fields']['nothing_2']['alter']['text'] = '[name][street][province][postal_code]';
$handler->display->display_options['fields']['nothing_2']['element_type'] = 'h6';
$handler->display->display_options['fields']['nothing_2']['element_class'] = 'introduction';
$handler->display->display_options['fields']['nothing_2']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['nothing_2']['hide_empty'] = TRUE;
/* Field: Content: Start and End Dates */
$handler->display->display_options['fields']['cls_mcl_event_datetime']['id'] = 'cls_mcl_event_datetime';
$handler->display->display_options['fields']['cls_mcl_event_datetime']['table'] = 'field_data_cls_mcl_event_datetime';
$handler->display->display_options['fields']['cls_mcl_event_datetime']['field'] = 'cls_mcl_event_datetime';
$handler->display->display_options['fields']['cls_mcl_event_datetime']['label'] = '';
$handler->display->display_options['fields']['cls_mcl_event_datetime']['element_type'] = 'h6';
$handler->display->display_options['fields']['cls_mcl_event_datetime']['element_class'] = 'event-time';
$handler->display->display_options['fields']['cls_mcl_event_datetime']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['cls_mcl_event_datetime']['settings'] = array(
  'format_type' => 'time',
  'fromto' => 'value',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
);
/* Field: Content: URL */
$handler->display->display_options['fields']['cls_mcl_event_url']['id'] = 'cls_mcl_event_url';
$handler->display->display_options['fields']['cls_mcl_event_url']['table'] = 'field_data_cls_mcl_event_url';
$handler->display->display_options['fields']['cls_mcl_event_url']['field'] = 'cls_mcl_event_url';
$handler->display->display_options['fields']['cls_mcl_event_url']['label'] = '';
$handler->display->display_options['fields']['cls_mcl_event_url']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['cls_mcl_event_url']['alter']['text'] = 'More information';
$handler->display->display_options['fields']['cls_mcl_event_url']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['cls_mcl_event_url']['alter']['path'] = '[cls_mcl_event_url]';
$handler->display->display_options['fields']['cls_mcl_event_url']['alter']['absolute'] = TRUE;
$handler->display->display_options['fields']['cls_mcl_event_url']['alter']['external'] = TRUE;
$handler->display->display_options['fields']['cls_mcl_event_url']['alter']['link_class'] = 'external';
$handler->display->display_options['fields']['cls_mcl_event_url']['alter']['target'] = '_blank';
$handler->display->display_options['fields']['cls_mcl_event_url']['element_type'] = 'p';
$handler->display->display_options['fields']['cls_mcl_event_url']['element_class'] = 'event-more-information';
$handler->display->display_options['fields']['cls_mcl_event_url']['element_label_colon'] = FALSE;
/* Field: Global: Custom text */
$handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
$handler->display->display_options['fields']['nothing_1']['table'] = 'views';
$handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing_1']['label'] = '';
$handler->display->display_options['fields']['nothing_1']['alter']['text'] = '</div>
</div>';
$handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
/* Sort criterion: Content: Start and End Dates -  start date (cls_mcl_event_datetime) */
$handler->display->display_options['sorts']['cls_mcl_event_datetime_value']['id'] = 'cls_mcl_event_datetime_value';
$handler->display->display_options['sorts']['cls_mcl_event_datetime_value']['table'] = 'field_data_cls_mcl_event_datetime';
$handler->display->display_options['sorts']['cls_mcl_event_datetime_value']['field'] = 'cls_mcl_event_datetime_value';
/* Sort criterion: Content: Related Institutions (cls_mcl_event_institutions) */
$handler->display->display_options['sorts']['cls_mcl_event_institutions_value']['id'] = 'cls_mcl_event_institutions_value';
$handler->display->display_options['sorts']['cls_mcl_event_institutions_value']['table'] = 'field_data_cls_mcl_event_institutions';
$handler->display->display_options['sorts']['cls_mcl_event_institutions_value']['field'] = 'cls_mcl_event_institutions_value';
/* Contextual filter: Location: Distance / Proximity */
$handler->display->display_options['arguments']['distance']['id'] = 'distance';
$handler->display->display_options['arguments']['distance']['table'] = 'location';
$handler->display->display_options['arguments']['distance']['field'] = 'distance';
$handler->display->display_options['arguments']['distance']['default_action'] = 'default';
$handler->display->display_options['arguments']['distance']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['distance']['default_argument_options']['argument'] = 'US_00000_0';
$handler->display->display_options['arguments']['distance']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['distance']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['distance']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['distance']['search_units'] = 'mile';
$handler->display->display_options['filter_groups']['operator'] = 'OR';
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'cls_mcl_event' => 'cls_mcl_event',
);
$handler->display->display_options['filters']['type']['group'] = 1;
/* Filter criterion: Content: Start and End Dates -  start date (cls_mcl_event_datetime) */
$handler->display->display_options['filters']['cls_mcl_event_datetime_value']['id'] = 'cls_mcl_event_datetime_value';
$handler->display->display_options['filters']['cls_mcl_event_datetime_value']['table'] = 'field_data_cls_mcl_event_datetime';
$handler->display->display_options['filters']['cls_mcl_event_datetime_value']['field'] = 'cls_mcl_event_datetime_value';
$handler->display->display_options['filters']['cls_mcl_event_datetime_value']['operator'] = '>=';
$handler->display->display_options['filters']['cls_mcl_event_datetime_value']['form_type'] = 'date_text';
$handler->display->display_options['filters']['cls_mcl_event_datetime_value']['default_date'] = 'now';

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'block_1');
