#include "valve.h"

Valve::Valve()
{
    state = VALVE_CLOSE;
    exitRadius = 0;
    exitConnection = 0;
}

Valve::Valve(unsigned int exitRadius, unsigned int exitConnection)
{
    state = VALVE_CLOSE;
    this->exitRadius = exitRadius;
    this->exitConnection = exitConnection;
}

unsigned int Valve::getExitRadius() const
{
    return exitRadius;
}

unsigned int Valve::getExitConnection() const
{
    return exitConnection;
}
