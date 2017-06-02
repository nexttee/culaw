<?php
dpm($content);
$count = 1;
?>
<div class="main-holder">
    <!-- sticky nav area -->
    <nav class="sticky-nav-area hidden-sm hidden-xs">
        <div class="container">
            <ul class="sticky-nav list-unstyled">

                <?php foreach($content['field_content_rows']['#items'] AS $key => $row) : ?>
                    <li><a href="#section<?php print $count; ?>" class="smooth-anchor"><?php print $key; ?></a></li>
                    <?php $count++; ?>
                <?php endforeach; ?>

            </ul>
        </div>
    </nav>
    <?php $count = 1; ?>
    <?php foreach($content['field_content_rows']['#items'] AS $key => $row) : ?>
        <?php
            $pid = $row['value'];
            //$rid = $row['revision_id'];

            $entities = entity_load('paragraphs_item', array($pid));
            $paragraphs_render = entity_view('paragraphs_item', $entities, 'full');
        ?>

        <div class="accordion-wrap">
            <a href="#" class="accordion-opener">Curriculum</a>
            <div class="three-column three-column__style03 accordion-slide" id="section<?php print $count; ?>">
                <?php print drupal_render($paragraphs_render); ?>
            </div>
        </div>

        <?php
            $count++;
        ?>

    <?php endforeach; ?>


</div>