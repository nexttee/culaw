<?php
/**
 * @file
 * culaw_paragraphs.box.inc
 */

/**
 * Implements hook_default_box().
 */
function culaw_paragraphs_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'event_listing_archive';
  $box->plugin_key = 'simple';
  $box->title = 'News Archive ';
  $box->description = 'Archive links for News Listing';
  $box->options = array(
    'body' => array(
      'value' => '<ul class="monthlinks"></ul>
<script>
jQuery(document).ready(function($){

var year = checkString(window.location.href,\'/\');
if(year.split(\'-\').length == 1)
{
//year month, hide content
$(".view-news-listing").hide();
} else {
$(".monthlinks").hide();
}


year = year.split(\'-\')[0];


var monthNameList = ["Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"];

var links = "";
for(i=1;  i <= 12; i++)
{
links += "<li><a href=\'/news-listing/" + year + "-" + i + "\'>" + monthNameList[i-1] + " "  + year + "</a></li>";
}

$(".monthlinks").append(links);

function firstItem(stringToCheck,divider) {
    var list1 = stringToCheck.split(divider);
return list1;
}
function checkString(stringToCheck, divider) {
    var list1 = stringToCheck.split(divider);
    if (list1[list1.length - 1].length < 1) {
        var item = list1[list1.length - 2]
    } else {
       var item = list1[list1.length - 1];
    }
    return item;
}

});
</script>
<ul>
<li><a href="/news-listing/2017">2017</a></li>
<li><a href="/news-listing/2016">2016</a></li>
<li><a href="/news-listing/2015">2015</a></li>
<li><a href="/news-listing/2014">2014</a></li>
</ul>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['event_listing_archive'] = $box;

  return $export;
}
