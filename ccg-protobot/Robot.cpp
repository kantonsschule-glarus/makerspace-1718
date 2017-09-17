#include "Arduino.h"
#include "Robot.h"

Robot::Robot(Drive &theDrive)
: drive(theDrive)
{;}

void Robot::setUp(){
  drive.setUp();
}
  
void Robot::forward(){
  Serial.println("Es funkioniert also das forward ;)");
  drive.forward();
}
void Robot::backward(){
  Serial.println("Es funkioniert also das backward ;)");
  drive.backward();
}
void Robot::stop(){
  Serial.println("Es funkioniert also das stoppen ;)");
  drive.stop();
}
