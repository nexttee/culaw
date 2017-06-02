<?php

$view = new view();
$view->name = 'cls_mcl_dashboard_centers';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'cls_mcl_center';
$view->human_name = 'My Columbia Law: Dashboard: Centers';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'My Columbia Law: Dashboard: Centers';
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
/* Field: CLS MCL Center: Url */
$handler->display->display_options['fields']['url']['id'] = 'url';
$handler->display->display_options['fields']['url']['table'] = 'cls_mcl_center';
$handler->display->display_options['fields']['url']['field'] = 'url';
$handler->display->display_options['fields']['url']['label'] = '';
$handler->display->display_options['fields']['url']['exclude'] = TRUE;
$handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
/* Field: CLS MCL Center: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'cls_mcl_center';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['path'] = '[url]';
$handler->display->display_options['fields']['title']['alter']['absolute'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['external'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['target'] = '_blank';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
/* Sort criterion: CLS MCL Center: Title */
$handler->display->display_options['sorts']['title']['id'] = 'title';
$handler->display->display_options['sorts']['title']['table'] = 'cls_mcl_center';
$handler->display->display_options['sorts']['title']['field'] = 'title';

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'block');
