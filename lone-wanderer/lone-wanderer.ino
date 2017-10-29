#include <Arduino.h>
#include <Adafruit_MotorShield.h>

#include "Robot.h"
#include "Drive.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();

const float wheelDistanceInCm = 15.0; // cm
const float wheelRadiusInCm = 3.0; // cm

Drive drive(wheelDistanceInCm, wheelRadiusInCm, AFMS);
Robot robot(drive);

/**
 * This is the lone wanderer robot. It's
 * purpose in life is to wander around.
 * @autor: nils
 */

void setup() {
  Serial.begin(9600);
  robot.setUp();
  
  robot.wakeUp();
}


void loop() {
  robot.check();
  delay(25);
}

