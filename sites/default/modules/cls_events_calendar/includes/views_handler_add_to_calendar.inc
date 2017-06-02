<?php
/**
 * @file
 * This file contains implementation of handler for custom add_to_calendar field.
 */
/**
 * Custom handler class.
 *
 * @ingroup views_field_handlers
 */
class views_handler_add_to_calendar extends views_handler_field {

  function construct() {
    parent::construct();
    $this->additional_fields['nid'] = 'nid';
  }
  /**
   * {@inheritdoc}
   */
  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  /**
   * {@inheritdoc}
   *
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['event_date_field'] = array('default' => '');
    return $options;
  }

  /**
   * {@inheritdoc}
   *
   * Make changes to the field settings form seen by the end user when adding
   * your field.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['event_date_field'] = array(
      '#title' => t('Machine name of date field that contains event date.'),
      '#description' => t('Machine name of Event Date field.'),
      '#type' => 'textfield',
      '#size' => 60,
      '#default_value' => $this->options['event_date_field'],
      '#required' => TRUE,
    );
  }

  /**
   * Render callback handler.
   *
   * Return the markup that will appear in the rendered field.
   */
  function render($values) {
    $base_url = 'node/' . $this->get_value($values, 'nid') . '/' . $this->options['event_date_field'] . '/' . 'default';
    $ics_url = $base_url . '/addtocal.ics';
    $google_url = $base_url . '/addtocal-google';
    $yahoo_url = $base_url . '/addtocal-yahoo';

    $items = array(
      l(t('iCalendar'), $ics_url, array('attributes' => array('class' => 'icalendar'))),
      l(t('Google'), $google_url, array('attributes' => array('target' => '_blank', 'class' => 'google'))),
      l(t('Outlook'), $ics_url, array('attributes' => array('class' => 'outlook'))),
      l(t('Yahoo'), $yahoo_url, array('attributes' => array('target' => '_blank', 'class' => 'yahoo'))),
    );
    $links = theme('item_list', array(
        'items' => $items,
        'type' => 'ul',
        '#attributes' => array(
          'class' => array('add_to_cal_menu'),
        ),
      )
    );
    return $links;
  }
}
