#include "pump.h"

Pump::Pump()
{

}

unsigned int Pump::getFlow() const
{
    return flow;
}

void Pump::setFlow(unsigned int value)
{
    flow = value;
}

int Pump::getPumpTemperature() const
{
    return pumpTemperature;
}

void Pump::setPumpTemperature(int value)
{
    pumpTemperature = value;
}
