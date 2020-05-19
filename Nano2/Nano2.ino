
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

bool fan_state  = 0 ;
int  M1speed    = 70;
int  M2speed    = 70;
int  M3speed    = 70;
int  M4speed    = 70;
int t, h;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(3);

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
    } else if (NanoData == "RFan") {
      Fan();
    } else if (NanoData == "Elevator") {
      Elevator();
    }  else if (NanoData == "Curtains") {
      Curtains();
    } else if (NanoData.substring(0, 1) == "T") {
      t = (NanoData.substring(1)).toInt();
    } else if (NanoData.substring(0, 1) == "H") {
      h = (NanoData.substring(1)).toInt();
    }
  }
}


void Gate() {
  digitalWrite(Ain1, !digitalRead(Ain1));
  digitalWrite(Ain2, !digitalRead(Ain2));
  analogWrite(AEnA, M1speed);
  delay(750);
}

void Elevator() {
  digitalWrite(Bin3, !digitalRead(Bin3));
  digitalWrite(Bin4, !digitalRead(Bin4));
  analogWrite(BEnB, M4speed);
  delay(750);

}
void Curtains() {
  digitalWrite(Ain3, !digitalRead(Ain3));
  digitalWrite(Ain4, !digitalRead(Ain4));
  analogWrite(AEnB, M2speed);
  delay(750);
}

//void Fan() {
//  fan_state = !fan_state;
//  if (fan_state == 1) {
//    digitalWrite(Bin1, HIGH);
//    digitalWrite(Bin2, LOW);
//    if (t > 23 & t < 27) {
//      analogWrite(BEnA, 150);
//    } else if (t > 27) {
//      analogWrite(BEnA, 255);
//    }
//  } else {
//    digitalWrite(Bin1, LOW);
//    digitalWrite(Bin2, LOW);
//  }
//}

void Fan() {
  fan_state = !fan_state;
  if (fan_state == 1) {
    //digitalWrite(A0, 1);
    digitalWrite(13, 1);
  } else {
    //digitalWrite(A0, 0);
    digitalWrite(13, 0);
  }
}
