const char *ssid       = "SmartHome"; 
const char *password   = "*2222060*";

IPAddress local_IP(192, 168, 1, 17);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

void SoftAPInit(){
  Serial.println("");
  Serial.print("Setting soft-AP configuration ... ");
  Serial.println(WiFi.softAPConfig(local_IP, gateway, subnet) ? "Ready" : "Failed!");
  Serial.print("Setting soft-AP ... ");
  Serial.println(WiFi.softAP(ssid, password) ? "Ready" : "Failed!");
  Serial.print("AP IP address = ");
  Serial.println(WiFi.softAPIP());

}
