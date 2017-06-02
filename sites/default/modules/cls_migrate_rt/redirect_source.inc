<?php

/**
 * @file
 * Migrate source plugin to read .htaccess / apache.conf mod_rewrite rules.
 */

/**
 * @file
 * Class MigrateSourceConfRedirect.
 *
 * Read an apache .htaccess or apache.conf file with pairs of RewriteCond/
 * RewriteRule lines and parse into source -> destination rows which can
 * be migrated into Drupal redirects.
 */
class MigrateSourceConfRedirect extends MigrateSource {

  /**
   * Full path to the file to parse.
   *
   * @var array
   */
  protected $filePath;

  /**
   * File handle of opened file.
   *
   * @var null
   */
  protected $confHandle = NULL;

  /**
   * Current line we are working on.
   *
   * @var string
   */
  protected $currentLine = '';

  /**
   * Server match for destination rule.
   *
   * @var mixed|string
   */
  protected $serverMatch = '';

  /**
   * MigrateSourceConfRedirect constructor.
   *
   * @param array $path
   *   Path to apache configuration file.
   * @param string $server_match
   *   Optional server to match in the redirect path.
   * @param array $options
   *   Options array passed to all source migration plugins.
   */
  public function __construct($path, $server_match = '', array $options = array()) {
    parent::__construct($options);
    $this->filePath = $path;
    $this->serverMatch = $this->escapeMatchString($server_match);
  }

  /**
   * Implementation of MigrateSource::__toString().
   *
   * @return string
   *   String representation of migration.
   */
  public function __toString() {
    return $this->filePath . ' (matching "' . $this->serverMatch . '"")';
  }

  /**
   * Returns a list of fields available to be mapped from the source query.
   *
   * @return array
   *   Keys: machine names of the fields (to be passed to addFieldMapping)
   *   Values: Human-friendly descriptions of the fields.
   */
  public function fields() {
    return array(
      'condition_url' => t('The source URL condition to match'),
      'rules' => t('JSON encoded array of rules associated with the condition'),
    );
  }

  /**
   * Opens the file for reading and find the first RewriteCond line.
   */
  public function performRewind() {
    if (!is_null($this->confHandle)) {
      fclose($this->confHandle);
      $this->confHandle = NULL;
    }
    // Open the file for reading.
    $this->confHandle = fopen($this->filePath, 'r');
    // Skip any beginning configuration lines and position the cursor at the
    // first RewriteCond line.
    $this->findNextCondition();
  }

  /**
   * Returns the next row from the source.
   *
   * @return null|object
   *   The row or NULL if end of file has been reached.
   */
  public function getNextRow() {
    do {
      $row = $this->getNextRule();
    } while ($row !== FALSE && (is_array($row) && empty($row)));

    if ($row === FALSE) {
      fclose($this->confHandle);
      $this->confHandle = NULL;
      return NULL;
    }
    else {
      return (object) $row;
    }
  }

  /**
   * Estimated count of number of rows to be imported.
   *
   * @return int
   *   Number of condition/rule rows in the file.
   */
  public function computeCount() {
    // @todo: Figure out how to compute a count.
    $count = 0;
    $this->performRewind();
    while (($rule = $this->getNextRule()) !== FALSE) {
      if (!empty($rule)) {
        $count++;
      }
    }
    return $count;
  }

  /**
   * Return the next RewriteCond/RewriteRule pair from the file.
   *
   * @return array|bool
   *   Array with source/destination or FALSE if we have reached end of file.
   */
  public function getNextRule() {
    // We've reached the end of the file.
    if ($this->currentLine === FALSE) {
      return FALSE;
    }
    $condition_pattern = '/^RewriteCond\s+%{REQUEST_URI}\s+(?P<src>.*?)$/';
    $condition_matches = array();
    if (preg_match($condition_pattern, $this->currentLine, $condition_matches) && isset($condition_matches['src'])) {
      $rules = $this->findRulesForCondition();
      return array(
        'condition_url' => $condition_matches['src'],
        'rules' => json_encode($rules),
      );
    }
    else {
      // We didn't have a RewriteCond line we are interested in. Go to next
      // condition line.
      $this->findNextCondition();
      return array();
    }
  }

  /**
   * Escape REGEX reserved characters in a given string.
   *
   * @param string $dest
   *   String which contains characters that may need escaped.
   *
   * @return string
   *   String with REGEX reserved characters escaped with a backslash.
   */
  protected function escapeMatchString($dest) {
    $dest = str_replace('/', '\/', $dest);
    $dest = str_replace('.', '\.', $dest);
    return $dest;
  }

  /**
   * Read each line of the file until we reach a "RewriteCond" line.
   */
  protected function findNextCondition() {
    do {
      $this->currentLine = fgets($this->confHandle);
      // Only trim the current line if we actually have one.
      if ($this->currentLine) {
        $this->currentLine = trim($this->currentLine);
      }
    } while ($this->currentLine !== FALSE && strpos($this->currentLine, 'RewriteCond') === FALSE);
  }

  /**
   * Read lines from configuration file and save each RewriteRule line.
   */
  protected function findRulesForCondition() {
    $rules = array();
    $rule_pattern = '/^RewriteRule\s+(?P<src>.*?)\s+' . $this->serverMatch . '(?P<dest>.*?)\s+(?P<flags>.*)$/';
    $rule_matches = array();

    do {
      $this->currentLine = fgets($this->confHandle);
      if ($this->currentLine) {
        $this->currentLine = trim($this->currentLine);
        if (preg_match($rule_pattern, $this->currentLine, $rule_matches) && isset($rule_matches['src'])) {
          $rules[] = array(
            'src' => $rule_matches['src'],
            'dest' => $rule_matches['dest'],
            'flags' => $rule_matches['flags'],
          );
        }
      }
    } while ($this->currentLine !== FALSE && strpos($this->currentLine, 'RewriteRule') !== FALSE);

    return $rules;
  }

}
