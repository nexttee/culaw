<?php
/**
 * @file
 * cls_content_common_features.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function cls_content_common_features_taxonomy_default_vocabularies() {
  return array(
    'cls_groups' => array(
      'name' => 'CLS Groups',
      'machine_name' => 'cls_groups',
      'description' => 'Groups imported from RT used to control content visibility.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'metatags' => array(),
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
