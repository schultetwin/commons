/* 
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */


// $Id$
Drupal.behaviors.jrst_app = function (context) {
  var myTimer = undefined;
  var delayTime = 3000;

  $('a.jrstposLink', context).click(function () {
    // This function will get exceuted after the ajax request is completed successfully
    $(this).addClass('display-throbber');

    var jrstposInfo = function(data) {
      // The data parameter is a JSON object. The “products” property is the list of products items that was returned from the server response to the ajax request.
      $('#block-views-jrst_app_pos_info-block_1 .view-jrst-app-pos-info').html(data.jrst_app_view);
      $(this).removeClass('display-throbber');
      $('a.jrstposLink').removeClass('display-throbber');
    }
    $.ajax({
      type: 'POST',
      url: this.href, // Which url should be handle the ajax request. This is the url defined in the <a> html tag
      success: jrstposInfo, // The js function that will be called upon success request
      dataType: 'json', //define the type of data that is going to get back from the server
      data: 'js=' + $(this).attr("title") //Pass a key/value pair
    });

    return false;  // return false so the navigation stops here and not continue to the page in the link
}).removeClass('display-throbber');
}
