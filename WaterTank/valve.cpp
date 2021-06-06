#include "valve.h"
#include <QDebug>

Valve::Valve()
{
    state = VALVE_CLOSE;
    exitRadius = 0;
    exitConnection = 0;
}

Valve::Valve(float exitRadius, float exitConnection)
{
    state = VALVE_CLOSE;
    this->exitRadius = exitRadius;
    this->exitConnection = exitConnection;

#if WT_DEBUG == 1
    QString str = "Valve initialized with:\n";
    str += "exitRadius = " + QString::number(exitRadius) + "\n";
    str += "exitConnection = " + QString::number(exitConnection) + "\n";

    qDebug().noquote() << str;
#endif
}

float Valve::getExitRadius() const
{
    return exitRadius;
}

float Valve::getExitConnection() const
{
    return exitConnection;
}
