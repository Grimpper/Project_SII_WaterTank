#include "simulation.h"
#include <math.h>
#include <QString>
#include <QDebug>

Simulation::Simulation(Tank*& tank, Pump*& pump, Valve*& valve, Heater*& heater, float step, float gravity)
    : tank(tank), pump(pump), valve(valve), heater(heater), step(step), gravity(gravity)
{
#if WT_DEBUG == 1
    QString str = "Simulation initialized with:\n";
    str += "step = " + QString::number(step) + "\n";
    str += "gravity = " + QString::number(gravity) + "\n";

    qDebug().noquote() << str;
#endif
}

void Simulation::computeStep()
{
    computeEntranceVolume();

    computeOutputFlow();
    computeExitVolume();

    computeTankLevel();
    computeTankTemperature();
}

void Simulation::computeEntranceVolume()
{
    entranceVolume = pump->getFlow() * step;
}

void Simulation::computeOutputFlow()
{
    float heightDifference =  tank->getLiquidHeight() - valve->getExitConnection();
    float output = valve->getExitRadius() * 2 * M_PI * sqrt(2 * gravity * heightDifference);

    outputValveFlow = output > 0 ? output : 0;
}

void Simulation::computeExitVolume()
{
    exitVolume = outputValveFlow * step;
}

void Simulation::computeTankLevel()
{
    tank->setLevel(tank->getLevel() + entranceVolume - exitVolume);

#if WT_DEBUG == 1
    QString str = "entranceVolume = " + QString::number(entranceVolume) + "\n";
    str += "exitVolume = " + QString::number(exitVolume) + "\n";

    qDebug().noquote() << str;
#endif
}

float Simulation::computeCoolingConstant()
{
    return 1000 * tank->getLiquidSurface() / (tank->getLevel() * 4.183);
}

void Simulation::computeTankTemperature()
{
    float weightedCoefficient = entranceVolume * pump->getPumpTemperature() + tank->getLevel() * tank->getTemperature();
    float weightsSum = entranceVolume + tank->getLevel();
    float entranceTempDelta = weightedCoefficient / weightsSum;

    float coolingConstant = computeCoolingConstant();
    float ambientTempDelta = -coolingConstant * (tank->getTemperature() - tank->getEnviromentTemp());
    float heaterTempDelta =  -coolingConstant * (tank->getTemperature() - heater->temp);

    float totalTempDelta = step * (entranceTempDelta + ambientTempDelta + heaterTempDelta);

    tank->setTemperature(tank->getTemperature() + totalTempDelta);
}
