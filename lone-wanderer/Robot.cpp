#include "Arduino.h"
#include "Robot.h"

Robot::Robot(Drive &theDrive)
: drive(theDrive)
{;}

void Robot::setUp(){
  drive.setUp();
}

void Robot::wakeUp(){ 
  Serial.println("Robot wakeup ..."); 
  digitalWrite(awakeIndicatorPin, HIGH);
  drive.forward();
  delay(25);
  drive.backward();
  delay(25);
  Serial.println("Robot wakeup done"); 
}

void Robot::forward(){
  Serial.println("Robot forward");
  drive.forward();
}

void Robot::backward(){
  Serial.println("Robot backward");
  drive.backward();
}

void Robot::left(){
  Serial.println("Robot left");
  drive.left();
}

void Robot::right(){
  Serial.println("Robot right");
  drive.right();
}

void Robot::stop(){
  Serial.println("Robot stop");
  drive.stop();
}

void Robot::check(){
  Serial.println("Robot check sensors and save data");
}

void Robot::behave(){
  Serial.println("Robot read data and behave normal");
}

