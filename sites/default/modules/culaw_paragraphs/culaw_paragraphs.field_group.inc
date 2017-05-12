<?php
/**
 * @file
 * culaw_paragraphs.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function culaw_paragraphs_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_flexible_content|node|landing_page|form';
  $field_group->group_name = 'group_flexible_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'landing_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Horizontal Tab Group',
    'weight' => '0',
    'children' => array(
      0 => 'group_default',
      1 => 'group_flexicontent',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'label' => 'Horizontal Tab Group',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
      ),
    ),
  );
  $field_groups['group_flexible_content|node|landing_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_flexicontent|node|landing_page|form';
  $field_group->group_name = 'group_flexicontent';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'landing_page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_flexible_content';
  $field_group->data = array(
    'label' => 'Flexible Content',
    'weight' => '8',
    'children' => array(
      0 => 'field_content_rows',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-flexicontent field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_flexicontent|node|landing_page|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Flexible Content');
  t('Horizontal Tab Group');

  return $field_groups;
}
