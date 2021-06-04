#include "pump.h"
#include <QDebug>

Pump::Pump()
{
    maxFlow = 0;
    pumpTemperature = 0;
    flow = 0;
}

Pump::Pump(unsigned int maxFlow, int pumpTemperature)
{
    this->maxFlow = maxFlow;
    this->pumpTemperature = pumpTemperature;
    flow = 0;

#if WT_DEBUG == 1
    QString str = "Pump initialized with:\n";
    str += "maxFlow = " + QString::number(maxFlow) + "\n";
    str += "pumpTemperature = " + QString::number(pumpTemperature) + "\n";

    qDebug().noquote() << str;
#endif
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
