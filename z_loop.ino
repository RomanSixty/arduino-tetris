void loop() {
  Serial.print(F("Loop: "));
  Serial.println(freeRam());
  
  if ( keys() ) {

  }

  delay(1000);
}
