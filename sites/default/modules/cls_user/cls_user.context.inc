<?php
/**
 * @file
 * cls_user.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function cls_user_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'faculty_profile_block';
  $context->description = 'This context places faculty profile block on left sidebar.';
  $context->tag = 'faculty';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'user/*' => 'user/*',
        'user/' => 'user/',
        'user' => 'user',
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
        'cls_faculty-faculty_link' => array(
          'module' => 'cls_faculty',
          'delta' => 'faculty_link',
          'region' => 'sub_featured',
          'weight' => '-10',
        ),
        'cls_core-address' => array(
          'module' => 'cls_core',
          'delta' => 'address',
          'region' => 'sub_content',
          'weight' => '-10',
        ),
        'views-12704a35fe7c5eb388644c4242caa24f' => array(
          'module' => 'views',
          'delta' => '12704a35fe7c5eb388644c4242caa24f',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('This context places faculty profile block on left sidebar.');
  t('faculty');
  $export['faculty_profile_block'] = $context;

  return $export;
}
