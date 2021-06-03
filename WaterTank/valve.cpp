#include "valve.h"

Valve::Valve()
{
    exitRadius = 0;
    exitConnection = 0;

}

void Valve::setValveOpen()
{
    valveState = valve_OPEN;
}

void Valve::setValveClose()
{
    valveState = valve_CLOSE;
}

Valve::EnumValve Valve::getValveState() const
{
    return valveState;
}
