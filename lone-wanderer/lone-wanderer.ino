#include "Robot.h"
/**
 * This is the lone wanderer robot. It's
 * purpose in life is to wander around.
 * @autor: nils
 */
Robot robot;

void setup() {
  Serial.begin(9600);
  
  robot.wakeUp();
}


void loop() {
  robot.check();
  robot.behave();

  delay(25);
}

