#include <OneWire.h>
#include <DallasTemperature.h>
#include "Wire.h"
#include "LiquidCrystal.h"

#define SPEAKER_PIN 10
#define ONE_WIRE_BUS 5

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
LiquidCrystal lcd(0);

const float limits[] = { 80.00, 85.00 };

float temp;
void setup(void)
{
  temp = 0;
  lcd.begin(16, 2);
  sensors.begin();
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

