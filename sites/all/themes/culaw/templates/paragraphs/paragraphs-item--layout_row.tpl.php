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

$classes = "";
$content_classes = array("");
$container_class = "container";
$secondary_layout_option= "";

if (isset($content['field_cta_options']['#items'][0])) {
    $layout_option = $content['field_cta_options']['#items'][0];
    unset($content['field_cta_options']);
}
if (isset($content['field_backgrounds'])) {
    $row_id = $content['row_id']['#value'];
    $background = $content['field_backgrounds'];
    unset($content['field_backgrounds']);
    $bg_tid = $background['#items'][0]['tid'];
    $bg_term = taxonomy_term_load($bg_tid);
    $bg_uri = $bg_term->field_media_file['und'][0]['uri'];
    $bg_image = image_style_url('responsive_1200w', $bg_uri);
    $content_classes[] = "content-background-".$row_id;
    ?>

    <style>
        .content-background-<?php print $row_id; ?> {
            background:transparent url(<?php print $bg_image; ?>) no-repeat;
            background-size: cover;
        }
    </style>
<?php
}


if (isset($content['field_background_color'])) {
    $row_id = $content['row_id']['#value'];
    $bkg_color = $content['field_background_color']['#items'][0]['rgb'];
	$content_classes[] = "content-background-".$row_id;
    ?>

    <style>
        .content-background-<?php print $row_id; ?> {
            background: <?php print $bkg_color; ?>;
            
        }
    </style>

    <?php
}

//handle wrapper for content here
//format headline, optional
if (isset($content['field_headline']['#items'][0]['safe_value'])) {
    $headline = $content['field_headline']['#items'][0]['safe_value'];
    unset($content['field_headline']);
    //on the sticky nav, we use the headline for the link in the nav.
    //sometimes the card already has a hard coded headline.
    //unset headline if the card has a hard coded headline.
}
//Basic Column
if (isset($content['field_card_options'][0]['entity']['paragraphs_item'])) {
    foreach ($content['field_card_options'][0]['entity']['paragraphs_item'] as $key => $item) {
        if (isset($item['field_text_formatting'])) {
            //field_media_layout_options
            $secondary_layout_option = $item['field_text_formatting']['#items'][0]['value'];
        } else if (isset($item['field_feed_type'])) {
            //field_media_layout_options
            $secondary_layout_option = $item['field_feed_type']['#items'][0]['value'];
        } else {
            $secondary_layout_option = $item['#bundle'];
        }
    }
}
switch($layout_option['value']) {
    case 'flexible-grid':
        $classes = "flexible-grid";//"four-column";
        $container_class = "null";
        //if I remove this the layout fails
        unset($headline);
        break;
    case 'circular-images':
        $classes = "three-column";
        $container_class = "container";
        break;
    case 'banner':
        $classes = "one-column";
        $container_class = "null";
        unset($headline);
        break;
    default:
        switch ($secondary_layout_option) {
            case 'testimonial':
                $classes = "testimonial";
                $container_class = "container";
                break;
            case 'news_article':
            case 'cls_mcl_event':
                $classes = "events-feed-grid";
                $container_class = "container";
                unset($headline);
                break;
            case 'social_media_card':
                $container_class = "null";
                unset($headline);
                break;
            default:
                $classes = "three-column";
                $container_class = "container";
                break;
        }
        unset($content['field_headline']);
        unset($content['headline']);
        break;
}
$content_classes[] = "";

?>

<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
    <div class="content<?php print implode(" ", $content_classes); ?>"<?php print $content_attributes; ?>>
        <div class="row">
            <?php if (isset($headline)) : ?>
                <h2><?php print $headline; ?></h2>
            <?php endif; ?>
            <!-- this container should not appear on hero-banner -->
            <div class="<?php print $container_class; ?>">
                <?php print render($content); ?>
                <div class="clear"></div>
            </div>
        </div>
    </div>
</div>