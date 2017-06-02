<?php
/**
 * @file
 * cls_news_articles.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function cls_news_articles_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addthis_508_compliant';
  $strongarm->value = 0;
  $export['addthis_508_compliant'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addthis_addressbook_enabled';
  $strongarm->value = 0;
  $export['addthis_addressbook_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addthis_bookmark_url';
  $strongarm->value = 'https://www.addthis.com/bookmark.php?v=300';
  $export['addthis_bookmark_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addthis_click_to_open_compact_menu_enabled';
  $strongarm->value = 0;
  $export['addthis_click_to_open_compact_menu_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addthis_clickback_tracking_enabled';
  $strongarm->value = 0;
  $export['addthis_clickback_tracking_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addthis_co_brand';
  $strongarm->value = '';
  $export['addthis_co_brand'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addthis_enabled_services';
  $strongarm->value = array(
    'buffer' => 'buffer',
    'mailto' => 'mailto',
    'gmail' => 'gmail',
    'linkedin' => 'linkedin',
    'pinterest_share' => 'pinterest_share',
    'tumblr' => 'tumblr',
    '100zakladok' => 0,
    'addressbar' => 0,
    'adfty' => 0,
    'adifni' => 0,
    'advqr' => 0,
    'amazonwishlist' => 0,
    'amenme' => 0,
    'aim' => 0,
    'aolmail' => 0,
    'apsense' => 0,
    'arto' => 0,
    'baidu' => 0,
    'balatarin' => 0,
    'beat100' => 0,
    'bitly' => 0,
    'bizsugar' => 0,
    'bland' => 0,
    'blogger' => 0,
    'blogkeen' => 0,
    'blogmarks' => 0,
    'bobrdobr' => 0,
    'bonzobox' => 0,
    'bookmarkycz' => 0,
    'bookmerkende' => 0,
    'box' => 0,
    'camyoo' => 0,
    'care2' => 0,
    'foodlve' => 0,
    'citeulike' => 0,
    'cleanprint' => 0,
    'cleansave' => 0,
    'cndig' => 0,
    'colivia' => 0,
    'technerd' => 0,
    'link' => 0,
    'cosmiq' => 0,
    'cssbased' => 0,
    'delicious' => 0,
    'diary_ru' => 0,
    'digg' => 0,
    'diggita' => 0,
    'digo' => 0,
    'diigo' => 0,
    'douban' => 0,
    'draugiem' => 0,
    'edcast' => 0,
    'efactor' => 0,
    'email' => 0,
    'evernote' => 0,
    'exchangle' => 0,
    'stylishhome' => 0,
    'fabulously40' => 0,
    'facebook' => 0,
    'facebook_like' => 0,
    'informazione' => 0,
    'thefancy' => 0,
    'fashiolista' => 0,
    'favable' => 0,
    'faves' => 0,
    'favorites' => 0,
    'favoritus' => 0,
    'financialjuice' => 0,
    'flipboard' => 0,
    'folkd' => 0,
    'foursquare' => 0,
    'thefreedictionary' => 0,
    'gg' => 0,
    'govn' => 0,
    'google_plusone' => 0,
    'google' => 0,
    'google_classroom' => 0,
    'googleplus' => 0,
    'googletranslate' => 0,
    'google_plusone_share' => 0,
    'hackernews' => 0,
    'hatena' => 0,
    'hedgehogs' => 0,
    'historious' => 0,
    'hootsuite' => 0,
    'w3validator' => 0,
    'indexor' => 0,
    'instapaper' => 0,
    'iorbix' => 0,
    'jappy' => 0,
    'kaixin' => 0,
    'kakao' => 0,
    'ketnooi' => 0,
    'kik' => 0,
    'kindleit' => 0,
    'kledy' => 0,
    'lidar' => 0,
    'lineme' => 0,
    'linkuj' => 0,
    'livejournal' => 0,
    'mymailru' => 0,
    'margarin' => 0,
    'markme' => 0,
    'meinvz' => 0,
    'memonic' => 0,
    'memori' => 0,
    'mendeley' => 0,
    'meneame' => 0,
    'mixi' => 0,
    'moemesto' => 0,
    'mrcnetworkit' => 0,
    'myspace' => 0,
    'myvidster' => 0,
    'n4g' => 0,
    'naszaklasa' => 0,
    'netvibes' => 0,
    'netvouz' => 0,
    'newsmeback' => 0,
    'newsvine' => 0,
    'nujij' => 0,
    'nurses_lounge' => 0,
    'odnoklassniki_ru' => 0,
    'oknotizie' => 0,
    'openthedoor' => 0,
    'hotmail' => 0,
    'oyyla' => 0,
    'pafnetde' => 0,
    'pdfmyurl' => 0,
    'pinboard' => 0,
    'pinterest' => 0,
    'plurk' => 0,
    'pocket' => 0,
    'posteezy' => 0,
    'print' => 0,
    'printfriendly' => 0,
    'pusha' => 0,
    'qrsrc' => 0,
    'quantcast' => 0,
    'qzone' => 0,
    'reddit' => 0,
    'rediff' => 0,
    'renren' => 0,
    'researchgate' => 0,
    'retellity' => 0,
    'safelinking' => 0,
    'scoopit' => 0,
    'sinaweibo' => 0,
    'skyrock' => 0,
    'slack' => 0,
    'smiru' => 0,
    'sodahead' => 0,
    'spinsnap' => 0,
    'startaid' => 0,
    'startlap' => 0,
    'studivz' => 0,
    'stuffpit' => 0,
    'stumbleupon' => 0,
    'stumpedia' => 0,
    'supbro' => 0,
    'surfingbird' => 0,
    'svejo' => 0,
    'symbaloo' => 0,
    'taringa' => 0,
    'telegram' => 0,
    'tencentqq' => 0,
    'tencentweibo' => 0,
    'thisnext' => 0,
    'trello' => 0,
    'tuenti' => 0,
    'twitter' => 0,
    'typepad' => 0,
    'urlaubswerkde' => 0,
    'viadeo' => 0,
    'viber' => 0,
    'virb' => 0,
    'visitezmonsite' => 0,
    'vk' => 0,
    'vkrugudruzei' => 0,
    'voxopolis' => 0,
    'vybralisme' => 0,
    'wanelo' => 0,
    'internetarchive' => 0,
    'sharer' => 0,
    'webnews' => 0,
    'wechat' => 0,
    'whatsapp' => 0,
    'domaintoolswhois' => 0,
    'wirefan' => 0,
    'wishmindr' => 0,
    'wordpress' => 0,
    'wykop' => 0,
    'xing' => 0,
    'yahoomail' => 0,
    'yammer' => 0,
    'yookos' => 0,
    'yoolink' => 0,
    'yorumcuyum' => 0,
    'youmob' => 0,
    'yummly' => 0,
    'yuuby' => 0,
    'zakladoknet' => 0,
    'ziczac' => 0,
    'zingme' => 0,
  );
  $export['addthis_enabled_services'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addthis_excluded_services';
  $strongarm->value = array(
    '100zakladok' => 0,
    'addressbar' => 0,
    'adfty' => 0,
    'adifni' => 0,
    'advqr' => 0,
    'amazonwishlist' => 0,
    'amenme' => 0,
    'aim' => 0,
    'aolmail' => 0,
    'apsense' => 0,
    'arto' => 0,
    'baidu' => 0,
    'balatarin' => 0,
    'beat100' => 0,
    'bitly' => 0,
    'bizsugar' => 0,
    'bland' => 0,
    'blogger' => 0,
    'blogkeen' => 0,
    'blogmarks' => 0,
    'bobrdobr' => 0,
    'bonzobox' => 0,
    'bookmarkycz' => 0,
    'bookmerkende' => 0,
    'box' => 0,
    'buffer' => 0,
    'camyoo' => 0,
    'care2' => 0,
    'foodlve' => 0,
    'citeulike' => 0,
    'cleanprint' => 0,
    'cleansave' => 0,
    'cndig' => 0,
    'colivia' => 0,
    'technerd' => 0,
    'link' => 0,
    'cosmiq' => 0,
    'cssbased' => 0,
    'delicious' => 0,
    'diary_ru' => 0,
    'digg' => 0,
    'diggita' => 0,
    'digo' => 0,
    'diigo' => 0,
    'douban' => 0,
    'draugiem' => 0,
    'edcast' => 0,
    'efactor' => 0,
    'email' => 0,
    'mailto' => 0,
    'evernote' => 0,
    'exchangle' => 0,
    'stylishhome' => 0,
    'fabulously40' => 0,
    'facebook' => 0,
    'facebook_like' => 0,
    'informazione' => 0,
    'thefancy' => 0,
    'fashiolista' => 0,
    'favable' => 0,
    'faves' => 0,
    'favorites' => 0,
    'favoritus' => 0,
    'financialjuice' => 0,
    'flipboard' => 0,
    'folkd' => 0,
    'foursquare' => 0,
    'thefreedictionary' => 0,
    'gg' => 0,
    'gmail' => 0,
    'govn' => 0,
    'google_plusone' => 0,
    'google' => 0,
    'google_classroom' => 0,
    'googleplus' => 0,
    'googletranslate' => 0,
    'google_plusone_share' => 0,
    'hackernews' => 0,
    'hatena' => 0,
    'hedgehogs' => 0,
    'historious' => 0,
    'hootsuite' => 0,
    'w3validator' => 0,
    'indexor' => 0,
    'instapaper' => 0,
    'iorbix' => 0,
    'jappy' => 0,
    'kaixin' => 0,
    'kakao' => 0,
    'ketnooi' => 0,
    'kik' => 0,
    'kindleit' => 0,
    'kledy' => 0,
    'lidar' => 0,
    'lineme' => 0,
    'linkedin' => 0,
    'linkuj' => 0,
    'livejournal' => 0,
    'mymailru' => 0,
    'margarin' => 0,
    'markme' => 0,
    'meinvz' => 0,
    'memonic' => 0,
    'memori' => 0,
    'mendeley' => 0,
    'meneame' => 0,
    'mixi' => 0,
    'moemesto' => 0,
    'mrcnetworkit' => 0,
    'myspace' => 0,
    'myvidster' => 0,
    'n4g' => 0,
    'naszaklasa' => 0,
    'netvibes' => 0,
    'netvouz' => 0,
    'newsmeback' => 0,
    'newsvine' => 0,
    'nujij' => 0,
    'nurses_lounge' => 0,
    'odnoklassniki_ru' => 0,
    'oknotizie' => 0,
    'openthedoor' => 0,
    'hotmail' => 0,
    'oyyla' => 0,
    'pafnetde' => 0,
    'pdfmyurl' => 0,
    'pinboard' => 0,
    'pinterest_share' => 0,
    'pinterest' => 0,
    'plurk' => 0,
    'pocket' => 0,
    'posteezy' => 0,
    'print' => 0,
    'printfriendly' => 0,
    'pusha' => 0,
    'qrsrc' => 0,
    'quantcast' => 0,
    'qzone' => 0,
    'reddit' => 0,
    'rediff' => 0,
    'renren' => 0,
    'researchgate' => 0,
    'retellity' => 0,
    'safelinking' => 0,
    'scoopit' => 0,
    'sinaweibo' => 0,
    'skyrock' => 0,
    'slack' => 0,
    'smiru' => 0,
    'sodahead' => 0,
    'spinsnap' => 0,
    'startaid' => 0,
    'startlap' => 0,
    'studivz' => 0,
    'stuffpit' => 0,
    'stumbleupon' => 0,
    'stumpedia' => 0,
    'supbro' => 0,
    'surfingbird' => 0,
    'svejo' => 0,
    'symbaloo' => 0,
    'taringa' => 0,
    'telegram' => 0,
    'tencentqq' => 0,
    'tencentweibo' => 0,
    'thisnext' => 0,
    'trello' => 0,
    'tuenti' => 0,
    'tumblr' => 0,
    'twitter' => 0,
    'typepad' => 0,
    'urlaubswerkde' => 0,
    'viadeo' => 0,
    'viber' => 0,
    'virb' => 0,
    'visitezmonsite' => 0,
    'vk' => 0,
    'vkrugudruzei' => 0,
    'voxopolis' => 0,
    'vybralisme' => 0,
    'wanelo' => 0,
    'internetarchive' => 0,
    'sharer' => 0,
    'webnews' => 0,
    'wechat' => 0,
    'whatsapp' => 0,
    'domaintoolswhois' => 0,
    'wirefan' => 0,
    'wishmindr' => 0,
    'wordpress' => 0,
    'wykop' => 0,
    'xing' => 0,
    'yahoomail' => 0,
    'yammer' => 0,
    'yookos' => 0,
    'yoolink' => 0,
    'yorumcuyum' => 0,
    'youmob' => 0,
    'yummly' => 0,
    'yuuby' => 0,
    'zakladoknet' => 0,
    'ziczac' => 0,
    'zingme' => 0,
  );
  $export['addthis_excluded_services'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addthis_facebook_like_count_support_enabled';
  $strongarm->value = 1;
  $export['addthis_facebook_like_count_support_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addthis_google_analytics_social_tracking_enabled';
  $strongarm->value = 0;
  $export['addthis_google_analytics_social_tracking_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addthis_google_analytics_tracking_enabled';
  $strongarm->value = 0;
  $export['addthis_google_analytics_tracking_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addthis_open_windows_enabled';
  $strongarm->value = 0;
  $export['addthis_open_windows_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addthis_profile_id';
  $strongarm->value = '';
  $export['addthis_profile_id'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addthis_services_css_url';
  $strongarm->value = 'https://cache.addthiscdn.com/icons/v1/sprites/services.css';
  $export['addthis_services_css_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addthis_services_json_url';
  $strongarm->value = 'https://cache.addthiscdn.com/services/v1/sharing.en.json';
  $export['addthis_services_json_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addthis_standard_css_enabled';
  $strongarm->value = 1;
  $export['addthis_standard_css_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addthis_twitter_template';
  $strongarm->value = '{{title}} {{url}} via @AddThis';
  $export['addthis_twitter_template'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addthis_twitter_via';
  $strongarm->value = 'AddThis';
  $export['addthis_twitter_via'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addthis_ui_delay';
  $strongarm->value = '0';
  $export['addthis_ui_delay'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addthis_ui_header_background_color';
  $strongarm->value = '';
  $export['addthis_ui_header_background_color'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addthis_ui_header_color';
  $strongarm->value = '';
  $export['addthis_ui_header_color'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addthis_widget_js_url';
  $strongarm->value = 'https://s7.addthis.com/js/300/addthis_widget.js';
  $export['addthis_widget_js_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cls_news_article_media_contact';
  $strongarm->value = array(
    'value' => '<p>Public Affairs, 212-854-2650 or&nbsp;<a href="mailto:publicaffairs@law.columbia.edu">publicaffairs@law.columbia.edu</a></p>',
    'format' => 'full_html',
  );
  $export['cls_news_article_media_contact'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_access_news_article';
  $strongarm->value = array(
    'view_own' => array(
      0 => 1,
      1 => 2,
      2 => 22,
      3 => 27,
      4 => 3,
      5 => 217,
    ),
    'view' => array(
      0 => 1,
      1 => 2,
      2 => 22,
      3 => 27,
      4 => 3,
      5 => 217,
    ),
    'per_node' => 1,
  );
  $export['content_access_news_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__news_article';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'locations' => array(
          'weight' => '30',
        ),
        'metatags' => array(
          'weight' => '10',
        ),
        'title' => array(
          'weight' => '-5',
        ),
        'path' => array(
          'weight' => '30',
        ),
        'redirect' => array(
          'weight' => '30',
        ),
        'xmlsitemap' => array(
          'weight' => '30',
        ),
      ),
      'display' => array(
        'news_article_media_contact' => array(
          'default' => array(
            'weight' => '3',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__news_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_news_article_pattern';
  $strongarm->value = 'news/[node:field-publish-date:custom:Y]/[node:field-publish-date:custom:m]/[node:title]';
  $export['pathauto_node_news_article_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_apc_content_categories_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_apc_content_categories_pattern'] = $strongarm;

  return $export;
}
