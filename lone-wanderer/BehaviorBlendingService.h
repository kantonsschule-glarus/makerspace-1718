#ifndef BehaviorBlendingService_h
#define BehaviorBlendingService_h

class BehaviorBlendingService {
  public:
    BehaviorBlendingService();
    ~BehaviorBlendingService();
    
    float blend(float distance, float angleGoToGoal, float angleAvoidObstacle);
  private:
    float beta;
    float sigma(float distance);
};

#endif
