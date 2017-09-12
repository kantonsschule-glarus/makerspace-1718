#include "Arduino.h"
#include "Robot.h"
#include "Drive.h"

Robot::Robot()
: awakeIndicatorPin(13),
  drive()
{
  pinMode(awakeIndicatorPin, OUTPUT);
}

void Robot::wakeUp(){ 
  Serial.println("Robot waking up..."); 
  digitalWrite(awakeIndicatorPin, HIGH);
  drive.forward();
  delay(25);
  drive.backward();
  delay(25);
  Serial.println("Robot awake"); 
}

void Robot::check(){
  Serial.println("Robot check sensors and save data");
}

void Robot::behave(){
  Serial.println("Robot read data and behave normal");
}

