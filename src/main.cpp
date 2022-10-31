#include <Arduino.h>

#define fan_high_high 4
#define fan_high 5
#define fan_med 6
#define fan_low 7
#define hydronic_loop_on_off 8
#define hydronic_loop_temp 9

void fanHighHigh()
{
  digitalWrite(fan_high_high, !fan_high_high);
  digitalWrite(fan_high, false);
  digitalWrite(fan_med, false);
  digitalWrite(fan_low, false);
  Serial.print("fan set to high high");
}

void fanHigh()
{
  digitalWrite(fan_high_high, false);
  digitalWrite(fan_high, true);
  digitalWrite(fan_med, false);
  digitalWrite(fan_low, false);
  Serial.print("fan set to high high");
}
void fanMed()
{
  digitalWrite(fan_high_high, false);
  digitalWrite(fan_high, false);
  digitalWrite(fan_med, true);
  digitalWrite(fan_low, false);
  Serial.print("fan set to high high");
}
void fanLow()
{
  digitalWrite(fan_high_high, false);
  digitalWrite(fan_high, false);
  digitalWrite(fan_med, false);
  digitalWrite(fan_low, true);
  Serial.print("fan set to high high");
}

void setup()
{
  // initialize LED digital pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available())
  {
    int incoming = Serial.read();
    if (incoming == '1')
    {
      fanHighHigh();
    }
    else if (incoming == '2')
    {
      fanHigh();
    }
    else if (incoming == '3')
    {
      fanMed();
    }
    else if (incoming == '4')
    {
      fanLow();
    }
    else
    {
      Serial.println("unrecognized command");
    }
  }
}
