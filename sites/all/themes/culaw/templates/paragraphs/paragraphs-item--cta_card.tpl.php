<?php

/**
 * @file
 * Default theme implementation for a single paragraph item.
 *
 * Available variables:
 * - $content: An array of content items. Use render($content) to print them
 *   all, or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity
 *   - entity-paragraphs-item
 *   - paragraphs-item-{bundle}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened into
 *   a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */
//dpm($content);

$style_option = $content['style_option'];

$bg_uri = $content['field_media_file']['#items'][0]['uri'];
$media_type = $content['field_media_file']['#items'][0]['filemime'];
if ($media_type == "video/youtube" || $media_type == "video/vimeo") {
    $content['field_media_file'][0]['file']['#options']['width'] = 300;
    $content['field_media_file'][0]['file']['#options']['height'] = 182;
    $bg_image = theme('media_youtube_video',$content['field_media_file'][0]['file']);
} else {
    switch ($style_option) {
        case 'flexible-grid':
            $bg_image = theme('image_style', array('path' => $bg_uri, 'style_name' => 'flexible_grid', 'attributes' => array("class" => $style_option)));
            break;
        default:
            $bg_image = theme('image_style', array('path' => $bg_uri, 'style_name' => 'medium', 'attributes' => array("class" => $style_option)));
            break;
    }
}

$cta_url = $content['field_media_link']['#items'][0]['url'];
$cta_title = $content['field_media_link']['#items'][0]['title'];
$cta = l($cta_title, $cta_url);

$headline = $content['field_headline']['#items'][0]['value'];

if (isset($content['field_summary']['#items'][0])) {
    $summary = $content['field_summary']['#items'][0]['safe_value'];
}


?>

<style>
    .cta_card_wrapper {
        float:left;
        margin-left:50px;
    }
    .flexible_grid_wrapper {
        float:left;
        height:250px;
        width:250px;
        overflow:hidden;
        text-align:center;
    }

    .flexible_grid_wrapper .background {
        position:absolute;
    }
    .cta_card_wrapper .summary {
        width:300px;
    }

    .summary_wrapper {
        position:relative;
    }
</style>

<?php switch($style_option) : ?>
<?php case 'flexible-grid': ?>
    <div class="flexible_grid_wrapper">
        <div class="background"><?php print $bg_image;?></div>
        <div class="summary_wrapper">
            <div class="headline"><?php print $headline; ?></div>
            <?php if (isset($summary)) : ?>
                <div class="summary"><?php print $summary; ?></div>
            <?php endif; ?>
            <div class="cta"><?php print $cta; ?></div>
        </div>
    </div>
    <?php break; ?>
<?php default: ?>
    <div class="cta_card_wrapper">
        <div class="background"><?php print $bg_image;?></div>
        <div class="headline"><?php print $headline; ?></div>
        <?php if (isset($summary)) : ?>
            <div class="summary"><?php print $summary; ?></div>
        <?php endif; ?>
        <div class="cta"><?php print $cta; ?></div>
    </div>
    <?php break; ?>
<?php endswitch; ?>