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

$layout_option = culaw_paragraphs_format_class($content['field_text_formatting']['#items'][0]['value']);

$bg_uri = $content['field_media_file']['#items'][0]['uri'];
switch ($layout_option) {
    default:
        $bg_image = theme('image_style', array('path' => $bg_uri, 'style_name' => 'medium'));
        break;
}

$headline = $content['field_headline']['#items'][0]['value'];
$summary = $content['field_summary']['#items'][0]['safe_value'];
$attribution = $content['field_attribution']['#items'][0]['safe_value'];

?>

    <style>
    </style>

<?php switch($layout_option) : ?>
<?php case 'callout-text': ?>
    <div class="callout-text-wrapper">
        <div class="headline"><h3><?php print $headline; ?></h3></div>
        <div class="background"><?php print $bg_image;?></div>
        <div class="summary"><?php print $summary; ?></div>
        <div class="attribution"><?php print $attribution; ?></div>
    </div>
    <?php break; ?>

    <?php endswitch; ?>