<?php
/**
 * @file
 * Configuration form for cls_migrate_rt migrations.
 */

/**
 * Menu callback function for RTSB migration configuraion.
 *
 * @return array|mixed
 *   System settings form build array.
 */
function migrate_rt_configure() {
  return drupal_get_form('cls_migrate_rt_configure_form', _cls_migrate_rt_get_file_field_info());
}

/**
 * File management form for file-based sources.
 */
function cls_migrate_rt_configure_form($form, &$form_state, $file_fields) {
  foreach ($file_fields as $field => $info) {
    $form[$field] = array(
      '#title' => $info['title'],
      '#description' => $info['description'],
      '#type' => 'managed_file',
      '#upload_location' => 'private://',
      '#default_value' => variable_get($field, ''),
      '#upload_validators' => array(
        'file_validate_extensions' => $info['allowed_extensions'],
      ),
    );
  }
  $form = system_settings_form($form);
  $form_state['file_fields'] = array_keys($file_fields);
  $form['#submit'][] = 'cls_migrate_rt_configure_form_submit';

  return $form;
}

/**
 * Submit handler for migration configuration form.
 */
function cls_migrate_rt_configure_form_submit($form, &$form_state) {
  $file_fields = is_array($form_state['file_fields']) ? $form_state['file_fields'] : array($form_state['file_fields']);

  foreach ($file_fields as $file_field) {
    $existing_file = (!empty($form[$file_field]['#default_value'])) ? $form[$file_field]['#default_value'] : 0;
    if (isset($form_state['values'][$file_field]) && $form_state['values'][$file_field]) {
      if ($existing_file && $existing_file != $form_state['values'][$file_field]) {
        _cls_migrate_rt_remove_file($existing_file, $file_field);
        _cls_migrate_rt_add_file($form_state['values'][$file_field], $file_field);
      }
      else {
        _cls_migrate_rt_add_file($form_state['values'][$file_field], $file_field);
      }
    }
    else {
      if (isset($redirect_source)) {
        _cls_migrate_rt_remove_file($redirect_source, $file_field);
      }
    }
  }
}

/**
 * Helper function to delete a managed file and update the file path variable.
 *
 * @param int $file_id
 *   File ID of the file to delete.
 * @param string $file_field
 *   Field name on the admin form containing the file to delete.
 */
function _cls_migrate_rt_remove_file($file_id, $file_field) {
  $file = (!empty($file_id)) ? file_load($file_id) : FALSE;
  if ($file) {
    file_usage_delete($file, 'cls_migrate_rt');
    file_delete($file);
    variable_set($file_field . '_path', '');
  }
}

/**
 * Helper function to save a managed file and update the file path variable.
 *
 * @param int $file_id
 *   File ID of the file to save.
 * @param string $file_field
 *   Field name on the admin form containing the file to save.
 */
function _cls_migrate_rt_add_file($file_id, $file_field) {
  $file = file_load($file_id);
  $file_references = file_usage_list($file);
  $existing_file = !empty($file_references) && isset($file_references['cls_migrate_rt']['file'][$file_id]);
  if (!$existing_file) {
    $file->status = FILE_STATUS_PERMANENT;
    file_save($file);
    file_usage_add($file, 'cls_migrate_rt', 'file', $file_id);
    variable_set($file_field . '_path', $file->uri);
  }

}

function _cls_migrate_rt_get_file_field_info() {
  return array(
    'cls_migrate_rt_redirect_source' => array(
      'title' => t('Legacy Apache configuration file'),
      'description' => t('Apache configuration file from legacy site which contains mappings from legacy URLs to current Drupal URLs. File must have a .txt extension.'),
      'allowed_extensions' => array('txt'),
    ),
    'cls_migrate_rt_files_source' => array(
      'title' => t('RT_FILES source CSV'),
      'description' => t('Source CSV for rt_files, see the <a target="_blank" href="https://confluence.law.columbia.edu/display/LCEdu/Files">Confluence page</a> for the source SQL query to use to generate the file.'),
      'allowed_extensions' => array('csv'),
    ),
    'cls_migrate_rt_fileroots_source' => array(
      'title' => t('RT_FILEROOTS source CSV'),
      'description' => t('Source CSV for rt_filerootss, see the <a target="_blank" href="https://confluence.law.columbia.edu/display/LCEdu/Files">Confluence page</a> for more information.'),
      'allowed_extensions' => array('csv'),
    ),
    'cls_migrate_rt_categories_source' => array(
      'title' => t('RT_CATEGORIES source CSV'),
      'description' => t('Source CSV for rt_categories table.'),
      'allowed_extensions' => array('csv'),
    ),
    'cls_migrate_rt_groups_source' => array(
      'title' => t('RT_GROUPS source CSV'),
      'description' => t('Source CSV for rt_groups table.'),
      'allowed_extensions' => array('csv'),
    ),
    'cls_migrate_rt_publish_source' => array(
      'title' => t('RT_PUBLISH source CSV'),
      'description' => t('Source CSV for rt_publish table.'),
      'allowed_extensions' => array('csv'),
    ),
  );
}
