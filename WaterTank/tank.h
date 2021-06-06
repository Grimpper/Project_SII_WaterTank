#pragma once

class Tank
{
public:
    Tank();
    Tank(unsigned int maxLevel, unsigned int level, int maxTemperature,
         int temperature, unsigned int baseRadius, int enviromentTemp);

    float getLevel() const;
    void setLevel(float value);

    int getTemperature() const;
    void setTemperature(int value);

    bool getOverheat() const;
    bool getOverflow() const;

    unsigned int getMaxLevel() const;

    unsigned int getBaseRadius() const;

    int getMaxTemperature() const;

    int getEnviromentTemp() const;

    unsigned int getLiquidHeight() const;
    unsigned int getLiquidSurface() const;

private:
    unsigned int maxLevel, liquidHeight;
    float level;
    unsigned int baseRadius, liquidSurface;

    int maxTemperature, enviromentTemp, temperature;

    bool overheat, overflow;
};
