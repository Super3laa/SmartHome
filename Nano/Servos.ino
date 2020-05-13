void gate(int gate_state) {

  int pos;
  if (gate_state == 1) {
    for (pos = 0; pos <= 180; pos += 1) {
      D.write(pos);
    }
  } else {
    for (pos = 180; pos >= 0; pos -= 1) {
      D.write(pos);
    }
    delay(15);

  }

  }

  void Curtains(int curt_state) {

  int pos;
  if (curt_state == 1) {
    for (pos = 0; pos <= 180; pos += 1) {
      C.write(pos);
    }
  } else {
    for (pos = 180; pos >= 0; pos -= 1) {
      C.write(pos);
    }
    delay(15);

  }

  }


   void Garage(int car_state) {

  int pos;
  if (car_state == 1) {
    for (pos = 0; pos <= 180; pos += 1) {
      G.write(pos);
    }
  } else {
    for (pos = 180; pos >= 0; pos -= 1) {
      G.write(pos);
    }
    delay(15);

  }

  }


  
