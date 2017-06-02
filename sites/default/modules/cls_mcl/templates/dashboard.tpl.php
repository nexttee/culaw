<?php
/**
 *  @TODO Add logic to the views for different instances,
 *    or create separate views
 */
?>
<div class="content">
  <div class="mcl-login-success-column">
    <h1><?php echo $title; ?></h1>
    <?php echo theme('cls_mcl_dashboard_top_' . $instance_id, array('instance_path' => $instance_path)); ?>
    <div class="my-courses-section">
      <div id="my-courses-tabs" class="mcl-tabs">
      	<ul>
      		<?php if ($interest_area_views_argument != ''): ?>
      		  <li><a href="#tab-courses">My Courses</a></li>
      		<?php else: ?>
      		  <li><a href="#tab-courses">Selected Courses</a></li>
      		<?php endif; ?>
      		<li class="tab-btn-custom"><a href="<?php echo $courses_custom_link_1_path; ?>" target="_blank"><?php echo $courses_custom_link_1_title ?></a></li>
      		<li class="tab-btn-custom"><a href="<?php echo $courses_custom_link_2_path ?>" target="_blank"><?php echo $courses_custom_link_2_title ?></a></li>
      	</ul>
      	<div id="tab-courses">
          <?php if (isset($interest_area_courses)): ?>
            <div class="view view-cls-mcl-dashboard-courses">
              <div class="view-content">
                <div class="mcl-interest-jcarousel jcarousel-skin-default">
                  <ul>
                    <?php foreach($interest_area_courses as $course): ?>
                      <li>
                        <div class="views-field views-field-name">
                          <a href="/courses/<?php print $course['course_number']; ?>" target="_blank"><?php print $course['name']; ?></a>
                        </div>
                        <div class="views-field views-field-faculty">
                          <?php if(isset($course['instructors'])): ?>
                            <?php print $course['instructors']; ?>
                          <?php endif; ?>
                        </div>
                        <!-- <div class="views-field views-field-offering-description"></div> -->
                      </li>
                    <?php endforeach; ?>
                  </ul>
                </div>
              </div>
            </div>
          <?php endif; ?>
      	</div>
      </div>
    </div>
    <div class="my-faculty-section">
      <div id="my-faculty-tabs" class="mcl-tabs">
      	<ul>
      		<?php if ($interest_area_views_argument != ''): ?>
      		  <li><a href="#tab-faculty">My Faculty</a></li>
      	 <?php else: ?>
      	   <li><a href="#tab-faculty">Selected Faculty</a></li>
      	 <?php endif; ?>
      		<li class="tab-btn-custom"><a href="<?php echo $faculty_custom_link_1_path ?>" target="_blank"><?php echo $faculty_custom_link_1_title ?></a></li>
      	</ul>
      	<div id="tab-faculty">
          <?php if (isset($interest_area_faculty)): ?>
            <div class="view view-cls-mcl-dashboard-faculty-all">
              <div class="view-content">
                <div class="mcl-interest-jcarousel-faculty jcarousel-skin-default">
                  <ul>
                    <?php foreach($interest_area_faculty as $profile): ?>
                      <li>
                        <?php if(isset($profile['photo_url'])): ?>
                          <div class="views-field views-field-image">
                            <a href="<?php print $profile['path']; ?>" target="_blank"><img src="<?php print image_style_url('cls_mcl_interest_faculty_thumb', $profile['photo_url']); ?>" width="68" height="91" /></a>
                          </div>
                        <?php endif; ?>
                        <div class="views-field views-field-nothing-2">
                          <a href="<?php print $profile['path']; ?>" target="_blank"><?php print $profile['name']; ?></a>
                        </div>
                        <div class="views-field views-field-title"><?php print $profile['title']; ?></div>
                        <div class="views-field views-field-nothing">
                          <a href="<?php print $profile['path']; ?>" target="_blank">View profile and courses</a>
                        </div>
                      </li>
                    <?php endforeach; ?>
                  </ul>
                </div>
              </div>
            </div>
          <?php endif; ?>
      	</div>
      </div>
    </div>
    <div class="my-other-areas-section">
      <div id="my-other-areas-tabs" class="mcl-tabs">
      	<ul>
      		<li><a href="#tab-centers-and-programs">Centers and Programs</a></li>
      		<li><a href="#tab-journals">Journals</a></li>
      		<li><a href="#tab-students-organizations">Student Organizations</a></li>
      	</ul>
      	<div id="tab-centers-and-programs">
          <?php echo views_embed_view('cls_mcl_dashboard_centers', 'default'); ?>
      	</div>
      	<div id="tab-journals">
          <?php echo views_embed_view('cls_mcl_dashboard_journals', 'default'); ?>
      	</div>
      	<div id="tab-students-organizations">
          <?php echo views_embed_view('cls_mcl_dashboard_student_organizations', 'default'); ?>
      	</div>
      </div>
    </div>
    <h3 style="font-weight: normal;">Not what you wanted? <a href="<?php echo base_path() . $instance_path; ?>/update-my-profile#interests">Update your interests</a>.</h3>
    <hr />
    <div class="buttons-area">
      <div class="clearfix">
        <div style="float:left; width: 210px; margin-right:35px;">
          <div class="dashboard-button"><a href="<?php echo $viewbook_path; ?>" class="white" target="_blank"><span class="header"><?php echo $viewbook_title; ?></span> <span class="description"></span> </a></div>
        </div>
        <div style="float:left; width: 210px; margin-right:35px;">
          <div class="dashboard-button">
            <?php if ($account_in_current_admissions_cycle): ?>
              <?php if ($account_application_found): ?>
                <a href="<?php echo $status_checker_path; ?>" class="blue" target="_blank"><span class="header">Check Your Application Status</span><span class="description"></span></a>
              <?php else: ?>
                <a href="<?php echo $apply_path; ?>" class="blue" target="_blank"><span class="header">Apply</span> <span class="description"></span></a>
              <?php endif; ?>
            <?php else: ?>
              <?php if ($instance_id == 'my_columbia_law'): ?>
                <a href="<?php echo $visit_path; ?>" class="blue" target="_blank"><span class="header">Visit the<br />Law School</span> <span class="description"></span></a>
              <?php else: ?>
                  <a href="<?php echo $apply_path; ?>" class="blue" target="_blank"><span class="header">Apply</span> <span class="description"></span></a>
              <?php endif; ?>
            <?php endif; ?>
          </div>
        </div>
        <div style="float:left; width: 210px; margin-right:0;">
          <div class="dashboard-button">
            <a href="<?php echo $tour_path; ?>" class="white"><span class="header"><?php echo $tour_title; ?></span> <span class="description"></span></a>
          </div>
        </div>
      </div>
    </div>
    <hr />
    <?php echo theme('cls_mcl_dashboard_bottom_' . $instance_id, array('show_upcoming_events_view' => $show_upcoming_events_view, 'events_postal_code_proximity' => $events_postal_code_proximity, 'instance_path' => $instance_path)); ?>
  </div>
</div>
