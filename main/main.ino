#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <FS.h>
#include <WebSocketsServer.h>

//SoftwareSerial EspSerial(2, 3); // RX, TX

const char *ssid       = "Esp-01"; // The name of the Wi-Fi network that will be created
const char *password   = "*smarthome*";
const char *myssid     = "E.A";
const char *mypassword = "4208694*";
const char *AP_IP = "192.168.1.17";
const char* mdnsName = "esp"; // Domain name for the mDNS responder
//IPAddress local_IP(192, 168, 1, 17);
//IPAddress gateway(192, 168, 1, 1);
//IPAddress subnet(255, 255, 255, 0);

ESP8266WebServer server(80);

void setup() {
  pinMode(2,OUTPUT);
  Serial.begin(115200);        // Start the Serial communication to send messages to the computer
  delay(10);
  Serial.println("\r\n");

  startWiFi();                 // Start a Wi-Fi access point, and try to connect to some given access points. Then wait for either an AP or STA connection

  // startOTA();                  // Start the OTA service

  startSPIFFS();               // Start the SPIFFS and list all contents

  startWebSocket();            // Start a WebSocket server

  startMDNS();                 // Start the mDNS responder

  startServer();               // Start a HTTP server with a file read handler and an upload handler

}




void loop() {
  webSocket.loop();
  server.handleClient();
}




//void startOTA() {}






  
//void startSPIFFS{  // Start the SPIFFS and list all contents
//  SPIFFS.begin();                             // Start the SPI Flash File System (SPIFFS)
//  Serial.println("SPIFFS started. Contents:");
//  {
//    Dir dir = SPIFFS.openDir("/");
//    while (dir.next()) {                      // List the file system contents
//      String fileName = dir.fileName();
//      size_t fileSize = dir.fileSize();
//      Serial.printf("\tFS File: %s, size: %s\r\n", fileName.c_str(), formatBytes(fileSize).c_str());
//    }
//    Serial.printf("\n");
//  }
//  }
//bool handleFileRead(String path) { // send the right file to the client (if it exists)
//  Serial.println("handleFileRead: " + path);
//  if (path.endsWith("/")) path += "index.html";          // If a folder is requested, send the index file
//  String contentType = getContentType(path);             // Get the MIME type
//  String pathWithGz = path + ".gz";
//  if (SPIFFS.exists(pathWithGz) || SPIFFS.exists(path)) { // If the file exists, either as a compressed archive, or normal
//    if (SPIFFS.exists(pathWithGz))                         // If there's a compressed version available
//      path += ".gz";                                         // Use the compressed verion
//    File file = SPIFFS.open(path, "r");                    // Open the file
//    size_t sent = server.streamFile(file, contentType);    // Send it to the client
//    file.close();                                          // Close the file again
//    Serial.println(String("\tSent file: ") + path);
//    return true;
//  }
//  Serial.println(String("\tFile Not Found: ") + path);   // If the file doesn't exist, return false
//  return false;
//}
//
//void handleFileUpload(){ // upload a new file to the SPIFFS
//  HTTPUpload& upload = server.upload();
//  String path;
//  if(upload.status == UPLOAD_FILE_START){
//    path = upload.filename;
//    if(!path.startsWith("/")) path = "/"+path;
//    if(!path.endsWith(".gz")) {                          // The file server always prefers a compressed version of a file 
//      String pathWithGz = path+".gz";                    // So if an uploaded file is not compressed, the existing compressed
//      if(SPIFFS.exists(pathWithGz))                      // version of that file must be deleted (if it exists)
//         SPIFFS.remove(pathWithGz);
//    }
//    Serial.print("handleFileUpload Name: "); Serial.println(path);
//    fsUploadFile = SPIFFS.open(path, "w");            // Open the file for writing in SPIFFS (create if it doesn't exist)
//    path = String();
//  } else if(upload.status == UPLOAD_FILE_WRITE){
//    if(fsUploadFile)
//      fsUploadFile.write(upload.buf, upload.currentSize); // Write the received bytes to the file
//  } else if(upload.status == UPLOAD_FILE_END){
//    if(fsUploadFile) {                                    // If the file was successfully created
//      fsUploadFile.close();                               // Close the file again
//      Serial.print("handleFileUpload Size: "); Serial.println(upload.totalSize);
//      server.sendHeader("Location","/success.html");      // Redirect the client to the success page
//      server.send(303);
//    } else {
//      server.send(500, "text/plain", "500: couldn't create file");
//    }
//  }
//}



void startWebSocket{
  webSocket.begin();                          // start the websocket server
  webSocket.onEvent(webSocketEvent);          // if there's an incomming websocket message, go to function 'webSocketEvent'
  Serial.println("WebSocket server started.");
  }


  
void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t lenght) { // When a WebSocket message is received
  switch (type) {
    case WStype_DISCONNECTED:             // if the websocket is disconnected
      Serial.printf("[%u] Disconnected!\n", num);
      break;
    case WStype_CONNECTED: {              // if a new websocket connection is established
        IPAddress ip = webSocket.remoteIP(num);
        Serial.printf("[%u] Connected from %d.%d.%d.%d url: %s\n", num, ip[0], ip[1], ip[2], ip[3], payload);
        rainbow = false;                  // Turn rainbow off when a new connection is established
      }
      break;
    case WStype_TEXT:                     // if new text data is received
      Serial.printf("[%u] get Text: %s\n", num, payload);
      if (payload[0] == '#') {            // we get RGB data
        uint32_t rgb = (uint32_t) strtol((const char *) &payload[1], NULL, 16);   // decode rgb data
        int r = ((rgb >> 20) & 0x3FF);                     // 10 bits per color, so R: bits 20-29
        int g = ((rgb >> 10) & 0x3FF);                     // G: bits 10-19
        int b =          rgb & 0x3FF;                      // B: bits  0-9

        analogWrite(LED_RED,   r);                         // write it to the LED output pins
        analogWrite(LED_GREEN, g);
        analogWrite(LED_BLUE,  b);
      } else if (payload[0] == 'R') {                      // the browser sends an R when the rainbow effect is enabled
        rainbow = true;
      } else if (payload[0] == 'N') {                      // the browser sends an N when the rainbow effect is disabled
        rainbow = false;
      }
      break;
  }
}
