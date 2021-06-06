#include "simulation.h"
#include <math.h>

Simulation::Simulation(Tank*& tank, Pump*& pump, Valve*& valve, Heater*& heater, float gravity)
    : tank(tank), pump(pump), valve(valve), heater(heater), gravity(gravity)
{

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
}

float Simulation::computeCoolingConstant()
{
    return 1000 * tank->getLiquidSurface() / (0.997 * tank->getLevel() * 4.183);
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
