<?php
$plugin = array(
  'form'     => 'feeds_tamper_php_compute_form',
  'callback' => 'feeds_tamper_php_compute_callback',
  'name'     => 'PHP Compute',
  'multi'    => 'skip',
);

function feeds_tamper_php_compute_form($importer, $element_key, $settings) {
  $form = array();
  $importers = feeds_importer_load_all();
  $options = array_keys($importers);
  $options = array_combine($options, $options);
  $form['importer'] = array(
    '#type' => 'select',
    '#title' => t('Importer'),
    '#options' => $options,
    '#default_value' => isset($settings['importer']) ? $settings['importer'] : array(),
  );

  ctools_include('dependent');
  foreach($importers as $importer_id => $importer) {
    $i = str_replace('_', '-', $importer_id);
    $form[$importer_id] = array(
      '#type' => 'fieldset',
      '#title' => t('Fields for '. $importer_id),
      '#process' => array('ctools_dependent_process'),
      '#dependency' => array('edit-php-compute-importer' => array($importer_id)),
      '#input' => TRUE,
      '#prefix' => '<div id="edit-php-compute-'. $i .'-wrapper"><div id="edit-php-compute-'. $i .'">',
      '#suffix' => '</div></div>',
    );

    $mappings = $importer->processor->config['mappings'];
    $options = array();
    $replace = array();
    foreach ($mappings as $map) {
      $options[$map['source']] = $map['source'] . ' (' . $map['target'] . ')';
      $replace[] = '[' . $map['source'] . '] = ' . $map['target'];
    }

    $form[$importer_id]['help'] = array(
      '#type' => 'fieldset',
      '#title' => t("Your code should return the value for the desired field.  Replacement fields are below:"),
      '#collapsible' => TRUE,
    );
    foreach ($replace as $replacement) {
      $form[$importer_id]['help'][$replacement] = array(
        '#value' => t("$replacement"),
        '#prefix' => '<div>',
        '#suffix' => '</div>',
      );
    }

    $form[$importer_id]['php_compute_code'] = array(
        '#type' => 'textarea',
        '#title' => t('PHP Code To Calculate Field'),
        '#default_value' => isset($settings[$importer_id]['php_compute_code']) ? $settings[$importer_id]['php_compute_code'] : '',
    );    
  }
  return $form;
}

function feeds_tamper_php_compute_callback($source, $item_key, $element_key, &$field, $values) {
  $res = $values[$values['importer']]['php_compute_code'];
  $sources = $source->batch->items[$item_key];
  foreach ($sources as $key => $value) {
    $res = str_replace("[$key]", $value, $res);
  }
  $field = _php_compute_value($res);
}

function _php_compute_value($code) {
  $result = drupal_eval('<?php ' . $code . ' ?>');
  return $result;
}