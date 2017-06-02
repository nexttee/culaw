<?php
/**
 * @file
 * cls_news_articles.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function cls_news_articles_taxonomy_default_vocabularies() {
  return array(
    'apc_content_categories' => array(
      'name' => 'Content Categories',
      'machine_name' => 'apc_content_categories',
      'description' => 'Categories that are children of the All-Purpose Content category in Runtime',
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
