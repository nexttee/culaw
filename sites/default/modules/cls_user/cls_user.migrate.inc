<?php
/**
 * @file
 * Common code for user migrations.
 */

/**
 * Implements hook_migrate_api().
 */
function cls_user_migrate_api() {
  $api = array(
    'api' => 2,
    'migrations' => array(
      'RtsbProfileImage' => array(
        'class_name' => 'RtsbFacultyProfileImageMigration',
        'group_name' => 'rtsb_files',
      ),
      'RtsbProfileElementType' => array(
        'class_name' => 'RtsbProfileElementTaxonomyTermsMigration',
        'group_name' => 'rtsb_taxonomy',
      ),
      'RtsbProfileElement' => array(
        'class_name' => 'RtsbProfileElementMigration',
        'group_name' => 'rtsb_paragraphs',
      ),
      'RtsbProfile' => array(
        'class_name' => 'RtsbFacultyProfileMigration',
        'group_name' => 'rtsb_content',
        'dependencies' => array(
          'RtsbProfileElement',
          'RtsbProfileImage',
          'RtsbFile',
        ),
      ),
    ),
  );

  return $api;
}
