#include "Disk.h"

Disk::Disk(){}

Disk::LEVEL Disk::getLevel(float distanceInMeter)
{
  if(distanceInMeter < 0.1){
    return Disk::DANGER;
  }
  if(distanceInMeter < 0.5){
    return Disk::ATTENTION;
  }
  return Disk::CLEAR;
}
