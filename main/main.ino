#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <SoftwareSerial.h>

SoftwareSerial EspSerial(2, 3); // RX, TX

const char *ssid       = "Esp-01"; // The name of the Wi-Fi network that will be created
const char *password   = "*smarthome*";

IPAddress local_IP(192, 168, 1, 17);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

ESP8266WebServer server(80);
// Writing a simple HTML page.
char HTML[] = "<html><body><h1>Inovo Smart Home</h1><h2>Created by Alolo & Alaa</h2><button action=\"/LED\">Toggle LED</button> </body></html>";

void setup() {
  pinMode(2, OUTPUT);
  Serial.begin(115200);
  Serial.setTimeout(3);
  SoftAPInit();
  handleRoutes();
  server.begin();
  Serial.println("HTTP server started");
}
  
// the loop function runs over and over again forever
void loop() {
  server.handleClient();
  if(Serial.available()){
    Serial.println(Serial.readString());
  }
}
