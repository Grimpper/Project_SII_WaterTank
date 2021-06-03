#pragma once

class Heater
{
public:
   Heater();

    int heaterTemp;

    enum EnumHeater
    {
       heater_ON,
       heater_OFF
    };

    int getHeaterTemp() const;
    void setHeaterTemp(int value);
    void setHeaterOn();
    void setHeaterOff();


    EnumHeater getHeaterState() const;

private:

    EnumHeater heaterState;

};
