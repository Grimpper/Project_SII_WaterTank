#include "heater.h"

Heater::Heater()
{
    state = HEATER_OFF;
    temp = 0 ;
}

Heater::Heater(int initTemp)
{
    state = HEATER_OFF;
    this->temp = initTemp;
}
