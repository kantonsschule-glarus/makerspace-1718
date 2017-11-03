#include <Arduino.h>
#include "AvoidObstacle.h"

AvoidObstacle::AvoidObstacle(Distance &distance)
: _distance(distance)
{;}

AvoidObstacle::~AvoidObstacle(){;}

float AvoidObstacle::calculateAngle(){
  int currentDistance = _distance.getDistanceInCm();
  Serial.print("AvoidObstacle currentDistance=");
  Serial.print(currentDistance);
  Serial.println("cm");
  if(currentDistance >= 90){
    return 0.0;
  }
  if(currentDistance >= 80){
    return 0.3 * -PI;
  }
  if(currentDistance >= 70){
    return  0.6 * -PI;
  }
  if(currentDistance >= 50){
    return 0.833333 * -PI;
  }
  if(currentDistance > -100){
    return -PI;
  }
  return 0.0;
  
  /*
  switch(currentZone){
      case Distance::danger:
        return PI;
      case Distance::attention:
        return PI/2.0;
      case Distance::clear:
      default:
        return 0.0;
    }
    */
}


