#include "Disk.h"

Disk::Disk(){}

Disk::LEVEL Disk::getLevel(float distanceInCm)
{
  if(distanceInCm < 10){
    return Disk::DANGER;
  }
  if(distanceInCm < 50){
    return Disk::ATTENTION;
  }
  return Disk::CLEAR;
}
