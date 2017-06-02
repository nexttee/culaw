<div class="content">
  <div class="mcl-login-instructions-column">
    <h2><?php echo $login_page_header ? $login_page_header : 'My Columbia Law'; ?></h2>
    <?php echo theme('mcl_login_' . $instance_id); ?>
    <div class="mcl-register-btn" style="margin-top: 35px; text-align: center;">
      <a href="<?php echo base_path() . $instance_path; ?>/get-started" class="button">Register &raquo;</a>
      <p style="margin-top: 10px; margin-bottom: 0; font-style: italic; font-size: 11px;">and get started now</p>
    </div>
  </div>
  <div class="mcl-login-form-column">
    <div class="mcl-login-photo">
      <img src="<?php echo $login_photo_uri; ?>" alt="<?php echo $login_photo_caption; ?>" style="border-radius: 0 10px 0 0;" />
    </div>
    <div class="mcl-login-form-login">
      <h3<?php if (!empty($_SESSION['messages']['error'])) {?> class="login-error"<?php } ?>>
        <?php echo !empty($login_form_header) ? $login_form_header : 'Already Registered?'; ?>
      </h3>
      <span class="error-msg">
        <?php echo (isset($_SESSION['messages']['error'][0])) ? $_SESSION['messages']['error'][0] : ''; ?>
      </span>
      <?php echo drupal_render($form); ?>
      <p class="having-trouble">
        <a id="having-trouble-link" href="<?php echo base_path() . $instance_path; ?>/password-recovery">Having trouble logging in?</a>
      </p>
    </div>
  </div>
</div>
