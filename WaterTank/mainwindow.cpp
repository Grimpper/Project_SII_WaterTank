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
}

void MainWindow::setDrawing()
{
    int level = tank->getLevel();
    int temperature = tank->getTemperature();
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
    tank->maxLevel = ui->spinBox_MaxLevel->value();

#if WT_DEBUG == 1
    qDebug() << "maxLevelSet";
#endif
}

void MainWindow::setInitLevel()
{
    tank->initLevel = ui->spinBox_InitLevel->value();

#if WT_DEBUG == 1
    qDebug() << "initLevel";
#endif
}

void MainWindow::setMaxTemperature()
{
    tank->maxTemperature = ui->spinBox_MaxTemp->value();

#if WT_DEBUG == 1
    qDebug() << "maxTemperature";
#endif
}

void MainWindow::setInitTemperature()
{
    tank->initTemperature = ui->spinBox_InitTemp->value();

#if WT_DEBUG == 1
    qDebug() << "initTemperature";
#endif
}

void MainWindow::setBaseRadius()
{
    tank->baseRadius = ui->spinBox_BaseRadius->value();
    ui->label_BaseArea_Value->setText(QString::number(2 * M_PI * tank->baseRadius, 'f', 2) + " m^2");

#if WT_DEBUG == 1
    qDebug() << "baseRadius";
#endif
}
