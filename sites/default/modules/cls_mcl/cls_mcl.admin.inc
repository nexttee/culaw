<?php

function cls_mcl_interest_type_view($cls_mcl_interest_type) {
  drupal_set_title(entity_label('cls_mcl_interest_type', $cls_mcl_interest_type));
  return entity_view('cls_mcl_interest_type', array(entity_id('cls_mcl_interest_type', $cls_mcl_interest_type) => $cls_mcl_interest_type), 'full');
}

function cls_mcl_journal_view($cls_mcl_journal) {
  drupal_set_title(entity_label('cls_mcl_journal', $cls_mcl_journal));
  return entity_view('cls_mcl_journal', array(entity_id('cls_mcl_journal', $cls_mcl_journal) => $cls_mcl_journal), 'full');
}

function cls_mcl_student_organization_view($cls_mcl_student_organization) {
  drupal_set_title(entity_label('cls_mcl_student_organization', $cls_mcl_student_organization));
  return entity_view('cls_mcl_student_organization', array(entity_id('cls_mcl_student_organization', $cls_mcl_student_organization) => $cls_mcl_student_organization), 'full');
}

function cls_mcl_center_view($cls_mcl_center) {
  drupal_set_title(entity_label('cls_mcl_center', $cls_mcl_center));
  return entity_view('cls_mcl_center', array(entity_id('cls_mcl_center', $cls_mcl_center) => $cls_mcl_center), 'full');
}

function cls_mcl_faculty_view($cls_mcl_faculty) {
  drupal_set_title(entity_label('cls_mcl_faculty', $cls_mcl_faculty));
  return entity_view('cls_mcl_faculty', array(entity_id('cls_mcl_faculty', $cls_mcl_faculty) => $cls_mcl_faculty), 'full');
}

// @todo Remove once usages are removed
function cls_mcl_course_view($cls_mcl_course) {
  drupal_set_title(entity_label('cls_mcl_course', $cls_mcl_course));
  return entity_view('cls_mcl_course', array(entity_id('cls_mcl_course', $cls_mcl_course) => $cls_mcl_course), 'full');
}

/**
 * cls_mcl_interest_type Form.
 */
function cls_mcl_interest_type_form($form, &$form_state, $cls_mcl_interest_type) {
  $form_state['cls_mcl_interest_type'] = $cls_mcl_interest_type;

  $form['uid'] = array(
    '#type' => 'value',
    '#value' => $cls_mcl_interest_type->uid,
  );

  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#required' => TRUE,
    '#default_value' => $cls_mcl_interest_type->title,
    '#weight' => -298,
  );
  $form['rtsb_id'] = array(
    '#type' => 'textfield',
    '#title' => t('RTSB ID'),
    '#required' => TRUE,
    '#default_value' => $cls_mcl_interest_type->rtsb_id,
    '#weight' => -297,
  );
  $form['old_mcl_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Old MCL ID'),
    '#required' => TRUE,
    '#default_value' => $cls_mcl_interest_type->old_mcl_id,
    '#weight' => -296,
  );

  field_attach_form('cls_mcl_interest_type', $cls_mcl_interest_type, $form, $form_state);

  $submit = array();
  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions'] = array(
    '#weight' => 100,
  );

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save CLS MCL Interest Type'),
    '#submit' => $submit + array('cls_mcl_interest_type_form_submit'),
  );

  // Show Delete button if we edit cls_reunion_update.
  $cls_mcl_interest_type_id = entity_id('cls_mcl_interest_type', $cls_mcl_interest_type);
  //if (!empty($cls_reunion_update_id) && cls_reunion_update_access('edit', $cls_reunion_update)) {
  if (!empty($cls_mcl_interest_type_id)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete'),
      '#submit' => array('cls_mcl_interest_type_form_submit_delete'),
    );
  }

  return $form;
}

/**
 * cls_mcl_interest_type submit handler.
 */
function cls_mcl_interest_type_form_submit($form, &$form_state) {
  $cls_mcl_interest_type = $form_state['cls_mcl_interest_type'];

  entity_form_submit_build_entity('cls_mcl_interest_type', $cls_mcl_interest_type, $form, $form_state);

  cls_mcl_interest_type_save($cls_mcl_interest_type);

  $cls_mcl_interest_type_uri = entity_uri('cls_mcl_interest_type', $cls_mcl_interest_type);

  $form_state['redirect'] = $cls_mcl_interest_type_uri['path'];

  drupal_set_message(t('CLS MCL Interest Type %title saved.', array('%title' => entity_label('cls_mcl_interest_type', $cls_mcl_interest_type))));
}

function cls_mcl_interest_type_form_submit_delete($form, &$form_state) {
  $cls_mcl_interest_type = $form_state['cls_mcl_interest_type'];
  $cls_mcl_interest_type_uri = entity_uri('cls_mcl_interest_type', $cls_mcl_interest_type);
  $form_state['redirect'] = $cls_mcl_interest_type_uri['path'] . '/delete';
}

/**
 * Delete confirmation form.
 */
function cls_mcl_interest_type_delete_form($form, &$form_state, $cls_mcl_interest_type) {
  $form_state['cls_mcl_interest_type'] = $cls_mcl_interest_type;
  // Always provide entity id in the same form key as in the entity edit form.
  $form['cls_mcl_interest_type_id'] = array(
    '#type' => 'value',
    '#value' => entity_id('cls_mcl_interest_type', $cls_mcl_interest_type)
  );
  $cls_mcl_interest_type_uri = entity_uri('cls_mcl_interest_type', $cls_mcl_interest_type);
  return confirm_form($form,
    t('Are you sure you want to delete CLS MCL Interest Type %title?', array('%title' => entity_label('cls_mcl_interest_type', $cls_mcl_interest_type))),
    $cls_mcl_interest_type_uri['path'],
    t('This action cannot be undone.'),
    t('Delete'),
    t('Cancel')
  );
}

/**
 * Delete form submit handler.
 */
function cls_mcl_interest_type_delete_form_submit($form, &$form_state) {
  $cls_mcl_interest_type = $form_state['cls_mcl_interest_type'];
  cls_mcl_interest_type_delete($cls_mcl_interest_type);

  drupal_set_message(t('CLS MCL Interest Type %title deleted.', array('%title' => entity_label('cls_mcl_interest_type', $cls_mcl_interest_type))));

  $form_state['redirect'] = '<front>';
}

/**
 * cls_mcl_journal Form.
 */
function cls_mcl_journal_form($form, &$form_state, $cls_mcl_journal) {
  $form_state['cls_mcl_journal'] = $cls_mcl_journal;

  $form['uid'] = array(
    '#type' => 'value',
    '#value' => $cls_mcl_journal->uid,
  );

  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#required' => TRUE,
    '#default_value' => $cls_mcl_journal->title,
    '#weight' => -298,
  );
  $form['url'] = array(
    '#type' => 'textfield',
    '#title' => t('URL'),
    '#required' => TRUE,
    '#default_value' => $cls_mcl_journal->url,
    '#weight' => -297,
  );

  field_attach_form('cls_mcl_journal', $cls_mcl_journal, $form, $form_state);

  $submit = array();
  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions'] = array(
    '#weight' => 100,
  );

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save CLS MCL Interest Type'),
    '#submit' => $submit + array('cls_mcl_journal_form_submit'),
  );

  // Show Delete button if we edit cls_reunion_update.
  $cls_mcl_journal_id = entity_id('cls_mcl_journal', $cls_mcl_journal);
  //if (!empty($cls_reunion_update_id) && cls_reunion_update_access('edit', $cls_reunion_update)) {
  if (!empty($cls_mcl_journal_id)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete'),
      '#submit' => array('cls_mcl_journal_form_submit_delete'),
    );
  }

  return $form;
}

/**
 * cls_mcl_journal submit handler.
 */
function cls_mcl_journal_form_submit($form, &$form_state) {
  $cls_mcl_journal = $form_state['cls_mcl_journal'];

  entity_form_submit_build_entity('cls_mcl_journal', $cls_mcl_journal, $form, $form_state);

  cls_mcl_journal_save($cls_mcl_journal);

  $cls_mcl_journal_uri = entity_uri('cls_mcl_journal', $cls_mcl_journal);

  $form_state['redirect'] = $cls_mcl_journal_uri['path'];

  drupal_set_message(t('CLS MCL Journal %title saved.', array('%title' => entity_label('cls_mcl_journal', $cls_mcl_journal))));
}

function cls_mcl_journal_form_submit_delete($form, &$form_state) {
  $cls_mcl_journal = $form_state['cls_mcl_journal'];
  $cls_mcl_journal_uri = entity_uri('cls_mcl_journal', $cls_mcl_journal);
  $form_state['redirect'] = $cls_mcl_journal_uri['path'] . '/delete';
}

/**
 * Delete confirmation form.
 */
function cls_mcl_journal_delete_form($form, &$form_state, $cls_mcl_journal) {
  $form_state['cls_mcl_journal'] = $cls_mcl_journal;
  // Always provide entity id in the same form key as in the entity edit form.
  $form['cls_mcl_journal_id'] = array('#type' => 'value', '#value' => entity_id('cls_mcl_journal', $cls_mcl_journal));
  $cls_mcl_journal_uri = entity_uri('cls_mcl_journal', $cls_mcl_journal);
  return confirm_form($form,
    t('Are you sure you want to delete CLS MCL Journal %title?', array('%title' => entity_label('cls_mcl_journal', $cls_mcl_journal))),
    $cls_mcl_journal_uri['path'],
    t('This action cannot be undone.'),
    t('Delete'),
    t('Cancel')
  );
}

/**
 * Delete form submit handler.
 */
function cls_mcl_journal_delete_form_submit($form, &$form_state) {
  $cls_mcl_journal = $form_state['cls_mcl_journal'];
  cls_mcl_journal_delete($cls_mcl_journal);

  drupal_set_message(t('CLS MCL Journal %title deleted.', array('%title' => entity_label('cls_mcl_journal', $cls_mcl_journal))));

  $form_state['redirect'] = '<front>';
}


/**
 * cls_mcl_student_organization Form.
 */
function cls_mcl_student_organization_form($form, &$form_state, $cls_mcl_student_organization) {
  $form_state['cls_mcl_student_organization'] = $cls_mcl_student_organization;

  $form['uid'] = array(
    '#type' => 'value',
    '#value' => $cls_mcl_student_organization->uid,
  );

  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#required' => TRUE,
    '#default_value' => $cls_mcl_student_organization->title,
    '#weight' => -298,
  );
  $form['url'] = array(
    '#type' => 'textfield',
    '#title' => t('URL'),
    '#required' => TRUE,
    '#default_value' => $cls_mcl_student_organization->url,
    '#weight' => -297,
  );

  field_attach_form('cls_mcl_student_organization', $cls_mcl_student_organization, $form, $form_state);

  $submit = array();
  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions'] = array(
    '#weight' => 100,
  );

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save CLS MCL Interest Type'),
    '#submit' => $submit + array('cls_mcl_student_organization_form_submit'),
  );

  // Show Delete button if we edit cls_reunion_update.
  $cls_mcl_student_organization_id = entity_id('cls_mcl_student_organization', $cls_mcl_student_organization);
  //if (!empty($cls_reunion_update_id) && cls_reunion_update_access('edit', $cls_reunion_update)) {
  if (!empty($cls_mcl_student_organization_id)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete'),
      '#submit' => array('cls_mcl_student_organization_form_submit_delete'),
    );
  }

  return $form;
}

/**
 * cls_mcl_student_organization submit handler.
 */
function cls_mcl_student_organization_form_submit($form, &$form_state) {
  $cls_mcl_student_organization = $form_state['cls_mcl_student_organization'];

  entity_form_submit_build_entity('cls_mcl_student_organization', $cls_mcl_student_organization, $form, $form_state);

  cls_mcl_student_organization_save($cls_mcl_student_organization);

  $cls_mcl_student_organization_uri = entity_uri('cls_mcl_student_organization', $cls_mcl_student_organization);

  $form_state['redirect'] = $cls_mcl_student_organization_uri['path'];

  drupal_set_message(t('MCL Student Organization %title saved.', array('%title' => entity_label('cls_mcl_student_organization', $cls_mcl_student_organization))));
}

function cls_mcl_student_organization_form_submit_delete($form, &$form_state) {
  $cls_mcl_student_organization = $form_state['cls_mcl_student_organization'];
  $cls_mcl_student_organization_uri = entity_uri('cls_mcl_student_organization', $cls_mcl_student_organization);
  $form_state['redirect'] = $cls_mcl_student_organization_uri['path'] . '/delete';
}

/**
 * Delete confirmation form.
 */
function cls_mcl_student_organization_delete_form($form, &$form_state, $cls_mcl_student_organization) {
  $form_state['cls_mcl_student_organization'] = $cls_mcl_student_organization;
  // Always provide entity id in the same form key as in the entity edit form.
  $form['cls_mcl_student_organization_id'] = array(
    '#type' => 'value',
    '#value' => entity_id('cls_mcl_student_organization', $cls_mcl_student_organization)
  );
  $cls_mcl_student_organization_uri = entity_uri('cls_mcl_student_organization', $cls_mcl_student_organization);
  return confirm_form($form,
    t('Are you sure you want to delete MCL Student Organization %title?', array('%title' => entity_label('cls_mcl_student_organization', $cls_mcl_student_organization))),
    $cls_mcl_student_organization_uri['path'],
    t('This action cannot be undone.'),
    t('Delete'),
    t('Cancel')
  );
}

/**
 * Delete form submit handler.
 */
function cls_mcl_student_organization_delete_form_submit($form, &$form_state) {
  $cls_mcl_student_organization = $form_state['cls_mcl_student_organization'];
  cls_mcl_student_organization_delete($cls_mcl_student_organization);

  drupal_set_message(t('CLS MCL Student Organization %title deleted.', array('%title' => entity_label('cls_mcl_student_organization', $cls_mcl_student_organization))));

  $form_state['redirect'] = '<front>';
}
