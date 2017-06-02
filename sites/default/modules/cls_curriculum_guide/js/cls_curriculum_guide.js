(function($){
  $(document).ready(function(){

    /* homepage */
    if($('#search-compare-courses-input') != undefined){
      $('#search-compare-courses-input').focus();
    }
    $('#search-compare-courses-input').keypress(function(){
      value = $(this).val().replace('Course name or number', '');
      $(this).val(value);
    });

    $('#search-compare-courses-input').focusout(function(){
      if($(this).val() == '') {
        $(this).val('Course name or number');
      }
    });

    /* offering page */
    $("#change-school-year").change(function(){
      var parts = window.location.pathname.split( '/' ),
      text = $('#change-school-year option:selected').text();

      $.get("/courses/" + parts[2] + "/ajax-sections/" + $(this).val(),{}, function(data){
        $(".section-listing .heading h3 strong").text(text);
        $('#sections-ajax-container').html(data);
      });
    });

    $("#change-semester-link").click(function(){
      $(this).hide();
      $('#change-school-year').show();
    });

    /* search page */
    $('#course-search-expanded-options').slideToggle();

    function toggleOptions(){
      $('#course-search-expanded-options').slideToggle();
      $('.advanced-search div.more, .advanced-search div.less').toggle();
    }

    $('#more-options, #less-options').click(function(){
      toggleOptions();
    });

    $("#schoolyear").change(function(){
      $.get("/courses/ajax-instructors/" + $(this).val(),{}, function(data){
        $("select#instructor").html(data);
        $('select#instructor option:first').attr('selected', 'selected');
      });

      $.get("/courses/ajax-categories/" + $(this).val(),{}, function(data){
        $('#category-checkbox-list').html(data);
      });
    });

    $("#curriculum-guide-search-form").submit(function(event) {
      event.preventDefault();

      var criteria = [],
          data = $(this).serialize();

      var pairs = data.split('&').reduce(function(collect, pair) {
        var kv = pair.split('=');
        var name = kv[0].substr(kv[0].indexOf('_') + 1);
        collect.push({
          name: name,
          value: kv[1]
        });
        return collect;
      }, []);

      $.each(pairs, function() {
        if(this.value !== ""){criteria.push(this.value);}
      });

      if( criteria.length > 4 && $('#coursename').val() !== '*' ){
        document.getElementById("curriculum-guide-search-form").submit();
      }
      else if($('#Foundation').is(':checked') == true || $('#Upperclass').is(':checked') == true){
        document.getElementById("curriculum-guide-search-form").submit();
      }
      else if( (criteria.length > 3) && !($('#semesterfall').is(':checked') == true && $('#semesterspring').is(':checked') == true) ){
        document.getElementById("curriculum-guide-search-form").submit();
      }
      else{
        $('#curriculum-guide-search-error').text('Please select an additional search criterion to narrow down the search.');
        $('#curriculum-guide-search-error').css('margin-bottom', '10px');
      }
    });

    /* search results page */
    var sectionIDs = [],
        size = 30;

    $('table.results-table tr.course-row').each(function () {
      sectionIDs.push($(this).data('id'));
    });

    for (var i=0; i < sectionIDs.length; i+=size) {
      var batch = sectionIDs.slice(i,i+size);

      $.ajax({
        url: '/courses/ajax-search-results-batch',
        type: 'POST',
        data: {ids: batch},
        beforeSend: function() {
          batch.forEach(function(entry){
            var row = $("table.results-table td table.inner tr[data-cid='" + entry + "']");
                row.children('td.schedules').addClass('ajax-loading-icon');
          });

        },
        dataType: 'json',
        success: function(data) {
          data.forEach(function(entry) {

            var row = $("table.results-table td table.inner tr[data-cid='" + entry.id +"']");
                row.children('td.schedules').removeClass('ajax-loading-icon');

                row.children('td.instructors').html(entry.instructors);
                row.children('td.schedules').html(entry.schedule);
                row.children('td.locations').html(entry.location);

          });
        }
      });

    }

    $('table.results-table a.description-toggle').click(function(){
      var description = $(this).attr('data-toggle'),
          id = $(this).attr('data-id');

      if( $('#'+description+'-expanded div').text() == "" ){
        $.ajax({
          url: "/courses/ajax-search-results-course-details/" + id + "/description",
          global: false,
          type: "GET",
          cache: false,
          beforeSend: function() {
            $('#'+description+'-expanded div').html("<img src='/sites/all/modules/custom/cls_curriculum_guide/images/lazy-loader.gif'/>");
          },
          success: function(data) {
            $('#'+description+'-expanded div').html( data );
          }
        });
      }

      if($(this).text() == '+'){
        $(this).text('–');
        $('#'+description+'-expanded div').show();
      }else{
        $(this).text('+');
        $('#'+description+'-expanded div').hide();
      }
    });

    /* section page */
    $('#primary-goals-link, #secondary-goals-link').click(function(){
      var link = $(this),
          id = link.attr('id').replace('-link', ""),
          text = id.replace('-', " ");

      if($('#'+id).is(':visible')){
        link.text('Show ' + text + ' provided by instructor');
        $('#'+id).slideToggle();
      }else{
        link.text('Hide ' + text + ' provided by instructor');
        $('#'+id).slideToggle();
      }
    });

    /* sections taught by instructor's page */
    $("#browseSchoolYear").change(function(){
      var parts = window.location.pathname.split( '/' );

      $.ajax({
        url: "/courses/instructors/" + parts[3] + "/ajax-sections/" + $(this).val(),
        global: false,
        type: "GET",
        cache: false,
        beforeSend: function() {
          $('#instructor-sections-container').html("<img src='/sites/all/modules/custom/cls_curriculum_guide/images/lazy-loader.gif'/>");
        },
        success: function(data) {
          $('#instructor-sections-container').html(data);
        }
      });
    });

  });
})(jQuery);
