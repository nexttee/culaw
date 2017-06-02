<?php

class cls_mcl_handler_argument_course_categories extends views_handler_argument_many_to_one {

  function query($group_by = FALSE) {
    $empty = FALSE;
/*
    if (isset($this->definition['zero is null']) && $this->definition['zero is null']) {
      if (empty($this->argument)) {
        $empty = TRUE;
      }
    }
    else {
      if (!isset($this->argument)) {
        $empty = TRUE;
      }
    }
    if ($empty) {
      parent::ensure_my_table();
      $this->query->add_where(0, "$this->table_alias.$this->real_field", NULL, 'IS NULL');
      return;
    }
*/

/*
    if (!empty($this->options['break_phrase'])) {
      views_break_phrase($this->argument, $this);
    }
    else {
*/
      $this->value = array($this->argument);
      $this->operator = 'or';
/*     } */

    $this->ensure_my_table();
    
    $sep = ',';
    
    // negated operator uses AND, positive uses OR
    $op = 'LIKE';
    $glue = ($this->operator == 'or') ? 'OR ' : 'AND ';
    foreach ($this->value as $value) {
      $exploded_value_array = explode(',', $value);
      foreach ($exploded_value_array as $new_value) {
        if (!empty($new_value)) {
          $clauses[] = "$this->table_alias.$this->real_field " . $op . " '%" . $sep . $new_value . $sep . "%' ";
        }
      }
    }
    $clause = implode($glue, $clauses);
    $this->query->add_where_expression(0, $clause);
  }
}

class cls_mcl_handler_filter_course_categories extends views_handler_filter_in_operator {

  function get_value_options() {
    if (!isset($this->value_options)) {
      $query = db_select('cls_mcl_interest_type', 'cmit')
        ->fields('cmit', array('id', 'title'));
      $query->orderBy('title', 'ASC'); 
      $interests = $query->execute();
      while ($interest_record = $interests->fetchAssoc()) {
        $this->value_options[$interest_record['id']] = $interest_record['title'];
      }
      $this->value_options['%1'] = 'Value of argument 1 (if defined)';
      $this->value_options['%2'] = 'Value of argument 2 (if defined)';
      $this->value_options['%3'] = 'Value of argument 3 (if defined)';
    }
  }

  function op_simple() {
    if (empty($this->value)) {
        return;
    }
    
    $this->ensure_my_table();
    
    $sep = ',';
    
    // negated operator uses AND, positive uses OR
    $op = ($this->operator == 'in') ? 'LIKE' : 'NOT LIKE';
    $glue = ($this->operator == 'in') ? 'OR ' : 'AND ';
    foreach ($this->value as $value) {
      $exploded_value_array = explode(',', $value);
      foreach ($exploded_value_array as $new_value) {
        if (!empty($new_value)) {
          $clauses[] = "$this->table_alias.$this->real_field " . $op . " '%" . $sep . $new_value . $sep . "%' ";
        }
      }
    }
    $clause = implode($glue, $clauses);
    $this->query->add_where_expression($this->options['group'], $clause);
  }

}

class cls_mcl_handler_field_course_instructors extends views_handler_field {

  function get_value($values, $field = NULL) {
    $alias = isset($field) ? $this->aliases[$field] : $this->field_alias;
    if (isset($values->{$alias})) {
      $field_value = '';
      $instructors = _cls_courses_get_instructor_array_by_csv($values->{$alias});
      $instructor_count = count($instructors);
      $row_count = 0;
      foreach ($instructors as $instructor) {
        $row_count++;
        $field_value .= substr($instructor['first_name'], 0, 1) . '. ' . $instructor['last_name'];
        if ($row_count != $instructor_count)  {
          $field_value .= ', ';
        }
      }
      return $field_value;  
    }
  }

}

class cls_mcl_handler_field_course_html_to_plain extends views_handler_field {

  function get_value($values, $field = NULL) {
    $alias = isset($field) ? $this->aliases[$field] : $this->field_alias;
    if (isset($values->{$alias})) {
      //$field_value = $values->{$alias};
      $field_value = strip_tags($values->{$alias});
      return $field_value;  
    }
  }

}