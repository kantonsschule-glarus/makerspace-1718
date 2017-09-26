#ifndef Drive_h
#define Drive_h

#include <Adafruit_MotorShield.h>
/**
 * The drive coordinates the two motors.
 * 
 */
class Drive {
  public:
    Drive(Adafruit_MotorShield &AFMS);
    
    void forward();
    void backward();
    void left();
    void right();
    void stop();
    
  private:
    Adafruit_MotorShield &AFMS;
    Adafruit_DCMotor *leftMotor;
    Adafruit_DCMotor *rightMotor;
};

#endif
