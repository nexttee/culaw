<?php
/**
 * @file
 * Registration for migrations defined by cls_news_articles module.
 */

/**
 * Implements hook_migrate_api().
 */
function cls_news_articles_migrate_api() {
  $api = array(
    'api' => 2,
    'migrations' => array(
      'RtsbNewsContent' => array(
        'class_name' => 'RtsbNewsContentMigration',
        'group_name' => 'rtsb_paragraphs',
        'object_type' => 'rt_content',
        'owner_module' => 'apc',
        'default_status' => 0,
      ),
      'RtsbNewsPage' => array(
        'class_name' => 'RtsbNewsPageMigration',
        'group_name' => 'rtsb_content',
        'object_type' => 'rt_pages',
        'owner_module' => 'pages',
        'default_status' => 0,
      ),
    ),
  );

  return $api;
}
