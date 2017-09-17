#include "Arduino.h"
#include "Robot.h"

Robot robot;

void setup() {
  Serial.begin(9600);
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
