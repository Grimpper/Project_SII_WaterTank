#pragma once

class Pump
{
public:
    Pump();
    Pump(float maxFlow, float pumpTemperature);

    float getFlow() const;
    void setFlow(float value);

    float getPumpTemperature() const;
    void setPumpTemperature(float value);

    float getMaxFlow() const;

private:
    float maxFlow, flow;
    float pumpTemperature;
};
