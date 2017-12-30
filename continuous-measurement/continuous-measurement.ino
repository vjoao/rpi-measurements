/*
    INA219 Zero-Drift, Bi-directional Current/Power Monitor. Simple Example.
    Read more: http://www.jarzebski.pl/arduino/czujniki-i-sensory/cyfrowy-czujnik-pradu-mocy-ina219.html
    GIT: https://github.com/jarzebski/Arduino-INA219
    Web: http://www.jarzebski.pl
    (c) 2014 by Korneliusz Jarzebski
*/

#include <Wire.h>
#include <INA219.h>

INA219 ina;

unsigned long long m = 0;
unsigned long long total = 0;
unsigned long initTime = 0;

#define TIME_SEC 20 // boot time
bool finished = false;

void setup() 
{
  Serial.begin(115200);

  ina.begin();

  // Configure INA219
  ina.configure(INA219_RANGE_16V, INA219_GAIN_160MV, INA219_BUS_RES_12BIT, INA219_SHUNT_RES_12BIT_128S);

  // Calibrate INA219. Rshunt = 0.1 ohm, Max excepted current = 1.6A
  ina.calibrate(0.1, 1.6);

  // start measurement on RPi connection
//  while (ina.readBusPower() < 0.1) {
//  }

  Serial.println("power,time");
  while (digitalRead(8) == 0); // wait for pin8 to be high
  initTime = millis();
}

void loop()
{
//  unsigned long t = millis() - initTime;
//  Serial.print("Bus voltage:   ");
//  Serial.print(ina.readBusVoltage(), 5);
//  Serial.println(" V");
//
  if(digitalRead(8) != 0) {
    if(ina.conversionReady()) {
      Serial.print(ina.readBusPower(), 5);
      Serial.print(",");
      Serial.println(millis() - initTime);
    }
  } else if (!finished) {
    Serial.println("end");
    finished = true;
  }
//
//
//  Serial.print("Shunt voltage: ");
//  Serial.println(" V");
//
//  Serial.print("Shunt current: ");
  
//  Serial.println(" A");

//  total += (millis() - t);
//  m++;
//  Serial.println(" Hz");
}
