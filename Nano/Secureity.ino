void security () {
  int prox_value = digitalRead(proximity);
  if ((prox_value == 1) and (sec_state == 1) ) {
    digitalWrite(Buzzer, HIGH);
    digitalWrite(9, HIGH);
  } else {
    digitalWrite(Buzzer, LOW);
    digitalWrite(9, LOW);
  }
}


void Garage() {
  int pos;
  if (car_state == 1) {
    for (pos = 0; pos <= 120; pos += 1) {
      G.write(pos);
      delay(25);
    }
  } else {
    for (pos = 120; pos >= 0; pos -= 1) {
      G.write(pos);
      delay(25);
    }
  }
}
