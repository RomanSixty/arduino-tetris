void start() {
  levels = 0;
  lines  = 0;
  points = 0;

  LXLedPanelNumbers::write(levels, SCORE_LEVELS);
  LXLedPanelNumbers::write(lines,  SCORE_LINES);
  LXLedPanelNumbers::write(points, SCORE_POINTS);
}
