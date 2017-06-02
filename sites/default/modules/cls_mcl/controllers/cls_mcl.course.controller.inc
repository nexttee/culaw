<?php

class CLSMCLCourseController extends EntityAPIController {

  public function save($entity, DatabaseTransaction $transaction = NULL) {
    parent::save($entity, $transaction);
  }

  public function create(array $values = array()) {
    global $user;
    $values += array(
      'number' => '',
      'name' => '',
    );
    return parent::create($values);
  }

  public function buildContent($entity, $view_mode = 'full', $langcode = NULL, $content = array()) {
    $wrapper = entity_metadata_wrapper('cls_mcl_course', $entity);

    $content['number'] = array(
      '#theme' => 'field',
      '#weight' => 1,
      '#title' =>t('Number'),
      '#access' => TRUE,
      '#label_display' => 'above',
      '#view_mode' => 'full',
      '#language' => LANGUAGE_NONE,
      '#field_name' => 'field_fake_number',
      '#field_type' => 'text',
      '#entity_type' => 'cls_mcl_course',
      //'#bundle' => $entity->type,
      '#items' => array(array('value' => $entity->number)),
      '#formatter' => 'text_default',
      0 => array('#markup' => check_plain($entity->number))
    );

    $content['name'] = array(
      '#theme' => 'field',
      '#weight' => 2,
      '#title' =>t('Name'),
      '#access' => TRUE,
      '#label_display' => 'above',
      '#view_mode' => 'full',
      '#language' => LANGUAGE_NONE,
      '#field_name' => 'field_fake_name',
      '#field_type' => 'text',
      '#entity_type' => 'cls_mcl_course',
      //'#bundle' => $entity->type,
      '#items' => array(array('value' => $entity->name)),
      '#formatter' => 'text_default',
      0 => array('#markup' => check_plain($entity->name))
    );

    return parent::buildContent($entity, $view_mode, $langcode, $content);
  }
}

/**
 * CLS MCL Course class.
 */
class CLSMCLCourse extends Entity {
  protected function defaultLabel() {
    return $this->number . ' ' . $this->name;
  }

  protected function defaultUri() {
    return array('path' => 'cls-mcl-course/' . $this->identifier());
  }
}
