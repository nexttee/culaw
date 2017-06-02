<div class="tour-content">
  <h2>Second and Third Years</h2>
  <p class="article"><img src="<?php echo '/' . drupal_get_path('module', 'cls_mcl'); ?>/images/tour/second-third-year.jpg" class="float-right" height="370" width="370" />With the Foundation Curriculum behind you, you will be prepared to fully embrace the upper-class curricular offerings at Columbia Law School. These courses examine many of the most compelling areas of legal scholarship, and, similar to the practice of law at the highest levels, our curriculum is global, interdisciplinary, and rigorously practical.</p>
  <p class="article">A sampling of opportunities include:</p>
  <ul class="article">
    <li>Participating in a clinic focused on Human Rights Law or Environmental Law</li>
    <li>Taking a course in African Human Rights Systems in Comparative Perspective</li>
    <li>Attending a seminar in Civil Liberties and the Response to Terrorism or Critical Race Theory</li>
    <li>Completing an externship at the United Nations</li>
  </ul>
  <p class="article">As a law student, you are also afforded the opportunity to take classes at other schools within Columbia University, spend a semester abroad through our extensive collection of international programs, or obtain a double degree at a foreign university.</p>
<h4>Explore More</h4>
<?php echo drupal_render($form); ?>
<div class="actions-choices">
  <p><a class="skip-tour" href="<?php echo $mcl_home_url; ?>/experience/end">Jump to the next section</a></p>
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
