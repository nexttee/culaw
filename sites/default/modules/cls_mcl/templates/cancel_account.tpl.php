<div class="content">
<!--
  <div id="cls-mcl-cancel-account-serverside-errors" class="error serverside-error" style="display: block;">
    <?php echo (isset($_SESSION['messages']['error'][0])) ? $_SESSION['messages']['error'][0] : "" ?>
  </div>
-->
  <h2>Cancelling Your <?php echo $site_instance['title']; ?> Account</h2>
  <p class="introduction">You&rsquo;ve requested to cancel your <?php echo $site_instance['title']; ?> account. Once your request is processed, your personal information, account settings, and communication preferences will be marked for removal, and you will no longer be able to log in to <?php echo $site_instance['title']; if ($site_instance['instance_id'] != 'my_columbia_llm'): ?>.<?php endif; ?></p>
  <hr class="dashed" />
  <h4 style="
    margin-bottom: 25px;
">For the safety of your account, please confirm your cancellation request<br>by entering your <?php echo $site_instance['title']; ?> password: <span class="form-required" title="This field is required.">*</span></h4>
  <?php echo drupal_render($form); ?>
</div>

<script type="text/javascript">
<!--//--><![CDATA[//><!--
(function ($) {
  Drupal.behaviors.clsmcllogin = {
    attach: function(context, settings) {
      $('#edit-password').focus();
      $('#edit-password:not(.no-big)').not('[value=\'\']').addClass('no-bg');

      $('#edit-password').keypress(function() {
        $(this).addClass('no-bg');
      });
      $('#edit-password').focusout(function() {
        if ($(this).val() === '') {
          $(this).removeClass('no-bg');
        }
      });
    }
  };
})(jQuery);

//--><!]]>
</script>
