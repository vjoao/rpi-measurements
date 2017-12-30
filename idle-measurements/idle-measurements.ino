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

void setup() 
{
  Serial.begin(115200);

  ina.begin();

  // Configure INA219
  ina.configure(INA219_RANGE_16V, INA219_GAIN_160MV, INA219_BUS_RES_12BIT, INA219_SHUNT_RES_12BIT_32S);

  // Calibrate INA219. Rshunt = 0.1 ohm, Max excepted current = 1.6A
  ina.calibrate(0.1, 1.6);
}

void loop()
{
//  unsigned long t = millis() - initTime;
//  Serial.print("Bus voltage:   ");
//  Serial.print(ina.readBusVoltage(), 5);
//  Serial.println(" V");
//
//  Serial.print("Bus power:     ");
  float busPower = ina.readBusPower();
//  Serial.println(ina.conversionReady());/
//  
//  if((millis() - initTime) > TIME_SEC * 1000) {
//    Serial.println("end"); 
//  } else {
//    Serial.print(busPower, 5);
//    Serial.print(",");
//    Serial.print(ina.readShuntCurrent() * 1000, 5);
//    Serial.print(",");
//    Serial.println(millis() - initTime);  
//  }
  Serial.println(digitalRead(8));
//  delay(1000);
//
//
//  Serial.print("Shunt voltage: ");
//  Serial.print(ina.readShuntVoltage(), 5);//
//  Serial.println(" V");
//
//  Serial.print("Shunt current: ");
  
//  Serial.println(" A");

//  total += (millis() - t);
//  m++;
//  Serial.println(" Hz");
}
