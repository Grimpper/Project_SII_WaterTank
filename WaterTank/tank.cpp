#include "tank.h"

Tank::Tank()
{
    initLevel = 0;
    maxLevel = 0;
    baseRadius = 0;
    initTemperature = 0;
    maxTemperature = 0;
    overflow = 0;
    overheat = 0;
}

unsigned int Tank::getLevel() const
{
    return level;
}

void Tank::setLevel(unsigned int value)
{
    level = value;

    if (level > maxLevel)
        overflow = true;
}

int Tank::getTemperature() const
{
    return temperature;
}

void Tank::setTemperature(int value)
{
    temperature = value;

    if (temperature > maxTemperature)
        overheat = true;
}

bool Tank::getOverheat() const
{
    return overheat;
}

bool Tank::getOverflow() const
{
    return overflow;
}
