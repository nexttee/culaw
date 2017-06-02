<div class="tour-content">
  <h2>LL.M. Student Life</h2>
  <p class="article"><img src="<?php echo '/' . drupal_get_path('module', 'cls_mcl'); ?>/images/tour_llm/11-student-life.jpg" class="float-right" height="370" width="370" />LL.M. students contribute greatly to the vibrant atmosphere at Columbia Law School. They become leaders in student organizations, such as the Student Senate and the Columbia International Arbitration Association. They help organize various social and academic events on campus. And they participate in club sports teams such as the Law School’s own intramural Dean’s Cup basketball team.</p>
<h4>Explore More</h4>
<?php echo drupal_render($form); ?>
<div class="actions-choices">
  <p><a class="skip-tour" href="<?php echo $mcl_home_url; ?>/tour/thanks">Jump to the next section</a></p>
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
