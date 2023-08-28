#include "TraficLight.h"
#include <Arduino.h>

TraficLight::TraficLight(int greenPin, int yellowPin, int redPin, int greenPin1, int yellowPin1, int redPin1, long stateTime[])
        : _greenPin(greenPin), _yellowPin(yellowPin), _redPin(redPin), _greenPin1(greenPin1), _yellowPin1(yellowPin1), _redPin1(redPin1),_nextChange(0), _state(0) {
        _pStateTime = stateTime; // Initialize the pointer to state times
    }


void TraficLight::setup(long startTime)
{
    pinMode(_redPin, OUTPUT);
    pinMode(_yellowPin, OUTPUT);
    pinMode(_greenPin, OUTPUT);
    pinMode(_redPin1, OUTPUT);
    pinMode(_yellowPin1, OUTPUT);
    pinMode(_greenPin1, OUTPUT);
    _nextChange = startTime + _pStateTime[_state];
    digitalWrite(_redPin, HIGH);
    digitalWrite(_yellowPin, LOW);
    digitalWrite(_greenPin, LOW);
    digitalWrite(_redPin1, HIGH);
    digitalWrite(_yellowPin1, LOW);
    digitalWrite(_greenPin1, LOW);
}

void TraficLight::update(long now)
{
    if (now < _nextChange)
        return;
    {
        _state = (_state + 1) % 8;
        digitalWrite(_redPin, _state == 0 || _state == 1 || _state == 4 || _state == 5 || _state == 6 || _state == 7);
        digitalWrite(_yellowPin, _state == 1 || _state == 3);
        digitalWrite(_greenPin, _state == 2);

        digitalWrite(_redPin1, _state == 0 || _state == 1 || _state == 2 || _state == 3 || _state == 4 || _state == 5);
        digitalWrite(_yellowPin1, _state == 5 || _state == 7);
        digitalWrite(_greenPin1, _state == 6);
        _nextChange += _pStateTime[_state];
    }
      
    
}
