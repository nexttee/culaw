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

$layout_option = $content['field_media_layout_options']['#items'][0]['value'];
$style_option = $content['style_option'];

$bg_uri = $content['field_media_file']['#items'][0]['uri'];
switch ($layout_option) {
    case 'banner':
        $bg_image = theme('image_style', array('path' => $bg_uri, 'style_name' => 'responsive_1200w'));
        break;
    default:
        $bg_image = theme('image_style', array('path' => $bg_uri, 'style_name' => 'medium', 'attributes'=>array("class"=>$style_option)));
        break;
}

$cta_url = $content['field_media_link']['#items'][0]['url'];
$cta_title = $content['field_media_link']['#items'][0]['title'];
$cta = l($cta_title, $cta_url);

$headline = $content['field_headline']['#items'][0]['value'];

$summary = $content['field_summary']['#items'][0]['safe_value'];


?>

<style>
    .banner_wrapper {
        position:relative;
        height:350px;
        overflow:hidden;
    }
    .banner_wrapper .background {
        position:absolute;
    }
    .banner_wrapper .summary_wrapper {
        position:relative;
        text-align:center;
        margin:100px auto;
        font-size:3em;
    }
    .media_card_wrapper {
        float:left;
    }
</style>

<?php switch($layout_option) : ?>
<?php case 'banner': ?>
    <div class="banner_wrapper">
        <div class="background"><?php print $bg_image;?></div>
        <div class="summary_wrapper">
            <div class="headline"><?php print $headline; ?></div>
            <div class="summary"><?php print $summary; ?></div>
            <div class="cta"><?php print $cta; ?></div>
        </div>
    </div>
    <?php break; ?>
<?php default: ?>
    <div class="media_card_wrapper">
        <div class="background"><?php print $bg_image;?></div>
        <div class="headline"><?php print $headline; ?></div>
        <div class="summary"><?php print $summary; ?></div>
        <div class="cta"><?php print $cta; ?></div>
    </div>
    <?php break; ?>
<?php endswitch; ?>