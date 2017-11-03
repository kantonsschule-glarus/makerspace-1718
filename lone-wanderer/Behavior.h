#ifndef Behavior_h
#define Behavior_h

class Behavior {
  public: 
    /**
     * The behave calculates the angle that the robot should head.
     * The angle is in radiants (not degrees) and always between -PI and PI.
     */
    virtual float calculateAngle() = 0;
};

#endif
