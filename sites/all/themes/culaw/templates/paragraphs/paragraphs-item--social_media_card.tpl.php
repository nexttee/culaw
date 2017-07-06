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

$field_twitter_query = isset($content['field_twitter_query']['#items'][0]['value']) ? $content['field_twitter_query']['#items'][0]['value'] : "";
$field_twitter_key = isset($content['field_twitter_key']['#items'][0]['value']) ? $content['field_twitter_key']['#items'][0]['value'] : "";
$field_twitter_secret = isset($content['field_twitter_secret']['#items'][0]['value']) ? $content['field_twitter_secret']['#items'][0]['value'] : "";
$field_twitter_limit = isset($content['field_twitter_limit']['#items'][0]['value']) ? $content['field_twitter_limit']['#items'][0]['value'] : "";

$field_instagram_query = isset($content['field_instagram_query']['#items'][0]['value']) ? $content['field_instagram_query']['#items'][0]['value'] : "";
$field_instagram_client_id = isset($content['field_instagram_client_id']['#items'][0]['value']) ? $content['field_instagram_client_id']['#items'][0]['value'] : "";
$field_instagram_token = isset($content['field_instagram_token']['#items'][0]['value']) ? $content['field_instagram_token']['#items'][0]['value'] : "";
$field_instagram_limit = isset($content['field_instagram_limit']['#items'][0]['value']) ? $content['field_instagram_limit']['#items'][0]['value'] : "";

$field_facebook_query = isset($content['field_facebook_query']['#items'][0]['value']) ? $content['field_facebook_query']['#items'][0]['value'] : "";
$field_facebook_token = isset($content['field_facebook_token']['#items'][0]['value']) ? $content['field_facebook_token']['#items'][0]['value'] : "";
$field_facebook_limit = isset($content['field_facebook_limit']['#items'][0]['value']) ? $content['field_facebook_limit']['#items'][0]['value'] : "";

?>
<style>
    .media_card_wrapper {
        float:left;
    }
	.social-block { background: white; }
</style>

    <!-- social area -->
    <div class="social-area">
        <div class="container">
            <div class="row social-feed-container"
				data-tw_query="<?php echo $field_twitter_query; ?>"
				data-tw_limit="<?php echo $field_twitter_limit; ?>"
				data-tw_key="<?php echo $field_twitter_key; ?>"
				data-tw_secret="<?php echo $field_twitter_secret; ?>"
				
				data-ig_query="<?php echo $field_instagram_query; ?>"
				data-ig_limit="<?php echo $field_instagram_limit; ?>"
				data-ig_client="<?php echo $field_instagram_client_id; ?>"
				data-ig_token="<?php echo $field_instagram_token; ?>"
				
				data-fb_query="<?php echo $field_facebook_query; ?>"
				data-fb_limit="<?php echo $field_facebook_limit; ?>"
				data-fb_token="<?php echo $field_facebook_token; ?>"

				></div>
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
 



	<?php
	drupal_add_css("https://maxcdn.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css");
	drupal_add_js(drupal_get_path('theme', 'culaw') . '/js/jquery.socialfeed/codebird.js', array(
	  'type' => 'file',
	  'group' => JS_THEME,
	));
	drupal_add_js(drupal_get_path('theme', 'culaw') . '/js/jquery.socialfeed/doT.min.js', array(
	  'type' => 'file',
	  'group' => JS_THEME,
	));
	drupal_add_js(drupal_get_path('theme', 'culaw') . '/js/jquery.socialfeed/moment.min.js', array(
	  'type' => 'file',
	  'group' => JS_THEME,
	));
	drupal_add_js(drupal_get_path('theme', 'culaw') . '/js/jquery.socialfeed/jquery.socialfeed.js', array(
	  'type' => 'file',
	  'group' => JS_THEME,
	));
	drupal_add_js(drupal_get_path('theme', 'culaw') . '/js/jquery.socialfeed/init.js', array(
	  'type' => 'file',
	  'group' => JS_THEME,
	));
	?>

   
