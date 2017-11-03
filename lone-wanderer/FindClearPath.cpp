#include <Arduino.h>

#include "FindClearPath.h"

FindClearPath::FindClearPath(Sonar &sonar, Servo &sonarServo)
: _sonar(sonar),
  _sonarServo(sonarServo)
{}

float FindClearPath::calculateAngle()
{
  float distances[180];
  int pos;
  _sonarServo.attach(10);
  for (pos = 90; pos > 0; pos -= 1) {  
    // in steps of 1 degree
    _sonarServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 0; pos < 180; pos += 1) { // goes from 180 degrees to 0 degrees
    _sonarServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
    distances[pos] = _sonar.getDistanceInCm();    
  }
  for (pos = 179; pos >= 90; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    _sonarServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  _sonarServo.detach();

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

  float nominalAngle = asRadiant( angleOfLargestDistance - 90.0 );
  Serial.print("FindClearPath nominalAngle=");
  Serial.print(nominalAngle);
  Serial.println("rad");
  
/*    Serial.print("GoToGoal distanceMap=[");
    for(pos = 0; pos < 180; pos++){
      Serial.print(distances[pos]);
      Serial.print(",");
    }
    Serial.println("]");
*/

  return nominalAngle;  
}


float FindClearPath::asRadiant(float degrees){
  return degrees*PI/180.0;
}
