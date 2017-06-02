<?php
/**
 * @file
 * Custom JSON Reader class for MigrateSourceJSON.
 */

/**
 * Class RtsbJSONReader.
 */
class RtsbJSONReader extends MigrateJSONReader {
  /**
   * {@inheritdoc}
   */
  public function next() {
    migrate_instrument_start('MigrateJSONReader::next');

    $this->currentElement = $this->currentId = NULL;

    // Open the file and position it if necessary.
    if (!$this->fileHandle) {
      $this->fileHandle = fopen($this->url, 'r');
      if (!$this->fileHandle) {
        Migration::displayMessage(t('Could not open JSON file !url',
                                  array('!url' => $this->url)));
        return;
      }

      // Position ourseoves at the beginning of the rt_objects array.
      $char = $this->findRtObjectStart();
      if ($char != '[') {
        Migration::displayMessage(t('!url is not a JSON file containing an array of objects',
                                  array('!url' => $this->url)));
        return;
      }
    }

    // We expect to be positioned either at an object (beginning with {) or
    // the end of the file (we should see a ] indicating this). Or, an
    // object-separating comma, to be skipped. Note that this treats
    // commas as optional between objects, which helps with processing
    // malformed JSON with missing commas (as in Ning exports).
    $c = $this->getNonBlank();
    if ($c == ',') {
      $c = $this->getNonBlank();
    }
    // Ning sometimes emits a ] where there should be a comma.
    elseif ($c == ']') {
      $c = $this->getNonBlank();
      if ($c != '{') {
        $c = NULL;
      }
    }
    // We expect to be at the first character of an object now.
    if ($c == '{') {
      // Start building a JSON string for this object.
      $json = $c;
      // Look for the closing }, ignoring brackets in strings, tracking nested
      // brackets. Watch out for escaped quotes, but also note that \\" is not
      // an escaped quote.
      $depth = 1;
      $in_string = FALSE;
      $in_escape = FALSE;
      while (($c = fgetc($this->fileHandle)) !== FALSE) {
        $json .= $c;
        if ($in_string) {
          // Quietly accept an escaped character.
          if ($in_escape) {
            $in_escape = FALSE;
          }
          else {
            switch ($c) {
              // Unescaped " means end of string.
              case '"':
                $in_string = FALSE;
                break;

              // Unescaped \\ means start of escape.
              case '\\':
                $in_escape = TRUE;
                break;
            }
          }
        }
        else {
          // Outside of strings, recognize {} as depth changes, " as start of
          // string.
          switch ($c) {
            case '{':
              $depth++;
              break;

            case '}':
              $depth--;
              break;

            case '"':
              $in_string = TRUE;
              break;
          }
          // We've found our match, exit the loop.
          if ($depth < 1) {
            break;
          }
        }
      }

      // Turn the JSON string into an object.
      $this->currentElement = json_decode($json);
      $this->currentElement->id = $this->currentElement->_attributes->{$this->idField};
      $this->currentId = $this->currentElement->_attributes->{$this->idField};
    }
    else {
      $this->currentElement = NULL;
      $this->currentId = NULL;
    }
    migrate_instrument_stop('MigrateJSONReader::next');
  }

  /**
   * Search for the array opening bracket inside the rt_objects element.
   *
   * @return mixed
   *   Return the '[' character, or FALSE if we reach the end of the file.
   */
  protected function findRtObjectStart() {
    // Runtime JSON API resultsets are contained in an object with index
    // rt_objects so we need to skip everything before that. It is possible
    // that there is a "messages" object preceding the "rt_objects" object.
    $string = '';
    while (($c = fgetc($this->fileHandle)) !== FALSE && $c != '[') {
      $string .= $c;
    }
    // If we don't find the expected index, keep looking as long as we
    // are not at the end of the file.
    if (strpos($string, 'rt_object') === FALSE && $c !== FALSE) {
      $this->findRtObjectStart();
    }

    return $c;
  }

}
