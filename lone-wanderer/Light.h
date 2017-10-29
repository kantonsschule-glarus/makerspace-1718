#ifndef Light_h
#define Light_h

class Light {
  public:
    Light(int pin);
    void on();
    void off();
    
  private:
    int _pin;
};

#endif

