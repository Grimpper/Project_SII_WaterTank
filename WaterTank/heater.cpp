#include "heater.h"
#include <QDebug>

Heater::Heater()
{
    state = HEATER_OFF;
    temp = 0 ;
}

Heater::Heater(float temp)
{
    state = HEATER_OFF;
    this->temp = temp;

#if WT_DEBUG == 1
    QString str = "Heater initialized with:\n";
    str += "initTemp = " + QString::number(temp) + "\n";
    qDebug().noquote() << str;
#endif
}
