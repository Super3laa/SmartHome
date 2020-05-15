void pir(bool room_state) {

  pir_value = digitalRead(PIR);
  if (pir_value == 1 & room_state ==1) {
    digitalWrite(OUT1,!digitalRead(PIR));  
       Serial.println("Motion detected!");
    

  } else {
    digitalWrite(OUT1, LOW); // turn LED OFF
    Serial.println("Motion ended!");
    
  }
}
