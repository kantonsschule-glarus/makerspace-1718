#ifndef GoToGoal_h
#define GoToGoal_h

#include <Servo.h>

#include "Behavior.h"
#include "PIDController.h"
#include "Sonar.h"

class GoToGoal : Behavior {
  public:
    GoToGoal(Sonar &s, Servo &sServo);
    ~GoToGoal();
    
    virtual float calculateAngle();

    void behave();
    
  private:
    float nominalAngle;
    float actualAngle;
    PIDController pidController;
    Sonar &sonar;
    Servo &sonarServo;    
};

#endif
