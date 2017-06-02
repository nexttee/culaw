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
$summary = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Quisque sed elit tellus. Nam ullam tincidunt bibendum. Sed ipsum augue, mattis sed tristique at.";

$layout_option = culaw_paragraphs_format_class($content['field_text_formatting']['#items'][0]['value']);

if (isset($content['field_media_file']['#items'][0]['uri'])) {
    $bg_uri = $content['field_media_file']['#items'][0]['uri'];
    switch ($layout_option) {
        default:
            $bg_image = theme('image_style', array('path' => $bg_uri, 'style_name' => 'medium'));
            $bg_path = image_style_url('medium',$bg_uri);
            break;
    }
}

if (isset($content['field_headline']['#items'][0]['value'])) {
    $headline = $content['field_headline']['#items'][0]['value'];
}
if (trim($content['field_summary']['#items'][0]['safe_value']) != "") {
    $summary = $content['field_summary']['#items'][0]['safe_value'];
}

if (isset($content['field_attribution']['#items'][0]['safe_value'])) {
    $attribution = $content['field_attribution']['#items'][0]['safe_value'];
}

?>

    <style>
    </style>

<?php switch($layout_option) : ?>
<?php case 'testimonial': ?>
        <div class="testimonial">
            <div class="container">
                <div class="testimonial-holder">
                    <div class="testimonial-holder__image-wrap">
                        <a href="#"><img src="<?php print $bg_path; ?>" width="166" height="166" alt="image-description"></a>
                    </div>
                    <blockquote>
                        <?php if (isset($summary)) : ?>
                            <q><?php print $summary; ?></q>
                        <?php endif; ?>
                        <?php if (isset($attribution)) : ?>
                            <cite><?php print $attribution; ?></cite>
                        <?php endif; ?>
                    </blockquote>
                </div>
            </div>
        </div>
    <?php break; ?>
<?php case 'callout-text': ?>
    <div class="callout-holder">
        <div class="container">
            <div class="callout-frame">
                <strong class="callout-holder__tagline"><?php print $summary; ?></strong>
            </div>
        </div>
    </div>

    <?php break; ?>

<?php endswitch; ?>
