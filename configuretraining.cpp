#include "configuretraining.h"
#include "ui_configuretraining.h"
#include <QtCore/QFile>
#include <QXmlStreamWriter>

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
    int repetitions = ui->amountSpinBox->value();
    for(int i =0; i<repetitions; i++)
    {
        const int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);

        QString powText =QString::number(ui->powerSlider->value());
        QTableWidgetItem *powValue = new QTableWidgetItem(powText);
        ui->tableWidget->setItem(row,0,powValue);

        QString rotText =ui->radioButton->text();
        QTableWidgetItem *rotValue = new QTableWidgetItem(rotText);
        ui->tableWidget->setItem(row,1,rotValue);

        QString angText = QString::number(ui->angleSlider->value());
        QTableWidgetItem *angValue = new QTableWidgetItem(angText);
        ui->tableWidget->setItem(row,2,angValue);

        QString posText = QString::number(ui->positionSlider->value());
        QTableWidgetItem *posValue = new QTableWidgetItem(posText);
        ui->tableWidget->setItem(row,3,posValue);
    }
}

void ConfigureTraining::on_generateButton_clicked()
{
    QFile file ("Parametry_treningu.xml");
    file.open(QIODevice::WriteOnly);
    QXmlStreamWriter *xmlWriter = new QXmlStreamWriter();
    xmlWriter->setDevice(&file);
    xmlWriter->writeStartDocument();
    xmlWriter->writeStartElement("Wygenerowane parametry treningu");
    xmlWriter->writeEndElement();
    xmlWriter->writeEndDocument();
    file.close();
}

void ConfigureTraining::on_deleteButton_clicked()
{
    ui->tableWidget->removeRow(ui->tableWidget->currentRow());
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

