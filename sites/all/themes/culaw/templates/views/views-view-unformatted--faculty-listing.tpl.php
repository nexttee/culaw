<?php

/**
* @file
* Default simple view template to display a list of rows.
*
* @ingroup views_templates
*/

// kpr($view->result[0]->uid); die();
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php foreach ($rows as $id => $row): ?>
  <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?> data-id="<?php print $view->result[$id]->uid; ?>">
    <?php print $row; ?>
  </div>
<?php endforeach; ?>
