#pragma once

class Heater
{
public:
   Heater();
   Heater(int initHeaterTemp);

    enum EnumHeater
    {
      HEATER_OFF,
      HEATER_ON
    } state;

    int temp;
int getTempHeater() const;
};
