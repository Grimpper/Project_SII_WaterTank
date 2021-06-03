#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "math.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->label_BaseArea_Value->setText(QString::number(2 * M_PI * ui->spinBox_BaseRadius->value(), 'f', 2) + " m^2");
    ui->groupBox_GUI->setStyleSheet("background-color: white");

    ui->label_ExitArea_Value->setText(QString::number(2 * M_PI * ui->spinBox_ExitRadius->value(), 'f', 2) + " m^2");


    connectQtElements();
    setDrawing();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectQtElements()
{
    connect(ui->spinBox_MaxLevel, SIGNAL(valueChanged(int)), this, SLOT(setMaxLevel()));
    connect(ui->spinBox_InitLevel, SIGNAL(valueChanged(int)), this, SLOT(setInitLevel()));
    connect(ui->spinBox_MaxTemp, SIGNAL(valueChanged(int)), this, SLOT(setMaxTemperature()));
    connect(ui->spinBox_InitTemp, SIGNAL(valueChanged(int)), this, SLOT(setInitTemperature()));
    connect(ui->spinBox_BaseRadius, SIGNAL(valueChanged(int)), this, SLOT(setBaseRadius()));
    connect(ui->spinBox_EnviromentalTemp, SIGNAL(valueChanged(int)), this, SLOT(setEnviromentalTemp()));

    connect(ui->spinBox_EntranceFlow, SIGNAL(valueChanged(int)),this, SLOT (setMaxFlow()));
    connect(ui->spinBox_EntranceTemp, SIGNAL(valueChanged(int)),this, SLOT(setInitPumpTemperature()));

    connect(ui->spinBox_ExitRadius, SIGNAL(valueChanged(int)), this, SLOT(setExitRadius()));
    connect(ui->spinBox_ExitConnection, SIGNAL(valueChanged(int)), this, SLOT(setExitConnection()));
    connect(ui->pushButton_Pump_Open, SIGNAL(clicked()), this, SLOT(setValveOpen()));
    connect(ui->pushButton_Pump_Close, SIGNAL(clicked()), this, SLOT(setValveClose()));

    connect(ui->spinBox_HeaterTemp, SIGNAL(valueChanged(int)), this, SLOT(setHeaterTemp()));
    connect(ui->pushButton_Heater_On, SIGNAL(clicked()), this, SLOT(setHeaterOn()));
    connect(ui->pushButton_Heater_Off, SIGNAL(clicked()), this, SLOT(setHeaterOff()));

}

void MainWindow::setDrawing()
{
    int level = tank.getLevel();
    int temperature = tank.getTemperature();
    //double pump = ;
/*
    EnumHeater heater = readHeaterState();
    EnumValve valve = readValveState();
    EnumOverHeat overHeat = readOverHeat();
    EnumOverFlow overFlow = readOverFlow();
*/

    double imageWhiteMaskHeight = level * (10 - 305.0) / 8000.0 + 305;
    double imageWaterFlowHeight = level * (10 - 305.0) / 8000.0 + 305;
    double imageThermometerMaskHeight = (temperature + 20) * -137.0 / (120.0 + 20.0) + 137.0;

    if(imageWhiteMaskHeight < 10){
            imageWhiteMaskHeight = 10;
    } else if (imageWhiteMaskHeight > 305){
            imageWhiteMaskHeight = 305;
    }

    if(imageWaterFlowHeight < 10){
            imageWaterFlowHeight = 10;
    } else if (imageWaterFlowHeight > 305){
            imageWaterFlowHeight = 305;
    }

    if(imageThermometerMaskHeight < 0){
            imageThermometerMaskHeight = 0;
    } else if (imageThermometerMaskHeight > 137){
            imageThermometerMaskHeight = 137;
    }

    ui->ImageWhiteMask->resize(ui->ImageWhiteMask->size().width(), imageWhiteMaskHeight);
    ui->ImageWaterFlow->resize(ui->ImageWaterFlow->size().width(), imageWaterFlowHeight);
    ui->ImageThermometerMask->resize(ui->ImageThermometerMask->size().width(), imageThermometerMaskHeight);


/*
    if(pump > 0){
            FormUser->ImageWaterFlow->Visible = true;
            FormUser->ImageWhiteMask->Visible = false;
    } else {
            FormUser->ImageWaterFlow->Visible = false;
            FormUser->ImageWhiteMask->Visible = true;
    }

    if(valve == Valve_OPEN){
            FormUser->ImageTankValveOpen->Visible = true;
            FormUser->ImageTankValveClose->Visible = false;
    } else {
            FormUser->ImageTankValveOpen->Visible = false;
            FormUser->ImageTankValveClose->Visible = true;
    }

    if(heater == Heater_ON){
            FormUser->ImageFlame->Visible = true;
    } else {
            FormUser->ImageFlame->Visible = false;
    }

    if(overHeat == OverHeat_YES){
            FormUser->ImageOverHeat->Visible = true;
            FormUser->LabelOverHeat->Visible = true;
    } else {
            FormUser->ImageOverHeat->Visible = false;
            FormUser->LabelOverHeat->Visible = false;
    }

    if(overFlow == OverFlow_YES){
            FormUser->ImageOverFlow->Visible = true;
            FormUser->LabelOverFlow->Visible = true;
    } else {
            FormUser->ImageOverFlow->Visible = false;
            FormUser->LabelOverFlow->Visible = false;
    }
*/
}

void MainWindow::setMaxLevel()
{
    tank.maxLevel = ui->spinBox_MaxLevel->value();

#if WT_DEBUG == 1
    qDebug() << "maxLevelSet = " + QString::number(tank.maxLevel);
#endif
}

void MainWindow::setInitLevel()
{
    tank.initLevel = ui->spinBox_InitLevel->value();

#if WT_DEBUG == 1
    qDebug() << "initLevel = " + QString::number(tank.initLevel);
#endif
}

void MainWindow::setMaxTemperature()
{
    tank.maxTemperature = ui->spinBox_MaxTemp->value();

#if WT_DEBUG == 1
    qDebug() << "maxTemperature = " + QString::number(tank.maxTemperature);
#endif
}

void MainWindow::setInitTemperature()
{
    tank.initTemperature = ui->spinBox_InitTemp->value();

#if WT_DEBUG == 1
    qDebug() << "initTemperature = " + QString::number(tank.initTemperature);
#endif
}

void MainWindow::setBaseRadius()
{
    tank.baseRadius = ui->spinBox_BaseRadius->value();
    ui->label_BaseArea_Value->setText(QString::number(2 * M_PI * tank.baseRadius, 'f', 2) + " m^2");

#if WT_DEBUG == 1
    qDebug() << "baseRadius = " + QString::number(tank.baseRadius);
#endif
}

void MainWindow::setEnviromentalTemp()
{
    tank.enviromentalTemp = ui->spinBox_EnviromentalTemp->value();

#if WT_DEBUG == 1
    qDebug() << "enviromentalTemp = " + QString::number(tank.enviromentalTemp);
#endif
}


void MainWindow::setMaxFlow()
{
    pump.maxFlow = ui->spinBox_EntranceFlow->value();

#if WT_DEBUG == 1
    qDebug() << "maxFlow = " + QString::number(pump.maxFlow);
#endif
}


void MainWindow::setInitPumpTemperature()
{
    pump.initTemperaturePump = ui->spinBox_EntranceTemp->value();

#if WT_DEBUG == 1
    qDebug() << "initTemperaturePump = " + QString::number(pump.initTemperaturePump);
#endif
}
void MainWindow::setExitRadius()
{
    valve.exitRadius = ui->spinBox_ExitRadius->value();
    ui->label_ExitArea_Value->setText(QString::number(2 * M_PI * valve.exitRadius, 'f', 2) + " m^2");

#if WT_DEBUG == 1
    qDebug() << "exitRadius = " + QString::number(valve.exitRadius);
#endif
}

void MainWindow::setExitConnection()
{
    valve.exitConnection = ui->spinBox_ExitConnection->value();

#if WT_DEBUG == 1
    qDebug() << "exitConnection = " + QString::number(valve.exitConnection);
#endif
}
void MainWindow::setValveOpen()
{
    ui->label_ValveState->setText("OPEN");


#if WT_DEBUG == 1
    qDebug() << "Valve Open ";
#endif
}

void MainWindow::setValveClose()
{
    ui->label_ValveState->setText("CLOSE");

#if WT_DEBUG == 1
    qDebug() << "Valve close";
#endif
}


void MainWindow::setHeaterTemp()
{
    heater.heaterTemp = ui->spinBox_HeaterTemp->value();

#if WT_DEBUG == 1
    qDebug() << "heaterTemp = " + QString::number(heater.heaterTemp);
#endif
}


void MainWindow::setHeaterOn()
{
    ui->label_HeaterState->setText("ON");

#if WT_DEBUG == 1
    qDebug() << "Heater On ";
#endif
}

void MainWindow::setHeaterOff()
{
    ui->label_HeaterState->setText("OFF");

#if WT_DEBUG == 1
    qDebug() << "Heater Off ";
#endif
}





