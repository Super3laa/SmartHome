void dht11(){
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print("\tTemperature: ");
  Serial.print(t);
  Serial.print("°C ");
  }
