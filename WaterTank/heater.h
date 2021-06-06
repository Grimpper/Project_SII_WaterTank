#pragma once

class Heater
{
public:
   Heater();
   Heater(float initHeaterTemp);

    enum EnumHeater
    {
      HEATER_OFF,
      HEATER_ON
    } state;

    float temp;
};
