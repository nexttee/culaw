<?php
/**
 * @file
 * cls_user.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function cls_user_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'faculty_profile_block';
  $view->description = 'This view provides block which contains information related to faculty profile.';
  $view->tag = 'faculty, profile';
  $view->base_table = 'users';
  $view->human_name = 'Faculty Profile Block';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Field: User: Faculty Profile Image */
  $handler->display->display_options['fields']['field_faculty_profile_image']['id'] = 'field_faculty_profile_image';
  $handler->display->display_options['fields']['field_faculty_profile_image']['table'] = 'field_data_field_faculty_profile_image';
  $handler->display->display_options['fields']['field_faculty_profile_image']['field'] = 'field_faculty_profile_image';
  $handler->display->display_options['fields']['field_faculty_profile_image']['label'] = '';
  $handler->display->display_options['fields']['field_faculty_profile_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_faculty_profile_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_faculty_profile_image']['settings'] = array(
    'image_style' => 'faculty_details_300x360',
    'image_link' => '',
  );
  /* Field: Global: Fieldset */
  $handler->display->display_options['fields']['fieldset']['id'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset']['table'] = 'views';
  $handler->display->display_options['fields']['fieldset']['field'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset']['label'] = 'Office Location';
  $handler->display->display_options['fields']['fieldset']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['fieldset']['children'] = array(
    0 => 'nothing',
    1 => 'fieldset_3',
  );
  $handler->display->display_options['fields']['fieldset']['fieldset']['type'] = 'div';
  $handler->display->display_options['fields']['fieldset']['fieldset']['classes'] = 'faculty-office-location';
  /* Field: Office Location Title */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Office Location Title';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Office Location';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'office-location-title';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Global: Fieldset */
  $handler->display->display_options['fields']['fieldset_3']['id'] = 'fieldset_3';
  $handler->display->display_options['fields']['fieldset_3']['table'] = 'views';
  $handler->display->display_options['fields']['fieldset_3']['field'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset_3']['label'] = 'Office Address';
  $handler->display->display_options['fields']['fieldset_3']['children'] = array(
  0 => 'field_faculty_office_address_1',
  1 => 'field_office_number',
  2 => 'field_faculty_office_address_2',
  3 => 'field_faculty_office_city',
  4 => 'field_faculty_office_state',
  5 => 'field_faculty_office_zip_code',
  );
  $handler->display->display_options['fields']['fieldset_3']['fieldset']['type'] = 'div';
  $handler->display->display_options['fields']['fieldset_3']['fieldset']['classes'] = 'office__addess field__content';
  /* Field: User: Faculty Office Address 1 */
  $handler->display->display_options['fields']['field_faculty_office_address_1']['id'] = 'field_faculty_office_address_1';
  $handler->display->display_options['fields']['field_faculty_office_address_1']['table'] = 'field_data_field_faculty_office_address_1';
  $handler->display->display_options['fields']['field_faculty_office_address_1']['field'] = 'field_faculty_office_address_1';
  $handler->display->display_options['fields']['field_faculty_office_address_1']['label'] = '';
  $handler->display->display_options['fields']['field_faculty_office_address_1']['element_label_colon'] = FALSE;
  /* Field: User: Office Number */
  $handler->display->display_options['fields']['field_office_number']['id'] = 'field_office_number';
  $handler->display->display_options['fields']['field_office_number']['table'] = 'field_data_field_office_number';
  $handler->display->display_options['fields']['field_office_number']['field'] = 'field_office_number';
  $handler->display->display_options['fields']['field_office_number']['label'] = '';
  $handler->display->display_options['fields']['field_office_number']['element_label_colon'] = FALSE;
  /* Field: User: Faculty Office Address 2 */
  $handler->display->display_options['fields']['field_faculty_office_address_2']['id'] = 'field_faculty_office_address_2';
  $handler->display->display_options['fields']['field_faculty_office_address_2']['table'] = 'field_data_field_faculty_office_address_2';
  $handler->display->display_options['fields']['field_faculty_office_address_2']['field'] = 'field_faculty_office_address_2';
  $handler->display->display_options['fields']['field_faculty_office_address_2']['label'] = '';
  $handler->display->display_options['fields']['field_faculty_office_address_2']['element_label_colon'] = FALSE;
  /* Field: User: Faculty Office City */
  $handler->display->display_options['fields']['field_faculty_office_city']['id'] = 'field_faculty_office_city';
  $handler->display->display_options['fields']['field_faculty_office_city']['table'] = 'field_data_field_faculty_office_city';
  $handler->display->display_options['fields']['field_faculty_office_city']['field'] = 'field_faculty_office_city';
  $handler->display->display_options['fields']['field_faculty_office_city']['label'] = '';
  $handler->display->display_options['fields']['field_faculty_office_city']['element_label_colon'] = FALSE;
  /* Field: User: Faculty Office State */
  $handler->display->display_options['fields']['field_faculty_office_state']['id'] = 'field_faculty_office_state';
  $handler->display->display_options['fields']['field_faculty_office_state']['table'] = 'field_data_field_faculty_office_state';
  $handler->display->display_options['fields']['field_faculty_office_state']['field'] = 'field_faculty_office_state';
  $handler->display->display_options['fields']['field_faculty_office_state']['label'] = '';
  $handler->display->display_options['fields']['field_faculty_office_state']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_faculty_office_state']['type'] = 'list_key';
  /* Field: User: Faculty Office Zip Code */
  $handler->display->display_options['fields']['field_faculty_office_zip_code']['id'] = 'field_faculty_office_zip_code';
  $handler->display->display_options['fields']['field_faculty_office_zip_code']['table'] = 'field_data_field_faculty_office_zip_code';
  $handler->display->display_options['fields']['field_faculty_office_zip_code']['field'] = 'field_faculty_office_zip_code';
  $handler->display->display_options['fields']['field_faculty_office_zip_code']['label'] = '';
  $handler->display->display_options['fields']['field_faculty_office_zip_code']['element_label_colon'] = FALSE;
  /* Field: Global: Fieldset */
  $handler->display->display_options['fields']['fieldset_1']['id'] = 'fieldset_1';
  $handler->display->display_options['fields']['fieldset_1']['table'] = 'views';
  $handler->display->display_options['fields']['fieldset_1']['field'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset_1']['label'] = 'Contact Info';
  $handler->display->display_options['fields']['fieldset_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['fieldset_1']['children'] = array(
  0 => 'nothing_1',
  1 => 'fieldset_4',
  );
  $handler->display->display_options['fields']['fieldset_1']['fieldset']['type'] = 'div';
  $handler->display->display_options['fields']['fieldset_1']['fieldset']['classes'] = 'faculty-contact-info';
  /* Field: Contact Info Title */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Contact Info Title';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'Contact Info';
  $handler->display->display_options['fields']['nothing_1']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing_1']['element_class'] = 'contact-info-title';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['hide_empty'] = TRUE;
  /* Field: Global: Fieldset */
  $handler->display->display_options['fields']['fieldset_4']['id'] = 'fieldset_4';
  $handler->display->display_options['fields']['fieldset_4']['table'] = 'views';
  $handler->display->display_options['fields']['fieldset_4']['field'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset_4']['label'] = 'Contact Details';
  $handler->display->display_options['fields']['fieldset_4']['children'] = array(
  0 => 'field_faculty_office_phone',
  1 => 'field_faculty_office_fax',
  2 => 'field_faculty_office_email',
  3 => 'field_faculty_twitter',
  );
  $handler->display->display_options['fields']['fieldset_4']['fieldset']['type'] = 'div';
  $handler->display->display_options['fields']['fieldset_4']['fieldset']['classes'] = 'contact__details field__content';
  /* Field: User: Faculty Office Phone */
  $handler->display->display_options['fields']['field_faculty_office_phone']['id'] = 'field_faculty_office_phone';
  $handler->display->display_options['fields']['field_faculty_office_phone']['table'] = 'field_data_field_faculty_office_phone';
  $handler->display->display_options['fields']['field_faculty_office_phone']['field'] = 'field_faculty_office_phone';
  $handler->display->display_options['fields']['field_faculty_office_phone']['label'] = 'Tel';
  /* Field: User: Faculty Office Fax */
  $handler->display->display_options['fields']['field_faculty_office_fax']['id'] = 'field_faculty_office_fax';
  $handler->display->display_options['fields']['field_faculty_office_fax']['table'] = 'field_data_field_faculty_office_fax';
  $handler->display->display_options['fields']['field_faculty_office_fax']['field'] = 'field_faculty_office_fax';
  $handler->display->display_options['fields']['field_faculty_office_fax']['label'] = 'Fax';
  $handler->display->display_options['fields']['field_faculty_office_fax']['hide_empty'] = TRUE;
  /* Field: User: Faculty Office Email */
  $handler->display->display_options['fields']['field_faculty_office_email']['id'] = 'field_faculty_office_email';
  $handler->display->display_options['fields']['field_faculty_office_email']['table'] = 'field_data_field_faculty_office_email';
  $handler->display->display_options['fields']['field_faculty_office_email']['field'] = 'field_faculty_office_email';
  $handler->display->display_options['fields']['field_faculty_office_email']['label'] = '';
  $handler->display->display_options['fields']['field_faculty_office_email']['element_label_colon'] = FALSE;
  /* Field: User: Faculty Twitter */
  $handler->display->display_options['fields']['field_faculty_twitter']['id'] = 'field_faculty_twitter';
  $handler->display->display_options['fields']['field_faculty_twitter']['table'] = 'field_data_field_faculty_twitter';
  $handler->display->display_options['fields']['field_faculty_twitter']['field'] = 'field_faculty_twitter';
  $handler->display->display_options['fields']['field_faculty_twitter']['ui_name'] = 'User: Faculty Twitter';
  $handler->display->display_options['fields']['field_faculty_twitter']['label'] = '';
  $handler->display->display_options['fields']['field_faculty_twitter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_faculty_twitter']['click_sort_column'] = 'url';
  /* Field: Global: Fieldset */
  $handler->display->display_options['fields']['fieldset_2']['id'] = 'fieldset_2';
  $handler->display->display_options['fields']['fieldset_2']['table'] = 'views';
  $handler->display->display_options['fields']['fieldset_2']['field'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset_2']['label'] = 'Assistant Information';
  $handler->display->display_options['fields']['fieldset_2']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['fieldset_2']['children'] = array(
  0 => 'nothing_2',
  1 => 'fieldset_5',
  );
  $handler->display->display_options['fields']['fieldset_2']['fieldset']['type'] = 'div';
  $handler->display->display_options['fields']['fieldset_2']['fieldset']['classes'] = 'assistant-information';
  /* Field: Assistant Information Title */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['ui_name'] = 'Assistant Information Title';
  $handler->display->display_options['fields']['nothing_2']['label'] = '';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = 'Assistant Info';
  $handler->display->display_options['fields']['nothing_2']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing_2']['element_class'] = 'assistant-info-title';
  $handler->display->display_options['fields']['nothing_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_2']['hide_empty'] = TRUE;
  /* Field: Global: Fieldset */
  $handler->display->display_options['fields']['fieldset_5']['id'] = 'fieldset_5';
  $handler->display->display_options['fields']['fieldset_5']['table'] = 'views';
  $handler->display->display_options['fields']['fieldset_5']['field'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset_5']['label'] = 'Assistant Details';
  $handler->display->display_options['fields']['fieldset_5']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['fieldset_5']['children'] = array(
  0 => 'field_faculty_assistant_name',
  1 => 'field_faculty_assistant_phone',
  2 => 'field_faculty_assistant_email',
  );
  $handler->display->display_options['fields']['fieldset_5']['fieldset']['type'] = 'div';
  $handler->display->display_options['fields']['fieldset_5']['fieldset']['classes'] = 'assistant__details field__content';
  /* Field: User: Assistant Name */
  $handler->display->display_options['fields']['field_faculty_assistant_name']['id'] = 'field_faculty_assistant_name';
  $handler->display->display_options['fields']['field_faculty_assistant_name']['table'] = 'field_data_field_faculty_assistant_name';
  $handler->display->display_options['fields']['field_faculty_assistant_name']['field'] = 'field_faculty_assistant_name';
  $handler->display->display_options['fields']['field_faculty_assistant_name']['label'] = '';
  $handler->display->display_options['fields']['field_faculty_assistant_name']['element_label_colon'] = FALSE;
  /* Field: User: Assistant Phone */
  $handler->display->display_options['fields']['field_faculty_assistant_phone']['id'] = 'field_faculty_assistant_phone';
  $handler->display->display_options['fields']['field_faculty_assistant_phone']['table'] = 'field_data_field_faculty_assistant_phone';
  $handler->display->display_options['fields']['field_faculty_assistant_phone']['field'] = 'field_faculty_assistant_phone';
  $handler->display->display_options['fields']['field_faculty_assistant_phone']['label'] = '';
  $handler->display->display_options['fields']['field_faculty_assistant_phone']['element_label_colon'] = FALSE;
  /* Field: User: Assistant Email */
  $handler->display->display_options['fields']['field_faculty_assistant_email']['id'] = 'field_faculty_assistant_email';
  $handler->display->display_options['fields']['field_faculty_assistant_email']['table'] = 'field_data_field_faculty_assistant_email';
  $handler->display->display_options['fields']['field_faculty_assistant_email']['field'] = 'field_faculty_assistant_email';
  $handler->display->display_options['fields']['field_faculty_assistant_email']['label'] = '';
  $handler->display->display_options['fields']['field_faculty_assistant_email']['element_label_colon'] = FALSE;
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
  229 => '229',
  );

  /* Display: Faculty Info Block */
  $handler = $view->new_display('block', 'Faculty Info Block', 'faculty_info_block');
  $handler->display->display_options['display_description'] = 'This block displays related information for Faculty profile page.';

  $export['faculty_profile_block'] = $view;

  return $export;
}
