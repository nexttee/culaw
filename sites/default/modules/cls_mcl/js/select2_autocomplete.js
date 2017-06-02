(function($) {

  // Implements select2 autocomplete functionality to Drupal forms
  Drupal.behaviors.clsMclSelect2Autocomplete = {
    attach: function(context) {
      // load all autocomplete inputs that match the criteria
      var inputs = $('.form-item.form-type-textfield input.form-autocomplete.form-select2');

      // process each autocomplete enabled textfield
      $.each(inputs, this.processAutocompleteInput);
    },

    /**
     * Processes an autocomplete input with its proper configuration
     */
    processAutocompleteInput: function(index, input) {
      var autocompletePath = $(input).siblings('input[type="hidden"].autocomplete').first().attr("value");
      var timeout = 0;
      var quietMillis = 500;
      var noResultsCallback = $(input).data( "no-results-callback" );
      var noResultsText = $(input).data( "no-results-text" );

      var options = {
        minimumInputLength: 3,
        maximumSelectionSize: 1,
         placeholder: 'Search for your school...',
         allowClear: true,
         formatInputTooShort: function (input, min) { return ''; },
         formatNoMatches: function (term) { return '<a href="#" onclick="' + noResultsCallback + '  ();return false;">' + noResultsText + '</a>'; },
         createSearchChoice: function (term) { return; },
         multiple: false,
        
        // returns a list of tags
        query: function(query) {

          window.clearTimeout(timeout);
          timeout = window.setTimeout(function () {
            var term = query.term;

            $.ajax({
              type: 'GET',
              url: autocompletePath + '/' + Drupal.encodePath(term),
              dataType: 'json',
              // process response
              success: function (matches) {
                var found = [];
              
                $.each(matches, function(matchKey, matchText) {
                  found.push({
                    id: matchKey,
                    text: matchText
                  });
                });

                // return the results
                query.callback({
                  results : found
                });
              },
              // process errors
              error: function (xmlhttp) {
                alert(Drupal.ajaxError(xmlhttp, db.uri));
              }
            });
            
          }, quietMillis);
        },

        // processes each element
        initSelection: function (element) {
          var data = [];
          var regexp = /("(?:[^"]*)(?:""[^"]*)*"|(?:[^",]*))/g;
          var matches = element.val().match(regexp);

          $.each(matches, function (index, value) {
            // skip emtpy matches that are empty spaces
            if (value.trim() === '') {
              return;
            }
            
            data.push({
              id: value,
              text: value
            });
          });
          return data;
        }
      };

      // implement the select2 library
      $(input).select2(options);

      // add sorting functionality
      $(input).change(function() {
        $( $(input).attr('id') + '_val').html($(input).val());
      });

    }
  }

})(jQuery)
