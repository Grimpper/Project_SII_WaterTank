#ifndef TANK_H
#define TANK_H


class Tank
{
public:
    Tank();

    unsigned int initLevel, maxLevel;
    unsigned int baseRadius;

    int initTemperature, maxTemperature;

    unsigned int getLevel() const;
    int getTemperature() const;

private:
    unsigned int level;
    int temperature;
};

#endif // TANK_H
