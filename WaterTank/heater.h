#ifndef HEATER_H
#define HEATER_H


class heater
{
public:
    heater();

    int heaterTemp;
    enum EnumHeater
    {
       heater_ON,
       heater_OFF
    };

    EnumHeater readHeaterState() const;



};

#endif // HEATER_H
