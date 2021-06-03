#pragma once

class Valve
{
public:
    Valve();

    unsigned int exitRadius;
    unsigned int exitConnection;

    enum EnumValve
    {
       valve_OPEN,
       valve_CLOSE
    };

    void setValveOpen();
    void setValveClose();


    EnumValve getValveState() const;

private:

    EnumValve valveState;


};

