#include "tank.h"

Tank::Tank()
    : initLevel(0), maxLevel(0), baseRadius(0), initTemperature(0), maxTemperature(0)
{
}

unsigned int Tank::getLevel() const
{
    return level;
}

int Tank::getTemperature() const
{
    return temperature;
}
