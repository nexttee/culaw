<?php

if ($_SESSION['mcl_tour']['joint_degrees']===1) {
  $next_url = '/experience/first-year/joint-degrees';
}
else if ($_SESSION['mcl_tour']['moot_court']===1) {
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
<h2>First-year Electives</h2>
<p class="introduction"><img src="<?php echo '/' . drupal_get_path('module', 'cls_mcl'); ?>/images/tour/first-year-electives.jpg" class="float-right" height="370" width="370" />The first-year elective course offerings provide you with the opportunity to explore the breadth and depth of our curriculum. Some examples include: Law and Contemporary Society, Legislation and Regulation, The United States and the International Legal System, International Law, Antitrust and Trade Regulation, Lawyering for Change</p>
<div class="actions">
  <p><a href="<?php echo $mcl_home_url . $next_url; ?>" class="continue-with-the-tour">Continue with the tour</a></p>
  <p><a class="skip-tour" href="<?php echo $mcl_home_url; ?>/experience/second-third-years">Jump to the next section</a></p>
  <p><a class="skip-tour" href="<?php echo $mcl_home_url; ?>">Skip the rest of the tour</a></p>
</div>
</div>
