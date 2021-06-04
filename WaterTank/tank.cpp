#include "tank.h"

Tank::Tank()
{
    level = 0;
    maxLevel = 0;
    baseRadius = 0;
    temperature = 0;
    maxTemperature = 0;
    enviromentTemp = 0;
    overflow = 0;
    overheat = 0;
}

Tank::Tank(unsigned int maxLevel, unsigned int level, int maxTemperature,
           int temperature, unsigned int baseRadius, int enviromentTemp)
{
    this->setLevel(level);
    this->maxLevel = maxLevel;
    this->baseRadius = baseRadius;
    this->setTemperature(temperature);
    this->maxTemperature = maxTemperature;
    this->enviromentTemp = enviromentTemp;
    this->overflow = 0;
    this->overheat = 0;
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

unsigned int Tank::getMaxLevel() const
{
    return maxLevel;
}

unsigned int Tank::getBaseRadius() const
{
    return baseRadius;
}

int Tank::getMaxTemperature() const
{
    return maxTemperature;
}

int Tank::getEnviromentTemp() const
{
    return enviromentTemp;
}
