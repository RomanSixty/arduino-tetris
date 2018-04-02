void keys() {
  if ( millis() - last_interaction < 200 )
    return false;

  int keypress = analogRead(SWITCH);

  if ( keypress > 1020 ) {
    Serial.println(F("LEFT"));
    move_tetromino_right();
  }
  else if ( keypress > 990 ) {
    Serial.println(F("DOWN"));
    move_tetromino_down();
  }
  else if ( keypress > 680 ) {
    Serial.println(F("RIGHT"));
    move_tetromino_left();
  }
  else if ( keypress > 490 ) {
    Serial.println(F("UP"));
    rotate_tetromino();
  }

  if ( keypress > 490 ) {
    last_interaction = millis();

    if ( game_over ) {
      game_over = false;
      reset();
    }
  }
}

