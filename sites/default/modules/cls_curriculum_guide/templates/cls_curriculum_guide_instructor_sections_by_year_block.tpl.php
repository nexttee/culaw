<div class="box blue">
  <div class="nav-browse-by-year">
    <h3><img class="browse-year" src="/sites/all/themes/custom/cls/images/browse-year.png" /></h3>
    <select id="browseSchoolYear" name="browseSchoolYear">
      <?php foreach($academic_years as $year): ?>
        <option value="<?php print $year['id']; ?>"><?php print $year['academicYear']; ?></option>
      <?php endforeach; ?>
    </select>
  </div>
</div>
