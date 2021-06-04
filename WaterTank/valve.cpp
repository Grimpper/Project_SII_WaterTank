#include "valve.h"
#include <QDebug>

Valve::Valve()
{
    state = VALVE_CLOSE;
    exitRadius = 0;
    exitConnection = 0;
}

Valve::Valve(unsigned int exitRadius, unsigned int exitConnection)
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

unsigned int Valve::getExitRadius() const
{
    return exitRadius;
}

unsigned int Valve::getExitConnection() const
{
    return exitConnection;
}
