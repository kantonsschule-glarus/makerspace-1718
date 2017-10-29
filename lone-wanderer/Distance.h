#ifndef Distance_h
#define Distance_h

class Distance {
  public:
    Distance(int pin);

    int check();
    
  private:
    int _pin;
};

#endif
