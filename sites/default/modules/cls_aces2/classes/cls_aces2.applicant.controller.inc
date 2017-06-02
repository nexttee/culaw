<?php

/**
 * @file
 */

module_load_include('inc', 'cls_oracle_integration', 'cls_oracle_integration.connection.class');

class CLSACES2ApplicantController extends EntityAPIController {

  public function save($entity, DatabaseTransaction $transaction = NULL) {
    return FALSE;
  }

  public function create(array $values = array()) {
    return FALSE;
  }

  public function load($ids = array(), $conditions = array()) {
    $entities = parent::load($ids, $conditions);
    $entity = new stdClass();
    $entity->recommenders = NULL;
    if (count($entities) == 1) {
      foreach ($entities as $entity) {
      	$entity->recommenders = $entity->getApplicantRecommenders();
      }
    }

    return $entities;
  }

  public function buildContent($entity, $view_mode = 'full', $langcode = NULL, $content = array()) {
    $build = parent::buildContent($entity, $view_mode, $langcode, $content);

    $build['year_entering'] = array(
      '#theme' => 'field',
      '#weight' => 0,
      '#title' =>t('Year Entering'),
      '#access' => TRUE,
      '#label_display' => 'above',
      '#view_mode' => 'full',
      '#language' => LANGUAGE_NONE,
      '#field_name' => 'field_fake_year_entering',
      '#field_type' => 'text',
      '#entity_type' => 'cls_aces2_applicant',
      '#bundle' => 'cls_aces2_applicant',
      '#items' => array(array('value' => $entity->year_entering)),
      '#formatter' => 'text_default',
      0 => array('#markup' => check_plain($entity->year_entering))
    );

    $build['program_applied'] = array(
      '#theme' => 'field',
      '#weight' => 1,
      '#title' =>t('Program Applied'),
      '#access' => TRUE,
      '#label_display' => 'above',
      '#view_mode' => 'full',
      '#language' => LANGUAGE_NONE,
      '#field_name' => 'field_fake_program_applied',
      '#field_type' => 'text',
      '#entity_type' => 'cls_aces2_applicant',
      '#bundle' => 'cls_aces2_applicant',
      '#items' => array(array('value' => $entity->program_applied)),
      '#formatter' => 'text_default',
      0 => array('#markup' => check_plain($entity->program_applied))
    );

    $build['lsac_account_number'] = array(
      '#theme' => 'field',
      '#weight' => 2,
      '#title' =>t('LSAC Account Number'),
      '#access' => TRUE,
      '#label_display' => 'above',
      '#view_mode' => 'full',
      '#language' => LANGUAGE_NONE,
      '#field_name' => 'field_fake_lsac_account_number',
      '#field_type' => 'text',
      '#entity_type' => 'cls_aces2_applicant',
      '#bundle' => 'cls_aces2_applicant',
      '#items' => array(array('value' => $entity->lsac_account_number)),
      '#formatter' => 'text_default',
      0 => array('#markup' => check_plain($entity->lsac_account_number))
    );

    $build['first_name'] = array(
      '#theme' => 'field',
      '#weight' => 3,
      '#title' =>t('First name'),
      '#access' => TRUE,
      '#label_display' => 'above',
      '#view_mode' => 'full',
      '#language' => LANGUAGE_NONE,
      '#field_name' => 'field_fake_first_name',
      '#field_type' => 'text',
      '#entity_type' => 'cls_aces2_applicant',
      '#bundle' => 'cls_aces2_applicant',
      '#items' => array(array('value' => $entity->first_name)),
      '#formatter' => 'text_default',
      0 => array('#markup' => check_plain($entity->first_name))
    );

    $build['last_name'] = array(
      '#theme' => 'field',
      '#weight' => 4,
      '#title' =>t('Last name'),
      '#access' => TRUE,
      '#label_display' => 'above',
      '#view_mode' => 'full',
      '#language' => LANGUAGE_NONE,
      '#field_name' => 'field_fake_last_name',
      '#field_type' => 'text',
      '#entity_type' => 'cls_aces2_applicant',
      '#bundle' => 'cls_aces2_applicant',
      '#items' => array(array('value' => $entity->last_name)),
      '#formatter' => 'text_default',
      0 => array('#markup' => check_plain($entity->last_name))
    );

    // @todo Add additional properties to $build array
    // Use http://drupal.org/project/eva and hook_field_extra_fields to attach:
    //   - pending notification emails
    //   - sent notifications emails
    //   - sent MailChimp emails
    //   - notification exclusions

    return $build;
  }

}

/**
 * CLS ACES2 Applicant class.
 */
class CLSACES2Applicant extends Entity {
  protected function defaultLabel() {
    return $this->first_name . ' ' . $this->last_name . ' (' . $this->lsac_account_number . ', ' . $this->year_entering . ')';
  }

  protected function defaultUri() {
    return array('path' => 'admissions/admin/applicants/' . $this->identifier());
  }

  public function getSessionSafeObject() {
    $applicant_data = new stdClass;

    $applicant_data->id = $this->id;
    $applicant_data->program_applied = $this->program_applied;
    $applicant_data->year_entering = $this->year_entering;
    $applicant_data->lsac_account_number = $this->lsac_account_number;
    $applicant_data->last_name = $this->last_name;
    $applicant_data->first_name = $this->first_name;
    $applicant_data->middle_name = $this->middle_name;
    $applicant_data->prefix = $this->prefix;
    $applicant_data->suffix = $this->suffix;
    $applicant_data->salutation = $this->salutation;
    $applicant_data->birth_date = $this->birth_date;
    $applicant_data->gender = $this->gender;
    $applicant_data->cuid = $this->cuid;
    $applicant_data->email_primary = $this->email_primary;
    $applicant_data->email_secondary = $this->email_secondary;
    $applicant_data->cell_phone = $this->cell_phone;
    $applicant_data->application_type = $this->application_type;
    $applicant_data->application_status = $this->application_status;
    $applicant_data->current_status = $this->current_status;
    $applicant_data->application_signed = $this->application_signed;
    $applicant_data->application_fee_received = $this->application_fee_received;
    $applicant_data->completed_date = $this->completed_date;
    $applicant_data->decision_status = $this->decision_status;
    $applicant_data->resume_on_file = $this->resume_on_file;
    $applicant_data->personal_statement_received = $this->personal_statement_received;
    $applicant_data->number_of_lors = $this->number_of_lors;
    $applicant_data->lsdas_received_date = $this->lsdas_received_date;
    $applicant_data->dean_certification = $this->dean_certification;
    $applicant_data->final_transcript = $this->final_transcript;
    $applicant_data->degree_applied = $this->degree_applied;
    $applicant_data->deposit_deadline = $this->deposit_deadline;
    $applicant_data->deposit_deadline_formatted = $this->deposit_deadline_formatted;
    $applicant_data->deposit_amount = $this->deposit_amount;
    $applicant_data->deposit_waived = $this->deposit_waived;
    $applicant_data->deposit2_deadline = $this->deposit2_deadline;
    $applicant_data->deposit2_deadline_formatted = $this->deposit2_deadline_formatted;
    $applicant_data->deposit2_amount = $this->deposit2_amount;
    $applicant_data->deposit2_waived = $this->deposit2_waived;
    $applicant_data->enrollment_id = $this->enrollment_id;
    $applicant_data->enrollment_offer_accepted = $this->enrollment_offer_accepted;
    $applicant_data->enrollment_decline_reason = $this->enrollment_decline_reason;
    $applicant_data->enrollment_decision_date = $this->enrollment_decision_date;
    $applicant_data->enrollment_decision_date_formatted = $this->enrollment_decision_date_formatted;
    $applicant_data->current_school_code = $this->current_school_code;
    $applicant_data->previously_synced_school_code = $this->previously_synced_school_code;
    $applicant_data->current_school_degree_date = $this->current_school_degree_date;
    $applicant_data->previously_synced_school_degree_date = $this->previously_synced_school_degree_date;
    $applicant_data->current_zip_code = $this->current_zip_code;
    $applicant_data->previously_synced_zip_code = $this->previously_synced_zip_code;
    $applicant_data->current_country = $this->current_country;
    $applicant_data->previously_synced_country = $this->previously_synced_country;
    $applicant_data->export_modified_date = $this->export_modified_date;
    $applicant_data->created = $this->created;
    $applicant_data->changed = $this->changed;
    $applicant_data->status = $this->status;
    $applicant_data->module = $this->module;
    $applicant_data->recommenders = $this->recommenders;

    return $applicant_data;
  }

  public function getApplicantRecommenders() {

    $recommenders = array();

    // Get recommenders for applicants who applied to the J.D. program.
    // @todo Have Boris add a YEAR_ENTERING column to the ACES2_RECOMMENDER table so
    //   we can query an applicant's recommenders by a specific application year.

    if ($this->program_applied == 1) {
      $client_id = variable_get('cls_client_id_2');
      $client_secret = variable_get('cls_client_secret_2');
      $endpoint_base_url = cls_rest_api_get_endpoint_base_url();
      $client = cls_rest_api_make_api_request($client_id, $client_secret);

      $lsac = $this->lsac_account_number;
      $response = $client->fetch($endpoint_base_url.'/batch/aces2/jd/applicant/' . $lsac . '/recommenders');
      if(isset($response['result'][0])){
        foreach($response['result'] as $recommender){
          $name = trim($recommender['name']);
          $name = preg_replace('!\s+!', ' ', $name);
          $recommenders[] = $name;
        }
      }
    }

    // @todo Add functionality to return recommenders for applicants who applied to G.L.S. programs
    // once G.L.S. migrates to ACES2.

    return $recommenders;
  }

}
