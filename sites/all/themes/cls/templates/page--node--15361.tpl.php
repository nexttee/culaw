<?php
/**
 * @file
 * CLS's theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template normally located in the
 * modules/system folder.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 * - $hide_site_name: TRUE if the site name has been toggled off on the theme
 *   settings page. If hidden, the "element-invisible" class is added to make
 *   the site name visually hidden, but still accessible.
 * - $hide_site_slogan: TRUE if the site slogan has been toggled off on the
 *   theme settings page. If hidden, the "element-invisible" class is added to
 *   make the site slogan visually hidden, but still accessible.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['banner']: Items for the banner region.
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['dashboard_navigate_section']: Items for the Dashboard's Navigate
 *   section.
 * - $page['dashboard_messaging_and_marketing_section']: Items for the
 *   Dashboard's Messaging and Marketing section.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see template_process()
 * @see cls_process_page()
 */

/**
 * Add $microsite_head_tags to the page title
 */
if (!empty($microsite_head_tags)) {
  $element = array(
    '#type' => 'markup',
    '#markup' => $microsite_head_tags,
  );
  drupal_add_html_head($element, 'microsite_head_tags');
}

global $base_url;
$secure_base_url = str_replace('http:', 'https:', $base_url);
?>
<link type="text/css" rel="stylesheet" href="/sites/all/themes/custom/culaw/build/main.css">
<link type="text/css" rel="stylesheet" href="/sites/all/themes/custom/cls/css/admission.css">
<link type="text/css" rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css" media="all" />
<link type="text/css" rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css" media="all" />
<div class="" >

<div class="main-container container">

  <header role="banner" id="page-header">
    <?php if (!empty($site_slogan)): ?>
      <p class="lead"><?php print $site_slogan; ?></p>
    <?php endif; ?>

    <div class="header__container">
        <div class="site__logo">
          <div class="inner-container container">
            <a class="logo navbar-btn" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
              <img src="sites/all/themes/custom/cls/images/admissions/logo.png" alt="<?php print t('Home'); ?>" />
            </a>
            <a class="site__main-link" href="/">Visit the Law School's Homepage</a>
          </div>
        </div>

      <div class="region region-header banner">
        <img class="banner__image" src="sites/all/themes/custom/cls/images/admissions/banner.jpg" alt="banner" />
        <div class="banner__content">
          <div class="banner__title">Explore Columbia Law School</div>
          <div class="banner__subtitle">Build a career. Change the world.</div>
        </div>
      </div>
    </div>
  </header> <!-- /#page-header -->

  <div class="intro container">
      <div class="intro__text">
        Columbia Law School offers a rich intellectual experience with practical and far-reaching applications. Our students go on to practice law as part of an international community of innovative professionals and dynamic leaders who set the highest standards.
      </div>
    </div>

    <div class="spotlight-container container">
      <a class="spotlight" href="http://www3.law.columbia.edu/admissions/viewbook/international/introduction.html" target="_blank">
        <img src="sites/all/themes/custom/cls/images/admissions/global.jpg" class="spotlight__image" />
        <div class="spotlight__content">
          <div class="spotlight__title">Global and International Law</div>
          <div class="spotlight__blurb">Our curriculum is infused with a global perspective. Learn about Rights & Freedom, Conflict & Security, Property & Markets, Governance & Cooperation.</div>
        </div>
      </a>
      <a class="spotlight" href="http://www3.law.columbia.edu/admissions/viewbook/public-interest/introduction.html" target="_blank">
        <img src="sites/all/themes/custom/cls/images/admissions/publicinterest.jpg" class="spotlight__image" />
        <div class="spotlight__content">
          <div class="spotlight__title">Public Interest and Human Rights Law</div>
          <div class="spotlight__blurb">Providing legal representation and advocating for underserved populations is a privilege and responsibility of the Columbia community.</div>
        </div>
      </a>
      <a class="spotlight" href="http://www3.law.columbia.edu/admissions/viewbook/business/introduction.html" target="_blank">
        <img src="sites/all/themes/custom/cls/images/admissions/lawandbusiness.jpg" class="spotlight__image" />
        <div class="spotlight__content">
          <div class="spotlight__title">Law and Business</div>
          <div class="spotlight__blurb">Our leafy campus is in the capital of capital. There is simply no better place than New York to learn about Wall Street, startup funding, the ins and outs of corporate law, or entrepreneurship.</div>
        </div>
      </a>
      <a class="spotlight" href="http://www3.law.columbia.edu/admissions/viewbook/ip/introduction.html" target="_blank">
        <img src="sites/all/themes/custom/cls/images/admissions/intellectualproperty.jpg" class="spotlight__image" />
        <div class="spotlight__content">
          <div class="spotlight__title">Intellectual Property Law</div>
          <div class="spotlight__blurb">As a fashion, media, and tech hub, New York is a laboratory for cutting-edge conversation and litigation affecting us 24/7.</div>
        </div>
      </a>
      <a class="spotlight" href="http://www3.law.columbia.edu/admissions/viewbook/clinics/introduction.html" target="_blank">
        <img src="sites/all/themes/custom/cls/images/admissions/clinicallegal.jpg" class="spotlight__image" />
        <div class="spotlight__content">
          <div class="spotlight__title">Clinical Education and Experiential Learning</div>
          <div class="spotlight__blurb">Prep a witness. Submit a brief. Go to court. Nothing beats representing a client or fighting for a policy change to make you feel like a lawyer.</div>
        </div>
      </a>
      <a class="spotlight" href="http://www3.law.columbia.edu/admissions/viewbook/environmental/introduction.html" target="_blank">
        <img src="sites/all/themes/custom/cls/images/admissions/enviro.jpg" class="spotlight__image" />
        <div class="spotlight__content">
          <div class="spotlight__title">Environmental and Energy Law</div>
          <div class="spotlight__blurb">Columbia’s Sabin Center for Climate Change Law and the University’s Earth Institute are premier places to research regulatory issues, promote sustainability, and shape public policy.</div>
        </div>
      </a>
    </div>


  <footer class="footer container">
    <div class="region region-footer">
        <section id="block-cls-core-address" class="block block-cls-core clearfix">
          <div class="title__wrap">
            <h2 class="block-title">Columbia Law School</h2>
          </div>
          <span class="address">435 West 116th Street</span><span class="city">New York, NY 10027-7297</span><span class="contact">212-854-2640</span>
        </section>

        <section id="block-menu-block-318" class="block block-menu-block block__social-menu clearfix">
          <div class="social-container">
            <div class="title__wrap">
              <h2 class="block-title social__callout">See what <a href="http://twitter.com/ColumbiaLaw">@ColumbiaLaw</a> is all about.</h2>
            </div>
            <div class="social__menu menu-block-wrapper menu-block-318 menu-name-menu-social-menu parent-mlid-0 menu-level-1">
              <ul class="menu nav"><li class="first leaf menu-mlid-82306"><a href="http://twitter.com/ColumbiaLaw" class="social-media-twitter" target="_blank">Twitter</a></li>
                <li class="leaf menu-mlid-82311"><a href="https://www.linkedin.com/edu/columbia-law-school-18944" class="social-media-linkedin" target="_blank">LinkedIn</a></li>
                <li class="last leaf menu-mlid-82321"><a href="https://www.facebook.com/columbialawschool/" class="social-media-facebook" target="_blank">Facebook</a></li>
              </ul>
            </div>
          </div>
        </section>
      </div>
  </footer>



  <div class="footer__bottom">
    <div class="region region-footer-bottom inner-container">
      <section id="block-cls-core-copyright" class="block block-cls-core clearfix">
        <span> &copy; Copyright 2017, The Trustees of Columbia University in the City of New York.</span><span> For questions or comments, please contact the<a href="mailto:webadmin@law.columbia.edu"> web administrators</a></span>
      </section>
      <a class="site__main-link" href="/">Visit the Law School's Homepage</a>
    </div>
  </div>

<script type="text/javascript" src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
  <script type="text/javascript">
  <!--//--><![CDATA[//><!--
  window.CKEDITOR_BASEPATH = '/sites/all/libraries/ckeditor/'
  //--><!]]>
  </script>
  <script type="text/javascript">
  <!--//--><![CDATA[//><!--
  var _gaq = _gaq || [];_gaq.push(["_setAccount", "UA-1387894-7"]);_gaq.push(['_setCustomVar', 1, "User roles", "anonymous user", 1]);_gaq.push(["_trackPageview"]);(function() {var ga = document.createElement("script");ga.type = "text/javascript";ga.async = true;ga.src = "http://web.law.columbia.edu/sites/default/files/googleanalytics/ga.js?ojj0s3";var s = document.getElementsByTagName("script")[0];s.parentNode.insertBefore(ga, s);})();
  //--><!]]>
  </script>
<script type="text/javascript">
  jQuery(window).load(function() {
    adjustPosition(mediaQuery);
  });

  // Initialize the media query
  var mediaQuery = window.matchMedia('(min-width: 1080px)');

  // Add a listen event
  mediaQuery.addListener(adjustPosition);

  // Function to do something with the media query
  function adjustPosition(mediaQuery) {
    if (mediaQuery.matches) {
      jQuery('.spotlight__blurb').each(function(i, obj) {
        var amount = jQuery(this).innerHeight() + 9;
        var size = '-' + amount + 'px';
        jQuery(this).parent().css('bottom', size);
      });
    } else {
      jQuery('.spotlight__content').css('bottom', '0');
    }
  }
</script>
</div>
