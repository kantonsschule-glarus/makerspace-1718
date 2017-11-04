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
#include "Explore.h"
#include "ThreePointTurn.h"
#include "WakeUp.h"

/*
 * This is the interface of the robot
 */
class Robot {
  public:
    Robot(Drive &drive);
    void doWakeUp();
    void doExplore();
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
    Explore explore;
    ThreePointTurn threePointTurn;
    WakeUp wakeUp;
    Disk::LEVEL currentDiskLevel;
    float currentDistanceFromObstacleInMeter;
    boolean isBumped();
};

#endif

