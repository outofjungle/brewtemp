#include <OneWire.h>
#include <DallasTemperature.h>
#include "Wire.h"
#include "LiquidCrystal.h"

#define SPEAKER_PIN 10
#define ONE_WIRE_BUS 5

int resolution = 12;
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
LiquidCrystal lcd(0);
DeviceAddress device_address;

const double limits[] = { 148.00, 152.00 };

double temp;
void setup(void)
{
  temp = 0;
  lcd.begin(16, 2);
  sensors.begin();
  sensors.getAddress(device_address, 0);
  sensors.setResolution(device_address, resolution);
}

void loop(void)
{ 
  sensors.requestTemperatures();
  temp = sensors.getTempFByIndex(0);

  if ( temp < limits[0] || temp > limits[1] ) {
    tone(SPEAKER_PIN, 440);
  } else {
    noTone(SPEAKER_PIN);
  }

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print( (char) 0xdf );
  lcd.print("F");
  
  delay(100);
}

