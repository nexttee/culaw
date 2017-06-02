<?php

function cls_aces2_applicant_view($cls_aces2_applicant) {
  return entity_view('cls_aces2_applicant', array(entity_id('cls_aces2_applicant', $cls_aces2_applicant) => $cls_aces2_applicant), 'full');
}

function cls_aces2_sync_page() {
  CLSACES2SyncController::sync();
  drupal_set_message('Applicants were synchronized with data from the latest export of ACES2.');
  drupal_goto('admissions/admin/applicants');
}

function cls_aces2_applicant_test() {
  $aces2_applicants = cls_aces2_applicant_load_by_program_year_lsac('1', '2013', 'L32135604');
  print_r($aces2_applicants);
  $status_checker = cls_aces2_applicant_load_by_status_checker_criteria('1', '2013', 'L32135604', 'Ethan', 'Merel', '1991-07-26');
  print_r($status_checker);
  drupal_exit();
}
