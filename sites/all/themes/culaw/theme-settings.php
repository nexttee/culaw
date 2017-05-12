<?php

/**
 * @file
 * Theme setting callbacks for the culaw theme.
 */

/**
 * Implements hook_form_FORM_ID_alter().
 */
function culaw_form_system_theme_settings_alter(&$form, &$form_state) {

  // CLS settings.
  $form['cls'] = array(
    '#type' => 'fieldset',
    '#title' => t('CLS Settings'),
  );

  // Site Announcement.
  $form['cls']['site_announcement'] = array(
    '#type' => 'fieldset',
    '#title' => t('Site Announcement'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['cls']['site_announcement']['site_announcement_status'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable site announcement'),
    '#default_value' => theme_get_setting('site_announcement_status'),
    '#description' => t(''),
  );
  $form['cls']['site_announcement']['site_announcement_message'] = array(
    '#type' => 'textarea',
    '#title' => t('Site announcement message'),
    '#description' => t('Message that will be displayed when announcement is enabled.'),
    '#default_value' => theme_get_setting('site_announcement_message'),
  );
}
