#ifndef AvoidObstacle_h
#define AvoidObstacle_h

#include "Behavior.h"
#include "Distance.h"

class AvoidObstacle : Behavior {
  public:
    AvoidObstacle(Distance &distance);
    ~AvoidObstacle();
    
    virtual float calculateAngle();

  private:
    Distance &_distance;
};

#endif
