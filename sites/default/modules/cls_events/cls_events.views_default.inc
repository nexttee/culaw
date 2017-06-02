<?php
/**
 * @file
 * cls_events.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function cls_events_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'event_views';
  $view->description = 'Views for displaying specific calendar content on microsites';
  $view->tag = 'calendar';
  $view->base_table = 'xml';
  $view->human_name = 'Event Views';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Event List View';
  $handler->display->display_options['css_class'] = 'alumni-microsite';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=%';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'jcarousel';
  $handler->display->display_options['style_options']['wrap'] = '0';
  $handler->display->display_options['style_options']['visible'] = '3';
  $handler->display->display_options['style_options']['auto'] = '0';
  $handler->display->display_options['style_options']['autoPause'] = 1;
  $handler->display->display_options['style_options']['easing'] = '';
  $handler->display->display_options['style_options']['vertical'] = 0;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<style>
.jcarousel-skin-default .jcarousel-container-horizontal { padding-left: 30px !important; }
.jcarousel-skin-default .threecol {width: 150px;}
div.event-left {float: right; text-align: left !important; width: 100px;}
</style>
<h3>Upcoming Events</h3>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Field: id: Text */
  $handler->display->display_options['fields']['text_1']['id'] = 'text_1';
  $handler->display->display_options['fields']['text_1']['table'] = 'xml';
  $handler->display->display_options['fields']['text_1']['field'] = 'text';
  $handler->display->display_options['fields']['text_1']['label'] = '';
  $handler->display->display_options['fields']['text_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['text_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text_1']['xpath_selector'] = 'id';
  $handler->display->display_options['fields']['text_1']['multiple'] = 0;
  /* Field: startMonth: Text */
  $handler->display->display_options['fields']['text_2']['id'] = 'text_2';
  $handler->display->display_options['fields']['text_2']['table'] = 'xml';
  $handler->display->display_options['fields']['text_2']['field'] = 'text';
  $handler->display->display_options['fields']['text_2']['label'] = '';
  $handler->display->display_options['fields']['text_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['text_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text_2']['xpath_selector'] = 'startMonth';
  $handler->display->display_options['fields']['text_2']['multiple'] = 0;
  /* Field: startDay: Text */
  $handler->display->display_options['fields']['text_3']['id'] = 'text_3';
  $handler->display->display_options['fields']['text_3']['table'] = 'xml';
  $handler->display->display_options['fields']['text_3']['field'] = 'text';
  $handler->display->display_options['fields']['text_3']['label'] = '';
  $handler->display->display_options['fields']['text_3']['exclude'] = TRUE;
  $handler->display->display_options['fields']['text_3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text_3']['xpath_selector'] = 'startDay';
  $handler->display->display_options['fields']['text_3']['multiple'] = 0;
  /* Field: title: Text */
  $handler->display->display_options['fields']['text']['id'] = 'text';
  $handler->display->display_options['fields']['text']['table'] = 'xml';
  $handler->display->display_options['fields']['text']['field'] = 'text';
  $handler->display->display_options['fields']['text']['label'] = '';
  $handler->display->display_options['fields']['text']['exclude'] = TRUE;
  $handler->display->display_options['fields']['text']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['text']['alter']['path'] = 'http://www.law.columbia.edu/calendar?main.rtresume=%2Fcalendar&main.cal=we&main.id=[text_1]&main.ctrl=eventmgr.detail&main.view=calendar.detail';
  $handler->display->display_options['fields']['text']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['text']['alter']['max_length'] = '60';
  $handler->display->display_options['fields']['text']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['text']['element_type'] = 'h5';
  $handler->display->display_options['fields']['text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text']['xpath_selector'] = 'title';
  $handler->display->display_options['fields']['text']['multiple'] = 0;
  /* Field: location: Text */
  $handler->display->display_options['fields']['text_4']['id'] = 'text_4';
  $handler->display->display_options['fields']['text_4']['table'] = 'xml';
  $handler->display->display_options['fields']['text_4']['field'] = 'text';
  $handler->display->display_options['fields']['text_4']['label'] = '';
  $handler->display->display_options['fields']['text_4']['exclude'] = TRUE;
  $handler->display->display_options['fields']['text_4']['element_type'] = 'h6';
  $handler->display->display_options['fields']['text_4']['element_class'] = 'introduction';
  $handler->display->display_options['fields']['text_4']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text_4']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['text_4']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['text_4']['xpath_selector'] = 'location';
  $handler->display->display_options['fields']['text_4']['multiple'] = 0;
  /* Field: timeLine: Text */
  $handler->display->display_options['fields']['text_5']['id'] = 'text_5';
  $handler->display->display_options['fields']['text_5']['table'] = 'xml';
  $handler->display->display_options['fields']['text_5']['field'] = 'text';
  $handler->display->display_options['fields']['text_5']['label'] = '';
  $handler->display->display_options['fields']['text_5']['exclude'] = TRUE;
  $handler->display->display_options['fields']['text_5']['element_type'] = 'h6';
  $handler->display->display_options['fields']['text_5']['element_class'] = 'introduction';
  $handler->display->display_options['fields']['text_5']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text_5']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['text_5']['xpath_selector'] = 'timeLine';
  $handler->display->display_options['fields']['text_5']['multiple'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="threecol alpha omega">
<div class="calendar-item">
<div class="icon">
<div class="month">[text_2]</div>
<div class="day">[text_3]</div>
</div>
<div class="event-left">
<h5>[text]</h5>
<h6 class="introduction">[text_5]</h6>
</div>
</div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'More information';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'http://www.law.columbia.edu/calendar?main.rtresume=%2Fcalendar&main.cal=we&main.id=[text_1]&main.ctrl=eventmgr.detail&main.view=calendar.detail';
  $handler->display->display_options['fields']['nothing_1']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;

  /* Display: TEMPLATE Event Carousel Block */
  $handler = $view->new_display('block', 'TEMPLATE Event Carousel Block', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event Carousel View';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=%';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<style>
.jcarousel-skin-default .jcarousel-container-horizontal { padding-left: 30px !important; }
.jcarousel-skin-default .threecol {width: 150px;}
div.event-left {float: right; text-align: left !important; width: 100px;}
</style>
<hr class="dashed"><h3>Featured Events</h3>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['block_description'] = 'Event Carousel View';

  /* Display: TEMPLATE Event List Block */
  $handler = $view->new_display('block', 'TEMPLATE Event List Block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event List View';
  $handler->display->display_options['display_description'] = 'Template for the event list view';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=%';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'date',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<h2>Upcoming Events</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: id: Text */
  $handler->display->display_options['fields']['text_1']['id'] = 'text_1';
  $handler->display->display_options['fields']['text_1']['table'] = 'xml';
  $handler->display->display_options['fields']['text_1']['field'] = 'text';
  $handler->display->display_options['fields']['text_1']['label'] = '';
  $handler->display->display_options['fields']['text_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['text_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text_1']['xpath_selector'] = 'id';
  $handler->display->display_options['fields']['text_1']['multiple'] = 0;
  /* Field: title: Text */
  $handler->display->display_options['fields']['text']['id'] = 'text';
  $handler->display->display_options['fields']['text']['table'] = 'xml';
  $handler->display->display_options['fields']['text']['field'] = 'text';
  $handler->display->display_options['fields']['text']['label'] = '';
  $handler->display->display_options['fields']['text']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['text']['alter']['path'] = 'http://www.law.columbia.edu/calendar?main.rtresume=%2Fcalendar&main.cal=we&main.id=[text_1]&main.ctrl=eventmgr.detail&main.view=calendar.detail';
  $handler->display->display_options['fields']['text']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['text']['element_type'] = 'h5';
  $handler->display->display_options['fields']['text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text']['xpath_selector'] = 'title';
  $handler->display->display_options['fields']['text']['multiple'] = 0;
  /* Field: startDate: Date */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'xml';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  $handler->display->display_options['fields']['date']['label'] = '';
  $handler->display->display_options['fields']['date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['date']['xpath_selector'] = 'startDate';
  $handler->display->display_options['fields']['date']['multiple'] = 0;
  $handler->display->display_options['fields']['date']['date_format'] = 'custom';
  $handler->display->display_options['fields']['date']['custom_date_format'] = 'l, F j, Y';
  /* Field: timeLine: Markup */
  $handler->display->display_options['fields']['markup']['id'] = 'markup';
  $handler->display->display_options['fields']['markup']['table'] = 'xml';
  $handler->display->display_options['fields']['markup']['field'] = 'markup';
  $handler->display->display_options['fields']['markup']['label'] = '';
  $handler->display->display_options['fields']['markup']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['markup']['xpath_selector'] = 'timeLine';
  $handler->display->display_options['fields']['markup']['multiple'] = 0;
  $handler->display->display_options['fields']['markup']['format'] = 'full_html';
  $handler->display->display_options['block_description'] = 'Event List View';

  /* Display: JD Admitted Event Carousel Block */
  $handler = $view->new_display('block', 'JD Admitted Event Carousel Block', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event Carousel View';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=admitted';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['block_description'] = 'JD Admitted Event Carousel View';

  /* Display: JD Admitted Event List Block */
  $handler = $view->new_display('block', 'JD Admitted Event List Block', 'block_3');
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=admitted';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'date',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<h2>Upcoming Events</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<hr /><p class="anchor-links"><a class="right" href="#top">Back to top</a></p>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: id: Text */
  $handler->display->display_options['fields']['text_1']['id'] = 'text_1';
  $handler->display->display_options['fields']['text_1']['table'] = 'xml';
  $handler->display->display_options['fields']['text_1']['field'] = 'text';
  $handler->display->display_options['fields']['text_1']['label'] = '';
  $handler->display->display_options['fields']['text_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['text_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text_1']['xpath_selector'] = 'id';
  $handler->display->display_options['fields']['text_1']['multiple'] = 0;
  /* Field: title: Text */
  $handler->display->display_options['fields']['text']['id'] = 'text';
  $handler->display->display_options['fields']['text']['table'] = 'xml';
  $handler->display->display_options['fields']['text']['field'] = 'text';
  $handler->display->display_options['fields']['text']['label'] = '';
  $handler->display->display_options['fields']['text']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['text']['alter']['path'] = 'http://www.law.columbia.edu/calendar?main.rtresume=%2Fcalendar&main.cal=we&main.id=[text_1]&main.ctrl=eventmgr.detail&main.view=calendar.detail';
  $handler->display->display_options['fields']['text']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['text']['element_type'] = 'h5';
  $handler->display->display_options['fields']['text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text']['xpath_selector'] = 'title';
  $handler->display->display_options['fields']['text']['multiple'] = 0;
  /* Field: startDate: Date */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'xml';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  $handler->display->display_options['fields']['date']['label'] = '';
  $handler->display->display_options['fields']['date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['date']['xpath_selector'] = 'startDate';
  $handler->display->display_options['fields']['date']['multiple'] = 0;
  $handler->display->display_options['fields']['date']['date_format'] = 'custom';
  $handler->display->display_options['fields']['date']['custom_date_format'] = 'l, F j, Y';
  /* Field: timeLine: Markup */
  $handler->display->display_options['fields']['markup']['id'] = 'markup';
  $handler->display->display_options['fields']['markup']['table'] = 'xml';
  $handler->display->display_options['fields']['markup']['field'] = 'markup';
  $handler->display->display_options['fields']['markup']['label'] = '';
  $handler->display->display_options['fields']['markup']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['markup']['xpath_selector'] = 'timeLine';
  $handler->display->display_options['fields']['markup']['multiple'] = 0;
  $handler->display->display_options['fields']['markup']['format'] = 'full_html';
  $handler->display->display_options['block_description'] = 'JD Admitted Event List View';

  /* Display: BLSA Event Carousel Block */
  $handler = $view->new_display('block', 'BLSA Event Carousel Block', 'block_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event Carousel View';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=blsa';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['block_description'] = 'BLSA Event Carousel View';

  /* Display: Career Services Event Carousel Block */
  $handler = $view->new_display('block', 'Career Services Event Carousel Block', 'block_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event Carousel View';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=career-services';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['label'] = 'Event Footer';
  $handler->display->display_options['footer']['area']['empty'] = TRUE;
  $handler->display->display_options['footer']['area']['content'] = '<div style="clear: both;"><a target="_blank" class="external" href="http://law.columbia.edu/calendar">View the full Columbia Law School calendar</a></div>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['block_description'] = 'Career Services Event Carousel View';

  /* Display: Law and Entrepreneurship Society Event Carousel Block */
  $handler = $view->new_display('block', 'Law and Entrepreneurship Society Event Carousel Block', 'block_6');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event Carousel View';
  $handler->display->display_options['display_description'] = 'Law and Entrepreneurship Society';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=cles';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['block_description'] = 'Law and Entrepreneurship Society Event Carousel View';

  /* Display: Chinese Event Carousel Block */
  $handler = $view->new_display('block', 'Chinese Event Carousel Block', 'block_7');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event Carousel View';
  $handler->display->display_options['display_description'] = 'Chinese Legal Studies';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=chinese';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['block_description'] = 'Chinese Event Carousel View';

  /* Display: Chinese Event List Block */
  $handler = $view->new_display('block', 'Chinese Event List Block', 'block_8');
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=chinese';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'date',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<h2>Upcoming Events</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: id: Text */
  $handler->display->display_options['fields']['text_1']['id'] = 'text_1';
  $handler->display->display_options['fields']['text_1']['table'] = 'xml';
  $handler->display->display_options['fields']['text_1']['field'] = 'text';
  $handler->display->display_options['fields']['text_1']['label'] = '';
  $handler->display->display_options['fields']['text_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['text_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text_1']['xpath_selector'] = 'id';
  $handler->display->display_options['fields']['text_1']['multiple'] = 0;
  /* Field: title: Text */
  $handler->display->display_options['fields']['text']['id'] = 'text';
  $handler->display->display_options['fields']['text']['table'] = 'xml';
  $handler->display->display_options['fields']['text']['field'] = 'text';
  $handler->display->display_options['fields']['text']['label'] = '';
  $handler->display->display_options['fields']['text']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['text']['alter']['path'] = 'http://www.law.columbia.edu/calendar?main.rtresume=%2Fcalendar&main.cal=we&main.id=[text_1]&main.ctrl=eventmgr.detail&main.view=calendar.detail';
  $handler->display->display_options['fields']['text']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['text']['element_type'] = 'h5';
  $handler->display->display_options['fields']['text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text']['xpath_selector'] = 'title';
  $handler->display->display_options['fields']['text']['multiple'] = 0;
  /* Field: startDate: Date */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'xml';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  $handler->display->display_options['fields']['date']['label'] = '';
  $handler->display->display_options['fields']['date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['date']['xpath_selector'] = 'startDate';
  $handler->display->display_options['fields']['date']['multiple'] = 0;
  $handler->display->display_options['fields']['date']['date_format'] = 'custom';
  $handler->display->display_options['fields']['date']['custom_date_format'] = 'l, F j, Y';
  /* Field: timeLine: Markup */
  $handler->display->display_options['fields']['markup']['id'] = 'markup';
  $handler->display->display_options['fields']['markup']['table'] = 'xml';
  $handler->display->display_options['fields']['markup']['field'] = 'markup';
  $handler->display->display_options['fields']['markup']['label'] = '';
  $handler->display->display_options['fields']['markup']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['markup']['xpath_selector'] = 'timeLine';
  $handler->display->display_options['fields']['markup']['multiple'] = 0;
  $handler->display->display_options['fields']['markup']['format'] = 'full_html';
  $handler->display->display_options['block_description'] = 'Chinese Event List View';

  /* Display: Chinese Past Event List Block */
  $handler = $view->new_display('block', 'Chinese Past Event List Block', 'block_9');
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=chinese&main.timeframe=past';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'date',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<h2>Past Events</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: id: Text */
  $handler->display->display_options['fields']['text_1']['id'] = 'text_1';
  $handler->display->display_options['fields']['text_1']['table'] = 'xml';
  $handler->display->display_options['fields']['text_1']['field'] = 'text';
  $handler->display->display_options['fields']['text_1']['label'] = '';
  $handler->display->display_options['fields']['text_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['text_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text_1']['xpath_selector'] = 'id';
  $handler->display->display_options['fields']['text_1']['multiple'] = 0;
  /* Field: title: Text */
  $handler->display->display_options['fields']['text']['id'] = 'text';
  $handler->display->display_options['fields']['text']['table'] = 'xml';
  $handler->display->display_options['fields']['text']['field'] = 'text';
  $handler->display->display_options['fields']['text']['label'] = '';
  $handler->display->display_options['fields']['text']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['text']['alter']['path'] = 'http://www.law.columbia.edu/calendar?main.rtresume=%2Fcalendar&main.cal=we&main.id=[text_1]&main.ctrl=eventmgr.detail&main.view=calendar.detail';
  $handler->display->display_options['fields']['text']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['text']['element_type'] = 'h5';
  $handler->display->display_options['fields']['text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text']['xpath_selector'] = 'title';
  $handler->display->display_options['fields']['text']['multiple'] = 0;
  /* Field: startDate: Date */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'xml';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  $handler->display->display_options['fields']['date']['label'] = '';
  $handler->display->display_options['fields']['date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['date']['xpath_selector'] = 'startDate';
  $handler->display->display_options['fields']['date']['multiple'] = 0;
  $handler->display->display_options['fields']['date']['date_format'] = 'custom';
  $handler->display->display_options['fields']['date']['custom_date_format'] = 'l, F j, Y';
  /* Field: timeLine: Markup */
  $handler->display->display_options['fields']['markup']['id'] = 'markup';
  $handler->display->display_options['fields']['markup']['table'] = 'xml';
  $handler->display->display_options['fields']['markup']['field'] = 'markup';
  $handler->display->display_options['fields']['markup']['label'] = '';
  $handler->display->display_options['fields']['markup']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['markup']['xpath_selector'] = 'timeLine';
  $handler->display->display_options['fields']['markup']['multiple'] = 0;
  $handler->display->display_options['fields']['markup']['format'] = 'full_html';
  $handler->display->display_options['block_description'] = 'Chinese Past Event List View';

  /* Display: CICIA Event Carousel Block */
  $handler = $view->new_display('block', 'CICIA Event Carousel Block', 'block_10');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event Carousel View';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=cicia';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['block_description'] = 'CICIA Event Carousel View';

  /* Display: CICIA Past Event List Block */
  $handler = $view->new_display('block', 'CICIA Past Event List Block', 'block_11');
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=cicia&main.timeframe=past';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'date',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<h2>Past Events</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: id: Text */
  $handler->display->display_options['fields']['text_1']['id'] = 'text_1';
  $handler->display->display_options['fields']['text_1']['table'] = 'xml';
  $handler->display->display_options['fields']['text_1']['field'] = 'text';
  $handler->display->display_options['fields']['text_1']['label'] = '';
  $handler->display->display_options['fields']['text_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['text_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text_1']['xpath_selector'] = 'id';
  $handler->display->display_options['fields']['text_1']['multiple'] = 0;
  /* Field: title: Text */
  $handler->display->display_options['fields']['text']['id'] = 'text';
  $handler->display->display_options['fields']['text']['table'] = 'xml';
  $handler->display->display_options['fields']['text']['field'] = 'text';
  $handler->display->display_options['fields']['text']['label'] = '';
  $handler->display->display_options['fields']['text']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['text']['alter']['path'] = 'http://www.law.columbia.edu/calendar?main.rtresume=%2Fcalendar&main.cal=we&main.id=[text_1]&main.ctrl=eventmgr.detail&main.view=calendar.detail';
  $handler->display->display_options['fields']['text']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['text']['element_type'] = 'h5';
  $handler->display->display_options['fields']['text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text']['xpath_selector'] = 'title';
  $handler->display->display_options['fields']['text']['multiple'] = 0;
  /* Field: startDate: Date */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'xml';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  $handler->display->display_options['fields']['date']['label'] = '';
  $handler->display->display_options['fields']['date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['date']['xpath_selector'] = 'startDate';
  $handler->display->display_options['fields']['date']['multiple'] = 0;
  $handler->display->display_options['fields']['date']['date_format'] = 'custom';
  $handler->display->display_options['fields']['date']['custom_date_format'] = 'l, F j, Y';
  /* Field: timeLine: Markup */
  $handler->display->display_options['fields']['markup']['id'] = 'markup';
  $handler->display->display_options['fields']['markup']['table'] = 'xml';
  $handler->display->display_options['fields']['markup']['field'] = 'markup';
  $handler->display->display_options['fields']['markup']['label'] = '';
  $handler->display->display_options['fields']['markup']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['markup']['xpath_selector'] = 'timeLine';
  $handler->display->display_options['fields']['markup']['multiple'] = 0;
  $handler->display->display_options['fields']['markup']['format'] = 'full_html';
  $handler->display->display_options['block_description'] = 'CICIA Past Event List View';

  /* Display: CICIA Event List Block */
  $handler = $view->new_display('block', 'CICIA Event List Block', 'block_12');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event List View';
  $handler->display->display_options['display_description'] = 'Template for the event list view';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=cicia';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'date',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<h2>Upcoming Events</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: id: Text */
  $handler->display->display_options['fields']['text_1']['id'] = 'text_1';
  $handler->display->display_options['fields']['text_1']['table'] = 'xml';
  $handler->display->display_options['fields']['text_1']['field'] = 'text';
  $handler->display->display_options['fields']['text_1']['label'] = '';
  $handler->display->display_options['fields']['text_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['text_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text_1']['xpath_selector'] = 'id';
  $handler->display->display_options['fields']['text_1']['multiple'] = 0;
  /* Field: title: Text */
  $handler->display->display_options['fields']['text']['id'] = 'text';
  $handler->display->display_options['fields']['text']['table'] = 'xml';
  $handler->display->display_options['fields']['text']['field'] = 'text';
  $handler->display->display_options['fields']['text']['label'] = '';
  $handler->display->display_options['fields']['text']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['text']['alter']['path'] = 'http://www.law.columbia.edu/calendar?main.rtresume=%2Fcalendar&main.cal=we&main.id=[text_1]&main.ctrl=eventmgr.detail&main.view=calendar.detail';
  $handler->display->display_options['fields']['text']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['text']['element_type'] = 'h5';
  $handler->display->display_options['fields']['text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text']['xpath_selector'] = 'title';
  $handler->display->display_options['fields']['text']['multiple'] = 0;
  /* Field: startDate: Date */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'xml';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  $handler->display->display_options['fields']['date']['label'] = '';
  $handler->display->display_options['fields']['date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['date']['xpath_selector'] = 'startDate';
  $handler->display->display_options['fields']['date']['multiple'] = 0;
  $handler->display->display_options['fields']['date']['date_format'] = 'custom';
  $handler->display->display_options['fields']['date']['custom_date_format'] = 'l, F j, Y';
  /* Field: timeLine: Markup */
  $handler->display->display_options['fields']['markup']['id'] = 'markup';
  $handler->display->display_options['fields']['markup']['table'] = 'xml';
  $handler->display->display_options['fields']['markup']['field'] = 'markup';
  $handler->display->display_options['fields']['markup']['label'] = '';
  $handler->display->display_options['fields']['markup']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['markup']['xpath_selector'] = 'timeLine';
  $handler->display->display_options['fields']['markup']['multiple'] = 0;
  $handler->display->display_options['fields']['markup']['format'] = 'full_html';
  $handler->display->display_options['block_description'] = 'CICIA Event List View';

  /* Display: Clerkships Event Carousel Block */
  $handler = $view->new_display('block', 'Clerkships Event Carousel Block', 'block_13');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event Carousel View';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=clerkships';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<style>
.jcarousel-skin-default .jcarousel-container-horizontal { padding-left: 30px !important; }
.jcarousel-skin-default .threecol {width: 150px;}
div.event-left {float: right; text-align: left !important; width: 100px;}
</style>
<hr class="dashed"><h3>Featured Events</h3>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['block_description'] = 'Clerkships Event Carousel View';

  /* Display: Climate Change Event Carousel Block */
  $handler = $view->new_display('block', 'Climate Change Event Carousel Block', 'block_14');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event Carousel View';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=climate-change';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<style>
.jcarousel-skin-default .jcarousel-container-horizontal { padding-left: 30px !important; }
.jcarousel-skin-default .threecol {width: 150px;}
div.event-left {float: right; text-align: left !important; width: 100px;}
</style>
<hr class="dashed"><h3>Upcoming Events</h3>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['block_description'] = 'Climate Change Event Carousel View';

  /* Display: Criminal Law Event List Block */
  $handler = $view->new_display('block', 'Criminal Law Event List Block', 'block_15');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event List View';
  $handler->display->display_options['display_description'] = 'Template for the event list view';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=criminal-law';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'date',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<h2>Upcoming Events</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: id: Text */
  $handler->display->display_options['fields']['text_1']['id'] = 'text_1';
  $handler->display->display_options['fields']['text_1']['table'] = 'xml';
  $handler->display->display_options['fields']['text_1']['field'] = 'text';
  $handler->display->display_options['fields']['text_1']['label'] = '';
  $handler->display->display_options['fields']['text_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['text_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text_1']['xpath_selector'] = 'id';
  $handler->display->display_options['fields']['text_1']['multiple'] = 0;
  /* Field: title: Text */
  $handler->display->display_options['fields']['text']['id'] = 'text';
  $handler->display->display_options['fields']['text']['table'] = 'xml';
  $handler->display->display_options['fields']['text']['field'] = 'text';
  $handler->display->display_options['fields']['text']['label'] = '';
  $handler->display->display_options['fields']['text']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['text']['alter']['path'] = 'http://www.law.columbia.edu/calendar?main.rtresume=%2Fcalendar&main.cal=we&main.id=[text_1]&main.ctrl=eventmgr.detail&main.view=calendar.detail';
  $handler->display->display_options['fields']['text']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['text']['element_type'] = 'h5';
  $handler->display->display_options['fields']['text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text']['xpath_selector'] = 'title';
  $handler->display->display_options['fields']['text']['multiple'] = 0;
  /* Field: startDate: Date */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'xml';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  $handler->display->display_options['fields']['date']['label'] = '';
  $handler->display->display_options['fields']['date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['date']['xpath_selector'] = 'startDate';
  $handler->display->display_options['fields']['date']['multiple'] = 0;
  $handler->display->display_options['fields']['date']['date_format'] = 'custom';
  $handler->display->display_options['fields']['date']['custom_date_format'] = 'l, F j, Y';
  /* Field: timeLine: Markup */
  $handler->display->display_options['fields']['markup']['id'] = 'markup';
  $handler->display->display_options['fields']['markup']['table'] = 'xml';
  $handler->display->display_options['fields']['markup']['field'] = 'markup';
  $handler->display->display_options['fields']['markup']['label'] = '';
  $handler->display->display_options['fields']['markup']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['markup']['xpath_selector'] = 'timeLine';
  $handler->display->display_options['fields']['markup']['multiple'] = 0;
  $handler->display->display_options['fields']['markup']['format'] = 'full_html';
  $handler->display->display_options['block_description'] = 'Criminal Law Event List View';

  /* Display: Criminal Law Past Event List Block */
  $handler = $view->new_display('block', 'Criminal Law Past Event List Block', 'block_16');
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=criminal-law&main.timeframe=past';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'date',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<h2>Past Events</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: id: Text */
  $handler->display->display_options['fields']['text_1']['id'] = 'text_1';
  $handler->display->display_options['fields']['text_1']['table'] = 'xml';
  $handler->display->display_options['fields']['text_1']['field'] = 'text';
  $handler->display->display_options['fields']['text_1']['label'] = '';
  $handler->display->display_options['fields']['text_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['text_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text_1']['xpath_selector'] = 'id';
  $handler->display->display_options['fields']['text_1']['multiple'] = 0;
  /* Field: title: Text */
  $handler->display->display_options['fields']['text']['id'] = 'text';
  $handler->display->display_options['fields']['text']['table'] = 'xml';
  $handler->display->display_options['fields']['text']['field'] = 'text';
  $handler->display->display_options['fields']['text']['label'] = '';
  $handler->display->display_options['fields']['text']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['text']['alter']['path'] = 'http://www.law.columbia.edu/calendar?main.rtresume=%2Fcalendar&main.cal=we&main.id=[text_1]&main.ctrl=eventmgr.detail&main.view=calendar.detail';
  $handler->display->display_options['fields']['text']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['text']['element_type'] = 'h5';
  $handler->display->display_options['fields']['text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text']['xpath_selector'] = 'title';
  $handler->display->display_options['fields']['text']['multiple'] = 0;
  /* Field: startDate: Date */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'xml';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  $handler->display->display_options['fields']['date']['label'] = '';
  $handler->display->display_options['fields']['date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['date']['xpath_selector'] = 'startDate';
  $handler->display->display_options['fields']['date']['multiple'] = 0;
  $handler->display->display_options['fields']['date']['date_format'] = 'custom';
  $handler->display->display_options['fields']['date']['custom_date_format'] = 'l, F j, Y';
  /* Field: timeLine: Markup */
  $handler->display->display_options['fields']['markup']['id'] = 'markup';
  $handler->display->display_options['fields']['markup']['table'] = 'xml';
  $handler->display->display_options['fields']['markup']['field'] = 'markup';
  $handler->display->display_options['fields']['markup']['label'] = '';
  $handler->display->display_options['fields']['markup']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['markup']['xpath_selector'] = 'timeLine';
  $handler->display->display_options['fields']['markup']['multiple'] = 0;
  $handler->display->display_options['fields']['markup']['format'] = 'full_html';
  $handler->display->display_options['block_description'] = 'Criminal Law Past Event List View';

  /* Display: Diversity Event Carousel Block */
  $handler = $view->new_display('block', 'Diversity Event Carousel Block', 'block_17');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event Carousel View';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=diversity';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<style>
.jcarousel-skin-default .jcarousel-container-horizontal { padding-left: 30px !important; }
.jcarousel-skin-default .threecol {width: 150px;}
div.event-left {float: right; text-align: left !important; width: 100px;}
</style>
<hr class="dashed"><h3>Featured Events</h3>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['block_description'] = 'Diversity Event Carousel View';

  /* Display: ELS Event Carousel Block */
  $handler = $view->new_display('block', 'ELS Event Carousel Block', 'block_18');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event Carousel View';
  $handler->display->display_options['display_description'] = 'Template for the event carousel view';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=els';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<style>
.jcarousel-skin-default .jcarousel-container-horizontal { padding-left: 30px !important; }
.jcarousel-skin-default .threecol {width: 150px;}
div.event-left {float: right; text-align: left !important; width: 100px;}
</style>
<hr class="dashed"><h3>Upcoming Events</h3>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['block_description'] = 'ELS Event Carousel View';

  /* Display: Federalist Society Event Carousel Block */
  $handler = $view->new_display('block', 'Federalist Society Event Carousel Block', 'block_19');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event Carousel View';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=federalist';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<style>
.jcarousel-skin-default .jcarousel-container-horizontal { padding-left: 30px !important; }
.jcarousel-skin-default .threecol {width: 150px;}
div.event-left {float: right; text-align: left !important; width: 100px;}
</style>
<hr class="dashed"><h3>Featured Events</h3>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<hr class="dashed"><h3>Upcoming Events</h3><p class="introduction">There are no upcoming events currently listed. Check back for updates.</p>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['block_description'] = 'Federalist Society Event Carousel View';

  /* Display: Federalist Society Past Event List Block */
  $handler = $view->new_display('block', 'Federalist Society Past Event List Block', 'block_20');
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=federalist&main.timeframe=past';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'date',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<h2>Past Events</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: id: Text */
  $handler->display->display_options['fields']['text_1']['id'] = 'text_1';
  $handler->display->display_options['fields']['text_1']['table'] = 'xml';
  $handler->display->display_options['fields']['text_1']['field'] = 'text';
  $handler->display->display_options['fields']['text_1']['label'] = '';
  $handler->display->display_options['fields']['text_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['text_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text_1']['xpath_selector'] = 'id';
  $handler->display->display_options['fields']['text_1']['multiple'] = 0;
  /* Field: title: Text */
  $handler->display->display_options['fields']['text']['id'] = 'text';
  $handler->display->display_options['fields']['text']['table'] = 'xml';
  $handler->display->display_options['fields']['text']['field'] = 'text';
  $handler->display->display_options['fields']['text']['label'] = '';
  $handler->display->display_options['fields']['text']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['text']['alter']['path'] = 'http://www.law.columbia.edu/calendar?main.rtresume=%2Fcalendar&main.cal=we&main.id=[text_1]&main.ctrl=eventmgr.detail&main.view=calendar.detail';
  $handler->display->display_options['fields']['text']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['text']['element_type'] = 'h5';
  $handler->display->display_options['fields']['text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text']['xpath_selector'] = 'title';
  $handler->display->display_options['fields']['text']['multiple'] = 0;
  /* Field: startDate: Date */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'xml';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  $handler->display->display_options['fields']['date']['label'] = '';
  $handler->display->display_options['fields']['date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['date']['xpath_selector'] = 'startDate';
  $handler->display->display_options['fields']['date']['multiple'] = 0;
  $handler->display->display_options['fields']['date']['date_format'] = 'custom';
  $handler->display->display_options['fields']['date']['custom_date_format'] = 'l, F j, Y';
  /* Field: timeLine: Markup */
  $handler->display->display_options['fields']['markup']['id'] = 'markup';
  $handler->display->display_options['fields']['markup']['table'] = 'xml';
  $handler->display->display_options['fields']['markup']['field'] = 'markup';
  $handler->display->display_options['fields']['markup']['label'] = '';
  $handler->display->display_options['fields']['markup']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['markup']['xpath_selector'] = 'timeLine';
  $handler->display->display_options['fields']['markup']['multiple'] = 0;
  $handler->display->display_options['fields']['markup']['format'] = 'full_html';
  $handler->display->display_options['block_description'] = 'Federalist Past Event List View';

  /* Display: Gender & Sexuality Event Carousel Block */
  $handler = $view->new_display('block', 'Gender & Sexuality Event Carousel Block', 'block_21');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event Carousel View';
  $handler->display->display_options['display_description'] = 'Template for the event carousel view';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=gender-sexuality';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<style>
.jcarousel-skin-default .jcarousel-container-horizontal { padding-left: 30px !important; }
.jcarousel-skin-default .threecol {width: 150px;}
div.event-left {float: right; text-align: left !important; width: 100px;}
</style>
<hr class="dashed"><h3>Upcoming Events</h3>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['label'] = 'Event Footer';
  $handler->display->display_options['footer']['area']['content'] = '<br />Visit our<a href="https://web.law.columbia.edu/gender-sexuality/events"> Events </a> page for the full schedule.';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['block_description'] = 'Gender & Sexuality Event Carousel View';

  /* Display: Gender & Sexuality Event List Block */
  $handler = $view->new_display('block', 'Gender & Sexuality Event List Block', 'block_22');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event List View';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=gender-sexuality';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'date',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<h2>Upcoming Events</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: id: Text */
  $handler->display->display_options['fields']['text_1']['id'] = 'text_1';
  $handler->display->display_options['fields']['text_1']['table'] = 'xml';
  $handler->display->display_options['fields']['text_1']['field'] = 'text';
  $handler->display->display_options['fields']['text_1']['label'] = '';
  $handler->display->display_options['fields']['text_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['text_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text_1']['xpath_selector'] = 'id';
  $handler->display->display_options['fields']['text_1']['multiple'] = 0;
  /* Field: title: Text */
  $handler->display->display_options['fields']['text']['id'] = 'text';
  $handler->display->display_options['fields']['text']['table'] = 'xml';
  $handler->display->display_options['fields']['text']['field'] = 'text';
  $handler->display->display_options['fields']['text']['label'] = '';
  $handler->display->display_options['fields']['text']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['text']['alter']['path'] = 'http://www.law.columbia.edu/calendar?main.rtresume=%2Fcalendar&main.cal=we&main.id=[text_1]&main.ctrl=eventmgr.detail&main.view=calendar.detail';
  $handler->display->display_options['fields']['text']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['text']['element_type'] = 'h5';
  $handler->display->display_options['fields']['text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text']['xpath_selector'] = 'title';
  $handler->display->display_options['fields']['text']['multiple'] = 0;
  /* Field: startDate: Date */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'xml';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  $handler->display->display_options['fields']['date']['label'] = '';
  $handler->display->display_options['fields']['date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['date']['xpath_selector'] = 'startDate';
  $handler->display->display_options['fields']['date']['multiple'] = 0;
  $handler->display->display_options['fields']['date']['date_format'] = 'custom';
  $handler->display->display_options['fields']['date']['custom_date_format'] = 'l, F j, Y';
  /* Field: timeLine: Markup */
  $handler->display->display_options['fields']['markup']['id'] = 'markup';
  $handler->display->display_options['fields']['markup']['table'] = 'xml';
  $handler->display->display_options['fields']['markup']['field'] = 'markup';
  $handler->display->display_options['fields']['markup']['label'] = '';
  $handler->display->display_options['fields']['markup']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['markup']['xpath_selector'] = 'timeLine';
  $handler->display->display_options['fields']['markup']['multiple'] = 0;
  $handler->display->display_options['fields']['markup']['format'] = 'full_html';
  $handler->display->display_options['block_description'] = 'Event List View';

  /* Display: GLS Event Carousel Block */
  $handler = $view->new_display('block', 'GLS Event Carousel Block', 'block_23');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event Carousel View';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=gls';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<style>
.jcarousel-skin-default .jcarousel-container-horizontal { padding-left: 30px !important; }
.jcarousel-skin-default .threecol {width: 150px;}
div.event-left {float: right; text-align: left !important; width: 100px;}
</style>
<hr class="dashed"><h3>Featured Events</h3>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['block_description'] = 'GLS Event Carousel View';

  /* Display: GLS MCLLM Event Carousel Block */
  $handler = $view->new_display('block', 'GLS MCLLM Event Carousel Block', 'block_24');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event Carousel View';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=gls';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<h3 style="font-size: 24px; font-family: Georgia,\'Times New Roman\',Times,serif; margin-bottom: 25px; margin-left: -2px; margin-top: -4px; font-weight: normal; color: rgb(138, 138, 138);">Upcoming Events</h3>
';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: id: Text */
  $handler->display->display_options['fields']['text_1']['id'] = 'text_1';
  $handler->display->display_options['fields']['text_1']['table'] = 'xml';
  $handler->display->display_options['fields']['text_1']['field'] = 'text';
  $handler->display->display_options['fields']['text_1']['label'] = '';
  $handler->display->display_options['fields']['text_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['text_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text_1']['xpath_selector'] = 'id';
  $handler->display->display_options['fields']['text_1']['multiple'] = 0;
  /* Field: startMonth: Text */
  $handler->display->display_options['fields']['text_2']['id'] = 'text_2';
  $handler->display->display_options['fields']['text_2']['table'] = 'xml';
  $handler->display->display_options['fields']['text_2']['field'] = 'text';
  $handler->display->display_options['fields']['text_2']['label'] = '';
  $handler->display->display_options['fields']['text_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['text_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text_2']['xpath_selector'] = 'startMonth';
  $handler->display->display_options['fields']['text_2']['multiple'] = 0;
  /* Field: startDay: Text */
  $handler->display->display_options['fields']['text_3']['id'] = 'text_3';
  $handler->display->display_options['fields']['text_3']['table'] = 'xml';
  $handler->display->display_options['fields']['text_3']['field'] = 'text';
  $handler->display->display_options['fields']['text_3']['label'] = '';
  $handler->display->display_options['fields']['text_3']['exclude'] = TRUE;
  $handler->display->display_options['fields']['text_3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text_3']['xpath_selector'] = 'startDay';
  $handler->display->display_options['fields']['text_3']['multiple'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<div>
<div class="calendar-item" style="float: left;">
<div class="icon">
<div class="month">[text_2]</div>
<div class="day">[text_3]</div>
</div>
<div style="width:135px; float:right;">
';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: title: Text */
  $handler->display->display_options['fields']['text']['id'] = 'text';
  $handler->display->display_options['fields']['text']['table'] = 'xml';
  $handler->display->display_options['fields']['text']['field'] = 'text';
  $handler->display->display_options['fields']['text']['label'] = '';
  $handler->display->display_options['fields']['text']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['text']['alter']['path'] = 'http://www.law.columbia.edu/calendar?main.rtresume=%2Fcalendar&main.cal=we&main.id=[text_1]&main.ctrl=eventmgr.detail&main.view=calendar.detail';
  $handler->display->display_options['fields']['text']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['text']['element_type'] = 'h5';
  $handler->display->display_options['fields']['text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text']['xpath_selector'] = 'title';
  $handler->display->display_options['fields']['text']['multiple'] = 0;
  /* Field: location: Text */
  $handler->display->display_options['fields']['text_4']['id'] = 'text_4';
  $handler->display->display_options['fields']['text_4']['table'] = 'xml';
  $handler->display->display_options['fields']['text_4']['field'] = 'text';
  $handler->display->display_options['fields']['text_4']['label'] = '';
  $handler->display->display_options['fields']['text_4']['element_type'] = 'h6';
  $handler->display->display_options['fields']['text_4']['element_class'] = 'introduction';
  $handler->display->display_options['fields']['text_4']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text_4']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['text_4']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['text_4']['xpath_selector'] = 'location';
  $handler->display->display_options['fields']['text_4']['multiple'] = 0;
  /* Field: timeLine: Text */
  $handler->display->display_options['fields']['text_5']['id'] = 'text_5';
  $handler->display->display_options['fields']['text_5']['table'] = 'xml';
  $handler->display->display_options['fields']['text_5']['field'] = 'text';
  $handler->display->display_options['fields']['text_5']['label'] = '';
  $handler->display->display_options['fields']['text_5']['element_type'] = 'h6';
  $handler->display->display_options['fields']['text_5']['element_class'] = 'introduction';
  $handler->display->display_options['fields']['text_5']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text_5']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['text_5']['xpath_selector'] = 'timeLine';
  $handler->display->display_options['fields']['text_5']['multiple'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['label'] = '';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = 'More information';
  $handler->display->display_options['fields']['nothing_2']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_2']['alter']['path'] = 'http://www.law.columbia.edu/calendar?main.rtresume=%2Fcalendar&main.cal=we&main.id=[text_1]&main.ctrl=eventmgr.detail&main.view=calendar.detail';
  $handler->display->display_options['fields']['nothing_2']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['nothing_2']['element_type'] = 'p';
  $handler->display->display_options['fields']['nothing_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_2']['element_default_classes'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '</div>
</div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['block_description'] = 'GLS MCLLM Event Carousel View';

  /* Display: Health & Wellness Event List Block */
  $handler = $view->new_display('block', 'Health & Wellness Event List Block', 'block_25');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event List View';
  $handler->display->display_options['display_description'] = 'Template for the event list view';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=wellness';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'date',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<h2>Upcoming Events</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: id: Text */
  $handler->display->display_options['fields']['text_1']['id'] = 'text_1';
  $handler->display->display_options['fields']['text_1']['table'] = 'xml';
  $handler->display->display_options['fields']['text_1']['field'] = 'text';
  $handler->display->display_options['fields']['text_1']['label'] = '';
  $handler->display->display_options['fields']['text_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['text_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text_1']['xpath_selector'] = 'id';
  $handler->display->display_options['fields']['text_1']['multiple'] = 0;
  /* Field: title: Text */
  $handler->display->display_options['fields']['text']['id'] = 'text';
  $handler->display->display_options['fields']['text']['table'] = 'xml';
  $handler->display->display_options['fields']['text']['field'] = 'text';
  $handler->display->display_options['fields']['text']['label'] = '';
  $handler->display->display_options['fields']['text']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['text']['alter']['path'] = 'http://www.law.columbia.edu/calendar?main.rtresume=%2Fcalendar&main.cal=we&main.id=[text_1]&main.ctrl=eventmgr.detail&main.view=calendar.detail';
  $handler->display->display_options['fields']['text']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['text']['element_type'] = 'h5';
  $handler->display->display_options['fields']['text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text']['xpath_selector'] = 'title';
  $handler->display->display_options['fields']['text']['multiple'] = 0;
  /* Field: startDate: Date */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'xml';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  $handler->display->display_options['fields']['date']['label'] = '';
  $handler->display->display_options['fields']['date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['date']['xpath_selector'] = 'startDate';
  $handler->display->display_options['fields']['date']['multiple'] = 0;
  $handler->display->display_options['fields']['date']['date_format'] = 'custom';
  $handler->display->display_options['fields']['date']['custom_date_format'] = 'l, F j, Y';
  /* Field: timeLine: Markup */
  $handler->display->display_options['fields']['markup']['id'] = 'markup';
  $handler->display->display_options['fields']['markup']['table'] = 'xml';
  $handler->display->display_options['fields']['markup']['field'] = 'markup';
  $handler->display->display_options['fields']['markup']['label'] = '';
  $handler->display->display_options['fields']['markup']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['markup']['xpath_selector'] = 'timeLine';
  $handler->display->display_options['fields']['markup']['multiple'] = 0;
  $handler->display->display_options['fields']['markup']['format'] = 'full_html';
  $handler->display->display_options['block_description'] = 'Health & Wellness Event List View';

  /* Display: Hertog Event List Block */
  $handler = $view->new_display('block', 'Hertog Event List Block', 'block_26');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event List View';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=hertog';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'date',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<h2>Upcoming Events</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: id: Text */
  $handler->display->display_options['fields']['text_1']['id'] = 'text_1';
  $handler->display->display_options['fields']['text_1']['table'] = 'xml';
  $handler->display->display_options['fields']['text_1']['field'] = 'text';
  $handler->display->display_options['fields']['text_1']['label'] = '';
  $handler->display->display_options['fields']['text_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['text_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text_1']['xpath_selector'] = 'id';
  $handler->display->display_options['fields']['text_1']['multiple'] = 0;
  /* Field: title: Text */
  $handler->display->display_options['fields']['text']['id'] = 'text';
  $handler->display->display_options['fields']['text']['table'] = 'xml';
  $handler->display->display_options['fields']['text']['field'] = 'text';
  $handler->display->display_options['fields']['text']['label'] = '';
  $handler->display->display_options['fields']['text']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['text']['alter']['path'] = 'http://www.law.columbia.edu/calendar?main.rtresume=%2Fcalendar&main.cal=we&main.id=[text_1]&main.ctrl=eventmgr.detail&main.view=calendar.detail';
  $handler->display->display_options['fields']['text']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['text']['element_type'] = 'h5';
  $handler->display->display_options['fields']['text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text']['xpath_selector'] = 'title';
  $handler->display->display_options['fields']['text']['multiple'] = 0;
  /* Field: startDate: Date */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'xml';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  $handler->display->display_options['fields']['date']['label'] = '';
  $handler->display->display_options['fields']['date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['date']['xpath_selector'] = 'startDate';
  $handler->display->display_options['fields']['date']['multiple'] = 0;
  $handler->display->display_options['fields']['date']['date_format'] = 'custom';
  $handler->display->display_options['fields']['date']['custom_date_format'] = 'l, F j, Y';
  /* Field: timeLine: Markup */
  $handler->display->display_options['fields']['markup']['id'] = 'markup';
  $handler->display->display_options['fields']['markup']['table'] = 'xml';
  $handler->display->display_options['fields']['markup']['field'] = 'markup';
  $handler->display->display_options['fields']['markup']['label'] = '';
  $handler->display->display_options['fields']['markup']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['markup']['xpath_selector'] = 'timeLine';
  $handler->display->display_options['fields']['markup']['multiple'] = 0;
  $handler->display->display_options['fields']['markup']['format'] = 'full_html';
  $handler->display->display_options['block_description'] = 'Hertog Event List View';

  /* Display: Hertog Event Carousel Block */
  $handler = $view->new_display('block', 'Hertog Event Carousel Block', 'block_27');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event Carousel View';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=hertog';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<style>
.jcarousel-skin-default .jcarousel-container-horizontal { padding-left: 30px !important; }
.jcarousel-skin-default .threecol {width: 150px;}
div.event-left {float: right; text-align: left !important; width: 100px;}
</style>
<hr class="dashed"><h3>Featured Events</h3>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['block_description'] = 'Hertog Event Carousel View';

  /* Display: HRI Event List Block */
  $handler = $view->new_display('block', 'HRI Event List Block', 'block_28');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event List View';
  $handler->display->display_options['display_description'] = 'Template for the event list view';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=hri';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'date',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<h2>Upcoming Events</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: id: Text */
  $handler->display->display_options['fields']['text_1']['id'] = 'text_1';
  $handler->display->display_options['fields']['text_1']['table'] = 'xml';
  $handler->display->display_options['fields']['text_1']['field'] = 'text';
  $handler->display->display_options['fields']['text_1']['label'] = '';
  $handler->display->display_options['fields']['text_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['text_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text_1']['xpath_selector'] = 'id';
  $handler->display->display_options['fields']['text_1']['multiple'] = 0;
  /* Field: title: Text */
  $handler->display->display_options['fields']['text']['id'] = 'text';
  $handler->display->display_options['fields']['text']['table'] = 'xml';
  $handler->display->display_options['fields']['text']['field'] = 'text';
  $handler->display->display_options['fields']['text']['label'] = '';
  $handler->display->display_options['fields']['text']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['text']['alter']['path'] = 'http://www.law.columbia.edu/calendar?main.rtresume=%2Fcalendar&main.cal=we&main.id=[text_1]&main.ctrl=eventmgr.detail&main.view=calendar.detail';
  $handler->display->display_options['fields']['text']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['text']['element_type'] = 'h5';
  $handler->display->display_options['fields']['text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text']['xpath_selector'] = 'title';
  $handler->display->display_options['fields']['text']['multiple'] = 0;
  /* Field: startDate: Date */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'xml';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  $handler->display->display_options['fields']['date']['label'] = '';
  $handler->display->display_options['fields']['date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['date']['xpath_selector'] = 'startDate';
  $handler->display->display_options['fields']['date']['multiple'] = 0;
  $handler->display->display_options['fields']['date']['date_format'] = 'custom';
  $handler->display->display_options['fields']['date']['custom_date_format'] = 'l, F j, Y';
  /* Field: timeLine: Markup */
  $handler->display->display_options['fields']['markup']['id'] = 'markup';
  $handler->display->display_options['fields']['markup']['table'] = 'xml';
  $handler->display->display_options['fields']['markup']['field'] = 'markup';
  $handler->display->display_options['fields']['markup']['label'] = '';
  $handler->display->display_options['fields']['markup']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['markup']['xpath_selector'] = 'timeLine';
  $handler->display->display_options['fields']['markup']['multiple'] = 0;
  $handler->display->display_options['fields']['markup']['format'] = 'full_html';
  $handler->display->display_options['block_description'] = 'HRI Event List View';

  /* Display: HRI Event Carousel Block */
  $handler = $view->new_display('block', 'HRI Event Carousel Block', 'block_29');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event Carousel View';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=hri';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<style>
.jcarousel-skin-default .jcarousel-container-horizontal { padding-left: 30px !important; }
.jcarousel-skin-default .threecol {width: 150px;}
div.event-left {float: right; text-align: left !important; width: 100px;}
</style>
<hr class="dashed"><h3>Featured Events</h3>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['block_description'] = 'HRI Event Carousel View';

  /* Display: Israeli Legal Studies Event Carousel Block */
  $handler = $view->new_display('block', 'Israeli Legal Studies Event Carousel Block', 'block_30');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event Carousel View';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=israeli';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<style>
.jcarousel-skin-default .jcarousel-container-horizontal { padding-left: 30px !important; }
.jcarousel-skin-default .threecol {width: 150px;}
div.event-left {float: right; text-align: left !important; width: 100px;}
</style>
<hr class="dashed"><h3>Featured Events</h3>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['block_description'] = 'Islraeli Legal Studies Event Carousel View';

  /* Display: IT Event Carousel Block */
  $handler = $view->new_display('block', 'IT Event Carousel Block', 'block_31');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event Carousel View';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=information-tech';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<a class="external" href="https://web.law.columbia.edu/information-technology/contact-us/monthly-downtime">View complete schedule</a>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['block_description'] = 'IT Event Carousel View';

  /* Display: IT Event List Block */
  $handler = $view->new_display('block', 'IT Event List Block', 'block_32');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event List View';
  $handler->display->display_options['display_description'] = 'Template for the event list view';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=information-tech';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'date',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<h2>Upcoming Events</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: id: Text */
  $handler->display->display_options['fields']['text_1']['id'] = 'text_1';
  $handler->display->display_options['fields']['text_1']['table'] = 'xml';
  $handler->display->display_options['fields']['text_1']['field'] = 'text';
  $handler->display->display_options['fields']['text_1']['label'] = '';
  $handler->display->display_options['fields']['text_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['text_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text_1']['xpath_selector'] = 'id';
  $handler->display->display_options['fields']['text_1']['multiple'] = 0;
  /* Field: title: Text */
  $handler->display->display_options['fields']['text']['id'] = 'text';
  $handler->display->display_options['fields']['text']['table'] = 'xml';
  $handler->display->display_options['fields']['text']['field'] = 'text';
  $handler->display->display_options['fields']['text']['label'] = '';
  $handler->display->display_options['fields']['text']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['text']['alter']['path'] = 'http://www.law.columbia.edu/calendar?main.rtresume=%2Fcalendar&main.cal=we&main.id=[text_1]&main.ctrl=eventmgr.detail&main.view=calendar.detail';
  $handler->display->display_options['fields']['text']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['text']['element_type'] = 'h5';
  $handler->display->display_options['fields']['text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text']['xpath_selector'] = 'title';
  $handler->display->display_options['fields']['text']['multiple'] = 0;
  /* Field: startDate: Date */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'xml';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  $handler->display->display_options['fields']['date']['label'] = '';
  $handler->display->display_options['fields']['date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['date']['xpath_selector'] = 'startDate';
  $handler->display->display_options['fields']['date']['multiple'] = 0;
  $handler->display->display_options['fields']['date']['date_format'] = 'custom';
  $handler->display->display_options['fields']['date']['custom_date_format'] = 'l, F j, Y';
  /* Field: timeLine: Markup */
  $handler->display->display_options['fields']['markup']['id'] = 'markup';
  $handler->display->display_options['fields']['markup']['table'] = 'xml';
  $handler->display->display_options['fields']['markup']['field'] = 'markup';
  $handler->display->display_options['fields']['markup']['label'] = '';
  $handler->display->display_options['fields']['markup']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['markup']['xpath_selector'] = 'timeLine';
  $handler->display->display_options['fields']['markup']['multiple'] = 0;
  $handler->display->display_options['fields']['markup']['format'] = 'full_html';
  $handler->display->display_options['block_description'] = 'IT Event List View';

  /* Display: JD Orientation Event List Block */
  $handler = $view->new_display('block', 'JD Orientation Event List Block', 'block_33');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event List View';
  $handler->display->display_options['display_description'] = 'Template for the event list view';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=orientation';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'date',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: id: Text */
  $handler->display->display_options['fields']['text_1']['id'] = 'text_1';
  $handler->display->display_options['fields']['text_1']['table'] = 'xml';
  $handler->display->display_options['fields']['text_1']['field'] = 'text';
  $handler->display->display_options['fields']['text_1']['label'] = '';
  $handler->display->display_options['fields']['text_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['text_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text_1']['xpath_selector'] = 'id';
  $handler->display->display_options['fields']['text_1']['multiple'] = 0;
  /* Field: title: Text */
  $handler->display->display_options['fields']['text']['id'] = 'text';
  $handler->display->display_options['fields']['text']['table'] = 'xml';
  $handler->display->display_options['fields']['text']['field'] = 'text';
  $handler->display->display_options['fields']['text']['label'] = '';
  $handler->display->display_options['fields']['text']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['text']['alter']['path'] = 'http://www.law.columbia.edu/calendar?main.rtresume=%2Fcalendar&main.cal=we&main.id=[text_1]&main.ctrl=eventmgr.detail&main.view=calendar.detail';
  $handler->display->display_options['fields']['text']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['text']['element_type'] = 'h5';
  $handler->display->display_options['fields']['text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text']['xpath_selector'] = 'title';
  $handler->display->display_options['fields']['text']['multiple'] = 0;
  /* Field: startDate: Date */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'xml';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  $handler->display->display_options['fields']['date']['label'] = '';
  $handler->display->display_options['fields']['date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['date']['xpath_selector'] = 'startDate';
  $handler->display->display_options['fields']['date']['multiple'] = 0;
  $handler->display->display_options['fields']['date']['date_format'] = 'custom';
  $handler->display->display_options['fields']['date']['custom_date_format'] = 'l, F j, Y';
  /* Field: timeLine: Markup */
  $handler->display->display_options['fields']['markup']['id'] = 'markup';
  $handler->display->display_options['fields']['markup']['table'] = 'xml';
  $handler->display->display_options['fields']['markup']['field'] = 'markup';
  $handler->display->display_options['fields']['markup']['label'] = '';
  $handler->display->display_options['fields']['markup']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['markup']['xpath_selector'] = 'timeLine';
  $handler->display->display_options['fields']['markup']['multiple'] = 0;
  $handler->display->display_options['fields']['markup']['format'] = 'full_html';
  $handler->display->display_options['block_description'] = 'JD Orientation Event List View';

  /* Display: Japanese Legal Studies Event Carousel Block */
  $handler = $view->new_display('block', 'Japanese Legal Studies Event Carousel Block', 'block_34');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event Carousel View';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=japanese';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<style>
.jcarousel-skin-default .jcarousel-container-horizontal { padding-left: 30px !important; }
.jcarousel-skin-default .threecol {width: 150px;}
div.event-left {float: right; text-align: left !important; width: 100px;}
</style>
<hr class="dashed"><h3>Featured Events</h3>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['block_description'] = 'Japanese Legal Studies Event Carousel View';

  /* Display: Japanese Legal Studies Event List Block */
  $handler = $view->new_display('block', 'Japanese Legal Studies Event List Block', 'block_35');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event List View';
  $handler->display->display_options['display_description'] = 'Template for the event list view';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=japanese';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'date',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<h2>Upcoming Events</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: id: Text */
  $handler->display->display_options['fields']['text_1']['id'] = 'text_1';
  $handler->display->display_options['fields']['text_1']['table'] = 'xml';
  $handler->display->display_options['fields']['text_1']['field'] = 'text';
  $handler->display->display_options['fields']['text_1']['label'] = '';
  $handler->display->display_options['fields']['text_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['text_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text_1']['xpath_selector'] = 'id';
  $handler->display->display_options['fields']['text_1']['multiple'] = 0;
  /* Field: title: Text */
  $handler->display->display_options['fields']['text']['id'] = 'text';
  $handler->display->display_options['fields']['text']['table'] = 'xml';
  $handler->display->display_options['fields']['text']['field'] = 'text';
  $handler->display->display_options['fields']['text']['label'] = '';
  $handler->display->display_options['fields']['text']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['text']['alter']['path'] = 'http://www.law.columbia.edu/calendar?main.rtresume=%2Fcalendar&main.cal=we&main.id=[text_1]&main.ctrl=eventmgr.detail&main.view=calendar.detail';
  $handler->display->display_options['fields']['text']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['text']['element_type'] = 'h5';
  $handler->display->display_options['fields']['text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text']['xpath_selector'] = 'title';
  $handler->display->display_options['fields']['text']['multiple'] = 0;
  /* Field: startDate: Date */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'xml';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  $handler->display->display_options['fields']['date']['label'] = '';
  $handler->display->display_options['fields']['date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['date']['xpath_selector'] = 'startDate';
  $handler->display->display_options['fields']['date']['multiple'] = 0;
  $handler->display->display_options['fields']['date']['date_format'] = 'custom';
  $handler->display->display_options['fields']['date']['custom_date_format'] = 'l, F j, Y';
  /* Field: timeLine: Markup */
  $handler->display->display_options['fields']['markup']['id'] = 'markup';
  $handler->display->display_options['fields']['markup']['table'] = 'xml';
  $handler->display->display_options['fields']['markup']['field'] = 'markup';
  $handler->display->display_options['fields']['markup']['label'] = '';
  $handler->display->display_options['fields']['markup']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['markup']['xpath_selector'] = 'timeLine';
  $handler->display->display_options['fields']['markup']['multiple'] = 0;
  $handler->display->display_options['fields']['markup']['format'] = 'full_html';
  $handler->display->display_options['block_description'] = 'Japanese Legal Studies Event List View';

  /* Display: Japanese Legal Studies Past Event List Block */
  $handler = $view->new_display('block', 'Japanese Legal Studies Past Event List Block', 'block_36');
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=japanese&main.timeframe=past';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'date',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<h2>Past Events</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: id: Text */
  $handler->display->display_options['fields']['text_1']['id'] = 'text_1';
  $handler->display->display_options['fields']['text_1']['table'] = 'xml';
  $handler->display->display_options['fields']['text_1']['field'] = 'text';
  $handler->display->display_options['fields']['text_1']['label'] = '';
  $handler->display->display_options['fields']['text_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['text_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text_1']['xpath_selector'] = 'id';
  $handler->display->display_options['fields']['text_1']['multiple'] = 0;
  /* Field: title: Text */
  $handler->display->display_options['fields']['text']['id'] = 'text';
  $handler->display->display_options['fields']['text']['table'] = 'xml';
  $handler->display->display_options['fields']['text']['field'] = 'text';
  $handler->display->display_options['fields']['text']['label'] = '';
  $handler->display->display_options['fields']['text']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['text']['alter']['path'] = 'http://www.law.columbia.edu/calendar?main.rtresume=%2Fcalendar&main.cal=we&main.id=[text_1]&main.ctrl=eventmgr.detail&main.view=calendar.detail';
  $handler->display->display_options['fields']['text']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['text']['element_type'] = 'h5';
  $handler->display->display_options['fields']['text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text']['xpath_selector'] = 'title';
  $handler->display->display_options['fields']['text']['multiple'] = 0;
  /* Field: startDate: Date */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'xml';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  $handler->display->display_options['fields']['date']['label'] = '';
  $handler->display->display_options['fields']['date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['date']['xpath_selector'] = 'startDate';
  $handler->display->display_options['fields']['date']['multiple'] = 0;
  $handler->display->display_options['fields']['date']['date_format'] = 'custom';
  $handler->display->display_options['fields']['date']['custom_date_format'] = 'l, F j, Y';
  /* Field: timeLine: Markup */
  $handler->display->display_options['fields']['markup']['id'] = 'markup';
  $handler->display->display_options['fields']['markup']['table'] = 'xml';
  $handler->display->display_options['fields']['markup']['field'] = 'markup';
  $handler->display->display_options['fields']['markup']['label'] = '';
  $handler->display->display_options['fields']['markup']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['markup']['xpath_selector'] = 'timeLine';
  $handler->display->display_options['fields']['markup']['multiple'] = 0;
  $handler->display->display_options['fields']['markup']['format'] = 'full_html';
  $handler->display->display_options['block_description'] = 'Japanese Legal Studies Past Event List View';

  /* Display: Kernochan Event Carousel Block */
  $handler = $view->new_display('block', 'Kernochan Event Carousel Block', 'block_37');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event Carousel View';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=kernochan';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<style>
.jcarousel-skin-default .jcarousel-container-horizontal { padding-left: 30px !important; }
.jcarousel-skin-default .threecol {width: 150px;}
div.event-left {float: right; text-align: left !important; width: 100px;}
</style>
<hr class="dashed"><h3>Featured Events</h3>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['block_description'] = 'Kernochan Event Carousel View';

  /* Display: Kernochan Event List Block */
  $handler = $view->new_display('block', 'Kernochan Event List Block', 'block_38');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event List View';
  $handler->display->display_options['display_description'] = 'Template for the event list view';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=kernochan';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'date',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<h2>Upcoming Events</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: id: Text */
  $handler->display->display_options['fields']['text_1']['id'] = 'text_1';
  $handler->display->display_options['fields']['text_1']['table'] = 'xml';
  $handler->display->display_options['fields']['text_1']['field'] = 'text';
  $handler->display->display_options['fields']['text_1']['label'] = '';
  $handler->display->display_options['fields']['text_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['text_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text_1']['xpath_selector'] = 'id';
  $handler->display->display_options['fields']['text_1']['multiple'] = 0;
  /* Field: title: Text */
  $handler->display->display_options['fields']['text']['id'] = 'text';
  $handler->display->display_options['fields']['text']['table'] = 'xml';
  $handler->display->display_options['fields']['text']['field'] = 'text';
  $handler->display->display_options['fields']['text']['label'] = '';
  $handler->display->display_options['fields']['text']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['text']['alter']['path'] = 'http://www.law.columbia.edu/calendar?main.rtresume=%2Fcalendar&main.cal=we&main.id=[text_1]&main.ctrl=eventmgr.detail&main.view=calendar.detail';
  $handler->display->display_options['fields']['text']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['text']['element_type'] = 'h5';
  $handler->display->display_options['fields']['text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text']['xpath_selector'] = 'title';
  $handler->display->display_options['fields']['text']['multiple'] = 0;
  /* Field: startDate: Date */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'xml';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  $handler->display->display_options['fields']['date']['label'] = '';
  $handler->display->display_options['fields']['date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['date']['xpath_selector'] = 'startDate';
  $handler->display->display_options['fields']['date']['multiple'] = 0;
  $handler->display->display_options['fields']['date']['date_format'] = 'custom';
  $handler->display->display_options['fields']['date']['custom_date_format'] = 'l, F j, Y';
  /* Field: timeLine: Markup */
  $handler->display->display_options['fields']['markup']['id'] = 'markup';
  $handler->display->display_options['fields']['markup']['table'] = 'xml';
  $handler->display->display_options['fields']['markup']['field'] = 'markup';
  $handler->display->display_options['fields']['markup']['label'] = '';
  $handler->display->display_options['fields']['markup']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['markup']['xpath_selector'] = 'timeLine';
  $handler->display->display_options['fields']['markup']['multiple'] = 0;
  $handler->display->display_options['fields']['markup']['format'] = 'full_html';
  $handler->display->display_options['block_description'] = 'Kernochan Event List View';

  /* Display: Kernochan Past Event List Block */
  $handler = $view->new_display('block', 'Kernochan Past Event List Block', 'block_39');
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=kernochan&main.timeframe=past';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'date',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<h2>Past Events</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: id: Text */
  $handler->display->display_options['fields']['text_1']['id'] = 'text_1';
  $handler->display->display_options['fields']['text_1']['table'] = 'xml';
  $handler->display->display_options['fields']['text_1']['field'] = 'text';
  $handler->display->display_options['fields']['text_1']['label'] = '';
  $handler->display->display_options['fields']['text_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['text_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text_1']['xpath_selector'] = 'id';
  $handler->display->display_options['fields']['text_1']['multiple'] = 0;
  /* Field: title: Text */
  $handler->display->display_options['fields']['text']['id'] = 'text';
  $handler->display->display_options['fields']['text']['table'] = 'xml';
  $handler->display->display_options['fields']['text']['field'] = 'text';
  $handler->display->display_options['fields']['text']['label'] = '';
  $handler->display->display_options['fields']['text']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['text']['alter']['path'] = 'http://www.law.columbia.edu/calendar?main.rtresume=%2Fcalendar&main.cal=we&main.id=[text_1]&main.ctrl=eventmgr.detail&main.view=calendar.detail';
  $handler->display->display_options['fields']['text']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['text']['element_type'] = 'h5';
  $handler->display->display_options['fields']['text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text']['xpath_selector'] = 'title';
  $handler->display->display_options['fields']['text']['multiple'] = 0;
  /* Field: startDate: Date */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'xml';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  $handler->display->display_options['fields']['date']['label'] = '';
  $handler->display->display_options['fields']['date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['date']['xpath_selector'] = 'startDate';
  $handler->display->display_options['fields']['date']['multiple'] = 0;
  $handler->display->display_options['fields']['date']['date_format'] = 'custom';
  $handler->display->display_options['fields']['date']['custom_date_format'] = 'l, F j, Y';
  /* Field: timeLine: Markup */
  $handler->display->display_options['fields']['markup']['id'] = 'markup';
  $handler->display->display_options['fields']['markup']['table'] = 'xml';
  $handler->display->display_options['fields']['markup']['field'] = 'markup';
  $handler->display->display_options['fields']['markup']['label'] = '';
  $handler->display->display_options['fields']['markup']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['markup']['xpath_selector'] = 'timeLine';
  $handler->display->display_options['fields']['markup']['multiple'] = 0;
  $handler->display->display_options['fields']['markup']['format'] = 'full_html';
  $handler->display->display_options['block_description'] = 'Kernochan Past Event List View';

  /* Display: Law & Economics Event Carousel Block */
  $handler = $view->new_display('block', 'Law & Economics Event Carousel Block', 'block_40');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event Carousel View';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=law-economics';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<style>
.jcarousel-skin-default .jcarousel-container-horizontal { padding-left: 30px !important; }
.jcarousel-skin-default .threecol {width: 150px;}
div.event-left {float: right; text-align: left !important; width: 100px;}
</style>
<hr class="dashed"><h3>Featured Events</h3>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['block_description'] = 'Law & Economics Event Carousel View';

  /* Display: Law Teaching Event Carousel Block */
  $handler = $view->new_display('block', 'Law Teaching Event Carousel Block', 'block_41');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event Carousel View';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=law-teaching';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<style>
.jcarousel-skin-default .jcarousel-container-horizontal { padding-left: 30px !important; }
.jcarousel-skin-default .threecol {width: 150px;}
div.event-left {float: right; text-align: left !important; width: 100px;}
</style>
<hr class="dashed"><h3>Featured Events</h3>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['block_description'] = 'Law Teaching Event Carousel View';

  /* Display: Law Teaching Event List Block */
  $handler = $view->new_display('block', 'Law Teaching Event List Block', 'block_42');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event List View';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=law-teaching';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'date',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<h2>Upcoming Events</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: id: Text */
  $handler->display->display_options['fields']['text_1']['id'] = 'text_1';
  $handler->display->display_options['fields']['text_1']['table'] = 'xml';
  $handler->display->display_options['fields']['text_1']['field'] = 'text';
  $handler->display->display_options['fields']['text_1']['label'] = '';
  $handler->display->display_options['fields']['text_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['text_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text_1']['xpath_selector'] = 'id';
  $handler->display->display_options['fields']['text_1']['multiple'] = 0;
  /* Field: title: Text */
  $handler->display->display_options['fields']['text']['id'] = 'text';
  $handler->display->display_options['fields']['text']['table'] = 'xml';
  $handler->display->display_options['fields']['text']['field'] = 'text';
  $handler->display->display_options['fields']['text']['label'] = '';
  $handler->display->display_options['fields']['text']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['text']['alter']['path'] = 'http://www.law.columbia.edu/calendar?main.rtresume=%2Fcalendar&main.cal=we&main.id=[text_1]&main.ctrl=eventmgr.detail&main.view=calendar.detail';
  $handler->display->display_options['fields']['text']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['text']['element_type'] = 'h5';
  $handler->display->display_options['fields']['text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text']['xpath_selector'] = 'title';
  $handler->display->display_options['fields']['text']['multiple'] = 0;
  /* Field: startDate: Date */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'xml';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  $handler->display->display_options['fields']['date']['label'] = '';
  $handler->display->display_options['fields']['date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['date']['xpath_selector'] = 'startDate';
  $handler->display->display_options['fields']['date']['multiple'] = 0;
  $handler->display->display_options['fields']['date']['date_format'] = 'custom';
  $handler->display->display_options['fields']['date']['custom_date_format'] = 'l, F j, Y';
  /* Field: timeLine: Markup */
  $handler->display->display_options['fields']['markup']['id'] = 'markup';
  $handler->display->display_options['fields']['markup']['table'] = 'xml';
  $handler->display->display_options['fields']['markup']['field'] = 'markup';
  $handler->display->display_options['fields']['markup']['label'] = '';
  $handler->display->display_options['fields']['markup']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['markup']['xpath_selector'] = 'timeLine';
  $handler->display->display_options['fields']['markup']['multiple'] = 0;
  $handler->display->display_options['fields']['markup']['format'] = 'full_html';
  $handler->display->display_options['block_description'] = 'Law Teaching Event List View';

  /* Display: Law Theory Workshop Event Carousel Block */
  $handler = $view->new_display('block', 'Law Theory Workshop Event Carousel Block', 'block_43');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event Carousel View';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=legal-theory-workshop';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<style>
.jcarousel-skin-default .jcarousel-container-horizontal { padding-left: 30px !important; }
.jcarousel-skin-default .threecol {width: 150px;}
div.event-left {float: right; text-align: left !important; width: 100px;}
</style>
<hr class="dashed"><h3>Featured Events</h3>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['block_description'] = 'Law Theory Workshop Event Carousel View';

  /* Display: NSLS Event Carousel Block */
  $handler = $view->new_display('block', 'NSLS Event Carousel Block', 'block_44');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event Carousel View';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=nsls';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<style>
.jcarousel-skin-default .jcarousel-container-horizontal { padding-left: 30px !important; }
.jcarousel-skin-default .threecol {width: 150px;}
div.event-left {float: right; text-align: left !important; width: 100px;}
</style>
<hr class="dashed"><h3>Featured Events</h3>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['block_description'] = 'NSLS Event Carousel View';

  /* Display: NSLS Past Event List Block */
  $handler = $view->new_display('block', 'NSLS Past Event List Block', 'block_45');
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=nsls&main.timeframe=past';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'date',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<h2>Past Events</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: id: Text */
  $handler->display->display_options['fields']['text_1']['id'] = 'text_1';
  $handler->display->display_options['fields']['text_1']['table'] = 'xml';
  $handler->display->display_options['fields']['text_1']['field'] = 'text';
  $handler->display->display_options['fields']['text_1']['label'] = '';
  $handler->display->display_options['fields']['text_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['text_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text_1']['xpath_selector'] = 'id';
  $handler->display->display_options['fields']['text_1']['multiple'] = 0;
  /* Field: title: Text */
  $handler->display->display_options['fields']['text']['id'] = 'text';
  $handler->display->display_options['fields']['text']['table'] = 'xml';
  $handler->display->display_options['fields']['text']['field'] = 'text';
  $handler->display->display_options['fields']['text']['label'] = '';
  $handler->display->display_options['fields']['text']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['text']['alter']['path'] = 'http://www.law.columbia.edu/calendar?main.rtresume=%2Fcalendar&main.cal=we&main.id=[text_1]&main.ctrl=eventmgr.detail&main.view=calendar.detail';
  $handler->display->display_options['fields']['text']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['text']['element_type'] = 'h5';
  $handler->display->display_options['fields']['text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text']['xpath_selector'] = 'title';
  $handler->display->display_options['fields']['text']['multiple'] = 0;
  /* Field: startDate: Date */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'xml';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  $handler->display->display_options['fields']['date']['label'] = '';
  $handler->display->display_options['fields']['date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['date']['xpath_selector'] = 'startDate';
  $handler->display->display_options['fields']['date']['multiple'] = 0;
  $handler->display->display_options['fields']['date']['date_format'] = 'custom';
  $handler->display->display_options['fields']['date']['custom_date_format'] = 'l, F j, Y';
  /* Field: timeLine: Markup */
  $handler->display->display_options['fields']['markup']['id'] = 'markup';
  $handler->display->display_options['fields']['markup']['table'] = 'xml';
  $handler->display->display_options['fields']['markup']['field'] = 'markup';
  $handler->display->display_options['fields']['markup']['label'] = '';
  $handler->display->display_options['fields']['markup']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['markup']['xpath_selector'] = 'timeLine';
  $handler->display->display_options['fields']['markup']['multiple'] = 0;
  $handler->display->display_options['fields']['markup']['format'] = 'full_html';
  $handler->display->display_options['block_description'] = 'NSLS Past Event List View';

  /* Display: Professionalism Event Carousel Block */
  $handler = $view->new_display('block', 'Professionalism Event Carousel Block', 'block_46');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event Carousel View';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=professionalism';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<style>
.jcarousel-skin-default .jcarousel-container-horizontal { padding-left: 30px !important; }
.jcarousel-skin-default .threecol {width: 150px;}
div.event-left {float: right; text-align: left !important; width: 100px;}
</style>
<hr class="dashed"><h3>Featured Events</h3>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['block_description'] = 'Professionalism Event Carousel View';

  /* Display: PRPCP Event Carousel Block */
  $handler = $view->new_display('block', 'PRPCP Event Carousel Block', 'block_47');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event Carousel View';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=public-rights';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<style>
.jcarousel-skin-default .jcarousel-container-horizontal { padding-left: 30px !important; }
.jcarousel-skin-default .threecol {width: 150px;}
div.event-left {float: right; text-align: left !important; width: 100px;}
</style>
<hr class="dashed"><h3>Featured Events</h3>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['block_description'] = 'PRPCP Event Carousel View';

  /* Display: SIRR Event Carousel Block */
  $handler = $view->new_display('block', 'SIRR Event Carousel Block', 'block_48');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event Carousel View';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=sirr';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<style>
.jcarousel-skin-default .jcarousel-container-horizontal { padding-left: 30px !important; }
.jcarousel-skin-default .threecol {width: 150px;}
div.event-left {float: right; text-align: left !important; width: 100px;}
</style>
<hr class="dashed"><h3>Featured Events</h3>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['block_description'] = 'SIRR Event Carousel View';

  /* Display: SIRR Event List Block */
  $handler = $view->new_display('block', 'SIRR Event List Block', 'block_49');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event List View';
  $handler->display->display_options['display_description'] = 'Template for the event list view';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=sirr';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'date',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<h2>Upcoming Events</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: id: Text */
  $handler->display->display_options['fields']['text_1']['id'] = 'text_1';
  $handler->display->display_options['fields']['text_1']['table'] = 'xml';
  $handler->display->display_options['fields']['text_1']['field'] = 'text';
  $handler->display->display_options['fields']['text_1']['label'] = '';
  $handler->display->display_options['fields']['text_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['text_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text_1']['xpath_selector'] = 'id';
  $handler->display->display_options['fields']['text_1']['multiple'] = 0;
  /* Field: title: Text */
  $handler->display->display_options['fields']['text']['id'] = 'text';
  $handler->display->display_options['fields']['text']['table'] = 'xml';
  $handler->display->display_options['fields']['text']['field'] = 'text';
  $handler->display->display_options['fields']['text']['label'] = '';
  $handler->display->display_options['fields']['text']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['text']['alter']['path'] = 'http://www.law.columbia.edu/calendar?main.rtresume=%2Fcalendar&main.cal=we&main.id=[text_1]&main.ctrl=eventmgr.detail&main.view=calendar.detail';
  $handler->display->display_options['fields']['text']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['text']['element_type'] = 'h5';
  $handler->display->display_options['fields']['text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text']['xpath_selector'] = 'title';
  $handler->display->display_options['fields']['text']['multiple'] = 0;
  /* Field: startDate: Date */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'xml';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  $handler->display->display_options['fields']['date']['label'] = '';
  $handler->display->display_options['fields']['date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['date']['xpath_selector'] = 'startDate';
  $handler->display->display_options['fields']['date']['multiple'] = 0;
  $handler->display->display_options['fields']['date']['date_format'] = 'custom';
  $handler->display->display_options['fields']['date']['custom_date_format'] = 'l, F j, Y';
  /* Field: timeLine: Markup */
  $handler->display->display_options['fields']['markup']['id'] = 'markup';
  $handler->display->display_options['fields']['markup']['table'] = 'xml';
  $handler->display->display_options['fields']['markup']['field'] = 'markup';
  $handler->display->display_options['fields']['markup']['label'] = '';
  $handler->display->display_options['fields']['markup']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['markup']['xpath_selector'] = 'timeLine';
  $handler->display->display_options['fields']['markup']['multiple'] = 0;
  $handler->display->display_options['fields']['markup']['format'] = 'full_html';
  $handler->display->display_options['block_description'] = 'SIRR Event List View';

  /* Display: SIRR Past Event List Block */
  $handler = $view->new_display('block', 'SIRR Past Event List Block', 'block_50');
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=sirr&main.timeframe=past';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'date',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<h2>Past Events</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: id: Text */
  $handler->display->display_options['fields']['text_1']['id'] = 'text_1';
  $handler->display->display_options['fields']['text_1']['table'] = 'xml';
  $handler->display->display_options['fields']['text_1']['field'] = 'text';
  $handler->display->display_options['fields']['text_1']['label'] = '';
  $handler->display->display_options['fields']['text_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['text_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text_1']['xpath_selector'] = 'id';
  $handler->display->display_options['fields']['text_1']['multiple'] = 0;
  /* Field: title: Text */
  $handler->display->display_options['fields']['text']['id'] = 'text';
  $handler->display->display_options['fields']['text']['table'] = 'xml';
  $handler->display->display_options['fields']['text']['field'] = 'text';
  $handler->display->display_options['fields']['text']['label'] = '';
  $handler->display->display_options['fields']['text']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['text']['alter']['path'] = 'http://www.law.columbia.edu/calendar?main.rtresume=%2Fcalendar&main.cal=we&main.id=[text_1]&main.ctrl=eventmgr.detail&main.view=calendar.detail';
  $handler->display->display_options['fields']['text']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['text']['element_type'] = 'h5';
  $handler->display->display_options['fields']['text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text']['xpath_selector'] = 'title';
  $handler->display->display_options['fields']['text']['multiple'] = 0;
  /* Field: startDate: Date */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'xml';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  $handler->display->display_options['fields']['date']['label'] = '';
  $handler->display->display_options['fields']['date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['date']['xpath_selector'] = 'startDate';
  $handler->display->display_options['fields']['date']['multiple'] = 0;
  $handler->display->display_options['fields']['date']['date_format'] = 'custom';
  $handler->display->display_options['fields']['date']['custom_date_format'] = 'l, F j, Y';
  /* Field: timeLine: Markup */
  $handler->display->display_options['fields']['markup']['id'] = 'markup';
  $handler->display->display_options['fields']['markup']['table'] = 'xml';
  $handler->display->display_options['fields']['markup']['field'] = 'markup';
  $handler->display->display_options['fields']['markup']['label'] = '';
  $handler->display->display_options['fields']['markup']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['markup']['xpath_selector'] = 'timeLine';
  $handler->display->display_options['fields']['markup']['multiple'] = 0;
  $handler->display->display_options['fields']['markup']['format'] = 'full_html';
  $handler->display->display_options['block_description'] = 'SIRR Past Event List View';

  /* Display: SJI Event List Block */
  $handler = $view->new_display('block', 'SJI Event List Block', 'block_51');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event List View';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=sji';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'date',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<h2>Upcoming Events</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: id: Text */
  $handler->display->display_options['fields']['text_1']['id'] = 'text_1';
  $handler->display->display_options['fields']['text_1']['table'] = 'xml';
  $handler->display->display_options['fields']['text_1']['field'] = 'text';
  $handler->display->display_options['fields']['text_1']['label'] = '';
  $handler->display->display_options['fields']['text_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['text_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text_1']['xpath_selector'] = 'id';
  $handler->display->display_options['fields']['text_1']['multiple'] = 0;
  /* Field: title: Text */
  $handler->display->display_options['fields']['text']['id'] = 'text';
  $handler->display->display_options['fields']['text']['table'] = 'xml';
  $handler->display->display_options['fields']['text']['field'] = 'text';
  $handler->display->display_options['fields']['text']['label'] = '';
  $handler->display->display_options['fields']['text']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['text']['alter']['path'] = 'http://www.law.columbia.edu/calendar?main.rtresume=%2Fcalendar&main.cal=we&main.id=[text_1]&main.ctrl=eventmgr.detail&main.view=calendar.detail';
  $handler->display->display_options['fields']['text']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['text']['element_type'] = 'h5';
  $handler->display->display_options['fields']['text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text']['xpath_selector'] = 'title';
  $handler->display->display_options['fields']['text']['multiple'] = 0;
  /* Field: startDate: Date */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'xml';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  $handler->display->display_options['fields']['date']['label'] = '';
  $handler->display->display_options['fields']['date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['date']['xpath_selector'] = 'startDate';
  $handler->display->display_options['fields']['date']['multiple'] = 0;
  $handler->display->display_options['fields']['date']['date_format'] = 'custom';
  $handler->display->display_options['fields']['date']['custom_date_format'] = 'l, F j, Y';
  /* Field: timeLine: Markup */
  $handler->display->display_options['fields']['markup']['id'] = 'markup';
  $handler->display->display_options['fields']['markup']['table'] = 'xml';
  $handler->display->display_options['fields']['markup']['field'] = 'markup';
  $handler->display->display_options['fields']['markup']['label'] = '';
  $handler->display->display_options['fields']['markup']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['markup']['xpath_selector'] = 'timeLine';
  $handler->display->display_options['fields']['markup']['multiple'] = 0;
  $handler->display->display_options['fields']['markup']['format'] = 'full_html';
  $handler->display->display_options['block_description'] = 'SJI Event List View';

  /* Display: SJI Past Event List Block */
  $handler = $view->new_display('block', 'SJI Past Event List Block', 'block_52');
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=sji&main.timeframe=past';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'date',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<h2>Past Events</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: id: Text */
  $handler->display->display_options['fields']['text_1']['id'] = 'text_1';
  $handler->display->display_options['fields']['text_1']['table'] = 'xml';
  $handler->display->display_options['fields']['text_1']['field'] = 'text';
  $handler->display->display_options['fields']['text_1']['label'] = '';
  $handler->display->display_options['fields']['text_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['text_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text_1']['xpath_selector'] = 'id';
  $handler->display->display_options['fields']['text_1']['multiple'] = 0;
  /* Field: title: Text */
  $handler->display->display_options['fields']['text']['id'] = 'text';
  $handler->display->display_options['fields']['text']['table'] = 'xml';
  $handler->display->display_options['fields']['text']['field'] = 'text';
  $handler->display->display_options['fields']['text']['label'] = '';
  $handler->display->display_options['fields']['text']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['text']['alter']['path'] = 'http://www.law.columbia.edu/calendar?main.rtresume=%2Fcalendar&main.cal=we&main.id=[text_1]&main.ctrl=eventmgr.detail&main.view=calendar.detail';
  $handler->display->display_options['fields']['text']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['text']['element_type'] = 'h5';
  $handler->display->display_options['fields']['text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text']['xpath_selector'] = 'title';
  $handler->display->display_options['fields']['text']['multiple'] = 0;
  /* Field: startDate: Date */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'xml';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  $handler->display->display_options['fields']['date']['label'] = '';
  $handler->display->display_options['fields']['date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['date']['xpath_selector'] = 'startDate';
  $handler->display->display_options['fields']['date']['multiple'] = 0;
  $handler->display->display_options['fields']['date']['date_format'] = 'custom';
  $handler->display->display_options['fields']['date']['custom_date_format'] = 'l, F j, Y';
  /* Field: timeLine: Markup */
  $handler->display->display_options['fields']['markup']['id'] = 'markup';
  $handler->display->display_options['fields']['markup']['table'] = 'xml';
  $handler->display->display_options['fields']['markup']['field'] = 'markup';
  $handler->display->display_options['fields']['markup']['label'] = '';
  $handler->display->display_options['fields']['markup']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['markup']['xpath_selector'] = 'timeLine';
  $handler->display->display_options['fields']['markup']['multiple'] = 0;
  $handler->display->display_options['fields']['markup']['format'] = 'full_html';
  $handler->display->display_options['block_description'] = 'SJI Past Event List View';

  /* Display: SJI-Gov Event Carousel Block */
  $handler = $view->new_display('block', 'SJI-Gov Event Carousel Block', 'block_53');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event Carousel View';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=sji-gov';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<style>
.jcarousel-skin-default .jcarousel-container-horizontal { padding-left: 30px !important; }
.jcarousel-skin-default .threecol {width: 150px;}
div.event-left {float: right; text-align: left !important; width: 100px;}
</style>
<hr class="dashed"><h3>Featured Events</h3>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['block_description'] = 'SJI-Gov Event Carousel View';

  /* Display: SJI-Probono Event Carousel Block */
  $handler = $view->new_display('block', 'SJI-Probono Event Carousel Block', 'block_54');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event Carousel View';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=sji-probono';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<style>
.jcarousel-skin-default .jcarousel-container-horizontal { padding-left: 30px !important; }
.jcarousel-skin-default .threecol {width: 150px;}
div.event-left {float: right; text-align: left !important; width: 100px;}
</style>
<hr class="dashed"><h3>Featured Events</h3>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['block_description'] = 'SJI-Probono Event Carousel View';

  /* Display: SJI-Public Interest Event Carousel Block */
  $handler = $view->new_display('block', 'SJI-Public Interest Event Carousel Block', 'block_55');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event Carousel View';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=sji-pubint';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<style>
.jcarousel-skin-default .jcarousel-container-horizontal { padding-left: 30px !important; }
.jcarousel-skin-default .threecol {width: 150px;}
div.event-left {float: right; text-align: left !important; width: 100px;}
</style>
<hr class="dashed"><h3>Featured Events</h3>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['block_description'] = 'SJI-Public Interest Event Carousel View';

  /* Display: SJI Event Carousel Block */
  $handler = $view->new_display('block', 'SJI Event Carousel Block', 'block_56');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event Carousel View';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=sji-events';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<style>
.jcarousel-skin-default .jcarousel-container-horizontal { padding-left: 30px !important; }
.jcarousel-skin-default .threecol {width: 150px;}
div.event-left {float: right; text-align: left !important; width: 100px;}
</style>
<hr class="dashed"><h3>Featured Events</h3>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['block_description'] = 'SJI Event Carousel View';

  /* Display: Student Services Event Carousel Block */
  $handler = $view->new_display('block', 'Student Services Event Carousel Block', 'block_57');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event Carousel View';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=students';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<style>
.jcarousel-skin-default .jcarousel-container-horizontal { padding-left: 30px !important; }
.jcarousel-skin-default .threecol {width: 150px;}
div.event-left {float: right; text-align: left !important; width: 100px;}
</style>
<hr class="dashed"><h3>Featured Events</h3>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['block_description'] = 'Student Services Event Carousel View';

  /* Display: Tax Policy Event List Block */
  $handler = $view->new_display('block', 'Tax Policy Event List Block', 'block_58');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event List View';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=tax-policy';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'date',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<h2>Upcoming Events</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: id: Text */
  $handler->display->display_options['fields']['text_1']['id'] = 'text_1';
  $handler->display->display_options['fields']['text_1']['table'] = 'xml';
  $handler->display->display_options['fields']['text_1']['field'] = 'text';
  $handler->display->display_options['fields']['text_1']['label'] = '';
  $handler->display->display_options['fields']['text_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['text_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text_1']['xpath_selector'] = 'id';
  $handler->display->display_options['fields']['text_1']['multiple'] = 0;
  /* Field: title: Text */
  $handler->display->display_options['fields']['text']['id'] = 'text';
  $handler->display->display_options['fields']['text']['table'] = 'xml';
  $handler->display->display_options['fields']['text']['field'] = 'text';
  $handler->display->display_options['fields']['text']['label'] = '';
  $handler->display->display_options['fields']['text']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['text']['alter']['path'] = 'http://www.law.columbia.edu/calendar?main.rtresume=%2Fcalendar&main.cal=we&main.id=[text_1]&main.ctrl=eventmgr.detail&main.view=calendar.detail';
  $handler->display->display_options['fields']['text']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['text']['element_type'] = 'h5';
  $handler->display->display_options['fields']['text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text']['xpath_selector'] = 'title';
  $handler->display->display_options['fields']['text']['multiple'] = 0;
  /* Field: startDate: Date */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'xml';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  $handler->display->display_options['fields']['date']['label'] = '';
  $handler->display->display_options['fields']['date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['date']['xpath_selector'] = 'startDate';
  $handler->display->display_options['fields']['date']['multiple'] = 0;
  $handler->display->display_options['fields']['date']['date_format'] = 'custom';
  $handler->display->display_options['fields']['date']['custom_date_format'] = 'l, F j, Y';
  /* Field: timeLine: Markup */
  $handler->display->display_options['fields']['markup']['id'] = 'markup';
  $handler->display->display_options['fields']['markup']['table'] = 'xml';
  $handler->display->display_options['fields']['markup']['field'] = 'markup';
  $handler->display->display_options['fields']['markup']['label'] = '';
  $handler->display->display_options['fields']['markup']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['markup']['xpath_selector'] = 'timeLine';
  $handler->display->display_options['fields']['markup']['multiple'] = 0;
  $handler->display->display_options['fields']['markup']['format'] = 'full_html';
  $handler->display->display_options['block_description'] = 'Tax Policy Event List View';

  /* Display: Transactional Studies Event Carousel Block */
  $handler = $view->new_display('block', 'Transactional Studies Event Carousel Block', 'block_59');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event Carousel View';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=transactional';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<style>
.jcarousel-skin-default .jcarousel-container-horizontal { padding-left: 30px !important; }
.jcarousel-skin-default .threecol {width: 150px;}
div.event-left {float: right; text-align: left !important; width: 100px;}
</style>
<hr class="dashed"><h3>Featured Events</h3>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['block_description'] = 'Transactional Studies Event Carousel View';

  /* Display: Writing Center Event Carousel Block */
  $handler = $view->new_display('block', 'Writing Center Event Carousel Block', 'block_60');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event Carousel View';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=writing-center';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<style>
.jcarousel-skin-default .jcarousel-container-horizontal { padding-left: 30px !important; }
.jcarousel-skin-default .threecol {width: 150px;}
div.event-left {float: right; text-align: left !important; width: 100px;}
</style>
<hr class="dashed"><h3>Featured Events</h3>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['block_description'] = 'Writing Center Event Carousel View';

  /* Display: Writing Center Event List Block */
  $handler = $view->new_display('block', 'Writing Center Event List Block', 'block_61');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event List View';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=writing-center';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'date',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<h2>Upcoming Events</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: id: Text */
  $handler->display->display_options['fields']['text_1']['id'] = 'text_1';
  $handler->display->display_options['fields']['text_1']['table'] = 'xml';
  $handler->display->display_options['fields']['text_1']['field'] = 'text';
  $handler->display->display_options['fields']['text_1']['label'] = '';
  $handler->display->display_options['fields']['text_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['text_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text_1']['xpath_selector'] = 'id';
  $handler->display->display_options['fields']['text_1']['multiple'] = 0;
  /* Field: title: Text */
  $handler->display->display_options['fields']['text']['id'] = 'text';
  $handler->display->display_options['fields']['text']['table'] = 'xml';
  $handler->display->display_options['fields']['text']['field'] = 'text';
  $handler->display->display_options['fields']['text']['label'] = '';
  $handler->display->display_options['fields']['text']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['text']['alter']['path'] = 'http://www.law.columbia.edu/calendar?main.rtresume=%2Fcalendar&main.cal=we&main.id=[text_1]&main.ctrl=eventmgr.detail&main.view=calendar.detail';
  $handler->display->display_options['fields']['text']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['text']['element_type'] = 'h5';
  $handler->display->display_options['fields']['text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text']['xpath_selector'] = 'title';
  $handler->display->display_options['fields']['text']['multiple'] = 0;
  /* Field: startDate: Date */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'xml';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  $handler->display->display_options['fields']['date']['label'] = '';
  $handler->display->display_options['fields']['date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['date']['xpath_selector'] = 'startDate';
  $handler->display->display_options['fields']['date']['multiple'] = 0;
  $handler->display->display_options['fields']['date']['date_format'] = 'custom';
  $handler->display->display_options['fields']['date']['custom_date_format'] = 'l, F j, Y';
  /* Field: timeLine: Markup */
  $handler->display->display_options['fields']['markup']['id'] = 'markup';
  $handler->display->display_options['fields']['markup']['table'] = 'xml';
  $handler->display->display_options['fields']['markup']['field'] = 'markup';
  $handler->display->display_options['fields']['markup']['label'] = '';
  $handler->display->display_options['fields']['markup']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['markup']['xpath_selector'] = 'timeLine';
  $handler->display->display_options['fields']['markup']['multiple'] = 0;
  $handler->display->display_options['fields']['markup']['format'] = 'full_html';
  $handler->display->display_options['block_description'] = 'Writing Center Event List View';

  /* Display: Student Org Career Event List Block */
  $handler = $view->new_display('block', 'Student Org Career Event List Block', 'block_62');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Event List View';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=orgjob';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'date',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<h2>Upcoming Events</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: id: Text */
  $handler->display->display_options['fields']['text_1']['id'] = 'text_1';
  $handler->display->display_options['fields']['text_1']['table'] = 'xml';
  $handler->display->display_options['fields']['text_1']['field'] = 'text';
  $handler->display->display_options['fields']['text_1']['label'] = '';
  $handler->display->display_options['fields']['text_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['text_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text_1']['xpath_selector'] = 'id';
  $handler->display->display_options['fields']['text_1']['multiple'] = 0;
  /* Field: title: Text */
  $handler->display->display_options['fields']['text']['id'] = 'text';
  $handler->display->display_options['fields']['text']['table'] = 'xml';
  $handler->display->display_options['fields']['text']['field'] = 'text';
  $handler->display->display_options['fields']['text']['label'] = '';
  $handler->display->display_options['fields']['text']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['text']['alter']['path'] = 'http://www.law.columbia.edu/calendar?main.rtresume=%2Fcalendar&main.cal=we&main.id=[text_1]&main.ctrl=eventmgr.detail&main.view=calendar.detail';
  $handler->display->display_options['fields']['text']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['text']['element_type'] = 'h5';
  $handler->display->display_options['fields']['text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text']['xpath_selector'] = 'title';
  $handler->display->display_options['fields']['text']['multiple'] = 0;
  /* Field: startDate: Date */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'xml';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  $handler->display->display_options['fields']['date']['label'] = '';
  $handler->display->display_options['fields']['date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['date']['xpath_selector'] = 'startDate';
  $handler->display->display_options['fields']['date']['multiple'] = 0;
  $handler->display->display_options['fields']['date']['date_format'] = 'custom';
  $handler->display->display_options['fields']['date']['custom_date_format'] = 'l, F j, Y';
  /* Field: timeLine: Markup */
  $handler->display->display_options['fields']['markup']['id'] = 'markup';
  $handler->display->display_options['fields']['markup']['table'] = 'xml';
  $handler->display->display_options['fields']['markup']['field'] = 'markup';
  $handler->display->display_options['fields']['markup']['label'] = '';
  $handler->display->display_options['fields']['markup']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['markup']['xpath_selector'] = 'timeLine';
  $handler->display->display_options['fields']['markup']['multiple'] = 0;
  $handler->display->display_options['fields']['markup']['format'] = 'full_html';
  $handler->display->display_options['block_description'] = 'Student Org Career Event List View';

  /* Display: Student Org Career Past Event List Block */
  $handler = $view->new_display('block', 'Student Org Career Past Event List Block', 'block_63');
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['xml_file'] = 'http://www.law.columbia.edu/event-xml-feed?global.tag=orgjob&main.timeframe=past';
  $handler->display->display_options['query']['options']['row_xpath'] = '/rtsb/items/item';
  $handler->display->display_options['query']['options']['show_errors'] = 1;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'date',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['content'] = '<h2>Past Events</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: id: Text */
  $handler->display->display_options['fields']['text_1']['id'] = 'text_1';
  $handler->display->display_options['fields']['text_1']['table'] = 'xml';
  $handler->display->display_options['fields']['text_1']['field'] = 'text';
  $handler->display->display_options['fields']['text_1']['label'] = '';
  $handler->display->display_options['fields']['text_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['text_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text_1']['xpath_selector'] = 'id';
  $handler->display->display_options['fields']['text_1']['multiple'] = 0;
  /* Field: title: Text */
  $handler->display->display_options['fields']['text']['id'] = 'text';
  $handler->display->display_options['fields']['text']['table'] = 'xml';
  $handler->display->display_options['fields']['text']['field'] = 'text';
  $handler->display->display_options['fields']['text']['label'] = '';
  $handler->display->display_options['fields']['text']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['text']['alter']['path'] = 'http://www.law.columbia.edu/calendar?main.rtresume=%2Fcalendar&main.cal=we&main.id=[text_1]&main.ctrl=eventmgr.detail&main.view=calendar.detail';
  $handler->display->display_options['fields']['text']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['text']['element_type'] = 'h5';
  $handler->display->display_options['fields']['text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text']['xpath_selector'] = 'title';
  $handler->display->display_options['fields']['text']['multiple'] = 0;
  /* Field: startDate: Date */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'xml';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  $handler->display->display_options['fields']['date']['label'] = '';
  $handler->display->display_options['fields']['date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['date']['xpath_selector'] = 'startDate';
  $handler->display->display_options['fields']['date']['multiple'] = 0;
  $handler->display->display_options['fields']['date']['date_format'] = 'custom';
  $handler->display->display_options['fields']['date']['custom_date_format'] = 'l, F j, Y';
  /* Field: timeLine: Markup */
  $handler->display->display_options['fields']['markup']['id'] = 'markup';
  $handler->display->display_options['fields']['markup']['table'] = 'xml';
  $handler->display->display_options['fields']['markup']['field'] = 'markup';
  $handler->display->display_options['fields']['markup']['label'] = '';
  $handler->display->display_options['fields']['markup']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['markup']['xpath_selector'] = 'timeLine';
  $handler->display->display_options['fields']['markup']['multiple'] = 0;
  $handler->display->display_options['fields']['markup']['format'] = 'full_html';
  $handler->display->display_options['block_description'] = 'Student Org Career Past Event List View';
  $export['event_views'] = $view;

  return $export;
}
