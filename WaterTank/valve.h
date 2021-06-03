#pragma once

class Valve
{
public:
    Valve();

    enum EnumValve
    {
       VALVE_CLOSE,
       VALVE_OPEN
    } state;

    unsigned int exitRadius;
    unsigned int exitConnection;
};

