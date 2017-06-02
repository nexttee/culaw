<?php

/**
 * @file
 * Drush integration for cls_core.
 */

/**
 * Implements hook_drush_command().
 */
function cls_core_drush_command() {
  $items = array();

  $items['cls-core-update-footer-menu-parent'] = array(
    'callback' => 'cls_core_update_footer_menu_parent',
    'description' => dt('Update the parent menu link for Mega Menu footer blocks.'),
    'aliases' => array('cls-ufmp'),
  );

  $items['cls-core-publish-news-articles'] = array(
    'callback' => 'cls_core_publish_news_article',
    'description' => dt('Publish the migrated news article that should be published'),
    'aliases' => array('cls-pna'),
  );

  $items['cls-core-publish-calendar-nodes'] = array(
    'callback' => 'cls_core_publish_calendar_nodes',
    'description' => dt('Publish the migrated calendar nodes that should be published'),
    'aliases' => array('cls-pcn'),
  );

  return $items;
}

/**
 * Drush callback for to update footer menu's parent links.
 *
 * Update the parent menu link for Mega Menu footer blocks.
 * Reason is, sometimes parent menu links can differ based on mlid. So here
 * we will retrieve particular mlid and save it in parent menu's variable.
 */
function cls_core_update_footer_menu_parent() {
  $menu_blocks_variables = array('menu_block_320_parent', 'menu_block_321_parent', 'menu_block_322_parent', 'menu_block_323_parent', 'menu_block_324_parent', 'menu_block_325_parent');
  $parent_menus = array('Admissions', 'Academics & Courses', 'Our Faculty', 'Research & Scholarship', 'Careers', 'About');
  foreach ($parent_menus AS $key => $link_title) {
    $menu = cls_core_get_menu_from_title($link_title, 'menu-main-mega-menu');
    if ($menu) {
      variable_set($menu_blocks_variables[$key], 'menu-main-mega-menu:' . $menu['mlid']);
    }
  }
}

function cls_core_publish_news_article() {
  $query = new EntityFieldQuery();
  $result = $query->entityCondition('entity_type', 'node')
                  ->entityCondition('bundle', 'news_article')
                  ->propertyCondition('status', 0)
                  ->fieldCondition('field_world_read', 'value', 1)
                  ->addMetaData('account', user_load(1))
                  ->execute();

  $nodes = node_load_multiple(array_keys($result['node']));

  $count = count($nodes);
  drupal_set_message(t('%count node(s) to be published', array('%count' => (string)$count)));

  $processed = 0;
  $not_processed = 0;

  foreach($nodes as $node) {
    try{
      $node->status = 1;
      node_save($node);
      $processed++;
    }catch (Exception $e) {
      drupal_set_message(t('Node with nid: %nid not processed.', array('%nid' => (string)$node->nid)), 'warning');
      $not_processed++;
    }
  }
  drupal_set_message(t('%count node(s) published', array('%count' => (string)$processed)));
  drupal_set_message(t('Unable to publish %count node(s)', array('%count' => (string)$not_processed)));
}

function cls_core_publish_calendar_nodes(){
  $query = db_select('node', 'n');
  $query->fields('n', array('nid'));
  $query->condition('n.type', 'calendar');
  $query->condition('n.status', 0);
  $query->innerJoin('field_data_field_world_read', 'r', 'n.nid = r.entity_id');
  $query->condition('r.field_world_read_value', 1, '=');
  $query->innerJoin('field_data_field_publish_to_lawcal', 'p', 'n.nid = p.entity_id');
  $query->condition('p.field_publish_to_lawcal_value', 1, '=');
  $query->leftJoin('field_data_field_limit_access', 'l', 'n.nid = l.entity_id');
  $query->isNull('l.field_limit_access_tid');

  $result = $query->execute()->fetchCol();

  $count = count($result);
  drupal_set_message(t('%count calendar node(s) to be published', array('%count' => (string)$count)));

  $processed = 0;
  $not_processed = 0;

  foreach($result as $nid){
    try{
      $node = node_load($nid);
      $node->status = 1;
      node_save($node);
      $processed++;
    }catch (Exception $e) {
      drupal_set_message(t('Calendar node with nid: %nid not processed.', array('%nid' => (string)$nid)), 'warning');
      $not_processed++;
    }
  }

  drupal_set_message(t('%count calendar node(s) published', array('%count' => (string)$processed)));
  drupal_set_message(t('Unable to publish %count calendar node(s)', array('%count' => (string)$not_processed)));
}
