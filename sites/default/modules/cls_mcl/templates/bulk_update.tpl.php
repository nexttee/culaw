<?php
// $Id: bulk_update.tpl.php 2013-07-05 atkach $
?>
<div class="content">

  <div <?php echo (isset($_SESSION['messages']['status'][0])) ? "class='status-msg'" : "" ?> >
    <?php echo (isset($_SESSION['messages']['status'][0])) ? $_SESSION['messages']['status'][0] : "" ?>
  </div>
  <div <?php echo (isset($_SESSION['messages']['error'][0])) ? "class='error-msg'" : "" ?> > 
    <?php echo (isset($_SESSION['messages']['error'][0])) ? $_SESSION['messages']['error'][0] : "" ?>
  </div>

      <?php echo drupal_render($form); ?>
</div>

<script type="text/javascript">
<!--//--><![CDATA[//><!--
//--><!]]>
</script>