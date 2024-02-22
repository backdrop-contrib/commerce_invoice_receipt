<?php
/**
 * Set recipients of an invoice, and mail it.
 *
 * @ingroup forms
 * @see
 *   commerce_invoice_receipt_mail_form_validate()
 *   commerce_invoice_receipt_mail_form_submit()
 */
function commerce_invoice_receipt_mail_form($form_state, $order) {
  $form['order_id'] = array(
    '#type' => 'hidden',
    '#value' => $order['build_info']['args'][0]->order_id,
  );
  
  $form['email'] = array(
    '#type' => 'textfield',
    '#title' => t('Recipient e-mail address'),
    '#default_value' => $order['build_info']['args'][0]->mail,
  );
  
  $form['submit' ] = array(
    '#type' => 'submit',
    '#value' => t('Email invoice'),
  );

  return $form;
}

/**
 * Only mail invoices to valid email addresses.
 *
 * @see commerce_invoice_receipt_mail_form()
 */
function commerce_invoice_receipt_mail_form_validate($form, &$form_state) {
  $recipient = check_plain($form_state['values']['email']);
  if (empty($recipient) || !valid_email_address($recipient)) {
    form_set_error('email', t('Invalid e-mail address.'));
  }
}

/**
 * @see commerce_invoice_receipt_mail_form()
 */
function commerce_invoice_receipt_mail_form_submit($form, &$form_state) {
  $order = commerce_order_load($form_state['values']['order_id']);
  
  if ($order === FALSE) {
    backdrop_set_message(t('Order @order_id does not exist.', array('@order_id' => $form_state['values']['order_id'])));
    backdrop_goto('admin/commerce/orders');
  }
  
  $recipient = check_plain($form_state['values']['email']);
  
  $params = array('order' => $order);
  $from_email = config_get('system.core', 'site_mail');
  
  $account = user_load($order->uid);
  $language = user_preferred_language($account);
  
  $sent = backdrop_mail('commerce_invoice_receipt', 'invoice', $recipient, $language, $params, $from_email);
  
  if (!$sent) {
    backdrop_set_message(t('E-mail failed.'));
  }
  else {
    $message = t('Invoice e-mailed to @email.', array('@email' => $recipient));
    backdrop_set_message($message);
  }
}