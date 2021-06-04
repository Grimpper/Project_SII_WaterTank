#pragma once

class Valve
{
public:
    Valve();
    Valve(unsigned int exitRadius, unsigned int exitConnection);

    enum EnumValve
    {
       VALVE_CLOSE,
       VALVE_OPEN
    } state;

    unsigned int getExitRadius() const;

    unsigned int getExitConnection() const;

private:
    unsigned int exitRadius, exitConnection;
};

