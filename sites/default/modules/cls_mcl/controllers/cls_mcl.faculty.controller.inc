<?php

class CLSMCLFacultyController extends EntityAPIController {

  public function save($entity, DatabaseTransaction $transaction = NULL) {
    $entity->changed = REQUEST_TIME;
    parent::save($entity, $transaction);
  }

  public function create(array $values = array()) {
    global $user;
    $values += array(
      'last_name' => '',
      'created' => REQUEST_TIME,
      'changed' => REQUEST_TIME,
      'uid' => $user->uid,
    );
    return parent::create($values);
  }

  public function buildContent($entity, $view_mode = 'full', $langcode = NULL, $content = array()) {
    $wrapper = entity_metadata_wrapper('cls_mcl_faculty', $entity);
    //$content['author'] = array('#markup' => t('Created by: !author', array('!author' => $wrapper->uid->name->value(array('sanitize' => TRUE)))));

    $content['last_name'] = array(
      '#theme' => 'field',
      '#weight' => 2,
      '#title' =>t('Last Name'),
      '#access' => TRUE,
      '#label_display' => 'above',
      '#view_mode' => 'full',
      '#language' => LANGUAGE_NONE,
      '#field_name' => 'field_fake_last_name',
      '#field_type' => 'text',
      '#entity_type' => 'cls_mcl_faculty',
      //'#bundle' => $entity->type,
      '#items' => array(array('value' => $entity->last_name)),
      '#formatter' => 'text_default',
      0 => array('#markup' => check_plain($entity->last_name))
    );

    return parent::buildContent($entity, $view_mode, $langcode, $content);
  }
}

/**
 * CLS MCL Faculty class.
 */
class CLSMCLFaculty extends Entity {
  protected function defaultLabel() {
    return $this->last_name;
  }

  protected function defaultUri() {
    return array('path' => 'cls-mcl-faculty/' . $this->identifier());
  }
}
