<?php
/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template in this directory.
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
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['header']: Items for the header region.
 * - $page['footer']: Items for the footer region.
 *
 * @see bootstrap_preprocess_page()
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see bootstrap_process_page()
 * @see template_process()
 * @see html.tpl.php
 *
 * @ingroup templates
 */
?>
<?php if (!empty($cls_site_announcement)): ?>
  <div class="announcement__container">
    <div class="alert">
      <a href="#" class="close" data-dismiss="alert" aria-label="close">&times;</a>
      <div class="announcement"><span class="alert__title">Alert: </span><span class="alert__message"><?php print $cls_site_announcement; ?></span></div>
    </div>
  </div>
<?php endif; ?>

<div class="main-container" id="wrapper">

  <header role="banner" id="page-header">
    <?php if (!empty($site_slogan)): ?>
      <p class="lead"><?php print $site_slogan; ?></p>
    <?php endif; ?>

    <?php if (!empty($page['header_top'])): ?>
      <div class="header__top">
        <?php print render($page['header_top']); ?>
      </div>
    <?php endif; ?>

    <div class="header__container">
      <?php if ($logo): ?>
        <div class="site__logo">
          <a class="logo navbar-btn pull-left" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
            <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
          </a>
        </div>
      <?php endif; ?>
      <?php print render($page['header']); ?>
    </div>
  </header> <!-- /#page-header -->

  <?php if (!empty($page['sub_featured'])): ?>
    <div class="col-sm-12 sub__feature">
      <?php print render($page['sub_featured']); ?>
    </div>  <!-- /Sub Featured Content -->
  <?php endif; ?>

  <div class="row">

    <section class="col-sm-12">
      <?php if (!empty($page['highlighted'])): ?>
        <div class="highlighted jumbotron"><?php print render($page['highlighted']); ?></div>
      <?php endif; ?>
      <a id="main-content"></a>

      <?php print $messages; ?>
      <?php if (!empty($tabs)): ?>
        <?php print render($tabs); ?>
      <?php endif; ?>
      <?php if (!empty($page['help'])): ?>
        <?php print render($page['help']); ?>
      <?php endif; ?>
      <?php if (!empty($action_links)): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>

      <main>
        <div class="sidebar__first">
          <?php if (!empty($page['sidebar_first'])): ?>
            <aside class="col-sm-3" role="complementary">
              <?php print render($page['sidebar_first']); ?>
            </aside>  <!-- /#sidebar-first -->
          <?php endif; ?>
        </div>
        <header class="heading-area">
          <!-- breadcrumbs area -->
          <?php
          if (!empty($breadcrumb)) {
            print ('<div class="breadcrumb-area hidden-xs"><div class="container">' . $breadcrumb . '</div></div>');
          }
          ?>

          <div class="container">
            <div class="heading-wrap">

              <?php if (!empty($title)): ?>
                <h1 class="page-header"><?php print $title; ?></h1>
              <?php endif; ?>

              <?php $block = module_invoke('menu_block', 'block_view', 1); ?>
              <?php if (count($block['content'])) : ?>
                <div class="heading-area__btn-wrap">
                  <?php
                    $block['content']['#theme'] = array('menu_block_wrapper__secondary_nav');
                    $secondary_nav_title = render($block['subject']);
                    print str_replace(' class="',' class="heading-area__back-btn ',$secondary_nav_title);
                    print render($block['content']);
                  ?>
                </div>
              <?php endif; ?>

            </div>
          </div>
        </header>

        <?php print render($page['top_content']); ?>
        <?php print render($page['content']); ?>
      </main>

      <div class="sub__content">
        <?php print render($page['sub_content']); ?>
      </div>

    </section>

    <?php if (!empty($page['sidebar_second'])): ?>
      <aside class="col-sm-3" role="complementary">
        <?php print render($page['sidebar_second']); ?>
      </aside>  <!-- /#sidebar-second -->
    <?php endif; ?>

  </div>
</div>

<?php if (!empty($page['footer'])): ?>
  <footer class="footer <?php print $container_class; ?>">
    <?php print render($page['footer']); ?>
  </footer>
<?php endif; ?>

<?php if (!empty($page['footer_bottom'])): ?>
  <div class="footer__bottom">
    <?php print render($page['footer_bottom']); ?>
  </div>
<?php endif; ?>
