// @TODO Namespace all functions so they don't exist in the global scope
//   and also use a closure for jQuery

function performClientsideValidation(instance_id, action, existing_undergrad_school) {
    var returnflag = true;
    if (jQuery('#edit-first-name').length > 0 && !validateFirstName(instance_id)) {
        returnflag = false;
    }
    if (jQuery('#edit-middle-name').length > 0 && !validateMiddleName(instance_id)) {
        returnflag = false;
    }
    if (jQuery('#edit-last-name').length > 0 && !validateLastName(instance_id)) {
        returnflag = false;
    }
    if (jQuery('#edit-birth-date').length > 0 && !validateBirthDate()) {
        returnflag = false;
    }
    if (jQuery('#edit-lsac-account-number').length > 0 && !validateLSAC()) {
        returnflag = false;
    }
    if (jQuery('#edit-email').length > 0 && !validateEmail()) {
        returnflag = false;
    }
    if (jQuery('#edit-password').length > 0 && !validatePassword(action)) {
        returnflag = false;
    }
    if (jQuery('#edit-security-question-select').length > 0 && !validateSecurityQuestion()) {
        returnflag = false;
    }
    if (jQuery('#edit-security-answer').length > 0 && !validateSecurityAnswer(action)) {
        returnflag = false;
    }
    if (jQuery('#edit-application-year').length > 0 && !validateApplicationYear()) {
        returnflag = false;
    }
    if (jQuery('#edit-country').length > 0 && !validateCountry()) {
        returnflag = false;
    }
    if (jQuery('#edit-state-province').length > 0 && !validateStateOrProvince()) {
        returnflag = false;
    }
    if (jQuery('#edit-city').length > 0 && !validateCity()) {
        returnflag = false;
    }
    if (jQuery('#edit-zip-code').length > 0 && !validateZipCode()) {
        returnflag = false;
    }
    if (jQuery('#edit-undergrad-school-name').length > 0 && !validateUndergraduateSchoolName(instance_id, action, existing_undergrad_school)) {
        returnflag = false;
    }
    if (jQuery('#edit-graduate-school-name').length > 0 && !validateGraduateSchoolName()) {
        returnflag = false;
    }
    // @TODO Why don't we also validate this for JDs? Where do we do clientside
    //   on whether LLMs added a school for their first law degree?
    if (jQuery('#edit-undergrad-graduation-year').length > 0 && instance_id == 'my_columbia_llm' && !validateFirstGraduationYear()) {
        returnflag = false;
    }
    // if (!moveServerSideValidationMessages()) {
    // 	returnflag = false;
    // }

    if (returnflag === false) {
      jQuery('html, body').animate({ scrollTop: 0}, 1000, 'easeOutExpo');
    }

    return returnflag;
}

function moveServerSideValidationMessages() {
	var errorcontainer = jQuery('.twelvecol > .messages');
    var errormessage = '';
    if (errorcontainer.length > 0) {
    	if (jQuery('.twelvecol > .messages ul').length > 0) {
    		jQuery('.twelvecol > .messages ul li').each(function() {
    			var unformattedListItem = jQuery(this).html();
    			jQuery(this).html('<label class="error">' + unformattedListItem + '</label>');
    		});
    		errormessage = jQuery('.twelvecol > .messages ul').html();
    	}
    	else {
    		errormessage = '<li><label class="error">' + jQuery('.twelvecol > .messages').html() + '</label></li>';
    	}
    }
    if (errormessage != '') {
    	jQuery('#cls-mcl-account-errors ul').append(errormessage);
    	errorcontainer.hide();
    	jQuery('#cls-mcl-account-errors ul li, #cls-mcl-account-errors ul li label').show();
    	return false;
    }
    jQuery('#cls-mcl-account-errors ul li, #cls-mcl-account-errors ul li label').show();
    return true;
}

function performClientsideValidationSecurityQuestion() {
    var returnflag = true;
	if(jQuery('#edit-security-question-select').length > 0 && !validateSecurityQuestion()){
		returnflag = false;
	}
	if(jQuery('#edit-security-answer').length > 0 && !validateSecurityAnswer()){
		returnflag = false;
	}
    if (returnflag === false) {
      jQuery('body').animate({ scrollTop: jQuery('body').offset().top}, 1000, 'easeOutExpo')
    }
    return returnflag;
}

function validateFirstName(instance_id) {
    if (jQuery('#edit-first-name').length > 0) {
        var return_flag = true;
        var first_name_field = jQuery('#edit-first-name');
        var first_name = first_name_field.val();
        var first_name_error_label = jQuery('#cls-mcl-account-errors label[for="edit-first-name"]');
        var error = '';
        first_name = jQuery.trim(first_name);
        if (!first_name) {
            return_flag = false;
            error = ' is required.';
        }
        else {
            if (instance_id === 'my_columbia_law') {
                var pattern = /[^A-Z|a-z|\-|\.|\'|\s]/;
            }
            else {
                var pattern = XRegExp("[^\\p{L}\\s\\-\\.\\']")
            }
            if (pattern.test(first_name)) {
                return_flag = false;
                error = ' can only contain letters, dashes and spaces.';
            }
        }

        if (return_flag) {
            jQuery('#cls-mcl-account-errors li#edit-first-name-error').remove();
            if (first_name_error_label.length == 0) {
                first_name_field.removeClass('error');
                first_name_field.addClass('valid');
            }
            hideErrorContainer();
        }
        else {
            displayErrorContainer();
            if (first_name_error_label.length == 0) {
                jQuery('#cls-mcl-account-errors ul').append('<li id="edit-first-name-error"><label class="error" for="edit-first-name" generated="true">First name' + error + '</label></li>');
            } else {
                first_name_error_label.html('First name' + error);
            }
            first_name_field.removeClass('valid');
            first_name_field.addClass('error');
        }
        return return_flag;
    }
}

function validateMiddleName(instance_id) {
    if (jQuery('#edit-middle-name').length > 0) {
        var return_flag = true;
        var middle_name_field = jQuery('#edit-middle-name');
        var middle_name = middle_name_field.val();
        var middle_name_error_label = jQuery('#cls-mcl-account-errors label[for="edit-middle-name"]');
        var error = '';
            if (instance_id === 'my_columbia_law') {
                var pattern = /[^A-Z|a-z|\-|\.|\'|\s]/;
            }
            else {
                var pattern = XRegExp("[^\\p{L}\\s\\-\\.\\']")
            }
        middle_name = jQuery.trim(middle_name);
        if (middle_name.length > 0 && pattern.test(middle_name)) {
            return_flag = false;
            error = ' can only contain letters, dashes and spaces.';
        }

        if (return_flag) {
            jQuery('#cls-mcl-account-errors li#edit-middle-name-error').remove();
            if (middle_name_error_label.length == 0) {
                middle_name_field.removeClass('error');
                middle_name_field.addClass('valid');
            }
            hideErrorContainer();
        }
        else {
            displayErrorContainer();
            if (middle_name_error_label.length == 0) {
                jQuery('#cls-mcl-account-errors ul').append('<li id="edit-middle-name-error"><label class="error" for="edit-middle-name" generated="true">Middle name' + error + '</label></li>');
            } else {
                middle_name_error_label.html('Middle name' + error);
            }
            middle_name_field.removeClass('valid');
            middle_name_field.addClass('error');
        }
        return return_flag;
    }
}

function validateLastName(instance_id) {
    if (jQuery('#edit-last-name').length > 0) {
        var return_flag = true;
        var last_name_field = jQuery('#edit-last-name');
        var last_name = last_name_field.val();
        var last_name_error_label = jQuery('#cls-mcl-account-errors label[for="edit-last-name"]');
        var error = '';
        last_name = jQuery.trim(last_name);
        if (!last_name) {
            return_flag = false;
            error = ' is required.';
        }
        else {
            if (instance_id === 'my_columbia_law') {
                var pattern = /[^A-Z|a-z|\-|\.|\'|\s]/;
            }
            else {
                var pattern = XRegExp("[^\\p{L}\\s\\-\\.\\']")
            }
            if (pattern.test(last_name)) {
                return_flag = false;
                error = ' can only contain letters, dashes and spaces.';
            }
        }

        if (return_flag) {
            jQuery('#cls-mcl-account-errors li#edit-last-name-error').remove();
            if (last_name_error_label.length == 0) {
                last_name_field.removeClass('error');
                last_name_field.addClass('valid');
            }
            hideErrorContainer();
        }
        else {
            displayErrorContainer();
            if (last_name_error_label.length == 0) {
                jQuery('#cls-mcl-account-errors ul').append('<li id="edit-last-name-error"><label class="error" for="edit-last-name" generated="true">Last name' + error + '</label></li>');
            } else {
                last_name_error_label.html('Last name' + error);
            }
            last_name_field.removeClass('valid');
            last_name_field.addClass('error');
        }
        return return_flag;
    }
}

function validateBirthDate() {
    if (jQuery('#edit-birth-date').length > 0) {
        var return_flag = true;
        var birth_date_field = jQuery('#edit-birth-date');
        var date = birth_date_field.val();
        var birth_date_error_label = jQuery('#cls-mcl-account-errors label[for="edit-birth-date"]');
        var error = '';
        date = jQuery.trim(date);
        if (!date) {
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
            jQuery('#cls-mcl-account-errors li#edit-birth-date-error').remove();
            if (birth_date_error_label.length == 0) {
                birth_date_field.removeClass('error');
                birth_date_field.addClass('valid');
            }
            hideErrorContainer();
        }
        else {
            displayErrorContainer();
            if (birth_date_error_label.length == 0) {
                jQuery('#cls-mcl-account-errors ul').append('<li id="edit-birth-date-error"><label class="error" for="edit-birth-date" generated="true">Birth date' + error + '</label></li>');
            } else {
                birth_date_error_label.html('Birth date' + error);
            }
            birth_date_field.removeClass('valid');
            birth_date_field.addClass('error');
        }
        return return_flag;
    }
}

function validateLSAC() {
    if (jQuery('#edit-lsac-account-number').length > 0) {
        var return_flag = true;
        var lsac_field = jQuery('#edit-lsac-account-number');
        var lsac = lsac_field.val();
        var lsac_error_label = jQuery('#cls-mcl-account-errors label[for="edit-lsac-account-number"]');
        var pattern = /^([L]{1}[0-9]{8})?$/;
        lsac = jQuery.trim(lsac);
        if (!pattern.test(lsac)) {
            return_flag = false;
            error = ' has invalid format.';
        }
        if (return_flag) {
            jQuery('#cls-mcl-account-errors li#edit-lsac-error').remove();
            if (lsac_error_label.length == 0) {
                lsac_field.removeClass('error');
                lsac_field.addClass('valid');
            }
            hideErrorContainer();
        }
        else {
            displayErrorContainer();
            if (lsac_error_label.length == 0) {
                jQuery('#cls-mcl-account-errors ul').append('<li id="edit-lsac-error"><label class="error" for="edit-lsac-account-number" generated="true">LSAC account number' + error + '</label></li>');
            } else {
                lsac_error_label.html('LSAC account number' + error);
            }
            lsac_field.removeClass('valid');
            lsac_field.addClass('error');
        }
        return return_flag;
    }
}


function validateEmail() {
    var return_flag = true;
    var edit_email = jQuery('#edit-email').val().toLowerCase().trim();
    jQuery('#edit-email').val(edit_email);
    var edit_email_reenter = jQuery('#edit-email-reenter').val().toLowerCase().trim();
    jQuery('#edit-email-reenter').val(edit_email_reenter);
    var email_field = jQuery('#edit-email');
    var email_reenter_field = jQuery('#edit-email-reenter');
    var error_list = jQuery('#cls-mcl-account-errors ul');
    if (email_field.length > 0) {
        var email = email_field.val();
        var email_error_label = jQuery('#cls-mcl-account-errors label[for="edit-email"]');
        var error = '';
        email = jQuery.trim(email);
        if (!email) {
            return_flag = false;
            error = 'Email is required.';
        }
        else {
            var pattern = /^[a-z|0-9|\-|\_|\.]{1,}[@]{1}[a-z|0-9|\-|\_|\.]{1,}[\.][a-z]{2,4}$/;
            if (!pattern.test(email)) {
                return_flag = false;
                error = 'Email has invalid format.';
            }
            else if (email_reenter_field.length > 0) {
                var email_reenter = email_reenter_field.val();
                email_reenter = jQuery.trim(email_reenter);
                if (email != email_reenter) {
                    return_flag = false;
                    error = 'Emails do not match.';
                }
            }
        }
        if (return_flag) {
            jQuery('#cls-mcl-account-errors li#edit-email-error').remove();
            if (email_error_label.length == 0) {
                email_field.removeClass('error');
                email_field.addClass('valid');
            }
            hideErrorContainer();
        }
        else {
            displayErrorContainer();
            if (email_error_label.length == 0) {
                jQuery('#cls-mcl-account-errors ul').append('<li id="edit-email-error"><label class="error" for="edit-email" generated="true">' + error + '</label></li>');
            } else {
                email_error_label.html(error);
            }
            email_field.removeClass('valid');
            email_field.addClass('error');
        }
        return return_flag;
    }
}

function validatePassword(action) {
    var return_flag = true;
    var password_field = jQuery('#edit-password');
    var password_reenter_field = jQuery('#edit-password-reenter');
    var error_list = jQuery('#cls-mcl-account-errors ul');
    if (password_field.length > 0) {
        var password = password_field.val();
        var password_error_label = jQuery('#cls-mcl-account-errors label[for="edit-password"]');
        if (action == 'create' && !password) {
            return_flag = false;
            error = 'Password is required.';
        }
        else if (password_reenter_field.length > 0) {
            var password_reenter = password_reenter_field.val();
            if (password != password_reenter) {
                return_flag = false;
                error = 'Passwords do not match.';
            }
        }
        if (return_flag) {
            jQuery('#cls-mcl-account-errors li#edit-password-error').remove();
            if (password_error_label.length == 0) {
                password_field.removeClass('error');
                password_field.addClass('valid');
            }
            hideErrorContainer();
        }
        else {
            displayErrorContainer();
            if (password_error_label.length == 0) {
                jQuery('#cls-mcl-account-errors ul').append('<li id="edit-password-error"><label class="error" for="edit-password" generated="true">' + error + '</label></li>');
            } else {
                password_error_label.html(error);
            }
            password_field.removeClass('valid');
            password_field.addClass('error');
        }
        return return_flag;
    }
}

function validateSecurityQuestion() {
    var return_flag = true;
    var security_question_field = jQuery('#edit-security-question-select');
    if (security_question_field.length > 0) {
        var security_question_other_field = jQuery('#edit-security-question-other');
        var security_question_error_label = jQuery('#cls-mcl-account-errors label[for="edit-security-question"]');
        var error_list = jQuery('#cls-mcl-account-errors ul');
        if (security_question_field.val() == "") {
            security_question_field.removeClass('valid');
            security_question_field.addClass('error');
            displayErrorContainer();
            if (security_question_error_label.length == 0) {
                error_list.append('<li id="edit-security-question-error"><label class="error" for="edit-security-question" generated="true">Please select or enter your security question.</label></li>');
            } else {
                security_question_error_label.html('Please select or enter your security question.');
            }
            return_flag = false;
        } else if (security_question_field.val() == "select_or_other" && jQuery.trim(jQuery('#edit-security-question-other').val()) == "") {
            security_question_other_field.removeClass('valid');
            security_question_other_field.addClass('error');
            displayErrorContainer();
            if (security_question_error_label.length == 0) {
                error_list.append('<li id="edit-security-question-error"><label class="error" for="edit-security-question" generated="true">Please type in your Security Question.</label></li>');
            } else {
                security_question_error_label.html('Please select or enter your security question.');
            }
            return_flag = false;
        } else {
            hideErrorContainer();
            jQuery('#edit-security-question-error').remove();
            security_question_field.removeClass('error');
            security_question_field.addClass('valid');
            security_question_other_field.removeClass('error');
            security_question_other_field.addClass('valid');
            return_flag = true;
        }
    }
    return return_flag;
}

function validateSecurityAnswer(action) {
    var return_flag = true;
    var security_answer_field = jQuery('#edit-security-answer');
    if (security_answer_field.length > 0) {
        var security_answer = security_answer_field.val();
        var security_answer_error_label = jQuery('#cls-mcl-account-errors label[for="edit-security-answer"]');
        var error_list = jQuery('#cls-mcl-account-errors ul');
        var error = '';
        security_answer = jQuery.trim(security_answer);
        if (action == 'create' && !security_answer) {
            return_flag = false;
            error = 'Security answer is required.';
        }
        else {
            if (security_answer == "Your Answer") {
                return_flag = false;
                error = 'Invalid Security Answer.';
            }
            else {
                var pattern = /^([A-Z|a-z]{2,}([A-Z|a-z|0-9|\-|\_|\.|\,|\:|\;|\'|\"|\/|\!|\?|\@|\#|\$|\%|\(|\)||\=|\+|\s]{1,})?)?$/;
                if (!pattern.test(security_answer)) {
                    return_flag = false;
                    error = 'Security Answer has invalid format.';
                }
            }
        }
        if (return_flag) {
            jQuery('#cls-mcl-account-errors li#edit-security-answer-error').remove();
            if (security_answer_error_label.length == 0) {
                security_answer_field.removeClass('error');
                security_answer_field.addClass('valid');
            }
            hideErrorContainer();
        }
        else {
            displayErrorContainer();
            if (security_answer_error_label.length == 0) {
                jQuery('#cls-mcl-account-errors ul').append('<li id="edit-security-answer-error"><label class="error" for="edit-security-answer" generated="true">' + error + '</label></li>');
            } else {
                security_answer_error_label.html(error);
            }
            security_answer_field.removeClass('valid');
            security_answer_field.addClass('error');
        }
        return return_flag;
    }
}

function validateApplicationYear() {
    if (jQuery('#edit-application-year').length > 0 && jQuery('#edit-application-year').val() == "") {
        jQuery('#edit-application-year').removeClass('valid');
        jQuery('#edit-application-year').addClass('error');
        displayErrorContainer();
        if (jQuery('#cls-mcl-account-errors label[for="edit-application-year"]').length == 0) {
            jQuery('#cls-mcl-account-errors ul').append('<li id="edit-application-year-error"><label class="error" for="edit-application-year" generated="true">Application Year is required.</label></li>');
        } else {
            jQuery('#cls-mcl-account-errors label[for="edit-application-year"]').html('Application Year is required.');
        }
        return false;
    } else {
        hideErrorContainer();
        if (jQuery('#edit-application-year').length > 0) {
            jQuery('#cls-mcl-account-errors li#edit-application-year-error').remove();
            jQuery('#edit-application-year').removeClass('error');
            jQuery('#edit-application-year').addClass('valid');
        }
        return true;
    }
}

function validateCountry() {
    if (jQuery('#edit-country').length > 0 && jQuery('#edit-country').val() == "") {
        jQuery('#edit-country').removeClass('valid');
        jQuery('#edit-country').addClass('error');
        displayErrorContainer();
        if (jQuery('#cls-mcl-account-errors label[for="edit-country"]').length == 0) {
            jQuery('#cls-mcl-account-errors ul').append('<li id="edit-country-error"><label class="error" for="edit-country" generated="true">Country is required.</label></li>');
        } else {
            jQuery('#cls-mcl-account-errors label[for="edit-country"]').html('Country is required.');
        }
        return false;
    } else {
        hideErrorContainer();
        if (jQuery('#edit-country').length > 0) {
            jQuery('#cls-mcl-account-errors li#edit-country-error').remove();
            jQuery('#edit-country').removeClass('error');
            jQuery('#edit-country').addClass('valid');
        }
        return true;
    }
}

function validateStateOrProvince() {
    if (jQuery('#edit-state-province').length > 0 && jQuery('#edit-state-province').val() == "") {
        jQuery('#edit-state-province').removeClass('valid');
        jQuery('#edit-state-province').addClass('error');
        displayErrorContainer();
        if (jQuery('#cls-mcl-account-errors label[for="edit-state-province"]').length == 0) {
            jQuery('#cls-mcl-account-errors ul').append('<li id="edit-state-province-error"><label class="error" for="edit-state-province" generated="true">State or Province is required if country is US or Canada.</label></li>');
        } else {
            jQuery('#cls-mcl-account-errors label[for="edit-state-province"]').html('State or Province is required if country is US or Canada.');
        }
        return false;
    } else {
        hideErrorContainer();
        if (jQuery('#edit-state-province').length > 0) {
            jQuery('#cls-mcl-account-errors li#edit-state-province-error').remove();
            jQuery('#edit-state-province').removeClass('error');
            jQuery('#edit-state-province').addClass('valid');
        }
        return true;
    }
}

function validateCity() {
    if (jQuery('#edit-city').length > 0) {
        var return_flag = true;
        var city_field = jQuery('#edit-city');
        var city = city_field.val();
        var city_error_label = jQuery('#cls-mcl-account-errors label[for="edit-city"]');
        var error = '';
        city = jQuery.trim(city);

        if (!city) {
            return_flag = false;
            error = ' is required.';
        }
        else {
            var pattern = /^([A-Z|a-z|\-|\.|\'|\s]{1,})?$/;
            if (!pattern.test(city)) {
                return_flag = false;
                error = ' can only contain letters, dashes and spaces.';
            }
        }

        if (return_flag) {
            jQuery('#cls-mcl-account-errors li#edit-city-error').remove();
            if (city_error_label.length == 0) {
                city_field.removeClass('error');
                city_field.addClass('valid');
            }
            hideErrorContainer();
        }
        else {
            displayErrorContainer();
            if (city_error_label.length == 0) {
                jQuery('#cls-mcl-account-errors ul').append('<li id="edit-city-error"><label class="error" for="edit-city" generated="true">City' + error + '</label></li>');
            } else {
                city_error_label.html('City' + error);
            }
            city_field.removeClass('valid');
            city_field.addClass('error');
        }
        return return_flag;
    }
    return true;
}

function validateZipCode() {
    if (jQuery('#edit-zip-code').length > 0) {
        var return_flag = true;
        var zip_code_field = jQuery('#edit-zip-code');
        var zip_code = zip_code_field.val();
        var zip_code_error_label = jQuery('#cls-mcl-account-errors label[for="edit-zip-code"]');
        var error = '';
        zip_code = jQuery.trim(zip_code);

        if (!zip_code) {
            return_flag = false;
            error = ' is required if country is USA.';
        }
        else {
            var pattern = /^[0-9]{5}$/;
            if (!pattern.test(zip_code)) {
                return_flag = false;
                error = ' has invalid format.';
            }
        }

        if (return_flag) {
            jQuery('#cls-mcl-account-errors li#edit-zip-code-error').remove();
            if (zip_code_error_label.length == 0) {
                zip_code_field.removeClass('error');
                zip_code_field.addClass('valid');
            }
            hideErrorContainer();
        }
        else {
            displayErrorContainer();
            if (zip_code_error_label.length == 0) {
                jQuery('#cls-mcl-account-errors ul').append('<li id="edit-zip-code-error"><label class="error" for="edit-zip-code" generated="true">Zip Code' + error + '</label></li>');
            } else {
                zip_code_error_label.html('Zip Code' + error);
            }
            zip_code_field.removeClass('valid');
            zip_code_field.addClass('error');
        }
        return return_flag;
    }
    return true;
}

function validateUndergraduateSchoolName(instance_id, action, existing_undergrad_school) {
    if (jQuery('#edit-undergrad-school-name').length > 0) {
        var return_flag = true;
        var undergrad_school_field = jQuery('#edit-undergrad-school-name');
        var undergrad_school_name = undergrad_school_field.val();
        var undergrad_school_error_label = jQuery('#cls-mcl-account-errors label[for="edit-undergrad-school-name"]');
        var undergrad_school_other_field = jQuery('#edit-undergrad-school-name-other');
        var undergrad_school_other_value = undergrad_school_other_field.val();
        var error = '';
        undergrad_school_other_value = jQuery.trim(undergrad_school_other_value);
        if (instance_id == 'my_columbia_llm' && undergrad_school_name == 0 && !undergrad_school_other_value && (action == "create" || action == "edit" && !existing_undergrad_school)) {
            return_flag = false;
            error = ' is required.';
        }
        else if (undergrad_school_other_value.length > 0 && undergrad_school_other_value.length < 2) {
            return_flag = false;
            error = ' must contain at least two characters.';
        }
        else {
            var pattern = /^([A-Z|a-z|\-|\.|\'|\s]{1,})?$/;
            if (!pattern.test(undergrad_school_other_value)) {
                return_flag = false;
                error = ' can only contain letters, dashes and spaces.';
            }
        }

        if (return_flag) {
            jQuery('#cls-mcl-account-errors li#edit-undergrad-school-name-error').remove();
            if (undergrad_school_error_label.length == 0) {
                undergrad_school_field.removeClass('error');
                undergrad_school_field.addClass('valid');
            }
            hideErrorContainer();
        }
        else {
            displayErrorContainer();
            if (undergrad_school_error_label.length == 0) {
            	if (instance_id == 'my_columbia_law') {
                    jQuery('#cls-mcl-account-errors ul').append('<li id="edit-undergrad-school-name-error"><label class="error" for="edit-undergrad-school-name" generated="true">Undergraduate School Name' + error + '</label></li>');
            	}
            	else if (instance_id == 'my_columbia_llm') {
            		jQuery('#cls-mcl-account-errors ul').append('<li id="edit-undergrad-school-name-error"><label class="error" for="edit-undergrad-school-name" generated="true">First Law Degree' + error + '</label></li>');
            	}
            } else {
            	if (instance_id == 'my_columbia_law') {
                    undergrad_school_error_label.html('Undergraduate School Name' + error);
            	}
            	else if (instance_id == 'my_columbia_llm') {
            		undergrad_school_error_label.html('First Law Degree' + error);
            	}
            }
            undergrad_school_field.removeClass('valid');
            undergrad_school_field.addClass('error');
        }
        return return_flag;
    }
}

function validateGraduateSchoolName() {
    if (jQuery('#edit-grad-school-name').length > 0) {
        var return_flag = true;
        var graduate_school_field = jQuery('#edit-grad-school-name');
        var graduate_school_name = graduate_school_field.val();
        var graduate_school_error_label = jQuery('#cls-mcl-account-errors label[for="edit-grad-school-name"]');
        var graduate_school_other_field = jQuery('#edit-grad-school-name-other');
        var graduate_school_other_value = graduate_school_other_field.val();
        var error = '';
        graduate_school_other_value = jQuery.trim(graduate_school_other_value);
        if (graduate_school_other_value.length > 0 && graduate_school_other_value.length < 2) {
            return_flag = false;
            error = ' must contain at least two characters.';
        }
        else {
            var pattern = /^([A-Z|a-z|\-|\.|\'|\s]{1,})?$/;
            if (!pattern.test(graduate_school_other_value)) {
                return_flag = false;
                error = ' can only contain letters, dashes and spaces.';
            }
        }

        if (return_flag) {
            jQuery('#cls-mcl-account-errors li#edit-grad-school-name-error').remove();
            if (graduate_school_error_label.length == 0) {
                graduate_school_field.removeClass('error');
                graduate_school_field.addClass('valid');
            }
            hideErrorContainer();
        }
        else {
            displayErrorContainer();
            if (graduate_school_error_label.length == 0) {
                jQuery('#cls-mcl-account-errors ul').append('<li id="edit-grad-school-name-error"><label class="error" for="edit-grad-school-name" generated="true">Graduate School Name' + error + '</label></li>');
            } else {
                graduate_school_error_label.html('Graduate School Name' + error);
            }
            graduate_school_field.removeClass('valid');
            graduate_school_field.addClass('error');
        }
        return return_flag;
    }
}

function validateFirstGraduationYear() {
    if (jQuery('#edit-undergrad-graduation-year').length > 0 && jQuery('#edit-undergrad-graduation-year').val() == "") {
        jQuery('#edit-undergrad-graduation-year').removeClass('valid');
        jQuery('#edit-undergrad-graduation-year').addClass('error');
        displayErrorContainer();
        if (jQuery('#cls-mcl-account-errors label[for="edit-undergrad-graduation-year"]').length == 0) {
            jQuery('#cls-mcl-account-errors ul').append('<li id="edit-undergrad-graduation-year-error"><label class="error" for="edit-undergrad-graduation-year" generated="true">Graduation Year is required.</label></li>');
        } else {
            jQuery('#cls-mcl-account-errors label[for="edit-undergrad-graduation-year"]').html('Graduation Year is required.');
        }
        return false;
    } else {
        hideErrorContainer();
        if (jQuery('#edit-undergrad-graduation-year').length > 0) {
            jQuery('#cls-mcl-account-errors li#edit-undergrad-graduation-year-error').remove();
            jQuery('#edit-undergrad-graduation-year').removeClass('error');
            jQuery('#edit-undergrad-graduation-year').addClass('valid');
        }
        return true;
    }
}

function displayErrorContainer() {
    jQuery('#cls-mcl-account-errors, #cls-mcl-account-errors ul').show();
}

function hideErrorContainer() {
    var error_list = jQuery('#cls-mcl-account-errors ul');
    if (error_list.html() == "") {
        error_list.hide();
        jQuery('#cls-mcl-account-errors').hide();
    }
}
