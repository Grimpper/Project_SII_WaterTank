#include "pump.h"

Pump::Pump()
{
    maxFlow = 0;
    initTemperaturePump = 0;
    flow = 0;
    pumpTemperature = 0;
}

Pump::Pump(unsigned int maxFlow, int initTemperaturePump)
{
    this->maxFlow = maxFlow;
    this->initTemperaturePump = initTemperaturePump;
    flow = 0;
    pumpTemperature = 0;
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

unsigned int Pump::getMaxFlow() const
{
    return maxFlow;
}

int Pump::getInitTemperaturePump() const
{
    return initTemperaturePump;
}
