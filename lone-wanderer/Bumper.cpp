#include "Arduino.h"
#include "Bumper.h"

Bumper::Bumper(int pin)
: _pin(pin)
{
  pinMode(_pin, INPUT);
}

boolean Bumper::isPressed(){
  boolean result = digitalRead(_pin) == HIGH;
  /*Serial.print("Bumper on pin ");
  Serial.print(_pin);
  Serial.print(" is ");
  Serial.println(result);*/
  return result;
}

