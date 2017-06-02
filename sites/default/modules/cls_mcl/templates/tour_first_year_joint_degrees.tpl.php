<?php

if ($_SESSION['mcl_tour']['moot_court']===1) {
  $next_url = '/experience/first-year/moot-court';
}
else if ($_SESSION['mcl_tour']['student_orgs']===1) {
  $next_url = '/experience/first-year/student-orgs';
}
else {
  $next_url = '/experience/second-third-years';
}

?>
<div class="tour-content">
<h2>Joint Degrees</h2>
<p class="introduction"><img src="<?php echo '/' . drupal_get_path('module', 'cls_mcl'); ?>/images/tour/first-year-joint-degrees.jpg" class="float-right" height="370" width="370" />One of the many advantages of being a Columbia Law School student is participation in the life of an eminent university. We invite you to explore the many options available for those who wish to pursue a dual degree while attending Columbia Law School.</p>
<p class="introduction">Students interested in studying at other schools within Columbia University outside the context of pursing a joint degree may apply up to 12 credits of non&ndash;Law School coursework directly to their J.D. degree requirements.</p>
<div class="actions">
  <p><a href="<?php echo $mcl_home_url . $next_url; ?>" class="continue-with-the-tour">Continue with the tour</a></p>
  <p><a class="skip-tour" href="<?php echo $mcl_home_url; ?>/experience/second-third-years">Jump to the next section</a></p>
  <p><a class="skip-tour" href="<?php echo $mcl_home_url; ?>">Skip the rest of the tour</a></p>
</div>
</div>
