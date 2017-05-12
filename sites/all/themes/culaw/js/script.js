(function($, Drupal) {

  Drupal.behaviors.carousel = {

    attach: function(context) {
      $(".carousel").carousel({ interval: 8000 });

      // Carousel infinite loop
      if ($(".jcarousel").length > 0) {
        $(".jcarousel").jcarousel({
          wrap: "circular",
          easing: "linear",
          animation: 700
        });
      }

      // Letter Scroller in Faculty.
      var widthOneItem = parseInt($(".alpha-pagination-list li").first().css("width"), 10);

      $(".view-id-faculty_listing .arrow-left").click(function() {
        $(".alpha-pagination-list").animate({ scrollLeft: "-=" + widthOneItem });
      });

      $(".view-id-faculty_listing .arrow-right").click(function() {
        $(".alpha-pagination-list").animate({ scrollLeft: "+=" + widthOneItem });
      });

      // Faculty field visibility behaviour.
      var LinkParents = $(".field-name-field-faculty-profile-elements > .field-items > .field-item");

      var Link = $(".entity-paragraphs-item .field-name-field-element-name");

      $(Link).click(function(){
        $(this).closest(LinkParents).toggleClass("visible");
      });
    }
  };

  Drupal.behaviors.clone = {

    attach: function() {
      $(".page-events .region-sidebar-second").clone().appendTo(".main__content .view-display-id-events_listing_page .view-header");
    }
  };

  Drupal.behaviors.megaMenuLink = {
    attach: function() {
      $("#boxes-box-adminssions_menu_content_block ul").prepend('<li class="edit first"><a href="/admin/structure/block/manage/boxes/adminssions_menu_content_block/configure?destination=node/89" class="boxes-processed">Edit Box</a></li>');
    }
  };

  Drupal.behaviors.loadMore = {

    attach: function() {

      // Toggle the button text and the homepage sub featured content view display in mobile viewport
      $(".load__more").click(function() {
        $(this).toggleClass("visible").text(function(i, text) {
          return text === "LOAD MORE" ? "SHOW LESS" : "LOAD MORE";
        });
        $('#block-views-009342aafbd1c5ec68d33853b45ae045 h2.block-title').toggleClass('show');
        $(".view-display-id-sub_featured_content_list").toggleClass("show");
      });

      $(".show__more").click(function() {
        $(this).toggleClass("visible").text(function(i, text) {
          return text === "LOAD MORE" ? "SHOW LESS" : "LOAD MORE";
        });
        $(".view-community-content-section li").toggleClass("show");
      });

      $(".main__content .region-sidebar-second .block-mefibs .views-widget-filter-field_lawcal_categories_tid > label").click(function() {
        $(this).parent().addClass("show__category");
      });

      $(".main__content .region-sidebar-second .block-mefibs .views-widget-filter-field_lawcal_categories_tid").prepend("<a href='#' class='close-category'>&times;</a>");

      $(".main__content .region-sidebar-second .close-category").click(function() {
        $(".main__content .region-sidebar-second .block-mefibs .views-widget-filter-field_lawcal_categories_tid").removeClass("show__category");
      });

      $(".main__content .region-sidebar-second #block-cls-core-event-category-search-block .views-widget-filter-field_lawcal_categories_tid > label").click(function() {
        $(this).parent().addClass("show__category");
      });

      $(".main__content #block-cls-core-event-category-search-block .views-widget-filter-field_lawcal_categories_tid").prepend("<a href='#' class='close-category'>&times;</a>");

      $(".main__content .region-sidebar-second .close-category").click(function() {
        $(".main__content #block-cls-core-event-category-search-block .views-widget-filter-field_lawcal_categories_tid").removeClass("show__category");
      });

      var cutCount = 2;

      $(".node-type-calendar .field-name-field-event-description p").each(function(i) {

        i++;

        if (i === cutCount) {
          $(this).addClass("elipsis").after("<div class='read__more'><p>READ MORE</p></div>");
        }

        if (i > cutCount) {
          $(this).addClass("hide__content");
        }
      });

      $(".read__more").click(function() {
        $(this).addClass("hide");
        $(".hide__content").toggleClass("show");
      });

      //  Faculty Section role filter.
      $("#block-cls-core-faculty-role-filter-block .title__wrap").click(function() {
        $("#block-cls-core-faculty-role-filter-block").toggleClass("visible");
      });

      if (!$(".faculty-office-location .field__content").children().length) {
        $(".faculty-office-location").addClass("no__body");
      }

      if (!$(".assistant-information .field__content").children().length) {
        $(".assistant-information").addClass("no__body");
      }

      if (!$(".faculty-contact-info .field__content").children().length) {
        $(".faculty-contact-info").addClass("no__body");
      }

      //  Faculty Section read more.
      var minimizedElements = $(".field-name-field-faculty-profile-bio .field-item");
      var minimizeCharacterCount = 300;
      var ellipsesText = "...";
      var moreText = "&nbsp;Read more";
      var lessText = "Read less";

      function cutKeepingTags(elem, reqCount) {
        var grabText = '',
            missCount = reqCount;

        $(elem).contents().each(function(i, v) {
          switch (this.nodeType) {
            case Node.TEXT_NODE:
              // Get node text, limited to missCount.
              grabText += this.data.substr(0,missCount);
              missCount -= Math.min(this.data.length, missCount);
              break;
            case Node.ELEMENT_NODE:
              // Explore current child:
              var childPart = cutKeepingTags(this, missCount);
              grabText += childPart.text;
              missCount -= childPart.count;
              break;
          }
          if (missCount === 0) {
            // We got text enough, stop looping.
            return false;
          }
        });

        return {
          text:
            // Wrap text using current elem tag.
            elem.outerHTML.match(/^<[^>]+>/m)[0]
            + grabText
            + '</' + elem.localName + '>',
          count: reqCount - missCount
        };
      }

      minimizedElements.each(function() {
        var bodyText = $(this).html();

        if (bodyText.length < minimizeCharacterCount) {
          return;
        }

        var truncatedText = cutKeepingTags($(this)[0], minimizeCharacterCount);
        var textString = String(truncatedText.text);
        var preIndex = textString.lastIndexOf(" ");
        var lastIndex = preIndex + textString.substring(preIndex).indexOf("<");
        var string1 = textString.slice(0, preIndex);
        var string2 = textString.slice(lastIndex, textString.length);
        var result = string1 +
                    '<span class="ellipses__text">' + ellipsesText + '</span>' +
                    '<a href="#" class="more-link read__button" style="display:inline-block; margin-top:0;">' + moreText + '</a>' +
                    string2;

        var html = '<div class="truncated-text" style="display:block">' + result +
                    '</div><div class="entire-content" style="display:none">' + bodyText +
                    '</div><a href="#" class="less-link read__button" style="display:none">' + lessText + '</a>';

        $(this).html(html);
      });

      $(".more-link").click(function(event) {
        event.preventDefault();
        $('.truncated-text').hide();
        $('.entire-content').show();
        $('.less-link').show();
      });

      $(".less-link").click(function(event) {
        event.preventDefault();
        $('.entire-content').hide();
        $('.less-link').hide();
        $('.truncated-text').show();
      });
    }
  };

  Drupal.behaviors.respIframe = {
    attach: function() {
      // Make video iframe responsive

      //debounce func
      function debounce(func, wait, immediate) {
        var timeout;
        return function() {
          var context = this, args = arguments;
          var later = function() {
            timeout = null;
            if (!immediate) func.apply(context, args);
          };
          var callNow = immediate && !timeout;
          clearTimeout(timeout);
          timeout = setTimeout(later, wait);
          if (callNow) func.apply(context, args);
        };
      };

      // Find all iframes
      var $iframes = $( ".front .view-sub-featured-homepage-content iframe" );

      // Find &#x26; save the aspect ratio for all iframes
      $iframes.each(function () {
        $( this ).attr( "data-ratio", this.height / this.width )
        // Remove the hardcoded width &#x26; height attributes
        .removeAttr( "width" )
        .removeAttr( "height" );

        if ( $( '.front #block-cls-core-experience-columbia-law' ).width() > 991 ) {
            var width = $( '.front #block-cls-core-experience-columbia-law' ).width() * 0.492;
          } else if ( $( '.front #block-cls-core-experience-columbia-law' ).width() > 750 ) {
            var width = $( '.front #block-cls-core-experience-columbia-law' ).width() * 0.43;
          } else {
            var width = $( '.front #block-cls-core-experience-columbia-law' ).width() * 0.85;
          }
          
          var height = width * $( this ).attr( "data-ratio" );

          $( this ).width( width )
          .height( height );
      });

      var resizeIframe = debounce(function() {
        $iframes.each( function() {
          // Get the parent container&#x27;s width

          if ( $( '.front #block-cls-core-experience-columbia-law' ).width() > 991 ) {
            var width = $( '.front #block-cls-core-experience-columbia-law' ).width() * 0.492;
          } else if ( $( '.front #block-cls-core-experience-columbia-law' ).width() > 750 ) {
            var width = $( '.front #block-cls-core-experience-columbia-law' ).width() * 0.43;
          } else {
            var width = $( '.front #block-cls-core-experience-columbia-law' ).width() * 0.85;
          }
          
          var height = width * $( this ).attr( "data-ratio" );

          $( this ).width( width )
          .height( height );
        });
      }, 200);

      // Resize the iframes when the window is resized
        $( window ).resize(resizeIframe);
    }
  };

  // Add class based on condition.
  Drupal.behaviors.class = {

    attach: function() {
      $("strong").parent("p").addClass("is__bold");
    }
  };

  // Toggle Behavior of Footer Menu Links.
  Drupal.behaviors.footerBehavior = {

    attach: function() {
      var group = $(".block__menu-admissions-block").nextUntil(".block__menu-about-us");

      group = group.add(group.last().next()).add(group.first().prev());
      $(group).wrapAll("<div class='footer__menu-wrap'></div>");

      var footerLinkParents = $(".footer__menu-wrap section");

      var footerLink = $(".footer__menu-wrap .title__wrap");

      $.each(footerLink, function() {
        $(this).click(function() {
          if ($(this).parent().hasClass("visible")) {
            $(this).parent().removeClass("visible");
          } else {
            $.each(footerLinkParents, function() {
              $(this).removeClass("visible");
            });
            $(this).parent().toggleClass("visible");
          }
        });
      });

      $(".tb-megamenu-nav.level-0 > .tb-megamenu-item > a").wrap("<span class='link__wrap'></span>");

      $(".tb-megamenu-button").click(function() {
        $(this).toggleClass("menu_open");
      });

      $(".tb-megamenu .nav-collapse").append("<button data-target='.nav-collapse' data-toggle='collapse' class='lower__menu-btn btn btn-navbar tb-megamenu-button menuIstance-processed' type='button'></button>");

      $(".lower__menu-btn").click(function() {
        $(".tb-megamenu-button").toggleClass("menu_open");
      });

      $(".topmenu").click(function() {
        $(".tb-megamenu-button").removeClass("menu_open").addClass("lower__button");
      });

      $(".first__nav a").click(function() {
        $(".nav-collapse").addClass("hide__nav");
        $(".tb-megamenu-button").removeClass("menu_open");
      });

      $("ul.level-0 > .level-1.dropdown").children(".mega-dropdown-menu").find(".mega-dropdown-inner").prepend("<button class='menu__toggler'>BACK</button>");

      $("ul.level-0 > .level-1").click(function() {
        $(this).toggleClass("activated visible");
        $("ul.level-0 > .level-1").not(this).toggleClass("not__activated");
      });


      $(".menu__toggler").click(function() {
        $(this).parent().find(".level-1").removeClass("activated visible");
        $(this).parent().find(".level-1").siblings().removeClass("not__activated");
      });
    }
  };

  Drupal.behaviors.alert = {
    attach: function() {

      if ($.cookie("alert_close_timestamp") == null || $.cookie("alert_close_timestamp") < $.cookie("announcement_timestamp")) {
        $(".announcement__container").slideDown("slow");

        $(".close").click(function() {
          var timestamp = new Date().getTime();

          $.cookie("alert_close_timestamp", timestamp, {
            path: Drupal.settings.basePath
          });
        });
      }
    }
  };

  Drupal.behaviors.extendMobileNavMenu = {
    attach: function() {
      var headerMenuLink = $('#block-menu-menu-header-menu ul.nav li');
      var megaMenu = $('#block-tb-megamenu-menu-main-mega-menu ul.level-0');
      var count = headerMenuLink.length;
      headerMenuLink.each(function( index ) {
        if (index !== count - 1) {
          $(this).clone().appendTo(megaMenu);
        }
      });
    }
  };

  Drupal.behaviors.fetchFacultyProfileForFacultyLandingPage = {
    attach: function() {

      /* search results page */
      var rowIDs = [],
      size = 5;

      $('.view-faculty-listing .view-content .views-row').each(function () {
        rowIDs.push($(this).data('id'));
      });

      for (var i=0; i < rowIDs.length; i+=size) {
        var batch = rowIDs.slice(i,i+size);

        batch.forEach(function(entry){
          var row = $(".view-faculty-listing .view-content .views-row[data-id='" + entry + "']");
        });

        $.ajax({
          url: '/faculty/ajax-profile-data',
          type: 'POST',
          data: {ids: batch},
          beforeSend: function() {
            batch.forEach(function(entry){
              var row = $(".view-faculty-listing .view-content .views-row[data-id='" + entry + "']");
              row.children('.faculty-phone-email').addClass('ajax-loading-icon');
            });
          },
          dataType: 'json',
          success: function(data) {
            data.forEach(function(entry) {
              var row = $(".view-faculty-listing .view-content .views-row[data-id='" + entry.id + "']");
              row.children('.faculty-phone-email').removeClass('ajax-loading-icon');

              if (entry.phone) {
                if (row.find('.faculty-phone-email .views-field-field-faculty-office-phone .field-content').length) {
                  row.find('.faculty-phone-email .views-field-field-faculty-office-phone .field-content').text(entry.phone);
                }
                else {
                  $('<div class="views-field views-field-field-faculty-office-phone"><span class="views-label views-label-field-faculty-office-phone">Tel: </span><div class="field-content">' + entry.phone + '</div></div>').appendTo(row.children('.faculty-phone-email'));
                }

              }

              if(entry.email){
                var emailHtml = '<a href="mailto:'+entry.email+'">'+entry.email+'</a>';
                if (row.find('.faculty-phone-email .views-field-field-faculty-office-email .field-content').length) {
                  row.find('.faculty-phone-email .views-field-field-faculty-office-email .field-content').html(emailHtml);
                }
                else {
                  $('<div class="views-field views-field-field-faculty-office-email"><div class="field-content">' + emailHtml + '</div></div>').appendTo(row.children('.faculty-phone-email'));
                }
              }

              row.find('.faculty-phone-email .views-field-field-faculty-office-phone').show();
              row.find('.faculty-phone-email .views-field-field-faculty-office-email').show();

            });
          }
        });
      }
    }
  };

}(jQuery, Drupal));
