<?php

/**
 * @file
 * Migration class for files in the RT_FILES table.
 */

/**
 * Class RtsbFileMigration.
 */
class RtsbFileMigration extends RtsbMigration {
  protected $baseDir;

  /**
   * {@inheritdoc}
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->baseDir = 'public://legacy';

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'file_id' => array(
          'type' => 'int',
          'not null' => TRUE,
          'unsigned' => TRUE,
          'description' => 'File ID',
          'alias' => 'f',
        ),
      ),
      MigrateDestinationFile::getKeySchema());

    $this->destination = new MigrateDestinationFile();

    $fields = array(
      'file_id' => t('The file ID.'),
      'file_name' => t('Name of the file'),
      'relative_path' => t('Relative path of file'),
      'fileroot_name' => t('Fileroot prepended to relative_path'),
      'file_size' => t('File size reported by RT'),
      'author_email' => t('Email address of user who uploaded the file'),
      'w_read' => t('World read flag'),
      'world_group_id' => t('Group to limit access to, 0 is no restrictions'),
      'author_uid' => t('Drupal uid corresponding to author_email, added in prepareRow()')
    );

    $query = db_select('rt_files', 'f');
    $query->join('rt_fileroots', 'fr', 'f.fileroot_id=fr.fileroot_id');
    $query->fields('f', array(
      'file_id',
      'file_name',
      'relative_path',
      'file_size',
      'author_email',
      'w_read',
      'world_group_id',
    ))
      ->fields('fr', array('fileroot_name'));

    $count_query = db_select('rt_files', 'f');
    $count_query->addExpression('COUNT(file_id)', 'cnt');

    $options = array('track_changes' => 1);

    $this->source = new MigrateSourceSQL($query, $fields, $count_query, $options);

    $this->addFieldMapping('uid', 'author_uid');
    $this->addFieldMapping('source_dir')
      ->defaultValue('http://www.law.columbia.edu/null');
    $this->addFieldMapping('value', 'file_id')
      ->callbacks(array($this, 'fixSourceFile'));
    $this->addFieldMapping('destination_dir', 'relative_path')
      ->callbacks(array($this, 'addBaseDir'));
    $this->addFieldMapping('destination_file', 'file_name');
    $this->addFieldMapping('file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);

    $this->addFieldMapping('urlencode')
      ->defaultValue(0);

  }

  /**
   * {@inheritdoc}
   */
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
    if ($row->w_read == 0) {
      $this->queueMessage(t('Incoming file @dir/@file has w_read flag set to 0, skipping', array(
        '@dir' => $row->relative_path,
        '@file' => $row->file_name,
      )));
      return FALSE;
    }
    if ($row->relative_path == '/') {
      $row->relative_path = '/' . $row->fileroot_name;
    }
    else {
      $row->relative_path = '/' . $row->fileroot_name . strtolower(str_replace(' ', '_', $row->relative_path));
    }

    $row->file_name = transliteration_clean_filename($row->file_name);
    $uid = $this->getDrupalUidFromEmail($row->author_email);
    if ($uid !== FALSE) {
      $row->author_uid = $uid;
    }
    else {
      $row->author_uid = $this->defaultAuthorUid;
    }
  }

  /**
   * Prepends the correct RT path to the file ID.
   *
   * @param int $file
   *   File ID.
   *
   * @return string
   *   Path to download file from RT.
   */
  protected function fixSourceFile($file) {
    return 'download?exclusive=filemgr.download&file_id=' . $file;
  }

  /**
   * Add common base destination directory to path.
   *
   * @param string $path
   *   Full Drupal URI path to file.
   */
  protected function addBaseDir($path) {
    return $this->baseDir . $path;
  }

}
