<?php

/**
 * @file
 * Migration class to migrate the news pages to Drupal nodes.
 */

/**
 * Class RtsbNewsPageMigration
 */
class RtsbNewsPageMigration extends RtsbNodeBaseMigration {

  /**
   * RtsbNewsPageMigration constructor.
   *
   * @param array $arguments
   *   Array of arguments defined in the migration registration.
   */
  public function __construct($arguments) {
    $this->description = t('Migrate news pages from Runtime to drupal nodes.');
    $this->addHardDependencies(array('RtsbNewsContent'));

    $this->sourceFields += array(
      'title' => t('The node title'),
      'long_title' => t('Long title, appears as a summary at top of page'),
      'content_blocks' => t('Reference to paragraph items containing the content'),
      'description' => t('Content description, used in meta description tag and on news view'),
      'w_read' => t('Source w_read field'),
      'w_edit' => t('Source w_edit field'),
      'w_link' => t('Source w_link field'),
      'limit_access' => t('Access level, public or limited to a specific group'),
      'owner_group_id' => t('Group ID that owns this content'),
      'path' => t('Path alias for this content'),
    );

    parent::__construct($arguments);

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'id' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
          'description' => t('Source item id.'),
          'alias' => 'jd',
        ),
      ),
      MigrateDestinationNode::getKeySchema());

    $this->destination = new MigrateDestinationNode('news_article');
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('field_long_title', 'long_title');
    $this->addFieldMapping('field_description', 'description');
    $this->addFieldMapping('field_news_content_section', 'content_blocks')
      ->sourceMigration('RtsbNewsContent');
    $this->addFieldMapping('path', 'page_path');
    $this->addFieldMapping('field_world_read', 'w_read');
    $this->addFieldMapping('field_world_edit', 'w_edit');
    $this->addFieldMapping('field_world_link', 'w_link');
    $this->addFieldMapping('field_limit_access', 'limit_access')
      ->sourceMigration('RtsbGroup');
    $this->addFieldMapping('field_limit_access:source_type')
      ->defaultValue('tid');
    $this->addFieldMapping('field_group_owner', 'owner_group_id')
      ->sourceMigration('RtsbGroup');
    $this->addFieldMapping('field_group_owner:source_type')
      ->defaultValue('tid');
  }

  /**
   * {@inheritDoc}
   */
  protected function query() {
    $query = parent::query();

    // We only want pages with news content paths.
    $query->condition('jd.page_path', '/media_inquiries/news_events%', 'LIKE');

    return $query;
  }

  /**
   * {@inheritDoc}
   */
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
    $contend_ids = db_select('rt_publish', 'pub')
      ->fields('pub', ['item_id'])
      ->condition('page_id', $row->item_id, '=')
      ->orderBy('region', 'ASC')
      ->orderBy('sequence', 'ASC')
      ->execute()->fetchCol();

    if (empty($contend_ids)) {
      $this->queueMessage(t('No content pieces found for page with path !path. Skipping', [
        '!path' => $row->page_path,
      ]));
      return FALSE;
    }

    $fields = $this->data->fields;

    $row->title = $fields->page_title;
    $row->long_title = $fields->page_longtitle;
    $row->description = $fields->description;
    $row->content_blocks = array();
    foreach ($contend_ids as $id) {
      $row->content_blocks[] = 'rt_content_' . $id;
    }
    $row->w_read = $fields->w_read;
    $row->w_edit = $fields->w_edit;
    $row->w_link = $fields->w_link;
    $row->owner_group_id = $fields->owner_group_id;
    $row->limit_access = $fields->world_group_id;
    $row->page_path = ltrim($row->page_path, '/');

  }

}
