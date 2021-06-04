#include "heater.h"

Heater::Heater()
{
    state = HEATER_OFF;
    initTemp = 0;
    temp = 0 ;
}

Heater::Heater(int initTemp)
{
    state = HEATER_OFF;
    this->initTemp = initTemp;
    temp = 0 ;
}

int Heater::getInitHeaterTemp() const
{
    return initTemp;
}
