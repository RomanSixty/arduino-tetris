void loop() {
  Serial.print(F("Loop: "));
  Serial.println(freeRam());
  
  if ( keys() ) {
    get_tetromino();
    drop_tetromino();
  }

  delay(1000);
}
