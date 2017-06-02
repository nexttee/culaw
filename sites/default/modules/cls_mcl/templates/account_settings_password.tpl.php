<div class="mcl-login-form-login">
  <h2><?php echo ($instance_id == "my_columbia_llm") ? "My Columbia LL.M." : "My Columbia Law" . " Admitted Student" ?></h2>
  <h3>Password Change Form</h3>
  <div <?php echo (isset($_SESSION['messages']['status'][0])) ? "class='status-msg'" : "" ?> >
    <?php echo (isset($_SESSION['messages']['status'][0])) ? $_SESSION['messages']['status'][0] : "" ?>
  </div> 
  <div <?php echo (isset($_SESSION['messages']['error'][0])) ? "class='error-msg'" : "" ?> >
    <?php echo (isset($_SESSION['messages']['error'][0])) ? $_SESSION['messages']['error'][0] : "" ?>
  </div>
  <?php echo drupal_render($form); ?>
  <p class="back-to-account-settings">
    <a id="back-to-account-settings-link" href=".">Back to Account Settings</a>
  </p>
</div>

<script type="text/javascript">
<!--//--><![CDATA[//><!--
(function ($) {
  Drupal.behaviors.clsmclpasswordchange = {
    attach: function(context, settings) {
      try {
        if ($('#edit-current-password') != undefined) {
	        $('#edit-current-password').focus();
        }
      } catch (e) {};
    }
  };
})(jQuery);
//--><!]]>
</script>
<style type="text/css">
body div.messages {display: none;}
.menu-mlid-4476 a {color:#333333;}
div.mcl-login-form-login label {
  font-weight: bold;
	font-size: 13px;
	color: #333333;
}

div.mcl-login-form-login div#edit-actions {
  margin-bottom: 0 !important;
  margin-top: 15px !important;
}

div.mcl-login-form-login label span.form-required {
  display: none;
}

div.error-msg {
    background-color: #FEF5F1;
    color: #8C2E0B;
    border: 1px solid #ED541D;
    background-image: url("/misc/message-24-error.png");
    background-position: 8px 8px;
    background-repeat: no-repeat;
    margin: 6px 0;
    padding: 10px 10px 10px 50px;
    font-size: 13px;
} 

div.status-msg {
    background-color: #F8FFF0;
    color: #234600;
    border: 1px solid #BBEE77;
    background-image: url("/misc/message-24-ok.png");
    background-position: 8px 8px;
    background-repeat: no-repeat;
    margin: 6px 0;
    padding: 10px 10px 10px 50px;
    font-size: 13px;
    font-style: italic;
}

div.mcl-login-form-login input#edit-submit {
	border-radius: 15px;
	-moz-border-radius: 15px;
    -webkit-border-radius: 15px;
    background-color: #333333;
    border: 2px solid #999999;
    color: #FFFFFF;
    font: 15px Verdana, Arial, sans-serif;
    padding: 3px 15px 5px;
    margin-bottom: 15px;
    margin-top: 10px;
}

div.mcl-login-form-login input#edit-submit:active {
    background-color: #186E9E;
    color: #FFFFFF;
}

div.mcl-login-form-login input#edit-current-password,
div.mcl-login-form-login input#edit-new-password,
div.mcl-login-form-login input#edit-password-reenter {
	background-color: #FFFFFF;
    border: 2px solid #999999;
    border-radius:15px;
	-moz-border-radius:15px;
	-webkit-border-radius:15px;
    color: #666666;
    display: block;
    font: 21px/18px Verdana,Arial,Helvetica,sans-serif;
    height: 25px;
    margin: 10px 0;
    padding: 1px 10px 3px;
    width: 221px;
}

div.mcl-login-form-login input#edit-password:focus,
div.mcl-login-form-login input#edit-password-reenter {	
	border: #186E9E 2px solid;
}

p#mcl-password-reenter {
  font-size: 13px;
  margin-top: 10px;
}

</style>
