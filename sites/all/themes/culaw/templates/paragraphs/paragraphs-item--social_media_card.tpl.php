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
//barebones setup of feed

$field_twitter_query = $content['field_twitter_query']['#items'][0]['value'];
$field_twitter_key = $content['field_twitter_key']['#items'][0]['value'];
$field_twitter_secret = $content['field_twitter_secret']['#items'][0]['value'];
$field_twitter_limit = $content['field_twitter_limit']['#items'][0]['value'];

$field_instagram_query = $content['field_instagram_query']['#items'][0]['value'];
$field_instagram_client_id = $content['field_instagram_client_id']['#items'][0]['value'];
$field_instagram_token = $content['field_instagram_token']['#items'][0]['value'];
$field_instagram_limit = $content['field_instagram_limit']['#items'][0]['value'];

$field_facebook_query = $content['field_facebook_query']['#items'][0]['value'];
$field_facebook_token = $content['field_facebook_token']['#items'][0]['value'];
$field_facebook_limit = $content['field_facebook_limit']['#items'][0]['value'];

$js_twitter_config = "";
$js_instagram_config = "";
$js_facebook_config = "";

if($field_twitter_key != "") {
	$js_twitter_config = 
		"// Twitter
		twitter: {
			accounts: ('$field_twitter_query').replace(' ', '').split(','),
			limit: $field_twitter_limit,
			consumer_key: '$field_twitter_key', // make sure to have your app read-only
			consumer_secret: '$field_twitter_secret', // make sure to have your app read-only
		},";
}
if($field_instagram_client_id != "") {
	$js_instagram_config = 
		"// INSTAGRAM
		instagram: {
			accounts: ('$field_instagram_query').replace(' ', '').split(','),
			limit: $field_instagram_limit,
			client_id: '$field_instagram_client_id',
			access_token: '$field_instagram_token'
		},";
}
if($field_facebook_token != "") {
	$js_facebook_config = 
		"// FACEBOOK
		facebook: {
			accounts: ('$field_facebook_query').replace(' ', '').split(','),
			limit: $field_facebook_limit,
			access_token: '$field_facebook_token'
		},";
}

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

    <!-- social area -->
    <div class="social-area">
        <div class="container">
            <div class="row social-feed-container"></div>
            <div class="social-networks-wrap">
                <strong class="social-networks-wrap__title">Connect With Us</strong>
                <ul class="social-networks list-unstyled">
                    <li><a href="#"><span class="hidden">twitter</span><i class="icon-twitter"></i></a></li>
                    <li><a href="#"><span class="hidden">facebook</span><i class="icon-facebook2"></i></a></li>
                    <li><a href="#"><span class="hidden">linkedin</span><i class="icon-linkedin"></i></a></li>
                    <li><a href="#"><span class="hidden">instagram</span><i class="icon-instagram"></i></a></li>
                </ul>
            </div>
        </div>
    </div>
 



<!-- Codebird.js - required for TWITTER -->
	<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css"/>
    <script src="/sites/all/themes/culaw/js/jquery.socialfeed/codebird.js"></script>
    <!-- doT.js for rendering templates -->
    <script src="/sites/all/themes/culaw/js/jquery.socialfeed/doT.min.js"></script>
    <!-- Moment.js for showing "time ago" -->
    <script src="/sites/all/themes/culaw/js/jquery.socialfeed/moment.min.js"></script>
    <!-- Social-feed js -->
    <script src="/sites/all/themes/culaw/js/jquery.socialfeed/jquery.socialfeed.js"></script>
    <script>
    jQuery(document).ready(function($) {

        var updateFeed = function() {
            $('.social-feed-container').socialfeed({
                
				<?php echo $js_facebook_config; ?>
                <?php echo $js_twitter_config; ?>
				<?php echo $js_instagram_config; ?>
                

                // GENERAL SETTINGS
                length: 200,
                show_media: true,
                template : "/sites/all/themes/culaw/js/jquery.socialfeed/template.html",
                // Moderation function - if returns false, template will have class hidden
                moderation: function(content) {
                    return (content.text) ? content.text.indexOf('porn') == -1 : true;
                },
                //update_period: 5000,
                // When all the posts are collected and displayed - this function is evoked
                callback: function() {
                    console.log('all posts are collected');
                }
            });
        };

        updateFeed();
       

    });
    </script>
<style>
/* need to roll into styles */
.social-block { background: white; }

</style>
<?php /*
<?php switch($layout_option) : ?>
<?php case 'banner': ?>
        <!-- hero banner -->
        <div class="hero-banner">
            <?php print $bg_image;?>
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


        <div class="four-column__block yellow">
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

<?php */ ?>