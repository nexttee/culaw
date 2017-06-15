<?php
/**
 * @file
 * culaw_paragraphs.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function culaw_paragraphs_ctools_plugin_api($module = NULL, $api = NULL) {
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
      5 => array(
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => 1600,
          'height' => 630,
          'anchor' => 'center-center',
          'disable_scale' => 0,
          'jcrop_settings' => array(
            'aspect_ratio' => '',
            'bgcolor' => 'black',
            'bgopacity' => 0.6,
            'fallback' => 0,
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: banner_mobile_style.
  $styles['banner_mobile_style'] = array(
    'label' => 'Banner Mobile Style',
    'effects' => array(
      6 => array(
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => 800,
          'height' => 900,
          'anchor' => 'center-center',
          'disable_scale' => 0,
          'jcrop_settings' => array(
            'aspect_ratio' => '',
            'bgcolor' => 'black',
            'bgopacity' => 0.6,
            'fallback' => 0,
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: banner_tablet_style.
  $styles['banner_tablet_style'] = array(
    'label' => 'Banner Tablet Style',
    'effects' => array(
      7 => array(
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => 1550,
          'height' => 800,
          'anchor' => 'center-center',
          'disable_scale' => 0,
          'jcrop_settings' => array(
            'aspect_ratio' => '',
            'bgcolor' => 'black',
            'bgopacity' => 0.6,
            'fallback' => 0,
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: flexible_grid.
  $styles['flexible_grid'] = array(
    'label' => 'flexible_grid',
    'effects' => array(
      4 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 250,
          'height' => 250,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 1,
      ),
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
      2 => array(
        'name' => 'focal_point_crop',
        'data' => array(
          'width' => 1200,
          'height' => 350,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 2,
      ),
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
