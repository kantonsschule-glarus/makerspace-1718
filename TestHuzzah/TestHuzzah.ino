#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();

Adafruit_DCMotor *motorOne = AFMS.getMotor(1);
Adafruit_DCMotor *motorTwo = AFMS.getMotor(2);


void setup() {
  Serial.begin(9600);

  AFMS.begin();
}

void loop() {
  motorOne -> run(FORWARD);
  motorTwo -> run(FORWARD);
  for(int i = 0; i < 256; i++){
    motorOne -> setSpeed(i);
    motorTwo -> setSpeed(i);
    delay(10);
  }
  
  motorOne -> run(BACKWARD);
  motorTwo -> run(BACKWARD);
  for(int i = 0; i < 256; i++){
    motorOne -> setSpeed(i);
    motorTwo -> setSpeed(i);
    delay(10);
  }
  
  motorOne -> run(FORWARD);
  motorTwo -> run(BACKWARD);
  for(int i = 0; i < 256; i++){
    motorOne -> setSpeed(i);
    motorTwo -> setSpeed(i);
    delay(10);
  }

  motorOne -> run(BACKWARD);
  motorTwo -> run(FORWARD);
  for(int i = 0; i < 256; i++){
    motorOne -> setSpeed(i);
    motorTwo -> setSpeed(i);
    delay(10);
  }
}
