<?php
//dpm($content);
$count = 1;
$label = "placeholder";
$elements = array();
?>
<div class="main-holder">
    <!-- sticky nav area -->
    <nav class="sticky-nav-area hidden-sm hidden-xs">
        <div class="container">
            <ul class="sticky-nav list-unstyled">

                <?php foreach($content['field_content_rows']['#items'] AS $key => $row) : ?>
                    <?php
                    $pid = $row['value'];
                    //$rid = $row['revision_id'];
                    $entities = entity_load('paragraphs_item', array($pid));
                    $temp = $entities;
                    $entity = array_pop($temp);
                    $label = $entity->field_headline['und'][0]['safe_value'];
                    $paragraphs_render = entity_view('paragraphs_item', $entities, 'full');
                    $elements[] = array(
                            "output"=>drupal_render($paragraphs_render),
                            "label"=>$label,
                            "index"=>$count
                    );
                    ?>
                    <li><a href="#section<?php print $count; ?>" class="smooth-anchor"><?php print $label; ?></a></li>
                    <?php $count++; ?>
                <?php endforeach; ?>

            </ul>
        </div>
    </nav>
    <?php foreach($elements AS $key => $value) : ?>

        <div class="accordion-wrap">
            <a href="#" class="accordion-opener"><?php print $value['label']; ?></a>
            <div class="accordion-slide" id="section<?php print $value['index']; ?>">
                <?php print $value['output']; ?>
            </div>
        </div>

    <?php endforeach; ?>


</div>