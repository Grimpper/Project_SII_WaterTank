#pragma once

class Tank
{
public:
    Tank();
    Tank(unsigned int maxLevel, unsigned int level, int maxTemperature,
         int temperature, unsigned int baseRadius, int enviromentTemp);

    unsigned int getLevel() const;
    void setLevel(unsigned int value);

    int getTemperature() const;
    void setTemperature(int value);

    bool getOverheat() const;
    bool getOverflow() const;

    unsigned int getMaxLevel() const;

    unsigned int getBaseRadius() const;

    int getMaxTemperature() const;

    int getEnviromentTemp() const;

private:
    unsigned int maxLevel, level;
    unsigned int baseRadius;

    int maxTemperature, enviromentTemp, temperature;

    bool overheat, overflow;
};
