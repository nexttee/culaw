<ul>
  <li <?php if ($request_path == 'courses') { ?> class="active"<?php } ?>><a href="/courses">Home</a></li>
  <li <?php if (strpos($request_path, 'courses/search') !== FALSE) { ?> class="active"<?php } ?> ><a href="/courses/search">Search</a></li>
</ul>
