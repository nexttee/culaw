<?php

$view = new view;
$view->name = 'cls_mcl_dashboard_courses';
$view->description = '';
$view->tag = 'cls_mcl';
$view->base_table = 'cls_courses_course';
$view->human_name = 'My Columbia Law/LL.M. Dashboard: Courses';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'My Columbia Law/LL.M. Dashboard: Courses';
$handler->display->display_options['css_class'] = 'view-cls-mcl-dashboard-courses';
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['query_comment'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '12';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'jcarousel';
$handler->display->display_options['style_options']['wrap'] = '0';
$handler->display->display_options['style_options']['visible'] = '';
$handler->display->display_options['style_options']['auto'] = '0';
$handler->display->display_options['style_options']['autoPause'] = 1;
$handler->display->display_options['style_options']['easing'] = '';
$handler->display->display_options['style_options']['vertical'] = 0;
$handler->display->display_options['row_plugin'] = 'fields';
/* Field: CLS MCL Course: Cls mcl course ID */
$handler->display->display_options['fields']['number']['id'] = 'number';
$handler->display->display_options['fields']['number']['table'] = 'cls_courses_course';
$handler->display->display_options['fields']['number']['field'] = 'number';
$handler->display->display_options['fields']['number']['label'] = '';
$handler->display->display_options['fields']['number']['exclude'] = TRUE;
$handler->display->display_options['fields']['number']['alter']['alter_text'] = 1;
$handler->display->display_options['fields']['number']['alter']['text'] = '/courses/[number]';
$handler->display->display_options['fields']['number']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['number']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['number']['alter']['external'] = 0;
$handler->display->display_options['fields']['number']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['number']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['number']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['number']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['number']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['number']['alter']['more_link'] = 0;
$handler->display->display_options['fields']['number']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['number']['alter']['trim'] = 0;
$handler->display->display_options['fields']['number']['alter']['html'] = 0;
$handler->display->display_options['fields']['number']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['number']['element_default_classes'] = 1;
$handler->display->display_options['fields']['number']['hide_empty'] = 0;
$handler->display->display_options['fields']['number']['empty_zero'] = 0;
$handler->display->display_options['fields']['number']['hide_alter_empty'] = 1;
/* Field: CLS MCL Course: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'cls_courses_course';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['label'] = '';
$handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['name']['alter']['make_link'] = 1;
$handler->display->display_options['fields']['name']['alter']['path'] = '[number]';
$handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['name']['alter']['external'] = 1;
$handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['name']['alter']['target'] = '_blank';
$handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['name']['alter']['more_link'] = 0;
$handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['name']['alter']['trim'] = 0;
$handler->display->display_options['fields']['name']['alter']['html'] = 0;
$handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['name']['element_default_classes'] = 1;
$handler->display->display_options['fields']['name']['hide_empty'] = 0;
$handler->display->display_options['fields']['name']['empty_zero'] = 0;
$handler->display->display_options['fields']['name']['hide_alter_empty'] = 1;
/* Field: CLS MCL Course: Course Faculty */
$handler->display->display_options['fields']['faculty']['id'] = 'faculty';
$handler->display->display_options['fields']['faculty']['table'] = 'cls_courses_course';
$handler->display->display_options['fields']['faculty']['field'] = 'faculty';
$handler->display->display_options['fields']['faculty']['label'] = '';
$handler->display->display_options['fields']['faculty']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['faculty']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['faculty']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['faculty']['alter']['external'] = 0;
$handler->display->display_options['fields']['faculty']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['faculty']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['faculty']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['faculty']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['faculty']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['faculty']['alter']['more_link'] = 0;
$handler->display->display_options['fields']['faculty']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['faculty']['alter']['trim'] = 0;
$handler->display->display_options['fields']['faculty']['alter']['html'] = 0;
$handler->display->display_options['fields']['faculty']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['faculty']['element_default_classes'] = 1;
$handler->display->display_options['fields']['faculty']['hide_empty'] = 0;
$handler->display->display_options['fields']['faculty']['empty_zero'] = 0;
$handler->display->display_options['fields']['faculty']['hide_alter_empty'] = 1;
/* Field: CLS MCL Course: Offering description */
$handler->display->display_options['fields']['offering_description']['id'] = 'offering_description';
$handler->display->display_options['fields']['offering_description']['table'] = 'cls_courses_course';
$handler->display->display_options['fields']['offering_description']['field'] = 'offering_description';
$handler->display->display_options['fields']['offering_description']['label'] = '';
$handler->display->display_options['fields']['offering_description']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['offering_description']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['offering_description']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['offering_description']['alter']['external'] = 0;
$handler->display->display_options['fields']['offering_description']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['offering_description']['alter']['trim_whitespace'] = 1;
$handler->display->display_options['fields']['offering_description']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['offering_description']['alter']['max_length'] = '190';
$handler->display->display_options['fields']['offering_description']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['offering_description']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['offering_description']['alter']['more_link'] = 0;
$handler->display->display_options['fields']['offering_description']['alter']['strip_tags'] = 1;
$handler->display->display_options['fields']['offering_description']['alter']['trim'] = 1;
$handler->display->display_options['fields']['offering_description']['alter']['html'] = 0;
$handler->display->display_options['fields']['offering_description']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['offering_description']['element_default_classes'] = 1;
$handler->display->display_options['fields']['offering_description']['hide_empty'] = 0;
$handler->display->display_options['fields']['offering_description']['empty_zero'] = 0;
$handler->display->display_options['fields']['offering_description']['hide_alter_empty'] = 1;
/* Sort criterion: Global: Random */
$handler->display->display_options['sorts']['random']['id'] = 'random';
$handler->display->display_options['sorts']['random']['table'] = 'views';
$handler->display->display_options['sorts']['random']['field'] = 'random';
/* Sort criterion: CLS MCL Course: Name */
$handler->display->display_options['sorts']['name']['id'] = 'name';
$handler->display->display_options['sorts']['name']['table'] = 'cls_courses_course';
$handler->display->display_options['sorts']['name']['field'] = 'name';
/* Contextual filter: Global: Null */
$handler->display->display_options['arguments']['null']['id'] = 'null';
$handler->display->display_options['arguments']['null']['table'] = 'views';
$handler->display->display_options['arguments']['null']['field'] = 'null';
$handler->display->display_options['arguments']['null']['default_action'] = 'default';
$handler->display->display_options['arguments']['null']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['null']['default_argument_options']['argument'] = '26';
$handler->display->display_options['arguments']['null']['default_argument_skip_url'] = 0;
$handler->display->display_options['arguments']['null']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['null']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['null']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['null']['must_not_be'] = 0;
/* Contextual filter: Global: Null */
$handler->display->display_options['arguments']['null_1']['id'] = 'null_1';
$handler->display->display_options['arguments']['null_1']['table'] = 'views';
$handler->display->display_options['arguments']['null_1']['field'] = 'null';
$handler->display->display_options['arguments']['null_1']['default_action'] = 'default';
$handler->display->display_options['arguments']['null_1']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['null_1']['default_argument_options']['argument'] = 'R';
$handler->display->display_options['arguments']['null_1']['default_argument_skip_url'] = 0;
$handler->display->display_options['arguments']['null_1']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['null_1']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['null_1']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['null_1']['must_not_be'] = 0;
/* Contextual filter: Global: Null */
$handler->display->display_options['arguments']['null_2']['id'] = 'null_2';
$handler->display->display_options['arguments']['null_2']['table'] = 'views';
$handler->display->display_options['arguments']['null_2']['field'] = 'null';
$handler->display->display_options['arguments']['null_2']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['null_2']['default_argument_skip_url'] = 0;
$handler->display->display_options['arguments']['null_2']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['null_2']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['null_2']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['null_2']['must_not_be'] = 0;
/* Filter criterion: CLS MCL Course: Course Categories */
$handler->display->display_options['filters']['categories']['id'] = 'categories';
$handler->display->display_options['filters']['categories']['table'] = 'cls_courses_course';
$handler->display->display_options['filters']['categories']['field'] = 'categories';
$handler->display->display_options['filters']['categories']['value'] = array(
  '%3' => '%3',
);
/* Filter criterion: CLS MCL Course: Hide_from_browse */
$handler->display->display_options['filters']['hide_from_browse']['id'] = 'hide_from_browse';
$handler->display->display_options['filters']['hide_from_browse']['table'] = 'cls_courses_course';
$handler->display->display_options['filters']['hide_from_browse']['field'] = 'hide_from_browse';
$handler->display->display_options['filters']['hide_from_browse']['value']['value'] = '0';
/* Filter criterion: CLS MCL Course: Offering description */
$handler->display->display_options['filters']['offering_description']['id'] = 'offering_description';
$handler->display->display_options['filters']['offering_description']['table'] = 'cls_courses_course';
$handler->display->display_options['filters']['offering_description']['field'] = 'offering_description';
$handler->display->display_options['filters']['offering_description']['operator'] = 'longerthan';
$handler->display->display_options['filters']['offering_description']['value'] = '50';
/* Filter criterion: CLS MCL Course: Course Faculty */
$handler->display->display_options['filters']['faculty']['id'] = 'faculty';
$handler->display->display_options['filters']['faculty']['table'] = 'cls_courses_course';
$handler->display->display_options['filters']['faculty']['field'] = 'faculty';
$handler->display->display_options['filters']['faculty']['operator'] = 'longerthan';
$handler->display->display_options['filters']['faculty']['value'] = '2';
/* Filter criterion: CLS MCL Course: Course Categories */
$handler->display->display_options['filters']['categories_1']['id'] = 'categories_1';
$handler->display->display_options['filters']['categories_1']['table'] = 'cls_courses_course';
$handler->display->display_options['filters']['categories_1']['field'] = 'categories';
$handler->display->display_options['filters']['categories_1']['operator'] = 'not in';
$handler->display->display_options['filters']['categories_1']['value'] = array(
  '%1' => '%1',
);
/* Filter criterion: CLS MCL Course: Level */
$handler->display->display_options['filters']['level']['id'] = 'level';
$handler->display->display_options['filters']['level']['table'] = 'cls_courses_course';
$handler->display->display_options['filters']['level']['field'] = 'level';
$handler->display->display_options['filters']['level']['operator'] = '!=';
$handler->display->display_options['filters']['level']['value'] = '%2';

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'block');
$handler->display->display_options['block_description'] = 'My Columbia Law/LL.M. Dashboard: Courses';
