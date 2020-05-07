#include <ESPAsyncWebServer.h>
#include <FS.h> 
AsyncWebServer server(80);

void setup() {
  pinMode(2, OUTPUT);
  Serial.begin(115200);
  Serial.setTimeout(3);
  SoftAPInit();
  handleRoutes();
  SPIFFS.begin();
  handleRoutes();
  server.begin();
  Serial.println("All is Good...");
}
  
void loop() { 
 
}
