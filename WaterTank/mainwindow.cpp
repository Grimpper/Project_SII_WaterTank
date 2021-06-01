#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "math.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->label_BaseArea_Value->setText(QString::number(2 * M_PI * ui->spinBox_BaseRadius->value(), 'f', 2) + " m^2");

    connect(ui->spinBox_MaxLevel, SIGNAL(valueChanged(int)), this, SLOT(setMaxLevel()));
    connect(ui->spinBox_InitLevel, SIGNAL(valueChanged(int)), this, SLOT(setInitLevel()));
    connect(ui->spinBox_MaxTemp, SIGNAL(valueChanged(int)), this, SLOT(setMaxTemperature()));
    connect(ui->spinBox_InitTemp, SIGNAL(valueChanged(int)), this, SLOT(setInitTemperature()));
    connect(ui->spinBox_BaseRadius, SIGNAL(valueChanged(int)), this, SLOT(setBaseRadius()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setMaxLevel()
{
    tank->maxLevel = ui->spinBox_MaxLevel->value();

    qDebug() << "maxLevelSet";
}

void MainWindow::setInitLevel()
{
    tank->initLevel = ui->spinBox_InitLevel->value();

    qDebug() << "initLevel";
}

void MainWindow::setMaxTemperature()
{
    tank->maxTemperature = ui->spinBox_MaxTemp->value();

    qDebug() << "maxTemperature";
}

void MainWindow::setInitTemperature()
{
    tank->initTemperature = ui->spinBox_InitTemp->value();

    qDebug() << "initTemperature";
}

void MainWindow::setBaseRadius()
{
    tank->baseRadius = ui->spinBox_BaseRadius->value();
    ui->label_BaseArea_Value->setText(QString::number(2 * M_PI * tank->baseRadius, 'f', 2) + " m^2");

    qDebug() << "baseRadius";
}
