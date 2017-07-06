   jQuery(document).ready(function($) {
		var sfcontainer = $(".social-feed-container");
		
		var tw_query = sfcontainer.attr("data-tw_query");
		var tw_limit = sfcontainer.attr("data-tw_limit");
		var tw_key = sfcontainer.attr("data-tw_key");
		var tw_secret = sfcontainer.attr("data-tw_secret");
		
		var ig_query = sfcontainer.attr("data-ig_query");
		var ig_limit = sfcontainer.attr("data-ig_limit");
		var ig_client = sfcontainer.attr("data-ig_client");
		var ig_token = sfcontainer.attr("data-ig_token");
		
		var fb_query = sfcontainer.attr("data-fb_query");
		var fb_limit = sfcontainer.attr("data-fb_limit");
		var fb_token = sfcontainer.attr("data-fb_token");

		
        var updateFeed = function() {
            $('.social-feed-container').socialfeed({
				// Twitter
				twitter: {
					accounts: tw_query.replace(' ', '').split(','),
					limit: tw_limit,
					consumer_key: tw_key, // make sure to have your app read-only
					consumer_secret: tw_secret, // make sure to have your app read-only
				},
				// INSTAGRAM
				instagram: {
					accounts: ig_query.replace(' ', '').split(','),
					limit: ig_limit,
					client_id: ig_client,
					access_token: ig_token
				},
				// FACEBOOK
				facebook: {
					accounts: fb_query.replace(' ', '').split(','),
					limit: fb_limit,
					access_token: fb_token
				},

					

                // GENERAL SETTINGS
                length: 200,
                show_media: true,
                template : "/sites/all/themes/culaw/js/jquery.socialfeed/template.html",
                // Moderation function - if returns false, template will have class hidden
                moderation: function(content) {
                    return (content.text) ? content.text.indexOf('porn') == -1 : true;
                },
                //update_period: 5000,
                // When all the posts are collected and displayed - this function is evoked
                callback: function() {
                    console.log('all posts are collected');

                    jQuery('.social-feed-container').each( function() {
                        var $this = jQuery(this);
                        var elems = $this.children('.social-feed-element');

                        elems.sort(function() { return (Math.round(Math.random())-0.5); });  

                        $this.detach('.social-feed-element');  

                        for(var i=0; i < elems.length; i++)
                            $this.append(elems[i]);
                        
                        console.log(elems);
                    });
                }
            });
        };

        updateFeed();
       

    });
   