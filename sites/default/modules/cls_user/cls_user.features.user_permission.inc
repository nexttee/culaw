<?php
/**
 * @file
 * cls_user.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function cls_user_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_faculty_assistant_email'.
  $permissions['create field_faculty_assistant_email'] = array(
    'name' => 'create field_faculty_assistant_email',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_faculty_assistant_name'.
  $permissions['create field_faculty_assistant_name'] = array(
    'name' => 'create field_faculty_assistant_name',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_faculty_assistant_phone'.
  $permissions['create field_faculty_assistant_phone'] = array(
    'name' => 'create field_faculty_assistant_phone',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_faculty_assistant_users'.
  $permissions['create field_faculty_assistant_users'] = array(
    'name' => 'create field_faculty_assistant_users',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_faculty_bio_summary'.
  $permissions['create field_faculty_bio_summary'] = array(
    'name' => 'create field_faculty_bio_summary',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_faculty_office_address_1'.
  $permissions['create field_faculty_office_address_1'] = array(
    'name' => 'create field_faculty_office_address_1',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_faculty_office_address_2'.
  $permissions['create field_faculty_office_address_2'] = array(
    'name' => 'create field_faculty_office_address_2',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_faculty_office_city'.
  $permissions['create field_faculty_office_city'] = array(
    'name' => 'create field_faculty_office_city',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_faculty_office_email'.
  $permissions['create field_faculty_office_email'] = array(
    'name' => 'create field_faculty_office_email',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_faculty_office_fax'.
  $permissions['create field_faculty_office_fax'] = array(
    'name' => 'create field_faculty_office_fax',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_faculty_office_phone'.
  $permissions['create field_faculty_office_phone'] = array(
    'name' => 'create field_faculty_office_phone',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_faculty_office_state'.
  $permissions['create field_faculty_office_state'] = array(
    'name' => 'create field_faculty_office_state',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_faculty_office_zip_code'.
  $permissions['create field_faculty_office_zip_code'] = array(
    'name' => 'create field_faculty_office_zip_code',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_faculty_profile_bio'.
  $permissions['create field_faculty_profile_bio'] = array(
    'name' => 'create field_faculty_profile_bio',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_faculty_profile_elements'.
  $permissions['create field_faculty_profile_elements'] = array(
    'name' => 'create field_faculty_profile_elements',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_faculty_profile_image'.
  $permissions['create field_faculty_profile_image'] = array(
    'name' => 'create field_faculty_profile_image',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_faculty_role'.
  $permissions['create field_faculty_role'] = array(
    'name' => 'create field_faculty_role',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_faculty_assistant_email'.
  $permissions['edit field_faculty_assistant_email'] = array(
    'name' => 'edit field_faculty_assistant_email',
    'roles' => array(
      'Profile Editor' => 'Profile Editor',
      'System Administrator' => 'System Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_faculty_assistant_name'.
  $permissions['edit field_faculty_assistant_name'] = array(
    'name' => 'edit field_faculty_assistant_name',
    'roles' => array(
      'Faculty Assistant' => 'Faculty Assistant',
      'Profile Editor' => 'Profile Editor',
      'System Administrator' => 'System Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_faculty_assistant_phone'.
  $permissions['edit field_faculty_assistant_phone'] = array(
    'name' => 'edit field_faculty_assistant_phone',
    'roles' => array(
      'Faculty Assistant' => 'Faculty Assistant',
      'Profile Editor' => 'Profile Editor',
      'System Administrator' => 'System Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_faculty_assistant_users'.
  $permissions['edit field_faculty_assistant_users'] = array(
    'name' => 'edit field_faculty_assistant_users',
    'roles' => array(
      'Faculty Assistant' => 'Faculty Assistant',
      'Profile Editor' => 'Profile Editor',
      'System Administrator' => 'System Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_faculty_bio_summary'.
  $permissions['edit field_faculty_bio_summary'] = array(
    'name' => 'edit field_faculty_bio_summary',
    'roles' => array(
      'Faculty Assistant' => 'Faculty Assistant',
      'Profile Editor' => 'Profile Editor',
      'System Administrator' => 'System Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_faculty_office_address_1'.
  $permissions['edit field_faculty_office_address_1'] = array(
    'name' => 'edit field_faculty_office_address_1',
    'roles' => array(
      'Faculty Assistant' => 'Faculty Assistant',
      'Profile Editor' => 'Profile Editor',
      'System Administrator' => 'System Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_faculty_office_address_2'.
  $permissions['edit field_faculty_office_address_2'] = array(
    'name' => 'edit field_faculty_office_address_2',
    'roles' => array(
      'Profile Editor' => 'Profile Editor',
      'System Administrator' => 'System Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_faculty_office_city'.
  $permissions['edit field_faculty_office_city'] = array(
    'name' => 'edit field_faculty_office_city',
    'roles' => array(
      'Profile Editor' => 'Profile Editor',
      'System Administrator' => 'System Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_faculty_office_email'.
  $permissions['edit field_faculty_office_email'] = array(
    'name' => 'edit field_faculty_office_email',
    'roles' => array(
      'Faculty Assistant' => 'Faculty Assistant',
      'Profile Editor' => 'Profile Editor',
      'System Administrator' => 'System Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_faculty_office_fax'.
  $permissions['edit field_faculty_office_fax'] = array(
    'name' => 'edit field_faculty_office_fax',
    'roles' => array(
      'Profile Editor' => 'Profile Editor',
      'System Administrator' => 'System Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_faculty_office_phone'.
  $permissions['edit field_faculty_office_phone'] = array(
    'name' => 'edit field_faculty_office_phone',
    'roles' => array(
      'Faculty Assistant' => 'Faculty Assistant',
      'Profile Editor' => 'Profile Editor',
      'System Administrator' => 'System Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_faculty_office_state'.
  $permissions['edit field_faculty_office_state'] = array(
    'name' => 'edit field_faculty_office_state',
    'roles' => array(
      'Faculty Assistant' => 'Faculty Assistant',
      'Profile Editor' => 'Profile Editor',
      'System Administrator' => 'System Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_faculty_office_zip_code'.
  $permissions['edit field_faculty_office_zip_code'] = array(
    'name' => 'edit field_faculty_office_zip_code',
    'roles' => array(
      'Faculty Assistant' => 'Faculty Assistant',
      'Profile Editor' => 'Profile Editor',
      'System Administrator' => 'System Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_faculty_profile_bio'.
  $permissions['edit field_faculty_profile_bio'] = array(
    'name' => 'edit field_faculty_profile_bio',
    'roles' => array(
      'Faculty Assistant' => 'Faculty Assistant',
      'Profile Editor' => 'Profile Editor',
      'System Administrator' => 'System Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_faculty_profile_elements'.
  $permissions['edit field_faculty_profile_elements'] = array(
    'name' => 'edit field_faculty_profile_elements',
    'roles' => array(
      'Faculty Assistant' => 'Faculty Assistant',
      'Profile Editor' => 'Profile Editor',
      'System Administrator' => 'System Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_faculty_profile_image'.
  $permissions['edit field_faculty_profile_image'] = array(
    'name' => 'edit field_faculty_profile_image',
    'roles' => array(
      'Faculty Assistant' => 'Faculty Assistant',
      'Profile Editor' => 'Profile Editor',
      'System Administrator' => 'System Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_faculty_role'.
  $permissions['edit field_faculty_role'] = array(
    'name' => 'edit field_faculty_role',
    'roles' => array(
      'Faculty Assistant' => 'Faculty Assistant',
      'Profile Editor' => 'Profile Editor',
      'System Administrator' => 'System Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_faculty_assistant_email'.
  $permissions['edit own field_faculty_assistant_email'] = array(
    'name' => 'edit own field_faculty_assistant_email',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_faculty_assistant_name'.
  $permissions['edit own field_faculty_assistant_name'] = array(
    'name' => 'edit own field_faculty_assistant_name',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_faculty_assistant_phone'.
  $permissions['edit own field_faculty_assistant_phone'] = array(
    'name' => 'edit own field_faculty_assistant_phone',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_faculty_assistant_users'.
  $permissions['edit own field_faculty_assistant_users'] = array(
    'name' => 'edit own field_faculty_assistant_users',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_faculty_bio_summary'.
  $permissions['edit own field_faculty_bio_summary'] = array(
    'name' => 'edit own field_faculty_bio_summary',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_faculty_office_address_1'.
  $permissions['edit own field_faculty_office_address_1'] = array(
    'name' => 'edit own field_faculty_office_address_1',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_faculty_office_address_2'.
  $permissions['edit own field_faculty_office_address_2'] = array(
    'name' => 'edit own field_faculty_office_address_2',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_faculty_office_city'.
  $permissions['edit own field_faculty_office_city'] = array(
    'name' => 'edit own field_faculty_office_city',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_faculty_office_email'.
  $permissions['edit own field_faculty_office_email'] = array(
    'name' => 'edit own field_faculty_office_email',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_faculty_office_fax'.
  $permissions['edit own field_faculty_office_fax'] = array(
    'name' => 'edit own field_faculty_office_fax',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_faculty_office_phone'.
  $permissions['edit own field_faculty_office_phone'] = array(
    'name' => 'edit own field_faculty_office_phone',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_faculty_office_state'.
  $permissions['edit own field_faculty_office_state'] = array(
    'name' => 'edit own field_faculty_office_state',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_faculty_office_zip_code'.
  $permissions['edit own field_faculty_office_zip_code'] = array(
    'name' => 'edit own field_faculty_office_zip_code',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_faculty_profile_bio'.
  $permissions['edit own field_faculty_profile_bio'] = array(
    'name' => 'edit own field_faculty_profile_bio',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_faculty_profile_elements'.
  $permissions['edit own field_faculty_profile_elements'] = array(
    'name' => 'edit own field_faculty_profile_elements',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_faculty_profile_image'.
  $permissions['edit own field_faculty_profile_image'] = array(
    'name' => 'edit own field_faculty_profile_image',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_faculty_role'.
  $permissions['edit own field_faculty_role'] = array(
    'name' => 'edit own field_faculty_role',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_faculty_assistant_email'.
  $permissions['view field_faculty_assistant_email'] = array(
    'name' => 'view field_faculty_assistant_email',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_faculty_assistant_name'.
  $permissions['view field_faculty_assistant_name'] = array(
    'name' => 'view field_faculty_assistant_name',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_faculty_assistant_phone'.
  $permissions['view field_faculty_assistant_phone'] = array(
    'name' => 'view field_faculty_assistant_phone',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_faculty_assistant_users'.
  $permissions['view field_faculty_assistant_users'] = array(
    'name' => 'view field_faculty_assistant_users',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_faculty_bio_summary'.
  $permissions['view field_faculty_bio_summary'] = array(
    'name' => 'view field_faculty_bio_summary',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_faculty_office_address_1'.
  $permissions['view field_faculty_office_address_1'] = array(
    'name' => 'view field_faculty_office_address_1',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_faculty_office_address_2'.
  $permissions['view field_faculty_office_address_2'] = array(
    'name' => 'view field_faculty_office_address_2',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_faculty_office_city'.
  $permissions['view field_faculty_office_city'] = array(
    'name' => 'view field_faculty_office_city',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_faculty_office_email'.
  $permissions['view field_faculty_office_email'] = array(
    'name' => 'view field_faculty_office_email',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_faculty_office_fax'.
  $permissions['view field_faculty_office_fax'] = array(
    'name' => 'view field_faculty_office_fax',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_faculty_office_phone'.
  $permissions['view field_faculty_office_phone'] = array(
    'name' => 'view field_faculty_office_phone',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_faculty_office_state'.
  $permissions['view field_faculty_office_state'] = array(
    'name' => 'view field_faculty_office_state',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_faculty_office_zip_code'.
  $permissions['view field_faculty_office_zip_code'] = array(
    'name' => 'view field_faculty_office_zip_code',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_faculty_profile_bio'.
  $permissions['view field_faculty_profile_bio'] = array(
    'name' => 'view field_faculty_profile_bio',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_faculty_profile_elements'.
  $permissions['view field_faculty_profile_elements'] = array(
    'name' => 'view field_faculty_profile_elements',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_faculty_profile_image'.
  $permissions['view field_faculty_profile_image'] = array(
    'name' => 'view field_faculty_profile_image',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_faculty_role'.
  $permissions['view field_faculty_role'] = array(
    'name' => 'view field_faculty_role',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_faculty_assistant_email'.
  $permissions['view own field_faculty_assistant_email'] = array(
    'name' => 'view own field_faculty_assistant_email',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_faculty_assistant_name'.
  $permissions['view own field_faculty_assistant_name'] = array(
    'name' => 'view own field_faculty_assistant_name',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_faculty_assistant_phone'.
  $permissions['view own field_faculty_assistant_phone'] = array(
    'name' => 'view own field_faculty_assistant_phone',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_faculty_assistant_users'.
  $permissions['view own field_faculty_assistant_users'] = array(
    'name' => 'view own field_faculty_assistant_users',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_faculty_bio_summary'.
  $permissions['view own field_faculty_bio_summary'] = array(
    'name' => 'view own field_faculty_bio_summary',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_faculty_office_address_1'.
  $permissions['view own field_faculty_office_address_1'] = array(
    'name' => 'view own field_faculty_office_address_1',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_faculty_office_address_2'.
  $permissions['view own field_faculty_office_address_2'] = array(
    'name' => 'view own field_faculty_office_address_2',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_faculty_office_city'.
  $permissions['view own field_faculty_office_city'] = array(
    'name' => 'view own field_faculty_office_city',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_faculty_office_email'.
  $permissions['view own field_faculty_office_email'] = array(
    'name' => 'view own field_faculty_office_email',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_faculty_office_fax'.
  $permissions['view own field_faculty_office_fax'] = array(
    'name' => 'view own field_faculty_office_fax',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_faculty_office_phone'.
  $permissions['view own field_faculty_office_phone'] = array(
    'name' => 'view own field_faculty_office_phone',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_faculty_office_state'.
  $permissions['view own field_faculty_office_state'] = array(
    'name' => 'view own field_faculty_office_state',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_faculty_office_zip_code'.
  $permissions['view own field_faculty_office_zip_code'] = array(
    'name' => 'view own field_faculty_office_zip_code',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_faculty_profile_bio'.
  $permissions['view own field_faculty_profile_bio'] = array(
    'name' => 'view own field_faculty_profile_bio',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_faculty_profile_elements'.
  $permissions['view own field_faculty_profile_elements'] = array(
    'name' => 'view own field_faculty_profile_elements',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_faculty_profile_image'.
  $permissions['view own field_faculty_profile_image'] = array(
    'name' => 'view own field_faculty_profile_image',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_faculty_role'.
  $permissions['view own field_faculty_role'] = array(
    'name' => 'view own field_faculty_role',
    'roles' => array(
      'System Administrator' => 'System Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
