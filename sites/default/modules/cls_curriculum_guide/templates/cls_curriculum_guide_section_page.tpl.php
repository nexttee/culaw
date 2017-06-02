<h2 id="course-section-name" class="course-name"><?php print $course_number; ?> <?php print $name; ?></h2>
<p class="course-section-label">Section <?php print $section; ?>, <?php print $semester; ?></p>

<div class="center-block course-view ninecol-alpha">
  <div class="right-main-column">
    <ul class="content-tools">
      <li>
        <!-- AddThis Button BEGIN -->
        <a class="addthis_button" href="http://www.addthis.com/bookmark.php?v=300&amp;pubid=ra-51b5374d23c2bf33">Share/email this section</a>
        <script type="text/javascript">var addthis_config = {"data_track_addressbar":true};</script>
        <script type="text/javascript" src="//s7.addthis.com/js/300/addthis_widget.js#pubid=ra-51b5374d23c2bf33"></script>
        <!-- AddThis Button END -->
      </li>
      <li><a onclick="window.print();return false;" href="#">Print</a></li>
    </ul>
    <div class="section-information">
      <h3>Section Information</h3>
      <div class="section-description">
        <h4>Section Description Provided by Instructor</h4>
        <p><?php print $description; ?></p>
      </div>
      <div class="row">
        <p class="part1"><em>Semester</em><br><?php print $semester ?></p>
        <p class="part2"><em>Section</em><br><?php print $section; ?></p>
        <p class="part3"><em>Schedule</em><br><?php print implode("<br>", $schedules); ?></p>
        <p class="part4"><em>Location</em><br><?php print implode("<br>", $locations); ?></p>
      </div>
      <div class="row">
        <p class="part1"><em>Points</em><br><?php print $points; ?></p>
        <p class="part3"><em>Method of Evaluation</em><br><?php print $method; ?></p>
        <p class="part4"><em>J.D. Writing Credit</em><br><?php print $jd_writing_credit_description; ?></p>
      </div>
      <div class="row">
        <p>
          <a rel="nofollow" target="_blank" href="<?php print $textbook_url; ?>">View textbooks</a>
        </p>
      </div>
    </div>
    <div class="course-limitations">
      <h3>Course Limitations</h3>
      <div class="row">
        <p><em>Instructor Pre-requisites</em><br><?php print $instructor_prerequistes; ?></p>
        <p><em>Instructor Co-requisites</em><br><?php print $instructor_corequisites; ?></p>
        <p><em>Recommended Courses</em><br><?php print $recommended_courses; ?></p>
      </div>
      <div class="row">
        <p><em>Other Limitations</em><br><?php print $registration_limitations; ?></p>
      </div>
    </div>
    <div class="general-information section-goals">
      <h3>Learning Outcome Goals</h3>
      <?php if(count($goals['primary']) > 0 || count($goals['secondary']) > 0): ?>
        <?php if (count($goals['primary']) > 0): ?>
          <div id="primary-goals">
            <p>Primary Goals</p>
            <ul>
              <?php foreach($goals['primary'] as $goal): ?>
                <li><?php echo $goal; ?></li>
              <?php endforeach; ?>
            </ul>
          </div>
          <p><a id="primary-goals-link" href="javascript:void(0)">Show primary goals provided by instructor</a></p>
        <?php endif; ?>
        <?php if (count($goals['secondary']) > 0): ?>
          <div id="secondary-goals">
            <p>Secondary Goals</p>
            <ul>
              <?php foreach ($goals['secondary'] as $goal): ?>
                <li><?php print $goal; ?></li>
              <?php endforeach; ?>
            </ul>
          </div>
          <p><a id="secondary-goals-link" href="javascript:void(0)">Show secondary goals provided by instructor</a></p>
        <?php endif; ?>
      <?php else: ?>
        <p class="no-goals">No learning outcome goals have been provided.</p>
      <?php endif; ?>
    </div>
    <div class="general-information">
      <h3>General Information</h3>
    </div>
    <div class="course-classification">
      <div class="type"><em>Type:</em> <?php print $course_type; ?></div>
      <div class="level"><em>Level:</em> <?php print $level; ?></div>
      <div class="categories">
        <em>Categories:</em>
        <?php $category_count = count($categories); ?>
        <?php if($category_count > 0): ?>
          <?php $row_count = 0; ?>
          <?php foreach($categories as $category): ?>
            <?php $row_count++; ?>
            <a href="/courses/search-results?categoryId=<?php print $category['id']; ?>"><?php print $category['name']; ?></a><?php if ($row_count != $category_count) { ?>, <?php } ?>
          <?php endforeach; ?>
        <?php endif; ?>
      </div>
    </div>
  </div>
</div>

<div class="right-small-column threecol-omega">
    <div class="box grey related-faculty">
      <h3>Instructor(s)</h3>
      <?php foreach($instructors as $instructor): ?>
        <div class="person-block clearfix">
          <?php if ($instructor['photo_url'] != ''): ?>
            <a href="/courses/instructors/<?php print $instructor['id']; ?>"><img width="68" height="91" align="right" src="<?php echo $instructor['photo_url']; ?>"></a>
          <?php endif; ?>
          <p>
            <a href="/courses/instructors/<?php print $instructor['id']; ?>"><?php print $instructor['full_name']; ?></a>
          </p>
        </div>
      <?php endforeach; ?>
    </div>
    <?php if (count($other_sections) > 0): ?>
      <div class="box grey other-sections">
        <h3>Other Sections</h3>
        <?php foreach ($other_sections as $section): ?>
          <p>
            <a href="/courses/sections/<?php print $section['id']; ?>"><?php print $section['section_semester']; ?></a>
            <br>
            <?php print implode("<br>", $section['schedules']); ?>
            <br>
            <?php foreach($section['instructors'] as $instructor): ?>
              <?php print $instructor['name'] . "<br>"; ?>
            <?php endforeach; ?>
          </p>
        <?php endforeach; ?>
      </div>
    <?php endif; ?>
</div>
