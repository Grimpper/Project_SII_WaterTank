#pragma once

#include <QMainWindow>
#include "tank.h"
#include "pump.h"

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

private slots:

   // Tank Slots
    void setMaxLevel();
    void setInitLevel();
    void setMaxTemperature();
    void setInitTemperature();
    void setBaseRadius();

    //Pump Slots
    void setMaxFlow();
    void setInitPumpTemperature();

private:
    void connectQtElements();
    void setDrawing();

};
