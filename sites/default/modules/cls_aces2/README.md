Roadmap
-------
Useful features to add or enhance:

- NOW: Synchronize and store recommenders data locally once the Oracle table contains a last modified date

- NOW: Integrate with Entity cache (https://drupal.org/project/entitycache) to allow native Drupal caching

- NOW: Copy Drupal 8's PHPTransliteration and add transliterated first, middle, last name properties to the applicant class

- NOW: Add method on the sync controller to allow an on-demand sync per applicant

- NOW: Add utility method to the applicant controller to execute an on-demand sync to retrieve the applicant's latest data

- NEAR TERM: Add utility method to applicant controller to return application notifications and exclusions if the related class exists

- NEAR TERM: Add utility method to applicant controller to return the applicant's MailChimp membership lists, profile data, and activity (sent, open, click, bounce, unsubscribe request, abuse report)

- NEAR TERM: Add utility method to applicant controller to return possibly-related MailChimp list memberships

- NEAR TERM: Add method to applicant controller to return linked MCL accounts

- NEAR TERM: Add method to applicant controller to return possibly-related MCL accounts

- NEAR TERM: Add function(s) to use entity field query to help match unlinked applicants, MailChimp list members, and MCL accounts

- NEAR TERM: Add graceful degradation in case Oracle is unreachable

- NEAR TERM: Integration with relation module

- NOW: Integration with eck module to allow for permissioning

- NOW: Add revisioning and remove "previous_" properties