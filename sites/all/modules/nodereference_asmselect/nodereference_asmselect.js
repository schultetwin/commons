Drupal.behaviors.nodereference_asmselect = function (context) {
  for (foo in Drupal.settings.nodereferenceAsmselect) {
    var bar = '#' + foo +'-nid-nid';
    $(bar).asmSelect({
      sortable: Drupal.settings.nodereferenceAsmselect[foo].sortable,
      highlight: Drupal.settings.nodereferenceAsmselect[foo].highlight,
      animate: Drupal.settings.nodereferenceAsmselect[foo].animate,
      addItemTarget: Drupal.settings.nodereferenceAsmselect[foo].add_item_target
    });
  }
  $('.asmSelect option:first-child').text('Select One or More');
}