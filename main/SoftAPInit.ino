void SoftAPInit() {
  Serial.print("");
  Serial.print("Setting soft-AP configuration ... ");
  Serial.print(WiFi.config(local_IP, gateway, subnet) ? "Ready" : "Failed!");
  Serial.print("Setting soft-AP ... ");
  Serial.print(WiFi.begin(ssid, password) ? "Ready" : "Failed!");
  Serial.print("AP IP address = ");
  Serial.print(WiFi.localIP());
}
