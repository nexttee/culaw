<div class="content">

  <div id="cls-mcl-new-account-serverside-errors" class="error serverside-error" style="display: block;">
    <?php echo (isset($_SESSION['messages']['error'][0])) ? $_SESSION['messages']['error'][0] : "" ?>
  </div>

      <?php echo drupal_render($form); ?>
</div>

<script type="text/javascript">
<!--//--><![CDATA[//><!--
(function ($) {
  Drupal.behaviors.clssso = {
    attach: function(context, settings) {
      try {
        if ($('#first-name') != undefined) {
	        $('#first-name').focus();
        }
      } catch (e) {};
    }
  };
})(jQuery);
//--><!]]>
</script>
