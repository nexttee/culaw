<?php
/**
 * @file
 * cls_news_articles.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cls_news_articles_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "metatag" && $api == "metatag") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function cls_news_articles_node_info() {
  $items = array(
    'news_article' => array(
      'name' => t('News Article'),
      'base' => 'node_content',
      'description' => t('News articles appearing in the News section.'),
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
function cls_news_articles_paragraphs_info() {
  $items = array(
    'news_article_blocks' => array(
      'name' => 'News Article Blocks',
      'bundle' => 'news_article_blocks',
      'locked' => '1',
    ),
  );
  return $items;
}
