#include <Arduino.h>

#include "Explore.h"

Explore::Explore(Sonar &sonar, 
                 FindClearPath &findClearPath,
                 Drive &drive,
                 Disk &disk)
: _sonar(sonar),
  _findClearPath(findClearPath),
  _drive(drive),
  _disk(disk)
{;}

float Explore::calculateAngle(){
  return 0.0;
}

void Explore::act()
{
  Serial.println("Explore act ...");
    float epsilon = 0.1;
    float nominalAngle = _findClearPath.calculateAngle();
    float actualAngle = 0.0;
    _drive.stop();
    float dm = _sonar.getDistanceInMeter();
    Disk::LEVEL level = _disk.getLevel(dm);
    switch(level){
      case Disk::ATTENTION:      
      case Disk::DANGER:
          for(int i=0; i<10; i++){
            float error = actualAngle - nominalAngle;
            Serial.print("Robot explore correcting angle by ");
            Serial.print(error);
            Serial.println("rad");
            
            //drive.setAngle(pid.calculateAngle(error));
            if(abs(error) <= epsilon){
              return;
            }
            _drive.setAngle(0);
            _drive.setVelocity(75);
            if(error > 0){
              _drive.spinRight();  
            }
            if(error < 0){
              _drive.spinLeft();  
            }
            delay(250);
            _drive.stop();
            dm = _sonar.getDistanceInMeter();
            level = _disk.getLevel(dm);
            switch(level){
              case Disk::CLEAR:
                _drive.forward();
                _drive.stop();
                Serial.println("Explore act done early");
                return;
              default:
                break;
            }
            nominalAngle = _findClearPath.calculateAngle();
            break;          
      }
      case Disk::CLEAR:
      default:
        _drive.forward();
        _drive.stop();
    }
    _drive.stop();  
    Serial.println("Explore act done");
}


