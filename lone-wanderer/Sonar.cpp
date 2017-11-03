#include <Arduino.h>
#include "Sonar.h"

Sonar::Sonar()
: echoPin(12),
  triggerPin(11)
{
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

float Sonar::getDistanceInCm()
{
    // Code from here: https://randomnerdtutorials.com/complete-guide-for-ultrasonic-sensor-hc-sr04/
    // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
    // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(5);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);
    
    // Read the signal from the sensor: a HIGH pulse whose
    // duration is the time (in microseconds) from the sending
    // of the ping to the reception of its echo off of an object.
    pinMode(echoPin, INPUT);
    long duration = pulseIn(echoPin, HIGH);
    
    // convert the time into a distance
    float cm = (duration/2.0) / 29.1;
    return cm;
}

