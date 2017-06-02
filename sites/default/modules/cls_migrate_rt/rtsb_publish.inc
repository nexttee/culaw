<?php
/**
 * @file
 * Migration class to import records from RTSB.RT_PUBLISH table into MySQL.
 */

/**
 * Class RtsbPublishMigration.
 */
class RtsbPublishMigration extends RtsbMigration {
  /**
   * RtsbPublishMigration constructor.
   *
   * @param array $arguments
   *   Array of arguments defined in the migration registration.
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description = 'Migration to import RT_PUBLISH records into a MySQL table';
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'PUBLISH_ID' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
        ),
      ),
      MigrateDestinationTable::getKeySchema('rt_publish'));

    $fields = array(
      'PUBLISH_ID' => t('Unique identifier for the row'),
      'SITE_ID' => t('Site ID, always 115'),
      'PAGE_ID' => t('The ID of the page'),
      'REGION' => t('The name of the region on the Runtime page content is to be displayed in'),
      'TABLE_ID' => t('The table ID the content is from'),
      'ITEM_ID' => t('The individual content item ID'),
      'SEQUENCE' => t('Order content should appear on page'),
      'DATE_START' => t('Date field, always empty'),
      'DATE_END' => t('Date field, always empty'),
      'DATE_CREATED' => t('Date content was created/published'),
      'CREATOR_ID' => t('User ID in Runtime of creator'),
    );

    $csv_options = array('header_rows' => 1, 'track_changes' => TRUE);

    $this->source = new MigrateSourceCSV($this->sourceFilePath, array(), $csv_options, $fields);
    $this->destination = new MigrateDestinationTable('rt_publish');

    $this->addFieldMapping('publish_id', 'PUBLISH_ID');
    $this->addFieldMapping('site_id', 'SITE_ID');
    $this->addFieldMapping('page_id', 'PAGE_ID');
    $this->addFieldMapping('region', 'REGION');
    $this->addFieldMapping('table_id', 'TABLE_ID');
    $this->addFieldMapping('item_id', 'ITEM_ID');
    $this->addFieldMapping('sequence', 'SEQUENCE');
    $this->addFieldMapping('date_created', 'DATE_CREATED')
      ->callbacks(array($this, 'convertOracleDateToTimestamp'));
    $this->addFieldMapping('creator_id', 'CREATOR_ID');

    $this->addUnmigratedSources(array('DATE_START', 'DATE_END'), t('DNM'));
  }

}
