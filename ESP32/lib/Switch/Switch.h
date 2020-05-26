#ifndef sw
#include <Arduino.h>

class Switch{
    public:
        Switch(byte switchPin, int delayTime);
        Switch(){};
        void toggle();
        void setup();
        void loop();
    private:
        unsigned long _oldTimeInt;
        byte _switchPin;
        int _delayTime;
        bool _toggle;
};

#endif