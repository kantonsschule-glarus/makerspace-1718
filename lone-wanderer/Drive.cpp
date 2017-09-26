#include "Arduino.h"
#include <Adafruit_MotorShield.h>

#include "Drive.h"

Drive::Drive(Adafruit_MotorShield &theAFMS)
: AFMS(theAFMS)
{
  leftMotor = AFMS.getMotor(1);  
  rightMotor = AFMS.getMotor(2);
}

void Drive::startDrive(){
  AFMS.begin();
  
  leftMotor->run(RELEASE);
  rightMotor->run(RELEASE);
  
}

void Drive::forward(){
  Serial.println("forward");
  
  leftMotor->run(FORWARD);
  rightMotor->run(FORWARD);
  
  leftMotor->setSpeed(150);
  rightMotor->setSpeed(150);
}

void Drive::backward(){
  Serial.println("backward");
  
  leftMotor->run(BACKWARD);
  rightMotor->run(BACKWARD);
  
  leftMotor->setSpeed(150);
  rightMotor->setSpeed(150);
}

void Drive::left(){
  Serial.println("left");
  
  leftMotor->run(BACKWARD);
  rightMotor->run(FORWARD);
  
  leftMotor->setSpeed(150);
  rightMotor->setSpeed(150);
}

void Drive::right(){
  Serial.println("right");
  
  leftMotor->run(FORWARD);
  rightMotor->run(BACKWARD);

  leftMotor->setSpeed(150);
  rightMotor->setSpeed(150);
}

void Drive::stop(){
  Serial.println("stop");
  
  leftMotor->run(RELEASE);
  rightMotor->run(RELEASE);

  leftMotor->setSpeed(150);
  rightMotor->setSpeed(150);
}
