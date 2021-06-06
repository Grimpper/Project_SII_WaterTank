#pragma once

#include "tank.h"
#include "pump.h"
#include "valve.h"
#include "heater.h"

class Simulation
{
public:
    Simulation(Tank*& tank, Pump*& pump, Valve*& valve, Heater*& heater, float gravity = 9.8);

    Tank* tank;
    Pump* pump;
    Valve* valve;
    Heater* heater;

    float gravity;

    enum SimulationStep
    {
        x1 = 1,
        x2 = 2,
        x5 = 5,
        x10 = 10
    } step;

    void computeStep();

private:
    float entranceVolume, exitVolume, outputValveFlow;

    void computeEntranceVolume();

    void computeOutputFlow();
    void computeExitVolume();

    void computeTankLevel();

    float computeCoolingConstant();

    void computeTankTemperature();
};

