<div class="tour-content">
<h2>First Year</h2>
<p class="article"><img src="<?php echo '/' . drupal_get_path('module', 'cls_mcl'); ?>/images/tour/first-year.jpg" class="float-right" height="370" width="370" />All first-year students begin their Law School journey with our distinctive Legal Methods course. First-year students arrive several weeks prior to the beginning of fall semester for an introduction to legal institutions, processes, and the professional use of case law and legislation.</p>
<p class="article">Legal Methods prepares you for the first year of law school&mdash;our Foundation Curriculum. At Columbia Law School, we believe the first year should be a time for expanding horizons, rather than one of stress and conformity; a time when students are encouraged to develop their understanding of how law works within a society. The Foundation Curriculum furnishes you with the fundamental tools that you will use throughout your legal career. The first-year courses include Legal Practice Workshop, Civil Procedure, Contracts, Torts, Moot Court, Constitutional Law, Criminal Law, and Property, in addition to the first-year elective options.</p>
<h4>Explore More</h4>
<?php echo drupal_render($form); ?>
<div class="actions-choices">
  <p><a class="skip-tour" href="<?php echo $mcl_home_url; ?>/experience/second-third-years">Jump to the next section</a></p>
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
