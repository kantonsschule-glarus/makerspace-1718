#include "Arduino.h"
#include "Robot.h"

Robot::Robot()
: drive()
{;}

void Robot::forward(){;
  Serial.println("Es funkioniert also das forward ;)");
  drive.forward();
}
void Robot::backward(){;
  Serial.println("Es funkioniert also das backward ;)");
}
void Robot::stop(){;
  Serial.println("Es funkioniert also das stoppen ;)");
}
