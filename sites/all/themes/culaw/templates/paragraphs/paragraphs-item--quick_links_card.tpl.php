<?php

if (isset($content['field_headline'])) {
    $headline = $content['field_headline'];
}
//dpm($content);

if (isset($content['field_navigation_links']['#items'])) : ?>
    <div class="button-list-wrap">
        <div class="container">
            <?php if (isset($headline)) : ?>
                <h2><?php print $headline; ?></h2>
            <?php endif; ?>
            <ul class="button-list list-unstyled">
                <?php foreach($content['field_navigation_links']['#items'] as $key => $value) : ?>
                    <?php
                    $target = (isset($value['attributes']['target'])) ? $value['attributes']['target'] : '_self';
                    ?>
                    <li><a href="<?php print $value['url']; ?>" target="<?php print $target; ?>"><?php print $value['title']; ?></a><i class="icon-keyboard_arrow_right"></i></a></li>
                <?php endforeach; ?>
            </ul>
        </div>
    </div>

<?php endif; ?>