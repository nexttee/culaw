<?php

/**
 * @file
 * Common base class for migrations which use the json_data table.
 */

/**
 * Class RtsbJSONBaseMigration.
 */
class RtsbJSONBaseMigration extends RtsbMigration {

  /**
   * The JSON source data.
   *
   * @var stdClass
   */
  protected $data;

  /**
   * The source fields array.
   *
   * @var array
   */
  protected $sourceFields = array();

  /**
   * RtsbJSONBaseMigration constructor.
   *
   * @param array $arguments
   *   Array of migration arguments. The 'owner_module' and 'object_type'
   *   arguments are required and determine the tpe of content to import.
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->sourceFields += array(
      'id' => t('The unique ID for this record'),
      'object_type' => t('The type of object, corresponds to the RT controller'),
      'owner_module' => t('The RT module which owns this data'),
      'date_modified' => t('Timestamp when the item was last modified'),
      'date_created' => t('Timestamp when the item was created'),
      'uid' => t('The Drupal uid to associate with this content'),
    );

    $this->highwaterField = array(
      'name' => 'date_modified',
      'alias' => 'jd',
      'type' => 'int',
    );

    $this->source = new MigrateSourceSQL($this->query(), $this->sourceFields, NULL,
      array('cache_counts' => TRUE, 'cache_key' => $this->machineName));

    $this->addUnmigratedSources(array(
      'json_data',
      'owner_module',
      'object_type',
      'table_id',
    ));
  }

  /**
   * The base query for the migration.
   *
   * @return SelectQueryInterface
   *   Query of common fields for all JSON source-based migrations.
   */
  protected function query() {
    $query = db_select('json_data', 'jd')
      ->fields('jd', array(
        'id',
        'item_id',
        'table_id',
        'object_type',
        'owner_module',
        'date_modified',
        'page_path',
        'json_data',
      ));

    if (isset($this->arguments['object_type'])) {
      $query->condition('jd.object_type', $this->arguments['object_type']);
    }
    if (isset($this->arguments['owner_module'])) {
      $query->condition('jd.owner_module', $this->arguments['owner_module']);
    }
    return $query;
  }

  /**
   * Implements Migration::prepareRow($row).
   */
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    $this->data = json_decode($row->json_data);
    $row->date_created = strtotime($this->data->fields->date_created);
    $uid = $this->getDrupalUidFromEmail($this->data->fields->author_email);
    if ($uid !== FALSE) {
      $row->uid = $uid;
    }
    else {
      $row->uid = $this->defaultAuthorUid;
    }

    return TRUE;
  }

}
