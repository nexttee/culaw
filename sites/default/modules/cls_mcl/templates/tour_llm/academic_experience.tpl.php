<div class="tour-content">
  <h2>The Academic Experience</h2>
  <p class="article"><img src="<?php echo '/' . drupal_get_path('module', 'cls_mcl'); ?>/images/tour_llm/6-academic-experience.jpg" class="float-right" height="370" width="370" />You can enhance your LL.M. studies with a number of academic activities designed to give you real-world experience and help you participate in legal scholarship on relevant issues.</p>
  <p class="article">For example, you can serve real clients as part of the Law School&rsquo;s human rights clinic; collaborate with the Center for Gender and Sexuality Law;  write articles for the Columbia Journal of Transnational Law; or work on&nbsp;pro bono cases.</p>
<h4>Explore More</h4>
<?php echo drupal_render($form); ?>
<div class="actions-choices">
  <p><a class="skip-tour" href="<?php echo $mcl_home_url; ?>/tour/student-life">Jump to the next section</a></p>
  <p><a class="skip-tour" href="<?php echo $mcl_home_url; ?>">Skip the rest of the tour</a></p>
</div>
</div>

<script type="text/javascript">
<!--//--><![CDATA[//><!--
(function ($) {
  Drupal.behaviors.clsmcl = {
    attach: function(context, settings) {
      try {
        $(document).ready(function() {
          $('.form-type-checkbox').addClass('group');
          $(':checkbox').iphoneStyle({
            checkedLabel: 'VIEW',
            uncheckedLabel: 'SKIP'
          });
        });
      } catch (e) {};
    }
  };
})(jQuery);
//--><!]]>
</script>
