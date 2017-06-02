<?php
/**
 * @file
 * culaw_paragraphs.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function culaw_paragraphs_taxonomy_default_vocabularies() {
  return array(
    'backgrounds' => array(
      'name' => 'Backgrounds',
      'machine_name' => 'backgrounds',
      'description' => 'These are graphics for assigning as backgrounds to Flexible Content Layout Rows',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
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
    'media_card_categories' => array(
      'name' => 'Media Card Categories',
      'machine_name' => 'media_card_categories',
      'description' => 'Used in the Media Card Paragraph Bundle',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
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
