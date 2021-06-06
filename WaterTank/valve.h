#pragma once

class Valve
{
public:
    Valve();
    Valve(float exitRadius, float exitConnection);

    enum EnumValve
    {
       VALVE_CLOSE,
       VALVE_OPEN
    } state;

    float getExitRadius() const;

    float getExitConnection() const;

private:
    float exitRadius, exitConnection;
};

