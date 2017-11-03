#include <Arduino.h>
#include "Distance.h"

Distance::Distance(int pin)
: _pin(pin)
{;}

int Distance::getDistanceInCm(){
   int value = analogRead(_pin);
   //Serial.println(value);
   return 100.0 - map(value,30,670, 1, 100);
/*   if(value <= 90){
      return 100; // cm 
   }
   if(value > 90 && value <= 120){
      return 1;
   }
   if(value > 120 && value <= 270){
      return 2;
   }
   return 3;*/
}
