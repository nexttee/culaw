<?php
/**
 * @file
 * Base functionality for all RTSB migrations.
 */

/**
 * Implements hook_migrate_api().
 */
function cls_migrate_rt_migrate_api() {
  $private_file_path = drupal_realpath('private://');
  $disable_hooks = array(
    'entity_insert' => array(
      'search_api',
    ),
    'entity_update' => array(
      'search_api',
    ),
    'entity_delete' => array(
      'search_api',
    ),
    'node_insert' => array(
      'expire',
      'acquia_purge',
      'search_api',
      'apachesolr'
    ),
    'node_update' => array(
      'expire',
      'acquia_purge',
      'search_api',
      'apachesolr'
    ),
    'node_delete' => array(
      'expire',
      'acquia_purge',
      'search_api',
      'apachesolr'
    ),
  );
  $api = array(
    'api' => 2,
    'groups' => array(
      'rtsb_content' => array(
        'title' => t("RTSB Content Migrations"),
        'disable_hooks' => $disable_hooks,
      ),
      'rtsb_preprocess' => array(
        'title' => t('RTSB data preprocessing'),
      ),
      'rtsb_taxonomy' => array(
        'title' => t('RTSB Taxonomy Migrations'),
        'disable_hooks' => $disable_hooks,
      ),
      'rtsb_paragraphs' => array(
        'title' => t('RTSB Paragraph Item Migrations'),
        'disable_hooks' => $disable_hooks,
      ),
      'rtsb_files' => array(
        'title' => t('RTSB File Migration'),
        'disable_hooks' => $disable_hooks,
      ),
      'rtsb_redirect' => array(
        'title' => t('RTSB Legacy Redirects Migration'),
      ),
    ),
    'migrations' => array(
      'RtsbCalendarLoad' => array(
        'group_name' => 'rtsb_preprocess',
        'class_name' => 'RtsbJSONPreprocess',
        'source_file' => $private_file_path . '/eventmgr-calendar-all.json',
      ),
      'RtsbFileRootPreprocess' => array(
        'group_name' => 'rtsb_preprocess',
        'class_name' => 'RtsbFileRootPreprocessMigration',
        'source_file' => drupal_realpath(variable_get('cls_migrate_rt_fileroots_source_path')),
      ),
      'RtsbFilePreprocess' => array(
        'group_name' => 'rtsb_preprocess',
        'class_name' => 'RtsbFilePreprocessMigration',
        'source_file' => drupal_realpath(variable_get('cls_migrate_rt_files_source_path')),
      ),
      'RtsbCategoryPreprocess' => array(
        'group_name' => 'rtsb_preprocess',
        'class_name' => 'RtsbCategoryPreprocessMigration',
        'source_file' => drupal_realpath(variable_get('cls_migrate_rt_categories_source_path')),
      ),
      'RtsbPublishPreprocess' => array(
        'class_name' => 'RtsbPublishMigration',
        'group_name' => 'rtsb_preprocess',
        'source_file' => drupal_realpath(variable_get('cls_migrate_rt_publish_source_path')),
      ),
      'RtsbApcContentLoad' => array(
        'group_name' => 'rtsb_preprocess',
        'class_name' => 'RtsbJSONPreprocess',
        'source_file' => $private_file_path . '/contentmgr-apc-all.json',
      )                                                                  ,
      'RtsbPagesLoad' => array(
        'group_name' => 'rtsb_preprocess',
        'class_name' => 'RtsbJSONPreprocess',
        'source_file' => $private_file_path . '/pagemgr-pages-all.json',
      ),
      'RtsbMagazineLoad' => array(
        'group_name' => 'rtsb_preprocess',
        'class_name' => 'RtsbJSONPreprocess',
        'source_file' => $private_file_path . '/contentmgr-articlesc-all.json',
      ),
      'RtsbRedirectPreprocess' => array(
        'group_name' => 'rtsb_preprocess',
        'class_name' => 'RtsbRedirectPreprocessMigration',
        'source_file' => drupal_realpath(variable_get('cls_migrate_rt_redirect_source_path')),
      ),
      'RtsbFile' => array(
        'class_name' => 'RtsbFileMigration',
        'group_name' => 'rtsb_files',
      ),
      'RtsbGroup' => array(
        'class_name' => 'RtsbGroupMigration',
        'group_name' => 'rtsb_taxonomy',
        'source_file' => drupal_realpath(variable_get('cls_migrate_rt_groups_source_path')),
      ),
      'RtsbCategoryApc' => array(
        'class_name' => 'RtsbCategoryMigration',
        'group_name' => 'rtsb_taxonomy',
        'parent_id' => 1068,
        'vocabulary' => 'apc_content_categories',
        'dependencies' => array('RtsbCategoryPreprocess'),
      ),
       'RtsbLegacyRedirect' => array(
        'group_name' => 'rtsb_redirect',
        'class_name' => 'RtsbLegacyRedirectMigration',
      ),
    ),
  );

  return $api;
}
