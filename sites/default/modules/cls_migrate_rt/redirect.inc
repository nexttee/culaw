<?php
/**
 * @file
 * Import redirects in the legacy apache.conf file into Drupal.
 */

/**
 * Class RtsbLegacyRedirectMigration.
 */
class RtsbLegacyRedirectMigration extends RtsbMigration {

  /**
   * RtsbLegacyRedirectMigration constructor.
   *
   * @inheritdoc
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description = 'Migrate redirects imported from apache.conf into Drupal redirects.';

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'condition_url' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
          'binary' => TRUE,
          'alias' => 'r',
        ),
      ),
      MigrateDestinationRedirect::getKeySchema());

    $query = db_select('rt_redirects', 'r')
      ->fields('r', array('condition_url', 'rules'));

    $fields = array(
      'source_url' => t('The URL to redirect from'),
      'destination_url' => t('The destination to redirect to'),
      'status_code' => t('The HTTP status code to use for the redirect'),
    );

    $this->source = new MigrateSourceSQL($query, $fields);
    $this->destination = new MigrateDestinationRedirect('redirect');

    $this->addFieldMapping('source', 'source_url');
    $this->addFieldMapping('redirect', 'destination_url');
    $this->addFieldMapping('status_code', 'status_code');
    $this->addFieldMapping('type')->defaultValue('redirect');
    $this->addFieldMapping('uid')->defaultValue(1);
  }

  /**
   * {@inheritdoc}
   */
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    $rules = json_decode($row->rules);
    // A single source must contain exactly 1 condition.
    $count = count($rules);
    if ($count != 1) {
      $this->queueMessage(t('Conditions must contain exactly 1 rewrite rule. Condition @condition contains @count redirects, skipping', array(
        '@condition' => $row->condition_url,
        '@count' => $count,
      )));
      return FALSE;
    }

    $rule = $rules[0];
    // We can't have redirects with regex patterns in the rewrite rule to match
    // part of a condition.
    if ($rule->src != '^(.*)$') {
      $this->queueMessage(t('Condition @condition contains a rewrite rule source (@rule) that does not match the entire condition', array(
        '@condition' => $row->condition_url,
        '@rule' => $rule->src,
      )));
      return FALSE;
    }
    $source = str_replace('^/', '', $row->condition_url);
    $source = str_replace('/?$', '', $source);
    $row->source_url = $source;
    $row->destination_url = $rule->dest;
    $row->status_code = strpos($rule->flags, 'R=permanent') !== FALSE ? 301 : 302;

    return TRUE;

  }

}
