#include <Switch.h>

Switch::Switch(byte switchPin, int delayTime){
    _switchPin = switchPin;
    _delayTime = delayTime;
    _toggle = false;   
}

void Switch::setup(){
    pinMode(_switchPin, OUTPUT);
}

void Switch::loop(){
    if(_toggle && millis()-_oldTimeInt >= _delayTime){
        _toggle = false;
        digitalWrite(_switchPin, LOW);
    }
}

void Switch::toggle(){
    _oldTimeInt = millis();
    _toggle = true;
    digitalWrite(_switchPin, HIGH);
}