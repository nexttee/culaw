<?php
/**
 * @file
 * Migration classes dealing with category migrations.
 */

/**
 * Class RtsbCategoryPreprocessMigration.
 *
 * Preprocess migration to import the RT_CATEGORIES table export into a
 * MySQL table that can be queried for the category parent_id.
 */
class RtsbCategoryPreprocessMigration extends RtsbMigration {

  /**
   * RtsbCategoryPreprocessMigration constructor.
   *
   * @param array $arguments
   *   Array of arguments defined in the registration.
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description = t('Preprocessor to import RT_CATEGORIES export csv file into a MySQL table.');

    $fields = array(
      'CATEGORY_ID' => t('Unique identifier for the row'),
      'PARENT_ID' => t('The parent ID of this category'),
      'CATEGORY_NAME' => t('The catgory name'),
      'CATEGORY_VALUE' => t('Text field used for arbitrary value data'),
      'DESCRIPTION' => t('The category description'),
      'CATEGORY_ATTRIBUTES' => t('Attributes for the category, mostly empty'),
      'PRIORITY' => t('Priority, default value is 5'),
    );

    $csv_options = array(
      'header_rows' => 1,
      'track_changes' => TRUE,
      'embedded_newlines' => TRUE,
      'enclosure' => '"',
    );
    $this->source = new MigrateSourceCSV($this->sourceFilePath, array(), $csv_options, $fields);

    $this->destination = new MigrateDestinationTable('rt_categories');
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'CATEGORY_ID' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
        ),
      ),
      MigrateDestinationTable::getKeySchema('rt_categories'));

    $this->addFieldMapping('category_id', 'CATEGORY_ID');
    $this->addFieldMapping('parent_id', 'PARENT_ID');
    $this->addFieldMapping('category_name', 'CATEGORY_NAME');
    $this->addFieldMapping('category_value', 'CATEGORY_VALUE');
    $this->addFieldMapping('description', 'DESCRIPTION');
    $this->addFieldMapping('category_attributes', 'CATEGORY_ATTRIBUTES');
    $this->addFieldMapping('priority', 'PRIORITY');
  }

}

/**
 * Class RtsbCategoryMigration.
 *
 * Generic taxonomy migration class for categories imported from Runtime.
 */
class RtsbCategoryMigration extends RtsbMigration {

  /**
   * Parent ID of categories to import.
   *
   * @var int
   */
  protected $parentId;

  /**
   * Machine name of vocabulary to import into.
   *
   * @var string
   */
  protected $vocabulary;

  /**
   * RtsbCategoryMigration constructor.
   *
   * @param array $arguments
   *   Array of arguments defined by the registration.
   */
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->parentId = $arguments['parent_id'];
    $this->vocabulary = $arguments['vocabulary'];

    $this->description = t('Migrate Runtime categories into a Drupal vocabulary.');
    $fields = array(
      'category_id' => t('Unique identifier for the row'),
      'parent_id' => t('The parent ID of this category'),
      'category_name' => t('The catgory name'),
      'category_value' => t('Text field used for arbitrary value data'),
      'description' => t('The category description'),
      'category_attributes' => t('Attributes for the category, mostly empty'),
      'priority' => t('Priority, default value is 5'),
    );

    $query = db_select('rt_categories', 'c')
      ->fields('c', array(
        'category_id',
        'parent_id',
        'category_name',
        'category_value',
        'description',
        'category_attributes',
        'priority',
      ))
      ->condition('parent_id', $this->parentId);

    $count_query = db_select('rt_categories', 'c')
      ->condition('parent_id', $this->parentId);
    $count_query->addExpression('COUNT(category_id)', 'cnt');

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'category_id' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
        ),
      ),
      MigrateDestinationTerm::getKeySchema());

    $this->source = new MigrateSourceSQL($query, $fields, $count_query);
    $this->destination = new MigrateDestinationTerm($this->vocabulary);

    $this->addFieldMapping('name', 'category_name');
    $this->addFieldMapping('description', 'description');
    $this->addUnmigratedSources(array('parent_id', 'category_attributes', 'priority'));
  }

}
