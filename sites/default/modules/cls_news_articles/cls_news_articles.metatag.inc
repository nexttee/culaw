<?php
/**
 * @file
 * cls_news_articles.metatag.inc
 */

/**
 * Implements hook_metatag_config_default().
 */
function cls_news_articles_metatag_config_default() {
  $export = array();

  $config = new stdClass();
  $config->disabled = FALSE; /* Edit this to true to make a default config disabled initially */
  $config->api_version = 1;
  $config->cid = '3';
  $config->instance = 'node:news_article';
  $config->config = array(
    'description' => array(
      'value' => '[node:field-description]',
    ),
    'og:description' => array(
      'value' => '[node:field-description]',
    ),
  );
  $export['node:news_article'] = $config;

  return $export;
}
