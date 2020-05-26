#ifndef bt
#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

#define SERVICE_UUID "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"

class Bluetooth
{
public:
    Bluetooth(){};       //initializes object
    void checkNewData(); //checks for new data in loop
    bool getNewData();   //returns
    int getXAxis();      //returns x axis
    int getYAxis();      //returns y axis
    bool getShoot();     //sets shoot to false if its true and returns shoot (careful!)
    bool getReload();    //sets reload to false and if its true returns reload (careful!)

    void setup();
    void loop();

    BLECharacteristic *pCharacteristic;

private:
    int _mode;
    int _xDeg;           //x axis deg
    int _yDeg;           // y axis deg
    bool _shoot;         //stores shoot bool
    bool _reload;        //stores reload bool
    bool _newData;       //stores new data bool
    void _processData(); //processes new bt data
    
    String _lastRecString;
};

#endif