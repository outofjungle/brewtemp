#include <OneWire.h>
#include <DallasTemperature.h>
#include "Wire.h"
#include "LiquidCrystal.h"

#define ONE_WIRE_BUS 5

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
LiquidCrystal lcd(0);

void setup(void)
{
  lcd.begin(16, 2);
  lcd.print("Temprature:");
  sensors.begin();
}

void loop(void)
{ 
  sensors.requestTemperatures();
  lcd.setCursor(0, 1);
  lcd.print(sensors.getTempCByIndex(0));
  lcd.print((char)0xdf);
  lcd.print("C/");
  lcd.print(sensors.getTempFByIndex(0));
  lcd.print((char)0xdf);
  lcd.print("F");

  delay(100);
}
