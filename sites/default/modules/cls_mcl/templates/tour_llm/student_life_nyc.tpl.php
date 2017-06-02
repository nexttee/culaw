<?php

if ($_SESSION['mcl_tour']['alumni']===1) {
  $next_url = '/tour/student-life/alumni';
}
else {
  $next_url = '/tour/thanks';
}

?>
<div class="tour-content">
<h2>New York City and Morningside Heights</h2>
<p class="article"><img src="<?php echo '/' . drupal_get_path('module', 'cls_mcl'); ?>/images/tour_llm/13-nyc.jpg" class="float-right" height="370" width="370" />It is not a coincidence that the university’s full name is Columbia University in the City of New York. The city’s pulse is interwoven in a Columbia education, and Columbia holds a central and influential position in New York life. As an LL.M. student, you will be living in a world center of law practice, along with the world capital of publishing, international finance, culture, the arts, and communications.</p>
<p class="article">Columbia students and faculty highly value the diversity, the pace, and the safety of Morningside Heights, the surrounding community nestled between the Upper West Side and Harlem neighborhoods.  In reality, it is a vibrant, close-knit community within an international capital.</p>
<div class="actions">
  <p><a href="<?php echo $mcl_home_url . $next_url; ?>" class="continue-with-the-tour">Continue with the tour</a></p>
  <p><a class="skip-tour" href="<?php echo $mcl_home_url; ?>/tour/thanks">Jump to the next section</a></p>
  <p><a class="skip-tour" href="<?php echo $mcl_home_url; ?>">Skip the rest of the tour</a></p>
</div>
</div>
