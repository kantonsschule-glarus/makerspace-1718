#ifndef ThreePointTurn_h
#define ThreePointTurn_h

#include "Behavior.h"
#include "Drive.h"

class ThreePointTurn : Behavior {
  public:
    ThreePointTurn(Drive &drive);
    
    virtual float calculateAngle();

    void act();
    
  private:
    Drive &_drive;
};

#endif
