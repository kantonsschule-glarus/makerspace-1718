#ifndef WakeUp_h
#define WakeUp_h

#include "Behavior.h"
#include "Drive.h"
#include "Light.h"

class WakeUp : Behavior {
  public:
    WakeUp(Drive &drive, 
           Light &fl, 
           Light &fr, 
           Light &rl, 
           Light &rr);
    
    virtual float calculateAngle();

    void act();
    
  private:
    Drive &_drive;
    Light &_fl;
    Light &_fr; 
    Light &_rl;
    Light &_rr;
};

#endif
