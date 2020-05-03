#include<ESP8266WiFi.h>
#include <ESP8266WebServer.h>


const char *ssid = "Esp-01"; // The name of the Wi-Fi network that will be created
const char *password = "*smarthome*";

IPAddress local_IP(192, 168, 1, 7);

IPAddress gateway(192, 168, 1, 1);

IPAddress subnet(255, 255, 255, 0);

ESP8266WebServer server(80);

// Writing a simple HTML page.
char HTML[] = "<html><body><h1>Inovo Smart Home</h1><h2>Created by Alolo & Alaa</h2><button><a href=\"toggle\">Toggle LED</a></button> </body></html>"; // --> Simple HTML page

void setup() {
  pinMode(2, OUTPUT);
  Serial.begin(115200);
  Serial.println();

  Serial.print("Setting soft-AP configuration ... ");

  Serial.println(WiFi.softAPConfig(local_IP, gateway, subnet) ? "Ready" : "Failed!");

  Serial.print("Setting soft-AP ... ");

  Serial.println(WiFi.softAP(ssid, password) ? "Ready" : "Failed!");

  Serial.print("Soft-AP IP address = ");

  Serial.println(WiFi.softAPIP());

  server.on("/", handleRoot);
  server.on("/toggle",toggle);
  server.begin();
  Serial.println("HTTP server started");
}
  
// the loop function runs over and over again forever
void loop() {
  server.handleClient();
}
void toggle()
{
  digitalWrite(LED_BUILTIN,!digitalRead(LED_BUILTIN));
  server.send(200, "text/html",HTML);
}
void handleRoot() {
  server.send(200, "text/html",HTML);
}
