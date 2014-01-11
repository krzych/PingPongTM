#include "configuretraining.h"
#include "ui_configuretraining.h"
#include <QtCore/QFile>
#include <QList>
#include <time.h>

ConfigureTraining::ConfigureTraining(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConfigureTraining)
{
    ui->setupUi(this);
    training = new Training();
}

ConfigureTraining::~ConfigureTraining()
{
    delete ui;
}

void ConfigureTraining::on_addButton_clicked()
{
    int repetitions = ui->amountSpinBox->value();


    for(int i =0; i<repetitions; i++)
    {
        training->addHit(ui->powerSlider->value(),ui->radioButton->isChecked(),ui->angleSlider->value(),ui->positionSlider->value());
    }
    ConfigureTraining::show();
}


void ConfigureTraining::on_generateButton_clicked()
{
    training->serialize();
}

void ConfigureTraining::on_loadButton_clicked()
{
    training->deserialize();
    ConfigureTraining::show();

}

void ConfigureTraining::show()
{
    int records = training->hits.size();
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    for(int i=0; i<records;i++)
    {
        const int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);

        QString powText =QString::number(training->hits.at(i).power);
        QTableWidgetItem *powValue = new QTableWidgetItem(powText);
        ui->tableWidget->setItem(row,0,powValue);

        QString rotText;
        if(training->hits.at(i).rotation!=0)
        {
            rotText =ui->radioButton->text();
        }
        if(training->hits.at(i).rotation==0)
        {
            rotText =ui->radioButton_2->text();
        }
        QTableWidgetItem *rotValue = new QTableWidgetItem(rotText);
        ui->tableWidget->setItem(row,1,rotValue);

        QString angText = QString::number(training->hits.at(i).angle);
        QTableWidgetItem *angValue = new QTableWidgetItem(angText);
        ui->tableWidget->setItem(row,2,angValue);

        QString posText = QString::number(training->hits.at(i).position);
        QTableWidgetItem *posValue = new QTableWidgetItem(posText);
        ui->tableWidget->setItem(row,3,posValue);
    }
}

void ConfigureTraining::on_deleteButton_clicked()
{
    int selectedRow = ui->tableWidget->currentRow();
    training->hits.removeAt(selectedRow);
    ui->tableWidget->removeRow(ui->tableWidget->currentRow());

}

void ConfigureTraining::on_mixButton_clicked()
{
    int iter = 3*(training->hits.size());

    for(int i=0;i<iter;i++)
    {
        int bufor1= rand()%(training->hits.size());
        int bufor2= rand()%(training->hits.size());
        training->hits.swap(bufor1, bufor2);
    }

    ConfigureTraining::show();
}


void ConfigureTraining::on_powerSlider_valueChanged(int value)
{
    ui->powerSpinBox->setValue(value);
}

void ConfigureTraining::on_powerSpinBox_valueChanged(int arg1)
{
    ui->powerSlider->setValue(arg1);
}

void ConfigureTraining::on_angleSlider_valueChanged(int value)
{
    ui->angleSpinBox->setValue(value);
}

void ConfigureTraining::on_angleSpinBox_valueChanged(int arg1)
{
    ui->angleSlider->setValue(arg1);
}

void ConfigureTraining::on_positionSlider_valueChanged(int value)
{
    ui->positionSpinBox->setValue(value);
}

void ConfigureTraining::on_positionSpinBox_valueChanged(int arg1)
{
    ui->positionSlider->setValue(arg1);
}



