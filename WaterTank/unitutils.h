#pragma once

class UnitUtils
{
public:
    UnitUtils() = delete;

    static float getInCubicMeters(float liters);
    static float getInLiters(float cubicMeters);

    static float getInMeters(float centimeters);

    static float getInKelvin(float celsius);
    static float getInCelsius(float kelvin);
};
