#include "Drive.h"

#ifndef Robot_h
#define Robot_h

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
};

#endif

