#include <Arduino.h>
#include <Adafruit_MotorShield.h>

#include "Drive.h"

Drive::Drive(Adafruit_MotorShield &theAFMS)
: AFMS(theAFMS)
{
  leftMotor = AFMS.getMotor(1);  
  rightMotor = AFMS.getMotor(2);   
}

void Drive::setUp(){
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  
  AFMS.begin();

  leftMotor->setSpeed(150);
  rightMotor->setSpeed(150);
}

void Drive::forward(){
  Serial.println("Drive forward ;)");
  leftMotor->run(FORWARD);
}
void Drive::backward(){
   Serial.println("Drive backward ;)");
   leftMotor->run(BACKWARD);
}
void Drive::stop(){
   Serial.println("Drive stop ;)");
   leftMotor->run(RELEASE);
}
