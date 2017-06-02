<div class="browse-courses">
  <div class="subject-information">
    <?php if ($photo_url != ''): ?>
      <a href="<?php print $profile_url; ?>"><img width="68" height="91" align="right" src="<?php print $photo_url; ?>"></a>
    <?php endif; ?>
    <h2><?php print $name; ?></h2>
    <p><em><?php print $title; ?></em></p>
    <?php if ($profile_url != ''): ?>
      <p><a href="<?php print $profile_url; ?>">View profile and contact information</a></p>
    <?php endif; ?>
  </div>
  <div class="browse-type dashed-grey">
    <div id="instructor-sections-container">
      <?php print theme('cls_curriculum_guide_instructor_ajax_sections', array('sections' => $sections)); ?>
    </div>
  </div>
</div>
