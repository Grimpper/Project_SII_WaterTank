#include "tank.h"

Tank::Tank()
{
    initLevel = 0;
    maxLevel = 0;
    baseRadius = 0;
    initTemperature = 0;
    maxTemperature = 0;
    enviromentalTemp = 0;
}

unsigned int Tank::getLevel() const
{
    return level;
}

void Tank::setLevel(unsigned int value)
{
    level = value;
}

int Tank::getTemperature() const
{
    return temperature;
}

void Tank::setTemperature(int value)
{
    temperature = value;
}
