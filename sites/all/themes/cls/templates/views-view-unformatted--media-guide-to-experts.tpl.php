<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */

?>
<div class="panel panel-default">
  <?php if (!empty($title)): ?>
    <div class="panel-heading">
      <h4 class="panel-title">
        <a data-toggle="collapse" href="#<?php print str_replace(' ', '-', $title); ?>"><?php print $title; ?></a>
      </h4>
    </div>
  <?php endif; ?>
  <div class="panel-collapse collapse" id="<?php print str_replace(' ', '-', $title); ?>">
    <?php foreach ($rows as $id => $row): ?>
      <div class="panel-body">
        <?php print $row; ?>
      </div>
    <?php endforeach; ?>
  </div>
</div>
