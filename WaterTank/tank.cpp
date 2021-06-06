#include <QDebug>
#include <math.h>
#include "tank.h"

Tank::Tank()
{
    level = 0;
    liquidHeight = 0;
    liquidSurface = 0;
    maxLevel = 0;
    baseRadius = 0;
    temperature = 0;
    maxTemperature = 0;
    enviromentTemp = 0;
    overflow = 0;
    overheat = 0;
}

Tank::Tank(float maxLevel, float level, float maxTemperature,
           float temperature, float baseRadius, float enviromentTemp)
    : maxLevel(maxLevel), baseRadius(baseRadius), maxTemperature(maxTemperature), enviromentTemp(enviromentTemp)
{
    liquidHeight = 0;
    liquidSurface = 0;
    overflow = 0;
    overheat = 0;
    setLevel(level);
    setTemperature(temperature);

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

float Tank::getLevel() const
{
    return level;
}

void Tank::setLevel(float value)
{
    if (value > maxLevel)
        level = maxLevel;
    else if (value < 0)
        level = 0;
    else
        level = value;

    liquidHeight = level / (M_PI * pow(getBaseRadius(), 2));
    liquidSurface = 2 * M_PI * getBaseRadius() * liquidHeight;

    if (level < maxLevel)
        overflow = false;
    else
        overflow = true;

#if WT_DEBUG == 1
    QString str = "Tank level:\n" + QString::number(level) + "\n";
    qDebug().noquote() << str;
#endif
}

float Tank::getTemperature() const
{
    return temperature;
}

void Tank::setTemperature(float value)
{
    temperature = value;

    if (temperature > maxTemperature)
        overheat = true;


#if WT_DEBUG == 1
    QString str = "Tank temperature:\n" + QString::number(temperature) + "\n";
    qDebug().noquote() << str;
#endif
}

bool Tank::getOverheat() const
{
    return overheat;
}

bool Tank::getOverflow() const
{
    return overflow;
}

float Tank::getMaxLevel() const
{
    return maxLevel;
}

float Tank::getBaseRadius() const
{
    return baseRadius;
}

float Tank::getMaxTemperature() const
{
    return maxTemperature;
}

float Tank::getEnviromentTemp() const
{
    return enviromentTemp;
}

float Tank::getLiquidHeight() const
{
    return liquidHeight;
}

float Tank::getLiquidSurface() const
{
    return liquidSurface;
}
