#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

    Tank* tank;

    Pump* pump;

private slots:

   // Slots Tank
    void setMaxLevel();
    void setInitLevel();

    void setMaxTemperature();
    void setInitTemperature();

    void setBaseRadius();

    //Slots Pump

    void setMaxFlow();
  //  void setInitFlow(); (not necessary)??

    void setInitPumpTemperature();

};
#endif // MAINWINDOW_H
