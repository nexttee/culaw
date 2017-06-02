<?php

if ($_SESSION['mcl_tour']['pro_bono']===1) {
  $next_url = '/tour/academic-experience/pro-bono';
}
else {
  $next_url = '/tour/student-life';
}
  
?>
<div class="tour-content">
<h2>Journals</h2>
<p class="article"><img src="<?php echo '/' . drupal_get_path('module', 'cls_mcl'); ?>/images/tour_llm/9-journals.jpg" class="float-right" height="370" width="370" />As a staff member for a law journal, you have the opportunity to participate actively in the scholarship and commentary central to the American legal tradition. Columbia Law School is home to 14 student law journals, including many of the leading scholarly publications in their respective fields. Law journal editors write and edit articles about critical legal issues and, at times, take on challenging and important projects, such as the recent reexamination of a capital punishment case conducted by the <em>Columbia Human Rights Law Review</em>.</p>
</p>
<p class="article">Other journals include: <em>Columbia Journal of Transnational Law</em>, <em>The American Review of International Arbitration</em>, <em>Columbia Journal of European Law, Columbia Journal of Environmental Law</em>, and <em>Columbia Business Law Review</em>.</p>
<div class="actions">
  <p><a href="<?php echo $mcl_home_url . $next_url; ?>" class="continue-with-the-tour">Continue with the tour</a></p>
  <p><a class="skip-tour" href="<?php echo $mcl_home_url; ?>/tour/student-life">Jump to the next section</a></p>
  <p><a class="skip-tour" href="<?php echo $mcl_home_url; ?>">Skip the rest of the tour</a></p>
</div>
</div>