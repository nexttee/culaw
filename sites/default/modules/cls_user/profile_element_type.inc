<?php
/**
 * @file
 * Migration class for profile extra element taxonomy terms.
 */

/**
 * Class RtsbProfileElementTaxonomyTermsMigration.
 *
 * Migrate existing profile element names as taxonomy terms.
 */
class RtsbProfileElementTaxonomyTermsMigration extends RtsbMigration {

  /**
   * {@inheritdoc}
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description = t('Import of extra element names into the Faculty Profile Element Types vocabulary.');

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'element_name' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
        ),
      ),
    MigrateDestinationTerm::getKeySchema());

    $fields = array(
      'element_name' => t('Name of element.'),
    );

    $query = db_select('migrate_profile_extras', 'e')
      ->distinct()
      ->fields('e', array('element_name'));

    $count_query = db_select('migrate_profile_extras', 'e');
    $count_query->addExpression('COUNT(DISTINCT element_name)');

    $this->source = new MigrateSourceSQL($query, $fields, $count_query);
    $this->destination = new MigrateDestinationTerm('faculty_profile_element_types');

    $this->addFieldMapping('name', 'element_name');
    $this->addFieldMapping('parent')
      ->defaultValue(0);
    $this->addUnmigratedDestinations(array('description', 'weight'));
  }

}
