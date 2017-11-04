#include <Arduino.h>
#include "Distance.h"

Distance::Distance(int pin)
: _pin(pin)
{;}

float Distance::getDistanceInMeter(){
   int value = analogRead(_pin);
   float result = 100.0 - map(value,30,670, 1, 100);
   result = 0.01 * result;
   Serial.print("Distance ");Serial.print(result);Serial.println("m");
   return result;
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
