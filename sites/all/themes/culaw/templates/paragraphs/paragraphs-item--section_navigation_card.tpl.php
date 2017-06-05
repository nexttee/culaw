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

if (isset($content['field_menu_option']['#items'][0]['value'])) {
    $menu = $content['field_menu_option']['#items'][0]['value'];
}

?>

<div class="subnavigation-area">
    <div class="container">
        <div class="subnavigation-frame">
            <a href="#" class="subnavigation-opener visible-xs">In this section<i class="icon-keyboard_arrow_down"></i></a>
            <div class="subnavigation-wrap row js-slide-hidden">
                <?php print culaw_paragraphs_render_menu($menu); ?>
            </div>
        </div>
    </div>
</div>