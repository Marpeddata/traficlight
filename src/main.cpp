#include <Arduino.h>
#include "TraficLight.h"

TraficLight traficLight (D2, D1, D0, D5, D4, D3, (long[]){1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000});
TraficLight traficLight1 (D8,D7, D6, 0, 0, 0, (long[]){1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000});

void setup()
{
  traficLight.setup(millis());
  traficLight1.setup(millis()+5000);
}

void loop()
{
  traficLight.update(millis());
  traficLight1.update(millis());

}

