<?php
/**
 * @file
 * Base class for all node migrations.
 */

/**
 * Class RtsbNodeBaseMigration.
 */
class RtsbNodeBaseMigration extends RtsbJSONBaseMigration {
  /**
   * Default publication status of imported content.
   *
   * @var int
   */
  protected $defaultStatus;

  /**
   * RtsbNodeBaseMigration constructor.
   *
   * @param array $arguments
   *   Array of arguments defined by the migration registration.
   */
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->defaultStatus = isset($arguments['default_status']) ? $arguments['default_status'] : 1;

    $this->addFieldMapping('status')->defaultValue($this->defaultStatus);
    $this->addFieldMapping('promote')->defaultValue(0);
    $this->addFieldMapping('sticky')->defaultValue(0);
    $this->addFieldMapping('revision')->defaultValue(0);
    $this->addFieldMapping('log')->defaultValue('Imported by migrate.');
    $this->addFieldMapping('language')->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('pathauto')->defaultValue(0);
    $this->addFieldMapping('created', 'date_created');
    $this->addFieldMapping('changed', 'date_modified');
    $this->addFieldMapping('uid', 'uid');
  }

}
