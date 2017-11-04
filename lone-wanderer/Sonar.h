#ifndef Sonar_h
#define Sonar_h

class Sonar {
  public:
    Sonar();
    
    float getDistanceInMeter();

  private:
    int echoPin;
    int triggerPin;
};

#endif
