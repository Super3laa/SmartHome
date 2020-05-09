#include <Servo.h>

Servo GD, ED, HD;
GD.attach(3);
ED.attach(10);
HD.attach(11);

String data = "";
void setup() {
  // put your setup code here, to run once:
  pinMode(5, INPUT_PULLUP);
  Serial.begin(115200);
  Serial.setTimeout(3);

}

void loop() {
  data = Serial.readString();
  if (data == "GD") {
   
  } else if {

} else if {

} else if {

} else if {

} else if {

} else if {

} else if {

} else if {

} else if {

} else if {

} else if {

} else if {

} else if {

} else if {

} else if {

} else if {

}
}
