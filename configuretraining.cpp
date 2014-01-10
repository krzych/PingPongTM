#include "configuretraining.h"
#include "ui_configuretraining.h"
#include <QtCore/QFile>
#include <QXmlStreamWriter>
#include <QList>
#include <time.h>
#include <QDataStream>
#include <QtCore/QTextStream>

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

QList<Hit> *hits = new QList<Hit>();

void ConfigureTraining::on_addButton_clicked()
{
    int repetitions = ui->amountSpinBox->value();
    for(int i =0; i<repetitions; i++)
    {
        hits->append( *(new Hit(ui->powerSlider->value(),ui->radioButton->isChecked(),ui->angleSlider->value(),ui->positionSlider->value())));
    }
    ConfigureTraining::show();
}


void ConfigureTraining::on_generateButton_clicked()
{

    QFile file("C://Parametry2.xml");
    file.open(QIODevice::WriteOnly);
    int i=0;
   QXmlStreamWriter *xmlWriter = new QXmlStreamWriter(&file);
    xmlWriter->writeStartDocument();
    xmlWriter->setAutoFormatting(true);
    xmlWriter->writeStartElement("Uderzenia");
    xmlWriter->writeAttribute("Ilosc", QString::number(hits->size()));

    for(int i=0;i<hits->size();i++)
    {

        xmlWriter->writeStartElement("Uderzenie");
        xmlWriter->writeTextElement("Sila",QString::number(hits->at(i).power));
        if(hits->at(i).rotation!=0)
        {
            xmlWriter->writeTextElement("Rotacja",ui->radioButton->text());
        }
        if(hits->at(i).rotation==0)
        {
            xmlWriter->writeTextElement("Rotacja",ui->radioButton_2->text());
        }
        xmlWriter->writeTextElement("Kat",QString::number(hits->at(i).angle));
        xmlWriter->writeTextElement("Pozycja",QString::number(hits->at(i).position));
        xmlWriter->writeEndElement();
    }
    xmlWriter->writeEndElement();
    xmlWriter->writeEndDocument();
    file.close();
}

void ConfigureTraining::on_loadButton_clicked()
{

}

void ConfigureTraining::show()
{
    int records = hits->size();
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    for(int i=0; i<records;i++)
    {
        const int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);

        QString powText =QString::number(hits->at(i).power);
        QTableWidgetItem *powValue = new QTableWidgetItem(powText);
        ui->tableWidget->setItem(row,0,powValue);

        QString rotText;
        if(hits->at(i).rotation!=0)
        {
            rotText =ui->radioButton->text();
        }
        if(hits->at(i).rotation==0)
        {
            rotText =ui->radioButton_2->text();
        }
        QTableWidgetItem *rotValue = new QTableWidgetItem(rotText);
        ui->tableWidget->setItem(row,1,rotValue);

        QString angText = QString::number(hits->at(i).angle);
        QTableWidgetItem *angValue = new QTableWidgetItem(angText);
        ui->tableWidget->setItem(row,2,angValue);

        QString posText = QString::number(hits->at(i).position);
        QTableWidgetItem *posValue = new QTableWidgetItem(posText);
        ui->tableWidget->setItem(row,3,posValue);
    }
}

void ConfigureTraining::on_deleteButton_clicked()
{
    int selectedRow = ui->tableWidget->currentRow();
    hits->removeAt(selectedRow);
    ui->tableWidget->removeRow(ui->tableWidget->currentRow());

}

void ConfigureTraining::on_mixButton_clicked()
{
    int iter = 3*(hits->size());

    for(int i=0;i<iter;i++)
    {
        int bufor1= rand()%(hits->size());
        int bufor2= rand()%(hits->size());
        hits->swap(bufor1, bufor2);
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



