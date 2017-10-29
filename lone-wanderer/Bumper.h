#ifndef Bumper_h
#define Bumper_h

class Bumper {
  public:
    Bumper(int pin);
    boolean isPressed();
    
  private:
    int _pin;
};

#endif
