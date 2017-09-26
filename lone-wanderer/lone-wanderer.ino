#include <Arduino.h>
#include <Adafruit_MotorShield.h>

#include "Robot.h"
#include "Drive.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();

Drive drive(AFMS);
Robot robot(drive);

/**
 * This is the lone wanderer robot. It's
 * purpose in life is to wander around.
 * @autor: nils
 */

void setup() {
  Serial.begin(9600);
}


void loop() {
  robot.forward();
  delay(1000);
  robot.backward();
  delay(1000);
  robot.left();
  delay(1000);
  robot.right();
  delay(1000);
  robot.stop();
  delay(1000);
}

