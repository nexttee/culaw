<?php
/**
 * @file
 * Drush commands for RT Migrations.
 */

/**
 * Implements hook_drush_command().
 */
function cls_migrate_rt_drush_command() {
  $items = array();
  $items['cls-migrate-rt-import-json'] = array(
    'description' => '(Re)import JSON file into the database prior to running profile migration',
    'aliases' => array('cmrij'),
    'callback' => 'cls_migrate_rt_import_json',
  );

  $items['cls-migrate-rt-fetch-json'] = array(
    'descrition' => 'Update JSON source files for RT migrations',
    'arguments' => array(
      'controller' => 'Specify type of content (contactmgr, contentmgr, eventmgr)',
      'module' => 'Specify which module data to update (contactmgr => profiles; contentmgr => apc, articlesc, calendar; eventmgr => calendar.',
    ),
    'options' => array(
      'username' => '(Optional) RT user to authenticate as, you will be prompted for username if not provided on command line.',
      'password' => '(Optional) Password for RT user, you will be prompted for password if not provided on command line.',
    ),
    'callback' => 'cls_migrate_rt_fetch_json',
    'aliases' => array('cmr-fetch'),
  );

  return $items;
}

/**
 * Callback for command cls-migrate-rt-import-json.
 */
function cls_migrate_rt_import_json() {
  if (($filepath = drupal_realpath("private://contactmgr-profiles-all.json")) !== FALSE) {
    $json_source = file_get_contents($filepath);
    if (($json = json_decode($json_source, TRUE)) !== NULL) {
      _cls_migrate_import_profiles($json);
    }
  }
}

/**
 * Callback for command cls-migrate-rt-fetch-json.
 *
 * @param string $controller
 *   RT CMS controller to add to URL; one of contentmgr, eventmgr, contactmgr.
 * @param string $module
 *   RT CMS module to add to URL; one of articlesc, apc, profiles, calendar.
 *
 * @return mixed
 *   Number of bytes written if file downloaded successfully; FALSE otherwise.
 */
function cls_migrate_rt_fetch_json($controller, $module) {
  $controller_module_map = array(
    'contactmgr' => array('profiles'),
    'contentmgr' => array('articlesc', 'apc', 'calendar'),
    'eventmgr' => array('calendar'),
    'pagemgr' => array('pages'),
  );
  if (!array_key_exists($controller, $controller_module_map)) {
    return drush_user_abort('Please specify a controller; valid values are contactmgr, contentmgr, eventmgr');
  }
  if (!in_array($module, $controller_module_map[$controller])) {
    return drush_user_abort('Please specify a valid module for the controller specified.');
  }
  $username = drush_get_option('username', '');
  if ($username == '') {
    $username = drush_prompt(dt('Username: '));
  }
  $password = drush_get_option('password', '');
  if ($password == '') {
    $password = drush_prompt(dt("Password: "));
  }
  if ($username == '' || $password == '') {
    return drush_user_abort('You must provide a username and password to continue.');
  }

  $cookie = _cls_migrate_rt_get_auth_cookie($username, $password);
  if ($cookie) {
    $bytes_written = _cls_migrate_rt_save_json($controller, $module, $cookie);
    if ($bytes_written) {
      drush_log(t('Wrote @bytes MB to file private://@controller-@module-all.json', array(
        '@bytes' => number_format($bytes_written / (1024 * 1024), 2),
        '@controller' => $controller,
        '@module' => $module,
      )), 'success');
    }
    else {
      drush_set_error('Unable to download JSON file.');
    }
  }
}

/**
 * Get session cookie to send with authenticated RT JSON requests.
 *
 * @param string $username
 *   Username to authenticate with.
 * @param string $password
 *   Password to authenticate with.
 *
 * @return string
 *   Authenticated session cookie if successful; empty string otherwise.
 */
function _cls_migrate_rt_get_auth_cookie($username, $password) {
  $cookie = '';
  $form = array(
    'username' => $username,
    'password' => $password,
    'rtrefresh_success' => 'http://www.law.columbia.edu/',
    'rtrefresh_fail' => 'http://www.law.columbia.edu/login?&main.ctrl=null&main.view=users.login',
    'call' => 'usermgr.auth',
    'layout' => 'loginredirector',
    'isNS4' => 'false',
  );

  $options = array(
    'method' => 'POST',
    'data' => http_build_query($form),
    'headers' => array('Content-Type' => 'application/x-www-form-urlencoded'),
  );

  $response = drupal_http_request('http://www.law.columbia.edu/login', $options);
  if ($response->code == 200) {
    // Check to see if authentication was successful by checking the meta
    // refresh url value.
    $pattern = '|<META HTTP-EQUIV="REFRESH" CONTENT="0; URL=(.*)">|i';
    preg_match($pattern, $response->data, $matches);
    if (isset($matches[1]) && $matches[1] == 'http://www.law.columbia.edu/') {
      $cookie = $response->headers['set-cookie'];
    }
  }

  return $cookie;
}

/**
 * Make request to the CLS JSON API for a specific controller/module.
 *
 * @param string $controller
 *   RT owner_controller corresponds to manger query parameter.
 * @param string $module
 *   RT owner_module, corresponds to module query parameter.
 * @param string $cookie
 *   Session cookie for authenticated request.
 *
 * @return mixed
 *   Return number of bytes written on success; FALSE otherwise.
 */
function _cls_migrate_rt_save_json($controller, $module, $cookie) {
  $api_url = "http://www.law.columbia.edu/rt/null?exclusive={$controller}.list&rtresponsetype=json&module={$module}&fieldlist=*";
  $options = array(
    'headers' => array(
      'Cookie' => $cookie,
    ),
    'timeout' => 600,
  );
  $response = drupal_http_request($api_url, $options);
  if ($response->code == 200) {
    $filepath = drupal_realpath("private://{$controller}-{$module}-all.json");
    return file_put_contents($filepath, $response->data);
  }

  return FALSE;
}

/**
 * Process JSON data and save to database for profiles.
 *
 * @param string $json
 *   Decoded JSON string.
 */
function _cls_migrate_import_profiles($json) {
  $field_list = array(
    "cat1_id",
    "cat2_id",
    "catid_list",
    "email",
    "name_first",
    "name_last",
    "name_middle",
    "phone_1",
    "phone_2",
    "prefix",
    "status",
    "suffix",
    "title",
    "uid",
    "usr_img_1",
    "usr_img_2",
    "usr_meta_1",
    "world_group_id",
    "w_address_1",
    "w_address_2",
    "w_city",
    "w_read",
    "w_state",
    "w_zip",
    "x_assistant_email",
    "x_assistant_name",
    "x_assistant_phone",
    "x_marketing_abstract",
    "x_profile_abstract",
    "x_profile_detail",
  );
  // Delete profile data and just insert it all again.
  db_delete('migrate_profile_main')->execute();
  db_delete('migrate_profile_extras')->execute();

  foreach ($json['rt_objects'] as $object) {
    $fields = array();
    $fields['date_modified'] = strtotime($object['_attributes']['date_modified']);
    $fields['contact_id'] = $object['_attributes']['item_id'];
    $json_fields = $object['fields'];
    foreach ($field_list as $field_name) {
      $fields[$field_name] = $json_fields[$field_name];
    }
    db_insert('migrate_profile_main')->fields($fields)->execute();
    for ($i = 0; $i < 30; $i++) {
      $extra_fields = array();
      $fieldnames = array(
        "x_element${i}_name_id" => 'element_name_id',
        "x_element${i}_name" => 'element_name',
        "x_element${i}_desc" => 'element_description',
        "x_element${i}_url" => 'element_url',
        "x_element${i}_attach" => 'element_attach',
      );
      if (!empty($json_fields["x_element${i}_name_id"])) {
        foreach ($fieldnames as $src => $dest) {
          $extra_fields[$dest] = $json_fields[$src];
        }
        $extra_fields['contact_id'] = $object['_attributes']['item_id'];
        $extra_fields['element_index'] = $i;
        db_insert('migrate_profile_extras')->fields($extra_fields)->execute();
      }
    }
  }
}
