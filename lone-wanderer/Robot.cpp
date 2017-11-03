#include "Arduino.h"
#include "Robot.h"

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
  currentDiskLevel(Disk::CLEAR),
  currentDistanceFromObstacleInCm(100.0)
{;}

void Robot::setUp(){
  drive.setUp();
}

void Robot::wakeUp(){ 
  Serial.println("Robot wakeup ..."); 
  digitalWrite(awakeIndicatorPin, HIGH);

  fl.on();
  fr.on();
  rl.on();
  rr.on();

  goToGoal.behave();
  
  drive.spinLeft();
  delay(2000);
  drive.stop();
  delay(200);
  drive.spinRight();
  delay(2000);
  drive.forward();
  drive.stop();
  Serial.println("Robot wakeup done"); 
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
  currentDistanceFromObstacleInCm = distance.getDistanceInCm();
  currentDiskLevel = disk.getLevel(currentDistanceFromObstacleInCm);
}

void Robot::act()
{
  switch(currentDiskLevel){
    case Disk::DANGER:
    {
      threePointTurnRight();
    }    
    case Disk::ATTENTION:
    case Disk::CLEAR:
    default:
      float angleToGo = blender.blend(
                            currentDistanceFromObstacleInCm, 
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

void Robot::threePointTurnLeft(){
    drive.stop();
    drive.left();
    drive.backward();
    delay(1000);
    drive.spinLeft();
    delay(600);
    drive.forward();
}

void Robot::threePointTurnRight(){
    drive.stop();
    drive.right();
    drive.backward();
    delay(500);
    drive.spinRight();
    delay(400);
    drive.forward();
}

