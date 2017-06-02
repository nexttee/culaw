<?php
/**
 * @file
 * Base class for all RTSB migrations.
 */

/**
 * Base class for all RTSB migrations.
 */
abstract class RtsbMigration extends Migration {

  /**
   * Client ID used for OAuth2 authentication to API.
   *
   * @var string
   */
  protected $restApiClientId;

  /**
   * Client secret used for OAuth2 authentication to API.
   *
   * @var string
   */
  protected $restApiClientSecret;

  /**
   * Rest API base url.
   *
   * @var string
   */
  protected $restApiBaseUrl;

  /**
   * Default Drupal uid to associate with migrated content.
   *
   * @var int
   */
  protected $defaultAuthorUid;

  /**
   * Full path to source file for file-based migrations.
   *
   * @var string
   */
  protected $sourceFilePath;

  /**
   * Constructor for RtsbMigration class.
   *
   * @inheritdoc
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments);
    $this->restApiClientId = variable_get('cls_client_id');
    $this->restApiClientSecret = variable_get('cls_client_secret');
    $this->restApiBaseUrl = cls_rest_api_get_endpoint_base_url();

    $this->sourceFilePath = isset($arguments['source_file']) ? $arguments['source_file'] : '';

    // Get Meg young's Drupal uid to use as the default for content with an
    // author email that does not map to a valid LawNet user.
    $this->defaultAuthorUid = db_select('users', 'u')
      ->fields('u', array('uid'))
      ->condition('mail', 'myoung4@law.columbia.edu', '=')
      ->execute()
      ->fetchField();
  }

  /**
   * Clean up US state values imported from RTSB profiles.
   *
   * @param string $value
   *   State text to clean up.
   *
   * @return string
   *   The cleaned up state value.
   */
  public function processWorkState($value) {
    $value = str_replace(".", "", $value);
    if ($value == 'New York') {
      $value = 'NY';
    }
    if (strpos($value, " ") !== FALSE) {
      $value = substr($value, 0, strpos($value, " "));
    }

    return $value;
  }

  /**
   * Determine if a URL is an API download URL and extract the file_id.
   *
   * @param string $url
   *   URL to parse.
   *
   * @return int
   *   File ID if match, otherwise 0
   */
  public function getFileIdFromDownloadUrl($url) {
    $pattern = '|.*exclusive=filemgr\.download.*&(?:amp;)?(?:file_)?id=(\d+)|';
    preg_match($pattern, $url, $matches);
    $file_id = count($matches) > 1 ? $matches[1] : 0;
    return $file_id;
  }

  /**
   * Replace legacy files referenced in <a> tags with a migrated file.
   *
   * @param array $matches
   *   Array from preg_replace_callback.
   *
   * @return string
   *   String with local path to file.
   */
  public function replaceLinkedFiles(array $matches) {
    // Default to the original <a> tag.
    $result = $matches[0];
    $pattern = '/href=[\'"](.+?)[\'"]/';

    if (preg_match($pattern, $result, $href_matches)) {
      $original_url = $href_matches[1];
      $file_id = $this->getFileIdFromDownloadUrl($original_url);
      if ($file_id) {
        $url = $this->getFileUrlFromFileId($file_id);
        $replacement = 'href="' . $url . '"';
        $result = preg_replace($pattern, $replacement, $result);

      }
    }

    return $result;
  }

  /**
   * Rewrite file links which point to the RT filemanager download link.
   *
   * @param string $body
   *   Body text to search for file links.
   *
   * @return string
   *   Body string with updated file links.
   */
  public function rewriteFileLinks($body) {
    migrate_instrument_start('rewriteFileLinks');
    $body = preg_replace_callback('|<a\b([^>]*)>.*?</a>|s',
      array($this, 'replaceLinkedFiles'), $body);
    migrate_instrument_stop('rewriteFileLinks');
    return $body;
  }

  /**
   * Rewrite image source tags which point to old RT image paths.
   *
   * @param string $body
   *   The text to search for <img> tags in.
   *
   * @return string
   *   The body string with <img> tags replaced.
   */
  public function rewriteImgTags($body) {
    migrate_instrument_start('rewriteImgTags');
    $body = preg_replace_callback('|<img [^>]*>|i', array($this, 'replaceImgSrc'), $body);
    migrate_instrument_stop('rewriteImgTags');
    return $body;
  }

  /**
   * Callback function to process <img> tag sources.
   *
   * @param array $matches
   *   Array of matches to process.
   *
   * @return string
   *   Tag with updated image src attribute or original string if nothing to do.
   */
  public function replaceImgSrc($matches) {
    $src_matches = array();
    $result = $matches[0];
    $pattern = '|src=[\'"]([^\'"]+)[\'"]|i';

    if (preg_match($pattern, $result, $src_matches)) {
      if (strpos($src_matches[1], '://') === FALSE || (strpos($src_matches[1], 'www.law.columbia.edu') !== FALSE && strpos($src_matches[1], 'exclusive=filemgr.download') === FALSE)) {
        // Ensure this is a file URL and replace with the Drupal path if so.
        if (strpos($src_matches[1], 'data:image') === FALSE) {
          $url_path = parse_url($src_matches[1], PHP_URL_PATH);
          $fid = $this->getFileIdFromFilePath($url_path);
          if ($fid) {
            $file = file_load($fid);
            if ($file) {
              $file_url = file_create_url($file->uri);
              if ($file_url) {
                $url = parse_url($file_url, PHP_URL_PATH);
                $src = 'src="' . $url . '"';
                $result = str_replace($src_matches[0], $src, $result);
              }
            }
          }
        }
      }
      else {
        $file_id = $this->getFileIdFromDownloadUrl($src_matches[1]);
        if ($file_id !== FALSE) {
          $url = $this->getFileUrlFromFileId($file_id);
          if ($url) {
            $src = 'src="' . $url . '"';
            $result = str_replace($src_matches[0], $src, $result);
          }
        }
      }
    }
    return $result;
  }

  /**
   * Query the REST API for directory information for a given employee.
   *
   * @param string $lawnet_name
   *   LawNet user id to look up.
   *
   * @return array
   *   Array of user information returned from the API call.
   */
  public function getEmployeeInfoFromApi($lawnet_name) {
    $data = array();
    migrate_instrument_start('getEmployeeInfoFromApi');
    $client = cls_rest_api_make_api_request($this->restApiClientId, $this->restApiClientSecret);
    $url = $this->restApiBaseUrl . '/public/directory/employees/username/' . $lawnet_name;
    $response = $client->fetch($url, array(), 'GET', array('Content-Type' => 'application/json'));
    if (intval($response['code']) == 200) {
      $data = $response['result'];
    }
    migrate_instrument_stop('getEmployeeInfoFromApi');

    return $data;
  }

  /**
   * Search for an existing Drupal user from LawNet username or email address.
   *
   * @param string $lawnet_username
   *   LawNet username associated with user to migrate.
   * @param string $email
   *   Email address associated with user to migrate.
   *
   * @return int|FALSE
   *   Return uid of existing user if found; FALSE if not.
   */
  protected function getExistingUserId($lawnet_username, $email) {
    // Check for existing user in the CAS user table.
    $uid = db_select('cas_user', 'u')
      ->fields('u', array('uid'))
      ->condition('cas_name', $lawnet_username, '=')
      ->execute()
      ->fetchField();
    if ($uid) {
      return $uid;
    }
    else {
      // See if the email address or username maps to an existing Drupal user.
      $db_or = db_or();
      $db_or->condition('u.mail', $email, '=');
      $db_or->condition('u.name', $lawnet_username, '=');
      $uid = db_select('users', 'u')
        ->fields('u', array('uid'))
        ->condition($db_or)
        ->execute()
        ->fetchField();
      if ($uid) {
        return $uid;
      }
    }

    // Couldn't find a user with the LawNet user mapped to the CAS name,
    // the drupal username, or a user with the given email address,
    // assume no user exists.
    return FALSE;
  }

  /**
   * Look up fid of a given image path in the drupal file_managed table.
   *
   * @param string $file_path
   *   The file path to search for.
   *
   * @return mixed
   *   Return the file id associated with the file path, or FALSE if not found.
   */
  protected function getFileIdFromFilePath($file_path) {
    // Clean up the incoming file path prior to querying the database. The
    // file path in the HTML may have had spaces encoded or may be document
    // relative paths which will fail either on lookup or on file creation
    // later.
    $file_path = str_replace('%20', ' ', $file_path);
    $file_path = ltrim($file_path, './');
    $filename = basename($file_path);
    $filedir = dirname($file_path);
    $filedir = str_replace('ipimages', 'images', $filedir);
    $query = db_select('migrate_map_rtsbfile', 'm')
      ->fields('m', array('destid1'));
    $query->join('rt_files', 'f', 'm.sourceid1=f.file_id');
    $query->join('rt_fileroots', 'fr', 'f.fileroot_id=fr.fileroot_id');
    $query->where("CONCAT(fr.fileroot_name, TRIM(TRAILING '/' FROM f.relative_path)) = :path",
      array(':path' => $filedir));
    $query->condition('f.file_name', $filename, '=');
    $fid = $query->execute()->fetchField();

    // If the file isn't found, try to load it from the legacy site and save it.
    if (!$fid) {
      $src_url = 'http://www.law.columbia.edu/' . $file_path;
      try {
        if (($image = $this->fetchFileFromLegacyUrl($src_url)) !== FALSE) {
          $newdir = strtolower(str_replace(' ', '_', $filedir));
          $newfile = transliteration_clean_filename($filename);
          $uri = 'public://legacy/' . $newdir;
          file_prepare_directory($uri, FILE_CREATE_DIRECTORY);
          $file = file_save_data($image, $uri . '/' . $newfile, FILE_EXISTS_REPLACE);
          if ($file) {
            file_usage_add($file, 'cls_migrate_rt', $this->machineName, $file->fid);
            $fid = $file->fid;
          }
        }
      }
      catch (Exception $e) {
        $this->queueMessage(t('Failed to load image from @path', array(
          '@path' => $file_path,
        )));
      }
    }

    return $fid;
  }

  /**
   * Convert date/time string from Oracle to unix timestamp.
   *
   * @param string $oracle_date
   *   The date string to convert.
   *
   * @return int|null
   *   Unix timestamp or null if date is empty.
   */
  protected function convertOracleDateToTimestamp($oracle_date) {
    $result = NULL;
    if ($oracle_date) {
      $date = DateTime::createFromFormat('d-M-y h.i.s.u??? A', $oracle_date);
      $result = $date->getTimestamp();
    }
    return $result;
  }

  /**
   * Get a Drupal file url given a file ID from the Runtime RT_FILES table.
   *
   * @param int $file_id
   *   The file ID to look up.
   *
   * @return string
   *   Return the relative path to the file or an empty string if not found.
   */
  protected function getFileUrlFromFileId($file_id) {
    $url = '';
    $fid = db_select('migrate_map_rtsbfile', 'mm')
      ->fields('mm', array('destid1'))
      ->condition('sourceid1', $file_id, '=')
      ->execute()
      ->fetchField();

    if ($fid) {
      $linked_file = file_load($fid);
      if ($linked_file) {
        $file_url = file_create_url($linked_file->uri);
        if ($file_url) {
          $url = parse_url($file_url, PHP_URL_PATH);
        }
      }
    }
    return $url;
  }

  /**
   * Get a Drupal uid for the specified author email address.
   *
   * @param string $email
   *   Author email for this row.
   *
   * @return mixed
   *   Return UID of Drupal user or FALSE if the $email parameter was empty.
   */
  protected function getDrupalUidFromEmail($email) {
    $uid = FALSE;
    if (!empty($email)) {
      list($name, $domain) = explode('@', $email);
      $uid = $this->getExistingUserId($name, $email);
      if ($uid === FALSE) {
        $edit = array(
          'name' => $name,
          'mail' => $email,
          'status' => 1,
          'init' => $email,
          'roles' => array(2 => 'authenticated user'),
          'cas_name' => $name,
        );
        $account = user_save(NULL, $edit);
        if (is_object($account)) {
          $uid = $account->uid;
        }
      }
    }
    return $uid;
  }

  /**
   * Fetch a file from the legacy site via a URL.
   *
   * @param string $url
   *   The URL to the legacy asset.
   *
   * @return mixed
   *   The contents of the file returned.
   */
  protected function fetchFileFromLegacyUrl($url) {
    $url = str_replace(" ", "%20", $url);
    $ch = curl_init($url);
    curl_setopt($ch, CURLOPT_HEADER, FALSE);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, TRUE);
    curl_setopt($ch, CURLOPT_BINARYTRANSFER, TRUE);
    $data = curl_exec($ch);

    return $data;
  }
  
}
