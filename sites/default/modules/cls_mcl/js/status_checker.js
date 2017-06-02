jQuery.noConflict();

jQuery(document).ready(
	function(){
	  
	  jQuery('#cls-mcl-check-status-form').submit(function() {
	      return performClientsideValidation();  
	  });
		
      jQuery("#edit-birth-date").datepicker({                       
	      dateFormat: "mm-dd-yy",
	      yearRange: "-80:-13",
	      changeMonth: true,
			  changeYear: true,
			  defaultDate: "-22y"
      });
      
/*
      jQuery("#edit-first-name").change(function(){
		  validateFirstName();
	  });
      
      jQuery("#edit-last-name").change(function(){
		  validateLastName();
	  });
      
      jQuery("#edit-birth-date").change(function(){
		  validateBirthDate();
	  });
      
      jQuery("#edit-lsac-account-number").change(function(){
		  validateLSAC();
	  });
*/
});

function clearAll() {
	jQuery("#edit-first-name").val("");
	jQuery("#edit-last-name").val("");
	jQuery("#edit-birth-date").val("");
	jQuery("#edit-lsac-account-number").val("L");
}

function performClientsideValidation() {
    var returnflag = true;
    if(jQuery('#edit-first-name').length > 0 && !validateFirstName()){
		returnflag = false;
	}
    if(jQuery('#edit-last-name').length > 0 && !validateLastName()){
		returnflag = false;
	}
	if(jQuery('#edit-birth-date').length > 0 && !validateBirthDate()){
		returnflag = false;
	}
	if(jQuery('#edit-lsac-account-number').length > 0 && !validateLSAC()){
		returnflag = false;
	}
	if(returnflag){
		hideErrorContainer();
	}
    return returnflag;
}

function validateFirstName(){
	if (jQuery('#edit-first-name').length > 0){
	    var return_flag = true;
	    var first_name_field = jQuery('#edit-first-name');
	    var first_name = first_name_field.val();
	    var first_name_error_label = jQuery('#cls-mcl-check-status-form-errors label[for="edit-first-name"]');
	    var error = '';
	    first_name = jQuery.trim(first_name);
	    if (!first_name){
	      return_flag = false;
	      error = ' is required.';
	    }
	    else {
	      var pattern = /^([A-Z|a-z|\-|\.|\'|\s]{1,})?$/;
	      if (!pattern.test(first_name)) {
	    	return_flag = false;
	        error = ' can only contain letters, dashes and spaces.';
	      }
	    }
	    
	    if (return_flag) {
	      jQuery('#cls-mcl-check-status-form-errors li#edit-first-name-error').remove();
		  if(first_name_error_label.length == 0){
			first_name_field.removeClass('error');
			first_name_field.addClass('valid');
	      }
		  hideErrorContainer();
	    }
	    else {
	      displayErrorContainer();
	      if(first_name_error_label.length == 0){
    		jQuery('#cls-mcl-check-status-form-errors ul').append('<li id="edit-first-name-error"><label class="error" for="edit-first-name" generated="true">First name' + error + '</label></li>');
          }else{
        	first_name_error_label.html('First name' + error);		
          }
	      first_name_field.removeClass('valid');
	      first_name_field.addClass('error');
	    }
	    return return_flag;
	}
}

function validateLastName(){
	if (jQuery('#edit-last-name').length > 0){
	    var return_flag = true;
	    var last_name_field = jQuery('#edit-last-name');
	    var last_name = last_name_field.val();
	    var last_name_error_label = jQuery('#cls-mcl-check-status-form-errors label[for="edit-last-name"]');
	    var error = '';
	    last_name = jQuery.trim(last_name);
	    if (!last_name){
	      return_flag = false;
	      error = ' is required.';
	    }
	    else {
	      var pattern = /^([A-Z|a-z|\-|\.|\'|\s]{1,})?$/;
	      if (!pattern.test(last_name)) {
	    	return_flag = false;
	        error = ' can only contain letters, dashes and spaces.';
	      }
	    }
	    
	    if (return_flag) {
	      jQuery('#cls-mcl-check-status-form-errors li#edit-last-name-error').remove();
		  if(last_name_error_label.length == 0){
			last_name_field.removeClass('error');
			last_name_field.addClass('valid');
	      }
		  hideErrorContainer();
	    }
	    else {
	      displayErrorContainer();
	      if(last_name_error_label.length == 0){
    		jQuery('#cls-mcl-check-status-form-errors ul').append('<li id="edit-last-name-error"><label class="error" for="edit-last-name" generated="true">Last name' + error + '</label></li>');
          }else{
        	last_name_error_label.html('Last name' + error);		
          }
	      last_name_field.removeClass('valid');
	      last_name_field.addClass('error');
	    }
	    return return_flag;
	}
}

function validateBirthDate(){
	if (jQuery('#edit-birth-date').length > 0){
	    var return_flag = true;
	    var birth_date_field = jQuery('#edit-birth-date');
	    var date = birth_date_field.val();
	    var birth_date_error_label = jQuery('#cls-mcl-check-status-form-errors label[for="edit-birth-date"]');
	    var error = '';
	    date = jQuery.trim(date);
	    if (!date){
		    return_flag = false;
		    error = ' is required.';
		}
		else {
		    var pattern = /^[0-1]?[0-9]{1}[\-]{1}[0-3]?[0-9]{1}[\-]{1}[1-2]{1}[0-9]{3}$/;
		    if (!pattern.test(date)) {
		        return_flag = false;
		        error = ' has invalid format.';
		    }
		}
	    if (return_flag) {
	      jQuery.ajax({
	        url: base_url+"/mcl/validate-birth-date",
	        type: "POST",
	        async: false,
	        data: {'birth_date': date},
	        dataType: 'json',
            success: function(data){
            	if(data.result){
            		return_flag = true;
            	}else{
            		error = data.error;
        		    return_flag = false;
            	}
            }
	      });
	    }
	    if (return_flag) {
		      jQuery('#cls-mcl-check-status-form-errors li#edit-birth-date-error').remove();
			  if(birth_date_error_label.length == 0){
				birth_date_field.removeClass('error');
				birth_date_field.addClass('valid');
		      }
			  hideErrorContainer();
		}
		else {
		      displayErrorContainer();
		      if(birth_date_error_label.length == 0){
	    		jQuery('#cls-mcl-check-status-form-errors ul').append('<li id="edit-birth-date-error"><label class="error" for="edit-birth-date" generated="true">Birth date' + error + '</label></li>');
	          }else{
	        	birth_date_error_label.html('Birth date' + error);		
	          }
		      birth_date_field.removeClass('valid');
		      birth_date_field.addClass('error');
		}
	    return return_flag;
	}
}

function validateLSAC(){
	if (jQuery('#edit-lsac-account-number').length > 0){
	    var return_flag = true;
	    var lsac_field = jQuery('#edit-lsac-account-number');
	    var lsac = lsac_field.val();
	    var lsac_error_label = jQuery('#cls-mcl-check-status-form-errors label[for="edit-lsac-account-number"]');
	    var pattern = /^([L]{1}[0-9]{8})?$/;
	    lsac = jQuery.trim(lsac);
	    if (!lsac){
		    return_flag = false;
		    error = ' is required.';
		}
	    else if (!pattern.test(lsac)) {
	        return_flag = false;
	        error = ' has invalid format.';
	    }
	    if (return_flag) {
		      jQuery('#cls-mcl-check-status-form-errors li#edit-lsac-error').remove();
			  if(lsac_error_label.length == 0){
				  lsac_field.removeClass('error');
				  lsac_field.addClass('valid');
		      }
			  hideErrorContainer();
		}
		else {
		      displayErrorContainer();
		      if(lsac_error_label.length == 0){
	    		jQuery('#cls-mcl-check-status-form-errors ul').append('<li id="edit-lsac-error"><label class="error" for="edit-lsac-account-number" generated="true">LSAC account number' + error + '</label></li>');
	          }else{
	        	  lsac_error_label.html('LSAC account number' + error);		
	          }
		      lsac_field.removeClass('valid');
		      lsac_field.addClass('error');
		}
	    return return_flag;
	}	
}

function displayErrorContainer(){
	if(jQuery('#cls-mcl-check-status-form-errors').length == 0){
		jQuery('div.mcl-status-checker-form-column').prepend('<div id="cls-mcl-check-status-form-errors" class="messages error clientside-error" style="display: block;"><ul style="display: block;"></ul></div>');
	}else{
		jQuery('#cls-mcl-check-status-form-errors').show();
		jQuery('#cls-mcl-check-status-form-errors ul').show();
	}
}

function hideErrorContainer(){
	if(jQuery('#cls-mcl-check-status-form-errors ul').html() == ""){
		jQuery('#cls-mcl-check-status-form-errors ul').hide();
		jQuery('#cls-mcl-check-status-form-errors').hide();
	}
}
