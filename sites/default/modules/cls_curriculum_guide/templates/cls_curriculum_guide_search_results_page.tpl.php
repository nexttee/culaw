<div class="search-results-container">
  <h2 class="search-results-text"><?php print $result_count_text; ?></h2>
  <?php if($result_count > 0): ?>
    <table id="results-table" class="results-table">
      <thead>
        <tr id="course-results-header" class="results-header">
          <th class="expand"></th>
          <th class="number-section">Number<br>&amp; Section</th>
          <th class="term">Term</th>
          <th class="name">Name</th>
          <th>
            <table class="inner">
              <thead>
                <tr>
                  <th class="instructors">Instructor(s)</th>
                  <th class="schedules">Schedule</th>
                  <th class="locations">Location</th>
                </tr>
              </thead>
            </table>
          </th>
          <th class="type">Type</th>
          <th class="points">Pts.</th>
        </tr>
      </thead>
      <tbody>
        <?php $row_count = 0; ?>
        <?php foreach($sections as $s): ?>
          <?php $row_count++; ?>
          <tr class="course-row <?php print ($row_count & 1) ? "odd" : "even"; ?>" data-id="<?php print $s['id']; ?>">
            <td class="expand"><a href="javascript:void(0)" class="description-toggle" data-id="<?php print $s['id']; ?>" data-toggle="course-result-<?php print $s['id']; ?>">+</a></td>
            <td class="number-section"><?php print $s['number_section']; ?></td>
            <td class="term"><?php print $s['term']; ?></td>
            <td class="name"><a href="/courses/sections/<?php print $s['id']; ?>"><?php print $s['name']; ?></a></td>
            <td>
              <table class="inner">
                <tbody>
                  <tr data-cid="<?php print $s['id']; ?>">
                    <td class="instructors"></td>
                    <td class="schedules"></td>
                    <td class="locations"></td>
                  </tr>
                </tbody>
              </table>
            </td>
            <td class="type"><?php print $s['type']; ?></td>
            <td class="points"><?php print $s['points']; ?></td>
          </tr>
          <tr id="course-result-<?php print $s['id']; ?>-expanded" class="<?php print ($row_count & 1) ? "odd" : "even"; ?> course-expanded">
            <td class="expand"></td>
            <td class="description" colspan="8"><div></div></td>
          </tr>
        <?php endforeach; ?>
      </tbody>
    </table>
  <?php endif; ?>
</div>
