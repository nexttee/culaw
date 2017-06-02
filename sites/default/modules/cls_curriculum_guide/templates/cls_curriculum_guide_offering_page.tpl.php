<h2 id="course-name" class="course-name"><?php print $offering['course_offering_number']; ?> <?php print $offering['name'];  ?></h2>
<div class="center-block course-view ninecol-alpha">
  <div class="right-main-column">
    <ul class="content-tools">
      <li>
        <!-- AddThis Button BEGIN -->
        <a class="addthis_button" href="http://www.addthis.com/bookmark.php?v=300&amp;pubid=ra-51b5374d23c2bf33">Share/email this course</a>
        <script type="text/javascript">var addthis_config = {"data_track_addressbar":true};</script>
        <script type="text/javascript" src="//s7.addthis.com/js/300/addthis_widget.js#pubid=ra-51b5374d23c2bf33"></script>
        <!-- AddThis Button END -->
      </li>
      <li><a onclick="window.print();return false;" href="#">Print</a></li>
    </ul>
    <div class="description"><p><?php print $offering['description']['long']; ?></p></div>
    <div class="course-classification">
      <div class="type"><em>Type:</em> <?php print $type; ?></div>
      <div class="level"><em>Level:</em> <?php print $level; ?></div>
      <div class="categories">
        <em>Categories:</em>
        <?php $category_count = count($categories); ?>
        <?php if ($category_count > 0): ?>
          <?php $row_count = 0; ?>
          <?php foreach ($categories as $category): ?>
            <?php $row_count++; ?>
            <a href="/courses/search-results?categoryId=<?php print $category['id']; ?>"><?php print $category['name']; ?></a><?php if ($row_count != $category_count) { ?>, <?php } ?>
          <?php endforeach; ?>
        <?php endif; ?>
      </div>
    </div>
  </div>
  <div class="section-listing">
    <div class="heading">
      <div class="change-year-container">
        <a href="javascript:void(0)" class="change-semester" id="change-semester-link">Change year</a>
        <select name="schoolYear" id="change-school-year">
          <?php foreach ($academic_years as $year): ?>
            <option value="<?php print $year['id']; ?>"><?php print $year['academicYear']; ?></option>
          <?php endforeach; ?>
        </select>
      </div>
      <h3>Section Offerings for <strong><?php print $academic_years[0]['academicYear']; ?></strong></h3>
    </div>
    <div id="sections-ajax-container">
      <?php print theme('cls_curriculum_guide_offering_ajax_sections', array('sections' => $sections)); ?>
    </div>
  </div>
</div>
<div class="right-small-column threecol-omega" style="margin: 0;">
  <?php if(count($offering['instructors']) > 0): ?>
    <div class="box grey related-faculty">
      <h3>Instructor(s)</h3>
      <?php foreach ($offering['instructors'] as $instructor): ?>
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
  <?php endif; ?>
</div>
