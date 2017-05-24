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
//defaults
$menu = 'main-menu';

$bg_tid = $content['field_backgrounds']['#items'][0]['tid'];
$bg_term = taxonomy_term_load($bg_tid);
$bg_uri = $bg_term->field_media_file['und'][0]['uri'];
$bg_image = theme('image_style', array('path' => $bg_uri, 'style_name' => 'responsive_1200w'));

$cta_url = $content['field_media_link']['#items'][0]['url'];
$cta_title = $content['field_media_link']['#items'][0]['title'];
$cta = l($cta_title, $cta_url);

if (isset($content['field_menu_option']['#items'][0]['value'])) {
    $menu = $content['field_menu_option']['#items'][0]['value'];
}

$headline = $content['field_headline'];

?>
<style>
    .section_nav_wrapper {
        position: relative;
        overflow:hidden;
    }
    .section_nav_wrapper .background img {
        position:absolute;
        z-index:0;
    }
    .section_nav_wrapper .cta {
        position: relative;
        float:right;
        z-index:1;
    }
    .section_nav_wrapper .headline {
        position: relative;
        float:left;
        z-index:1;
        padding:20px;
    }
    .section_nav_wrapper .menu {
        clear:both;
        position: relative;
        z-index:1;
    }
</style>
<div class="section_nav_wrapper">
    <div class="background"><?php print $bg_image;?></div>
    <div class="cta"><?php print $cta; ?></div>
    <div class="headline"><?php print $headline; ?></div>
    <div class="menu">
        <?php print culaw_paragraphs_render_menu($menu); ?>
    </div>
</div>