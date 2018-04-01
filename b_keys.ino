bool keys() {
  int keypress = analogRead(SWITCH);
  //int keypress = 1020;

  if ( keypress > 1020 ) {
    Serial.println("LEFT");
  }
  else if ( keypress > 990 ) {
    Serial.println("UP");
  }
  else if ( keypress > 680 ) {
    Serial.println("RIGHT");
  }
  else if ( keypress > 490 ) {
    Serial.println("DOWN");
  }

  if ( keypress > 490 ) {
    delay(2000);
    return true;
  }
  else
    return false;
}

