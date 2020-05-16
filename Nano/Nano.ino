
#include <Servo.h>
#include <SoftwareSerial.h>
#include <SimpleDHT.h>

#define DHTPIN A2
#define proximity A0
#define Buzzer 13
#define PIR A3
#define GAS A0
#define OUT1 4
#define OUT2 5
#define OUT3 6
#define OUT4 7
#define OUT5 8
#define FAN  9

SoftwareSerial Nano(A4, A5); // RX, TX

SimpleDHT11 dht11(DHTPIN);

Servo D, G, C;

bool sec_state  = 0; //securetiy off
bool gate_state = 0; //gate closed
bool curt_state = 0; //Curtains closed
bool car_state  = 0; //Garage closed
bool room_state = 0; //PIR disabled
bool fan_state  = 0; //fan off
int pir_value   = 0;
int gas_lvl     = 0;

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(3);

  pinMode(proximity, INPUT);
  pinMode(PIR, INPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(OUT1, OUTPUT);
  pinMode(OUT2, OUTPUT);
  pinMode(OUT3, OUTPUT);
  pinMode(OUT4, OUTPUT);
  pinMode(OUT5, OUTPUT);
  pinMode(FAN, OUTPUT);



}

void loop() {


  if (Serial.available()) {
    String data = Serial.readString();
    //!data.equals("")
    if (data == "BedRoom") {
      room_state = !room_state;
      pir(room_state);
    } else if (data == ("Security")) {
      sec_state = !sec_state;
      security (sec_state );
    } else if (data == ("Gate")) {
      Nano.print("Gate");
    } else if (data == ( "Garage")) {
      Nano.print("Garage");
    } else if (data == ("Elevator")) {
      Nano.print("Elevator");
    } else if (data == ("Curtains")) {
      Nano.print("Curtains");
    } else if (data == ("RFan")) {
      fan_state = !fan_state;
    } else if (data == ("Bathroom")) {
      digitalWrite(OUT2, !digitalRead(OUT2));

    } else if (data == ("RLight")) {
      digitalWrite(OUT3, !digitalRead(OUT3));

    }  else if (data == ( "Kitchen") ) {
      digitalWrite(OUT4, !digitalRead(OUT4));

    } else if (data == ( "GLights")) {
      digitalWrite(OUT5, !digitalRead(OUT5));

    }

  }
  dht(fan_state);
  security (sec_state );
}
