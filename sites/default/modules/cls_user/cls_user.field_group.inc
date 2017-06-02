<?php
/**
 * @file
 * cls_user.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cls_user_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_alumni_details|user|user|form';
  $field_group->group_name = 'group_alumni_details';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Alumni Details',
    'weight' => '10',
    'children' => array(
      0 => 'cls_user_alumni_preferred_degree',
      1 => 'cls_user_alumni_preferred_year',
      2 => 'cls_user_alumni_preferred_email',
      3 => 'field_alumni_year',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Alumni Details',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-alumni-details field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_alumni_details|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_element_description|paragraphs_item|faculty_profile_elements|faculty_detail_items';
  $field_group->group_name = 'group_element_description';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'faculty_profile_elements';
  $field_group->mode = 'faculty_detail_items';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Element Description',
    'weight' => '1',
    'children' => array(
      0 => 'field_element_description',
      1 => 'field_element_file_attachment',
      2 => 'field_element_link',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Element Description',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-element-description field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_element_description|paragraphs_item|faculty_profile_elements|faculty_detail_items'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_faculty_details|user|user|form';
  $field_group->group_name = 'group_faculty_details';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Faculty Details',
    'weight' => '4',
    'children' => array(
      0 => 'field_faculty_office_address_1',
      1 => 'field_faculty_office_address_2',
      2 => 'field_faculty_office_city',
      3 => 'field_faculty_office_state',
      4 => 'field_faculty_office_zip_code',
      5 => 'field_faculty_office_phone',
      6 => 'field_faculty_office_fax',
      7 => 'field_faculty_role',
      8 => 'field_faculty_office_email',
      9 => 'field_faculty_profile_image',
      10 => 'field_faculty_assistant_name',
      11 => 'field_faculty_assistant_email',
      12 => 'field_faculty_assistant_phone',
      13 => 'field_faculty_profile_elements',
      14 => 'field_faculty_assistant_users',
      15 => 'field_faculty_profile_bio',
      16 => 'field_faculty_bio_summary',
      17 => 'field_faculty_marketing_bio',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Faculty Details',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-faculty-details field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_faculty_details|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_mcl_details|user|user|form';
  $field_group->group_name = 'group_mcl_details';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'MCL Details',
    'weight' => '6',
    'children' => array(
      0 => 'cls_mcl_remote_user_id',
      1 => 'cls_mcl_birth_date',
      2 => 'cls_mcl_lsac_account_number',
      3 => 'cls_mcl_country',
      4 => 'cls_mcl_state_province',
      5 => 'cls_mcl_city',
      6 => 'cls_mcl_zip_code',
      7 => 'cls_mcl_undergrad_institution',
      8 => 'cls_mcl_undergrad_inst_other',
      9 => 'cls_mcl_undergrad_grad_year',
      10 => 'cls_mcl_grad_institution',
      11 => 'cls_mcl_grad_inst_other',
      12 => 'cls_mcl_grad_graduation_year',
      13 => 'cls_mcl_admissions_cycle',
      14 => 'cls_mcl_academic_interests',
      15 => 'cls_mcl_student_org_interests',
      16 => 'cls_mcl_security_question',
      17 => 'cls_mcl_security_answer',
      18 => 'cls_mcl_account_type',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'MCL Details',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-mcl-details field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_mcl_details|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_student_type_details|user|user|form';
  $field_group->group_name = 'group_student_type_details';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Student Type Details',
    'weight' => '7',
    'children' => array(
      0 => 'field_current_student_type',
      1 => 'field_prospective_student_type',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Student Type Details',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-student-type-details field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_student_type_details|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_information|user|user|form';
  $field_group->group_name = 'group_user_information';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'User Information',
    'weight' => '2',
    'children' => array(
      0 => 'cls_user_first_name',
      1 => 'cls_user_middle_name',
      2 => 'cls_user_last_name',
      3 => 'cls_user_prefix',
      4 => 'cls_user_suffix',
      5 => 'cls_user_advance_id',
      6 => 'cls_user_harris_id',
      7 => 'cls_user_department',
      8 => 'cls_user_title',
      9 => 'cls_user_alternate_email',
      10 => 'cls_user_raisers_edge_id',
      11 => 'cls_user_uni',
      12 => 'cls_user_upn',
      13 => 'cls_sso_passcode',
      14 => 'mimemail',
      15 => 'picture',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'User Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-user-information field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_user_information|user|user|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Alumni Details');
  t('Element Description');
  t('Faculty Details');
  t('MCL Details');
  t('Student Type Details');
  t('User Information');

  return $field_groups;
}
