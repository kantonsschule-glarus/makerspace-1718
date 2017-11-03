#include <Math.h>
#include "PIDController.h"

PIDController::PIDController()
:
oldError(0.0),
sumOfErrors(0.0),
kP(1.0),
kD(1.0),
kI(1.0)
{;}

PIDController::~PIDController()
{;}

float PIDController::calculateAngle(float error)
{
  // since error is an angle make shure its between -PI and PI:
  error = atan2(sin(error),cos(error));
  
  float eDot = error - oldError; 
  sumOfErrors = sumOfErrors + error;
  
  float u = kP * error + kD * eDot + kI * sumOfErrors;
  
  oldError = error;
  return u;
}

