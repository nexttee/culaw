<div class="group clearfix courses-featured">
  <div id="course-spotlight-left" class="eightcol-alpha" style="background-color:<?php print $course_spotlight['bg_color']; ?>">
    <div class="table-wrapper">
      <table id="table-course-spotlight" border="0" cellspacing="0" cellpadding="0">
        <tbody>
          <tr>
            <td>
              <h4>Course spotlight on
                <a href="/courses/<?php print $course_spotlight['course_offering_number']; ?>"><?php print $course_spotlight['course_offering_number']; ?></a>
              </h4>
              <h3>
                <a href="/courses/<?php print $course_spotlight['course_offering_number']; ?>"><?php print $course_spotlight['name']; ?></a>
              </h3>
              <?php $instructor_count = count($course_spotlight['instructors']); ?>
              <?php if($instructor_count > 0): ?>
                <p class="faculty-list">
                  <?php $row_count = 0; ?>
                  <?php foreach($course_spotlight['instructors'] as $instructor): ?>
                    <?php $row_count++; ?>
                    <a href="/courses/instructors/<?php print $instructor['id']; ?>"><?php print $instructor['name']; ?></a><?php if ($row_count != $instructor_count) { ?>, <?php } ?>
                  <?php endforeach; ?>
                </p>
              <?php endif; ?>
              <?php if (strlen($course_spotlight['name']) <= 40): ?>
                <p><?php print $course_spotlight['description']['short']; ?> <?php print $course_spotlight['points']; ?></p>
              <?php endif; ?>
              <p><a href="/courses/<?php print $course_spotlight['course_offering_number']; ?>">Learn more about this course</a></p>
            </td>
          </tr>
        </tbody>
      </table>
    </div>
  </div>
  <div id="course-spotlight-right" class="eightcol-omega" style="background: url('<?php print $course_spotlight['image_url']; ?>') no-repeat;"></div>
</div>

<div class="group clearfix courses-home-bottom">
  <div class="eightcol">
    <?php if(count($related_offerings) > 0): ?>
      <h3 class="you-may-be-interested-in">You may also be interested in...</h3>
      <?php foreach ($related_offerings as $offering): ?>
        <div class="promoted-course">
          <div class="course-number-title">
            <h5>
              <a href="/courses/<?php print $offering['course_offering_number']; ?>"><?php print $offering['course_offering_number']; ?></a>
            </h5>
            <h4>
              <a href="/courses/<?php print $offering['course_offering_number']; ?>"><?php print $offering['name']; ?></a>
            </h4>
          </div>
          <div class="course-information">
            <?php $instructor_count = count($offering['instructors']); ?>
            <?php if($instructor_count > 0): ?>
              <p class="faculty-list">
                <?php $row_count = 0; ?>
                <?php foreach ($offering['instructors'] as $instructor): ?>
                  <?php $row_count++; ?>
                  <a href="/courses/instructors/<?php print $instructor['id']; ?>"><?php print $instructor['name']; ?></a><?php if ($row_count != $instructor_count) { ?>, <?php } ?>
                <?php endforeach; ?>
              </p>
            <?php endif; ?>
          </div>
        </div>
        <p class="learn-more"><?php print $offering['description']['short']; ?> <a href="/courses/<?php print $offering['course_offering_number']; ?>">Learn&nbsp;more</a></p>
      <?php endforeach; ?>
    <?php endif; ?>
  </div>
  <div class="eightcol-omega">
    <div class="group clearfix no-margin">
      <div class="fourcol promoted-functions">
        <h3 class="search-courses">Search Courses</h3>
        <div>
          <form method="get" action="/courses/search-results">
            <input name="keyword" type="text" id="search-compare-courses-input" value="Course name or number">
          </form>
        </div>
        <p><a href="/courses/search">Advanced Search</a></p>
      </div>
    </div>

  </div>
</div>
