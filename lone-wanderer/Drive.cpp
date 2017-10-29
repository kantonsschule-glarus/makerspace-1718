#include "Arduino.h"
#include <Adafruit_MotorShield.h>

#include "Drive.h"

Drive::Drive(float wheelDistance, 
             float wheelRadius, 
             Adafruit_MotorShield &theAFMS)
: 
velocity(100.0),
maxVelocity(125),
velocityLeftMotor(0),
velocityRightMotor(0),
omega(0.0),
L(wheelDistance),
R(wheelRadius),
AFMS(theAFMS)
{
  leftMotor = AFMS.getMotor(1);  
  rightMotor = AFMS.getMotor(2);
}

void Drive::setUp(){
  Serial.println("Drive setUp ...");

  AFMS.begin();

  applyMotorVelocities();

  leftMotor->run(RELEASE);
  rightMotor->run(RELEASE);

  Serial.println("Drive setUp done");
}

void Drive::forward(){
  Serial.println("Drive forward");
  omega = 0.0;
  applyMotorVelocities();
  leftMotor->run(FORWARD);
  rightMotor->run(FORWARD);
}

void Drive::backward(){
  Serial.println("Drive backward");
  omega = 0.0;
  leftMotor->run(BACKWARD);
  rightMotor->run(BACKWARD);
}

void Drive::left(){
  Serial.println("Drive left");
  omega = -150.0;
  applyMotorVelocities();
}

void Drive::right(){
  Serial.println("Drive right");
  omega = 150.0;
  applyMotorVelocities();
}

void Drive::spinLeft(){
  leftMotor->run(BACKWARD);
  rightMotor->run(FORWARD);  
}
void Drive::spinRight(){
  leftMotor->run(FORWARD);
  rightMotor->run(BACKWARD);  
}

void Drive::stop(){
  Serial.println("Drive stop");
  leftMotor->run(RELEASE);
  rightMotor->run(RELEASE);
}

void Drive::setVelocity(int value){
  velocity = value;
  applyMotorVelocities();
}

void Drive::applyMotorVelocities(){
  calculateVelocityRightMotor();
  calculateVelocityLeftMotor();
    
  leftMotor->setSpeed(mapVelocityToPwm(velocityLeftMotor));
  rightMotor->setSpeed(mapVelocityToPwm(velocityRightMotor));
}

void Drive::calculateVelocityRightMotor(){
  velocityRightMotor = (2.0 * velocity + asRadiant(omega) * L)/(2.0 * R);
  Serial.print("Drive velocityRightMotor=");
  Serial.println(velocityRightMotor);
}

void Drive::calculateVelocityLeftMotor(){
  velocityLeftMotor = (2.0 * velocity - asRadiant(omega) * L)/(2.0 * R);
  Serial.print("Drive velocityLeftMotor=");
  Serial.println(velocityLeftMotor);
}

float Drive::asRadiant(float degrees){
  return degrees*PI/180.0;
}

int Drive::mapVelocityToPwm(float v){
  int vv = (int)v;
  return map(v, 0, 42, 0, maxVelocity);
}
