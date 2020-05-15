void dht(bool fan_state) {
  byte t = 0;
  byte h = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&t, &h, NULL)) != SimpleDHTErrSuccess) {
    //Serial.print("Read DHT11 failed, err="); Serial.println(err);
    delay(1000);
    return;
  }


  Serial.print("T"); Serial.print((int)t);
  Serial.print("H"); Serial.print((int)h);

  if (fan_state == 1) {
    if (int(t) >= 23) {
      analogWrite(FAN, 127);
    } else if (int(t) >= 23) {
      analogWrite(FAN, 255);
    }

  } else {
    analogWrite(FAN, 0);
  }

}


void gas() {

  gas_lvl = (analogRead(GAS));
  gas_lvl = map(gas_lvl, 0, 1023, 0, 255);

  if (gas_lvl > 70 ) { //gaslevel is greater than 20 and less than 30
    Serial.print("G1");
  }
  else
  {
    Serial.print("G0");
  }

}
