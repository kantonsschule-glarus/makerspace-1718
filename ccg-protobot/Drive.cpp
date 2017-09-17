#include "Arduino.h"
#include "Drive.h"

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61); 

// Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *leftMotor = AFMS.getMotor(1);
Adafruit_DCMotor *rightMotor = AFMS.getMotor(2);

Drive::Drive()
//: AFMS()
{
  //leftMotor = AFMS.getMotor(1);  
  //rightMotor = AFMS.getMotor(2); 

  AFMS.begin();

  leftMotor->setSpeed(150);
  rightMotor->setSpeed(150);
}

void Drive::forward(){
  Serial.println("Drive forward ;)");
  leftMotor->run(FORWARD);
}
void Drive::backward(){
   Serial.println("Drive backward ;)");
}
void Drive::stop(){
   Serial.println("Drive stop ;)");
}
