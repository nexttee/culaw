<?php

/**
 * Implements hook_views_default_views().
 **/
function cls_aces2_views_default_views() {
  $files = file_scan_directory(drupal_get_path('module', 'cls_aces2'). '/views', '/.views/');
  foreach ($files as $filepath => $file) {
    require $filepath;
    if (isset($view)) {
      $views[$view->name] = $view;
    }
  }
  return $views;
}