<?php
/**
 * @file
 * culaw_paragraphs.box.inc
 */

/**
 * Implements hook_default_box().
 */
function culaw_paragraphs_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'event_listing_archive';
  $box->plugin_key = 'simple';
  $box->title = 'News Archive ';
  $box->description = 'Archive links for News Listing';
  $box->options = array(
    'body' => array(
      'value' => '<ul><li><a href="/news-listing/2017/months">2017</a></li><li><a href="/news-listing/2016/months">2016</a></li><li><a href="/news-listing/2015/months">2015</a></li><li><a href="/news-listing/2014/months">2014</a></li></ul>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['event_listing_archive'] = $box;

  return $export;
}
