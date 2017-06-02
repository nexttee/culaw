<div class="box blue">
  <div class="nav-search-result-criteria">
    <h3><a href="/courses/search">Search Result Criteria</a></h3>
    <ul>
      <?php if($year) { ?><li>Academic Year: <em><?php print implode(", ", $year); ?></em></li><?php } ?>
      <?php if($level) { ?><li>Levels: <em><?php print $level; ?></em></li><?php } ?>
      <?php if($course_name) { ?><li>Course Name: <em><?php print $course_name; ?></em></li><?php } ?>
      <?php if($course_number) { ?><li>Course Number: <em><?php print $course_number; ?></em></li><?php } ?>
      <?php if($instructors) { ?><li>Instructor: <em><?php print implode("<br>", $instructors); ?></em></li><?php } ?>
      <?php if($term) { ?><li>Term: <em><?php print implode(", ", $term); ?></em></li><?php } ?>
      <?php if($days) { ?><li>Days: <em><?php print implode(", ", $days); ?></em></li><?php } ?>
      <?php if($start_time) { ?><li>Start Time: <em><?php print $start_time; ?></em></li><?php } ?>
      <?php if($end_time) { ?><li>End Time: <em><?php print $end_time; ?></em></li><?php } ?>
      <?php if($types) { ?><li>Course Types: <em><?php print implode(", ", $types); ?></em></li><?php } ?>
      <?php if($categories) { ?><li>Course Categories: <em><?php print implode(", ", $categories); ?></em></li><?php } ?>
      <?php if($tags) { ?><li>Course Tags: <em><?php print implode(", ", $tags); ?></em></li><?php } ?>
      <?php if($points) { ?><li>Points: <em><?php print $points; ?></em></li><?php } ?>
      <?php if($method) { ?><li>Method of Evaluation:: <em><?php print $method; ?></em></li><?php } ?>
      <?php if($writing_credit) { ?><li>J.D. Writing Credit: <em>Yes</em></li><?php } ?>
    </ul>
  </div>
</div>
<div class="box light-grey">
  <div class="nav-download">
    <?php if($download_path): ?>
      <h3><a href="<?php print $download_path; ?>">Download</a></h3>
    <?php endif; ?>
  </div>
</div>
<div class="back-link"><a href="/courses/search">&lt; Go back and search again</a></div>
