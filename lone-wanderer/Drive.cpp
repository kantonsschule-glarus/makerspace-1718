#include "Arduino.h"
#include "Drive.h"

Drive::Drive(){}

void Drive::forward(){
  Serial.println("forward");
}

void Drive::backward(){
  Serial.println("backward");
}

void Drive::rotate(){
  Serial.println("rotate");
}

void Drive::stop(){
  Serial.println("stop");
}
