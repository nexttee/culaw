<?php

if ($_SESSION['mcl_tour']['clinics']===1) {
  $next_url = '/experience/second-third-years/clinics-externships';
}
else if ($_SESSION['mcl_tour']['journals']===1) {
  $next_url = '/experience/second-third-years/journals';
}
else if ($_SESSION['mcl_tour']['pro_bono']===1) {
  $next_url = '/experience/second-third-years/pro-bono';
}
else {
  $next_url = '/experience/end';
}
  
?>
<div class="tour-content">
<h2>Centers and Programs</h2>
<p class="introduction"><img src="<?php echo '/' . drupal_get_path('module', 'cls_mcl'); ?>/images/tour/second-third-year-centers.jpg" class="float-right" height="370" width="370" />The centers and programs at the Law School conduct innovative legal scholarship on important issues, both on campus and around the world.</p>
<p class="introduction">The Law School&rsquo;s centers and programs include: the Center for Chinese Legal Studies, the Center for Climate Change Law, the Center for Gender &amp; Sexuality Law, the Center for Law and Economic Studies, the Human Rights Institute, the Kernochan Center for Law, Media and the Arts, the Roger Hertog Program on Law and National Security, and Social Justice Initiatives.</p>
<div class="actions">
  <p><a href="<?php echo $mcl_home_url . $next_url; ?>" class="continue-with-the-tour">Continue with the tour</a></p>
  <p><a class="skip-tour" href="<?php echo $mcl_home_url; ?>/experience/end">Jump to the next section</a></p>
  <p><a class="skip-tour" href="<?php echo $mcl_home_url; ?>">Skip the rest of the tour</a></p>
</div>
</div>
