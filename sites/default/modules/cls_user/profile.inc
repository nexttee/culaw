<?php

/**
 * @file
 * Class for migrating RTSB faculty profiles to Drupal user entities.
 */

/**
 * Class RtsbFacultyProfileMigration.
 */
class RtsbFacultyProfileMigration extends RtsbMigration {

  protected $facultyRid;

  /**
   * RtsbFacultyProfileMigration constructor.
   *
   * @param array $arguments
   *   Arguments specified in migration registration.
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments);
    $this->description = t('Import of faculty profiles from RTSB');

    $this->facultyRid = db_select('role', 'r')
      ->fields('r', array('rid'))
      ->condition('name', 'Faculty User', '=')
      ->execute()
      ->fetchField();

    $this->map = new MigrateSqlMap($this->machineName,
      array(
        'contact_id' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => t('Source contact ID'),
          'alias' => 'p',
        ),
      ),
      MigrateDestinationUser::getKeySchema()
    );

    $query = db_select('migrate_profile_main', 'p')
      ->fields('p', array(
        'contact_id',
        'date_modified',
        'name_last',
        'name_first',
        'name_middle',
        'prefix',
        'suffix',
        'title',
        'w_address_1',
        'w_address_2',
        'w_city',
        'w_state',
        'w_zip',
        'phone_1',
        'phone_2',
        'email',
        'cat1_id',
        'usr_meta_1',
        'usr_img_1',
        'x_profile_abstract',
        'x_profile_detail',
        'x_marketing_abstract',
        'x_assistant_name',
        'x_assistant_email',
        'x_assistant_phone',
      ))
      ->orderBy('date_modified');

    $count_query = db_select('migrate_profile_main', 'p');
    $count_query->addExpression('COUNT(contact_id)', 'cnt');

    // Source fields imported from the JSON API.
    $fields = array(
      'contact_id' => t('Unique contact identifier'),
      'date_modified' => t('Last modified date'),
      'name_last' => t('Last name'),
      'name_first' => t('First name'),
      'name_middle' => t('Middle name'),
      'prefix' => t('Name prefix'),
      'suffix' => t('Name suffix'),
      'title' => t("Person's title"),
      'w_address_1' => t('Work address line 1'),
      'w_address_2' => t('Work address line 2'),
      'w_city' => t('Work city'),
      'w_state' => t('Work state'),
      'w_zip' => t('Work zip code'),
      'phone_1' => t('Phone number'),
      'phone_2' => t('Fax number'),
      'email' => t('Email address'),
      'cat1_id' => t('Category ID 1, corresponds to faculty type'),
      'usr_meta_1' => t('LawNet username'),
      'usr_img_1' => t('User profile thumbnail image.'),
      'x_profile_abstract' => t('Profile summary'),
      'x_profile_detail' => t('Full profile'),
      'x_marketing_abstract' => t('Marketing bio'),
      'x_assistant_name' => t('Faculty assistant name'),
      'x_assistant_email' => t('Faculty assistant email'),
      'x_assistant_phone' => t('Faculty assistant phone'),
      'profile_elements' => t('Profile elements, mapped in prepareRow'),
      'department' => t('Department, retrieved from a REST API call.'),
      'faculty_assistants' => t('Drupal uid(s) of faculty assistants.'),
      'faculty_roles' => t('Array of role IDs, set in prepareRow()'),
      'cas_name' => t('LawNet username, set in prepareRow() only for new users'),
    );

    $this->highwaterField = array(
      'name' => 'date_modified',
      'alias' => 'p',
      'type' => 'int',
    );

    $this->source = new MigrateSourceSQL($query, $fields, $count_query);
    $this->destination = new MigrateDestinationUser();

    $this->addFieldMapping('name', 'usr_meta_1');
    $this->addFieldMapping('mail', 'email');
    $this->addFieldMapping('cls_user_first_name', 'name_first');
    $this->addFieldMapping('cls_user_middle_name', 'name_middle');
    $this->addFieldMapping('cls_user_last_name', 'name_last');
    $this->addFieldMapping('cls_user_prefix', 'prefix');
    $this->addFieldMapping('cls_user_suffix', 'suffix');
    $this->addFieldMapping('cls_user_title', 'title');
    $this->addFieldMapping('field_faculty_office_address_1', 'w_address_1');
    $this->addFieldMapping('field_faculty_office_address_2', 'w_address_2');
    $this->addFieldMapping('field_faculty_office_city', 'w_city');
    $this->addFieldMapping('field_faculty_office_state', 'w_state')
      ->callbacks(array($this, 'processWorkState'));
    $this->addFieldMapping('field_faculty_office_zip_code', 'w_zip');
    $this->addFieldMapping('field_faculty_office_phone', 'phone_1');
    $this->addFieldMapping('field_faculty_office_fax', 'phone_2');
    $this->addFieldMapping('field_faculty_office_email', 'email');
    $this->addFieldMapping('field_faculty_role', 'cat1_id');
    $this->addFieldMapping('field_faculty_profile_image', 'usr_img_1')
      ->sourceMigration('RtsbProfileImage');
    $this->addFieldMapping('field_faculty_profile_image:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_faculty_profile_bio', 'x_profile_detail');
    $this->addFieldMapping('field_faculty_profile_bio:format')
      ->defaultValue('full_html');
    $this->addFieldMapping('field_faculty_bio_summary', 'x_profile_abstract');
    $this->addFieldMapping('field_faculty_bio_summary:format')
      ->defaultValue('full_html');
    $this->addFieldMapping('field_faculty_marketing_bio', 'x_marketing_abstract');
    $this->addFieldMapping('field_faculty_marketing_bio:format')
      ->defaultValue('full_html');
    $this->addFieldMapping('field_faculty_assistant_name', 'x_assistant_name');
    $this->addFieldMapping('field_faculty_assistant_email', 'x_assistant_email');
    $this->addFieldMapping('field_faculty_assistant_phone', 'x_assistant_phone');
    $this->addFieldMapping('field_faculty_profile_elements', 'profile_elements')
      ->sourceMigration('RtsbProfileElement');
    $this->addFieldmapping('field_student_account')
      ->defaultValue(0);
    $this->addFieldmapping('cls_user_department', 'department');
    $this->addFieldMapping('field_faculty_assistant_users', 'faculty_assistants');
    $this->addFieldMapping('status')
      ->defaultValue(1);
    $this->addFieldMapping('roles', 'faculty_roles');

    $this->addUnmigratedDestinations(array(
      'cls_user_advance_id',
      'cls_user_harris_id',
      'cls_user_alternate_email',
      'cls_user_alumni_preferred_degree',
      'cls_user_alumni_preferred_year',
      'cls_user_alumni_preferred_email',
      'cls_user_raisers_edge_id',
      'cls_user_uni',
      'cls_user_upn',
      'cls_sso_passcode',
      'cls_mcl_remote_user_id',
      'cls_mcl_birth_date',
      'cls_mcl_lsac_account_number',
      'cls_mcl_country',
      'cls_mcl_state_province',
      'cls_mcl_city',
      'cls_mcl_zip_code',
      'cls_mcl_undergrad_institution',
      'cls_mcl_undergrad_inst_other',
      'cls_mcl_undergrad_grad_year',
      'cls_mcl_grad_institution',
      'cls_mcl_grad_inst_other',
      'cls_mcl_grad_graduation_year',
      'cls_mcl_admissions_cycle',
      'cls_mcl_academic_interests',
      'cls_mcl_student_org_interests',
      'cls_mcl_security_question',
      'cls_mcl_security_answer',
      'cls_mcl_account_type',
      'field_prospective_student_type',
      'field_student_type',
      'field_current_student_type',
      'field_alumni_year',
    ));
  }

  /**
   * Migration::prepareRow() implementation.
   *
   * @inheritDoc
   */
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    if (empty($row->usr_meta_1)) {
      $this->queueMessage(t('Contact !id does not have a LawNet username to map.', array(
        '!id' => $row->contact_id,
      )));
      return FALSE;
    }

    $row->faculty_roles = array(DRUPAL_AUTHENTICATED_RID, $this->facultyRid);

    $existing_uid = $this->getExistingUserId($row->usr_meta_1, $row->email);
    if ($existing_uid && empty($row->migrate_map_destid1)) {
      $row->migrate_map_destid1 = $existing_uid;
      $this->rollbackAction = MigrateMap::ROLLBACK_PRESERVE;
      $current_roles = db_select('users_roles', 'ur')
        ->fields('ur', array('rid'))
        ->condition('uid', $existing_uid, '=')
        ->execute()
        ->fetchCol();

      $this->faculty_roles = array_unique(array_merge($row->faculty_roles, $current_roles));
    }

    // Fetch profile information from the REST API.
    $data = $this->getEmployeeInfoFromApi($row->usr_meta_1);
    if ($data) {
      // Map profile fields to the data contained in the result.
      $row->name_last = $data['employee']['lastName'];
      $row->name_first = $data['employee']['firstName'];
      $row->name_middle = $data['employee']['middleName'];
      $row->suffix = $data['employee']['suffix'];
      $row->prefix = $data['employee']['salutation'];
      $row->department = $data['employee']['department'];
      if (isset($data['employee']['buildingRoom']) && !empty($data['employee']['buildingRoom'])) {
        $row->w_address_1 = $data['employee']['buildingRoom']['building']['name'];
        $row->w_address_2 = $data['employee']['buildingRoom']['building']['addressLine'];
        $row->w_city = $data['employee']['buildingRoom']['building']['city'];
        $row->w_state = $data['employee']['buildingRoom']['building']['state']['code'];
        $row->w_zip = $data['employee']['buildingRoom']['building']['zip'];
      }
      $row->phone_2 = isset($data['employee']['fax']) ? $data['employee']['fax'] : $row->phone_2;
      foreach ($data['phones'] as $phone) {
        if ($phone['phoneType']['name'] == 'Work Phone' && $phone['published'] == TRUE) {
          $row->phone_1 = $phone['phoneNumber'];
        }
      }
      if (empty($row->email)) {
        foreach ($data['emails'] as $email) {
          if ($email['primary']) {
            $row->email = $email['emailAddress'];
            break;
          }
        }
      }
      if (isset($data['facultyAssistants']) && is_array($data['facultyAsssistants'])) {
        $row->faculty_assistants = $this->getFacultyAssistants($data['facultyAssistants']);
      }
    }

    $profile_elements = db_select('migrate_profile_extras', 'e')
      ->fields('e', array('contact_id', 'element_index', 'element_name_id'))
      ->condition('contact_id', $row->contact_id, '=')
      ->orderBy('element_index')
      ->orderBy('element_name_id')
      ->execute();

    while ($element = $profile_elements->fetchAssoc()) {
      $row->profile_elements[] = array_values($element);
    }
    $row->x_profile_detail = $this->rewriteFileLinks($row->x_profile_detail);
    $row->x_marketing_abstract = $this->rewriteFileLinks($row->x_marketing_abstract);
    $row->x_profile_abstract = $this->rewriteFileLinks($row->x_profile_abstract);
  }

  /**
   * {@inheritdoc}
   */
  public function complete($entity, stdClass $row) {
    $cas_name = db_select('cas_user', 'cu')
      ->fields('cu')
      ->condition('uid', $entity->uid, '=')
      ->execute()
      ->fetchAssoc();

    if (!$cas_name) {
      db_insert('cas_user')
        ->fields(array(
          'uid' => $entity->uid,
          'cas_name' => $row->usr_meta_1,
        ))
        ->execute();
    }
  }

   /**
   * Convert the CLS employee ids to Drupal users, creating if necessary.
   *
   * @param array $assistants
   *   Array of faculty assistant information from REST API.
   *
   * @return array
   *   Array of Drupal user uids.
   */
  protected function getFacultyAssistants(array $assistants) {
    $uids = array();
    migrate_instrument_start('getFacultyAssistants');

    foreach ($assistants as $assistant) {
      $login = $assistant['login'];
      $email = $login . '@law.columbia.edu';

      $uid = $this->getExistingUserId($login, $email);
      if ($uid) {
        $uids[] = $uid;
      }
      else {
        $edit = array(
          'name' => $login,
          'mail' => $email,
          'status' => 1,
          'init' => $email,
          'cls_user_first_name' => array(LANGUAGE_NONE => array(array('value' => $assistant['firstName']))),
          'cls_user_last_name' => array(LANGUAGE_NONE => array(array('value' => $assistant['lastName']))),
          'cls_user_department' => array(LANGUAGE_NONE => array(array('value' => 'Faculty Assistants'))),
          'roles' => array(2 => 'authenticated user'),
          'cas_name' => $login,
        );
        $account = user_save(NULL, $edit);
        if (is_object($account)) {
          $uids[] = $account->uid;
        }
      }
    }

    migrate_instrument_stop('getFacultyAssistants');

    return $uids;
  }

}
