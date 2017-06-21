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
<div class="super-container" >
  <div class="container">
    <div id="skip"><a href="#global-header" class="hide">Skip to site navigation and search</a></div>
    <div id="page" class="<?php print $classes; ?>"<?php print $attributes; ?>>
<?php if( extension_loaded('newrelic') ) { echo newrelic_get_browser_timing_header(); } ?>
      <h1 class="logo"><a href="<?php print $base_path; ?>"><?php if ($title) { print $title; } ?> | <?php if ($site_name) { print $site_name; } ?></a><img src="<?php print $base_path; ?><?php echo drupal_get_path('theme', 'cls'); ?>/images/logo-print-columbia-law-school.gif" height="0" width="0" style="display: none;" /></h1>
      <div class="content-container">
        <div class="content-header">
    <?php print render($page['microsite_navigation']); ?>
        <h2><?php if (!empty($section_title)): ?><?php if (!empty($microsite_root_path)): ?><a href="/<?php print $microsite_root_path; ?>"><?php endif; ?><?php print $section_title; ?><?php if (!empty($microsite_root_path)): ?></a><?php endif; ?><?php if (!empty($section_subtitle)) { print " &raquo; "; } ?><?php if (!empty($microsite_subsection_root_path)): ?><a href="/<?php print $microsite_subsection_root_path; ?>"><?php endif; ?><?php if (!empty($section_subtitle)) { print $section_subtitle; } ?><?php if (!empty($microsite_subsection_root_path)): ?></a><?php endif; ?><?php elseif ($title): ?><?php print $title; ?><?php else: ?>Columbia Law School<?php endif; ?></h2>
        <?php print render($page['banner']); ?>
      </div>
      <div class="group clearfix content-main-area">
        <div class="fourcol clearfix">
          <?php print render($page['sidebar_first']); ?>
          <?php print render($page['sidebar_second']); ?>
        </div>
        <div class="twelvecol contextual-links-region">
          <?php print $messages; ?>
          <?php print render($page['help']); ?>
          <?php print render($tabs); ?>
          <?php if ($action_links): ?>
            <ul class="action-links">
              <?php print render($action_links); ?>
            </ul>
          <?php endif; ?>
          <?php print render($page['content']); ?>
          <?php print render($page['content_bottom']); ?>
        </div>
      </div>
    </div>
  </div>
  <div class="dashboard group sixteencol-omega-alpha">
    <div class="fourcol navigate-microsite">
      <h3>Navigate <?php if (!empty($section_subtitle)) { print $section_subtitle; } else if (!empty($section_title)) { print $section_title; } else if ($title) { print $title; } else { print "Columbia Law School"; } ?></h3>
      <div class="twocol-alpha">
        <?php print render($page['dashboard_navigate_section']); ?>
      </div>
      <div class="twocol-omega">&nbsp;</div>
    </div>
    <div class="fourcol navigate-site">
      <h3>Navigate the site</h3>
      <div class="twocol-alpha">
        <ul>
          <li><a href="<?php print $base_path; ?>">Home</a></li>
        </ul>
        <ul>
          <li><a href="<?php print $base_path; ?>about">About the School</a></li>
          <li><a href="<?php print $base_path; ?>admissions">Admissions</a></li>
        </ul>
        <ul>
          <li><a href="<?php print $base_path; ?>academics">Academics</a></li>
          <li><a href="<?php print $base_path; ?>faculty">Faculty</a></li>
          <li><a href="<?php print $base_path; ?>programs">Centers and Programs</a></li>
          <li><a href="<?php print $base_path; ?>courses">Courses</a></li>
        </ul>
        <ul>
          <li><a href="<?php print $base_path; ?>students">Students</a></li>
          <li><a href="https://lawnetportal.law.columbia.edu">LawNet</a></li>
        </ul>
      </div>
      <div class="twocol-omega">
        <ul>
          <li><a href="<?php print $base_path; ?>events">School Events</a></li>
          <li><a href="<?php print $base_path; ?>academic-calendar">Academic Calendar</a></li>
        </ul>
        <ul>
          <li><a href="<?php print $base_path; ?>news">School News</a></li>
          <li><a href="<?php print $base_path; ?>magazine">Magazine</a></li>
        </ul>
        <ul>
          <li><a href="<?php print $base_path; ?>alumni">Alumni</a></li>
          <li><a href="<?php print $base_path; ?>giving">Giving</a></li>
        </ul>
        <ul>
          <li><a href="<?php print $base_path; ?>careers">Careers</a></li>
          <li><a href="<?php print $base_path; ?>library">Library</a></li>
        </ul>
      </div>
    </div>
    <div class="sixcol messaging-and-marketing">
      <?php print render($page['dashboard_messaging_and_marketing_section']); ?>
    </div>
    <div class="twocol share-and-connect">
      <h3>Share Page</h3>
      <ul>
        <!--<li><a href="#">Email this</a></li>-->
        <li><a href="http://www.facebook.com/share.php?u=<?php print urlencode(url($_GET['q'], $options = array('absolute' => TRUE))); ?>" onclick="return sharePageFacebook()" target="_blank">Facebook</a></li>
        <li><a href="http://twitter.com/home?status=Currently%20reading%20<?php print urlencode(url($_GET['q'], $options = array('absolute' => TRUE))); ?>" onclick="return sharePageTwitter()" target="_blank">Twitter</a></li>
        <li><a href="http://www.linkedin.com/shareArticle?mini=true&amp;url=<?php print urlencode(url($_GET['q'], $options = array('absolute' => TRUE))); ?>&amp;title=<?php print urlencode($title) . urlencode(' | Columbia Law School'); ?>" onclick="return sharePageLinkedIn()" target="_blank">LinkedIn</a></li>
      </ul>
      <h3>Connect</h3>
      <ul>
        <li><a href="http://www.facebook.com/pages/New-York-NY/Columbia-Law-School-Alumni/72602371663">Facebook</a></li>
        <li><a href="https://www.linkedin.com/edu/school?id=18944">LinkedIn</a></li>
        <li><a href="http://twitter.com/ColumbiaLaw" onclick="pageTracker._trackEvent('External Links', 'Click', 'Twitter Link - Dashboard');">Twitter</a></li>
      </ul>
    </div>
  </div>
  <div id="global-header" class="global-header clearfix">
    <div class="tools-and-search">
      <?php
        $block = module_invoke('search', 'block_view');
        print render($block['content']);
      ?>
      <ul>
        <li><?php if (!$logged_in): ?><!-- <span class="nav-login-placeholder">&nbsp;</span> --><a class="nav-log-in" href="<?php print $secure_base_url ?><?php print $base_path; ?>sso/login?destination=<?php $destination = drupal_get_destination(); print $destination['destination'] ?>">Log in</a><?php else: ?><a class="nav-log-out" href="<?php print $base_path; ?>user/logout">Log out</a><?php endif; ?></li>
        <li><a class="nav-news" href="<?php print $base_path; ?>news">News</a></li>
        <li><a class="nav-events" href="<?php print $base_path; ?>events">Events</a></li>
      </ul>
    </div>
    <ul class="global-navigation">
      <li><a class="nav-admissions" href="<?php print $base_path; ?>admissions">Admissions</a></li>
      <li><a class="nav-students" href="<?php print $base_path; ?>students">Students</a></li>
      <li><a class="nav-faculty" href="<?php print $base_path; ?>faculty">Faculty</a></li>
      <li><a class="nav-alumni" href="<?php print $base_path; ?>alumni">Alumni</a></li>
      <li><a class="nav-careers" href="<?php print $base_path; ?>careers">Careers</a></li>
      <li><a class="nav-library" href="<?php print $base_path; ?>library">Library</a></li>
      <li><a class="nav-programs" href="<?php print $base_path; ?>programs">Programs</a></li>
    </ul>
  </div>
  <div id="footer">
    <p><a href="<?php print $base_path; ?>" class="logotype">Go to the Columbia Law School homepage</a></p>
    <div>
      <ul>
        <li><a href="<?php print $base_path; ?>directory">Directory</a></li>
        <li><a href="<?php print $base_path; ?>about/map-directions">Campus Map</a></li>
        <li><a href="http://www.columbia.edu/">Columbia University</a></li>
        <li><a href="http://www.columbia.edu/content/employment-columbia.html">Jobs at Columbia</a></li>
        <li><a href="<?php print $base_path; ?>business-office/policies">Policies</a></li>
        <li><a href="<?php print $base_path; ?>about/contact-us">Contact Us</a></li>
      </ul>
      <p>&copy; Copyright <?php echo date('Y'); ?>, The Trustees of Columbia University in the City of New York. For questions or comments, please contact the <a id="webmasteremaillink" href="mailto:webadmin@law.columbia.edu">web administrators</a>.</p>
    </div>
  </div>
  <?php if( extension_loaded('newrelic') ) { echo newrelic_get_browser_timing_footer(); } ?>
  <?php print render($page['mycl_toolbar']); ?>
</div>
