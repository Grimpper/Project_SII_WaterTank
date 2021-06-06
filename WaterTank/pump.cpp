#include "pump.h"
#include <QDebug>

Pump::Pump()
{
    maxFlow = 0;
    pumpTemperature = 0;
    flow = 0;
}

Pump::Pump(float maxFlow, float pumpTemperature)
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

float Pump::getFlow() const
{
    return flow;
}

void Pump::setFlow(float value)
{
    if (value > maxFlow)
        flow = maxFlow;
    else
        flow = value;
}

float Pump::getPumpTemperature() const
{
    return pumpTemperature;
}

void Pump::setPumpTemperature(float value)
{
    pumpTemperature = value;
}

float Pump::getMaxFlow() const
{
    return maxFlow;
}
