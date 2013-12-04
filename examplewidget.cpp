/*
** File:   examplewidget.cpp
** Class:  ExampleWidget
** Author: Krzysztof Sas
** Date:   2013-12-04
******************************/

#include "examplewidget.h"
#include "ui_examplewidget.h"

ExampleWidget::ExampleWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExampleWidget)
{
    ui->setupUi(this);
}

ExampleWidget::~ExampleWidget()
{
    delete ui;
}
