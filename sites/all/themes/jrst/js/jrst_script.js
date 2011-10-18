Drupal.behaviors.toggleFollow = function (context) {
  var flag_text = $('.jrst-notification-follow a.flag:first');
  var orig_text = flag_text.text();
  flag_text.hover(
    function () {
      $(this).text($(this).attr('title'));
    },
    function () {
      $(this).text(orig_text);
    }
  );
}
Drupal.behaviors.anotherFunctionName = function (context) {}

