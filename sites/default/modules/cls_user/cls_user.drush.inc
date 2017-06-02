<?php

/**
 * @file
 * Drush integration for cls_user.
 */

/**
 * Implements hook_drush_command().
 */
function cls_user_drush_command() {
  $items = array();

  $items['cls-student-roles'] = array(
    'callback' => 'cls_user_migrate_student_roles',
    'description' => dt('Migrate data from student roles into user objects.'),
    'aliases' => array('cls-sr'),
  );

  $items['cls-alumni-roles'] = array(
    'callback' => 'cls_user_migrate_alumni_roles',
    'description' => dt('Migrate data from alumni roles into user objects.'),
    'aliases' => array('cls-ar'),
  );

  return $items;
}

/**
 * Drush callback Migrate Almuni Roles.
 *
 * Migrate data from "Student" into the user profile fields.
 */
function cls_user_migrate_student_roles() {
  features_revert_module('cls_user');
  $batch_size = 500;

  $roles = user_roles(TRUE);

  // Setting email send method to FALSE so email won't be sent.
  $email_blocked_user_notice_value = variable_get('user_mail_status_blocked_notify', FALSE);
  variable_set('user_mail_status_blocked_notify', FALSE);
  $student_type_vocabulary = taxonomy_vocabulary_machine_name_load('current_student_type');

  // Applying processing for student with J.D. related roles.
  module_load_include('inc', 'cls_user', 'includes/cls_user.update_user');
  $js_student_mapping = cls_user_map_jd_student_role();
  $jd_roles = array_intersect_key($js_student_mapping, $roles);
  $rids = array_keys($jd_roles);

  $query = db_select('users_roles', 'ur');
  $query->fields('ur', array('uid', 'rid'));
  $query->condition('ur.rid', $rids, IN);
  $query->distinct();
  $query->orderBy('uid');
  $users = $query->execute()->fetchCol(0);

  $operations = array();
  $chunks = array_chunk($users, $batch_size);
  $count = count($chunks);
  $i = 0;
  foreach ($chunks as $chunk) {
    $msg_vars = array('@id' => $chunk[0], '@i' => ++$i, '@total' => $count);
    $operations[] = array(
      'cls_user_update_jd_student_type_field',
      array(
        $chunk,
        t('Processing users from id @id. @i/@total', $msg_vars),
        $jd_roles,
        $email_blocked_user_notice_value,
        $student_type_vocabulary,
      ),
    );
  }

  $jd_student_type_batch = array(
    'operations' => $operations,
    'title' => t('Updating student type user profile field with relevant values'),
    'init_message' => t('Initializing'),
    'error_message' => t('An error occurred.'),
    'finished' => 'cls_user_update_jd_student_type_field_finished',
    'file' => drupal_get_path('module', 'cls_user') . '/includes/cls_user.update_user.inc',
  );
  batch_set($jd_student_type_batch);

  // Process batch with drush.
  $jd_student_type_batch =& batch_get();
  $jd_student_type_batch['progressive'] = FALSE;
  drush_backend_batch_process();

  // Applying processing for student with G.L.S. related roles.
  $gls_student_mapping = cls_user_map_gls_student_role();
  $gls_roles = array_intersect_key($gls_student_mapping, $roles);
  $rids = array_keys($gls_roles);

  $query = db_select('users_roles', 'ur');
  $query->fields('ur', array('uid', 'rid'));
  $query->condition('ur.rid', $rids, IN);
  $query->distinct();
  $query->orderBy('uid');
  $users = $query->execute()->fetchCol(0);

  $operations = array();
  $chunks = array_chunk($users, $batch_size);
  $count = count($chunks);
  $i = 0;
  foreach ($chunks as $chunk) {
    $msg_vars = array('@id' => $chunk[0], '@i' => ++$i, '@total' => $count);
    $operations[] = array(
      'cls_user_update_gls_student_type_field',
      array(
        $chunk,
        t('Processing users from id @id. @i/@total', $msg_vars),
        $gls_roles,
        $email_blocked_user_notice_value,
        $student_type_vocabulary,
      ),
    );
  }

  $gls_student_type_batch = array(
    'operations' => $operations,
    'title' => t('Updating student type user profile field with relevant values'),
    'init_message' => t('Initializing'),
    'error_message' => t('An error occurred.'),
    'finished' => 'cls_user_update_gls_student_type_field_finished',
    'file' => drupal_get_path('module', 'cls_user') . '/includes/cls_user.update_user.inc',
  );
  batch_set($gls_student_type_batch);

  // Process batch with drush.
  $gls_student_type_batch =& batch_get();
  $gls_student_type_batch['progressive'] = FALSE;
  drush_backend_batch_process();

  // Applying processing for "Prospective students' Introduction.
  $prospective_student_mapping = cls_user_map_prospective_student_role();
  $prospective_roles = array_intersect_key($prospective_student_mapping, $roles);
  $rids = array_keys($prospective_roles);
  $prospective_student_type_vocabulary = taxonomy_vocabulary_machine_name_load('prospective_student_type');

  $query = db_select('users_roles', 'ur');
  $query->fields('ur', array('uid', 'rid'));
  $query->condition('ur.rid', $rids, IN);
  $query->distinct();
  $query->orderBy('uid');
  $users = $query->execute()->fetchCol(0);

  $operations = array();
  $chunks = array_chunk($users, $batch_size);
  $count = count($chunks);
  $i = 0;
  foreach ($chunks as $chunk) {
    $msg_vars = array('@id' => $chunk[0], '@i' => ++$i, '@total' => $count);
    $operations[] = array(
      'cls_user_update_prospective_student_type_field',
      array(
        $chunk,
        t('Processing users from id @id. @i/@total', $msg_vars),
        $prospective_roles,
        $email_blocked_user_notice_value,
        $prospective_student_type_vocabulary,
      ),
    );
  }

  $prospective_student_type_batch = array(
    'operations' => $operations,
    'title' => t('Updating Prospective Student type user profile field with relevant values'),
    'init_message' => t('Initializing'),
    'error_message' => t('An error occurred.'),
    'finished' => 'cls_user_update_prospective_student_type_field_finished',
    'file' => drupal_get_path('module', 'cls_user') . '/includes/cls_user.update_user.inc',
  );

  batch_set($prospective_student_type_batch);

  // Process batch with drush.
  $batch =& batch_get();
  $batch['progressive'] = FALSE;
  drush_backend_batch_process();
}

/**
 * Drush callback Migrate Almuni Roles.
 *
 * Migrate data from "Alumni Year" roles into the user profile fields.
 */
function cls_user_migrate_alumni_roles() {
  features_revert_module('cls_user');
  $batch_size = 500;

  // Setting email sending method to FALSE. So emails won't be send to users
  // on profile value change.
  $email_blocked_user_notice_value = variable_get('user_mail_status_blocked_notify', FALSE);
  variable_set('user_mail_status_blocked_notify', FALSE);
  $vocabulary = taxonomy_vocabulary_machine_name_load('year');

  $roles = user_roles(TRUE);
  module_load_include('inc', 'cls_user', 'includes/cls_user.update_user');
  $role_year_mapping = cls_user_map_alumni_role_year();
  $alumni_roles = array_intersect_key($role_year_mapping, $roles);
  $rids = array_keys($alumni_roles);

  $query = db_select('users_roles', 'ur');
  $query->fields('ur', array('uid', 'rid'));
  $query->condition('ur.rid', $rids, IN);
  $query->distinct();
  $query->orderBy('uid');
  $users = $query->execute()->fetchCol(0);

  $operations = array();
  $chunks = array_chunk($users, $batch_size);

  $count = count($chunks);
  $i = 0;
  foreach ($chunks as $chunk) {
    $msg_vars = array('@id' => $chunk[0], '@i' => ++$i, '@total' => $count);
    $operations[] = array(
      'cls_user_update_user_field',
      array(
        $chunk,
        t('Processing users from id @id. @i/@total', $msg_vars),
        $alumni_roles,
        $email_blocked_user_notice_value,
        $vocabulary,
      ),
    );
  }

  $batch = array(
    'operations' => $operations,
    'title' => t('Updating user profile fields with relevant values'),
    'init_message' => t('Initializing'),
    'error_message' => t('An error occurred.'),
    'finished' => 'cls_user_update_user_field_finished',
    'file' => drupal_get_path('module', 'cls_user') . '/includes/cls_user.update_user.inc',
  );

  batch_set($batch);

  // Process batch with drush.
  $batch =& batch_get();
  $batch['progressive'] = FALSE;
  drush_backend_batch_process();
}
