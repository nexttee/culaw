<?php

/**
 * @file
 * Functions related to My Columbia LL.M. status checker.
 */
 
function cls_mcl_llm_status_redirect() {
  $site_instance = cls_get_site_instance('my_columbia_llm');
  drupal_goto($site_instance['dashboard_status_checker_path'], array(), 301);
}
