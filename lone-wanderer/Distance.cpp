#include <Arduino.h>
#include "Distance.h"

Distance::Distance(int pin)
: _pin(pin)
{;}

int Distance::check(){
   int value = analogRead(_pin);
   if(value <= 90){
      return 0; 
   }
   if(value > 90 && value <= 120){
      return 1;
   }
   if(value > 120 && value <= 270){
      return 2;
   }
   return 3;
}
