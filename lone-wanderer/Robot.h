#ifndef Robot_h
#define Robot_h

#include <Servo.h>

#include "Drive.h"
#include "Light.h"
#include "Bumper.h"
#include "Distance.h"
#include "AvoidObstacle.h"
#include "GoToGoal.h"
#include "FindClearPath.h"
#include "BehaviorBlendingService.h"
#include "Disk.h"
#include "Sonar.h"

/*
 * This is the interface of the robot
 */
class Robot {
  public:
    Robot(Drive &drive);
    void wakeUp();
    /**
     * tick is called in time-descreete intervals like every 25milliseconds.
     * The robot's responsibility is to take this tick to plan and act.
     */
    void tick();
    /**
     * Checks the sensors and save sensor-data
     */
    void plan();
    void act();

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
    Distance distance;
    Sonar sonar;
    Servo sonarServo;
    AvoidObstacle avoidObstacle;
    FindClearPath findClearPath;
    GoToGoal goToGoal;
    BehaviorBlendingService blender;
    Disk disk;
    Disk::LEVEL currentDiskLevel;
    float currentDistanceFromObstacleInCm;
    boolean isBumped();
    void threePointTurnLeft();
    void threePointTurnRight();
};

#endif

