void SoftAPInit() {
  Serial.print("");
  Serial.print("Setting soft-AP configuration ... ");
  Serial.print(WiFi.softAPConfig(local_IP, gateway, subnet) ? "Ready" : "Failed!");
  Serial.print("Setting soft-AP ... ");
  Serial.print(WiFi.softAP(ssid, password) ? "Ready" : "Failed!");
  Serial.print("AP IP address = ");
  Serial.print(WiFi.softAPIP());
}
