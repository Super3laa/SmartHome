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
