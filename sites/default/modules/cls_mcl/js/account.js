(function ($) {
  Drupal.behaviors.cls_mcl_account = {
    attach: function (context, settings) {

      var instance_id = Drupal.settings.cls_mcl_account.instance_id;
      var action = Drupal.settings.cls_mcl_account.action;
      var uid = Drupal.settings.cls_mcl_account.uid;
      if (action == 'edit') {
    	var existing_undergrad_school = Drupal.settings.cls_mcl_account.existing_undergrad_school;
      }
      else {
    	  var existing_undergrad_school = 0;
      }

      if (action === 'edit_security_question') {
        $('#edit-security-question').focus();
        $('#cls-mcl-security-question-update').submit(function () {
          return performClientsideValidationSecurityQuestion();
        });
      }
      else {
        // @TODO Add a spinner using the approach on
        //   http://jsfiddle.net/amanaplan/zY2PC/

        $('#cls-mcl-new-account #edit-first-name').focus();

        $('#cls-mcl-new-account, #cls-mcl-profile-update').submit(function (event) {
          var validation = performClientsideValidation(instance_id, action, existing_undergrad_school);
          if (validation === true) {
            return;
          }
          event.preventDefault();
          jQuery('#cls-mcl-account-errors ul li, #cls-mcl-account-errors ul li label').show();
          event.stopPropagation();
        });

        $('#edit-birth-date').datepicker({
          dateFormat: 'mm-dd-yy',
          yearRange: '-80:-13',
          changeMonth: true,
          changeYear: true,
          defaultDate: '-22y'
        });

        $('#edit-security-answer').click(function () {
          if ($('#edit-security-answer').val() === 'Your Answer') {
            $('#edit-security-answer').val('');
          }
        });

        reloadCountryDependencies(instance_id);

        $('#edit-country').change(function () {
          reloadCountryDependencies(instance_id);
        });
      }
    }
  };
})(jQuery);

// @TODO Namespace this function so it doesn't exist in the global scope
// @TODO Refactor the state names in a scoped variable
function reloadCountryDependencies(instance_id) {
    var country = jQuery('#edit-country').val();
    // @TODO Need to review further
    if (country == '') { // City will be removed on LLM form
      if (jQuery('#edit-city').length > 0 && instance_id == 'my_columbia_llm') {
    	  jQuery('#edit-city').val('');
          jQuery('.form-item-city').remove();
          jQuery('#cls-mcl-account-errors li#edit-city-error').remove();
      }
    }
    else { // Country is selected, therefore city field will be added
      if (jQuery('#edit-city').length == 0) {
        if (jQuery('#edit-state-province').length == 0) { // State/Province field does not exist, add city after country
        	jQuery('.form-item-country').after('<div class="form-item form-type-textfield form-item-city"><label for="edit-city">City <span class="form-required" title="This field is required.">*</span></label><input id="edit-city" class="form-text required" type="text" maxlength="128" size="60" value="" name="city"></div>');
        }
        else if (jQuery('#edit-state-province').length > 0) { // Add city after state/province
        	jQuery('.form-item-state-province').after('<div class="form-item form-type-textfield form-item-city"><label for="edit-city">City <span class="form-required" title="This field is required.">*</span></label><input id="edit-city" class="form-text required" type="text" maxlength="128" size="60" value="" name="city"></div>');
        }
      }
    }
    if (country != 'USA') {
        jQuery('#edit-zip-code').val('');
        jQuery('.form-item-zip-code').remove();
        jQuery('#cls-mcl-account-errors li#edit-zip-code-error').remove();

        if (country != 'CAN') {
            jQuery('#edit-state-province').val('');
            jQuery('.form-item-state-province').remove();
            jQuery('#cls-mcl-account-errors li#edit-state-province-error').remove();
        } else {
            if (jQuery('#edit-state-province').length == 0) { //State/province field does not exist and will be added
                jQuery('.form-item-country').after('<div class="form-item form-type-select form-item-state-province"><label for="edit-state-province">State/Province <span class="form-required" title="This field is required.">*</span></label><select id="edit-state-province" name="state_province" class="form-select required"><option value="">\xe2\x80\x94 Select your state/province \xe2\x80\x94</option><option value="AL">Alabama                                                     </option><option value="AK">Alaska                                                      </option><option value="AB">Alberta                                                     </option><option value="AS">American Samoa                                              </option><option value="AZ">Arizona                                                     </option><option value="AR">Arkansas                                                    </option><option value="BC">British Columbia                                            </option><option value="CA">California                                                  </option><option value="CO">Colorado                                                    </option><option value="CT">Connecticut                                                 </option><option value="DC">D.C.                                                       </option><option value="DE">Delaware                                                    </option><option value="FL">Florida                                                     </option><option value="GA">Georgia                                                     </option><option value="GU">Guam                                                        </option><option value="HI">Hawaii                                                      </option><option value="ID">Idaho                                                       </option><option value="IL">Illinois                                                    </option><option value="IN">Indiana                                                     </option><option value="IA">Iowa                                                        </option><option value="KS">Kansas                                                      </option><option value="KY">Kentucky                                                    </option><option value="PW">Koror Caroline Islan                                        </option><option value="LB">Labrador                                                    </option><option value="LA">Louisiana                                                   </option><option value="ME">Maine                                                       </option><option value="MB">Manitoba                                                    </option><option value="TT">Mariana Islands                                             </option><option value="MH">Marshal Islands                                             </option><option value="MD">Maryland                                                    </option><option value="MA">Massachusetts                                               </option><option value="MI">Michigan                                                    </option><option value="MN">Minnesota                                                   </option><option value="MS">Mississippi                                                 </option><option value="MO">Missouri                                                    </option><option value="MT">Montana                                                     </option><option value="MP">N.  Mariana Islands                                         </option><option value="XX">N/a                                                         </option><option value="NE">Nebraska                                                    </option><option value="NV">Nevada                                                      </option><option value="NB">New Brunswick                                               </option><option value="NH">New Hampshire                                               </option><option value="NJ">New Jersey                                                  </option><option value="NM">New Mexico                                                  </option><option value="NY" selected="selected">New York                                                    </option><option value="NF">Newfoundland                                                </option><option value="NC">North Carolina                                              </option><option value="ND">North Dakota                                                </option><option value="NS">Nova Scotia                                                 </option><option value="NT">Nw Territories                                              </option><option value="OH">Ohio                                                        </option><option value="OK">Oklahoma                                                    </option><option value="ON">Ontario                                                     </option><option value="OR">Oregon                                                      </option><option value="PA">Pennsylvania                                                </option><option value="PE">Prince Edward Island                                        </option><option value="PR">Puerto Rico                                                 </option><option value="PQ">Quebec                                                      </option><option value="RI">Rhode Island                                                </option><option value="SK">Saskatchewan                                                </option><option value="AA">Service State                                               </option><option value="SC">South Carolina                                              </option><option value="SD">South Dakota                                                </option><option value="AE">State Service                                               </option><option value="FM">States Of Micronesia                                        </option><option value="TN">Tennessee                                                   </option><option value="TX">Texas                                                       </option><option value="UT">Utah                                                        </option><option value="VT">Vermont                                                     </option><option value="VI">Virgin Islands                                              </option><option value="VA">Virginia                                                    </option><option value="WA">Washington                                                  </option><option value="WV">West Virginia                                               </option><option value="WI">Wisconsin                                                   </option><option value="WY">Wyoming                                                     </option><option value="WT">Yukon Territory                                             </option></select></div>');
            }
        }
    } else if (country == 'USA') {
        if (jQuery('#edit-zip-code').length == 0) { //Zip code field does not exist and will be added
            jQuery('.form-item-city').after('<div class="form-item form-type-textfield form-item-zip-code"><label for="edit-zip-code">ZIP Code <span class="form-required" title="This field is required.">*</span></label><input type="text" id="edit-zip-code" name="zip_code" value="" size="5" maxlength="5" class="form-text required" /></div>');
        }
        if (jQuery('#edit-state-province').length == 0) { //State/province field does not exist and will be added
            jQuery('.form-item-country').after('<div class="form-item form-type-select form-item-state-province"><label for="edit-state-province">State/Province <span class="form-required" title="This field is required.">*</span></label><select id="edit-state-province" name="state_province" class="form-select required"><option value="AL">Alabama                                                     </option><option value="AK">Alaska                                                      </option><option value="AB">Alberta                                                     </option><option value="AS">American Samoa                                              </option><option value="AZ">Arizona                                                     </option><option value="AR">Arkansas                                                    </option><option value="BC">British Columbia                                            </option><option value="CA">California                                                  </option><option value="CO">Colorado                                                    </option><option value="CT">Connecticut                                                 </option><option value="DC">D.C.                                                       </option><option value="DE">Delaware                                                    </option><option value="FL">Florida                                                     </option><option value="GA">Georgia                                                     </option><option value="GU">Guam                                                        </option><option value="HI">Hawaii                                                      </option><option value="ID">Idaho                                                       </option><option value="IL">Illinois                                                    </option><option value="IN">Indiana                                                     </option><option value="IA">Iowa                                                        </option><option value="KS">Kansas                                                      </option><option value="KY">Kentucky                                                    </option><option value="PW">Koror Caroline Islan                                        </option><option value="LB">Labrador                                                    </option><option value="LA">Louisiana                                                   </option><option value="ME">Maine                                                       </option><option value="MB">Manitoba                                                    </option><option value="TT">Mariana Islands                                             </option><option value="MH">Marshal Islands                                             </option><option value="MD">Maryland                                                    </option><option value="MA">Massachusetts                                               </option><option value="MI">Michigan                                                    </option><option value="MN">Minnesota                                                   </option><option value="MS">Mississippi                                                 </option><option value="MO">Missouri                                                    </option><option value="MT">Montana                                                     </option><option value="MP">N.  Mariana Islands                                         </option><option value="XX">N/a                                                         </option><option value="NE">Nebraska                                                    </option><option value="NV">Nevada                                                      </option><option value="NB">New Brunswick                                               </option><option value="NH">New Hampshire                                               </option><option value="NJ">New Jersey                                                  </option><option value="NM">New Mexico                                                  </option><option value="NY" selected="selected">New York                                                    </option><option value="NF">Newfoundland                                                </option><option value="NC">North Carolina                                              </option><option value="ND">North Dakota                                                </option><option value="NS">Nova Scotia                                                 </option><option value="NT">Nw Territories                                              </option><option value="OH">Ohio                                                        </option><option value="OK">Oklahoma                                                    </option><option value="ON">Ontario                                                     </option><option value="OR">Oregon                                                      </option><option value="PA">Pennsylvania                                                </option><option value="PE">Prince Edward Island                                        </option><option value="PR">Puerto Rico                                                 </option><option value="PQ">Quebec                                                      </option><option value="RI">Rhode Island                                                </option><option value="SK">Saskatchewan                                                </option><option value="AA">Service State                                               </option><option value="SC">South Carolina                                              </option><option value="SD">South Dakota                                                </option><option value="AE">State Service                                               </option><option value="FM">States Of Micronesia                                        </option><option value="TN">Tennessee                                                   </option><option value="TX">Texas                                                       </option><option value="UT">Utah                                                        </option><option value="VT">Vermont                                                     </option><option value="VI">Virgin Islands                                              </option><option value="VA">Virginia                                                    </option><option value="WA">Washington                                                  </option><option value="WV">West Virginia                                               </option><option value="WI">Wisconsin                                                   </option><option value="WY">Wyoming                                                     </option><option value="WT">Yukon Territory                                             </option></select></div>');
        }

    }
    hideErrorContainer();
}

function toggleUndergradSchoolOtherField() {
  jQuery.fn.slideFadeToggle  = function(speed, easing, callback) {
    return this.animate({opacity: 'toggle', height: 'toggle'}, speed, easing, callback);
  };
	jQuery('#edit-undergrad-school-name-other').val('');
	jQuery('#edit-undergrad-school-name').select2("val", "");
	jQuery('#undergrad-school-name-field-container').toggle();
	jQuery('#undergrad-school-name-other-field-container').toggle();
	var visarea = jQuery('#undergrad-school-other-display-link-area:visible');
	var vishide = jQuery('#undergrad-school-other-display-link-area-hide:visible');
	if (visarea.length > 0) {
	  jQuery('#edit-undergrad-school-name').select2("close");
	  jQuery('#undergrad-school-other-display-link-area').slideFadeToggle( 400, function() {
      jQuery('#undergrad-school-other-display-link-area-hide').slideFadeToggle();
    });
    jQuery('#edit-undergrad-school-name-other').focus();
	}
	if (vishide.length > 0) {
	  jQuery('#undergrad-school-other-display-link-area-hide').slideFadeToggle( 400, function() {
      jQuery('#undergrad-school-other-display-link-area').slideFadeToggle( 400, function() {
        jQuery('#edit-undergrad-school-name').select2("open");
      });
    });
	}
}

function toggleGradSchoolOtherField() {
  jQuery.fn.slideFadeToggle  = function(speed, easing, callback) {
    return this.animate({opacity: 'toggle', height: 'toggle'}, speed, easing, callback);
  };
	jQuery('#edit-grad-school-name-other').val('');
	jQuery('#edit-grad-school-name').select2("val", "");
	jQuery('#grad-school-name-field-container').toggle();
	jQuery('#grad-school-name-other-field-container').toggle();
	var visarea = jQuery('#grad-school-other-display-link-area:visible');
	var vishide = jQuery('#grad-school-other-display-link-area-hide:visible');
	if (visarea.length > 0) {
	  jQuery('#edit-grad-school-name').select2("close");
	  jQuery('#grad-school-other-display-link-area').slideFadeToggle( 400, function() {
      jQuery('#grad-school-other-display-link-area-hide').slideFadeToggle();
    });
    jQuery('#edit-grad-school-name-other').focus();
	}
	if (vishide.length > 0) {
	  jQuery('#grad-school-other-display-link-area-hide').slideFadeToggle( 400, function() {
      jQuery('#grad-school-other-display-link-area').slideFadeToggle( 400, function() {
        jQuery('#edit-grad-school-name').select2("open");
      });
    });
	}
}
