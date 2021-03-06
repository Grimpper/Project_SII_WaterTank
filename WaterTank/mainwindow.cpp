#include <QDebug>
#include <QPixmap>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"
#include "unitutils.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), signalMapper(new QSignalMapper)
{
    ui->setupUi(this);

    ui->groupBox_GUI->setStyleSheet("background-color: white");

    ui->label_BaseArea_Value->setText(QString::number(2 * M_PI * ui->spinBox_BaseRadius->value(), 'f', 2) + " m^2");
    ui->label_ExitArea_Value->setText(QString::number(2 * M_PI * ui->spinBox_ExitRadius->value(), 'f', 2) + " m^2");


    connectQtElements();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete signalMapper;

    deletePointerMembers();
}

void MainWindow::connectQtElements()
{
    //  SIMULATION CONTROLS  //
    connect(ui->pushButton_Start, SIGNAL(clicked()), this, SLOT(start()));
    connect(ui->pushButton_Pause, SIGNAL(clicked()), this, SLOT(pause()));
    connect(ui->pushButton_Reset, SIGNAL(clicked()), this, SLOT(reset()));

    connect(ui->horizontalSlider_Flow, SIGNAL(valueChanged(int)), this, SLOT(flowChanged(int)));
    connect(ui->spinBox_Temperature, SIGNAL(valueChanged(int)), this, SLOT(tempChanged(int)));

    // RADIO BUTTONS //
    signalMapper->setMapping(ui->radioButton_x1, EnumSimStep::x1);
    signalMapper->setMapping(ui->radioButton_x2, EnumSimStep::x2);
    signalMapper->setMapping(ui->radioButton_x5, EnumSimStep::x5);
    signalMapper->setMapping(ui->radioButton_x10, EnumSimStep::x10);

    connect(ui->radioButton_x1, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->radioButton_x2, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->radioButton_x5, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->radioButton_x10, SIGNAL(clicked()), signalMapper, SLOT(map()));

    connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(setTimestep(int)));

    //  VALVE BUTTONS  //
    connect(ui->pushButton_Valve_Close, SIGNAL(clicked()), this, SLOT(setValveState()));
    connect(ui->pushButton_Valve_Open, SIGNAL(clicked()), this, SLOT(setValveState()));

    //  HEATER BUTTONS  //
    connect(ui->pushButton_Heater_Off, SIGNAL(clicked()), this, SLOT(setHeaterState()));
    connect(ui->pushButton_Heater_On, SIGNAL(clicked()), this, SLOT(setHeaterState()));

    //  CONFIGURATION BUTTONS  //
    connect(ui->spinBox_ExitRadius, SIGNAL(valueChanged(int)), this, SLOT(updateExitAreaLabel(int)));
    connect(ui->spinBox_BaseRadius, SIGNAL(valueChanged(int)), this, SLOT(updateBaseAreaLabel(int)));

    // TIMER //
    simulationTimer.setInterval(simulationIntervalMS);
    connect(&simulationTimer, SIGNAL(timeout()), this, SLOT(sim()));
}

void MainWindow::updateDrawing()
{
    if (!checkPointerInit()) return;

    float level = tank->getLevel();
    float temperature = tank->getTemperature();
    float pump = this->pump->getFlow();   

    QString str = "Tiempo simulado: " + QString::number((elapsedTimer.elapsed() * simStep + displayTimeUntilLastStop) / 1000.0) + " s";
    ui->label_SimTime->setText(str);

    str = "Temperatura: " + QString::number(UnitUtils::getInCelsius(temperature), 'f', 2) + " ??C";
    ui->label_Temp->setText(str);

    str = "Nivel: " + QString::number(UnitUtils::getInLiters(level), 'f', 2) + " L";
    ui->label_Level->setText(str);

    float imageWhiteMaskHeight = level * (10 - 305.0) / tank->getMaxLevel() + 305;
    float imageWaterFlowHeight = level * (10 - 305.0) / tank->getMaxLevel() + 305;
    float imageThermometerMaskHeight = (temperature + 20) * -137.0 / (tank->getMaxTemperature() + 20.0) + 137.0;

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


    if(pump){
        ui->ImageWaterFlow->setVisible(true);
        ui->ImageWhiteMask->setVisible(false);
    } else {
        ui->ImageWaterFlow->setVisible(false);
        ui->ImageWhiteMask->setVisible(true);
    }

    if(valve->state == Valve::VALVE_OPEN){
        ui->ImageTankValveOpen->setVisible(true);
        ui->ImageTankValveClose->setVisible(false);
    } else {
        ui->ImageTankValveOpen->setVisible(false);
        ui->ImageTankValveClose->setVisible(true);
    }

    if(heater->state == Heater::HEATER_ON){
        ui->ImageFlame->setVisible(true);
    } else {
        ui->ImageFlame->setVisible(false);
    }

    if(tank->getOverheat()){
        ui->ImageOverheat->setVisible(true);
        ui->label_Overheat->setVisible(true);
    } else {
        ui->ImageOverheat->setVisible(false);
        ui->label_Overheat->setVisible(false);
    }

    if(tank->getOverflow()){
        ui->ImageOverflow->setVisible(true);
        ui->label_Overflow->setVisible(true);
    } else {
        ui->ImageOverflow->setVisible(false);
        ui->label_Overflow->setVisible(false);
    }
}

void MainWindow::sim()
{
    simulation->computeStep();
    safetyHandler();
    updateDrawing();
}

bool MainWindow::checkPointerInit()
{
    return tank || pump || valve || heater || simulation;
}

void MainWindow::deletePointerMembers()
{
    delete tank;
    delete pump;
    delete valve;
    delete heater;
    delete simulation;

    tank = nullptr;
    pump = nullptr;
    valve = nullptr;
    heater = nullptr;
    simulation = nullptr;
}

void MainWindow::setEnableConfig(bool state)
{
    ui->groupBox_Pump_Config->setEnabled(state);
    ui->groupBox_Valve_Config->setEnabled(state);
    ui->groupBox_Tank_Config->setEnabled(state);
    ui->groupBox_Heater_Config->setEnabled(state);
    ui->groupBox_Enviroment_Config->setEnabled(state);

    ui->groupBox_Controls->setEnabled(!state);
    ui->groupBox_Valve->setEnabled(!state);
    ui->groupBox_Heater->setEnabled(!state);
}

float MainWindow::getTimestep()
{
    return simStep * simulationIntervalMS / 1000.0;
}

void MainWindow::start()
{
    simulationTimer.start();
    elapsedTimer.start();

    if (checkPointerInit()) return;

    pump = new Pump(UnitUtils::getInCubicMeters(ui->spinBox_EntranceFlow->value()),
                    UnitUtils::getInKelvin(ui->spinBox_EntranceTemp->value()));

    valve = new Valve(UnitUtils::getInMeters(ui->spinBox_ExitRadius->value()),
                      ui->spinBox_ExitConnection->value());

    tank = new Tank(UnitUtils::getInCubicMeters(ui->spinBox_MaxLevel->value()),
                    UnitUtils::getInCubicMeters(ui->spinBox_InitLevel->value()),
                    UnitUtils::getInKelvin(ui->spinBox_MaxTemp->value()),
                    UnitUtils::getInKelvin(ui->spinBox_InitTemp->value()),
                    ui->spinBox_BaseRadius->value(),
                    UnitUtils::getInKelvin(ui->spinBox_EnviromentalTemp->value()),
                    UnitUtils::getInCubicMeters(ui->spinBox_Overflow_Threshold->value()),
                    UnitUtils::getInKelvin(ui->spinBox_Overheat_Threshold->value()));

    heater = new Heater(UnitUtils::getInKelvin(ui->spinBox_InitHeaterTemp->value()));

    simulation = new Simulation(tank, pump, valve, heater, getTimestep());

    ui->horizontalSlider_Flow->setMaximum(UnitUtils::getInLiters(pump->getMaxFlow() * 10));

    setEnableConfig(false);

#if WT_DEBUG == 1
    qDebug() << "SIMULATION STARTED";
#endif
}

void MainWindow::pause()
{
    simulationTimer.stop();
    displayTimeUntilLastStop += elapsedTimer.elapsed() * simStep;

#if WT_DEBUG == 1
    qDebug() << "SIMULATION STOPPED";
#endif
}

void MainWindow::reset()
{
    simulationTimer.stop();
    deletePointerMembers();
    setEnableConfig(true);

    displayTimeUntilLastStop = 0;

#if WT_DEBUG == 1
    qDebug() << "SIMULATION RESETED";
#endif
}

void MainWindow::setTimestep(int step)
{

    displayTimeUntilLastStop += elapsedTimer.elapsed() * simStep;
    elapsedTimer.start();

    simStep = (EnumSimStep) step;

    if (!checkPointerInit()) return;
    simulation->setStep(getTimestep());

#if WT_DEBUG == 1
    qDebug() << "Checked = " + QString::number(step);
#endif
}

void MainWindow::flowChanged(int flow)
{
    pump->setFlow(UnitUtils::getInCubicMeters(flow / 10.0));

    QString str = "Caudal: " + QString::number(UnitUtils::getInLiters(pump->getFlow())) + " L/s";
    ui->label_PumpFlow->setText(str);

    str = "Porcentaje: " + QString::number(flow / (float)ui->horizontalSlider_Flow->maximum() * 100) + " %";
    ui->label_PumpPercentage->setText(str);

#if WT_DEBUG == 1
    qDebug() << "setFlow = " + QString::number(UnitUtils::getInLiters(pump->getFlow()));
#endif
}

void MainWindow::tempChanged(int temp)
{
    heater->temp = UnitUtils::getInKelvin(temp);

#if WT_DEBUG == 1
    qDebug() << "Temp: " + QString::number(temp) + " ??C";;
#endif
}

void MainWindow::setValveState()
{
    valve->state = sender() == ui->pushButton_Valve_Open ? Valve::VALVE_OPEN : Valve::VALVE_CLOSE;

#if WT_DEBUG == 1
    QString str = valve->state ? "OPEN" : "CLOSE";
    qDebug() << "valveState = " + str;
#endif
}

void MainWindow::setHeaterState()
{
    heater->state = sender() == ui->pushButton_Heater_On ? Heater::HEATER_ON : Heater::HEATER_OFF;

#if WT_DEBUG == 1
    QString str = heater->state ? "ON" : "OFF";
    qDebug() << "heaterState = " + str;
#endif
}

void MainWindow::updateExitAreaLabel(int value)
{
    ui->label_ExitArea_Value->setText(QString::number(2 * M_PI * value, 'f', 2) + " m^2");
}


void MainWindow::updateBaseAreaLabel(int value)
{
    ui->label_BaseArea_Value->setText(QString::number(2 * M_PI * value, 'f', 2) + " m^2");
}

void MainWindow::safetyHandler()
{
    if (tank->getLevel() > tank->getMaxLevel())
        pump->setFlow(0);

    if (tank->getTemperature() > tank->getMaxTemperature())
        heater->state = Heater::HEATER_OFF;
}
