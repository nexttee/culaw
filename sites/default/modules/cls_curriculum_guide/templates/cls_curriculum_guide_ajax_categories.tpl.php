<ul class="two-columns">
  <?php foreach($categories as $cat): ?>
    <li>
      <input name="categoryId" type="checkbox" id="<?php print $cat['name']; ?>"  value="<?php print $cat['id']; ?>" />
      <label for="<?php print $cat['name']; ?>"><?php print $cat['name']; ?></label>
    </li>
  <?php endforeach; ?>
</ul>
