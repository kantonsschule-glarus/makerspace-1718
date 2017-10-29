#include "Arduino.h"
#include "Bumper.h"

Bumper::Bumper(int pin)
: _pin(pin)
{
  pinMode(_pin, INPUT);
}

boolean Bumper::isPressed(){
  return digitalRead(_pin) == HIGH;
}

