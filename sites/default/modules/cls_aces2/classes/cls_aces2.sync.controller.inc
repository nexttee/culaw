<?php

  class CLSACES2SyncController {
    public static $deferred_data = array();

    public static function sync() {
      set_time_limit(0);
      date_default_timezone_set('America/New_York');
      $client_id = variable_get('cls_client_id_2');
      $client_secret = variable_get('cls_client_secret_2');
      $endpoint_base_url = cls_rest_api_get_endpoint_base_url();
      $client = cls_rest_api_make_api_request($client_id, $client_secret);

      self::sync_jd($client, $endpoint_base_url);
      self::downgrade_jds_to_deferred_role();
      self::sync_gls($client, $endpoint_base_url);
      self::sync_gls_transactions($client, $endpoint_base_url);
    }

    public static function cron() {
      CLSACES2SyncController::sync();
      variable_set('cls_aces2.cron.last_cron_run_date', REQUEST_TIME);
    }

    public static function sync_jd($client, $endpoint_base_url) {
      $last_modified_date = self::get_last_modified_record_date('jd');
      if ($last_modified_date !== FALSE) {
        $request = array('modifiedDate' => $last_modified_date);
        $response = $client->fetch($endpoint_base_url.'/batch/aces2/jd/applicants', $request);
        if(isset($response['result'][0])){
          $count = count($response['result']);
          foreach($response['result'] as $record){
            $current_status = trim($record['currentStatus']);
            $lsac_account_number = trim($record['lsacAccount']);

            if($current_status == 'Defer' || $current_status == 'Defer-1' || $current_status == 'Defer-2'){

              $old_status = db_select('cls_aces2_applicant', 'a')
                            ->fields('a', array('current_status'))
                            ->condition('a.lsac_account_number', $lsac_account_number, '=')
                            ->orderby('year_entering','DESC')
                            ->range(0,1)
                            ->execute()->fetchField();

              $previous_status = isset($old_status) ? $old_status : '';

              $deferred_object = array(
                'lsac_account_number' => $lsac_account_number,
                'defer_type' => $current_status,
                'previous_status' => $previous_status
              );

              self::$deferred_data[] = $deferred_object;
            }

            $export_modified_date = trim($record['modifiedDate']);
            $export_modified_date = date("Y-m-d H:i:s", strtotime($export_modified_date));

            if(isset($record['applicationSigned'])){
              $applicationSigned = trim($record['applicationSigned']) == true ? 'Y' : 'N';
            }else{
              $applicationSigned = NULL;
            }

            if(isset($record['applicationFeeReceived'])){
              $applicationFeeReceived = trim($record['applicationFeeReceived']) == true ? 'Y' : 'N';
            }else{
              $applicationFeeReceived = NULL;
            }

            if(isset($record['personalStatementReceived'])){
              $personalStatementReceived = trim($record['personalStatementReceived']) == true ? 'Y' : 'N';
            }else{
              $personalStatementReceived = NULL;
            }

            if(isset($record['resumeOnFile'])){
              $resumeOnFile = trim($record['resumeOnFile']) == true ? 'Y' : 'N';
            }else{
              $resumeOnFile = NULL;
            }

            if(isset($record['finalTranscriptRecieved'])){
              $finalTranscriptRecieved = trim($record['finalTranscriptRecieved']) == true ? 'Y' : 'N';
            }else{
              $finalTranscriptRecieved = NULL;
            }

            db_merge('cls_aces2_applicant')
            ->key(array(
              'program_applied' => 1,
              'lsac_account_number' => $lsac_account_number,
              'year_entering' => trim($record['yearEntering']),
            ))
            ->insertFields(array(
              'year_entering' => trim($record['yearEntering']),
              'lsac_account_number' => $lsac_account_number,
              'last_name' => trim($record['lastName']),
              'first_name' => trim($record['firstName']),
              'middle_name' => trim($record['middleName']),
              'prefix' => trim($record['prefix']),
              'suffix' => trim($record['suffix']),
              'salutation' => trim($record['salutation']),
              'birth_date' => trim($record['dob']),
              'gender' => trim($record['gender']),
              'cuid' => trim($record['cuid']),
              'email_primary' => trim($record['primaryEmail']),
              'email_secondary' => trim($record['secondaryEmail']),
              'application_status' => trim($record['applicationStatus']),
              'current_status' => $current_status,
              'application_signed' => $applicationSigned,
              'application_fee_received' => $applicationFeeReceived,
              'completed_date' => trim($record['completedDate']),
              'decision_status' => trim($record['decisionStatus']),
              'resume_on_file' => $resumeOnFile,
              'personal_statement_received' => $personalStatementReceived,
              'number_of_lors' => intval(trim($record['numberOfLors'])),
              'application_type' => trim($record['applicationType']),
              'lsdas_received_date' => trim($record['lsdasReceived']),
              'dean_certification' => trim($record['deanCertificationStatus']),
              'final_transcript' => $finalTranscriptRecieved,
              'export_modified_date' => $export_modified_date,
              'current_zip_code' => NULL,
              'current_country' => NULL,
              'current_school_code' => NULL,
              'current_school_degree_date' => NULL,
              'program_applied' => 1,
              'degree_applied' => 'JD',
              'created' => REQUEST_TIME,
              'changed' => REQUEST_TIME,
              'status' => 1,
              'module' => 'cls_aces2',
              ))
              ->updateFields(array(
                'year_entering' => trim($record['yearEntering']),
                'lsac_account_number' => trim($record['lsacAccount']),
                'last_name' => trim($record['lastName']),
                'first_name' => trim($record['firstName']),
                'middle_name' => trim($record['middleName']),
                'prefix' => trim($record['prefix']),
                'suffix' => trim($record['suffix']),
                'salutation' => trim($record['salutation']),
                'birth_date' => trim($record['dob']),
                'gender' => trim($record['gender']),
                'cuid' => trim($record['cuid']),
                'email_primary' => trim($record['primaryEmail']),
                'email_secondary' => trim($record['secondaryEmail']),
                'application_status' => trim($record['applicationStatus']),
                'current_status' => $current_status,
                'application_signed' => $applicationSigned,
                'application_fee_received' => $applicationFeeReceived,
                'completed_date' => trim($record['completedDate']),
                'decision_status' => trim($record['decisionStatus']),
                'resume_on_file' => $resumeOnFile,
                'personal_statement_received' => $personalStatementReceived,
                'number_of_lors' => intval(trim($record['numberOfLors'])),
                'application_type' => trim($record['applicationType']),
                'lsdas_received_date' => trim($record['lsdasReceived']),
                'dean_certification' => trim($record['deanCertificationStatus']),
                'final_transcript' => $finalTranscriptRecieved,
                'export_modified_date' => $export_modified_date,
                'current_zip_code' => NULL,
                'current_country' => NULL,
                'current_school_code' => NULL,
                'current_school_degree_date' => NULL,
                'changed' => REQUEST_TIME,
                ))
                ->execute();
          }
          watchdog('cls_aces2', 'ACES2 jd applicants synced: %count', array('%count' => $count), WATCHDOG_INFO);
        }else{
          $exception = $response['result']['message'];
          watchdog('cls_aces2', '%exception', array('%exception' => $exception), WATCHDOG_INFO);
        }
      }

      return TRUE;
    }

    public static function downgrade_jds_to_deferred_role(){
      if (count(self::$deferred_data) > 0) {
        $admitted_role            = 'Admitted Student (J.D.) User';
        $deferred_role            = 'Deferred Student (J.D.) User';
        $deposited_role           = 'Deposited Student (J.D.) User';
        $deposited_deferred_role  = 'Deposited Deferred Student (J.D.) User';

        $downgraded_lsacs = array();

        foreach (self::$deferred_data as $deferred_student) {
          $user_query = db_select('field_data_cls_mcl_lsac_account_number', 'f');
          $result = $user_query->fields('f', array('cls_mcl_lsac_account_number_value', 'entity_id'))
                    ->condition('cls_mcl_lsac_account_number_value', $deferred_student['lsac_account_number'])
                    ->condition('entity_type', 'user')
                    ->execute();

          if ($record = $result->fetchAssoc()) {
            if($record['cls_mcl_lsac_account_number_value'] && $record['entity_id']) {
              $jd_student = user_load($record['entity_id']);
              if ($jd_student) {
                // skip if student has already been downgraded to Deferred Student (J.D.) User
                if (in_array($deferred_role, $jd_student->roles)) {
                  continue;
                }
                // downgrade student if student has paid regular deposit and now defers
                elseif (in_array($deposited_role, $jd_student->roles)){
                  // removes $deposited_role
                  cls_common_user_remove_role_by_name($deposited_role, $jd_student->uid);
                  // add $admitted_role and $deferred_role
                  cls_common_user_add_role_by_name($admitted_role, $jd_student->uid);
                  cls_common_user_add_role_by_name($deferred_role, $jd_student->uid);

                  $downgraded_lsacs[] = $record['cls_mcl_lsac_account_number_value'];
                }
                // downgrade student if deferred student needs to pay additional deferral deposit
                elseif (in_array($deposited_deferred_role, $jd_student->roles) ){
                  if( $deferred_student['defer_type'] !== $deferred_student['previous_status'] && $deferred_student['previous_status'] !== ''){
                    // removes $deposited_deferred_role
                    cls_common_user_remove_role_by_name($deposited_deferred_role, $jd_student->uid);
                    // add $deferred_role
                    cls_common_user_add_role_by_name($deferred_role, $jd_student->uid);

                    $downgraded_lsacs[] = $record['cls_mcl_lsac_account_number_value'];
                  }
                }
              }
            }
          }
        }
        $downgraded_lsacs = count($downgraded_lsacs) > 0 ? implode(", ", $downgraded_lsacs) : 'None';
        watchdog('cls_aces2', 'JD applicants downgraded: %lsacs', array('%lsacs' => $downgraded_lsacs), WATCHDOG_INFO);
      }
      else{
        watchdog('cls_aces2', 'No JD applicants to downgrade', array(), WATCHDOG_INFO);
      }
    }

    public static function sync_gls($client, $endpoint_base_url) {
      $last_modified_date = self::get_last_modified_record_date('gls');
      $last_enrollment_date = self::get_last_enrollment_date('gls');

      if ($last_modified_date !== FALSE && $last_enrollment_date !== FALSE) {

        $request = array(
                    'modifiedDate' => $last_modified_date,
                    'enrollmentDecisionDate' => $last_enrollment_date
                  );
        $response = $client->fetch($endpoint_base_url.'/batch/aces2/gls/applicants', $request);

        if(isset($response['result'][0])){
          $count = count($response['result']);
          foreach($response['result'] as $record){

            $export_modified_date = trim($record['modifiedDate']);
            $export_modified_date = date("Y-m-d H:i:s", strtotime($export_modified_date));

            $enrollment_decision_date = trim($record['enrollmentStatus']['decisionDate']);
            $enrollment_decision_date = date("Y-m-d H:i:s", strtotime($enrollment_decision_date));

            $program_applied = (trim($record['degreeApplied']) == 'LLM') ? 2 : 3;
            $deposit_amount = trim($record['depositAmount']);
            $deposit_amount = (!empty($deposit_amount) && is_numeric($deposit_amount)) ? number_format($deposit_amount, 2, '.', '') : NULL;
            $deposit2_amount = trim($record['depositAmount2']);
            $deposit2_amount = (!empty($deposit2_amount) && is_numeric($deposit2_amount)) ? number_format($deposit2_amount, 2, '.', '') : NULL;

            $enrollment_id = trim($record['enrollmentStatus']['id']);

            if(isset($record['applicationSigned'])){
              $applicationSigned = trim($record['applicationSigned']) == true ? 'Y' : 'N';
            }else{
              $applicationSigned = NULL;
            }

            if(isset($record['applicationFeeReceived'])){
              $applicationFeeReceived = trim($record['applicationFeeReceived']) == true ? 'Y' : 'N';
            }else{
              $applicationFeeReceived = NULL;
            }

            if(isset($record['personalStatementReceived'])){
              $personalStatementReceived = trim($record['personalStatementReceived']) == true ? 'Y' : 'N';
            }else{
              $personalStatementReceived = NULL;
            }

            if(isset($record['depositWaived'])){
              $depositWaived = trim($record['depositWaived']) == true ? 'Y' : 'N';
            }else{
              $depositWaived = NULL;
            }

            if(isset($record['depositWaived2'])){
              $depositWaived2 = trim($record['depositWaived2']) == true ? 'Y' : 'N';
            }else{
              $depositWaived2 = NULL;
            }

            if(isset($record['enrollmentStatus']['offerAccepted'])){
              $offerAccepted = trim($record['enrollmentStatus']['offerAccepted']) == true ? 'Y' : 'N';
            }else{
              $offerAccepted = NULL;
            }

            db_merge('cls_aces2_applicant')
              ->key(array(
                'program_applied' => $program_applied,
                'lsac_account_number' => trim($record['lsacAccount']),
                'year_entering' => trim($record['yearEntering']),
              ))
              ->insertFields(array(
                'year_entering' => trim($record['yearEntering']),
                'lsac_account_number' => trim($record['lsacAccount']),
                'last_name' => trim($record['lastName']),
                'first_name' => trim($record['firstName']),
                'middle_name' => trim($record['middleName']),
                'prefix' => trim($record['prefix']),
                'suffix' => trim($record['suffix']),
                'salutation' => trim($record['salutation']),
                'birth_date' => trim($record['dob']),
                'gender' => trim($record['gender']),
                'cuid' => trim($record['cuid']),
                'email_primary' => trim($record['primaryEmail']),
                'email_secondary' => trim($record['secondaryEmail']),
                'cell_phone' => trim($record['cellPhone']),
                'application_status' => trim($record['applicationStatus']),
                'current_status' => trim($record['currentStatus']),
                'application_signed' => $applicationSigned,
                'application_fee_received' => $applicationFeeReceived,
                'completed_date' => trim($record['completedDate']),
                'decision_status' => trim($record['decisionStatus']),
                'personal_statement_received' => $personalStatementReceived,
                'number_of_lors' => intval(trim($record['numberOfLors'])),
                'application_type' => trim($record['applicationType']),
                'lsdas_received_date' => trim($record['lsdasReceived']),
                'degree_applied' => trim($record['degreeApplied']),
                'deposit_deadline' => !empty($record['depositDeadline']) ? strtotime($record['depositDeadline']) : NULL,
                'deposit_deadline_formatted' => trim($record['depositDeadline']),
                'deposit_amount' => $deposit_amount,
                'deposit_waived' => $depositWaived,
                'deposit2_deadline' => !empty($record['depositDeadline2']) ? strtotime($record['depositDeadline2']) : NULL,
                'deposit2_deadline_formatted' => trim($record['depositDeadline2']),
                'deposit2_amount' => $deposit2_amount,
                'deposit2_waived' => $depositWaived2,
                'enrollment_id' => !empty($enrollment_id) ? intval($enrollment_id) : NULL,
                'enrollment_offer_accepted' => $offerAccepted,
                'enrollment_decline_reason' => trim($record['enrollmentStatus']['declineReason']),
                'enrollment_decision_date' => !empty($record['enrollmentStatus']['decisionDate']) ? strtotime($record['enrollmentStatus']['decisionDate']) : NULL,
                'enrollment_decision_date_formatted' => $enrollment_decision_date,
                'export_modified_date' => $export_modified_date,
                'current_zip_code' => NULL,
                'current_country' => NULL,
                'current_school_code' => NULL,
                'current_school_degree_date' => NULL,
                'program_applied' => $program_applied,
                'created' => REQUEST_TIME,
                'changed' => REQUEST_TIME,
                'status' => 1,
                'module' => 'cls_aces2',
              ))
              ->updateFields(array(
                'year_entering' => trim($record['yearEntering']),
                'lsac_account_number' => trim($record['lsacAccount']),
                'last_name' => trim($record['lastName']),
                'first_name' => trim($record['firstName']),
                'middle_name' => trim($record['middleName']),
                'prefix' => trim($record['prefix']),
                'suffix' => trim($record['suffix']),
                'salutation' => trim($record['salutation']),
                'birth_date' => trim($record['dob']),
                'gender' => trim($record['gender']),
                'cuid' => trim($record['cuid']),
                'email_primary' => trim($record['primaryEmail']),
                'email_secondary' => trim($record['secondaryEmail']),
                'cell_phone' => trim($record['cellPhone']),
                'application_status' => trim($record['applicationStatus']),
                'current_status' => trim($record['currentStatus']),
                'application_signed' => $applicationSigned,
                'application_fee_received' => $applicationFeeReceived,
                'completed_date' => trim($record['completedDate']),
                'decision_status' => trim($record['decisionStatus']),
                'personal_statement_received' => $personalStatementReceived,
                'number_of_lors' => intval(trim($record['numberOfLors'])),
                'application_type' => trim($record['applicationType']),
                'lsdas_received_date' => trim($record['lsdasReceived']),
                'degree_applied' => trim($record['degreeApplied']),
                'deposit_deadline' => !empty($record['depositDeadline']) ? strtotime($record['depositDeadline']) : NULL,
                'deposit_deadline_formatted' => trim($record['depositDeadline']),
                'deposit_amount' => $deposit_amount,
                'deposit_waived' => $depositWaived,
                'deposit2_deadline' => !empty($record['depositDeadline2']) ? strtotime($record['depositDeadline2']) : NULL,
                'deposit2_deadline_formatted' => trim($record['depositDeadline2']),
                'deposit2_amount' => $deposit2_amount,
                'deposit2_waived' => $depositWaived2,
                'enrollment_id' => !empty($enrollment_id) ? intval($enrollment_id) : NULL,
                'enrollment_offer_accepted' => $offerAccepted,
                'enrollment_decline_reason' => trim($record['enrollmentStatus']['declineReason']),
                'enrollment_decision_date' => !empty($record['enrollmentStatus']['decisionDate']) ? strtotime($record['enrollmentStatus']['decisionDate']) : NULL,
                'enrollment_decision_date_formatted' => $enrollment_decision_date,
                'export_modified_date' => $export_modified_date,
                'current_zip_code' => NULL,
                'current_country' => NULL,
                'current_school_code' => NULL,
                'current_school_degree_date' => NULL,
                'changed' => REQUEST_TIME,
              ))
              ->execute();
          }
          watchdog('cls_aces2', 'ACES2 gls applicants synced: %count', array('%count' => $count), WATCHDOG_INFO);
        }else{
          $exception = $response['result']['message'];
          watchdog('cls_aces2', '%exception', array('%exception' => $exception), WATCHDOG_INFO);
        }
      }

      return TRUE;
    }

    public static function sync_gls_transactions($client, $endpoint_base_url) {
      $last_transaction_date = self::get_last_transaction_date();

      if ($last_transaction_date !== FALSE) {
        $request = array('transactionDate' => $last_transaction_date);
        $response = $client->fetch($endpoint_base_url.'/batch/aces2/gls/applicant/deposits', $request);

        if(isset($response['result'][0])){
          $count = 0;
          foreach($response['result'] as $record){

            $lsac_number = trim($record['lsacAccount']);
            $corresponding_entering_year = db_select('cls_aces2_applicant', 'a')
                                        ->fields('a', array('year_entering'))
                                        ->condition('a.lsac_account_number', $lsac_number, '=')
                                        ->orderby('year_entering','DESC')
                                        ->range(0,1)
                                        ->execute()->fetchField();

            if(isset($corresponding_entering_year)){
              $program_applied = 0;
              $amount = trim($record['amount']);
              $amount = (!empty($amount) && is_numeric($amount)) ? number_format($amount, 2, '.', '') : NULL;

              $transaction_date = trim($record['transactionDate']);
              $transaction_date = date("Y-m-d H:i:s", strtotime($transaction_date));

              db_merge('cls_aces2_deposit_transaction')
                ->key(array(
                  'record_id' => intval($record['id']),
                  ))
                ->insertFields(array(
                  'record_id' => intval($record['id']),
                  'transaction_id' => intval($record['transactionId']),
                  'year_entering' => $corresponding_entering_year,
                  'program_applied' => $program_applied,
                  'lsac_account_number' => $lsac_number,
                  'transaction_date' => !empty($record['transactionDate']) ? strtotime($record['transactionDate']) : NULL,
                  'transaction_date_formatted' => $transaction_date,
                  'amount' => $amount,
                  'response_code' => intval($record['responseCode']),
                  'response_description' => trim($record['responseDescription']),
                  'created' => REQUEST_TIME,
                  'changed' => REQUEST_TIME,
                  'status' => 1,
                  'module' => 'cls_aces2',
                  ))
                ->updateFields(array(
                  'record_id' => intval($record['id']),
                  'transaction_id' => intval($record['transactionId']),
                  'program_applied' => $program_applied,
                  'lsac_account_number' => $lsac_number,
                  'transaction_date' => !empty($record['transactionDate']) ? strtotime($record['transactionDate']) : NULL,
                  'transaction_date_formatted' => $transaction_date,
                  'amount' => $amount,
                  'response_code' => intval($record['responseCode']),
                  'response_description' => trim($record['responseDescription']),
                  'changed' => REQUEST_TIME,
                  ))
                ->execute();
                $count++;
            }else{
              watchdog('cls_aces2', 'No corresponding applicant found. Unable to sync transaction with record id: %id', array('%id' => intval($record['id'])), WATCHDOG_INFO);
            }
          }
          watchdog('cls_aces2', 'ACES2 gls transactions synced: %count', array('%count' => $count), WATCHDOG_INFO);
        }else{
          $exception = $response['result']['message'];
          watchdog('cls_aces2', '%exception', array('%exception' => $exception), WATCHDOG_INFO);
        }
      }

      return TRUE;
    }


    public static function get_last_modified_record_date($sync_type = 'jd') {
      $query = ($sync_type == 'gls') ? ' WHERE program_applied IN (2,3)' : ' WHERE program_applied = 1';
      $result = db_query("SELECT MAX(export_modified_date) as last_modified_date FROM {cls_aces2_applicant} $query");
      if ($result->rowCount() == 1) {
        $last_modified_date = $result->fetchColumn();
        if ($last_modified_date != '') {
          $last_modified_date = strtotime($last_modified_date);
          $micro_seconds = sprintf("%06d", ($last_modified_date - floor($last_modified_date)) * 1000000);
          $date_time = new DateTime(date('Y-m-d H:i:s.'. $micro_seconds, $last_modified_date));
          $formatted_date = sprintf("%s%03d%s", $date_time->format("Y-m-d\TH:i:s."), floor($date_time->format("u")/1000),$date_time->format("O"));
          return $formatted_date;
        }
      }
      return FALSE;
    }

    public static function get_last_enrollment_date($sync_type = 'jd') {
      $query = ($sync_type == 'gls') ? ' WHERE program_applied IN (2,3)' : ' WHERE program_applied = 1';
      $result = db_query("SELECT MAX(enrollment_decision_date_formatted) as last_enrollment_date FROM {cls_aces2_applicant} $query");

      if ($result->rowCount() == 1) {
        $last_enrollment_date = $result->fetchColumn();
        if ($last_enrollment_date != '') {
          $last_enrollment_date = strtotime($last_enrollment_date);
          $micro_seconds = sprintf("%06d", ($last_enrollment_date - floor($last_enrollment_date)) * 1000000);
          $date_time = new DateTime(date('Y-m-d H:i:s.'. $micro_seconds, $last_enrollment_date));
          $formatted_date = sprintf("%s%03d%s", $date_time->format("Y-m-d\TH:i:s."), floor($date_time->format("u")/1000),$date_time->format("O"));
          return $formatted_date;
        }
      }
      return FALSE;
    }

    public static function get_last_record_id($sync_type = 'jd') {
      $query = ($sync_type == 'gls') ? ' WHERE program_applied IN (2,3)' : ' WHERE program_applied = 1';
      $result = db_query("SELECT MAX(record_id) as last_record_id FROM {cls_aces2_deposit_transaction} $query");

      if ($result->rowCount() == 1) {
        $last_record_id = $result->fetchColumn();
        if ($last_record_id != '') {
          return $last_record_id;
        }
      }
      return 0;
    }

    public static function get_last_transaction_date(){
      $result = db_query("SELECT MAX(transaction_date_formatted) as last_transaction_date FROM {cls_aces2_deposit_transaction}");
      if ($result->rowCount() == 1) {
        $last_transaction_date= $result->fetchColumn();
        if ($last_transaction_date != '') {
          $last_transaction_date = strtotime($last_transaction_date);
          $micro_seconds = sprintf("%06d", ($last_transaction_date - floor($last_transaction_date)) * 1000000);
          $date_time = new DateTime(date('Y-m-d H:i:s.'. $micro_seconds, $last_transaction_date));
          $formatted_date = sprintf("%s%03d%s", $date_time->format("Y-m-d\TH:i:s."), floor($date_time->format("u")/1000),$date_time->format("O"));
          return $formatted_date;
        }
      }
      return FALSE;
    }

  }
