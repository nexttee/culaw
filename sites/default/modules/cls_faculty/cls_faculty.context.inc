<?php
/**
 * @file
 * cls_faculty.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function cls_faculty_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'faculty_exposed_filter_blocks';
  $context->description = 'This context places faculty filter block on faculty listing page.';
  $context->tag = 'faculty';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'faculty' => 'faculty',
        'faculty/*' => 'faculty/*',
      ),
    ),
    'theme' => array(
      'values' => array(
        'culaw' => 'culaw',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'cls_core-faculty_name_filter_block' => array(
          'module' => 'cls_core',
          'delta' => 'faculty_name_filter_block',
          'region' => 'content',
          'weight' => '-10',
        ),
        'cls_core-faculty_role_filter_block' => array(
          'module' => 'cls_core',
          'delta' => 'faculty_role_filter_block',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('This context places faculty filter block on faculty listing page.');
  t('faculty');
  $export['faculty_exposed_filter_blocks'] = $context;

  return $export;
}
