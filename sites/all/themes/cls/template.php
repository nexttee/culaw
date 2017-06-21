<?php
/**
 * @file
 * CLS theme override of the default HTML output of Drupal.
 */

/**
 * Auto-rebuild the theme registry during theme development.
 */
if (theme_get_setting('cls|themedev|rebuild_registry') && !defined('MAINTENANCE_MODE')) {
  // Rebuild .info data.
  system_rebuild_theme_data();
  // Rebuild theme registry.
  drupal_theme_rebuild();
}

/**
 * Override or insert variables into the page template.
 *
 * Implements template_preprocess_page
 */
function cls_preprocess_page(&$variables) {
  /**
   * Remove errant class in the $classes variable on the page template
   */
  $variables['classes_array'] = cls_remove_item_by_value($variables['classes_array'], 'contextual-links-region', FALSE);

  // $node = $variables['node'];
  // dpm($node);

  // if(isset($node->field_topics['und'])) {
  //   $terms = $node->field_topics['und'];

  //   // Figure out which vocab.
  //   $vid = $terms[0]['taxonomy_term']->vid;
  //   $vocabulary_name = $terms[0]['taxonomy_term']->vocabulary_machine_name;

  //   //$topics = taxonomy_get_term_by_name('Topics', $vocabulary_name);

  //   dpm($terms);

  //   //$types = taxonomy_get_term_by_name('Article Type', $vocabulary_name);

  //   $tree = taxonomy_get_tree($vid);

  //   $all_terms = array();

  //   // Get the root terms.
  //   $root = array();





  //   // Get root terms  Topic and Type
  //   foreach ($tree as $index => $term) {

  //    if($term->parents[0] == 0) {
  //      $root[$term->tid]  = $term;
  //    }

  //     $all_terms[$term->tid] = $term;

  //   }

  //   dpm($root);
  //   dpm($all_terms);

  //   $print_terms = array();

  //   foreach ($terms as $key => $term) {

  //     $parent_tid = $all_terms[$term['tid']]->parents[0];

  //     // If it is in root array.
  //     if(in_array($parent_tid , array_keys($root)) &&  $parent_tid != 0) {
  //       $print_terms[$all_terms[$parent_tid]->name][] = $term;
  //     }
  //     else if(!in_array($parent_tid , array_keys($root)) && $parent_tid > 0) {
  //       $print_terms[$all_terms[$parent_tid]->name][] = $term;
  //     }
  //     else {

  //     }




  //   }

  //   dpm($print_terms);

  //   // $types = taxonomy_get_tree($vid, $types_tid);
  //   //dpm($all_terms);
  //   //dpm($tree);
  // }
  if (array_key_exists('node', $variables)) {
    // Reset title to allow safe HTML
    $variables['title'] = check_markup($variables['node']->title, 'full_html');
    drupal_set_title($variables['head_title']);
  }

  if ($variables['node']->type == 'news_article') {
    $variables['theme_hook_suggestions'][] = 'page__media_inquiries__news_events';
  }
}


/**
 * Override or insert variables into the page template.
 *
 * Implements template_process_page
 */
function cls_process_page(&$variables) {
	$path = drupal_get_path_alias($_GET['q']); //get URL alias
	$path = explode('/', $path); //break path into an array
	if ( !empty($path[0]) && $path[0] == 'explore-columbia-law-school' ) {
	/**
	* X-UA-Compatible
	*/
	$element = array(
	 '#tag' => 'meta', // The #tag is the html tag - <meta />
	 '#attributes' => array( // Set up an array of attributes inside the tag
	   'name' => 'viewport',
	   'content' => 'width=device-width, initial-scale=1.0',
	),
	);

	drupal_add_html_head($element, 'viewport');
	}

	$element = array(
	   '#tag' => 'meta', // The #tag is the html tag - <meta />
	   '#attributes' => array( // Set up an array of attributes inside the tag
		 'http-equiv' => 'X-UA-Compatible',
		 'content' => 'IE=8;FF=3;OtherUA=4',
	  ),
	 );

	drupal_add_html_head($element, 'x_ua_compatible');

}

function cls_preprocess_html(&$variables) {
  $variables['classes_array'][] = 'allow-cls-print';

  if( current_path() == 'public-directory' ){
    drupal_add_library('system', 'ui.autocomplete');
  }
}

/**
 * Override or insert variables into the page template.
 *
 * Implements template_process_page
 */
function cls_process_html(&$variables) {
  $path = drupal_get_path_alias($_GET['q']); //get URL alias
  $path = explode('/', $path); //break path into an array
  if ( !empty($path[0]) && $path[0] == 'donor-report' ) {
    $new_classes = $variables['classes_array'];
    $target_index = array_search ( 'allow-cls-print' , $new_classes);
    unset($new_classes[$target_index]);
    $variables['classes_array'] = $new_classes;
    $variables['classes'] = str_replace(' allow-cls-print', '' , $variables['classes']);
  }
}

/**
 * Removes an array item by value.
 */
function cls_remove_item_by_value($array, $val = '', $preserve_keys = TRUE) {
  if (empty($array) || !is_array($array)) return FALSE;
  if (!in_array($val, $array)) return $array;

  foreach ($array as $key => $value) {
    if ($value == $val) unset($array[$key]);
  }

  return ($preserve_keys === TRUE) ? $array : array_values($array);
}



/**
* Implements hook_menu_local_task().
*
* @param array $variables
*
* return string with html
*/
function cls_menu_local_task($variables) {
  $link = $variables['element']['#link'];
  // remove the view link when viewing the node
  if ($link['path'] == 'node/%/view') return false;
  $link['localized_options']['html'] = TRUE;
  return '<li>'.l($link['title'], $link['href'], $link['localized_options']).'</li>'."\n";
}

/**
* Implements hook_menu_local_tasks().
*
* @param array $variables
*
* return string with html
*/
function cls_menu_local_tasks(&$variables) {
  $output = '';
  $has_access = user_access('access contextual links');
  // Add contextual links js and css library
  if ($has_access) {
    drupal_add_library('contextual', 'contextual-links');
  }
  if (!empty($variables['primary'])) {
    $variables['primary']['#prefix'] = '<h2 class="element-invisible">' . t('Primary tabs') . '</h2>';
    // Only display contextual links if the user has the correct permissions enabled.
    // Otherwise, the default primary tabs will be used.
    $variables['primary']['#prefix'] = ($has_access) ?
      '<div class="contextual-links-wrapper contextual-links-wrapper-local-tasks"><ul class="contextual-links">' : '<ul class="tabs primary">';
    $variables['primary']['#suffix'] = ($has_access) ?  '</ul></div>' : '</ul>';
    $output .= drupal_render($variables['primary']);
  }
  if (!empty($variables['secondary'])) {
    $variables['secondary']['#prefix'] = '<h2 class="element-invisible">' . t('Secondary tabs') . '</h2>';
    $variables['secondary']['#prefix'] = '<ul class="tabs secondary clearfix">';
    $variables['secondary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['secondary']);
  }
  return $output;
}

function cls_preprocess_views_view(&$vars) {
  $view = $vars['view'];
  if($view->name == 'ag_document_library') {
    if ($path = libraries_get_path('chosen')) {
     drupal_add_js($path . '/chosen.jquery.js');
     drupal_add_css($path . '/chosen.css');
     drupal_add_js("jQuery(document).ready(function() {
         jQuery('.form-select').chosen({width:'100%',search_contains:true});
     });", array("type" => "inline", "scope" => "footer"));
    }
  }
}

/**
* Implements hook_form_alter().
*/
function cls_form_alter(&$form, &$form_state, $form_id) {
  if ($form_id == 'search_block_form') {
    $form['search_block_form']['#attributes']['placeholder'] = t('Search Columbia Law School');
  }
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function cls_form_views_exposed_form_alter(&$form, &$form_state) {
  //drupal_set_message("<pre>" . print_r($form, 1) . "</pre>");
  if(isset($form['#id']) && $form['#id'] == 'views-exposed-form-ag-document-library-page-1') {
    if(isset($form['items_per_page'])) {
      $form['items_per_page']['#type'] = 'radios';
      $form['items_per_page']['#attributes'] = array(
        'onchange' => "this.form.submit()",
      );
    }

    if(isset($form['field_states'])) {
      $form['field_states']['#options']['All'] = "BY STATE";
    }

    if(isset($form['field_topics'])) {
      $form['field_topics']['#options']['All'] = 'BY TOPIC';
    }

    if(isset($form['field_types'])) {
      $form['field_types']['#options']['All'] = 'ARTICLE TYPE';
    }


    if(isset($form['search_api_views_fulltext'])) {
      $form['search_api_views_fulltext']['#attributes'] = array(
        'placeholder' => 'Enter Keywords or Phrases',
      );
    }

    if(isset($form['field_publish_dates'])) {
      $form['field_publish_dates']['#attributes'] = array(
        'placeholder' => t('STARTING DATE'),
      );
    }

    if(isset($form['field_publish_dates_1'])) {
      $form['field_publish_dates_1']['#attributes'] = array(
        'placeholder' => t('ENDING DATE'),
      );
    }
    $form['#validate'][] = 'cls_ag_views_exposed_form_validate';
    //dpm($form);
  }
}

/**
 * Drupal form validate handler.
 */
function cls_ag_views_exposed_form_validate($form, &$form_state) {
  $values = $form_state['values'];
  if(!empty($values['field_publish_dates'])) {
    if(is_numeric($values['field_publish_dates']) && strlen($values['field_publish_dates']) != 4) {
      form_set_error("field_publish_dates", t("The Start date should contain a numeric value"));
    }
    // elseif(!is_numeric($values['field_publish_dates'])) {
    //   form_set_error("field_publish_dates", "Start date must be a numerice value");
    // }
  }

  if(!empty($values['field_publish_dates_1'])) {
    if(is_numeric($values['field_publish_dates_1']) && strlen($values['field_publish_dates_1']) != 4) {
      form_set_error("field_publish_dates_1", t("The End date should contain a numeric value"));
    }
    // elseif(!is_numeric($values['field_publish_dates_1'])) {
    //   form_set_error("field_publish_dates_1", "End date must be a numerice value");
    // }
  }

  if(!empty($values['field_publish_dates']) && !empty($values['field_publish_dates_1']) && $values['field_publish_dates'] > $values['field_publish_dates_1']) {
    form_set_error("field_publish_dates_1", t("The Start Date should be set earlier than the End date"));
  }
}

function cls_menu_link__menu_graduate_legal_studies(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }

  $output = l($element['#title'], $element['#href'], $element['#localized_options']);

  if (!empty($element['#localized_options']['attributes']['title'])) {
    $element['#localized_options']['html'] = TRUE;
    $element['#title'] = check_plain($element['#title']);
    $element['#localized_options']['attributes']['title'] = check_plain($element['#localized_options']['attributes']['title']);
    $element['#title'] .= '<span class="description">'.$element['#localized_options']['attributes']['title'].'</span>';
    $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  }

  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

function cls_menu_link__menu_editors_tools(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }

  $output = l($element['#title'], $element['#href'], $element['#localized_options']);

  if (!empty($element['#localized_options']['attributes']['title'])) {
    $element['#localized_options']['html'] = TRUE;
    $element['#title'] = check_plain($element['#title']);
    $element['#localized_options']['attributes']['title'] = check_plain($element['#localized_options']['attributes']['title']);
    $element['#title'] .= '<span class="description">'.$element['#localized_options']['attributes']['title'].'</span>';
    $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  }

  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

/**
 * Implements theme_preprocess_node.
 */
function cls_preprocess_node(&$variables) {
  if($variables['type'] == 'cls_ag_document') {
    global $base_url;
    // $variables['node_url'] = $base_url.'/ag-document-library/document/'.$variables['nid'];
    // Fetch the ag document node's new url alias structure, instead of the old path.
    $variables['node_url'] = $base_url . '/' . drupal_get_path_alias('node' . '/' . $variables['nid']);
  }
  if (in_array($variables['type'], array('news_article', 'magazine_archive'))) {
    $variables['title'] = check_markup($variables['title'], 'full_html');
  }
}

/**
 * Implements template_preprocess_views_view_summary.
 */
function cls_preprocess_views_view_summary(&$vars) {
  $view = $vars['view'];

  // Appending content listing based on argument at the end of each row.
  // see variable $vars['rows'][$id]->content_list
  if ($view->name == 'news_archive' && $view->current_display == 'month_and_title_listing') {
    $argument = $view->argument[$view->build_info['summary_level']];
    $vars['row_classes'] = array();

    $url_options = array();

    if (!empty($view->exposed_raw_input)) {
      $url_options['query'] = $view->exposed_raw_input;
    }

    $active_urls = drupal_map_assoc(array(
      url($_GET['q'], array('alias' => TRUE)), // force system path
      url($_GET['q']), // could be an alias
    ));

    // Collect all arguments foreach row, to be able to alter them for example by the validator.
    // This is not done per single argument value, because this could cause performance problems.
    $row_args = array();
    foreach ($vars['rows'] as $id => $row) {
      $row_args[$id] = $argument->summary_argument($row);
    }
    $argument->process_summary_arguments($row_args);
    foreach ($vars['rows'] as $id => $row) {
      $vars['row_classes'][$id] = '';
      $vars['rows'][$id]->link = $argument->summary_name($row);
      $args = $view->args;
      $args[$argument->position] = $row_args[$id];

      $base_path = NULL;
      if (!empty($argument->options['summary_options']['base_path'])) {
        $base_path = $argument->options['summary_options']['base_path'];
      }
      $vars['rows'][$id]->url = url($view->get_url($args, $base_path), $url_options);
      $vars['rows'][$id]->count = intval($row->{$argument->count_alias});
      if (isset($active_urls[$vars['rows'][$id]->url])) {
        $vars['row_classes'][$id] = 'active';
      }
      $vars['rows'][$id]->month = date('n',strtotime($row->created_cls_year_month));
      $vars['rows'][$id]->content_list = '';
      if ($argument->summary_argument($row) == check_plain(arg(3))) {
        $year = filter_xss(arg(2));
        $vars['rows'][$id]->content_list = views_embed_view('news_archive', 'month_and_title_listing', $year, arg(3));
      }
    }
    if ($argument->options['summary']['sort_order'] == 'asc') {
      usort($vars['rows'], function($a, $b) {
        return $a->month > $b->month;
      });
    }
    else {
      usort($vars['rows'], function($a, $b) {
        return $a->month < $b->month;
      });
    }
    unset($vars['row_classes']);
    foreach ($vars['rows'] as $id => $row) {
      if (isset($active_urls[$vars['rows'][$id]->url])) {
        $vars['row_classes'][$id] = 'active';
      }
    }
  }
  if ($view->name == 'news_archive' && $view->current_display == 'page') {
    // Adding preprocess to sort the results based on month display.
    $argument = $view->argument[$view->build_info['summary_level']];
    $vars['row_classes'] = array();

    $url_options = array();

    if (!empty($view->exposed_raw_input)) {
      $url_options['query'] = $view->exposed_raw_input;
    }

    $active_urls = drupal_map_assoc(array(
      url($_GET['q'], array('alias' => TRUE)), // force system path
      url($_GET['q']), // could be an alias
    ));

    // Collect all arguments foreach row, to be able to alter them for example by the validator.
    // This is not done per single argument value, because this could cause performance problems.
    $row_args = array();
    foreach ($vars['rows'] as $id => $row) {
      $row_args[$id] = $argument->summary_argument($row);
    }
    $argument->process_summary_arguments($row_args);
    foreach ($vars['rows'] as $id => $row) {
      $vars['row_classes'][$id] = '';
      $vars['rows'][$id]->link = $argument->summary_name($row);
      $args = $view->args;
      $args[$argument->position] = $row_args[$id];

      $base_path = NULL;
      if (!empty($argument->options['summary_options']['base_path'])) {
        $base_path = $argument->options['summary_options']['base_path'];
      }
      $vars['rows'][$id]->url = url($view->get_url($args, $base_path), $url_options);
      $vars['rows'][$id]->count = intval($row->{$argument->count_alias});
      if (isset($active_urls[$vars['rows'][$id]->url])) {
        $vars['row_classes'][$id] = 'active';
      }
      $vars['rows'][$id]->month = date('n',strtotime($row->created_cls_year_month));
    }
    if ($argument->options['summary']['sort_order'] == 'asc') {
      usort($vars['rows'], function($a, $b) {
        return $a->month > $b->month;
      });
    }
    else {
      usort($vars['rows'], function($a, $b) {
        return $a->month < $b->month;
      });
    }
  }
}
