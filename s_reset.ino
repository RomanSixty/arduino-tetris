void reset() {
  Serial.print(F("Reset: "));
  Serial.println(freeRam());
  
  // empty bucket
  matrix.fillRect(2, 5, 10, 17, BLACK);

  // empty preview box
  matrix.fillRect(21, 4, 4, 4, BLACK);

  // reset scores
  levels = 0;
  lines  = 0;
  points = 0;

  LXLedPanelNumbers_write(levels, SCORE_LEVELS);
  LXLedPanelNumbers_write(lines,  SCORE_LINES);
  LXLedPanelNumbers_write(points, SCORE_POINTS);
}
