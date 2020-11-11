#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      timer(new QTimer(this))
{
    ui->setupUi(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(advanceProgress()));
    on_spinBox_valueChanged(ui->spinBox->value());
}

MainWindow::~MainWindow()
{
    delete ui; 
}

void MainWindow::advanceProgress()
{
    int curVal = ui->progressBar->value();
    if( curVal < ui->progressBar->maximum())
        ui->progressBar->setValue(++curVal);
    else
    {
        timer->stop();
        ui->startBut->setEnabled(true);
    }
}

void MainWindow::on_startBut_clicked()
{
    ui->progressBar->setValue(0);
    ui->startBut->setEnabled(false);
    timer->start();
}

void MainWindow::on_spinBox_valueChanged(int val)
{
    timer->setInterval(val);
}


void MainWindow::on_leftBut_clicked()
{
    ui->leftBut->setEnabled(false);
    butDir = dir::left;
    QTimer::singleShot(1000,this,SLOT(react()));
}

void MainWindow::on_rightBut_clicked()
{
    ui->rightBut->setEnabled(false);
    butDir = dir::right;
    QTimer::singleShot(1000,this,SLOT(react()));
}

void MainWindow::react()
{
    switch(butDir)
    {
    case dir::left: 
        ui->rightBut->setEnabled(true); 
        break;
    case dir::right: 
        ui->leftBut->setEnabled(true); 
        break;
    }
}
