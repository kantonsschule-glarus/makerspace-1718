#ifndef PIDController_h
#define PIDController_h

class PIDController {
  public:
    PIDController();
    ~PIDController();
    
    float calculateAngle(float error);

  private:
    float oldError;
    float sumOfErrors;
    float kP;
    float kD;
    float kI;
};

#endif
