<?php
/**
 * @file
 * Migration class to import calendar entities from Runtime into calendar nodes.
 */

/**
 * Class RtsbCalendarMigration.
 */
class RtsbCalendarMigration extends RtsbNodeBaseMigration {

  /**
   * {@inheritdoc}
   */
  public function __construct($arguments) {
    $this->description = t('Migrate calendar Runtime objects into calendar nodes.');

    $this->sourceFields += array(
      'event_title' => t('Title of the event'),
      'date_start' => t('Start date/time of the event'),
      'date_end' => t('End date/time of the event'),
      'date_created' => t('Date event was created'),
      'date_modified' => t('Date event was last modified'),
      'promotion_text' => t('Short promo text for the event'),
      'description' => t('Event description'),
      'location' => t('Event location'),
      'publish_to_lawcal' => t('Flag to determine if event is published in the calendar'),
      'lawcal_categories' => t('LawCal categories, extracted in prepareRow()'),
      'publish_microsite_calendar' => t('Flag to determine if event is published to a microsite calendar'),
      'microsite_tags' => t('List of microsite calendar tags'),
      'planning_unit' => t('ID of unit planning calendar event should be published to'),
      'other_offices_units' => t('List of other offices/units to share with, extracted in prepareRow()'),
      'w_read' => t('World read permission flag'),
      'w_edit' => t('World edit permission flag'),
      'w_link' => t('World link permission flag'),
      'group_owner' => t('Group ID of owner of event'),
      'group' => t('Group to limit access to, or none'),
      'attachments' => t('Attached files'),
      'link' => t('Link associated with event'),
      'promote_on_homepage' => t('Promote on homepage, from RT field usr_priority'),
    );

    parent::__construct($arguments);

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'id' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
          'description' => t('Source item id.'),
        ),
      ),
      MigrateDestinationNode::getKeySchema());

    $this->destination = new MigrateDestinationNode('calendar');

    $this->addFieldMapping('title', 'event_title');
    $this->addFieldMapping('field_event_promotion_text', 'promotion_text');
    $this->addFieldMapping('field_location_name', 'location');
    $this->addFieldMapping('field_event_date', 'date_start');
    $this->addFieldMapping('field_event_date:to', 'date_end');
    $this->addFieldMapping('field_microsite_calendar_tags', 'microsite_tags');
    $this->addFieldMapping('field_microsite_calendar_tags:create_term')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_microsite_calendar_tags:ignore_case')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_event_description', 'description');
    $this->addFieldMapping('field_event_description:format')
      ->defaultValue('full_html');
    $this->addFieldMapping('field_publish_to_lawcal', 'publish_to_lawcal');
    $this->addFieldMapping('field_lawcal_categories', 'lawcal_categories')
      ->sourceMigration('RtsbCalendarCategory');
    $this->addFieldMapping('field_lawcal_categories:source_type')
      ->defaultValue('tid');
    $this->addFieldMapping('field_publish_unit_planning_cal', 'planning_unit')
      ->sourceMigration('RtsbCalendarunit');
    $this->addFieldMapping('field_publish_unit_planning_cal:source_type')
      ->defaultValue('tid');
    $this->addFieldMapping('field_share_other_unit_calendar', 'other_offices_units')
      ->sourceMigration('RtsbCalendarUnit');
    $this->addFieldMapping('field_share_other_unit_calendar:source_type')
      ->defaultValue('tid');
    $this->addFieldMapping('field_publish_to_microsite_cal', 'publish_microsite_calendar');
    $this->addFieldMapping('field_world_read', 'w_read');
    $this->addFieldMapping('field_world_edit', 'w_edit');
    $this->addFieldMapping('field_world_link', 'w_link');
    $this->addFieldMapping('field_limit_access', 'group')
      ->sourceMigration('RtsbGroup');
    $this->addFieldMapping('field_limit_access:source_type')
      ->defaultValue('tid');
    $this->addFieldMapping('field_group_owner', 'group_owner')
      ->sourceMigration('RtsbGroup');
    $this->addFieldMapping('field_group_owner:source_type')
      ->defaultValue('tid');
    $this->addFieldMapping('field_url', 'link');
    $this->addFieldmapping('field_url:title')
      ->defaultValue('Find out more');
    $this->addFieldMapping('field_attachments', 'attachments')
    ->sourceMigration('RtsbFile');
    $this->addFieldMapping('field_attachments:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_attachments:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_promote_on_the_homepage', 'promote_on_homepage');

    $this->addUnmigratedSources(array('item_id', 'page_path'));

  }

  /**
   * {@inheritdoc}
   */
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
    $fields = $this->data->fields;
    $row->date_start = $fields->date_start;
    $row->date_end = $fields->date_end;
    $row->event_title = $fields->event_title;
    $row->description = $this->rewriteFileLinks($fields->description);
    $row->description = $this->rewriteImgTags($row->description);
    $row->promotion_text = $fields->x_promotiontext;
    $row->location = $fields->location;
    $row->publish_to_lawcal = $fields->usr_int_1;
    $cat_list = array_filter(explode(',', $fields->catid_list));
    $row->lawcal_categories = $cat_list;
    $row->other_offices_units = $cat_list;
    $row->planning_unit = $fields->cat5_id;
    $row->publish_microsite_calendar = $fields->usr_meta_4;
    $row->microsite_tags = preg_split('/[\s,\n]+/', $fields->x_micrositetags);
    $row->w_read = $fields->w_read;
    $row->w_edit = $fields->w_edit;
    $row->w_link = $fields->w_link;
    $row->group = $fields->world_group_id;
    $row->group_owner = $fields->owner_group_id;
    $row->attachments = array_filter(explode(',', $fields->attachments));
    $row->link = $fields->usr_url;
    $row->promote_on_homepage = $fields->usr_priority ? 1 : 0;

  }

}
