void pir() {

  pir_value = digitalRead(PIR);
  if (pir_value == HIGH ) {
    digitalWrite(out3, HIGH);  // turn LED ON
    //   Serial.println("Motion detected!");
    room_state = 1 ;

  } else {
    digitalWrite(out3, LOW); // turn LED OFF
    //Serial.println("Motion ended!");
    room_state = 0;
  }
}



void wc() {

  if (wc_state == 1) {
    digitalWrite(out1, HIGH);
  } else {
    digitalWrite(out1, LOW);
  }
}


void bed() {

  if (bed_state == 1) {
    digitalWrite(out2, HIGH);
  } else {
    digitalWrite(out2, LOW);
  }
}
