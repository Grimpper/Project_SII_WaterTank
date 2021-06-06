#include <QDebug>
#include <math.h>
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

#if WT_DEBUG == 1
    QString str = "Tank initialized with:\n";
    str += "maxLevel = " + QString::number(maxLevel) + "\n";
    str += "level = " + QString::number(level) + "\n";
    str += "maxTemperature = " + QString::number(maxTemperature) + "\n";
    str += "temperature = " + QString::number(temperature) + "\n";
    str += "baseRadius = " + QString::number(baseRadius) + "\n";
    str += "enviromentTemp = " + QString::number(enviromentTemp) + "\n";

    qDebug().noquote() << str;
#endif
}

unsigned int Tank::getLevel() const
{
    return level;
}

void Tank::setLevel(unsigned int value)
{
    level = value;

    liquidHeight = level / (pow(M_PI, 2)* getBaseRadius());
    liquidSurface = 2 * M_PI * liquidHeight;

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

unsigned int Tank::getLiquidHeight() const
{
    return liquidHeight;
}

unsigned int Tank::getLiquidSurface() const
{
    return liquidSurface;
}
