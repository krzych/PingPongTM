/*
** File:   mainwindow.cpp
** Class:  MainWindow
** Author: Krzysztof Sas
** Date:   2013-12-04
******************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "examplewidget.h"
#include "profilemanagement.h"
#include "configuretraining.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //connect button to signals
    connect(ui->Profile,SIGNAL(clicked()),this,SLOT(button1Clicked()));
    connect(ui->configureButton,SIGNAL(clicked()),this,SLOT(on_configureButton_clicked()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(button3Clicked()));

    m_mainFrameLayout = new QGridLayout(ui->mainFrame);
    ui->mainFrame->setLayout(m_mainFrameLayout);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Profile_clicked()
{
    //clear main frame
    clearLayout(m_mainFrameLayout);

    ProfileManagement* myProfilManagement = new ProfileManagement(this);
    m_mainFrameLayout->addWidget(myProfilManagement);
}

void MainWindow::on_configureButton_clicked()
{
    clearLayout(m_mainFrameLayout);

    ConfigureTraining* configureTraining = new ConfigureTraining(this);
    m_mainFrameLayout->addWidget(configureTraining);

}

void MainWindow::button3Clicked()
{
    //to implement
}

void MainWindow::clearLayout(QLayout* lay)
{
    QLayoutItem* item;
    while((item = lay->takeAt(0)))
    {
        if(item->layout())
        {
            clearLayout(item->layout());
            delete item->layout();
        }
        if(item->widget())
        {
            delete item->widget();
        }
        delete item;
    }
}


