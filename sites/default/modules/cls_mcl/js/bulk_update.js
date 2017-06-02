jQuery.noConflict();

jQuery(document).ready(
	function(){
	  jQuery('#cls-mcl-student-role-update-form').submit(function() {
	      return performClientsideValidation();  
	  });

});

function performClientsideValidation() {
    var returnflag = true;
    if(jQuery('#edit-roles-to-remove').length > 0 && !validateRolesToRemove()){
		returnflag = false;
	}
    if(jQuery('#edit-account-ids').length > 0 && !validateAccountIDs()){
		returnflag = false;
	}
	if(returnflag == true){
		hideErrorContainer();
	}
    return returnflag;
}

function validateRolesToRemove() {
	if (jQuery('#edit-roles-to-remove').length > 0){
	    var return_flag = true;
	    var roles_field = jQuery('#edit-roles-to-remove');
	    var chosen_role = roles_field.val();
	    var roles_error_label = jQuery('#cls-mcl-bulk-update-form-errors label[for="edit-roles-to-remove"]');
	    var error = '';
	    chosen_role = jQuery.trim(chosen_role);
	    if (!chosen_role){
	      return_flag = false;
	      error = ' are required.';
	    }
	    
	    if (return_flag) {
	      jQuery('#cls-mcl-bulk-update-form-errors li#edit-roles-to-remove-error').remove();
		  if(roles_error_label.length == 0){
			  roles_field.removeClass('error');
			  roles_field.addClass('valid');
	      }
		  hideErrorContainer();
	    }
	    else {
	      displayErrorContainer();
	      if(roles_error_label.length == 0){
    		jQuery('#cls-mcl-bulk-update-form-errors ul').append('<li id="edit-roles-to-remove-error"><label class="error" for="edit-roles-to-remove" generated="true">Roles to Remove' + error + '</label></li>');
          }else{
        	  roles_error_label.html('Roles to remove' + error);		
          }
	      roles_field.removeClass('valid');
	      roles_field.addClass('error');
	    }
	    return return_flag;
	}
}

function validateAccountIDs() {
	if (jQuery('#edit-account-ids').length > 0){
	    var return_flag = true;
	    var account_ids_field = jQuery('#edit-account-ids');
	    var account_ids = account_ids_field.val();
	    var account_ids_label = jQuery('#cls-mcl-bulk-update-form-errors label[for="edit-account-ids"]');
	    var error = '';
	    if (!account_ids){
	      return_flag = false;
	      error = ' are required.';
	    }
	    
	    if (return_flag) {
	      jQuery('#cls-mcl-bulk-update-form-errors li#edit-account-ids-error').remove();
		  if(account_ids_label.length == 0){
			account_ids_field.removeClass('error');
			account_ids_field.addClass('valid');
	      }
		  hideErrorContainer();
	    }
	    else {
	      displayErrorContainer();
	      if(account_ids_label.length == 0){
    		jQuery('#cls-mcl-bulk-update-form-errors ul').append('<li id="edit-account-ids-error"><label class="error" for="edit-account-ids" generated="true">Account IDs' + error + '</label></li>');
          }else{
        	  account_ids_label.html('Account IDs' + error);		
          }
	      account_ids_field.removeClass('valid');
	      account_ids_field.addClass('error');
	    }
	    return return_flag;
	}
}

function displayErrorContainer(){
	if(jQuery('#cls-mcl-bulk-update-form-errors').length == 0){
		jQuery('#cls-mcl-student-role-update-form').prepend('<div id="cls-mcl-bulk-update-form-errors" class="messages error clientside-error" style="display: block;"><ul style="display: block;"></ul></div>');
	}else{
		jQuery('#cls-mcl-bulk-update-form-errors').show();
		jQuery('#cls-mcl-bulk-update-form-errors ul').show();
	}
}

function hideErrorContainer(){
	if(jQuery('#cls-mcl-bulk-update-form-errors ul').html() == ""){
		jQuery('#cls-mcl-bulk-update-form-errors ul').hide();
		jQuery('#cls-mcl-bulk-update-form-errors').hide();
	}
}