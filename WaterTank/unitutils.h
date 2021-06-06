#pragma once

class UnitUtils
{
public:
    UnitUtils() = delete;

    static float getInCubicMeters(float liters);
    static float getInMeters(float centimeters);

    static float getInLiters(float cubicMeters);
};
