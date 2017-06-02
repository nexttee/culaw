<?php

/*
 * Sets the default default form settings and designates the player region.
 */
function cls_mcl_year_adjustment() {
  $form = array();

  $form['cls_mcl_current_year'] = array(
    '#type' => 'textfield',
    '#title' => t('Manually set the CLS MCL current year.'),
    '#required' => TRUE,
    '#description' => t('If this value is not updated, the previously-saved year will be used throughout the CLS MCL module. Click "Save Configuration" once this value has been set.'),
    '#default_value' => !empty($form_state['values']['cls_mcl_current_year']) ? $form_state['values']['cls_mcl_current_year'] : variable_get('cls_mcl_current_year', date("Y")),
  );

  return system_settings_form($form);
}

/*
 * Sets the default default form settings and designates the player region.
 */
function cls_mcl_year_adjustment_validate($form, &$form_state) {
  $cls_mcl_year = $form_state['values']['cls_mcl_current_year'];
  if ($cls_mcl_year && ($cls_mcl_year < 1900 || $cls_mcl_year > 2500)) {
    form_set_error('cls_mcl_current_year', t('Enter a valid year.'));
  }
}