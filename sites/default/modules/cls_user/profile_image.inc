<?php

/**
 * @file
 * Class to migrate faculty profile images from RTSB to Drupal.
 */

/**
 * Class RtsbFacultyProfileImageMigration.
 */
class RtsbFacultyProfileImageMigration extends RtsbMigration {

  /**
   * RtsbFacultyProfileImageMigration constructor.
   *
   * @param array $arguments
   *   Arguments defined in migration registration.
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description = t('Import of faculty profile images from RTSB.');

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'usr_img_1' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
          'description' => 'Image path',
          'alias' => 'i',
        ),
      ),
      MigrateDestinationFile::getKeySchema()
    );

    $fields = array(
      'usr_img_1' => t('Source field for the image path.'),
    );

    $query = db_select('migrate_profile_main', 'i')
      ->distinct()
      ->fields('i', array('usr_img_1'))
      ->isNotNull('usr_img_1');

    $count_query = db_select('migrate_profile_main', 'i')
      ->isNotNull('usr_img_1');
    $count_query->addExpression('COUNT(DISTINCT usr_img_1)', 'cnt');

    $this->source = new MigrateSourceSql($query, $fields, $count_query);
    $this->destination = new MigrateDestinationFile('image', 'MigrateFileUri');

    $this->addFieldMapping('source_dir')
      ->defaultValue("http://www.law.columbia.edu/images");
    $this->addFieldMapping('destination_dir')
      ->defaultValue(variable_get('file_default_scheme', 'public') . '://images');
    $this->addFieldMapping('value', 'usr_img_1');
    $this->addFieldMapping('file_replace')
      ->defaultValue(MigrateFile::FILE_EXISTS_REUSE);
    $this->addFieldMapping('preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('urlencode')
      ->defaultValue(0);
  }

}
