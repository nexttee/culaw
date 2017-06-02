<div id="curriculum-guide-search-error"></div>
<div class="advanced-search">
  <form id="curriculum-guide-search-form" action="/courses/search-results" method="get">
    <div class="searching">
      <h2>Search and explore our course offerings</h2>

      <div class="row group clearfix">
        <div class="levels">
          <h3>Curriculum Levels</h3>
          <ul>
            <?php $count = 0; ?>
            <?php foreach($curriculum_levels as $level): ?>
              <li>
                <input type="radio" <?php print ($count == 0) ? 'checked' : '';?> name="curriculumType" id="<?php print $level['id']; ?>" value="<?php print $level['id']; ?>" />
                <label for="<?php print $level['id']; ?>"><?php print $level['name']; ?></label>
              </li>
              <?php $count++; ?>
            <?php endforeach; ?>
          </ul>
        </div>
        <div class="name">
          <h3><label for="coursename">Course Name</label></h3>
          <span><input type="text" value="" id="coursename" name="courseName" class="text-input course-name" /></span>
        </div>
        <div class="number">
          <h3><label for="coursenumber">Course Number</label></h3>
          <span><input type="text" value="" id="coursenumber" name="courseNumber" class="text-input course-number" /></span>
        </div>
        <div class="instructor">
          <h3><label for="instructor">Instructor</label></h3>
          <div class="select">
            <select id="instructor" name="instructorId">
              <option value="">Select an instructor</option>
              <?php foreach($instructors as $instructor): ?>
                <option value="<?php print $instructor['id']; ?>"><?php print $instructor['name']; ?></option>
              <?php endforeach; ?>
            </select>
          </div>
        </div>
      </div>

      <div class="row dashed-grey group clearfix">
        <div class="year-semester">
          <h3><label for="schoolyear">School Year and Semester</label></h3>
          <div class="select">
            <select id="schoolyear" name="schoolYear">
              <?php foreach($academic_years as $year): ?>
                <option value="<?php print $year['id']; ?>"><?php print $year['academicYear']; ?></option>
              <?php endforeach; ?>
              <option value="<?php print $search_any_year_string; ?>">Any</option>
            </select>
          </div>
          <ul>
            <li>
              <input type="checkbox" checked="checked" id="semesterfall" name="term" value="Fall" />
              <label for="semesterfall">Fall</label>
            </li>
            <li>
              <input type="checkbox" checked="checked" id="semesterspring" name="term" value="Spring" />
              <label for="semesterspring">Spring</label>
            </li>
          </ul>
        </div>
        <div class="schedule">
          <h3>Schedule</h3>
          <div class="select">
            <div class="weekdays">
              <?php foreach($weekdays as $day): ?>
                <input name="days" type="checkbox"  value="<?php print $day; ?>" id="<?php print $day; ?>" />
                <label for="<?php print $day; ?>"><?php print $day; ?></label>
              <?php endforeach; ?>
            </div>
            <div class="start-time">
              <label for="starttime">Start Time</label>
              <select name="startTime" id="starttime">
                <option value="">Any time</option>
                <?php foreach($hours as $key => $value): ?>
                  <option value="<?php print $key; ?>"><?php print $value; ?></option>
                <?php endforeach; ?>
              </select>
            </div>
            <div class="end-time">
              <label for="endtime">End Time</label>
              <select name="endTime" id="endtime">
                <option value="">Any time</option>
                <?php foreach($hours as $key => $value): ?>
                  <option value="<?php print $key; ?>"><?php print $value; ?></option>
                <?php endforeach; ?>
              </select>
            </div>
          </div>
        </div>
      </div>

      <div id="course-search-expanded-options">
        <div class="row dashed-grey group clearfix">
          <div class="types group clearfix">
            <h3>Course Types</h3>
            <ul>
              <?php foreach ($course_types as $type): ?>
                <li>
                  <input type="checkbox" id="<?php print $type['name']; ?>" name="courseType"  value="<?php print $type['id']; ?>" />
                  <label for="<?php print $type['name']; ?>"><?php print $type['name']; ?></label>
                </li>
              <?php endforeach; ?>
            </ul>
          </div>
          <div class="categories group clearfix">
            <h3>Course Categories</h3>
            <div class="description" id="category-checkbox-list">
              <ul class="two-columns">
                <?php foreach($categories as $cat): ?>
                  <li>
                    <input name="categoryId" type="checkbox" id="<?php print $cat['name']; ?>"  value="<?php print $cat['id']; ?>" />
                    <label for="<?php print $cat['name']; ?>"><?php print $cat['name']; ?></label>
                  </li>
                <?php endforeach; ?>
              </ul>
            </div>
          </div>
        </div>
        <div class="row dashed-grey group clearfix">
          <div class="group clearfix">
            <h3>Course Tags</h3>
            <div class="description" id="tag-checkbox-list">
              <ul class="two-columns">
                <?php foreach($tags as $tag): ?>
                  <li>
                    <input name="tagId" type="checkbox" id="<?php print $tag['name']; ?>"  value="<?php print $tag['id']; ?>" />
                    <label for="<?php print $tag['name']; ?>"><?php print $tag['name']; ?></label>
                  </li>
                <?php endforeach; ?>
              </ul>
            </div>
          </div>
        </div>
        <div class="row dashed-grey group clearfix">
          <div class="points">
            <h3><label for="points">Course Points</label></h3>
            <div class="select">
              <select id="points" name="points">
                <option value="">Any</option>
                  <?php foreach($points as $key => $value): ?>
                    <option value="<?php print $key; ?>"><?php print $value; ?></option>
                  <?php endforeach; ?>
              </select>
            </div>
          </div>
          <div class="method">
            <h3><label for="evalmethod">Method of Evaluation</label></h3>
            <div class="select">
              <select id="evalmethod" name="evalMethods">
                <option value="">Select a method</option>
                <?php foreach($evaluation_methods as $key => $value): ?>
                  <option value="<?php print $value; ?>"><?php print $value; ?></option>
                <?php endforeach; ?>
              </select>
            </div>
          </div>
          <div class="credit">
            <h3>J.D. Writing Credit</h3>
            <div class="description">
              <input type="checkbox" id="writingcredit" name="writingCredit" value="true"  />
              <label for="writingcredit">Yes</label>
            </div>
          </div>
        </div>
      </div>

      <div class="row dashed-grey">
        <div class="buttons">
          <div class="back-link"><a href="#" onclick="javascript:history.go(-1);">&lt; Go back</a></div>
          <div><input name="submit-query" type="submit" id="submit-query" value="Search" /></div>
          <div class="options">
            <div class="more"><a href="#" id="more-options">More search options</a></div>
            <div class="less"><a href="#" id="less-options">Fewer search options</a></div>
          </div>
        </div>
      </div>

    </div>
  </form>
</div>
