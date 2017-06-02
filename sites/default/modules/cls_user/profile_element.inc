<?php
/**
 * @file
 * Migration class for individual profile elements.
 */

/**
 * Class RtsbProfileElementMigration.
 */
class RtsbProfileElementMigration extends RtsbMigration {

  /**
   * {@inheritdoc}
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description = t('Migration of profile elements into paragraphs.');

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'contact_id' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'Associated contact ID',
          'alias' => 'pe',
        ),
        'element_index' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'Index of the individual element',
          'alias' => 'pe',
        ),
        'element_name_id' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'Name ID of the individual element',
          'alias' => 'pe',
        ),
      ),
      MigrateDestinationParagraphsItem::getKeySchema());

    $fields = array(
      'contact_id' => t('ID of contact record this item belongs to.'),
      'element_index' => t('Index of the item.'),
      'element_name_id' => t('ID of the element name from legacy system.'),
      'element_name' => t('Name of this element.'),
      'element_description' => t('Body text for this element'),
      'element_url' => t('Link associated with this element.'),
      'element_attach' => t('File attached to this element.'),
    );

    $query = db_select('migrate_profile_extras', 'pe');
    $query->join('migrate_profile_main', 'p', 'pe.contact_id=p.contact_id');
    $query->fields('pe', array(
      'contact_id',
      'element_index',
      'element_name_id',
      'element_name',
      'element_description',
      'element_url',
      'element_attach',
    ))
      ->fields('p', array('date_modified'))
      ->orderBy('date_modified')
      ->orderBy('contact_id')
      ->orderBy('element_index')
      ->orderBy('element_name_id');

    $count_query = db_select('migrate_profile_extras', 'pe');
    $count_query->addExpression('COUNT(*)');
    $this->highwaterField = array(
      'name' => 'date_modified',
      'type' => 'int',
      'alias' => 'p',
    );

    $this->source = new MigrateSourceSQL($query, $fields, $count_query);
    $this->destination = new MigrateDestinationParagraphsItem('faculty_profile_elements', array(
      'field_name' => 'field_faculty_profile_elements',
    ));

    $this->addFieldMapping('field_element_name', 'element_name');
    $this->addFieldMapping('field_element_description', 'element_description');
    $this->addFieldMapping('field_element_description:format')
      ->defaultValue('full_html');
    $this->addFieldMapping('field_element_link', 'element_url');
    $this->addFieldMapping('field_element_link:title')
      ->defaultValue('Link to more information');
    $this->addFieldmapping('field_element_file_attachment', 'element_attach')
      ->sourceMigration('RtsbFile');
    $this->addFieldMapping('field_element_file_attachment:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_element_file_attachment:preserve_files')
      ->defaultValue(TRUE);

    $this->addUnmigratedSources(array(
      'contact_id',
      'element_index',
      'element_name_id',
    ));

  }

  /**
   * {@inheritdoc}
   */
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    // Migrate attached files from the url and file_attach fields.
    $file_list = array();
    $attached_files = array();
    // Pull out the file_ids from the element_attach column.
    $attached_files = array_filter(explode(',', $row->element_attach));

    // Check for any urls that begin with "http://www.law.columbia.edu/null"
    // and look for a download file_id.
    if (strpos($row->element_url, 'http://www.law.columbia.edu/null') !== FALSE) {
      $file_id = $this->getFileIdFromDownloadUrl($row->element_link);
      if ($file_id) {
        $row->element_url = NULL;
        $attached_files[] = $file_id;
      }
    }

    $row->element_attach = count($attached_files) ? $attached_files : NULL;
    $row->element_description = $this->rewriteFileLinks($row->element_description);

  }

}
