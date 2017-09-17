#ifndef Drive_h
#define Drive_h

//#include <Wire.h>
//#include <Adafruit_MotorShield.h>
//#include "utility/Adafruit_MS_PWMServoDriver.h"

class Drive {
  public:
    Drive();
    void forward();
    void backward();
    void stop();
 //private:
    //Adafruit_MotorShield AFMS;
    //Adafruit_DCMotor *leftMotor;
    //Adafruit_DCMotor *rightMotor;
};
#endif
