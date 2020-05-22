void security (bool sec_state ) {
  int prox_value = digitalRead(proximity);
  //  Serial.print(sec_state);
  //  Serial.print("\t");
  //  Serial.println(prox_value);
  if ( (prox_value == 1) & (sec_state == 1) ) {
    tone(Buzzer, 1000);


  } else {
    tone(Buzzer, 10000);
  }

}


void Garage(int car_state) {

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
