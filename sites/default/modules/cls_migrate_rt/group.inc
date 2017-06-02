<?php
/**
 * @file
 * Migration class for RTSB.RT_GROUPS.
 */

/**
 * Class RtsbGroupMigration.
 */
class RtsbGroupMigration extends RtsbMigration {
  /**
   * RtsbGroupMigration constructor.
   *
   * @param array $arguments
   *   Array of arguments defined in the migration registration.
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description = t('Migrate all groups from RTSB into group taxonomy.');

    $this->map = new MigrateSqlMap($this->machineName,
      array(
        'GROUP_ID' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => t('Source group ID'),
        ),
      ),
      MigrateDestinationTerm::getKeySchema());

    $fields = array(
      'GROUP_ID' => t('Incoming group ID'),
      'GROUP_NAME' => t('Name of the group'),
      'GROUP_DESC' => t('Group description'),
    );
    $csv_options = array('header_rows' => 1, 'track_changes' => TRUE);

    $this->source = new MigrateSourceCSV($this->sourceFilePath, array(), $csv_options, $fields);
    $this->destination = new MigrateDestinationTerm('cls_groups');

    $this->addFieldMapping('name', 'GROUP_NAME');
    $this->addFieldMapping('description', 'GROUP_DESC');
    $this->addFieldMapping('format')
      ->defaultValue('filtered_html');
    $this->addUnmigratedSources(array(
      'SITE_ID',
      'SELF_SELECT',
      'GROUP_THEME',
    ), t('DNM'));
    $this->addUnmigratedDestinations(array(
      'parent',
      'parent_name',
      'weight',
      'path',
    ));
  }

}
