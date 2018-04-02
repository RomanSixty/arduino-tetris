void reset() {
  Serial.print(F("Reset: "));
  Serial.println(freeRam());

  tick_length = 1000;
  
  // empty bucket
  matrix.fillRect(2, 5, 10, 17, BLACK);

  // note: the top of the bucket corresponds to the floor on the panel
  // so it's upside down
  for ( byte i = 0; i < 17; i++ )
    bucket[i] = 0b100000000001;

  // reset scores
  levels = 1;
  lines  = 0;
  points = 0;

  LXLedPanelNumbers_write(levels, SCORE_LEVELS);
  LXLedPanelNumbers_write(lines,  SCORE_LINES);
  LXLedPanelNumbers_write(points, SCORE_POINTS);
}
