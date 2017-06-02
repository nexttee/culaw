<div class="mcl-login-form-login">
  <h2><?php echo ($instance_id == "my_columbia_llm") ? "My Columbia LL.M. and Admitted Student" : "My Columbia Law and Admitted Student" ?></h2>
  <h3>Password Recovery</h3>
  <span class="error-msg">
    <?php echo (isset($_SESSION['messages']['error'][0])) ? $_SESSION['messages']['error'][0] : "" ?>
  </span>
  <?php echo drupal_render($form); ?>
  <p class="back-to-login">
    <a id="back-to-login-link" href="<?php echo base_path() . $path ?>">Go back to the login page</a>
  </p>
</div>

<script type="text/javascript">
<!--//--><![CDATA[//><!--
(function ($) {
  Drupal.behaviors.clssso = {
    attach: function(context, settings) {
      try {
        if ($('#edit-name') != undefined) {
	        $('#edit-name').focus();
        }
      } catch (e) {};
    }
  };
})(jQuery);
//--><!]]>
</script>
<style type="text/css">
body div.messages {display: none;}
.menu-mlid-4476 a,
.menu-mlid-7367 a,
.menu-mlid-14052 > a {color:#333333;}
div.mcl-login-form-login label {
  font-weight: bold;
	font-size: 13px;
	color: #333333;
}
.region-sidebar-first li.menu-mlid-14052.expanded {
  margin: 0 0 10px !important;
  padding: 0 0 10px !important;
}
div.mcl-login-form-login div#edit-actions {
  margin-bottom: 0 !important;
  margin-top: 15px !important;
}

div.mcl-login-form-login label span.form-required {
  display: none;
}

div.mcl-login-form-login span.error-msg {
	color: #cc0000;
	font-size: 13px;
	font-style: italic;
}

div.mcl-login-form-login input#edit-next,
div.mcl-login-form-login input#edit-submit {
	border-radius: 15px;
	-moz-border-radius: 15px;
    -webkit-border-radius: 15px;
    background-color: #333333;
    border: 2px solid #999999;
    color: #FFFFFF;
    font: 15px Verdana, Arial, sans-serif;
    padding: 1px 10px 3px;
    margin-bottom: 15px;
}

div.mcl-login-form-login input#edit-next:active,
div.mcl-login-form-login input#edit-submit:active {
    background-color: #186E9E;
    color: #FFFFFF;
}

div.mcl-login-form-login input#edit-name,
div.mcl-login-form-login input#edit-security-answer,
div.mcl-login-form-login input#edit-password,
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

div.mcl-login-form-login input#edit-name:focus,
div.mcl-login-form-login input#edit-security-answer {	
	border: #186E9E 2px solid;
}

p#mcl-password-recovery-security-question {
  font-size: 13px;
  margin-top: 10px;
}

</style>
