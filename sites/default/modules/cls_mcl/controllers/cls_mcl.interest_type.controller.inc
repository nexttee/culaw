<?php

class CLSMCLInterestTypeController extends EntityAPIController {

  public function save($entity, DatabaseTransaction $transaction = NULL) {
    $entity->changed = REQUEST_TIME;
    parent::save($entity, $transaction);
  }

  public function create(array $values = array()) {
    global $user;
    $values += array(
      'title' => '',
      'created' => REQUEST_TIME,
      'changed' => REQUEST_TIME,
      'uid' => $user->uid,
      'rtsb_id' => '',
      'old_mcl_id' => ''
    );
    return parent::create($values);
  }

  public function buildContent($entity, $view_mode = 'full', $langcode = NULL, $content = array()) {
    $wrapper = entity_metadata_wrapper('cls_mcl_interest_type', $entity);
    //$content['author'] = array('#markup' => t('Created by: !author', array('!author' => $wrapper->uid->name->value(array('sanitize' => TRUE)))));

    $content['title'] = array(
      '#theme' => 'field',
      '#weight' => 1,
      '#title' =>t('Title'),
      '#access' => TRUE,
      '#label_display' => 'above',
      '#view_mode' => 'full',
      '#language' => LANGUAGE_NONE,
      '#field_name' => 'field_fake_title',
      '#field_type' => 'text',
      '#entity_type' => 'cls_mcl_interest_type',
      //'#bundle' => $entity->type,
      '#items' => array(array('value' => $entity->title)),
      '#formatter' => 'text_default',
      0 => array('#markup' => check_plain($entity->title))
    );

    $content['rtsb_id'] = array(
      '#theme' => 'field',
      '#weight' => 2,
      '#title' =>t('RTSB ID'),
      '#access' => TRUE,
      '#label_display' => 'above',
      '#view_mode' => 'full',
      '#language' => LANGUAGE_NONE,
      '#field_name' => 'field_fake_rtsb_id',
      '#field_type' => 'text',
      '#entity_type' => 'cls_mcl_interest_type',
      //'#bundle' => $entity->type,
      '#items' => array(array('value' => $entity->rtsb_id)),
      '#formatter' => 'text_default',
      0 => array('#markup' => check_plain($entity->rtsb_id))
    );

    $content['old_mcl_id'] = array(
      '#theme' => 'field',
      '#weight' => 3,
      '#title' =>t('Old MCL ID'),
      '#access' => TRUE,
      '#label_display' => 'above',
      '#view_mode' => 'full',
      '#language' => LANGUAGE_NONE,
      '#field_name' => 'field_fake_old_mcl_id',
      '#field_type' => 'text',
      '#entity_type' => 'cls_mcl_interest_type',
      //'#bundle' => $entity->type,
      '#items' => array(array('value' => $entity->old_mcl_id)),
      '#formatter' => 'text_default',
      0 => array('#markup' => check_plain($entity->old_mcl_id))
    );

    return parent::buildContent($entity, $view_mode, $langcode, $content);
  }
}

/**
 * CLS MCL Interest Type class.
 */
class CLSMCLInterestType extends Entity {
  protected function defaultLabel() {
    return $this->title;
  }

  protected function defaultUri() {
    return array('path' => 'cls-mcl-interest-type/' . $this->identifier());
  }
}
