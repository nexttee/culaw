<?php
/**
 * @file
 * cls_news_articles.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function cls_news_articles_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'news_article_cls_introduction_block';
  $context->description = 'This context places "news article introduction block" for news page.';
  $context->tag = 'news';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'news_article' => 'news_article',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'theme' => array(
      'values' => array(
        'cls' => 'cls',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-news_article_cls_intro_block' => array(
          'module' => 'boxes',
          'delta' => 'news_article_cls_intro_block',
          'region' => 'content_bottom',
          'weight' => '10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('This context places "news article introduction block" for news page.');
  t('news');
  $export['news_article_cls_introduction_block'] = $context;

  return $export;
}
