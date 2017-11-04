#include "Arduino.h"
#include "Robot.h"

#include "PIDController.h"

Robot::Robot(Drive &theDrive)
: drive(theDrive),
  fl(3),
  fr(5),
  rl(9),
  rr(10),
  bfl(2),
  bfr(4),
  distance(A0),
  sonar(),
  sonarServo(),
  avoidObstacle(distance),
  findClearPath(sonar, sonarServo),
  goToGoal(sonar, sonarServo),
  blender(),
  disk(),
  explore(sonar,findClearPath,drive,disk),
  threePointTurn(theDrive),
  wakeUp(drive,fl,fr,rl,rr),
  currentDiskLevel(Disk::CLEAR),
  currentDistanceFromObstacleInMeter(1.0)
{;}

void Robot::setUp(){
  drive.setUp();
}

void Robot::doWakeUp(){ 
  wakeUp.act(); 
}

void Robot::doExplore()
{
  explore.act();
}

void Robot::forward(){
  Serial.println("Robot forward");
  drive.forward();
}

void Robot::backward(){
  Serial.println("Robot backward");
  drive.backward();
}

void Robot::left(){
  Serial.println("Robot left");
  drive.left();
}

void Robot::right(){
  Serial.println("Robot right");
  drive.right();
}

void Robot::stop(){
  Serial.println("Robot stop");
  drive.stop();
}

void Robot::tick()
{
  plan();
  act();  
}
void Robot::plan(){
  currentDistanceFromObstacleInMeter = distance.getDistanceInMeter();
  currentDiskLevel = disk.getLevel(currentDistanceFromObstacleInMeter);
  Serial.print("Robot plan currentDistanceFromObstacleInMeter=");
  Serial.print(currentDistanceFromObstacleInMeter);
  Serial.print("m, currentDiskLevel=");
  Serial.println(currentDiskLevel);
}

void Robot::act()
{
  switch(currentDiskLevel){
    case Disk::DANGER:
    {
      threePointTurn.act();
      explore.act();
      forward();
      break;
    }    
    case Disk::ATTENTION:
    case Disk::CLEAR:
    default:
      float angleToGo = blender.blend(
                            currentDistanceFromObstacleInMeter, 
                            goToGoal.calculateAngle(), 
                            avoidObstacle.calculateAngle());
  
      drive.setAngle(angleToGo);
  }
}
void Robot::behave(){
  Serial.println("Robot read data and behave normal");
}

boolean Robot::isBumped(){
  return bfr.isPressed();
}


