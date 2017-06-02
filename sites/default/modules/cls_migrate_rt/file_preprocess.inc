<?php

/**
 * @file
 * Preprocess classes to import file information from RTSB to MySQL.
 */

/**
 * Class RtsbFilePreprocessMigration.
 */
class RtsbFilePreprocessMigration extends RtsbMigration {
  /**
   * RtsbFilePreprocessMigration constructor.
   *
   * @param array $arguments
   *   Array of arguments defined in the migration registration.
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description = t('Preprocessor to import RT_FILES export csv file into a MySQL table.');

    $fields = array(
      'FILE_ID' => t('Unique identifier for the row'),
      'FILE_NAME' => t('Original filename'),
      'FILE_SIZE' => t('Size of file in bytes'),
      'MIME_TYPE' => t('Mime type of file'),
      'FILE_EXT' => t('Extension of file'),
      'RELATIVE_PATH' => t('Relative path of file within file root'),
      'FILEROOT_ID' => t('ID of fileroot path'),
      'FILE_NAME_PHYSICAL' => t('Physical filename in RT'),
      'AUTHOR_EMAIL' => t('Email address of person who uploaded file'),
      'W_READ' => t('World read flag'),
      'W_EDIT' => t('World edit flag'),
      'W_LINK' => t('World link flag'),
      'WORLD_GROUP_ID' => t('Restricted access group, 0 for none'),
      'OWNER_GROUP_ID' => t('Group ID which owns the file'),
      'OWNER_CONTROLLER' => t('Controller, always filemgr'),
      'OWNER_MODULE' => t('Module, one of files or fileroom'),
    );

    $csv_options = array('header_rows' => 1, 'track_changes' => TRUE);
    $this->source = new MigrateSourceCSV($this->sourceFilePath, array(), $csv_options, $fields);

    $this->destination = new MigrateDestinationTable('rt_files');
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'FILE_ID' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
        ),
      ),
      MigrateDestinationTable::getKeySchema('rt_files'));

    $this->addFieldMapping('file_id', 'FILE_ID');
    $this->addFieldMapping('file_name', 'FILE_NAME');
    $this->addFieldMapping('file_size', 'FILE_SIZE');
    $this->addFieldMapping('mime_type', 'MIME_TYPE');
    $this->addFieldMapping('file_ext', 'FILE_EXT');
    $this->addFieldMapping('relative_path', 'RELATIVE_PATH');
    $this->addFieldMapping('fileroot_id', 'FILEROOT_ID');
    $this->addFieldMapping('file_name_physical', 'FILE_NAME_PHYSICAL');
    $this->addFieldMapping('author_email', 'AUTHOR_EMAIL');
    $this->addFieldMapping('w_read', 'W_READ');
    $this->addFieldMapping('w_edit', 'W_EDIT');
    $this->addFieldMapping('w_link', 'W_LINK');
    $this->addFieldMapping('world_group_id', 'WORLD_GROUP_ID');
    $this->addFieldMapping('owner_group_id', 'OWNER_GROUP_ID');
    $this->addFieldMapping('owner_controller', 'OWNER_CONTROLLER');
    $this->addFieldMapping('owner_module', 'OWNER_MODULE');
  }

}

/**
 * Class RtsbFileRootPreprocessMigration.
 */
class RtsbFileRootPreprocessMigration extends RtsbMigration {
  /**
   * RtsbFileRootPreprocessMigration constructor.
   *
   * @param array $arguments
   *   Array of arguments defined in the migration registration.
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description = t('Preprocessor to import RT_FILEROOTS export csv file into a MySQL table.');

    $fields = array(
      'FILEROOT_ID' => t('Unique identifier for the row'),
      'SITE_ID' => t('Site ID; always 115'),
      'FILEROOT_NAME' => t('Path name'),
      'FILEROOT_PATH' => t('Path name prepended with Coumbia_Law'),
      'DEFAULT_FILEROOT' => t('Possibly a flag, all values are 0'),
    );

    $csv_options = array('header_rows' => 1, 'track_changes' => TRUE);

    $this->source = new MigrateSourceCSV($this->sourceFilePath, array(), $csv_options, $fields);
    $this->destination = new MigrateDestinationTable('rt_fileroots');
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'FILEROOT_ID' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
        ),
      ),
      MigrateDestinationTable::getKeySchema('rt_files'));

    $this->addFieldMapping('fileroot_id', 'FILEROOT_ID');
    $this->addFieldMapping('site_id', 'SITE_ID');
    $this->addFieldMapping('fileroot_name', 'FILEROOT_NAME');
    $this->addFieldMapping('fileroot_path', 'FILEROOT_PATH');
    $this->addFieldMapping('default_fileroot', 'DEFAULT_FILEROOT');
  }

}
