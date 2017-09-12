#ifndef Drive_h
#define Drive_h
/**
 * The drive coordinates the two motors.
 * 
 */
class Drive {
  public:
    Drive();
    
    void forward();
    void backward();
    void rotate();
    void stop();
};

#endif
