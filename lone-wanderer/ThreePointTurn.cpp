#include <Arduino.h>

#include "ThreePointTurn.h"

ThreePointTurn::ThreePointTurn(Drive &drive)
: _drive(drive)
{;}

float ThreePointTurn::calculateAngle(){
  return 0.0;
}

void ThreePointTurn::act(){
    Serial.print("ThreePointTurn act ...");
    _drive.stop();
    _drive.right();
    _drive.backward();
    delay(500);
    _drive.spinRight();
    delay(400);
    _drive.stop();
    Serial.println("ThreePointTurn act done");
}

