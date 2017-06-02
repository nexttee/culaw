<option value="">Select an instructor</option>
<?php foreach($instructors as $instructor): ?>
  <option value="<?php print $instructor['id']; ?>"><?php print $instructor['name']; ?></option>
<?php endforeach; ?>
