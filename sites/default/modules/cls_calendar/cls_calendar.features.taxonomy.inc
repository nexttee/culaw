<?php
/**
 * @file
 * cls_calendar.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function cls_calendar_taxonomy_default_vocabularies() {
  return array(
    'calendar_categories' => array(
      'name' => 'Calendar Categories',
      'machine_name' => 'calendar_categories',
      'description' => 'LawNet Calendar categories',
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
    'calendar_microsite_tags' => array(
      'name' => 'Calendar Microsite Tags',
      'machine_name' => 'calendar_microsite_tags',
      'description' => 'Microsite tags for LawNet calendar events',
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
    'calendar_units' => array(
      'name' => 'Calendar Units',
      'machine_name' => 'calendar_units',
      'description' => 'Individual unit planning calendars',
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
