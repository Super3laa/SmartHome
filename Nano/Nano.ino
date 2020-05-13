
#include <Servo.h>
#include "DHT.h"

#define DHTTYPE DHT11
#define DHTPIN A2
#define proximity A1
#define Buzzer 13
#define PIR A3
#define GAS A0
#define out1 4
#define out2 5
#define out3 6
#define out4 7
#define out5 8
#define FAN  9

DHT dht(DHTPIN, DHTTYPE);

Servo D, G, C;

String data = "";
bool sec_state  = 0; //securetiy off
bool gate_state = 0; //gate closed
bool curt_state = 0; //Curtains closed
bool car_state  = 0; //Garage closed
bool bed_state  = 0; //Bedroom dark
bool wc_state   = 0; //Bathroom dark
bool room_state = 0; //Room dark
bool fan_state  = 0; //fan off
bool gas_state  = 0; //gas stable
int pir_value   = 0;
int gas_lvl     = 0;
void setup() {
  Serial.begin(115200);
  Serial.setTimeout(2);

  pinMode(proximity, INPUT);
  pinMode(PIR, INPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(out1, OUTPUT);
  pinMode(out2, OUTPUT);
  pinMode(out3, OUTPUT);
  pinMode(out4, OUTPUT);
  pinMode(out5, OUTPUT);

  dht.begin();

  G.attach(3);
  C.attach(10);

}

void loop() {


  if (Serial.available() > 0) {
    data = Serial.readString();
    if (data == "Security") {
      sec_state = !sec_state;
    } else if (data == "Gate") {
      gate_state = !gate_state ;
      gate(gate_state);
    } else if (data == "Garage") {
      car_state = !car_state ;
      Garage(car_state);
    } else if (data == "Curtains") {
      Curt_state = !Curt_state ;
      Curtains(curt_state);
    } else if (data == "BedRoom") {
      bed_state = !bed_state ;
      bed(bed_state);
    } else if (data == "Bathroom") {
      wc_state = !wc_state ;
      wc(wc_state);
    } else if (data == "RLight") {
      pir();
    } else if (data == "RFan") {
      fan_state = !fan_state ;
      fan(fan_state);
    } else if (data == "Kitchen") {

      gas();
    }
  }
  security(sec_state);
}
