<?php
/**
 * @file
 * Migration to load JSON input into a database prior to migration.
 */

/**
 * Class RtsbJSONPreprocess. Load large JSON files into a MySQL table.
 */
class RtsbJSONPreprocess extends Migration {

  /**
   * RtsbJSONPreprocess constructor.
   *
   * @param array $arguments
   *   Array of arguments defined in the Migration registration.
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description = t('Preprocess JSON source files from Runtime JSON API');

    $fields = array(
      'id' => t('Unique ID for the JSON source item'),
      'item_id' => t('Individual item id from RTSB source table'),
      'table_id' => t('ID of RTSB table this item belongs to'),
      'objecttype' => t('Name of RTSB table this item belongs to'),
      'owner_module' => t('Runtime module name that manages this item'),
      'date_modified' => t('Date this item was last modified'),
      'page_path' => t('URL of item, only valid for page content'),
      'json_data' => t('Complete JSON encoding of the item'),
    );

    $this->source = new MigrateSourceJSON($arguments['source_file'], 'id',
      $fields, array(
        'cache_counts' => TRUE,
        'cache_key' => $this->machineName,
        'reader_class' => 'RtsbJSONReader',
      ));

    $this->destination = new MigrateDestinationTable('json_data');
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'id' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
          'description' => 'Unique content id',
        ),
      ),
      MigrateDestinationTable::getKeySchema('json_data'));

    $this->addFieldMapping('id', 'id');
    $this->addFieldMapping('item_id', 'item_id');
    $this->addFieldMapping('table_id', 'table_id');
    $this->addFieldMapping('object_type', 'objecttype');
    $this->addFieldMapping('owner_module', 'owner_module');
    $this->addFieldMapping('date_modified', 'date_modified');
    $this->addFieldMapping('page_path', 'page_path');
    $this->addFieldMapping('json_data', 'json_data');
  }

  /**
   * {@inheritdoc}
   */
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    $json = json_encode($row);
    $row->json_data = $json;
    $row->id = $row->_attributes->id;
    $row->item_id = $row->_attributes->item_id;
    $row->objecttype = $row->_attributes->objecttype;
    $row->table_id = $row->_attributes->table_id;
    $row->date_modified = strtotime($row->_attributes->date_modified);
    $row->owner_module = $row->_attributes->owner_module;
    $row->page_path = $row->owner_module == 'pages' ? $row->fields->page_path : NULL;
  }

}
