#ifndef Distance_h
#define Distance_h

class Distance {
  public:
    Distance(int pin);
    enum ZONE { clear, attention, danger};

    ZONE check();
    
  private:
    int _pin;
};

#endif
