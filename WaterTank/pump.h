#pragma once

class Pump
{
public:
    Pump();
    Pump(unsigned int maxFlow, int initTemperaturePump);

    unsigned int getFlow() const;
    void setFlow(unsigned int value);

    int getPumpTemperature() const;
    void setPumpTemperature(int value);

    unsigned int getMaxFlow() const;

    int getInitTemperaturePump() const;

private:
    unsigned int maxFlow, flow;
    int initTemperaturePump, pumpTemperature;
};
