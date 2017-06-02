(function ($) {
  Drupal.behaviors.clsmcllogin = {
    attach: function(context, settings) {
      $('form#cls-mcl-login-form .form-item #edit-name').focus();
      $('form#cls-mcl-login-form .form-item #edit-name:not(.no-big)').not('[value=\'\']').select();
      $('form#cls-mcl-login-form .form-item input:not(.no-big)').not('[value=\'\']').addClass('no-bg');
      
      $('form#cls-mcl-login-form input.form-text').keypress(function() {
        $(this).addClass('no-bg');
      });
      $('form#cls-mcl-login-form input.form-text').focusout(function() {
        if ($(this).val() === '') {
          $(this).removeClass('no-bg');
        }
      });
    }
  };
})(jQuery);
