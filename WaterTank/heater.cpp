#include "heater.h"
#include <QDebug>

Heater::Heater()
{
    state = HEATER_OFF;
    temp = 0 ;
}

Heater::Heater(int initTemp)
{
    state = HEATER_OFF;
    this->temp = initTemp;

#if WT_DEBUG == 1
    QString str = "Heater initialized with:\n";
    str += "initTemp = " + QString::number(initTemp) + "\n";
    qDebug().noquote() << str;
#endif
}
