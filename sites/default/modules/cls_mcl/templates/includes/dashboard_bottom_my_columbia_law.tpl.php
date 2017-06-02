<div class="events-area">
  <h3>Upcoming events near you</h3>
  <?php if ($show_upcoming_events_view): ?>
    <?php echo views_embed_view('cls_mcl_dashboard_events', 'default', $events_postal_code_proximity); ?>
  <?php else: ?>
    <p style="font-size: 14px;">Our Admissions Officers may be coming to a campus or conference near you. Visit <a href="/admissions/jd/visit/on-the-road">Columbia on the Road</a> to find out more.</p>
  <?php endif; ?>
</div>
