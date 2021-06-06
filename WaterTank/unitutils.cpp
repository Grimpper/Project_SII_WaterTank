#include "unitutils.h"

float UnitUtils::getInCubicMeters(float liters)
{
    return liters * 0.001;
}

float UnitUtils::getInMeters(float centimeters)
{
    return centimeters * 0.01;
}

float UnitUtils::getInLiters(float cubicMeters)
{
    return cubicMeters * 1000;
}
