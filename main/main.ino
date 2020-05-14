#include <ESPAsyncWebServer.h>
const char *ssid       = "SmartHome";
const char *password   = "*2222060*";
IPAddress local_IP(192, 168, 1, 17);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);
AsyncWebServer server(80);
String HT = "40%27 ";
String SecurityInfo = "100";
String Status = "00000000000";
String html ="<!DOCTYPE html> <html> <head> <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"> <style> html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: left; background:#fafafa; } .wrapper{ display:grid; grid-template-columns: 35fr 35fr 30fr; grid-gap:0.5em } .wrapper>div{ background: #ffffff; } .Security{ grid-row: 1/3; grid-column: 1/4; } .garage{ grid-row: 3/4; grid-column: 1; } .Title{ color: #042352; padding:0.6em; } .bedroom{ grid-row: 3/4; grid-column: 2; } .bathroom{ grid-row: 3/4; grid-column: 3; } .recep{ grid-row: 4/7; grid-column: 1/3; } .kitchen{ grid-row: 4/7; grid-column: 3; } .garden{ grid-row: 7/10; grid-column: 1/4; } .SystemMonitor{ color: #520404; padding:0.6em; } .buttonTitle{ color:#1c283a; } .SystemInfo{ margin-left: 1em; color:#981313; } .ButtonInfo{ display: grid; grid-template-columns: 90fr 10fr; margin-left:1em; } .switch { position: relative; display: inline-block; width: 55px; height: 30px; margin-right: 0.5em; margin-top : 0.5em; } .switch input { opacity: 0; width: 0; height: 0; } .slider { position: absolute; cursor: pointer; top: 0; left: 0; right: 0; bottom: 0; background-color: #ccc; -webkit-transition: .4s; transition: .4s; } .slider:before { position: absolute; content: \"\"; height: 22px; width: 22px; left: 4px; bottom: 4px; background-color: white; -webkit-transition: .4s; transition: .4s; } input:checked + .slider { background-color: #a82020; } input:focus + .slider { box-shadow: 0 0 1px #a82020; } input:checked + .slider:before { -webkit-transform: translateX(26px); -ms-transform: translateX(26px); transform: translateX(26px); } .slider.round { border-radius: 34px; } .slider.round:before { border-radius: 50%; } </style> <script> function updateState(){ var xhttp = new XMLHttpRequest(); xhttp.onreadystatechange = function() { if (this.readyState == 4 && this.status == 200) { var data = this.responseText; var i=0; for( i =0 ; i<11 ; i++){ if (data.substr(i,1) == \"1\"){ document.getElementById(`${i+1}`).checked = true; }else{ document.getElementById(`${i+1}`).checked = false ; } } } }; xhttp.open(\"GET\", \"/Status\", false); xhttp.send(); } </script> </head> <body onload=\"updateState()\"> <div class=\"wrapper\"> <div class=\"box Security\"> <h3 class=\"SystemMonitor\">System Monitor</h3> <div class=\"SystemInfo\"> <div> <p><strong>Tempreature : </strong><strong id = \"Tempreature\">21</strong></p> </div> <div> <p><strong>Humidity : </strong><strong id = \"Humidity\">60</strong></p> </div> <div> <p><strong>Gas : </strong><strong id = \"Gas\">No Gas Leak</strong></p> </div> <div> <p><strong>System Security : </strong><strong id = \"SecurityInfo\">Not Secured</strong></p> </div> </div> <div class = \"ButtonInfo\"> <p class =\"buttonTitle\"><strong>Security System Enable/Diablse</strong></p> <label class=\"switch\"> <input type=\"checkbox\" id='1' onclick='getRequest(\"/Security\")'> <span class=\"slider round\"></span> </label> </div> </div> <div class=\"box garage\"> <h2 class=\"Title\">Garage</h2> <div class = \"ButtonInfo\"> <p class =\"buttonTitle\"><strong>Gate</strong></p> <label class=\"switch\"> <input type=\"checkbox\" id ='2' onclick='getRequest(\"/Garage\")'> <span class=\"slider round\"></span> </label> </div> <div class = \"ButtonInfo\"> <p class =\"buttonTitle\"><strong>Elevator</strong></p> <label class=\"switch\"> <input type=\"checkbox\" id ='11' onclick='getRequest(\"/Elevator\")'> <span class=\"slider round\"></span> </label> </div> </div> <div class=\"box bedroom\"> <h2 class=\"Title\">BedRoom</h2> <div class = \"ButtonInfo\"> <p class =\"buttonTitle\"><strong>Lights</strong></p> <label class=\"switch\"> <input type=\"checkbox\" id ='3'onclick='getRequest(\"/BedRoom\")'> <span class=\"slider round\"></span> </label> </div> </div> <div class=\"box bathroom\"> <h2 class=\"Title\">Bathroom</h2> <div class = \"ButtonInfo\"> <p class =\"buttonTitle\"><strong>Lights</strong></p> <label class=\"switch\"> <input type=\"checkbox\" id ='4' onclick='getRequest(\"/Bathroom\")'> <span class=\"slider round\"></span> </label> </div> </div> <div class=\"box recep\"> <h2 class=\"Title\">Reception</h2> <div class = \"ButtonInfo\"> <p class =\"buttonTitle\"><strong>Lights</strong></p> <label class=\"switch\"> <input type=\"checkbox\" id ='5' onclick='getRequest(\"/RLight\")'> <span class=\"slider round\"></span> </label> </div> <div class = \"ButtonInfo\"> <p class =\"buttonTitle\"><strong>Fan</strong></p> <label class=\"switch\"> <input type=\"checkbox\" id ='6' onclick='getRequest(\"/RFan\")'> <span class=\"slider round\"></span> </label> </div> <div class = \"ButtonInfo\"> <p class =\"buttonTitle\"><strong>Curtains</strong></p> <label class=\"switch\"> <input type=\"checkbox\" id ='7' onclick='getRequest(\"/RCurtains\")'> <span class=\"slider round\"></span> </label> </div> </div> <div class=\"box kitchen\"> <h2 class=\"Title\">Kitchen</h2> <div class = \"ButtonInfo\"> <p class =\"buttonTitle\"><strong>Lights</strong></p> <label class=\"switch\"> <input type=\"checkbox\"id ='8' onclick='getRequest(\"/Kitchen\")'> <span class=\"slider round\"></span> </label> </div> </div> <div class=\"box garden\"> <h2 class=\"Title\">Garden</h2> <div class = \"ButtonInfo\"> <p class =\"buttonTitle\"><strong>Lights</strong></p> <label class=\"switch\"> <input type=\"checkbox\" id ='9' onclick='getRequest(\"/GLights\")'> <span class=\"slider round\"></span> </label> </div> <div class = \"ButtonInfo\"> <p class =\"buttonTitle\"><strong>Gate </strong></p> <label class=\"switch\"> <input type=\"checkbox\" id ='10'onclick='getRequest(\"/Gate\")'> <span class=\"slider round\"></span> </label> </div> </div> </div> <script> function getRequest(data){ var xhttp = new XMLHttpRequest(); xhttp.open(\"GET\",`${data}`,false); xhttp.send(); } </script> </body> <script> setInterval(function ( ) { var xhttp = new XMLHttpRequest(); xhttp.onreadystatechange = function() { if (this.readyState == 4 && this.status == 200) { var data = this.responseText; document.getElementById(\"Humidity\").innerHTML =data.substr(0,3); document.getElementById(\"Tempreature\").innerHTML = data.substr(3,3); } }; xhttp.open(\"GET\", \"/TH\", true); xhttp.send(); }, 20000 ) ; setInterval(function ( ) { var xhttp = new XMLHttpRequest(); xhttp.onreadystatechange = function() { if (this.readyState == 4 && this.status == 200) { var data = this.responseText; if (data.substr(0,1) == \"1\"){ document.getElementById(\"SecurityInfo\").innerHTML = \"NOT SECUERED\"; }else{ document.getElementById(\"SecurityInfo\").innerHTML = \"Secuered\"; } if (data.substr(1,1) == \"1\"){ document.getElementById(\"Gas\").innerHTML = \"Gas LEAK\"; }else{ document.getElementById(\"Gas\").innerHTML = \"No Gas leak\"; } if (data.substr(2,1) == \"1\"){ document.getElementById(\"5\").checked = true; }else{ document.getElementById(\"Gas\").checked = false; } } }; xhttp.open(\"GET\", \"/SecurityInfo\", true); xhttp.send(); }, 1000 ) ; </script> </html>";
void setup() {
  pinMode(2, OUTPUT);
  Serial.begin(115200);
  Serial.setTimeout(3);
  SoftAPInit();
  handleRoutes();
  server.begin();
  Serial.print("All is Good...");
}

void loop() {
  if (Serial.available()) {
    String data = Serial.readString();
    if (data.substring(0, 1) == "H") {
      HT = data.substring(1) + HT.substring(2);
    } else if (data.substring(0, 1) == "T") {
      HT = HT.substring(0, 3) + data.substring(1);
    } else if (data.substring(0, 1) == "P" ) {
      SecurityInfo = SecurityInfo.substring(0, 2) + data.substring(2);
    } else if (data.substring(0, 1) == "G" ) {
      SecurityInfo = SecurityInfo.substring(0, 1) + data.substring(1, 2) + SecurityInfo.substring(2);
    }
  }
}
