<div class="tour-content">
<h2>Curriculum</h2>
<p class="article"><img src="<?php echo '/' . drupal_get_path('module', 'cls_mcl'); ?>/images/tour_llm/2-curriculum.jpg" class="float-right" height="370" width="370" />We offer an extensive curriculum that examines many of the most compelling areas of legal scholarship. Like law practice at the highest levels, our curriculum is global, interdisciplinary, and rigorous.</p>
<p class="article">As an LL.M. student, your curricular opportunities are countless. You can work with a clinic in environmental or human rights law; take courses such as Law and Development or Corporate Finance; enroll in seminars such as Civil Liberties and the Response to Terrorism or Critical Race Theory; participate in a negotiation or deals workshop; do an externship at the United Nations; or conduct research&nbsp;under the guidance of faculty.</p>
<h4>Explore More</h4>
<?php echo drupal_render($form); ?>
<div class="actions-choices">
  <p><a class="skip-tour" href="<?php echo $mcl_home_url; ?>/tour/academic-experience">Jump to the next section</a></p>
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
