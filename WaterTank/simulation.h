#pragma once

#include "tank.h"
#include "pump.h"
#include "valve.h"
#include "heater.h"

class Simulation
{
public:
    Simulation(Tank*& tank, Pump*& pump, Valve*& valve, Heater*& heater, float step, float gravity = 9.8);

    Tank* tank;
    Pump* pump;
    Valve* valve;
    Heater* heater;

    void computeStep();

private:
    float entranceVolume, exitVolume, outputValveFlow;
    float step, gravity;

    void computeEntranceVolume();

    void computeOutputFlow();
    void computeExitVolume();

    void computeTankLevel();

    float computeCoolingConstant();

    void computeTankTemperature();
};

