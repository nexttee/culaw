<?php

class CLSCurriculumGuideOfferingEntity extends Entity {

  protected function defaultUri() {
    return array('path' => 'courses/' . $this->course_offering_number);
  }

}


class CLSCurriculumGuideOfferingEntityController extends EntityAPIController {
  /**
  * Override save method.
  * Populate created and updated timestamps automatically.
  */
  public function save($entity, DatabaseTransaction $transaction = NULL) {

    if (isset($entity->is_new)) {
      $entity->created_timestamp = REQUEST_TIME;
    }

    $entity->updated_timestamp = REQUEST_TIME;

    return parent::save($entity, $transaction);
  }
}


class CLSCurriculumGuideOfferingUIController extends EntityDefaultUIController {

  public function overviewForm($form, &$form_state) {
    $form['pager'] = array('#theme' => 'pager');

    $header = array(
      'name' => array('data' => t('Name'), 'field' => 'name'),
      'course_offering_number' => array('data' => t('Course Number'), 'field' => 'course_offering_number'),
      'operations' => array('data' => t('Operations'), 'field' => 'operations'),
    );

    $options = array();
    $search_term = !empty($_GET['search']) ? $_GET['search'] : NULL;

    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'cls_cg_offering');


    if (!empty($search_term)) {
      $query->propertyCondition('name', '%' . $search_term . '%', 'like');
    }

    // Check for sort order and sort key.
    if (!empty($_GET['sort']) && !empty($_GET['order'])) {
      $sort = strtoupper($_GET['sort']);
      $order = strtolower($_GET['order']);
      $order = str_replace(' ', '_', $order);
      if ($order == 'name') {
        $query->propertyOrderBy($order, $sort);
      }
    }

    $query->pager(50);

    $result = $query->execute();
    $results = !empty($result['cls_cg_offering']) ? $result['cls_cg_offering'] : array();
    $offerings = !empty($results) ? entity_load('cls_cg_offering', array_keys($results)) : array();
    
    foreach ($offerings as $offering_id => $offering) {
      $options['offering_id-' . $offering_id] = array(
        'name' => l($offering->name, 'courses/' . $offering->course_offering_number),
        'course_offering_number' => l($offering->course_offering_number, 'courses/' . $offering->course_offering_number),
        'operations' =>
        l(t('view'), 'courses/' . $offering->course_offering_number) . '&emsp;' .
        l(t('edit'), $this->path . '/manage/' . $offering_id) . '&emsp;' .
        l(t('delete'), $this->path . '/manage/' . $offering_id . '/delete', array('query' => drupal_get_destination()))
      );
    }

    $form['search'] = array(
      '#type' => 'fieldset',
      '#title' => t('Basic Search'),
      '#collapsible' => TRUE,
      '#collapsed' => !empty($search_term) ? FALSE : TRUE,
    );

    $form['search']['search_text'] = array(
      '#type' => 'textfield',
      '#title' => t('Search By Name'),
      '#default_value' => !empty($search_term) ? $search_term : '',
    );

    $form['search']['search_submit'] = array(
      '#type' => 'submit',
      '#value' => t('Search'),
    );

    $form['entities'] = array(
      '#type' => 'tableselect',
      '#header' => $header,
      '#options' => $options,
      '#attributes' => array('class' => array('entity-sort-table')),
      '#empty' => t('There are no course offerings.'),
    );

    return $form;
  }

  public function overviewFormSubmit($form, &$form_state) {
    $values = $form_state['input'];

    if (!empty($values['search_text'])) {
      drupal_goto('admin/config/services/cls-rest-api/cls_cg_offering', array('query' => array('search' => $values['search_text'])));
    }
  }
}
