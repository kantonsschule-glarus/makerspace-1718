#ifndef Disk_h
#define Disk_h

class Disk {
  public:
    Disk();
    enum LEVEL { CLEAR, ATTENTION, DANGER };
        
    LEVEL getLevel(float distanceInCm);

};

#endif
