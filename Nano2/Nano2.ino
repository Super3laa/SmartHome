#define Ain1  7
#define Ain2  5
#define Ain3  4
#define Ain4  2
#define Gate_pin  6
#define Elev_pin  3

#define Bin1  12
#define Bin2  13
#define Bin3  10
#define Bin4  8
#define Fan_pin  11
#define Curt_pin  9

#define SW1  A1
#define SW2  A2
#define SW3  A3
#define SW4  A4

bool fan_state  = 0 ;
int  Gate_speed    = 150;
int  Elev_speed    = 70;
int  Curt_speed    = 200;
int  Fan_speed    = 100;

bool G_sw1 = 0;
bool G_sw2 = 0;

bool E_sw1 = 0;
bool E_sw2 = 0;

int t, h;

int Flag_G = 0;
int Flag_E = 0;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(3);

  pinMode(Ain1, OUTPUT);
  pinMode(Ain2, OUTPUT);
  pinMode(Ain3, OUTPUT);
  pinMode(Ain4, OUTPUT);
  pinMode(Gate_pin, OUTPUT);
  pinMode(Elev_pin, OUTPUT);
  pinMode(Bin1, OUTPUT);
  pinMode(Bin2, OUTPUT);
  pinMode(Bin3, OUTPUT);
  pinMode(Bin4, OUTPUT);
  pinMode(Fan_pin, OUTPUT);
  pinMode(Curt_pin, OUTPUT);

  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
  pinMode(SW3, INPUT_PULLUP);
  pinMode(SW4, INPUT_PULLUP);

  digitalWrite(Bin1, 0);
  digitalWrite(Bin2, 1);
  pinMode(A0,OUTPUT);

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
    } else if (NanoData == "Curtains") {
      Curtains();
    }
  }
  if (Flag_G) {
    G_sw1 = digitalRead(SW1);
    G_sw2 = digitalRead(SW2);
    if (G_sw1 == 0 || G_sw2 == 0) {
      analogWrite(Gate_pin, 0 );
      Flag_G = 0;
    }
  }
  if (Flag_E) {
    E_sw1 = digitalRead(SW3);
    E_sw2 = digitalRead(SW4);
    if (E_sw1 == 0 || E_sw2 == 0) {
      analogWrite(Elev_pin, 0 );
      Flag_E = 0;
    }
  }
}
void Gate() {
  G_sw1 = digitalRead(SW1);
  G_sw2 = digitalRead(SW2);
  if (G_sw1 == 0 and G_sw2 == 1) {
    digitalWrite(Ain1, 1);
    digitalWrite(Ain2, 0);
    analogWrite(Gate_pin, Gate_speed);
  } else if (G_sw1 == 1 and G_sw2 == 0) {
    digitalWrite(Ain1, 0);
    digitalWrite(Ain2, 1);
    analogWrite(Gate_pin, Gate_speed);
  }
  Flag_G = 1;
}

void Elevator() {
  E_sw1 = digitalRead(SW3);
  E_sw2 = digitalRead(SW4);
  if (E_sw1 == 0 and E_sw2 == 1) {
    digitalWrite(Ain3, 1);
    digitalWrite(Ain4, 0);
    analogWrite(Elev_pin, Gate_speed);

  } else if (E_sw1 == 1 and E_sw2 == 0) {
    digitalWrite(Ain3, 0);
    digitalWrite(Ain4, 1);
    analogWrite(Elev_pin, Gate_speed);

  }
  Flag_G = 1;
}
void Curtains() {
  digitalWrite(Bin1, !digitalRead(Bin1));
  digitalWrite(Bin2, !digitalRead(Bin2));
  analogWrite(Curt_pin , Curt_speed);
  delay(750);
}

void Fan() {
  fan_state = !fan_state;
  if (fan_state == 1) {
    digitalWrite(Bin3, 0);
    digitalWrite(Bin4, 1);
    analogWrite(Fan_pin, Fan_speed);
  } else {
    analogWrite(Fan_pin, 0);
  }
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

//void sound (){
//  sound_state = digitalRead(SOUND);
//
//  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
//  if (sound_state ==HIGH && last_sound == LOW ) {
//
//     digitalWrite(SOUND, !digitalRead(SOUND));
//  }
//
// last_sound = sound_state;
//
//  }
