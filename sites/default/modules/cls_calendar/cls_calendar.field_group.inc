<?php
/**
 * @file
 * cls_calendar.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cls_calendar_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_access_control|node|calendar|form';
  $field_group->group_name = 'group_access_control';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'calendar';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Access Control',
    'weight' => '9',
    'children' => array(
      0 => 'field_group_owner',
      1 => 'field_limit_access',
      2 => 'field_world_edit',
      3 => 'field_world_link',
      4 => 'field_world_read',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-access-control field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_access_control|node|calendar|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_date_info|node|calendar|form';
  $field_group->group_name = 'group_event_date_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'calendar';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Date and Time',
    'weight' => '2',
    'children' => array(
      0 => 'field_event_date',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-event-date-info field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_event_date_info|node|calendar|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_info|node|calendar|form';
  $field_group->group_name = 'group_event_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'calendar';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basic Event Information',
    'weight' => '0',
    'children' => array(
      0 => 'field_attachments',
      1 => 'field_event_description',
      2 => 'field_event_promotion_text',
      3 => 'field_url',
      4 => 'field_event_image',
      5 => 'title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-event-info field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_event_info|node|calendar|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_location|node|calendar|form';
  $field_group->group_name = 'group_location';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'calendar';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Location',
    'weight' => '1',
    'children' => array(
      0 => 'field_location_name',
      1 => 'field_event_contact_info',
      2 => 'field_event_rsvp',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-location field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_location|node|calendar|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_main__content_left|node|calendar|default';
  $field_group->group_name = 'group_main__content_left';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'calendar';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_main__content';
  $field_group->data = array(
    'label' => 'Main content left',
    'weight' => '18',
    'children' => array(
      0 => 'calendar_event_date',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Main content left',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-main--content-left field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_main__content_left|node|calendar|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_main__content|node|calendar|default';
  $field_group->group_name = 'group_main__content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'calendar';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main Content',
    'weight' => '0',
    'children' => array(
      0 => 'field_attachments',
      1 => 'field_event_date',
      2 => 'field_event_description',
      3 => 'field_location_name',
      4 => 'field_url',
      5 => 'field_event_image',
      6 => 'calendar_direction',
      7 => 'group_main__content_left',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Main Content',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-main-content field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_main__content|node|calendar|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_publication_settings|node|calendar|form';
  $field_group->group_name = 'group_publication_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'calendar';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Publication Settings',
    'weight' => '6',
    'children' => array(
      0 => 'field_lawcal_categories',
      1 => 'field_microsite_calendar_tags',
      2 => 'field_promote_on_the_homepage',
      3 => 'field_publish_to_lawcal',
      4 => 'field_publish_to_microsite_cal',
      5 => 'field_publish_unit_planning_cal',
      6 => 'field_share_other_unit_calendar',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-publication-settings field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_publication_settings|node|calendar|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sub_content|node|calendar|default';
  $field_group->group_name = 'group_sub_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'calendar';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Main Sub Content',
    'weight' => '1',
    'children' => array(
      0 => 'field_event_contact_info',
      1 => 'field_event_rsvp',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Main Sub Content',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-sub-content field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_sub_content|node|calendar|default'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Access Control');
  t('Basic Event Information');
  t('Date and Time');
  t('Location');
  t('Main Content');
  t('Main Sub Content');
  t('Main content left');
  t('Publication Settings');

  return $field_groups;
}
