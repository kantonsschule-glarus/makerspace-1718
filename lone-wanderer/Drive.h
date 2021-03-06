#ifndef Drive_h
#define Drive_h

#include <Adafruit_MotorShield.h>
/**
 * The differential drive coordinates the two motors.
 * @autor nils
 */
class Drive {
  public:
    Drive(float wheelDistance, 
         float wheelRadius,
         Adafruit_MotorShield &AFMS);

    void setUp();
    void forward();
    void backward();
    void left();
    void right();
    void spinLeft();
    void spinRight();
    void flatLeft();
    void flatRight();
    void stop();
    void setAngle(float o);
    void setVelocity(int value); // [0..255]
    
  private:
    int velocity;
    int maxVelocity;
    int velocityLeftMotor;
    int velocityRightMotor;
    float omega;
    float L;
    float R; 
    Adafruit_MotorShield &AFMS;
    Adafruit_DCMotor *leftMotor;
    Adafruit_DCMotor *rightMotor;
    void applyMotorVelocities();
    void calculateVelocityLeftMotor();
    void calculateVelocityRightMotor();
    float asRadiant(float degrees);
    int mapVelocityToPwm(float v);
};

#endif
