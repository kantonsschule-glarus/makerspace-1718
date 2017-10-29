#ifndef Robot_h
#define Robot_h

#include "Drive.h"
#include "Light.h"
#include "Bumper.h"

/*
 * This is the interface of the robot
 */
class Robot {
  public:
    Robot(Drive &drive);
    void wakeUp();
    /**
     * Checks the sensors and save sensor-data
     */
    void check();

    void setUp();
    void forward();
    void backward();
    void left();
    void right();
    void stop();
    /**
     * Behave upon sensor data
     */
    void behave();
    
  private:
    int awakeIndicatorPin;
    Drive &drive;
    Light fl;
    Light fr;
    Light rl;
    Light rr;
    Bumper bfl;
    Bumper bfr;
};

#endif

