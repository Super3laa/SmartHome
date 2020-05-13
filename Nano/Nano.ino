
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
  D.attach(3);
  G.attach(10);
  C.attach(11);

}

void loop() {


  if (Serial.available() > 0) {
    data = Serial.readString();
    //!data.equals("")
    if (!data.equals("Security")) {
      sec_state = !sec_state;
    } else if (!data.equals("Gate")) {
      gate_state = !gate_state ;
      gate(gate_state);
    } else if (!data.equals("Garage")) {
      car_state = !car_state ;
      Garage(car_state);
    } else if (!data.equals("Curtains")) {
      curt_state = !curt_state ;
      Curtains(curt_state);
    } else if (!data.equals("BedRoom")) {
      bed_state = !bed_state ;
      bed(bed_state);
    } else if (!data.equals("Bathroom")) {
      wc_state = !wc_state ;
      wc(wc_state);
    } else if (!data.equals("RLight")) {
      pir();
    } else if (!data.equals("RFan")) {
      fan_state = !fan_state ;
    } else if (!data.equals( "Kitchen")) {
      gas();
    }
    Serial.println(data);
  }
  
  security(sec_state);
 // dht11(fan_state);
}
