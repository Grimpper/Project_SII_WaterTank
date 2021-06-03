#include "heater.h"

Heater::Heater()
{
    heaterTemp = 0 ;
}

int Heater::getHeaterTemp() const
{
    return heaterTemp;
}

void Heater::setHeaterTemp(int value)
{
    heaterTemp = value;
}

void Heater::setHeaterOn()
{
    heaterState = heater_ON;
}

void Heater::setHeaterOff()
{
    heaterState = heater_OFF;
}

Heater::EnumHeater Heater::getHeaterState() const
{
    return heaterState;
}
