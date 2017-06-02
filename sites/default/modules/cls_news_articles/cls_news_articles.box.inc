<?php
/**
 * @file
 * cls_news_articles.box.inc
 */

/**
 * Implements hook_default_box().
 */
function cls_news_articles_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'news_article_cls_intro_block';
  $box->plugin_key = 'simple';
  $box->title = '###';
  $box->description = 'News Article CLS Introduction Block';
  $box->options = array(
    'body' => array(
      'value' => '<p><a href="https://www.law.columbia.edu/">Columbia Law School</a>, founded in 1858, stands at the forefront of legal education and of the law in a global society. Columbia Law School combines traditional strengths in corporate law and financial regulation, international and comparative law, property, contracts, constitutional law, and administrative law with pioneering work in intellectual property, digital technology, tax law and policy, national security, human rights, sexuality and gender, and environmental law.</p><p>Join us on&nbsp;<a href="http://www.facebook.com/pages/Columbia-Law-School-Alumni/72602371663">Facebook</a><br />Follow us on Twitter:&nbsp;<a href="http://twitter.com/columbialaw">www.twitter.com/columbialaw</a></p>',
      'format' => 'full_html',
    ),
  );
  $export['news_article_cls_intro_block'] = $box;

  return $export;
}
