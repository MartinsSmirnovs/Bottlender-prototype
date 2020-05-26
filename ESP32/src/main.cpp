#include <Arduino.h>
#include <Bluetooth.h>
#include <Motor.h>
#include <Switch.h>

Bluetooth bt;
Motor xMotor(1063, 16, 17, 13);
Motor yMotor(1000, 18, 19, 8);

Switch valve(5 , 5000); //varsts
Switch reload(4 , 15000); //parladesana

unsigned long oldTimeInt;
int delayTime = 500;

int yLen = 100; //Y AXIS STRING LENGTH

void setup()
{
  Serial.begin(9600);

  xMotor.setup();
  yMotor.setup();

  valve.setup();
  reload.setup();

  bt.setup();
}

void loop()
{
  valve.loop();
  reload.loop();
  xMotor.loop();
  yMotor.loop();
  bt.loop();

  if (millis() - oldTimeInt >= delayTime)
  {
    oldTimeInt = millis();

    if (bt.getNewData())
    {
      xMotor.setPosition(bt.getXAxis());

      yMotor.setPosition(bt.getYAxis()*yLen/90);
      
      if(bt.getShoot()){
        valve.toggle();
      }
      if(bt.getReload())
        reload.toggle();


      // Serial.println("Update");
      // Serial.print("Shoot: ");
      // Serial.println(bt.getShoot());
      // Serial.print("Rereload: ");
      // Serial.println(bt.getRereload());
      // Serial.print("X: ");
      // Serial.println(bt.getXAxis());
      // Serial.print("Y: ");
      // Serial.println(bt.getYAxis());
      // Serial.println("-----------------------------");
    }
  }
}