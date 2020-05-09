void tempHum() {
  server.on("/TH", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send_P(200, "text/plain", HT.c_str());
  });
}
void  securityInfo() {
  server.on("/SecurityInfo", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send_P(200, "text/plain", SecurityInfo.c_str());
  });
}
void  UpdateStatus() {
  server.on("/Status", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send_P(200, "text/plain", Status.c_str());
  });
}
