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
  $view->name = 'taxonomy_term_display';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Taxonomy Term Display';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Taxonomy Term Display';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_media_file']['id'] = 'field_media_file';
  $handler->display->display_options['fields']['field_media_file']['table'] = 'field_data_field_media_file';
  $handler->display->display_options['fields']['field_media_file']['field'] = 'field_media_file';
  $handler->display->display_options['fields']['field_media_file']['label'] = '';
  $handler->display->display_options['fields']['field_media_file']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_media_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_media_file']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_media_file']['settings'] = array(
    'file_view_mode' => 'default',
  );
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'backgrounds' => 'backgrounds',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'taxonomy-term-display';
  $export['taxonomy_term_display'] = $view;

  $view = new view();
  $view->name = 'views_field_formatter_for_entity_taxonomy_term';
  $view->description = '';
  $view->tag = 'views_field_formatter';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Views field formatter for entity Taxonomy term';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['hide_admin_links'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_media_file']['id'] = 'field_media_file';
  $handler->display->display_options['fields']['field_media_file']['table'] = 'field_data_field_media_file';
  $handler->display->display_options['fields']['field_media_file']['field'] = 'field_media_file';
  $handler->display->display_options['fields']['field_media_file']['label'] = '';
  $handler->display->display_options['fields']['field_media_file']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_media_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_media_file']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_media_file']['settings'] = array(
    'file_view_mode' => 'default',
  );
  /* Contextual filter: This is the field item value placeholder. */
  $handler->display->display_options['arguments']['null']['id'] = 'null';
  $handler->display->display_options['arguments']['null']['table'] = 'views';
  $handler->display->display_options['arguments']['null']['field'] = 'null';
  $handler->display->display_options['arguments']['null']['ui_name'] = 'This is the field item value placeholder.';
  $handler->display->display_options['arguments']['null']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['null']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: This is the entity ID placeholder. */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['ui_name'] = 'This is the entity ID placeholder.';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: This is the item delta placeholder. */
  $handler->display->display_options['arguments']['null_1']['id'] = 'null_1';
  $handler->display->display_options['arguments']['null_1']['table'] = 'views';
  $handler->display->display_options['arguments']['null_1']['field'] = 'null';
  $handler->display->display_options['arguments']['null_1']['ui_name'] = 'This is the item delta placeholder.';
  $handler->display->display_options['arguments']['null_1']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['null_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null_1']['summary_options']['items_per_page'] = '25';
  $export['views_field_formatter_for_entity_taxonomy_term'] = $view;

  return $export;
}
