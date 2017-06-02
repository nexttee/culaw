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
<div class="apply-area">
    <div class="cta"><?php print $cta; ?></div>
    <div class="headline"><?php print $headline; ?></div>
</div>
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

<!-- subnavigation area -->
<!---<div class="subnavigation-area">
    <div class="container">
        <div class="subnavigation-frame">
            <a href="#" class="subnavigation-opener visible-xs">In this section<i class="icon-keyboard_arrow_down"></i></a>
            <div class="subnavigation-wrap row">
                <div class="col-sm-4 col-xs-12 same-height">
                    <ul class="subnavigation-wrap__subnavigation-links list-unstyled">
                        <li class="active"><a href="#">Learn</a>
                            <ul class="subnavigation-wrap__links-dropdown list-unstyled">
                                <li><a href="#">The History</a></li>
                                <li><a href="#">The Curriculum</a></li>
                                <li><a href="#">Centers &amp; Programs</a></li>
                                <li><a href="#">Clinics &amp; Externships</a></li>
                                <li><a href="#">Viewbook</a></li>
                            </ul>
                        </li>
                        <li><a href="#">Experience</a></li>
                        <li><a href="#" title="link3">Visit</a></li>
                    </ul>
                </div>
                <div class="col-sm-4 col-xs-12 same-height">
                    <ul class="subnavigation-wrap__subnavigation-links list-unstyled">
                        <li><a href="#">Apply</a></li>
                        <li><a href="#">Entering Class Profile</a></li>
                        <li><a href="#">Joint Degree Programs</a></li>
                    </ul>
                </div>
                <div class="col-sm-4 col-xs-12 same-height">
                    <ul class="subnavigation-wrap__subnavigation-links list-unstyled">
                        <li><a href="#">My Columbia Law</a></li>
                        <li><a href="#">Admitted Student Website</a></li>
                        <li><a href="#" title="link7">Contact Us</a></li>
                    </ul>
                </div>
            </div>
        </div>
    </div>
</div>--->