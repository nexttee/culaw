<div class="content">
  <div id="cls-mcl-check-status-form-serverside-errors" class="error serverside-error" style="display: block;">
    <?php echo (isset($_SESSION['messages']['error'][0])) ? $_SESSION['messages']['error'][0] : "" ?>
  </div>
  <div class="mcl-status-checker-form-column">
    <?php echo drupal_render($form); ?>
  </div>
  <div class="mcl-status-checker-form-instructions-column">
    <p></p>
  </div>
</div>
