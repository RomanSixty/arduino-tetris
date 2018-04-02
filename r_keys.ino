void keys() {
  if ( millis() - last_interaction < 200 )
    return;

  int keypress = analogRead(SWITCH);

  if ( keypress > 1020 ) {
    move_tetromino_right();
  }
  else if ( keypress > 990 ) {
    move_tetromino_down();
  }
  else if ( keypress > 680 ) {
    move_tetromino_left();
  }
  else if ( keypress > 490 ) {
    rotate_tetromino();
  }

  if ( keypress > 490 ) {
    if ( key_pressed )
      last_interaction = millis() - 150;
    else
      last_interaction = millis();

    key_pressed = true;

    if ( game_over ) {
      game_over = false;
      reset();
    }
  }
  else {
    key_pressed = false;
    last_interaction = 0;
  }
}

