<?php

/**
 * @file
 * Functions related to My Columbia Law login.
 *
 * @TODO Add logic to redirect My Columbia Law (J.D.) who sign into
 *   the LL.M. version to their correct microsite, and vice-versa.
 *
 * @TODO Add the site instance to the auditing system.
 */

/**
* Renders the My Columbia Law login page.
*
* @return string Rendered HTML
*/
function cls_mcl_login_page($instance_id) {
  drupal_add_css(drupal_get_path('module', 'cls_mcl') . '/css/login.css', array('every_page' => FALSE));
  drupal_add_js(drupal_get_path('module', 'cls_mcl') . '/js/login.js', array('every_page' => FALSE));

  $site_instance = cls_get_site_instance($instance_id);

  $login_photo_uri = $site_instance['login_photo_uri'];
  if (!url_is_external($login_photo_uri)) {
    $login_photo_uri = base_path() . drupal_get_path('module', 'cls_mcl') . '/images/' . $login_photo_uri;
  }
  return theme(
    'mcl_login',
    array(
      'instance_id' => $instance_id,
      'instance_path' => $site_instance['path'],
      'title' => $site_instance['title'],
      'login_page_header' => $site_instance['login_page_header'],
      'login_photo_uri' => $login_photo_uri,
      'login_photo_caption' => $site_instance['login_photo_caption'],
      'login_form_header' => $site_instance['login_form_header'],
      'form' => drupal_get_form('cls_mcl_login_form', $site_instance),
    )
  );
}

/**
 * Set up a series for validators which check for blocked users,
 * then authenticate against local database, then return an error if
 * authentication fails.
 *
 * @see user_login_name_validate()
 * @see user_login_authenticate_validate()
 * @see user_login_final_validate()
 * @return array
 *   A simple list of validate functions.
 */
function cls_mcl_login_default_validators() {
  return array(
      'user_login_name_validate',
      'user_login_authenticate_validate',
      'cls_mcl_check_remote_login',
      'user_login_final_validate'
    );
}

/**
 * Generates MCL login form
 */
function cls_mcl_login_form($form, &$form_state, $site_instance) {
  $form = array();

  $form['name'] = array(
    '#type' => 'textfield',
    //'#title' => t('Email address'),
    '#size' => 60,
    '#maxlength' => USERNAME_MAX_LENGTH,
    '#required' => TRUE,
  );

  $form['pass'] = array(
    '#type' => 'password',
    //'#title' => t('Password'),
    '#required' => TRUE,
  );

  $form['instance_id'] = array(
    '#type' => 'value',
    '#value' => $site_instance['instance_id'],
  );
  
  $form['default_path'] = array(
    '#type' => 'value',
    '#value' => $site_instance['path'],
  );

  $form['#validate'] = cls_mcl_login_default_validators();

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array('#type' => 'submit', '#value' => t('Log in'));

  return $form;
}

/**
 * Submit handler for the login form. Load $user object and perform standard login
 * tasks. The user is then redirected to the My Account page. Setting the
 * destination in the query string overrides the redirect.
 */
function cls_mcl_login_form_submit($form, &$form_state) {
  global $user;
  //$old_state = drupal_save_session();
  //drupal_save_session(FALSE);
  $loaded_user = user_load($form_state['uid']);

  $default_destination = 'admissions/jd/my-columbia-law';
  if (!empty($form_state['values']['default_path'])) {
    $default_destination = $form_state['values']['default_path'];
  }

  if ($loaded_user) {
  	$user = $loaded_user;
    $destination = isset($_COOKIE['destination']) ? $_COOKIE['destination'] : $default_destination;
    $form_state['redirect'] = $destination;
    user_login_finalize($form_state);
    
    $log_params = array('type' => 1, //successful login
                        'data' => array('email' => $user->mail,
                                        'name' => $user->name),
                        'uid' => $user->uid,
                        'ip_address' => ip_address(),
                        'created' => REQUEST_TIME,
                        );
    cls_mcl_create_audit_log($log_params);

	// Expire the destination cookie after a successful login
	// to prevent it from being used in a subsequent log in
	// (if the user is quickly signing in, out,
	// and back in an account)
	setcookie('destination', '', time() - 3600, '/');
  }
  else {
    $form_state['redirect'] = $default_destination;
    $log_params = array('type' => 2, //failed login
                        'data' => '',
                        'uid' => $user->uid,
                        'ip_address' => ip_address(),
                        'created' => REQUEST_TIME,
                        );
    cls_mcl_create_audit_log($log_params);
  }
  //drupal_save_session($old_state);
}
