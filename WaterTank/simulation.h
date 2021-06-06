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

    void setStep(float value);

private:
    float entranceVolume, exitVolume, outputValveFlow;
    float step, gravity, previousTemp;

    void computeEntranceVolume();

    void computeOutputFlow();
    void computeExitVolume();

    void computeTankLevel();

    float computeCoolingConstant();

    void computeTankTemperature();
};

