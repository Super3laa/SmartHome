
void Open_door(String servo) {

  int pos;
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    if (servo == "GD") {
      GD.write(pos);
    } else if (servo == "ED") {
      ED.write(pos);
    } else if (servo == "GD") {
      GD.write(pos);
    }              // tell servo to go to position in variable 'pos'
    delay(350);                       // waits 15ms for the servo to reach the position
  }
}

void Close_door(String servo) {
  int pos;
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    if (servo == "GD") {
      GD.write(pos);
    } else if (servo == "ED") {
      ED.write(pos);
    } else if (servo == "GD") {
      GD.write(pos);
    }             // tell servo to go to position in variable 'pos'
    delay(350);                       // waits 15ms for the servo to reach the position
  }
}
