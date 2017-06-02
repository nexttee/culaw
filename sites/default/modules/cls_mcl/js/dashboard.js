(function ($) {
  Drupal.behaviors.clsmcldashboard = {
    attach: function(context, settings) {
      try {
        $(document).ready(function() {
          $('.tab-btn-custom a').each(function() {
            $(this).attr('data-href', $(this).attr('href'));
            $(this).removeAttr('href');
          });
          $('#my-courses-tabs').tabs();
          $('#my-faculty-tabs').tabs();
          $('#my-other-areas-tabs').tabs();
          $('.tab-btn-custom a').each(function() {
            $(this).attr('href', $(this).attr('data-href'));
          });

          $('.mcl-interest-jcarousel').jcarousel({
            wrap: 'circular'
          });

          $('.mcl-interest-jcarousel-faculty').jcarousel({
            wrap: 'circular',
            scroll: 2
          });


          var jCarouselHeight = $('.view-cls-mcl-dashboard-courses .mcl-interest-jcarousel').height();
          $('.view-cls-mcl-dashboard-courses .jcarousel-skin-default .jcarousel-next-horizontal, .view-cls-mcl-dashboard-courses .jcarousel-skin-default .jcarousel-prev-horizontal').css('cssText', 'top: ' + ((jCarouselHeight / 2) - 5) + 'px !important;');

          $('.view-cls-mcl-dashboard-faculty-all .mcl-interest-jcarousel-faculty ul li').each(function(){
            if ($(this).find('.views-field-image').length == 0) {
              $(this).children().css({"margin-left": 0});
            }
          });
        });
      } catch (e) {};
    }
  };
})(jQuery);
