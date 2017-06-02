<?php

/**
 * @file
 * news_content.inc
 */
class RtsbNewsContentMigration extends RtsbJSONBaseMigration {

  /**
   * RtsbNewsContentMigration constructor.
   *
   * @param array $arguments
   *   Array of arguments passed to the migration, defined in the registration.
   */
  public function __construct($arguments) {
    $this->description = t('Migrate calendar Runtime objects into calendar nodes.');

    $this->sourceFields += array(
      'title' => t('The title for this section'),
      'body' => t('The full content of this section'),
      'abstract' => t('Short description of the content'),
      'apc_category' => t('Category to associate with this content'),
      'image' => t('Image associated with this content'),
      'image_alignment' => t('Image placement on page'),
      'image_size' => t('Size specifier for image'),
      'link_url' => t('Array of link URLs attached to this content'),
      'link_title' => t('Array of link titles attached to this content'),
      'link_attributes' => t('Array of link attributes attached to this content'),
      'attachments' => t('Array of file ids to attach to this content'),
      'lifecycle' => t('Lifecycle of this content'),
      'expiration_date' => t('Date this content expires'),
      'w_read' => t('Source w_read field'),
      'w_edit' => t('Source w_edit field'),
      'w_link' => t('Source w_link field'),
      'limit_access' => t('Group ID if this is not publicly available'),
      'owner_group_id' => t('Group ID which owns this content'),
      'region' => t('Region of page where content should appear'),
      'sequence' => t('Order content should appear'),
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
      MigrateDestinationParagraphsItem::getKeySchema());

    $this->destination = new MigrateDestinationParagraphsItem('news_article_blocks',
      array('field_name' => 'field_news_content_section'));

    $this->addFieldMapping('field_block_title', 'title');
    $this->addFieldMapping('field_block_body', 'body');
    $this->addFieldMapping('field_block_body:format')
      ->defaultValue('full_html');
    $this->addFieldMapping('field_article_abstract', 'abstract');
    $this->addFieldMapping('field_all_purpose_content', 'apc_category')
      ->sourceMigration('RtsbCategoryApc');
    $this->addFieldMapping('field_all_purpose_content:source_type')
      ->defaultValue('tid');
    $this->addFieldMapping('field_news_image', 'image')
      ->sourceMigration('RtsbFile');
    $this->addFieldMapping('field_news_image:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_news_image:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_image_alignment', 'image_alignment');
    $this->addFieldMapping('field_image_size', 'image_size');
    $this->addFieldMapping('field_news_link', 'link_url');
    $this->addFieldMapping('field_news_link:title', 'link_title');
    $this->addFieldMapping('field_news_link:attributes', 'link_attributes');
    $this->addFieldMapping('field_news_lifecycle', 'lifecycle');
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
    $this->addFieldMapping('field_news_expire_on', 'expiration_date');
    $this->addFieldMapping('field_news_file_attachment', 'attachments')
      ->sourceMigration('RtsbFile');
    $this->addFieldMapping('field_news_file_attachment:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_news_file_attachment:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('archived')->defaultValue(0);

    $this->addUnmigratedSources(array(
      'region',
      'sequence',
      'item_id',
      'page_path',
    ), t('DNM'));
  }

  /**
   * {@inheritdoc}
   */
  protected function query() {
    $query = parent::query();
    // To get only news article data, join to json_data page content with a
    // path that begins with '/media_inquiries/news_events' via the rt_publish
    // table.
    $query->join('rt_publish', 'pub', 'jd.item_id=pub.item_id AND jd.table_id=pub.table_id');
    $query->join('json_data', 'jd2', 'pub.page_id=jd2.item_id AND jd2.table_id=1');
    $query->condition('jd2.page_path', '/media_inquiries/news_events%', 'LIKE');
    $query->fields('pub', array('region', 'sequence'))
      ->orderBy('jd.item_id', 'ASC')
      ->orderBy('region', 'ASC')
      ->orderBy('sequence', 'ASC');

    return $query;
  }

  /**
   * @inheritDoc
   */
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
    $fields = $this->data->fields;
    $row->title = $fields->title;
    $row->body = $this->rewriteImgTags($fields->body);
    $row->body = $this->rewriteFileLinks($row->body);
    $row->abstract = $fields->aBstract;
    $links = $this->populateLinkData($fields);
    $row->link_url = $links['urls'];
    $row->link_title = $links['titles'];
    $row->link_attributes = $links['attributes'];
    if (!empty($fields->usr_img_1)) {
      $row->image = $this->getFileIdFromFilePath($fields->usr_img_1);
    }
    $row->image_alignment = $fields->x_imgalignment;
    $row->image_size = $fields->x_imgsize;
    $row->attachments = array_filter(explode(',', $fields->attachments));
    $row->apc_category = $fields->cat1_id;
    $row->expiration_date = $this->convertOracleDateToTimestamp($fields->expiration_date);
    $row->w_read = $fields->w_read;
    $row->w_edit = $fields->w_edit;
    $row->w_link = $fields->w_link;
    $row->lifecycle = $fields->expiration_status;
    $row->owner_group_id = $fields->owner_group_id;
    $row->limit_access = $fields->world_group_id;

    return TRUE;
  }

  /**
   * Extract the links from the individual link/title fields.
   *
   * Links appear in the row data as three variables named x_link[n]_url,
   * x_link[n]_title, and x_link[n]_description where the [n] is an integer
   * ranging from 1 to 10.
   *
   * @param $fields
   *   JSON fields object for current row.
   *
   * @return array
   *   Array of link urls/titles/attributes.
   */
  protected function populateLinkData($fields) {
    $links = array(
      'urls' => array(),
      'titles' => array(),
      'attributes' => array(),
    );

    for ($i = 0; $i < 10; $i++) {
      $index = $i + 1;
      $current_url = "x_link{$index}_url";
      $current_title = "x_link{$index}_title";
      $current_description = "x_link{$index}_description";
      if (!empty($fields->$current_url)) {
        $links['urls'][$i] = $fields->$current_url;
        $links['titles'][$i] = $fields->$current_title;
        $links['attributes'][$i]['title'] = $fields->$current_description;
      }
    }

    return $links;
  }

}
