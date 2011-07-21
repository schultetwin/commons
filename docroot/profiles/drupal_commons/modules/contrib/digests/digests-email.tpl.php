<?php
/**
 * @file
 *   Renders a digest email.
 *
 * See http://drupal.org/node/226776 for a list of default variables.
 *
 * Other variables available:
 * - $account: The user account object of the user receiving the message
 * - $messages: An array of activity message objects
 * - $stream: The themed (HTML) list of activity messages
 * - $name: The name of the user being sent the message
 * - $name_link: The name of the user being sent the message, linked to their profile
 * - $date_small: The small formatted date per the site's settings
 * - $date_medium: The medium formatted date per the site's settings
 * - $date_large: The large formatted date per the site's settings
 * - $logo: HTML for the logo image
 * - $header: The email header set by the administrator
 * - $footer: The email footer set by the administrator
 * - $unsubscribe: Instructions on how to unsubscribe from digest emails
 */
?>
<div id="digests">
  <?php if ($header): ?>
    <div id="digests-header">
      <?php print $header; ?>
    </div>
  <?php endif; ?>
  <div id="digests-stream">
    <?php print $stream; ?>
  </div>
  <?php if ($footer): ?>
    <div id="digests-footer">
      <?php print $footer; ?>
    </div>
  <?php endif; ?>
  <?php if ($unsubscribe): ?>
    <div id="digests-unsubscribe">
      <?php print $unsubscribe; ?>
    </div>
  <?php endif; ?>
</div>
