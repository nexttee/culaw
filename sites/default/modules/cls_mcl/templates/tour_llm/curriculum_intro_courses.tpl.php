<?php

if ($_SESSION['mcl_tour']['cross_reg']===1) {
  $next_url = '/tour/curriculum/cross-registration';
}
else {
  $next_url = '/tour/academic-experience';
}
  
?>
<div class="tour-content">
<h2>Introductory Courses</h2>
<p class="article"><img src="<?php echo '/' . drupal_get_path('module', 'cls_mcl'); ?>/images/tour_llm/3-introductory-courses.jpg" class="float-right" height="370" width="370" />In August, before the start of regular classes, LL.M. students begin their program of study with our Introduction to American Law (IAL) and Legal Research and Writing (LRW) courses.  These courses are designed to introduce you to common law methodology and basic concepts in American legal thought and practice.</p>
<p class="article">IAL offers a selective overview of the Law School’s first-year curriculum through close reading and critical discussion of cases in civil and criminal procedure and constitutional, criminal, and private law. LRW helps you strengthen the fundamental research, writing, and analytical skills you use in legal practice.</p>
<div class="actions">
  <p><a href="<?php echo $mcl_home_url . $next_url; ?>" class="continue-with-the-tour">Continue with the tour</a></p>
  <p><a class="skip-tour" href="<?php echo $mcl_home_url; ?>/tour/academic-experience">Jump to the next section</a></p>
  <p><a class="skip-tour" href="<?php echo $mcl_home_url; ?>">Skip the rest of the tour</a></p>
</div>
</div>