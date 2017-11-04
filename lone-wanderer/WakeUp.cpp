#include <Arduino.h>

#include "WakeUp.h"

WakeUp::WakeUp(Drive &drive, Light &fl, Light &fr, Light &rl, Light &rr)
: _drive(drive),
  _fl(fl),
  _fr(fr),
  _rl(rl),
  _rr(rr)
{;}

float WakeUp::calculateAngle(){
  return 0.0;
}

void WakeUp::act()
{
  Serial.println("WakeUp ..."); 
  digitalWrite(13, HIGH);

  _fl.on();
  _fr.on();
  _rl.on();
  _rr.on();

  _drive.spinLeft();
  delay(2000);
  _drive.stop();
  delay(200);
  _drive.spinRight();
  delay(2000);
  _drive.forward();
  _drive.stop();
  Serial.println("WakeUp done");
}


