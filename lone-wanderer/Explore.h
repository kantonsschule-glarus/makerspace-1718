#ifndef Explore_h
#define Explore_h

#include "Drive.h"
#include "Disk.h"
#include "Behavior.h"
#include "Sonar.h"
#include "FindClearPath.h"

class Explore : Behavior {
  public:
    Explore(Sonar &sonar, 
            FindClearPath &findClearPath, 
            Drive &drive,
            Disk &disk);
    
    virtual float calculateAngle();

    void act();
    
  private:
    Sonar &_sonar;
    FindClearPath &_findClearPath;
    Drive &_drive;
    Disk &_disk;
};

#endif
