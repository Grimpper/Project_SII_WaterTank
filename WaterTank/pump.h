#ifndef PUMP_H
#define PUMP_H


class Pump
{
public:
    Pump();

    unsigned int  maxFlow;
    int initTemperaturePump;

    unsigned int getFlow() const;
    void setFlow(unsigned int value);

    int getPumpTemperature() const;
    void setPumpTemperature(int value);

private:
    unsigned int flow;
    int pumpTemperature;
};

#endif // PUMP_H
