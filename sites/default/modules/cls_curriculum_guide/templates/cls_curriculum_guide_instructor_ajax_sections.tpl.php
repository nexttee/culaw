<?php if(count($sections) > 0): ?>
  <?php foreach ($sections as $array): ?>
    <div class="row group clearfix">
      <?php foreach ($array as $section): ?>
        <div class="course-abstract">
          <h4><a href="/courses/sections/<?php print $section['id']; ?>"><?php print $section['course_number']; ?> <?php print $section['section']; ?> <?php print $section['semester']; ?></a></h4>
          <h5><a href="/courses/sections/<?php print $section['id']; ?>"><?php print $section['name']; ?></a></h5>
          <?php if(count($section['instructors']) > 0): ?>
            <p class="faculty-list">
              <?php $count = 0; ?>
              <?php foreach($section['instructors'] as $instructor): ?>
                <?php $count++; ?>
                <a href="/courses/instructors/<?php print $instructor['id']; ?>"><?php print $instructor['name']; ?></a><?php if ($count != count($section['instructors'])) { ?>, <?php } ?>
              <?php endforeach; ?>
            </p>
          <?php endif; ?>
          <?php if($section['description'] != ''): ?>
            <p><?php print $section['description']; ?> (<?php print $section['points']; ?>)</p>
          <?php endif; ?>
          <p><a href="/courses/sections/<?php print $section['id']?>";>Learn more</a></p>
        </div>
      <?php endforeach; ?>
    </div>
  <?php endforeach; ?>
<?php else: ?>
  <p>No Courses Found</p>
<?php endif; ?>
