<?php

function cls_cg_offering_form($form, &$form_state, $entity, $operation, $entity_type) {

  $form['name'] = array(
    '#title' => t('Course Offering Name'),
    '#type' => 'textfield',
    '#default_value' => isset($entity->name) ? $entity->name : '',
    '#description' => t('Name of course offering'),
    '#required' => TRUE,
    '#weight' => -50,
  );

  $form['course_offering_number'] = array(
    '#title' => t('Course Offering Number'),
    '#type' => 'textfield',
    '#default_value' => isset($entity->course_offering_number) ? $entity->course_offering_number : '',
    '#description' => t('Course offering number'),
    '#required' => TRUE,
    '#weight' => -49,
  );

  field_attach_form($entity_type, $entity, $form, $form_state);

  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => isset($entity->is_new) ? t('Save Offering') : t('Update Offering'),
    ),
  );

  return $form;
}


/**
* Submit handler for offering entity form.
*/
function cls_cg_offering_form_submit($form, &$form_state) {

  //entity_ui_form_submit_build_entity. See entity.ui.inc file for more information.
  $entity = entity_ui_form_submit_build_entity($form, $form_state);
  $entity->save();
  drupal_set_message(t('@name has been saved.', array('@name' => $entity->name)));
  $form_state['redirect'] = 'admin/config/services/cls-rest-api/cls_cg_offering';
}
