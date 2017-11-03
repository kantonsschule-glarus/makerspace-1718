#ifndef FindClearPath_h
#define FindClearPath_h

#include <Servo.h>

#include "Behavior.h"
#include "Sonar.h"

class FindClearPath : Behavior {
  public:
    FindClearPath(Sonar &sonar, Servo &sonarServo);
    
    virtual float calculateAngle();

  private:
    Sonar &_sonar;
    Servo &_sonarServo;
};

#endif
