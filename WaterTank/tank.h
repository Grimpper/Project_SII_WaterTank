#pragma once

class Tank
{
public:
    Tank();
    Tank(float maxLevel, float level, float maxTemperature,
         float temperature, float baseRadius, float enviromentTemp, const float overflowThreshold, const float overheatThreshold);

    float getLevel() const;
    void setLevel(float value);

    float getTemperature() const;
    void setTemperature(float value);

    bool getOverheat() const;
    bool getOverflow() const;

    float getMaxLevel() const;

    float getBaseRadius() const;

    float getMaxTemperature() const;

    float getEnviromentTemp() const;

    float getLiquidHeight() const;
    float getLiquidSurface() const;

private:
    float maxLevel, level, liquidHeight, liquidSurface, baseRadius;

    float maxTemperature, enviromentTemp, temperature;

    const float overflowThreshold, overheatThreshold;

    bool overheat, overflow;
};
