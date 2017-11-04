#include <Arduino.h>
#include "AvoidObstacle.h"

AvoidObstacle::AvoidObstacle(Distance &distance)
: _distance(distance)
{;}

AvoidObstacle::~AvoidObstacle(){;}

float AvoidObstacle::calculateAngle(){
  float currentDistance = _distance.getDistanceInMeter();
  Serial.print("AvoidObstacle currentDistance=");
  Serial.print(currentDistance);
  Serial.println("m");
  if(currentDistance >= 0.9){
    return 0.0;
  }
  if(currentDistance >= 0.8){
    return 0.3 * -PI;
  }
  if(currentDistance >= 0.7){
    return  0.6 * -PI;
  }
  if(currentDistance >= 0.5){
    return 0.833333 * -PI;
  }
  if(currentDistance > -0.1){
    return -PI;
  }
  return 0.0;
}


