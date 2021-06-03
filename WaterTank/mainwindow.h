#pragma once

#include <QMainWindow>
#include "tank.h"
#include "pump.h"
#include "valve.h"
#include "heater.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    Tank tank;

    Pump pump;

    Valve  valve;

    Heater heater;

private slots:

   // Tank Slots
    void setMaxLevel();
    void setInitLevel();
    void setMaxTemperature();
    void setInitTemperature();
    void setBaseRadius();
    void setEnviromentalTemp();

    //Pump Slots
    void setMaxFlow();
    void setInitPumpTemperature();

    //Valve slots
    void setValveState();
    void setExitRadius();
    void setExitConnection();

    //Heater slot
    void setHeaterState();
    void setHeaterTemp();


private:
    void connectQtElements();
    void setDrawing();

};
