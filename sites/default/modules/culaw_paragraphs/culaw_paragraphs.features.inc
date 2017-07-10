<?php
/**
 * @file
 * culaw_paragraphs.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function culaw_paragraphs_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function culaw_paragraphs_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function culaw_paragraphs_image_default_styles() {
  $styles = array();

  // Exported image style: banner_desktop_style.
  $styles['banner_desktop_style'] = array(
    'label' => 'Banner Desktop Style',
    'effects' => array(
      5 => NULL,
    ),
  );

  // Exported image style: banner_mobile_style.
  $styles['banner_mobile_style'] = array(
    'label' => 'Banner Mobile Style',
    'effects' => array(
      6 => NULL,
    ),
  );

  // Exported image style: banner_tablet_style.
  $styles['banner_tablet_style'] = array(
    'label' => 'Banner Tablet Style',
    'effects' => array(
      7 => NULL,
    ),
  );

  // Exported image style: flexible_grid.
  $styles['flexible_grid'] = array(
    'label' => 'flexible_grid',
    'effects' => array(
      4 => NULL,
    ),
  );

  // Exported image style: responsive_1200w.
  $styles['responsive_1200w'] = array(
    'label' => 'responsive_1200w',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1200,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
      2 => NULL,
    ),
  );

  // Exported image style: round_250w.
  $styles['round_250w'] = array(
    'label' => 'round_250w',
    'effects' => array(
      3 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 250,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function culaw_paragraphs_node_info() {
  $items = array(
    'enhanced_page' => array(
      'name' => t('Enhanced Page'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'landing_page' => array(
      'name' => t('Landing Page'),
      'base' => 'node_content',
      'description' => t('Used for created flexible content layouts.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_paragraphs_info().
 */
function culaw_paragraphs_paragraphs_info() {
  $items = array(
    'feed_card' => array(
      'name' => 'Feed Card',
      'bundle' => 'feed_card',
      'locked' => '1',
    ),
    'layout_row' => array(
      'name' => 'Layout Row',
      'bundle' => 'layout_row',
      'locked' => '1',
    ),
    'media_card' => array(
      'name' => 'Media Card',
      'bundle' => 'media_card',
      'locked' => '1',
    ),
    'navigation_row' => array(
      'name' => 'Navigation Row',
      'bundle' => 'navigation_row',
      'locked' => '1',
    ),
    'quick_links_card' => array(
      'name' => 'Quick Links Card',
      'bundle' => 'quick_links_card',
      'locked' => '1',
    ),
    'section_navigation_card' => array(
      'name' => 'Section Navigation Card',
      'bundle' => 'section_navigation_card',
      'locked' => '1',
    ),
    'social_media_card' => array(
      'name' => 'Social Media Card',
      'bundle' => 'social_media_card',
      'locked' => '1',
    ),
    'sticky_navigation_card' => array(
      'name' => 'Sticky Navigation Card',
      'bundle' => 'sticky_navigation_card',
      'locked' => '1',
    ),
    'text_card' => array(
      'name' => 'Text Card',
      'bundle' => 'text_card',
      'locked' => '1',
    ),
  );
  return $items;
}

/**
 * Implements hook_themekey_features_rule_chain().
 */
function culaw_paragraphs_themekey_features_rule_chain() {
if (!defined('THEMEKEY_PAGECACHE_UNSUPPORTED')) {
    define('THEMEKEY_PAGECACHE_UNSUPPORTED', 0);
    define('THEMEKEY_PAGECACHE_SUPPORTED', 1);
    define('THEMEKEY_PAGECACHE_TIMEBASED', 2);
  }
$rules = array(
  0 => array(
    'rule' => array(
      'property' => 'node:type',
      'operator' => '=',
      'value' => 'landing_page',
      'theme' => 'culaw',
      'enabled' => 1,
      'wildcards' => 'a:0:{}',
      'module' => 'culaw_paragraphs',
    ),
    'string' => '"node:type = landing_page >>> culaw"',
    'childs' => array(),
  ),
  1 => array(
    'rule' => array(
      'property' => 'node:type',
      'operator' => '=',
      'value' => 'enhanced_page',
      'theme' => 'culaw',
      'enabled' => 1,
      'wildcards' => 'a:0:{}',
      'module' => 'culaw_paragraphs',
    ),
    'string' => '"node:type = enhanced_page >>> culaw"',
    'childs' => array(),
  ),
  2 => array(
    'rule' => array(
      'property' => 'drupal:path',
      'operator' => '=',
      'value' => 'news-listing',
      'theme' => 'culaw',
      'enabled' => 1,
      'wildcards' => array(),
      'module' => 'culaw_paragraphs',
    ),
    'string' => '"drupal:path = news-listing >>> culaw"',
    'childs' => array(),
  ),
  3 => array(
    'rule' => array(
      'property' => 'drupal:path',
      'operator' => '=',
      'value' => 'news-listing/%',
      'theme' => 'culaw',
      'enabled' => 1,
      'wildcards' => array(),
      'module' => 'culaw_paragraphs',
    ),
    'string' => '"drupal:path = news-listing/% >>> culaw"',
    'childs' => array(),
  ),
  4 => array(
    'rule' => array(
      'property' => 'node:type',
      'operator' => '=',
      'value' => 'news_article',
      'theme' => 'culaw',
      'enabled' => 1,
      'wildcards' => 'a:0:{}',
      'module' => 'culaw_paragraphs',
    ),
    'string' => '"node:type = news_article >>> culaw"',
    'childs' => array(),
  ),
);

return $rules;
}
