<?php
/**
 * @file
 * culaw_paragraphs.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function culaw_paragraphs_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Student Voices',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '05f4bf02-275f-4dda-82fe-871affa1af34',
    'vocabulary_machine_name' => 'media_card_categories',
  );
  $terms[] = array(
    'name' => 'Blue',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '192a7c94-ec1e-4640-ac5d-3c0db7b89c0a',
    'vocabulary_machine_name' => 'backgrounds',
    'field_media_file' => array(),
  );
  $terms[] = array(
    'name' => 'Beastie Boy',
    'description' => 'Sample Background inspired by the Beastie Boys',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '346341a5-0b25-4ec7-b7a4-c457c1926aa9',
    'vocabulary_machine_name' => 'backgrounds',
    'field_media_file' => array(),
  );
  $terms[] = array(
    'name' => 'Orange',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '36945ef4-3fac-4473-8f3a-daf4bc054c01',
    'vocabulary_machine_name' => 'backgrounds',
    'field_media_file' => array(),
  );
  $terms[] = array(
    'name' => 'Retro Light Background',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '42f2dcd5-b262-44b7-9d6f-b1dd47f6447c',
    'vocabulary_machine_name' => 'backgrounds',
    'field_media_file' => array(),
  );
  $terms[] = array(
    'name' => 'Blue/Gray with Diamonds',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '5293a236-9ca0-469e-b68d-cd523d6a9db8',
    'vocabulary_machine_name' => 'backgrounds',
    'field_media_file' => array(),
  );
  $terms[] = array(
    'name' => 'Gray with Diamonds',
    'description' => '',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '679a14c2-ddf9-4d1f-a5a1-b0176bb08851',
    'vocabulary_machine_name' => 'backgrounds',
    'field_media_file' => array(),
  );
  $terms[] = array(
    'name' => 'Yellow',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '99a566e1-6ba1-406e-861e-84e1dc8bff6d',
    'vocabulary_machine_name' => 'backgrounds',
    'field_media_file' => array(),
  );
  $terms[] = array(
    'name' => 'LinkedIn',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'e4f55d62-0641-4cea-8c2b-23abb894f100',
    'vocabulary_machine_name' => 'media_card_categories',
  );
  $terms[] = array(
    'name' => 'Scholarship',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'f329d710-523e-4e9a-96d2-6371061beaa7',
    'vocabulary_machine_name' => 'media_card_categories',
  );
  $terms[] = array(
    'name' => 'Arch Window Light',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'f92b0bf0-e735-40c7-93d2-53effebc02c0',
    'vocabulary_machine_name' => 'backgrounds',
    'field_media_file' => array(),
  );
  return $terms;
}
