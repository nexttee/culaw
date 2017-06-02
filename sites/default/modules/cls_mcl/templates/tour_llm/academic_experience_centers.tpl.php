<?php

if ($_SESSION['mcl_tour']['clinics']===1) {
  $next_url = '/tour/academic-experience/clinics-externships';
}
else if ($_SESSION['mcl_tour']['journals']===1) {
  $next_url = '/tour/academic-experience/journals';
}
else if ($_SESSION['mcl_tour']['pro_bono']===1) {
  $next_url = '/tour/academic-experience/pro-bono';
}
else {
  $next_url = '/tour/student-life';
}
  
?>
<div class="tour-content">
<h2>Centers and Programs</h2>
<p class="introduction"><img src="<?php echo '/' . drupal_get_path('module', 'cls_mcl'); ?>/images/tour_llm/7-centers-programs.jpg" class="float-right" height="370" width="370" />The Law School’s centers and programs conduct innovative legal scholarship on issues of importance, both on campus and around the world.</p>
<p class="introduction">The Law School's centers and programs include:</p>
<ul class="article"> 
	<li>Center for Chinese Legal Studies</li>
	<li>Sabin Center for Climate Change Law</li>
	<li>Center for Gender &#38; Sexuality Law</li>
	<li>Center for Law and Economic Studies</li>
	<li>Human Rights Institute</li>
	<li>Kernochan Center for Law, Media, and the Arts</li>
	<li>Roger Hertog Program on Law and National Security</li>
	<li>Center for International Commercial and Investment Arbitration</li>
	<li>Center for Public Research and Leadership</li>
	<li>Center for the Advancement of Public Integrity</li>
	<li>Center on Corporate Governance</li>
	<li>Columbia Center on Sustainable International Investment</li>
	<li>Program on the Law and Economics of Capital Markets</li>
	<li>Social Justice Initiatives</li>
</ul>

<div class="actions">
  <p><a href="<?php echo $mcl_home_url . $next_url; ?>" class="continue-with-the-tour">Continue with the tour</a></p>
  <p><a class="skip-tour" href="<?php echo $mcl_home_url; ?>/tour/student-life">Jump to the next section</a></p>
  <p><a class="skip-tour" href="<?php echo $mcl_home_url; ?>">Skip the rest of the tour</a></p>
</div>
</div>
