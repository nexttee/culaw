<?php

/**
 * @file
 * Template overrides as well as (pre-)process and alter hooks for the
 * culaw theme.
 */

function culaw_menu_link__menu_block($variables) {
  //dpm($variables);
  return theme_menu_link($variables);
}

function culaw_menu_tree__menu_block__main_menu($vars) {
    return '<ul class="subnavigation-wrap__subnavigation-links list-unstyled">' . $vars['tree'] . '</ul>';
}

function culaw_menu_tree__menu_block__main_menu_inner($vars) {
    return '<ul class="subnavigation-wrap__links-dropdown list-unstyled">' . $vars['tree'] . '</ul>';
}

/**
 * Add the title prefix and suffix for the footer menu block titles.
 */

function culaw_preprocess_block(&$variables) {

    if ($variables['elements']['#block']->bid == 'views-bbd200d728aff13c6e83d98fe8686bb0') {
      $variables['classes_array'][] = drupal_html_class('quotes__slideshow');
    }

    if ($variables['elements']['#block']->bid == 'views-b11a8f2b59c7f3cda69adcc0ea9c7460') {
      $variables['classes_array'][] = drupal_html_class('community__block');
    }

    if ($variables['elements']['#block']->bid == 'views-cdb11e70cc8297d2aa5d2341b9cb8c59') {
      $variables['classes_array'][] = drupal_html_class('admission__block');
    }
}

/**
* Implements template_preprocess_page().
*/
function culaw_preprocess_page(&$variables) {
  if (array_key_exists('user', $variables)) {

    if (isset($variables['page']['content']['system_main']['cls_user_first_name'])) {
      $name_first = $variables['page']['content']['system_main']['cls_user_first_name'];
    }

    if (isset($variables['page']['content']['system_main']['cls_user_middle_name'])) {
      $name_middle = $variables['page']['content']['system_main']['cls_user_middle_name'];
    }

    if (isset($variables['page']['content']['system_main']['cls_user_last_name'])) {
      $name_last = $variables['page']['content']['system_main']['cls_user_last_name'];
    }

    if (isset($variables['page']['content']['system_main']['cls_user_suffix'])) {
      $suffix = $variables['page']['content']['system_main']['cls_user_suffix'];
    }

    if (isset($variables['page']['content']['system_main']['cls_user_title'])) {
      $user_summary = $variables['page']['content']['system_main']['cls_user_title'];
    }

    $variables['first_name'] = NULL;
    $variables['middle_name'] = NULL;
    $variables['last_name'] = NULL;
    $variables['suffix'] = NULL;
    $variables['user_summary'] = NULL;

    if (isset($name_first)) {
      $variables['first_name'] = check_plain($name_first[0]['#markup']);
    }

    if (isset($name_middle)) {
      $variables['middle_name'] = check_plain($name_middle[0]['#markup']);
    }

    if (isset($name_last)) {
      $variables['last_name'] = check_plain($name_last[0]['#markup']);
    }

    if (isset($suffix)) {
      $variables['suffix'] = check_plain($suffix[0]['#markup']);
    }

    if (isset($user_summary)) {
      $variables['user_summary']  = check_markup($user_summary[0]['#markup'] , 'full_html');
    }
  }

  if (theme_get_setting('site_announcement_status')) {
    $message = theme_get_setting('site_announcement_message');
    $variables['cls_site_announcement'] = check_markup($message, 'full_html');
  }

  if (array_key_exists('node', $variables)) {
    if ($variables['node']->type == 'calendar') {
      $variables['theme_hook_suggestions'][] = 'page__node_' . $variables['node']->type;
    } else {
      $variables['theme_hook_suggestions'][] = 'page__' . $variables['node']->type;
    }
    $variables['title'] = check_markup($variables['node']->title, 'full_html');
  }
}

/**
* Customize the date field.
*/
function culaw_date_display_single($variables) {
  if($variables['dates']['format'] == "M d") {
    $date = $variables['dates']['value']['formatted_iso'];
    $timezone = $variables['timezone'];
    $attributes = $variables['attributes'];

    // Set variables
    $day = format_date(strtotime($date), 'custom', 'd');
    $month = format_date(strtotime($date), 'custom', 'M');

    // Wrap the result with the attributes.
    return '<span class="date-display-single"' . drupal_attributes($attributes) . '>' . '<span class="month">' . $month . '</span>' . '<span class="day">' . $day . '</span>' . $timezone . '</span>';
  }
  else {
    // Displaying default format. see theme_date_display_single() in date.theme
    // file.
    $date = $variables['date'];
    $timezone = $variables['timezone'];
    $attributes = $variables['attributes'];

    // Wrap the result with the attributes.
    $output = '<span class="date-display-single"' . drupal_attributes($attributes) . '>' . $date . $timezone . '</span>';

    if (!empty($variables['add_microdata'])) {
      $output .= '<meta' . drupal_attributes($variables['microdata']['value']['#attributes']) . '/>';
    }
    return $output;
  }
}

/**
 * Preprocess the primary theme implementation for a view.
 */
function culaw_preprocess_views_view(&$vars) {
  global $base_path;
  $view = $vars['view'];
  $vars['exposed_filter_result_text'] = '';
  if ($view->name == 'law_school_events' && $view->current_display == 'events_listing_page') {
    if (!empty($view->exposed_raw_input['title'])) {
      $vars['exposed_filter_term'] = '<span class="search-term">' . $view->exposed_raw_input['title'] . '</span>';
      $vars['exposed_filter_result_text'] = '<span class="filter__results">' . t('!count for !term', array('!count' => format_plural(count($view->result), '@count result', '@count results'), '!term' => $vars['exposed_filter_term'])) . '<span>';
      $vars['view_all_events'] = l(t('View All Events'), 'events', array('query' => array('display' => 'month')));
    }
  }
  if ($view->name == 'faculty_listing') {
    if (!empty($view->exposed_raw_input['search'])) {
      $vars['exposed_filter_term'] = '<span class="search-term">' . $view->exposed_raw_input['search'] . '</span>';
      $vars['exposed_filter_result_text'] = '<span class="filter__results">' . t('Your search returned !count for !term', array('!count' => format_plural(count($view->result), '@count result', '@count results'), '!term' => $vars['exposed_filter_term'])) . '<span>';
      $vars['back_to_full_list'] = l(t('Back to Full List'), 'faculty');
    }
  }
}

/**
 * Implements template_preprocess_maintenance_page().
 */
function culaw_preprocess_maintenance_page(&$variables) {
  // Overriding values for offline maintenance page tpl file. So that it should
  // not display other error messages. These variables will be used in
  // maintenance-page-offline.tpl.php file.
  if (isset($variables['db_is_active']) && !$variables['db_is_active']) {
    $default_message = t('<h1>Updates in Progress</h1>
<p>We’re sorry for the brief downtime. Please check back with us shortly.</p>');
    $variables['content'] = $default_message;
    $variables['head_title_array'] = array(
      'title' => t('Site under maintenance'),
      'name' => t('Columbia Law School '),
    );
    $variables['head_title'] = implode(' | ', $variables['head_title_array']);
  }
}

/**
 * Theme the calendar title.
 */
function culaw_date_nav_title($params) {
  $granularity = $params['granularity'];
  $view = $params['view'];
  $date_info = $view->date_info;
  $link = !empty($params['link']) ? $params['link'] : FALSE;
  $format = !empty($params['format']) ? $params['format'] : NULL;
  $format_with_year = variable_get('date_views_' . $granularity . 'format_with_year', 'l, F j, Y');
  $format_without_year = variable_get('date_views_' . $granularity . 'format_without_year', 'l, F j');
  switch ($granularity) {
    case 'year':
      $title = $date_info->year;
      $date_arg = $date_info->year;
      break;
    case 'month':
      $format = !empty($format) ? $format : (empty($date_info->mini) ? $format_with_year : $format_without_year);
      if ($view->name == 'law_school_events' && ($view->current_display == 'block_1' || $view->current_display == 'events_listing_page')) {
        $format = 'F Y';
      }
      $title = date_format_date($date_info->min_date, 'custom', $format);
      $date_arg = $date_info->year . '-' . date_pad($date_info->month);
      break;
    case 'day':
      $format = !empty($format) ? $format : (empty($date_info->mini) ? $format_with_year : $format_without_year);
      $title = date_format_date($date_info->min_date, 'custom', $format);
      $date_arg = $date_info->year . '-' . date_pad($date_info->month) . '-' . date_pad($date_info->day);
      break;
    case 'week':
      $format = !empty($format) ? $format : (empty($date_info->mini) ? $format_with_year : $format_without_year);
      $title = t('Week of @date', array('@date' => date_format_date($date_info->min_date, 'custom', $format)));
      if ($view->name == 'law_school_events' && $view->current_display == 'events_listing_page') {
        $title = t('@date_start - @date_end', array(
          '@date_start' => date_format_date($date_info->min_date, 'custom', $format),
          '@date_end' => date_format_date($date_info->max_date, 'custom', $format))
        );
      }
      $date_arg = $date_info->year . '-W' . date_pad($date_info->week);
      break;
  }
  if (!empty($date_info->mini) || $link) {
    // Month navigation titles are used as links in the mini view.
    $attributes = array('title' => t('View full page month'));
    $url = date_pager_url($view, $granularity, $date_arg, TRUE);
    return l($title, $url, array('attributes' => $attributes));
  }
  else {
    return $title;
  }
}

/**
 * Implements theme_preprocess_node.
 */
function culaw_preprocess_node(&$variables) {
  if (in_array($variables['type'], array('news_article', 'magazine_archive'))) {
    $variables['title'] = check_markup($variables['title'], 'full_html');
  }
}

/**
 * Implements hook_form_alter().
 */
function culaw_form_alter(&$form, &$form_state, $form_id) {
  if ($form_id == 'google_cse_results_searchbox_form') {
    $form['query']['#attributes']['placeholder'] = t('Search');
  }

  if (($form_id == 'views_exposed_form') && ($form['#id'] == 'views-exposed-form-law-school-events-events-listing-page')) {
    if (isset($form['title'])) {
      $form['title']['#attributes'] = array('placeholder' => array(t('Search for an event')));
    }
  }

  if (($form_id == 'views_exposed_form') && ($form['#id'] == 'views-exposed-form-faculty-listing-listing-page')) {
    $form['search']['#attributes']['placeholder'] = t('Search Faculty');
  }
}

/**
 * Create the calendar date box.
 */
function culaw_preprocess_calendar_datebox(&$vars) {
  $date = $vars['date'];
  $view = $vars['view'];
  $vars['day'] = intval(substr($date, 8, 2));
  $force_view_url = !empty($view->date_info->block) ? TRUE : FALSE;
  $month_path = calendar_granularity_path($view, 'month');
  $year_path = calendar_granularity_path($view, 'year');
  $day_path = calendar_granularity_path($view, 'day');
  $vars['url'] = str_replace(array($month_path, $year_path), $day_path, date_pager_url($view, NULL, $date, $force_view_url));
  // Replacing month and week arguments with day argument.
  if ($view->name == 'law_school_events' && $view->current_display == 'block_1') {
    if (stristr($vars['url'], 'week')) {
      $vars['url'] = str_replace('display=week', 'display=day', $vars['url']);
    }
    else if (stristr($vars['url'], 'month')) {
      $vars['url'] = str_replace('display=month', 'display=day', $vars['url']);
    }
    $params = drupal_get_query_parameters();
    if (empty($params)) {
      $vars['link'] = !empty($day_path) ? l($vars['day'], $vars['url'], array('query' => array('display' => 'day'))) : $vars['day'];
    }
    else {
      $vars['link'] = !empty($day_path) ? l($vars['day'], $vars['url']) : $vars['day'];
    }
  }
  else {
    $vars['link'] = !empty($day_path) ? l($vars['day'], $vars['url'], array('query' => array('display' => 'day'))) : $vars['day'];
  }
  $vars['granularity'] = $view->date_info->granularity;
  $vars['mini'] = !empty($view->date_info->mini);
  if ($vars['mini']) {
    if (!empty($vars['selected'])) {
      $vars['class'] = 'mini-day-on';
    }
    else {
      $vars['class'] = 'mini-day-off';
    }
    if ($view->name == 'law_school_events' && $view->current_display == 'block_1') {
      if (arg(1) === $date) {
        $vars['class'] .= ' active-day';
      }
    }
  }
  else {
    $vars['class'] = 'day';
  }
}
