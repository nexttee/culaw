<?php

if ($_SESSION['mcl_tour']['journals']===1) {
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
<h2>Clinics and Externships</h2>
<p class="article"><img src="<?php echo '/' . drupal_get_path('module', 'cls_mcl'); ?>/images/tour/second-third-year-clinics.jpg" class="float-right" height="370" width="370" />The clinical experience allows you to tackle legal problems faced by real clients, under the supervision of a professor. These opportunities allow students to see the law in context and to begin the lifelong process of becoming thoughtful, responsible, and reflective lawyers. Columbia Law School&rsquo;s clinics focus on issues related to child advocacy and adolescent representation, environmental law, human rights, the consequences of mass incarceration, prisoners and families, lawyering in the digital age, mediation, community enterprise, sexuality and gender law, and immigrants&rsquo; rights.</p>
<p class="article">Externships also allow students to gain real-world experience. At Columbia Law School, an externship consists of a seminar and a field experience at a non-governmental organization or government office that is closely related to the seminar. Adjunct professors who are leading legal practitioners teach the seminars and host many of the field placements. Externship opportunities include work at the United Nations, a number of federal agencies, the Bronx Defenders, and a multitude of public interest law organizations.</p>
<div class="actions">
  <p><a href="<?php echo $mcl_home_url . $next_url; ?>" class="continue-with-the-tour">Continue with the tour</a></p>
  <p><a class="skip-tour" href="<?php echo $mcl_home_url; ?>/experience/end">Jump to the next section</a></p>
  <p><a class="skip-tour" href="<?php echo $mcl_home_url; ?>">Skip the rest of the tour</a></p>
</div>
</div>
