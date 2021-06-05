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

    Tank* tank = nullptr;

    Pump* pump = nullptr;

    Valve*  valve = nullptr;

    Heater* heater = nullptr;

    void connectQtElements();
    void deletePointerMembers();
    void setEnableConfig(bool state);

private slots:
    void setDrawing();

    void start();
    void pause();
    void reset();

    void setValveState();
    void setHeaterState();

    void updateExitAreaLabel(int);
    void updateBaseAreaLabel(int);

};
