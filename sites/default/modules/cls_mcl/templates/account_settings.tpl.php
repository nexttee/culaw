<?php

  $first_name = isset($user->cls_user_first_name) && $user->cls_user_first_name && isset($user->cls_user_first_name['und']) && $user->cls_user_first_name['und'] && isset($user->cls_user_first_name['und'][0]) && $user->cls_user_first_name['und'][0] && isset($user->cls_user_first_name['und'][0]['value']) && $user->cls_user_first_name['und'][0]['value'] ? $user->cls_user_first_name['und'][0]['value'] . " " : " ";
  $middle_name = isset($user->cls_user_middle_name) && $user->cls_user_middle_name && isset($user->cls_user_middle_name['und']) && $user->cls_user_middle_name['und'] && isset($user->cls_user_middle_name['und'][0]) && $user->cls_user_middle_name['und'][0] && isset($user->cls_user_middle_name['und'][0]['value']) && $user->cls_user_middle_name['und'][0]['value'] ? $user->cls_user_middle_name['und'][0]['value'] . " " : " ";
  $last_name = isset($user->cls_user_last_name) && $user->cls_user_last_name && isset($user->cls_user_last_name['und']) && $user->cls_user_last_name['und'] && isset($user->cls_user_last_name['und'][0]) && $user->cls_user_last_name['und'][0] && isset($user->cls_user_last_name['und'][0]['value']) && $user->cls_user_last_name['und'][0]['value'] ? $user->cls_user_last_name['und'][0]['value'] . " " : " ";
  $account_type = isset($user->cls_mcl_account_type) && $user->cls_mcl_account_type && isset($user->cls_mcl_account_type['und']) && $user->cls_mcl_account_type['und'] && isset($user->cls_mcl_account_type['und'][0]) && $user->cls_mcl_account_type['und'][0] && isset($user->cls_mcl_account_type['und'][0]['value']) && $user->cls_mcl_account_type['und'][0]['value'] ? $user->cls_mcl_account_type['und'][0]['value'] : "";
  $account_type = ($account_type == "my_columbia_llm") ? "Admitted student account (LL.M.)" : $account_type;
  $account_type = ($account_type == "my_columbia_law") ? "Admitted student account (J.D.)" : $account_type;
  
  $security_question = isset($user->cls_mcl_security_question) && $user->cls_mcl_security_question && isset($user->cls_mcl_security_question['und']) && $user->cls_mcl_security_question['und'] && isset($user->cls_mcl_security_question['und'][0]) && $user->cls_mcl_security_question['und'][0] && isset($user->cls_mcl_security_question['und'][0]['value']) && $user->cls_mcl_security_question['und'][0]['value'] ? $user->cls_mcl_security_question['und'][0]['value'] : "";
  
  $security_answer = isset($user->cls_mcl_security_answer) && $user->cls_mcl_security_answer && isset($user->cls_mcl_security_answer['und']) && $user->cls_mcl_security_answer['und'] && isset($user->cls_mcl_security_answer['und'][0]) && $user->cls_mcl_security_answer['und'][0] && isset($user->cls_mcl_security_answer['und'][0]['value']) && $user->cls_mcl_security_answer['und'][0]['value'] ? $user->cls_mcl_security_answer['und'][0]['value'] : "";

?>

<div class="content">
<!--
  <div id="cls-mcl-account-settings-serverside-errors" class="error serverside-error" style="display: block;">
    <?php echo (isset($_SESSION['messages']['error'][0])) ? $_SESSION['messages']['error'][0] : "" ?>
  </div>
-->
  <h2>Account Settings</h2>
  
  <h3>General</h3>

  <div class="mcl-account-settings-field-labels account-settings-column left-column">
    <p class="label">Account Owner</p>
    <p class="label">Account Type</p>
    <p class="label">Username</p>
  </div>
  
  <div class="mcl-account-settings-account-fields account-settings-column right-column">
    <p class="account-field">
      <?php echo $first_name; ?>
      <?php echo $middle_name; ?>
      <?php echo $last_name; ?>
    </p>
    <p class="account-field">
      <?php echo $account_type; ?>
    </p>
    <p class="account-field"><?php echo $user->name; ?></p>
  </div>
  
  <div class="divider">
  </div>
  
  <h3>Email</h3>
  
  <div class="mcl-account-settings-field-labels account-settings-column left-column">
    <p class="label">Email Addresses</p>
    <p class="label">Email Subscriptions</p>
  </div>
  
  <div class="mcl-account-settings-account-fields account-settings-column right-column">
    <p class="account-field">
      <?php echo $user->mail; ?><br /><!-- Add more email addresses -->
    </p>
    <p class="account-field">
      <?php
        echo "Official Columbia Law School correspondence, account and transaction<br /> notifications, reminders, receipts and confirmations.<br />Announcements, news and events for admitted students &nbsp;&nbsp;<a>Unsubscribe</a><br /><i>Columbia Law School magazine</i> new issue reminders &nbsp;&nbsp;<a>Subscribe</a>"; 
      ?>
    </p>
  </div>
  
  <div class="divider">
  </div> 
  
  <h3>Password Security and Account Recovery</h3>
  
  <div class="mcl-account-settings-field-labels account-settings-column left-column">
    <p class="label">Password</p>
    <p class="label">Security Question</p><br /><br /><br /><br />
    <p class="label">Security Notifications</p>
  </div>
  
  <div class="mcl-account-settings-account-fields account-settings-column right-column">
    <p class="account-field">
      <a href="<?php echo $base_url."/".$path; ?>/password">Change password</a>
    </p>
    <p class="account-field">
      <?php echo $security_question; ?><br />
      <?php echo $security_answer ? "<i>- Answer on file -</i>" : ""; ?>
      <br /><br />
      <a href="<?php echo $base_path."/".$path; ?>/security-question">Change security question and answer</a>
    </p>
    <p class="account-field">
      Yes, please send me an email to my primary email address<br />
      each time my account's security settings change.<br /><br />
      <a href="<?php echo $base_url; ?>">Turn off security notification emails</a>
    </p>
  </div>
  
  <div class="divider">
  </div>      
      
</div>

<script type="text/javascript">
<!--//--><![CDATA[//><!--
//--><!]]>
</script>