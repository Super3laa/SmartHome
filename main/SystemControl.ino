void SystemControl()
{
  server.on("/Security", HTTP_GET, [](AsyncWebServerRequest * request) {
    Serial.print("Security");
    toggleString(1);
    toggleSecurity(1);
    request->send(200);
  });
  server.on("/Garage", HTTP_GET, [](AsyncWebServerRequest * request) {
    Serial.print("Garage");
    toggleString(2);
    request->send(200);
  });
  server.on("/BedRoom", HTTP_GET, [](AsyncWebServerRequest * request) {
    Serial.print("BedRoom");
    toggleString(3);
    request->send(200);
  });
  server.on("/Bathroom", HTTP_GET, [](AsyncWebServerRequest * request) {
    Serial.print("Bathroom");
    toggleString(4);
    request->send(200);
  });
  server.on("/RLight", HTTP_GET, [](AsyncWebServerRequest * request) {
    Serial.print("RLight");
    toggleString(5);
    toggleSecurity(3);
    request->send(200);
  });
  server.on("/RFan", HTTP_GET, [](AsyncWebServerRequest * request) {
    Serial.print("RFan");
    toggleString(6);
    request->send(200);
  });
  server.on("/RCurtains", HTTP_GET, [](AsyncWebServerRequest * request) {
    Serial.print("Curtains");
    toggleString(7);
    request->send(200);
  });
  server.on("/Kitchen", HTTP_GET, [](AsyncWebServerRequest * request) {
    Serial.print("Kitchen");
    toggleString(8);
    request->send(200);
  });
  server.on("/GLights", HTTP_GET, [](AsyncWebServerRequest * request) {
    Serial.print("GLights");
    toggleString(9);
    request->send(200);
  });

  server.on("/Gate", HTTP_GET, [](AsyncWebServerRequest * request) {
    Serial.print("Gate");
    toggleString(10);
    request->send(200);
  });
}
