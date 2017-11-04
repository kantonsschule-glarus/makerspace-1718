#ifndef Distance_h
#define Distance_h

class Distance {
  public:
    Distance(int pin);

    float getDistanceInMeter();
    
  private:
    int _pin;
};

#endif
