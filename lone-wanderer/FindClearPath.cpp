#include "FindClearPath.h"

FindClearPath::FindClearPath(Sonar &sonar, Servo &sonarServo)
: _sonar(sonar),
  _sonarServo(sonarServo)
{}

float FindClearPath::calculateAngle()
{
  return 0.0;  
}
