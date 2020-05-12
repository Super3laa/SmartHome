
#include <Servo.h>
#include "DHT.h"

#define DHTTYPE DHT11
#define DHTPIN 2
#define proximity A1
#define Buzzer 13

DHT dht(DHTPIN, DHTTYPE);

Servo G, C;

String data = "";
bool sec_state  = 0; //securetiy off
bool gate_state = 0; //gate closed
bool Curt_state = 0; //Curtains closed

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(2);
  pinMode(proximity, INPUT);
  pinMode(Buzzer, OUTPUT);
  dht.begin();

  G.attach(3);
  C.attach(10);

}

void loop() {


  if (Serial.available() > 0) {
    data = Serial.readString();
    if (data == "Security") {
      sec_state = !sec_state;
    } //else if (data == "Gate") {
    //    gate_state = !gate_state ;
    //    gate(gate_state);
    //  } else if (data == "Curtains") {
    //    Curt_state = !Curt_state ;
    //    Curtains(Curt_state);
    //  }
  }
  security(sec_state);
}
