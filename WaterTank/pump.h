#pragma once

class Pump
{
public:
    Pump();
    Pump(unsigned int maxFlow, int pumpTemperature);

    unsigned int getFlow() const;
    void setFlow(unsigned int value);

    int getPumpTemperature() const;
    void setPumpTemperature(int value);

    unsigned int getMaxFlow() const;

private:
    unsigned int maxFlow, flow;
    int pumpTemperature;
};
