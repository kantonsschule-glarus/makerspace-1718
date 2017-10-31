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
  distance(A0)
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

void Robot::check(){
  if(isBumped()){
    threePointTurnLeft();
    return;
  }

  Distance::ZONE d = distance.check();
  switch(d){
    case Distance::danger:
      drive.stop();
      delay(1000);
      threePointTurnRight();
      break;
    case Distance::attention:
      drive.left();
      break;
    case Distance::clear:
    default:
      drive.forward();
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

