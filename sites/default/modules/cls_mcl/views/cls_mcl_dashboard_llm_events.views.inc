<?php

$view = new view;
$view->name = 'cls_mcl_dashboard_llm_events';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'My Columbia Law/LL.M. Dashboard: LL.M. Events';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'My Columbia Law/LL.M. Dashboard: LL.M. Events';
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['query_comment'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '5';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'fields';
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['empty'] = FALSE;
$handler->display->display_options['empty']['area']['content'] = '<h3 style="font-size: 24px; font-family: Georgia,\'Times New Roman\',Times,serif; margin-bottom: 25px; margin-left: -2px; margin-top: -4px; font-weight: normal; color: rgb(138, 138, 138);">Upcoming Events</h3>
<div style="margin-bottom: 10px;" class="threecol alpha omega"><div class="calendar-item"><div class="fourcol alpha omega"><div class="calendar-item"><div class="icon"><div style="font-size: 9.5px; padding: 1px 0" class="month">SEP</div><div class="day">30</div></div><h5 style="margin-bottom: 10px"><a target="_blank" href="#">Sample Event</a></h5><!-- <h6 style="margin-bottom: 0;" class="introduction">Los Angeles</h6> --><h6 style="margin-bottom: 10px;" class="introduction"><em>1 p.m.</em></h6><div class="info"><p><a target="_blank" href="#">More information</a></p></div></div></div></div></div><div style="margin-bottom: 10px;" class="threecol alpha omega"><div class="calendar-item"><div class="fourcol alpha omega"><div class="calendar-item"><div class="icon"><div style="font-size: 9.5px; padding: 1px 0" class="month">SEP</div><div class="day">30</div></div><h5 style="margin-bottom: 10px"><a target="_blank" href="#">Sample Event</a></h5><!-- <h6 style="margin-bottom: 0;" class="introduction">Los Angeles</h6> --><h6 style="margin-bottom: 10px;" class="introduction"><em>10 a.m.</em></h6><div class="info"><p><a target="_blank" href="#">More information</a></p></div></div></div></div></div>';
$handler->display->display_options['empty']['area']['format'] = 'full_html';
$handler->display->display_options['empty']['area']['tokenize'] = 0;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
$handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['title']['alter']['trim'] = 0;
$handler->display->display_options['fields']['title']['alter']['html'] = 0;
$handler->display->display_options['fields']['title']['hide_empty'] = 0;
$handler->display->display_options['fields']['title']['empty_zero'] = 0;
$handler->display->display_options['fields']['title']['link_to_node'] = 1;
/* Sort criterion: Content: Post date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'node';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Nid */
$handler->display->display_options['filters']['nid']['id'] = 'nid';
$handler->display->display_options['filters']['nid']['table'] = 'node';
$handler->display->display_options['filters']['nid']['field'] = 'nid';
$handler->display->display_options['filters']['nid']['value']['value'] = '0';

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'block');
