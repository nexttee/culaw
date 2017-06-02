<?php
/**
 * @file
 * Contains the cls_aces2_applicant_views_handler_relationship class.
 */

class cls_aces2_applicant_views_handler_relationship extends views_handler_relationship {
  function option_definition() {
    $options = parent::option_definition();
    $options['applied_program'] = array('default' => array(2));
    $options['year_entering'] = array('default' => array('current'));

    return $options;
  }

  /**
   * Add an entity type option.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    
    $applied_program_options = array(
      1 => 'J.D.',
      2 => 'LL.M.',
    );

    $form['applied_program'] = array(
      '#title' => 'Applied Program',
      '#type' => 'radios',
      '#description' => t('Restrict this relationship to one or more applied programs.'),
      '#options' => $applied_program_options,
      '#default_value' => $this->options['applied_program'],
    );

    $form['year_entering'] = array(
      '#type' => 'select_or_other',
      '#title' => t('Criteria for relating applicant information'),
      '#default_value' => $this->options['year_entering'],
      '#options' => array(
        'current' => t('Only current applicants'),
        'any' => t('Current or former applicants ‡'),
        /* 'matching' => t('Only applicants who applied the same year indicated in MCL'), */
      ),
      '#other' => t('Only applicants from a specific entering year'),
      '#required' => TRUE,
      '#multiple' => FALSE,
      '#other_unknown_defaults' => 'ignore',
      '#other_delimiter' => FALSE,
      '#select_type' => 'radios',
    );

  }

  /**
   * Called to implement a relationship in a query.
   *
   * Mostly the same as the parent method, except we add an extra clause to
   * the join.
   */
  function query() {
    $table_data = views_fetch_data($this->definition['base']);
    $base_field = empty($this->definition['base field']) ? $table_data['table']['base']['field'] : $this->definition['base field'];
    $this->ensure_my_table();

    $def = $this->definition;
    $def['table'] = $this->definition['base'];
    $def['field'] = $base_field;
    $def['left_table'] = $this->table_alias;
    $def['left_field'] = $this->field;
    if (!empty($this->options['required'])) {
      $def['type'] = 'INNER';
    }

    $def['extra'] = array();

    $current_year_entering = variable_get('cls_mcl.config.current_application_year', date("Y"));
    
    if ($this->options['year_entering'] == 'current') {
      $def['extra'][] = array(
        'field' => 'year_entering',
        'value' => $current_year_entering,
      );
    }
    else if ($this->options['year_entering'] == 'any') {
    
    }
    else if ($this->options['year_entering'] == 'matching') {

    }
    else if (!empty($this->options['year_entering']) && intval($this->options['year_entering']) != 0) {
          $def['extra'][] = array(
    'field' => 'year_entering',
    'value' => intval($this->options['year_entering']),
    );
                  
    }

    // Add an extra clause to the join if there are bundle types selected.
    $def['extra'][] = array(
      'field' => 'program_applied',
      'value' => $this->options['applied_program'],
    );

    if (!empty($def['join_handler']) && class_exists($def['join_handler'])) {
      $join = new $def['join_handler'];
    }
    else {
      $join = new views_join();
    }

    $join->definition = $def;
    $join->construct();
    $join->adjusted = TRUE;

    // Use a short alias for this.
    $alias = $def['table'] . '_' . $this->table;
    $this->alias = $this->query->add_relationship($alias, $join, $this->definition['base'], $this->relationship);
  }
}

class cls_mcl_user_views_handler_relationship extends views_handler_relationship {

  /**
   * Called to implement a relationship in a query.
   *
   * Mostly the same as the parent method, except we add an extra clause to
   * the join.
   */
  function query() {
    $table_data = views_fetch_data($this->definition['base']);
    $base_field = empty($this->definition['base field']) ? $table_data['table']['base']['field'] : $this->definition['base field'];
    $this->ensure_my_table();

    $def = $this->definition;
    $def['table'] = $this->definition['base'];
    $def['field'] = $base_field;
    $def['left_table'] = $this->table_alias;
    $def['left_field'] = $this->field;
    if (!empty($this->options['required'])) {
      $def['type'] = 'INNER';
    }

    if (!empty($def['join_handler']) && class_exists($def['join_handler'])) {
      $join = new $def['join_handler'];
    }
    else {
      $join = new views_join();
    }

    $join->definition = $def;
    $join->construct();
    $join->adjusted = TRUE;

    // Use a short alias for this.
    $alias = $def['table'] . '_' . $this->table;
    $this->alias = $this->query->add_relationship($alias, $join, $this->definition['base'], $this->relationship);
  }
}