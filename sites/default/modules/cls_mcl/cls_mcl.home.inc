<?php

/**
 * @file
 * Functions related to the My Columbia Law home page.
 */

/**
* Page callback for the home page.
*
* @return string Rendered HTML content
*/
function cls_mcl_home_page($instance_id) {
  if (user_is_logged_in()) {
    module_load_include('inc', 'cls_mcl', 'cls_mcl.dashboard');
    return cls_mcl_dashboard_page($instance_id);
  }
  module_load_include('inc', 'cls_mcl', 'cls_mcl.login');
  return cls_mcl_login_page($instance_id);
}
