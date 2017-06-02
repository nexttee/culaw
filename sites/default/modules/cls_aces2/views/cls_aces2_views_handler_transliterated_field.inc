<?php
/**
 * @file
 * Contains the cls_aces2_views_handler_transliterated_field class.
 */

class cls_aces2_views_handler_transliterated_field extends views_handler_field {

  /**
   * Add some required fields needed on render().
   */
  function construct() {
    parent::construct();
    $this->additional_fields['first_name'] = array(
      'table' => 'cls_aces2_applicant',
      'field' => 'first_name',
    );
    $this->additional_fields['middle_name'] = array(
      'table' => 'cls_aces2_applicant',
      'field' => 'middle_name',
    );
    $this->additional_fields['last_name'] = array(
      'table' => 'cls_aces2_applicant',
      'field' => 'last_name',
    );
  }

  /**
   * Loads additional fields.
   */
  function query() {
    parent::query();
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function get_value($values, $field = NULL) {
    $alias = isset($field) ? $this->aliases[$field] : $this->field_alias;
    if (isset($values->{$alias})) {
      return $values->{$alias};
    }
  }

  /**
   * Renders the field handler.
   */
  function render($values) {
    $value = $this->get_value($values);
    $value = $this->sanitize_value($value);

    if (!empty($value)) {
      preg_match('/[^x00-x7f]/', $value, $non_ascii_matches);
  
      if (!empty($non_ascii_matches)) {
        $first = $values->cls_aces2_applicant_first_name;
        $last = $values->cls_aces2_applicant_last_name;
        $middle = $values->cls_aces2_applicant_middle_name;

        module_load_include('php', 'cls_aces2', 'includes/detectlanguage/detectlanguage');
        
        DetectLanguage\DetectLanguage::setApiKey("55a8599bd0b371eddcd1692d176facd2");
        //$result = DetectLanguage\DetectLanguage::simpleDetect("$first $middle $last");
        $result = DetectLanguage\DetectLanguage::simpleDetect($value);
        if (!in_array($result, array('de','es'))) {
          $result = 'es';
        }

        $value = transliteration_get($value, '?', $result);

      }
    }

    return trim($value);
  }

}
