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
  ina.configure(INA219_RANGE_16V, // Máximo de 16 Volts
    INA219_GAIN_160MV, // Máximo de 1.6 A
    INA219_BUS_RES_12BIT, // ADC de 12 bits
    INA219_SHUNT_RES_12BIT_128S); // ADC de 12 bits / 128 amostras
    
  ina.calibrate(0.1, 1.6);
  
  Serial.println("power,time");
  
  while (ina.readBusPower() < 0.1) {
  }
  
  initTime = millis();
}

void loop()
{
  unsigned long t = millis() - initTime;
  float busPower = ina.readBusPower();
  if(digitalRead(8) == 0 && !finished) {
    if(ina.conversionReady()) {
      Serial.print(busPower, 5);
      Serial.print(",");
      Serial.println(millis() - initTime);  
    }
  } else if (!finished) {
    Serial.println("end");
    finished = true;
  }
}
