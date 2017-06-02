<?php if(!empty($sections)): ?>
  <table cellspacing="0" cellpadding="0" border="0" class="results-table">
    <tbody>
      <tr class="top group-top">
        <td valign="bottom" class="number-section">Course No.</td>
        <td valign="bottom" class="term">Term</td>
        <td valign="bottom" class="name" colspan="3">Name</td>
      </tr>
      <tr class="top group-bottom">
        <td valign="bottom" class="number-section">&amp; Section</td>
        <td valign="bottom" class="term"></td>
        <td valign="bottom" class="instructors">Instructor(s)</td>
        <td valign="bottom" class="schedules">Schedule</td>
        <td valign="bottom" class="location">Location</td>
      </tr>
      <?php $row_count = 0; ?>
      <?php foreach($sections as $section): ?>
        <?php $row_count++; ?>
        <tr class="<?php print ($row_count & 1) ? "odd" : "even"; ?> group-top">
          <td valign="top" class="number-section">
            <a href="/courses/sections/<?php print $section['id']; ?>"><?php print $section['number_section']; ?></a>
          </td>
          <td valign="top" class="term"><?php print $section['term']; ?></td>
          <td valign="top" colspan="3" class="name">
            <a href="/courses/sections/<?php print $section['id']; ?>"><?php echo $section['name']; ?></a>
          </td>
        </tr>
        <tr class="<?php print ( $row_count & 1) ? "odd" : "even"; ?> group-bottom">
          <td class="number-section"></td>
          <td class="term"></td>
          <td valign="top" class="instructors">
            <?php $instructor_count = count($section['instructors']); ?>
            <?php $count = 0; ?>
            <?php foreach($section['instructors'] as $instructor): ?>
              <?php $count++; ?>
              <?php print $instructor['name']; ?><?php if ($count != $instructor_count) { ?>, <?php } ?>
            <?php endforeach; ?>
          </td>
          <td valign="top" class="schedules"><?php print implode(", ", $section['schedules']); ?></td>
          <td valign="top" class="location"><?php print implode(", ", $section['locations']); ?></td>
        </tr>
      <?php endforeach; ?>
    </tbody>
  </table>
  <div class="choose-a-section-instructions">
    <p>Choose a section for more information, including section descriptions, faculty, course limitations, syllabi, evaluations, points, writing credit eligibility, evaluation methods, textbooks, and learning outcome goals.</p>
  </div>
<?php else: ?>
  <p>No sections offered.</p>
<?php endif; ?>
