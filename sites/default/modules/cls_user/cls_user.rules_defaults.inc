<?php
/**
 * @file
 * cls_user.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function cls_user_default_rules_configuration() {
  $items = array();
  $items['rules_faculty_user_url_alias'] = entity_import('rules_config', '{ "rules_faculty_user_url_alias" : {
      "LABEL" : "Faculty User URL Alias",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "path" ],
      "ON" : { "user_update" : [], "user_insert" : [] },
      "IF" : [
        { "user_has_role" : { "account" : [ "account" ], "roles" : { "value" : { "229" : "229" } } } }
      ],
      "DO" : [
        { "path_alias" : {
            "source" : "user\\/[account:uid]",
            "alias" : "faculty\\/[account:cls-user-first-name]-[account:cls-user-last-name]"
          }
        }
      ]
    }
  }');
  return $items;
}
