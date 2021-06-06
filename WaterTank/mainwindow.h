#pragma once

#include <QMainWindow>
#include <QTimer>
#include <QElapsedTimer>
#include <QSignalMapper>
#include "tank.h"
#include "pump.h"
#include "valve.h"
#include "heater.h"
#include "simulation.h"

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
    QSignalMapper* signalMapper;

    QTimer simulationTimer;
    const unsigned int simulationIntervalMS = 100;

    QElapsedTimer elapsedTimer;
    int displayTimeUntilLastStop = 0;

    enum EnumSimStep
    {
        x1 = 1,
        x2 = 2,
        x5 = 5,
        x10 = 10
    } simStep = EnumSimStep::x1;

    Tank* tank = nullptr;

    Pump* pump = nullptr;

    Valve*  valve = nullptr;

    Heater* heater = nullptr;

    Simulation* simulation = nullptr;

    void connectQtElements();
    bool checkPointerInit();
    void deletePointerMembers();
    void setEnableConfig(bool state);
    float getTimestep();

    void updateDrawing();

private slots:
    void sim();

    void start();
    void pause();
    void reset();

    void setTimestep(int);
    void flowChanged(int);
    void tempChanged(int);

    void setValveState();
    void setHeaterState();

    void updateExitAreaLabel(int);
    void updateBaseAreaLabel(int);

    void safetyHandler();

};
