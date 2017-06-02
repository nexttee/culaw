<?php

if ($_SESSION['mcl_tour']['intro_courses']===1) {
  $next_url = '/tour/curriculum/introductory-courses';
}
else if ($_SESSION['mcl_tour']['cross_reg']===1) {
  $next_url = '/tour/curriculum/cross-registration';
}
else {
  $next_url = '/tour/academic-experience';
}

?>
<div class="tour-content">
<h2>Program of Study</h2>
<p class="introduction"><img src="<?php echo '/' . drupal_get_path('module', 'cls_mcl'); ?>/images/tour_llm/4-course-of-study.jpg" class="float-right" height="370" width="370" />We offer a general LL.M. degree. Our LL.M. students have a&nbsp;great deal of freedom to select their courses from our incredibly broad and deep curriculum. Your academic experience can include a wide variety of subjects or have a more narrow focus.</p><p class="introduction">We help you design an individual program of study to meet your academic and professional goals, which can include broadening your general preparation, specializing in a particular field, or acquiring knowledge of the American legal system, international law, or other legal systems.</p>
<div class="actions">
  <p><a href="<?php echo $mcl_home_url . $next_url; ?>" class="continue-with-the-tour">Continue with the tour</a></p>
  <p><a class="skip-tour" href="<?php echo $mcl_home_url; ?>/tour/academic-experience">Jump to the next section</a></p>
  <p><a class="skip-tour" href="<?php echo $mcl_home_url; ?>">Skip the rest of the tour</a></p>
</div>
</div>
