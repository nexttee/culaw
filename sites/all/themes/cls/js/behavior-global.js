/**
* Columbia Law School Global JavaScript Library and Behavior
* behavior-global.js
* http://law.columbia.edu
*
* Copyright (c) 2013 Trustees of Columbia University in the City of New York
* You may not use or redistribute this code.
*/

/**
* Table of Contents
*
* 1 -: Global variables
* 2 -: Global functions
* 3 -: Global behavior enhancements
*
*/

/* @group 1: GLOBAL VARIABLES */

// Set CLS namespace for global variable array and initialize its variables
var CLS={};
CLS.inputValueStorageArray = Array();

/* @group 2: GLOBAL FUNCTIONS */

// Functions to store, clear, and reset default input text

function clearInput(event){
  var thisObj = event.currentTarget;
  if(!CLS.inputValueStorageArray[thisObj]){
    CLS.inputValueStorageArray[thisObj] = thisObj.value;
    thisObj.value = "";
    thisObj.style.color = "black";
  }
}

function replaceInput(event){
  var thisObj = event.currentTarget;
  if(thisObj.value == ""){
    thisObj.value = CLS.inputValueStorageArray[thisObj];
    thisObj.style.color = "#999999";
    CLS.inputValueStorageArray[thisObj]= false;
  }
}



function getMetaValue(meta_name) {
  var my_arr=document.getElementsByTagName("META");
  for (var counter=0; counter<my_arr.length; counter++) {
    if (my_arr[counter].name.toLowerCase() == meta_name.toLowerCase()) {
      return my_arr[counter].content;
    }
  }
  return "";
}

function sharePageFacebook() {
  u=location.href;
  t=document.title;
  window.open('http://www.facebook.com/sharer.php?u='+encodeURIComponent(u)+'&amp;t='+encodeURIComponent(t),'Share on Facebook','toolbar=0,status=0,width=626,height=436');
  return false;
}

function sharePageTwitter() {
  u=location.href;
  t=document.title;
  window.open('http://twitter.com/home?status=Currently%20reading%20'+encodeURIComponent(u),'Share on Twitter');
  return false;
}

function sharePageLinkedIn() {
  u=location.href;
  t=document.title;
  d=getMetaValue('description');
  window.open('http://www.linkedin.com/shareArticle?mini=true&url='+encodeURIComponent(u)+'&title='+encodeURIComponent(t)+'&summary='+encodeURIComponent(d)+'&source=Columbia%20Law%20School','Share on Linked In','menubar=no,width=520,height=570,toolbar=no');
  return false;
}

function MM_jumpMenu_class(targ,selObj,restore){ //v3.0
  eval(targ+".location='"+selObj.options[selObj.selectedIndex].value+"'");
  if (restore) selObj.selectedIndex=0;
}

/* @group 3: GLOBAL BEHAVIOR ENHANCEMENTS */

(function ($) {

  Drupal.behaviors.cls = {
    attach: function(context, settings) {
      try {
        // IE6 and lower design enhancements (footer correction)
        $('#footer ul li:first-child').addClass('first-child');

        // Enhance search box to show or hide default text
        if ($('#global-search-input') != undefined) {
          $('#global-search-input').focus(function() {
            if ($(this).val() == "") {$(this).addClass('not-empty');}
          });
          $('#global-search-input').blur(function() {
            if ($(this).val() == "") {$(this).removeClass('not-empty');}
          });
        }
        // Open links with a class 'popup-link' in a popup.
        $('a.popup-link').click(function () {
          window.open($(this).attr('href'), "popup", 'titlebar=1,toolbar=1,scrollbars=1,location=1,status=0,menubar=1,resizable=1,width=600,height=600,top=10,left=10');
          return false;
        });

        // Open gls/jd admitted enroll links in a new tab
        $('a[href$="admitted/enroll/decision"], a[href$="admitted/enroll/second-deposit"], a[href$="transfer-orientation/enrollment-information/decision"]').click(function(){
          $(this).attr('target', '_blank');
        });
		
		
        $('.contextual-links-region .contextual-links-region').each(function(){
          var parentOffset = $(this).parents('.contextual-links-region').offset();
          var thisOffset = $(this).offset();
          var thisOffsetWrapper = $(this).children('.contextual-links-wrapper').offset();
          if (thisOffset.top < parentOffset.top + 19) {
            var thisOffsetTop = thisOffsetWrapper.top + 25;
            var thisZIndex = $(this).children('.contextual-links-wrapper').zIndex();
            $(this).children('.contextual-links-wrapper').zIndex(thisZIndex - 1);
            $(this).children('.contextual-links-wrapper').offset({ top: thisOffsetTop });
          }
        });

      } catch (e) {};
    }
  };

  Drupal.behaviors.cls_selects = {

    attach: function(context, settings) {

    }
  };

  Drupal.behaviors.backTo = {

    attach: function(context, settings) {

      var referer = $(".content .node").data('referer');

      if($("body").hasClass('node-type-cls-ag-document') && referer.length > 0) {
        if (referer.indexOf("attorneys-general/publications-resources") > -1) {
          $( ".page-node .content .node .node-inner .content" ).prepend("<a class='back-to-search' href='" + referer + "'>Back to Search Results</a>");
        }
        else {
          $( ".page-node .content .node .node-inner .content" ).prepend("<a class='back-to-search' href='" + '/attorneys-general/publications-resources/search-article-database' + "'>Back to Search Results</a>");
        }
      }
    }
  };



})(jQuery);
