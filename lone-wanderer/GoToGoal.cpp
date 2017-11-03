#include <Arduino.h>
#include "GoToGoal.h"

GoToGoal::GoToGoal(Sonar &s, Servo &sServo)
: nominalAngle(0.0),
  actualAngle(0.0),
  pidController(),
  sonar(s),
  sonarServo(sServo)
{
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
}

GoToGoal::~GoToGoal(){;}

float GoToGoal::calculateAngle(){
  float actualValue = nominalAngle; // TODO set measured angle
  float error = actualValue - nominalAngle;
  float newNominalValue = pidController.calculateAngle(error);
  //Serial.print("newNominalValue: ");
  //Serial.println(newNominalValue);
  return newNominalValue;
}

void GoToGoal::behave()
{
  
}


