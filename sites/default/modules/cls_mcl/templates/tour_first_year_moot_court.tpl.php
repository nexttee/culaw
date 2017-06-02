<?php

if ($_SESSION['mcl_tour']['student_orgs']===1) {
  $next_url = '/experience/first-year/student-orgs';
}
else {
  $next_url = '/experience/second-third-years';
}
  
?>
<div class="tour-content">
<h2>Moot Court</h2>
<p class="introduction"><img src="<?php echo '/' . drupal_get_path('module', 'cls_mcl'); ?>/images/tour/first-year-moot-court.jpg" class="float-right" height="370" width="370" />In Moot Court, students combine legal research with oral advocacy by arguing cases before a panel of judges. For most first-year students, Moot Court is a formative part of their Law School experience, representing the first practical exposure to the dynamics of a courtroom. The Paul, Weiss, Rifkind, Wharton &amp; Garrison Moot Court Program consists of the first-year Foundation Program, the Harlan Fiske Stone Moot Court Honors Competition, and other national competitions.</p>
<p class="introduction">First-year students are required to participate in Foundation Moot Court, although participation in other national competition offerings may satisfy the Moot Court requirement.</p>
<div class="actions">
  <p><a href="<?php echo $mcl_home_url . $next_url; ?>" class="continue-with-the-tour">Continue with the tour</a></p>
  <p><a class="skip-tour" href="<?php echo $mcl_home_url; ?>/experience/second-third-years">Jump to the next section</a></p>
  <p><a class="skip-tour" href="<?php echo $mcl_home_url; ?>">Skip the rest of the tour</a></p>
</div>
</div>
