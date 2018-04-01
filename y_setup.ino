void setup() {
  pinMode(SWITCH, INPUT);
  Serial.begin(9600);
  
  Serial.print(F("Setup: "));
  Serial.println(freeRam());
  
  matrix.begin();

  // draw the basic game setup

  matrix.fillScreen(BLACK);

  // bucket
  matrix.drawLine(1, 5, 1, 22, GRAY);
  matrix.drawLine(12, 5, 12, 22, GRAY);
  matrix.drawLine(2, 22, 11, 22, GRAY);

  // preview box for next item
  matrix.drawLine(20, 3, 25, 3, GRAY);
  matrix.drawLine(20, 8, 25, 8, GRAY);
  matrix.drawLine(20, 4, 20, 7, GRAY);
  matrix.drawLine(25, 4, 25, 7, GRAY);

  // lv (= level)
  matrix.drawLine(14, 10, 14, 15, GRAY);
  matrix.drawLine(16, 12, 16, 15, GRAY);
  matrix.drawLine(18, 12, 18, 13, GRAY);
  matrix.drawPixel(17, 14, GRAY);

  // ln (= lines)
  matrix.drawLine(14, 17, 14, 22, GRAY);
  matrix.drawLine(16, 19, 16, 22, GRAY);
  matrix.drawLine(18, 20, 18, 22, GRAY);
  matrix.drawPixel(17, 19, GRAY);

  // pt (= points)
  matrix.drawLine(1, 25, 1, 29, GRAY);
  matrix.drawPixel(2, 25, GRAY);
  matrix.drawLine(2, 27, 3, 26, GRAY);
  matrix.drawLine(5, 25, 5, 28, GRAY);
  matrix.drawPixel(6, 26, GRAY);
  matrix.drawPixel(6, 29, GRAY);

  // initialize scores etc.
  reset();

  get_tetromino();
  drop_tetromino();
}
