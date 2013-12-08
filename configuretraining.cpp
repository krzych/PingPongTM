#include "configuretraining.h"
#include "ui_configuretraining.h"

ConfigureTraining::ConfigureTraining(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConfigureTraining)
{
    ui->setupUi(this);
}

ConfigureTraining::~ConfigureTraining()
{
    delete ui;
}

void ConfigureTraining::on_addButton_clicked()
{

}
