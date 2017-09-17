#ifndef Robot_h
#define Robot_h

#include "Drive.h"
/**
 * This is the robot that is able to run in autonomous and teleoperated mode.
 * @autor cgg@...
 */
class Robot {
  public:
    Robot();
    void forward();
    void backward();
    void stop();
  private:
    Drive drive;
};

#endif
