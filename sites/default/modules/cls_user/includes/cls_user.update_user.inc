<?php

/**
 * @file
 * Support for updating user profile information.
 */

/**
 * Operation callback for updating Alumni year field.
 */
function cls_user_update_user_field($chunk, $msg, $alumni_roles, $email_blocked_user_notice_value, $vocabulary, &$context) {
  $context['message'] = $msg;
  $context['results']['email_blocked_user_notice_value'] = $email_blocked_user_notice_value;

  $users = user_load_multiple($chunk);
  foreach ($users AS $user) {
    $term_ids = array();
    $wrapper_user = entity_metadata_wrapper('user', $user);
    $role_year_value = array_intersect_key($alumni_roles, $user->roles);

    if (sizeof($role_year_value) > 1) {
      drush_print(sprintf('Multiple Alumni Roles found for user id : %s', $user->uid));
    }
    foreach ($role_year_value AS $rid => $year) {
      $term_ids[] = cls_user_get_term_id($vocabulary, $year);
    }
    // Setting "Alumni year" field value.
    $wrapper_user->field_alumni_year->set($term_ids);

    $wrapper_user->save();
  }
}

/**
 * Finish callback for user update batch process.
 */
function cls_user_update_user_field_finished($success, $results, $operations) {
  drush_print("Completed updating Alumni year field for users.");
  variable_set('user_mail_status_blocked_notify', $results['email_blocked_user_notice_value']);
}

/**
 * This function will create mapping of relevant user role to particular year.
 */
function cls_user_map_alumni_role_year() {
  // This is key value array for mapping.
  // key is rid of role and value is particular alumni year.
  $query = 'SELECT rid,name FROM
          {role} WHERE name LIKE :lawnet OR name LIKE :alumni';
  $result = db_query($query, array(
    ':lawnet' => '%lw.alum:columbia.edu%',
    ':alumni' => '%alumni%'
  ));
  foreach ($result as $record) {
    // ensures that only roles with numbers in them are included. ex. ("Alumni - 1970") or ex. ("y2013.lw.alum:columbia.edu")
    if (preg_match('/[0-9]/', $record->name)) {
      $mapping[$record->rid] = preg_replace("/[^0-9]/","",$record->name);
    }
  }
  return $mapping;
}

/**
 * This function will create mapping of JD students to particular roles.
 */
function cls_user_map_jd_student_role() {
  // key is rid of role and value is particular role name.
  $query = 'SELECT ur.uid, ur.rid, dr.name FROM {users_roles} AS ur INNER JOIN
    {role} AS dr ON ur.rid = dr.rid WHERE ur.rid IN (SELECT rid FROM
    {role} WHERE name LIKE :jd) AND name
    NOT LIKE :microsite OR :editor';
  $result = db_query($query, array(
    ':jd' => '%J.D.%',
    ':microsite' => '%microsite%',
    ':editor' => '%editor%',
  ));
  foreach ($result as $record) {
    $mapping[$record->rid] = $record->name;
  }
  return $mapping;
}

/**
 * This callback will update student type field with relevant taxonomy term
 * values.
 */
function cls_user_update_jd_student_type_field($chunk, $msg, $jd_roles, $email_blocked_user_notice_value, $vocabulary, &$context) {
  $context['message'] = $msg;
  $context['results']['email_blocked_user_notice_value'] = $email_blocked_user_notice_value;

  $users = user_load_multiple($chunk);
  foreach ($users AS $user) {
    $term_ids = array();
    $wrapper_user = entity_metadata_wrapper('user', $user);
    $jd_user_roles = array_intersect_key($jd_roles, $user->roles);

    foreach ($jd_user_roles AS $rid => $role_name) {
      switch ($role_name) {
        case 'Admitted Student (J.D.) User':
          $term_ids[] = cls_user_get_term_id($vocabulary, 'JD Admitted');
          break;
        case 'Deposited Deferred Student (J.D.) User':
          $term_ids[] = cls_user_get_term_id($vocabulary, 'JD Deposited Deferred');
          break;
        case 'Deposited Student (J.D.) LawNet User':
          $term_ids[] = cls_user_get_term_id($vocabulary, 'JD Deposited Lawnet');
          break;
        case 'Deposited Student (J.D.) User':
          $term_ids[] = cls_user_get_term_id($vocabulary, 'JD Deposited');
          break;
        case 'Student: J.D.: 1L User':
          $term_ids[] = cls_user_get_term_id($vocabulary, 'JD 1L');
          break;
        case 'Student: J.D.: 2L User':
          $term_ids[] = cls_user_get_term_id($vocabulary, 'JD 2L');
          break;
        case 'Student: J.D.: 3L User':
          $term_ids[] = cls_user_get_term_id($vocabulary, 'JD 3L');
          break;
        case 'Deferred Student (J.D.) User':
          $term_ids[] = cls_user_get_term_id($vocabulary, 'Deferred Student (J.D.) User');
          break;
        default:
          $term_ids[] = '';
      }
    }
    // Setting "Current Student Type" field value.
    $wrapper_user->field_current_student_type->set($term_ids);

    $wrapper_user->save();
  }
}

/**
 * Finish callback for student type user profile field update batch.
 */
function cls_user_update_jd_student_type_field_finished($success, $results, $operations) {
  drush_print("Completed updating J.D. Current Student type user profile fields.");
  variable_set('user_mail_status_blocked_notify', $results['email_blocked_user_notice_value']);
}

/**
 * This function will create mapping of GLS students to particular role ids.
 */
function cls_user_map_gls_student_role() {
  // key is rid of role and value is particular role name.
  $query = 'SELECT ur.uid, ur.rid, dr.name FROM {users_roles} AS ur INNER JOIN
    {role} AS dr ON ur.rid = dr.rid WHERE ur.rid IN (SELECT rid FROM
    {role} WHERE name LIKE :gls OR name LIKE
    :current_llm ) AND name NOT LIKE :microsite OR :editor';
  $result = db_query($query, array(
    ':gls' => '%(GLS)%',
    ':current_llm' => '%Current LL.M. Students%',
    ':editor' => '%editor%',
    ':microsite' => '%microsite%',
  ));
  foreach ($result as $record) {
    $mapping[$record->rid] = $record->name;
  }
  return $mapping;
}

/**
 * This callback will update student type field with relevant current student
 * type taxonomy term values.
 */
function cls_user_update_gls_student_type_field($chunk, $msg, $gls_roles, $email_blocked_user_notice_value, $vocabulary, &$context) {
  $context['message'] = $msg;
  $context['results']['email_blocked_user_notice_value'] = $email_blocked_user_notice_value;

  $users = user_load_multiple($chunk);
  foreach ($users AS $user) {
    $wrapper_user = entity_metadata_wrapper('user', $user);
    $gls_user_roles = array_intersect_key($gls_roles, $user->roles);

    foreach ($gls_user_roles AS $rid => $role_name) {
      $term_ids = array();
      switch ($role_name) {
        case 'Admitted Student (GLS) User':
          $term_ids[] = cls_user_get_term_id($vocabulary, 'GLS Admitted');
          break;
        case 'Committed Student (GLS) Lawnet User':
          $term_ids[] = cls_user_get_term_id($vocabulary, 'GLS Committed Lawnet');
          break;
        case 'Committed Student (GLS) User':
          $term_ids[] = cls_user_get_term_id($vocabulary, 'GLS Committed');
          break;
        case 'Current LL.M. Students':
          $term_ids[] = cls_user_get_term_id($vocabulary, 'Current GLS');
          break;
        default:
          $term_ids[] = '';
      }
    }
    // Setting "Current Student Type" field value.
    $wrapper_user->field_current_student_type->set($term_ids);

    $email_blocked_user_notice_value = variable_get('user_mail_status_blocked_notify', FALSE);
    variable_set('user_mail_status_blocked_notify', FALSE);
    $wrapper_user->save();
    variable_set('user_mail_status_blocked_notify', $email_blocked_user_notice_value);
  }
}

/**
 * Finish callback for student type user profile field update batch.
 */
function cls_user_update_gls_student_type_field_finished($success, $results, $operations) {
  drush_print("Completed updating G.L.S. Current Student type user profile fields.");
  variable_set('user_mail_status_blocked_notify', $results['email_blocked_user_notice_value']);
}

/**
 * This function will create mapping of Prospective students to particular role
 * ids.
 */
function cls_user_map_prospective_student_role() {
  // key is rid of role and value is particular role name.
  $query = 'SELECT ur.uid, ur.rid, dr.name FROM {users_roles} AS ur INNER JOIN
    {role} AS dr ON ur.rid = dr.rid WHERE ur.rid IN (SELECT rid
    FROM {role} WHERE name LIKE :mycolumbia) AND name NOT
    LIKE :microsite OR :editor';
  $result = db_query($query, array(
    ':mycolumbia' => '%my columbia%',
    ':editor' => '%editor%',
    ':microsite' => '%microsite%',
  ));
  foreach ($result as $record) {
    $mapping[$record->rid] = $record->name;
  }
  return $mapping;
}

/**
 * This callback will update Prospective Student type field with relevant
 * taxonomy term values.
 */
function cls_user_update_prospective_student_type_field($chunk, $msg, $prospective_roles, $email_blocked_user_notice_value, $vocabulary, &$context) {
  $context['message'] = $msg;
  $context['results']['email_blocked_user_notice_value'] = $email_blocked_user_notice_value;

  $users = user_load_multiple($chunk);

  foreach ($users AS $user) {
    $term_ids = array();
    $wrapper_user = entity_metadata_wrapper('user', $user);
    $prospective_user_roles = array_intersect_key($prospective_roles, $user->roles);

    foreach ($prospective_user_roles AS $rid => $role_name) {
      switch ($role_name) {
        case 'My Columbia LL.M. User':
          $term_ids[] = cls_user_get_term_id($vocabulary, 'MCLLM');
          break;
        case 'My Columbia Law User':
          $term_ids[] = cls_user_get_term_id($vocabulary, 'MCL');
          break;
        default:
          $term_ids[] = '';
      }
    }
    // Setting "Prospective Student Type" field value.
    $wrapper_user->field_prospective_student_type->set($term_ids);

    $email_blocked_user_notice_value = variable_get('user_mail_status_blocked_notify', FALSE);
    variable_set('user_mail_status_blocked_notify', FALSE);
    $wrapper_user->save();
    variable_set('user_mail_status_blocked_notify', $email_blocked_user_notice_value);
  }
}

/**
 * Finish callback for Prospective Student type user profile field update batch.
 */
function cls_user_update_prospective_student_type_field_finished($success, $results, $operations) {
  drush_print("Completed updating Prospective Student type user profile fields.");
  variable_set('user_mail_status_blocked_notify', $results['email_blocked_user_notice_value']);
}


/**
 * This function will create taxonomy term.
 */
function cls_user_create_taxonomy_term($vocabulary, $title, $description) {
  $term = new stdClass();
  $term->name = $title;
  $term->description = $description;
  $term->vid = $vocabulary->vid;
  taxonomy_term_save($term);
  return $term;
}

/**
 * This function will return term id.
 * If term is not found then it will create particular term and return it's tid
 */
function cls_user_get_term_id($vocabulary, $title) {
  $term = taxonomy_get_term_by_name($title, $vocabulary->machine_name);
  if ($term) {
    return key($term);
  }
  else {
    $term = cls_user_create_taxonomy_term($vocabulary, $title, '');
    return $term->tid;
  }
}

