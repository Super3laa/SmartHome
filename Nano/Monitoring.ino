void dht11(bool fan_state) {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  Serial.print("H" + String(h));
  Serial.print("T" + String(t));

  if (fan_state == 1) {
    if (t >= 23) {
      analogWrite(FAN, 127);
    } else if (t >= 23) {
      analogWrite(FAN, 255);
    }

  } else {
    analogWrite(FAN, 0);
  }

}


void gas() {

  gas_lvl = (analogRead(GAS));
  gas_lvl = map(gas_lvl, 0, 1023, 0, 255);

  if (gas_lvl > 20 && gas_lvl <= 30) { //gaslevel is greater than 20 and less than 30
    Serial.print("G1");
  }
  else
  {
    Serial.print("G0");
  }

}
