#include <Motor.h>

Motor::Motor(int stepsPerRevolution, byte stepPin, byte dirPin, int step)
{
    _stepPin = stepPin;
    _dirPin = dirPin;
    _stepsPerRevolution = stepsPerRevolution;
    _step = step;
    _currentPosition = 0;
    _plannedPosition = 0;
}

void Motor::setup()
{
    pinMode(_stepPin, OUTPUT);
    pinMode(_dirPin, OUTPUT);
}

void Motor::loop()
{
    if (_plannedPosition != _currentPosition)
    {
        if(abs(_currentPosition - _plannedPosition) < _step){
            _currentPosition = _plannedPosition;
        }
        else if (_currentPosition < _plannedPosition)
        {
            for (int i = 0; i < _step; i++)
            {
                _currentPosition++;
                digitalWrite(_dirPin, HIGH);
                digitalWrite(_stepPin, HIGH);
                delayMicroseconds(2000);
                digitalWrite(_stepPin, LOW);
                delayMicroseconds(2000);
            }
        }
        else if (_currentPosition > _plannedPosition)
        {
            for (int i = _step; i > 0; i--)
            {
                _currentPosition--;
                digitalWrite(_dirPin, LOW);
                digitalWrite(_stepPin, HIGH);
                delayMicroseconds(2000);
                digitalWrite(_stepPin, LOW);
                delayMicroseconds(2000);
            }
        }
    }
}

void Motor::setPosition(int newPosition)
{
    _plannedPosition = map(newPosition, 0, 360, 0, _stepsPerRevolution);
}
