#include<ESP8266WiFi.h>
#include <ESP8266WebServer.h>


const char *ssid = "SmartHome"; // The name of the Wi-Fi network that will be created
const char *password = "11011SmartHome";
IPAddress local_IP(192, 168, 1, 6);

IPAddress gateway(192, 168, 1, 1);

IPAddress subnet(255, 255, 255, 0);

ESP8266WebServer server(80);
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

  server.on("/", HTTP_GET,handleRoot);
  server.on("/LED", HTTP_POST,toggleLED);
  server.begin();

}
  
// the loop function runs over and over again forever
void loop() {
  server.handleClient();
}
void toggleLED(){
  Serial.print("ToggleLed");
  server.sendHeader("Location","/");
  server.send(303);  
}
void handleRoot() {
  server.send(200,"text/html","<form action=\"/LED\" method=\"POST\"><input type=\"submit\" value=\"Toggle LED\"></form>");
}
