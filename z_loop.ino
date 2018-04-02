void loop() {
  keys();

  if ( !game_over && millis() > next_tick ) {
    next_tick += tick_length;

    move_tetromino_down();
  }
}
