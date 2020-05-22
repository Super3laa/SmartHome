void dht() {
  byte t      = 0;
  byte h      = 0;
  byte last_t = 0;
  byte last_h = 0;
  int err = SimpleDHTErrSuccess;

  if ((err = dht11.read(&t, &h, NULL)) != SimpleDHTErrSuccess) {
    //Serial.print("Read DHT11 failed, err="); Serial.println(err);
    delay(1000);
    return;
  }

  if (last_t != t) {
    Serial.print("T"); Serial.print((int)t);
    Nano.print("T"); Nano.print(String((int)t));
  }
  if (last_h != h) {
    Serial.print("H"); Serial.print((int)h);
    Nano.print("H"); Nano.print(String((int)h));
  }
  last_t = t;
  last_h = h;
}


void gas() {

  gas_lvl = (analogRead(GAS));
  gas_lvl = map(gas_lvl, 0, 1023, 0, 255);

  if (gas_lvl > 70 ) {
    Serial.print("G1");
    digitalWrite(Buzzer,HIGH);
  }
  else
  {
    Serial.print("G0");
    digitalWrite(Buzzer,LOW);
    }

}
