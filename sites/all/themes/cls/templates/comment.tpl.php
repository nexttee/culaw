<?php

// $Id: comment.tpl.php 1116 2011-06-21 06:47:07Z cstuck $

/**
 * @file
 * Default theme implementation for displaying comments.
 */
?>
<div class="<?php print $classes . ' ' . $zebra; ?>">
	<div class="comment-inner">
	    
    <span class="submitted"><strong><?php print $comment->name; ?></strong> wrote:</span>
    
    <div class="content">
      <?php 
        hide($content['links']); 
        print render($content);
        ?>
    </div>

  </div> <!-- /comment-inner -->
</div> <!-- /comment -->