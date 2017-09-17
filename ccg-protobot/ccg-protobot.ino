#include <Arduino.h>
#include <Adafruit_MotorShield.h>

#include "Drive.h"
#include "Robot.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

Drive drive(AFMS);
Robot robot(drive);

void setup() {
  Serial.begin(9600);
  robot.setUp();
  delay(50);
  
  robot.forward();
  delay(1000);
  robot.stop();
  delay(1000);
  robot.backward();
  delay(1000);
  robot.stop();
  
}

void loop() {
  // put your main code here, to run repeatedly:
}
