<?php

if ($_SESSION['mcl_tour']['nyc']===1) {
  $next_url = '/tour/student-life/nyc';
}
else if ($_SESSION['mcl_tour']['alumni']===1) {
  $next_url = '/tour/student-life/alumni';
}
else {
  $next_url = '/tour/thanks';
}
  
?>
<div class="tour-content">
<h2>Student Organizations</h2>
<p class="article"><img src="<?php echo '/' . drupal_get_path('module', 'cls_mcl'); ?>/images/tour_llm/12-organizations.jpg" class="float-right" height="370" width="370" />Student organizations enrich the Law School experience by connecting classmates with peers who share similar interests and facilitating the opportunity for them to work together on exciting projects. Most of our LL.M. students are active in at least one of our more than 85 student organizations. The groups range from professional interest societies to social clubs.</p>
<p class="article">LL.M. students have helped found several student organizations, including the Columbia Latin American Business Law Association, the&nbsp;Columbia International Arbitration Association, and the Columbia International Antitrust Association. LL.M.s also regularly serve as officers&nbsp;of these and other organizations.</p>
<div class="actions">
  <p><a href="<?php echo $mcl_home_url . $next_url; ?>" class="continue-with-the-tour">Continue with the tour</a></p>
  <p><a class="skip-tour" href="<?php echo $mcl_home_url; ?>/tour/thanks">Jump to the next section</a></p>
  <p><a class="skip-tour" href="<?php echo $mcl_home_url; ?>">Skip the rest of the tour</a></p>
</div>
</div>