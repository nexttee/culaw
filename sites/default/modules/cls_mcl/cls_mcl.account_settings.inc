<?php

/**
 * @file
 * Functions related to My Columbia Law account settings page.
 */

/**
* Displays My Columbia Law Account Settings page.
*
* @return $html - string containing Account Settings page layout
*/
function cls_mcl_display_account_settings($instance_id) {
  global $user;
  global $base_url;
  $edited_user = user_load($user->uid);
  $site_instances = array('path' => '');	
  if (isset($edited_user->cls_mcl_account_type['und'][0]['value']) && !empty($edited_user->cls_mcl_account_type['und'][0]['value'])) {
  	 $site_instances = cls_get_site_instances($edited_user->cls_mcl_account_type['und'][0]['value']);	
  	 if ($edited_user->cls_mcl_account_type['und'][0]['value'] != $instance_id) {
  	   drupal_goto($site_instances['path'] . '/account-settings');
  	 }
  }
  if(cls_mcl_account_settings_access()){
  	drupal_add_css(drupal_get_path('module', 'cls_mcl') . '/css/account_settings.css', array('every_page' => FALSE));
    return theme('account_settings', array('title' => "Account Settings",
                                'instance_id' => $instance_id,
                                'base_url' => $base_url,
                                'path' => $site_instances['path'] . '/account-settings',
                                'user' => $edited_user));
  }else{
  	$site_instance = cls_get_site_instance($instance_id);
    drupal_goto($site_instance['path']);
  }
}
