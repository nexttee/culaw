<?php

$view = new view();
$view->name = 'cls_mcl_dashboard_faculty_all';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'cls_mcl_faculty';
$view->human_name = 'My Columbia Law: Dashboard: Faculty (All)';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'My Columbia Law: Dashboard: Faculty (All)';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '3';
$handler->display->display_options['style_plugin'] = 'jcarousel';
$handler->display->display_options['style_options']['wrap'] = '0';
$handler->display->display_options['style_options']['visible'] = '';
$handler->display->display_options['style_options']['auto'] = '0';
$handler->display->display_options['style_options']['autoPause'] = 1;
$handler->display->display_options['style_options']['easing'] = '';
$handler->display->display_options['style_options']['vertical'] = 0;
$handler->display->display_options['style_options']['ajax'] = 1;
$handler->display->display_options['row_plugin'] = 'fields';
/* Field: CLS MCL Faculty: Url */
$handler->display->display_options['fields']['url']['id'] = 'url';
$handler->display->display_options['fields']['url']['table'] = 'cls_mcl_faculty';
$handler->display->display_options['fields']['url']['field'] = 'url';
$handler->display->display_options['fields']['url']['label'] = '';
$handler->display->display_options['fields']['url']['exclude'] = TRUE;
$handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
/* Field: CLS MCL Faculty: First_name */
$handler->display->display_options['fields']['first_name']['id'] = 'first_name';
$handler->display->display_options['fields']['first_name']['table'] = 'cls_mcl_faculty';
$handler->display->display_options['fields']['first_name']['field'] = 'first_name';
$handler->display->display_options['fields']['first_name']['label'] = '';
$handler->display->display_options['fields']['first_name']['exclude'] = TRUE;
$handler->display->display_options['fields']['first_name']['element_label_colon'] = FALSE;
/* Field: CLS MCL Faculty: Last_name */
$handler->display->display_options['fields']['last_name']['id'] = 'last_name';
$handler->display->display_options['fields']['last_name']['table'] = 'cls_mcl_faculty';
$handler->display->display_options['fields']['last_name']['field'] = 'last_name';
$handler->display->display_options['fields']['last_name']['label'] = '';
$handler->display->display_options['fields']['last_name']['exclude'] = TRUE;
$handler->display->display_options['fields']['last_name']['element_label_colon'] = FALSE;
/* Field: CLS MCL Faculty: Middle_name */
$handler->display->display_options['fields']['middle_name']['id'] = 'middle_name';
$handler->display->display_options['fields']['middle_name']['table'] = 'cls_mcl_faculty';
$handler->display->display_options['fields']['middle_name']['field'] = 'middle_name';
$handler->display->display_options['fields']['middle_name']['label'] = '';
$handler->display->display_options['fields']['middle_name']['exclude'] = TRUE;
$handler->display->display_options['fields']['middle_name']['element_label_colon'] = FALSE;
/* Field: CLS MCL Faculty: Suffix */
$handler->display->display_options['fields']['suffix']['id'] = 'suffix';
$handler->display->display_options['fields']['suffix']['table'] = 'cls_mcl_faculty';
$handler->display->display_options['fields']['suffix']['field'] = 'suffix';
$handler->display->display_options['fields']['suffix']['label'] = '';
$handler->display->display_options['fields']['suffix']['exclude'] = TRUE;
$handler->display->display_options['fields']['suffix']['element_label_colon'] = FALSE;
/* Field: CLS MCL Faculty: Image */
$handler->display->display_options['fields']['image']['id'] = 'image';
$handler->display->display_options['fields']['image']['table'] = 'cls_mcl_faculty';
$handler->display->display_options['fields']['image']['field'] = 'image';
$handler->display->display_options['fields']['image']['label'] = '';
$handler->display->display_options['fields']['image']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['image']['alter']['text'] = '<a href="[url]" target="_blank"><img src="[image]" width="68" height="91" /></a>';
$handler->display->display_options['fields']['image']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['image']['hide_empty'] = TRUE;
/* Field: Name (Not yet trimmed) */
$handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
$handler->display->display_options['fields']['nothing_1']['table'] = 'views';
$handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Name (Not yet trimmed)';
$handler->display->display_options['fields']['nothing_1']['label'] = '';
$handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
$handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[first_name] [middle_name] [last_name] [suffix]';
$handler->display->display_options['fields']['nothing_1']['alter']['trim_whitespace'] = TRUE;
$handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
/* Field: Name */
$handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
$handler->display->display_options['fields']['nothing_2']['table'] = 'views';
$handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing_2']['ui_name'] = 'Name';
$handler->display->display_options['fields']['nothing_2']['label'] = '';
$handler->display->display_options['fields']['nothing_2']['alter']['text'] = '<a href="[url]" target="_blank">[nothing_1]</a>';
$handler->display->display_options['fields']['nothing_2']['element_label_colon'] = FALSE;
/* Field: CLS MCL Faculty: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'cls_mcl_faculty';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['max_length'] = '100';
$handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
/* Field: View profile and courses */
$handler->display->display_options['fields']['nothing']['id'] = 'nothing';
$handler->display->display_options['fields']['nothing']['table'] = 'views';
$handler->display->display_options['fields']['nothing']['field'] = 'nothing';
$handler->display->display_options['fields']['nothing']['ui_name'] = 'View profile and courses';
$handler->display->display_options['fields']['nothing']['label'] = '';
$handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="[url]" target="_blank">View profile and courses</a>';
$handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'block_1');
