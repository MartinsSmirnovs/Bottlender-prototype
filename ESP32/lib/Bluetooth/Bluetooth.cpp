#include "Bluetooth.h"

void Bluetooth::setup()
{
    BLEDevice::init("ESP32 BT");
    BLEServer *pServer = BLEDevice::createServer();
    BLEService *pService = pServer->createService(SERVICE_UUID);
    pCharacteristic = pService->createCharacteristic(
        CHARACTERISTIC_UUID,
        BLECharacteristic::PROPERTY_READ |
            BLECharacteristic::PROPERTY_WRITE);

    pCharacteristic->setValue("Hello World says Neil");
    pService->start();
    // BLEAdvertising *pAdvertising = pServer->getAdvertising();  // this still is working for backward compatibility
    BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
    pAdvertising->addServiceUUID(SERVICE_UUID);
    pAdvertising->setScanResponse(true);
    pAdvertising->setMinPreferred(0x06); // functions that help with iPhone connections issue
    pAdvertising->setMinPreferred(0x12);
    BLEDevice::startAdvertising();
}

void Bluetooth::loop()
{
    checkNewData();
}

void Bluetooth::checkNewData()
{
    //  Serial.println("In recvWithStartEndMarkers");
    int countDataSwCase; //recvWithStartEndMarkers switch operatora skaititajs
    static bool recvInProgress = false;
    static byte ndx = 0;
    char startMarker = '<';
    char endMarker = '>';

    char receivedChars[3];
    byte numChars = 3;
    char rc; //saja mainigaja tiek saglabats katrs ienakosais baits

    String inputString = pCharacteristic->getValue().c_str();
    // Serial.println(inputString);
    if (inputString != _lastRecString)
    {
        _lastRecString = inputString;

        for (int x = 0; x < inputString.length(); x++)
        {
            //      Serial.println("LoopVal: ");Serial.println(x);
            rc = inputString[x];
            if (recvInProgress == true)
            {
                if (rc != endMarker)
                {
                    receivedChars[ndx] = rc; //no siem datiem tiek pieskirtas mainigo vertibas, kas tiek iesutitas un no saraksta parveidotas skaitli
                    ndx++;
                    switch (countDataSwCase)
                    {
                    case 1: //tiek noteikts ienakoso datu tips
                        _mode = atoi(receivedChars);
                        if (_mode == 1)
                        {
                            _shoot = true;
                        }
                        else if (_mode == 2)
                        {
                            _reload = true;
                        }
                        ndx = 0;
                        break;
                    case 4: //tiek noteikts kuriem led pikseliem ir jastrada
                        if (_mode == 0)
                        {
                            _xDeg = atoi(receivedChars);
                        }
                        ndx = 0;
                        break;
                    case 7:
                        if (_mode == 0)
                        {
                            _yDeg = atoi(receivedChars);
                        }
                        ndx = 0;
                        break;
                    default:
                        break;
                    }
                    if (ndx >= numChars)
                    {
                        ndx = numChars - 1;
                    }
                }
                else
                {
                    receivedChars[sizeof(receivedChars)] = '\0'; // terminate the string, svariga koda rindina, kur ieprieks [] ieksa bija ndx. Ndx patstavigi mainas, tapec bija nepieciesams ievietot citu garuma vertibu
                    recvInProgress = false;
                    // setNewData();
                    _newData = true;
                }
                countDataSwCase++; //datu sadalisanas dalas skaititajs
            }
            else if (rc == startMarker)
            {
                recvInProgress = true;
                countDataSwCase = 1; //reseto mainigo no ieprieksejas vertibas
            }
        }
    }
}

bool Bluetooth::getNewData()
{
    if (_newData)
    {
        _newData = false;
        return true;
    }
    return false;
}

int Bluetooth::getXAxis()
{
    return _xDeg;
}

int Bluetooth::getYAxis()
{
    return _yDeg;
}

bool Bluetooth::getShoot()
{
    if (_shoot)
    {
        _shoot = false;
        return true;
    }
    return false;
}

bool Bluetooth::getReload()
{
    if (_reload)
    {
        _reload = false;
        return true;
    }
    return false;
}