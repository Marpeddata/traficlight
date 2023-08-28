#ifndef TRAFICLIGHT_H
#define TRAFICLIGHT_H

class TraficLight
{
public:
    TraficLight(int greenPin, int yellowPin, int redPin, int greenPin1, int yellowPin1, int redPin1,long stateTime []);
    void setup(long startTime);
    void update(long now);

private:
    int _greenPin;
    int _yellowPin;
    int _redPin;
     int _greenPin1;
    int _yellowPin1;
    int _redPin1;
    long* _pStateTime;
    long _nextChange;
    int _state;
};

#endif