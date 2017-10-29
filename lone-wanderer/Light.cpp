#include "Arduino.h"
#include "Light.h"

Light::Light(int pin)
: _pin(pin)
{
  pinMode(_pin, OUTPUT);
}

void Light::on(){
  Serial.println("Light on");
  digitalWrite(_pin, HIGH);
}

void Light::off(){
  Serial.println("Light off");
  digitalWrite(_pin, LOW);
}

