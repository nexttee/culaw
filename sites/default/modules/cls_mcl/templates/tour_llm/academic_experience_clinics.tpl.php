<?php

if ($_SESSION['mcl_tour']['journals']===1) {
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
<h2>Clinics and Externships</h2>
<p class="article"><img src="<?php echo '/' . drupal_get_path('module', 'cls_mcl'); ?>/images/tour_llm/8-clinics-externships.jpg" class="float-right" height="370" width="370" />Clinics enable you to experience the law in context by working with real clients under a professor&rsquo;s supervision and further the lifelong process of becoming a thoughtful, responsible, and reflective lawyer.  Columbia&rsquo;s clinics focus on issues ranging from environmental law, mediation, and sexuality and gender law to human rights, lawyering in the digital age, and child advocacy.</p>
<p class="article">Externships consist of both a seminar and closely related field placement&nbsp;at a nongovernmental organization or government office. Adjunct professors, who are also leading legal practitioners, teach the seminars and host many of the placements. Externship opportunities include working at the United Nations, the Bronx Defenders, and a broad range of other public interest organizations whose work includes such areas as immigration, domestic violence, and arts law.</p>
<div class="actions">
  <p><a href="<?php echo $mcl_home_url . $next_url; ?>" class="continue-with-the-tour">Continue with the tour</a></p>
  <p><a class="skip-tour" href="<?php echo $mcl_home_url; ?>/tour/student-life">Jump to the next section</a></p>
  <p><a class="skip-tour" href="<?php echo $mcl_home_url; ?>">Skip the rest of the tour</a></p>
</div>
</div>
