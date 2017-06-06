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

$cta = "";
$layout_option = $content['field_media_layout_options']['#items'][0]['value'];
$style_option = $content['style_option'];
if ($layout_option != "banner") {
    $layout_option = $style_option;
}

if (isset($content['field_media_file']['#items'][0]['uri'])) {
    $bg_uri = $content['field_media_file']['#items'][0]['uri'];
    $bg_alt_text = $content['field_media_file']['#items'][0]['alt'];
    switch ($layout_option) {
        case 'banner':
            $bg_image = theme('image_style', array('path' => $bg_uri, 'style_name' => 'responsive_1200w'));
            $bg_desktop_path = image_style_url('banner_desktop_style',$bg_uri);
            $bg_tablet_path = image_style_url('banner_tablet_style',$bg_uri);
            $bg_mobile_path = image_style_url('banner_mobile_style',$bg_uri);
            break;
        case 'flexible-grid':
            $hover_state = "yellow";
            $bg_image = theme('image_style', array('path' => $bg_uri, 'style_name' => 'flexible_grid', 'attributes' => array("class" => $style_option)));
            $bg_path = image_style_url('flexible_grid',$bg_uri);
            if (isset($content['field_hover_state'])) {
                $hover_state = $content['field_hover_state']['#items'][0]['value'];
            }
            break;
        case 'basic-column':
            $bg_image = theme('image_style', array('path' => $bg_uri, 'style_name' => 'medium', 'attributes' => array("class" => $style_option)));
            $bg_path = image_style_url('medium',$bg_uri);
            break;
        default:
            $bg_image = theme('image_style', array('path' => $bg_uri, 'style_name' => 'medium', 'attributes' => array("class" => $style_option)));
            $bg_path = image_style_url('medium',$bg_uri);
            break;
    }
}

if (isset($content['field_media_link']['#items'][0]['url'])) {
    $cta_url = $content['field_media_link']['#items'][0]['url'];
    $cta_title = $content['field_media_link']['#items'][0]['title'];
    $cta = l($cta_title, $cta_url);
}

$headline = $content['field_headline']['#items'][0]['value'];

$summary = $content['field_summary']['#items'][0]['safe_value'];


?>

<style>
    /*.banner_wrapper {
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
    }*/
    .media_card_wrapper {
        float:left;
    }
</style>

<?php switch($layout_option) : ?>
<?php case 'banner': ?>
        <!-- hero banner -->
        <div class="hero-banner">
            <picture id="images__hero--box1">
                <!--[if IE 9]><video style="display: none;"><![endif]-->
                <source srcset="<?php echo $bg_desktop_path; ?>" media="(min-width: 1224px)">
                <source srcset="<?php echo $bg_tablet_path; ?>" media="(min-width: 768px)">
                <!--[if IE 9]></video><![endif]-->
                <img src="<?php echo $bg_mobile_path; ?>" srcset="<?php echo $bg_mobile_path; ?>" alt="<?php echo  $bg_alt_text; ?>">
            </picture>
            <div class="hero-banner-wrap">
                <div class="hero-banner__caption-holder hidden-xs">
                    <div class="container">
                        <div class="hero-banner__caption">
                            <blockquote class="hero-banner__blockquote">
                                <?php print $summary; ?>
                                <!--<cite><strong class="hero-banner__name">David Leapheart</strong>Class of 2014</cite>-->
                            </blockquote>
                        </div>
                    </div>
                </div>
				<!-- apply area -->
				<div class="apply-area">
					<div class="container">
						<div class="apply-holder">
							<h1><a href="#" title="link1"><?php print $headline; ?></a></h1>
							<a href="<?php print $cta_url; ?>" class="btn btn-default"><span class="btn__text"><?php print $cta_title; ?></span><i class="icon-keyboard_arrow_right"></i></a>
						</div>
					</div>
				</div>
            </div>
        </div>
    <?php break; ?>
<?php case 'flexible-grid': ?>
        <!--<div class="flexible_grid_wrapper">
        <div class="background"><?php print $bg_image;?></div>
        <div class="summary_wrapper">
            <div class="headline"><?php print $headline; ?></div>
            <?php if (isset($summary)) : ?>
                <div class="summary"><?php print $summary; ?></div>
            <?php endif; ?>
            <div class="cta"><?php print $cta; ?></div>
        </div>
    </div>-->


        <div class="flexible-grid__block <?php print $hover_state; ?>">
            <?php if (isset($bg_path)) :?>
                <div class="four-column__image-wrap bg-stretch">
                    <span data-srcset="<?php print $bg_path; ?>"></span>
                </div>
            <?php endif; ?>
            <div class="four-column__image-caption">
                <div class="four-column__image-caption-wrap">
                    <strong class="four-column__title h3"><?php print $headline; ?></strong>
                    <div class="four-column__wrap">
                        <p><?php print $summary; ?></p>
                        <a href="#" class="four-column__more"><span class="hidden">more link</span><i class="icon-keyboard_arrow_right"></i></a>
                    </div>
                </div>
            </div>
        </div>

        <?php break; ?>
    <?php case 'basic-column': ?>

        <div class="col-sm-4 col-xs-12">
			<div class="spotlight">
                <?php if (isset($bg_image)) :?>
                    <div class="three-column__image-wrap">
                        <?php print $bg_image;?>
                        <a class="lightbox fancybox.iframe thumb three-column__play-btn" href="https://www.youtube.com/embed/P_rbC-qgB5o"><span class="hidden">video</span></a>
                    </div>
                    </div>
                <?php endif; ?>
                <div class="three-column__detail">
                    <span class="three-column__voice">Student Voices</span>
                    <strong class="three-column__heading h4"><?php print $headline; ?></strong>
                    <p><?php print $summary; ?></p>
                    <a href="#" class="more-link">Read More<i class="icon-keyboard_arrow_right"></i></a>
                </div>
            </div>
        </div>

        <?php break; ?>
    <?php case 'circular-images': ?>
    <?php default: ?>
        <!--<div class="media_card_wrapper">
        <div class="background"><?php print $bg_image;?></div>
        <div class="headline"><?php print $headline; ?></div>
        <div class="summary"><?php print $summary; ?></div>
        <div class="cta"><?php print $cta; ?></div>
    </div>-->

        <div class="col-sm-4 col-xs-12">
            <div class="three-column__circle-images">
                <?php if (isset($bg_image)) :?>
                    <div class="three-column__image-holder">
                        <?php print $bg_image;?>
                    </div>
                <?php endif; ?>
                <div class="three-column__description">
                    <strong class="three-column__title h3"><?php print $headline; ?></strong>
                    <p><?php print $summary; ?></p>
                    <a href="#" class="three-column__more"><span class="hidden">more link</span><i class="icon-keyboard_arrow_right"></i></a>
                </div>
            </div>
        </div>

        <?php break; ?>
<?php endswitch; ?>