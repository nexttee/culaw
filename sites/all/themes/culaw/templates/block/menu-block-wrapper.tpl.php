<?php
/**
 * @file
 * Default theme implementation to wrap menu blocks.
 *
 * Available variables:
 * - $content: The renderable array containing the menu.
 * - $classes: A string containing the CSS classes for the DIV tag. Includes:
 *   menu-block-DELTA, menu-name-NAME, parent-mlid-MLID, and menu-level-LEVEL.
 * - $classes_array: An array containing each of the CSS classes.
 *
 * The following variables are provided for contextual information.
 * - $delta: (string) The menu_block's block delta.
 * - $config: An array of the block's configuration settings. Includes
 *   menu_name, parent_mlid, title_link, admin_title, level, follow, depth,
 *   expanded, and sort.
 *
 * @see template_preprocess_menu_block_wrapper()
 */
?>
<h1>Dude</h1>

<div class="heading-area__btn-wrap">
    <a href="#" class="heading-area__back-btn">J.D. Admissions</a>
    <!-- subnavigation area -->
    <div class="subnavigation-area">
        <div class="subnavigation-frame">
            <a href="#" class="subnavigation-opener">In this section<i class="icon-keyboard_arrow_down"></i></a>
            <div class="subnavigation-wrap js-slide-hidden">

                <div class="<?php print $classes; ?>">
                    <?php print render($content); ?>
                </div>

            </div>
        </div>
    </div>
</div>