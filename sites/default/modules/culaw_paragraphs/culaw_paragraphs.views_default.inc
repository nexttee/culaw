<?php
/**
 * @file
 * culaw_paragraphs.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function culaw_paragraphs_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'internal_feeds';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Internal Feeds';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Internal Feeds';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Start and End Dates -  start date (cls_mcl_event_datetime) */
  $handler->display->display_options['sorts']['cls_mcl_event_datetime_value']['id'] = 'cls_mcl_event_datetime_value';
  $handler->display->display_options['sorts']['cls_mcl_event_datetime_value']['table'] = 'field_data_cls_mcl_event_datetime';
  $handler->display->display_options['sorts']['cls_mcl_event_datetime_value']['field'] = 'cls_mcl_event_datetime_value';
  $handler->display->display_options['sorts']['cls_mcl_event_datetime_value']['expose']['label'] = 'Start and End Dates -  start date (cls_mcl_event_datetime)';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: News Page */
  $handler = $view->new_display('page', 'News Page', 'page');
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['path'] = 'internal-feeds/news/%';

  /* Display: Event Page */
  $handler = $view->new_display('page', 'Event Page', 'page_1');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Start and End Dates -  start date (cls_mcl_event_datetime) */
  $handler->display->display_options['filters']['cls_mcl_event_datetime_value']['id'] = 'cls_mcl_event_datetime_value';
  $handler->display->display_options['filters']['cls_mcl_event_datetime_value']['table'] = 'field_data_cls_mcl_event_datetime';
  $handler->display->display_options['filters']['cls_mcl_event_datetime_value']['field'] = 'cls_mcl_event_datetime_value';
  $handler->display->display_options['filters']['cls_mcl_event_datetime_value']['operator'] = '>=';
  $handler->display->display_options['path'] = 'internal-feeds/event/%';
  $export['internal_feeds'] = $view;

  return $export;
}
