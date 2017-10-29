#include <Arduino.h>
#include <Adafruit_MotorShield.h>

#include "Robot.h"
#include "Drive.h"
#include "Light.h"
#include "Bumper.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();

Drive drive(AFMS);
Robot robot(drive);
Light fl(3);
Light fr(5);
Light rl(9);
Light rr(10);
Bumper bfl(4);
Bumper bfr(2);

/**
 * This is the lone wanderer robot. It's
 * purpose in life is to wander around.
 * @autor: nils
 */

void setup() {
  Serial.begin(9600);
  robot.startRobot();
  fl.on();
  fr.on();
  rl.on();
  rr.on();

  if(bfl.isPressed()){
    Serial.println("BFL is pressed");
  }
  if(bfr.isPressed()){
    Serial.println("BFR is pressed");
  }
}


void loop() {
  robot.forward();

  if(bfl.isPressed()){
    Serial.println("BFL is pressed");
  }
  if(bfr.isPressed()){
    Serial.println("BFR is pressed");
  }  delay(2000);
  robot.stop();
  delay(1000);
  robot.backward();

  if(bfl.isPressed()){
    Serial.println("BFL is pressed");
  }
  if(bfr.isPressed()){
    Serial.println("BFR is pressed");
  }
  delay(2000);
  robot.stop();
  delay(1000);
  robot.left();
  delay(4000);
  robot.right();
  delay(4000);
  robot.stop();
  delay(1000);
}

