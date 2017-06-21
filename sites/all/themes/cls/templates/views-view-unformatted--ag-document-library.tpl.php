<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php foreach ($rows as $id => $row): ?>
  <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
    <?php   
      if (isset($_GET['search_api_views_fulltext'])) {
        $text = $_GET['search_api_views_fulltext'];
        
        preg_match('/<a href="(.*?)">(.*?)<\/a>/', $row, $matches);
        // If the search term is successfully found in the link, let's color it red.
        if (!empty($matches)) {
          $url = $matches[1];
          $url_text = $matches[2];

          $replacement_find = $text;
          $replacement_replace = "<strong style='color:red;padding:2px;'>" . $replacement_find . "</strong>";

          $red_url_text = str_ireplace($replacement_find, $replacement_replace, $url_text);
          $row = str_replace($url_text, $red_url_text, $row);
        }
      }

      print $row;
    ?>
  </div>
<?php endforeach; ?>
