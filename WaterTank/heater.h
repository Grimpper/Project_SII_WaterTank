#pragma once

class Heater
{
public:
   Heater();

    enum EnumHeater
    {
      HEATER_OFF,
      HEATER_ON
    } state;

    int heaterTemp;
};
