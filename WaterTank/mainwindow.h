#pragma once

#include <QMainWindow>
#include <QTimer>
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
    QTimer* drawTimer;

    Tank tank;

    Pump pump;

    Valve  valve;

    Heater heater;

private slots:
    // Timer
    void setDrawing();

   // Tank
    void setMaxLevel();
    void setInitLevel();
    void setMaxTemperature();
    void setInitTemperature();
    void setBaseRadius();
    void setEnviromentalTemp();

    //Pump
    void setMaxFlow();
    void setInitPumpTemperature();

    //Valve
    void setValveState();
    void setExitRadius();
    void setExitConnection();

    //Heater
    void setHeaterState();
    void setHeaterTemp();

private:
    void connectQtElements();

};
