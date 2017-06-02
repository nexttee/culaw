<?php

/**
 * @file
 * This class represents an Oracle database connection.
 */

/**
 * Database Connection Class
 */
class CLSOracleIntegrationConnection {

  /* Declare class variables. */
  /**
   * @var mixed
   */
  protected $conn = FALSE;
  /**
   * @var mixed
   */
  protected $stmt = FALSE;
  /**
   * @var int
   */
  protected $prefetch = 100;
  /**
   * @var mixed
   */
  protected $sql = FALSE;
  /**
   * @var array
   */
  protected $bind_variables = array();
  /**
   * @var mixed
   */
  protected $db_schema_name = FALSE;

  /**
   * Constructor
   *
   * @param $connection_string
   * @param $username
   * @param $password
   * @param array $options
   */
  function __construct($connection_string, $username, $password, $options = array()) {

    $character_set = 'WE8ISO8859P1';
    if (isset($options['character_set'])) {
      $character_set = $options['character_set'];
    }

    // Construct a connection
    if (isset($options['persistent']) && $options['persistent'] === FALSE) {
      $this->conn = oci_connect($username, $password, $connection_string, $character_set);
    }
    else {
	    $this->conn = oci_pconnect($username, $password, $connection_string, $character_set);
    }

    // Check for a connection, and process the work.
    if (!$this->conn) {
      // Assign Oracle error message.
      $msg = oci_error();
      throw new Exception('Cannot connect to database: ' . $msg['message'] . ' (' . $msg['code'] . ')');
    }

    $this->db_schema_name = $username;
	  if (isset($options['schema'])) {
	    $this->setSchema($options['schema']);
	  }

    // Set Oracle Call Interface parameters
    if (isset($options['trace_client_info'])) {
	  oci_set_client_info($this->conn, $options['trace_client_info']);
    }
    if (isset($options['trace_module'])) {
      oci_set_module_name($this->conn, $options['trace_module']);
    }
    if (isset($options['trace_client_identifier'])) {
      oci_set_client_identifier($this->conn, $options['trace_client_identifier']);
    }

  }

  /**
   * Sets the database schema
   *
   * @param $schema_name
   * @param bool $return_object
   * @return $this|bool
   * @throws Exception
   */
  public function setSchema($schema_name, $return_object = TRUE) {
    if (!empty($schema_name)) {
      if (!preg_match('/([^A-Za-z0-9\_]+)/', $schema_name) && strlen($schema_name) <= 30) {
        $statement = oci_parse($this->conn, 'ALTER SESSION SET CURRENT_SCHEMA=' . strtoupper($schema_name));
        if ($statement && oci_execute($statement)) {
          $this->db_schema_name = $schema_name;
        }
        else {
          throw new Exception('Could not change schema to: ' . $schema_name);
        }
      }
      else {
        throw new Exception('Schema name is invalid: ' . $schema_name);
      }
    }
    else {
      throw new Exception('Provided schema name was blank.');
    }

    if (!$return_object) {
      return TRUE;
    }
    return $this;
  }

  /**
   * Sets a query statement
   *
   * @param $sql
   * @param array $bind_variables
   * @return $this
   */
  public function setQuery($sql, $bind_variables = array()) {
    $this->sql = $sql;
    $this->bind_variables = $bind_variables;
    return $this;
  }

  /**
   * @param string $action
   * @return $this
   */
  public function execute($action = '') {

    if ($this->sql == FALSE) {
      throw new Exception('No SQL statement has been set.');
    }

    // Parse statement.
    $this->stmt = oci_parse($this->conn, $this->sql);

    // Check for a prefetch value greater than zero.
    if ($this->prefetch >= 0) {
      oci_set_prefetch($this->stmt, $this->prefetch);
    }

    // Read the list of bind variables and bind them.
    foreach ($this->bind_variables as $bv_name => $bv_value) {
      oci_bind_by_name($this->stmt, $bv_name, $bv_value);
    }

    // Set the action name for Oracle tracing and execute statement.
    if ($action != '') {
      oci_set_action($this->conn, $action);
    }

    // Set to auto commit.
    oci_execute($this->stmt);

    return $this;
  }

  /**
   * @param string $row_type
   * @return object|array
   * @throws Exception
   */
  public function fetch($row_type = 'OBJECT') {
    if ($row_type == 'ASSOC') {
	  $row = oci_fetch_assoc($this->stmt);
    }
    else if ($row_type == 'OBJECT') {
	  $row = oci_fetch_object($this->stmt);
    }
    else {
      throw new Exception('Invalid result row return type: ' . $row_type);
    }
    return $row;
  }

  /* Declare function that fetches all. */
  /**
   * @return array
   */
  public function fetchAll() {
    oci_fetch_all($this->stmt, $res, 0, -1, OCI_FETCHSTATEMENT_BY_ROW);
    // Free statement resources.
    $this->stmt = null;
    return($res);
  }

  /**
   *
   */
  function __destruct() {
    if ($this->stmt)
      oci_free_statement($this->stmt);
    if ($this->conn)
      oci_close($this->conn);
  }

}
