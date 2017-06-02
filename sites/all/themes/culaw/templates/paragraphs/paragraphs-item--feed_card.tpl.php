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
?>

<?php
$area = "";
$argument_array = array();
//set content type for the feed
$feed_type = $content['field_feed_type']['#items'][0]['value'];
//$argument_array = array($feed_type);
//set Aread of Study argument for the feed
if (isset($content['field_area_of_study'])) {
    $area = $content['field_area_of_study']['#items'][0]['tid'];
    $tmp = array_push($argument_array, $area);
}
$view = views_get_view('internal_feeds');
switch($feed_type) {
    case 'news_article':
        $view->set_display("page");
        break;
    case 'cls_mcl_event':
        $view->set_display("page_1");
        break;
}
if (count($argument_array)) {
    $view->set_arguments($argument_array);
}
$view->pre_execute();
$view->execute();
$output = $view->render();
//($view);

?>

<?php switch($feed_type) : ?>
<?php case 'cls_mcl_event': ?>
    <div class="events-feed-grid">
        <div class="container">
            <h2>Upcoming Events</h2>
            <div class="events-feed-holder row">

                <?php foreach($view->result AS $key => $item) : ?>
                    <?php $row = _culaw_paragraphs_format_content($item->nid, 'event_feed_row'); ?>
                    <div class="col-md-3 col-sm-6 col-xs-12">
                        <div class="event-block">
                            <time datetime="<?php print $row['date']['class']; ?>" class="event-block__time"><span class="event-block__month"><?php print $row['date']['month']; ?></span><?php print $row['date']['day']; ?></time>
                            <strong class="event-block__title"><a href="<?php print $row['url']; ?>"><?php print $row['source']; ?></a></strong>
                            <p><?php print $row['summary']; ?></p>
                        </div>
                    </div>
                <?php endforeach; ?>

            </div>
            <span class="events-feed-grid__more"><a href="#" class="more-link">View Event Calendar<i class="icon-keyboard_arrow_right"></i></a></span>
        </div>
    </div>
    <?php break; ?>

<?php case 'news_article': ?>
<?php case 'default': ?>
    <div class="news-feed">
        <div class="container">
            <h2>Columbia Law in the Press</h2>
            <div class="news-feed__frame">
                <div class="row">

                    <?php foreach($view->result AS $key => $item) : ?>
                        <div class="col-sm-4 col-xs-12 news-feed__wrap">
                            <div class="news-block">
                                <?php $row = _culaw_paragraphs_format_content($item->nid, 'news_feed_row'); ?>
                                <div class="news-block__head-wrap">
                                    <span class="news-block__text"><?php print $row['category']; ?></span>
                                </div>
                                <p><?php print $row['summary']; ?></p>
                                <div class="news-block__time-wrap">
                                    <span class="news-block__newspapper"><a href="<?php print $row['url']; ?>"><?php print $row['source']; ?></a></span>
                                    <time datetime="2017-04-12"><?php print $row['date']['date']; ?></time>
                                </div>
                            </div>
                        </div>
                    <?php endforeach; ?>

                </div>
            </div>
        </div>
    </div>
    <?php break; ?>

<?php endswitch; ?>