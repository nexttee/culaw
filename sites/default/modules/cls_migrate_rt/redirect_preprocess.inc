<?php

/**
 * @file
 * Migration class to import rewrite rules from apache configuration files.
 */

/**
 * Class RtsbRedirectPreprocessMigration.
 */
class RtsbRedirectPreprocessMigration extends RtsbMigration {

  /**
   * RtsbRedirectPreprocessMigration constructor.
   *
   * @param array $arguments
   *   Array of arguments defined in the migration registration.
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description = t('Parse apache configuration file and store results in a holding table.');
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'condition_url' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
          'binary' => TRUE,
        ),
      ),
      MigrateDestinationTable::getKeySchema('rt_redirects'));

    $source_options = array(
      'cache_counts' => TRUE,
      'cache_key' => $this->machineName,
      'track_changes' => TRUE,
    );

    $this->source = new MigrateSourceConfRedirect($this->sourceFilePath, 'http://web.law.columbia.edu/', $source_options);

    $this->destination = new MigrateDestinationTable('rt_redirects');
    $this->addFieldMapping('condition_url', 'condition_url');
    $this->addFieldMapping('rules', 'rules');
  }

}
