<?php

if ($_SESSION['mcl_tour']['pro_bono']===1) {
  $next_url = '/experience/second-third-years/pro-bono';
}
else {
  $next_url = '/experience/end';
}
  
?>
<div class="tour-content">
<h2>Journals</h2>
<p class="article"><img src="<?php echo '/' . drupal_get_path('module', 'cls_mcl'); ?>/images/tour/second-third-year-journals.jpg" class="float-right" height="370" width="370" />Working as a staff member for a law journal provides you with the opportunity to participate actively in the scholarship and commentary central to the American legal tradition. Columbia Law School is home to 14 law journals, including many of the leading scholarly publications in their respective fields. Law journal editors write and edit articles about critical legal issues and sometimes take on challenging and important projects, such as the recent re-examination of a capital punishment case conducted by the <em>Columbia Human Rights Law Review</em>.</p>
</p>
<p class="article">Other journals include: <em>Columbia Law Review</em>, <em>Columbia Journal of Race and Law</em>, <em>Columbia Journal of Law &amp; the Arts</em>, and <em>Columbia Business Law Review</em>.</p>
<div class="actions">
  <p><a href="<?php echo $mcl_home_url . $next_url; ?>" class="continue-with-the-tour">Continue with the tour</a></p>
  <p><a class="skip-tour" href="<?php echo $mcl_home_url; ?>/experience/end">Jump to the next section</a></p>
  <p><a class="skip-tour" href="<?php echo $mcl_home_url; ?>">Skip the rest of the tour</a></p>
</div>
</div>
