<?php
/**
 * @file
 * cls_news_articles.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cls_news_articles_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_access_control|paragraphs_item|news_article_blocks|form';
  $field_group->group_name = 'group_access_control';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'news_article_blocks';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Access Control',
    'weight' => '2',
    'children' => array(
      0 => 'field_limit_access',
      1 => 'field_group_owner',
      2 => 'field_world_read',
      3 => 'field_world_edit',
      4 => 'field_world_link',
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
  $field_groups['group_access_control|paragraphs_item|news_article_blocks|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_additional_info|paragraphs_item|news_article_blocks|form';
  $field_group->group_name = 'group_additional_info';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'news_article_blocks';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Additional Information',
    'weight' => '1',
    'children' => array(
      0 => 'field_all_purpose_content',
      1 => 'field_news_image',
      2 => 'field_image_alignment',
      3 => 'field_image_size',
      4 => 'field_news_link',
      5 => 'field_news_file_attachment',
      6 => 'field_news_lifecycle',
      7 => 'field_news_expire_on',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-additional-info field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_additional_info|paragraphs_item|news_article_blocks|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content_information|paragraphs_item|news_article_blocks|form';
  $field_group->group_name = 'group_content_information';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'news_article_blocks';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content Information',
    'weight' => '0',
    'children' => array(
      0 => 'field_block_title',
      1 => 'field_block_body',
      2 => 'field_article_abstract',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-content-information field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_content_information|paragraphs_item|news_article_blocks|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_news_access_control|node|news_article|form';
  $field_group->group_name = 'group_news_access_control';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news_article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Access Control',
    'weight' => '2',
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
        'classes' => 'group-news-access-control field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_news_access_control|node|news_article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_news_content|node|news_article|form';
  $field_group->group_name = 'group_news_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news_article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '1',
    'children' => array(
      0 => 'field_news_content_section',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-news-content field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_news_content|node|news_article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_information|node|news_article|form';
  $field_group->group_name = 'group_page_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news_article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Page Information',
    'weight' => '0',
    'children' => array(
      0 => 'field_description',
      1 => 'field_long_title',
      2 => 'title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-page-information field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_page_information|node|news_article|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Access Control');
  t('Additional Information');
  t('Content');
  t('Content Information');
  t('Page Information');

  return $field_groups;
}
