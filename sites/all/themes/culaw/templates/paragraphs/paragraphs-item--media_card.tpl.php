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
$style_option = $content['style_option'];
$column_style = "col-sm-4";
$extra_flex_class = "";

//how many items
if (isset($content['single_item'])) {
    $column_style = "";
}
if (isset($content['field_media_category']['#items'][0])) {
    $media_category = $content['field_media_category']['#items'][0]['taxonomy_term']->name;
}
if (isset($content['field_media_file']['#items'][0]['uri'])) {
    $bg_uri = $content['field_media_file']['#items'][0]['uri'];
    $bg_alt_text = $content['field_media_file']['#items'][0]['alt'];
    switch ($style_option) {
        case 'banner':
            $bg_image = theme('image_style', array('path' => $bg_uri, 'style_name' => 'responsive_1200w'));
            $bg_desktop_path = image_style_url('banner_desktop_style',$bg_uri);
            $bg_tablet_path = image_style_url('banner_tablet_style',$bg_uri);
            $bg_mobile_path = image_style_url('banner_mobile_style',$bg_uri);
            break;
        case 'flexible-grid':
            $bg_image = theme('image_style', array('path' => $bg_uri, 'style_name' => 'flexible_grid', 'attributes' => array("class" => $style_option)));
            $bg_path = image_style_url('flexible_grid',$bg_uri);
            break;
        case 'basic-column':
            if ($field_media_file[0]['type'] == "video") {
                $display['settings'] = array('image_style' => 'medium');
                $file = file_load($field_media_file[0]['fid']);
                switch($field_media_file[0]['filemime']) {
                    case "video/youtube":
                        module_load_include('inc', 'media_youtube', '/includes/media_youtube.formatters.inc');
                        $video_code = str_replace("youtube://v/", "", $bg_uri);
                        $base_url = "https://www.youtube.com/embed/";
                        $image_render_array = media_youtube_file_formatter_image_view($file, $display, LANGUAGE_NONE);
                        break;
                    case "video/vimeo":
                        module_load_include('inc', 'media_vimeo', '/includes/media_vimeo.formatters.inc');
                        $video_code = str_replace("vimeo://v/", "", $bg_uri);
                        $base_url = "https://player.vimeo.com/video/";
                        $image_render_array = media_vimeo_file_formatter_image_view($file, $display, LANGUAGE_NONE);
                        break;
                }
                $video_path = $base_url . $video_code."?autoplay=1";
                $video = '<a class="lightbox fancybox.iframe thumb three-column__play-btn" href="' . $video_path . '"><span class="hidden">video</span></a>';
                if (isset($content['field_thumbnail_image'])) {
                    $thumbnail_uri = $content['field_thumbnail_image']['#items'][0]['uri'];
                    $thumbnail = theme('image_style', array('path' => $thumbnail_uri, 'style_name' => 'medium', 'attributes' => array("class" => $style_option)));
                } else {
                    $thumbnail = render($image_render_array);
                }
                $bg_image = $thumbnail . $video;
            } else {
                $bg_image = theme('image_style', array('path' => $bg_uri, 'style_name' => 'medium', 'attributes' => array("class" => $style_option)));
                $bg_path = image_style_url('medium',$bg_uri);
            }
            break;
        default:
            $bg_image = theme('image_style', array('path' => $bg_uri, 'style_name' => 'medium', 'attributes' => array("class" => $style_option)));
            $bg_path = image_style_url('medium',$bg_uri);
            break;
    }
} elseif (isset($content['field_backgrounds']['#items'][0]['tid'])) {
    $background = $content['field_backgrounds'];
    $bg_tid = $background['#items'][0]['tid'];
    $bg_term = taxonomy_term_load($bg_tid);
    $bg_uri = $bg_term->field_media_file['und'][0]['uri'];
    $bg_image = theme('image_style', array('path' => $bg_uri, 'style_name' => 'flexible_grid', 'attributes' => array("class" => $style_option)));
    $bg_path = image_style_url('flexible_grid',$bg_uri);
    $extra_flex_class = " four-column__image-wrap--static";
}

if (isset($content['field_media_link']['#items'][0]['url'])) {
    $cta_target = "_self";
    if (isset($content['field_media_link']['#items'][0]['attributes']['target'])) {
        $cta_target = $content['field_media_link']['#items'][0]['attributes']['target'];
    }
    $cta_url = $content['field_media_link']['#items'][0]['url'];
    $cta_title = $content['field_media_link']['#items'][0]['title'];
    $cta = l($cta_title, $cta_url);
    $apply_holder_class = "apply-holder";
} else {
    $apply_holder_class = "apply-holder apply-holder--cta";
}

if(isset($content['field_headline']['#items'][0]['value'])) {
    $headline = $content['field_headline']['#items'][0]['value'];
}
if (isset($content['field_summary']['#items'][0]['safe_value'])) {
    $summary = $content['field_summary']['#items'][0]['safe_value'];
}

?>

<?php switch($style_option) : ?>
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
                <?php if (isset($summary)) : ?>
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
                <?php endif; ?>
				<!-- apply area -->
                <?php if (isset($headline)) : ?>
                    <div class="apply-area">
                        <div class="container">
                            <div class="<?php print $apply_holder_class; ?>">
                                <h1><?php print $headline; ?></h1>
                                <?php if (isset($cta_url)) : ?>
                                    <a href="<?php print $cta_url; ?>" target="<?php print $cta_target; ?>" class="btn btn-default"><span class="btn__text"><?php print $cta_title; ?></span><i class="icon-keyboard_arrow_right"></i></a>
                                <?php endif; ?>
                            </div>
                        </div>
                    </div>
                <?php endif; ?>
            </div>
        </div>
    <?php break; ?>
<?php case 'flexible-grid': ?>

        <div class="flexible-grid__block">
            <?php if (isset($bg_path)) :?>
                <div class="four-column__image-wrap bg-stretch<?php print $extra_flex_class; ?>">
                    <span data-srcset="<?php print $bg_path; ?>"></span>
                </div>
            <?php endif; ?>
            <div class="four-column__image-caption">
                <div class="four-column__image-caption-wrap">
                    <strong class="four-column__title h3"><?php print $headline; ?></strong>
                    <div class="four-column__wrap">
                        <p><?php print $summary; ?></p>
                        <?php if(isset($cta_url)) : ?>
                            <a href="<?php print $cta_url; ?>" target="<?php print $cta_target; ?>" class="four-column__more"><span class="hidden"><?php print $cta_title; ?></span><i class="icon-keyboard_arrow_right"></i></a>
                        <?php endif; ?>
                    </div>
                </div>
            </div>
        </div>

        <?php break; ?>
    <?php case 'basic-column': ?>

        <div class="<?php print $column_style; ?> col-xs-12">
			<div class="spotlight">
                <?php if (isset($bg_image)) :?>
                    <div class="three-column__image-wrap">
                        <?php print $bg_image;?>
                    </div>
                <?php endif; ?>
                <div class="three-column__detail">
                    <?php if(isset($media_category)) : ?>
                        <span class="three-column__voice"><?php print $media_category; ?></span>
                    <?php endif; ?>
                    <?php if(isset($headline)) : ?>
                        <strong class="three-column__heading h4"><?php print $headline; ?></strong>
                    <?php endif; ?>
                    <p><?php print $summary; ?></p>
                    <?php if(isset($cta_url)) : ?>
                        <a href="<?php print $cta_url; ?>" target="<?php print $cta_target; ?>" class="more-link">Read More<i class="icon-keyboard_arrow_right"></i></a>
                    <?php endif; ?>
                    </div>
                </div>
            </div>
        </div>

        <?php break; ?>
    <?php case 'circular-images': ?>
    <?php default: ?>

        <div class="<?php print $column_style; ?> col-xs-12">
            <div class="three-column__circle-images">
                <?php if (isset($bg_image)) :?>
                    <div class="three-column__image-holder">
                        <?php print $bg_image;?>
                    </div>
                <?php endif; ?>
                <div class="three-column__description">
                    <strong class="three-column__title h3"><?php print $headline; ?></strong>
                    <p><?php print $summary; ?></p>
                    <?php if(isset($cta_url)) : ?>
                        <a href="<?php print $cta_url; ?>" target="<?php print $cta_target; ?>" class="three-column__more"><span class="hidden"><?php print $cta_title; ?></span><i class="icon-keyboard_arrow_right"></i></a>
                    <?php endif; ?>
                </div>
            </div>
        </div>

        <?php break; ?>
<?php endswitch; ?>