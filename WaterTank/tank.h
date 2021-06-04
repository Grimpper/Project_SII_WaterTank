#pragma once

class Tank
{
public:
    Tank();
    Tank(unsigned int maxLevel, unsigned int initLevel, int maxTemperature,
         int initTemperature, unsigned int baseRadius, int enviromentTemp);

    unsigned int getLevel() const;
    void setLevel(unsigned int value);

    int getTemperature() const;
    void setTemperature(int value);

    bool getOverheat() const;
    bool getOverflow() const;

    unsigned int getInitLevel() const;

    unsigned int getMaxLevel() const;

    unsigned int getBaseRadius() const;

    int getInitTemperature() const;

    int getMaxTemperature() const;

    int getEnviromentTemp() const;

private:
    unsigned int initLevel, maxLevel, level;
    unsigned int baseRadius;

    int initTemperature, maxTemperature, enviromentTemp, temperature;

    bool overheat, overflow;
};
