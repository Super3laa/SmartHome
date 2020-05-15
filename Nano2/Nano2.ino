#include <SoftwareSerial.h>

#define Ain1  7
#define Ain2  5
#define Ain3  4
#define Ain4  2
#define AEnA  6
#define AEnB  3

#define Bin1  12
#define Bin2  13
#define Bin3  10
#define Bin4  8
#define BEnA  11
#define BEnB  9

int M1speed = 70;
int M2speed = 70;
int M3speed = 70;
int M4speed = 70;


SoftwareSerial Nano(A3, A2); // RX, TX

void setup() {
  Serial.setTimeout(2);
  Serial.begin(9600);
  Nano.setTimeout(3);
  Nano.begin(57600);
  pinMode(Ain1, OUTPUT);
  pinMode(Ain2, OUTPUT);
  pinMode(Ain3, OUTPUT);
  pinMode(Ain4, OUTPUT);
  pinMode(AEnA, OUTPUT);
  pinMode(AEnB, OUTPUT);
  pinMode(Bin1, OUTPUT);
  pinMode(Bin2, OUTPUT);
  pinMode(Bin3, OUTPUT);
  pinMode(Bin4, OUTPUT);
  pinMode(BEnA, OUTPUT);
  pinMode(BEnB, OUTPUT);

  digitalWrite(Ain1, 0);
  digitalWrite(Ain2, 1);
  digitalWrite(Ain3, 0);
  digitalWrite(Ain4, 1);

  digitalWrite(Bin1, 0);
  digitalWrite(Bin2, 1);
  digitalWrite(Bin3, 0);
  digitalWrite(Bin4, 1);
}

void loop() {

  if (Serial.available() ) {
    String NanoData = Serial.readString();
    if (NanoData == "Gate") {
      Gate();
    } else if (NanoData == "Garage") {
      Garage();
    } else if (NanoData == "Elevator") {
      Elevator();
    }  else if (NanoData == "Curtains") {
      Curtains();
    }

  }
}


void Gate() {
  digitalWrite(Ain1, !digitalRead(Ain1));
  digitalWrite(Ain2, !digitalRead(Ain2));
  analogWrite(AEnA, M1speed);

}

void Curtains() {
  digitalWrite(Ain3, !digitalRead(Ain3));
  digitalWrite(Ain4, !digitalRead(Ain4));
  analogWrite(AEnB, M2speed);

}

void Garage() {
  digitalWrite(Bin1, !digitalRead(Bin1));
  digitalWrite(Bin2, !digitalRead(Bin2));
  analogWrite(BEnA, M3speed);
}

void Elevator() {
  digitalWrite(Bin3, !digitalRead(Bin3));
  digitalWrite(Bin4, !digitalRead(Bin4));
  analogWrite(BEnB, M4speed);

}
