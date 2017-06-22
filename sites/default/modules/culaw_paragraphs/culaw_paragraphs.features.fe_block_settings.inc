<?php
/**
 * @file
 * culaw_paragraphs.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function culaw_paragraphs_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['boxes-event_listing_archive'] = array(
    'cache' => -2,
    'custom' => 0,
    'delta' => 'event_listing_archive',
    'module' => 'boxes',
    'node_types' => array(),
    'pages' => 'news-listing*',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'culaw' => array(
        'region' => 'sub_content',
        'status' => 1,
        'theme' => 'culaw',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['menu_block-1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 1,
    'module' => 'menu_block',
    'node_types' => array(
      0 => 'enhanced_page',
    ),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'culaw' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'culaw',
        'weight' => -64,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
