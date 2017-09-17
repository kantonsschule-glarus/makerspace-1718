#ifndef Drive_h
#define Drive_h

#include <Adafruit_MotorShield.h>

class Drive {
  public:
    Drive(Adafruit_MotorShield &AFMS);
    void setUp();
    
    void forward();
    void backward();
    void stop();
 private:
    Adafruit_MotorShield &AFMS;
    Adafruit_DCMotor *leftMotor;
    Adafruit_DCMotor *rightMotor;
};
#endif
