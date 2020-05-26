#ifndef motor
#include <Arduino.h>
        class Motor{
            public:
                Motor(int stepsPerRevolution, byte stepPin, byte dirPin, int multiplier);
                Motor(){};
                void setup();
                void loop();
                void setPosition(int newPosition);
            private:
                int _currentPosition;
                byte _stepPin;
                byte _dirPin;
                int _step;
                int _plannedPosition;
                int _stepsPerRevolution;
        };
#endif 


