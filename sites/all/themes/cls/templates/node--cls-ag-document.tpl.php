<?php

// $Id: node.tpl.php 1116 2011-06-21 06:47:07Z cstuck $

/**
 * @file
 * Default theme implementation for displaying nodes.
 */
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>" data-referer="<?php print $_SERVER['HTTP_REFERER']; ?>">

  <div class="node-inner">

    <?php if (!$page): ?>
      <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print (isset($node_title) ? $node_title : $title); ?></a></h2>
    <?php endif; ?>

    <?php print $user_picture; ?>

    <?php if ($display_submitted): ?>
      <span class="submitted"><?php print $date; ?> — <?php print $name; ?></span>
    <?php endif; ?>

    <div class="content">
      <?php
        // We hide the comments and links now so that we can render them later.
        hide($content['comments']);
        hide($content['links']);
        // if($view_mode == 'full') {
        //   print "<h2 class='inner-node-header'>" . $node->title . "</h2>";
        // }
        print render($content);
       ?>
    </div>

    <?php if (!empty($content['links']['terms'])): ?>
      <div class="terms"><?php print render($content['links']['terms']); ?></div>
    <?php endif;?>

    <?php if (!empty($content['links'])): ?>
      <div class="links"><?php print render($content['links']); ?></div>
    <?php endif; ?>

  </div> <!-- /node-inner -->
</div> <!-- /node-->

<?php print render($content['comments']); ?>
