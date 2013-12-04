/*
** File:   mainwindow.cpp
** Class:  MainWindow
** Author: Krzysztof Sas
** Date:   2013-12-04
******************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "examplewidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //connect button to signals
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(button1Clicked()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(button2Clicked()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(button3Clicked()));

    m_mainFrameLayout = new QGridLayout(ui->mainFrame);
    ui->mainFrame->setLayout(m_mainFrameLayout);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::button1Clicked()
{
    //clear main frame
    clearLayout(m_mainFrameLayout);

    ExampleWidget* exWidget = new ExampleWidget(this);
    m_mainFrameLayout->addWidget(exWidget);
}

void MainWindow::button2Clicked()
{
    //clear main frame
    clearLayout(m_mainFrameLayout);

    //inne widgety
    ExampleWidget* exWidget = new ExampleWidget(this);
    m_mainFrameLayout->addWidget(exWidget);

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
