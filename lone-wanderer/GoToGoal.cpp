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
  float distances[180];
  int pos;
  sonarServo.attach(10);
  for (pos = 90; pos > 0; pos -= 1) {  
    // in steps of 1 degree
    sonarServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 0; pos < 180; pos += 1) { // goes from 180 degrees to 0 degrees
    sonarServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
    distances[pos] = sonar.getDistanceInCm();    
  }
  for (pos = 179; pos >= 90; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    sonarServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  //sonarServo.detach();

  float epsilon = 0.1;
  float d;
  float largestDistance = 0.0;
  int angleOfLargestDistance = 0;
  for(pos = 0; pos < 180; pos++){
    d = distances[pos];
    if(d > largestDistance){
      largestDistance = d;
      angleOfLargestDistance = pos;
    }
  }

  nominalAngle = asRadiant( angleOfLargestDistance );
  Serial.print("GoToGoal nominalAngle=");
  Serial.print(nominalAngle);
  Serial.println("rad");
  Serial.println(angleOfLargestDistance);
  
    Serial.print("GoToGoal distanceMap=[");
    for(pos = 0; pos < 180; pos++){
      Serial.print(distances[pos]);
      Serial.print(",");
    }
    Serial.println("]");

  //sonarServo.attach(10);
    sonarServo.write(angleOfLargestDistance);
    delay(250);
  sonarServo.detach();
}

float GoToGoal::asRadiant(float degrees){
  return degrees*PI/180.0;
}

