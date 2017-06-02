<?php
/**
 * @file
 * cls_user.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function cls_user_user_default_roles() {
  $roles = array();

  // Exported role: Faculty Assistant.
  $roles['Faculty Assistant'] = array(
    'name' => 'Faculty Assistant',
    'weight' => 296,
  );

  // Exported role: Profile Editor.
  $roles['Profile Editor'] = array(
    'name' => 'Profile Editor',
    'weight' => 297,
  );

  return $roles;
}
