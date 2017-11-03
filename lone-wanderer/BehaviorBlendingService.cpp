#include <Math.h>
#include "BehaviorBlendingService.h"

BehaviorBlendingService::BehaviorBlendingService()
: beta(0.75)
{}

BehaviorBlendingService::~BehaviorBlendingService()
{}

float BehaviorBlendingService::blend(float distance, float angleGoToGoal, float angleAvoidObstacle)
{
  return angleAvoidObstacle;
  //float sd = sigma(distance);
  //return sd * angleGoToGoal + (1 - sd) * angleAvoidObstacle;
}

float BehaviorBlendingService::sigma(float distance)
{
  return 1.0 - exp(-beta * distance);
}

