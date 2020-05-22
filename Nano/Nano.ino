#include <Servo.h>
#include <SoftwareSerial.h>
#include <SimpleDHT.h>

#define DHTPIN A2
#define proximity A1
#define Buzzer 13
#define PIR A3
#define GAS A0
#define OUT1 4
#define OUT2 5
#define OUT3 6
#define OUT4 7
#define OUT5 8


SoftwareSerial Nano(A4, A5); // RX, TX

SimpleDHT11 dht11(DHTPIN);

Servo G;

bool sec_state   = 0; //securetiy off
bool gate_state  = 0; //gate closed
bool curt_state  = 0; //Curtains closed
bool car_state   = 0; //Garage closed
bool sound_state = 0;
bool last_sound  = 0;
int pir_value    = 0;
int gas_lvl      = 0;

void setup() {
  Serial.begin(115200);
  Nano.begin(9600);
  Serial.setTimeout(3);

  pinMode(proximity, INPUT);
  pinMode(PIR, INPUT);
  pinMode(GAS, INPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(OUT1, OUTPUT);
  pinMode(OUT2, OUTPUT);
  pinMode(OUT3, OUTPUT);
  pinMode(OUT4, OUTPUT);
  pinMode(OUT5, OUTPUT);


  G.attach(3);
  G.write(0);

}

void loop() {


  if (Serial.available()) {
    String data = Serial.readString();
    //!data.equals("")
    if (data == ("Security")) {
      sec_state = !sec_state;
    } else if (data == ("Gate")) {
      Nano.print("Gate");
    } else if (data == ( "Garage")) {
      car_state = !car_state;
      Garage(car_state);
    } else if (data == ("Elevator")) {
      Nano.print("Elevator");
    } else if (data == ("Curtains")) {
      Nano.print("Curtains");
    } else if (data == ("RFan")) {
      Nano.print("RFan");
    } else if (data == ( "GLights")) {
      digitalWrite(OUT1, !digitalRead(OUT1));

    } else if (data == ("Bathroom")) {
      digitalWrite(OUT2, !digitalRead(OUT2));

    } else if (data == ("RLight")) {
      digitalWrite(OUT3, !digitalRead(OUT3));

    }  else if (data == ( "Kitchen") ) {
      digitalWrite(OUT4, !digitalRead(OUT4));

    }  else if (data == ( "BedRoom") ) {
      digitalWrite(OUT5, !digitalRead(OUT5));
    }
  }
  dht();
  gas();
  security (sec_state );
}
