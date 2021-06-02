#ifndef VALVE_H
#define VALVE_H


class valve
{
public:
    valve();

    unsigned int exitRadius;
    unsigned int exitConnection;

    enum EnumValve
    {
       valve_OPEN,
       valve_CLOSE
    };

    EnumValve readValveState() const;

};

#endif // VALVE_H
