#pragma once

class Tank
{
public:
    Tank();

    unsigned int initLevel, maxLevel;
    unsigned int baseRadius;

    int initTemperature, maxTemperature, enviromentalTemp;

    unsigned int getLevel() const;
    void setLevel(unsigned int value);

    int getTemperature() const;
    void setTemperature(int value);

    bool getOverheat() const;
    bool getOverflow() const;

private:
    unsigned int level;
    int temperature;

    bool overheat, overflow;
};
