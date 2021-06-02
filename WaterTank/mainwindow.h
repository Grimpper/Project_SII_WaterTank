#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tank.h"

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

private slots:
    void setMaxLevel();
    void setInitLevel();

    void setMaxTemperature();
    void setInitTemperature();

    void setBaseRadius();

private:
    void connectQtElements();
    void setDrawing();

};
#endif // MAINWINDOW_H
