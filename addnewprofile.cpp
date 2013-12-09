#include "addnewprofile.h"
#include "ui_addnewprofile.h"
#include "QStandardItemModel"

AddNewProfile::AddNewProfile(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddNewProfile)
{

    ui->setupUi(this);
}

AddNewProfile::~AddNewProfile()
{
    delete ui;
}

void AddNewProfile::on_positionSlider_valueChanged(int value)
{
    ui->PositionSpinBox->setValue(value);
}


void AddNewProfile::on_PositionSpinBox_valueChanged(int arg1)
{
    ui->positionSlider->setValue(arg1);
}

void AddNewProfile::on_angleSlider_valueChanged(int value)
{
    ui->AngleSpinBox->setValue(value);
}

void AddNewProfile::on_AngleSpinBox_valueChanged(int arg1)
{
    ui->angleSlider->setValue(arg1);
}

void AddNewProfile::on_AddButton_clicked()
{
      const int row = ui->tableWidget->rowCount();
      ui->tableWidget->insertRow(row);
      QString ForceStr =QString::number(ui->ForceSpinBox->value());

      QString RotationStr;
      if( ui->BocznaRadioButton->isChecked())
      {
         RotationStr = ui->BocznaRadioButton->text();
      }

      if( ui->WstecznaRadioButton->isChecked())
      {
         RotationStr = ui->WstecznaRadioButton->text();
      }
      if( ui->OtherRadioButton->isChecked())
      {
         RotationStr = ui->OtherRadioButton->text();
      }

      QString PositionStr =QString::number(ui->positionSlider->value());
      QString AngleStr =QString::number(ui->angleSlider->value());
      QString PercentStr =QString::number(ui->PercentSpinBox->value());

      QString ForceTxtUtf =QString::fromUtf8( "Siła=");
      QString AngleTxtUtf =QString::fromUtf8( "Kąt=");
      QString Parameters = (ForceTxtUtf+ForceStr+";"+"Rotacja="+RotationStr+";"+"Pozycja="+PositionStr+
              ";"+AngleTxtUtf+AngleStr);
      if(row==0)
      {
       Percent=0;
      }

      Percent = Percent + ui->PercentSpinBox->value();


      if ( Percent < 100 && Percent > 100)
      {
          ui->PercentSumTextEdit->clear();
          ui->PercentSumTextEdit->setTextColor(QColor("red"));
          ui->GenrateButton->setEnabled(0);
      }
      if ( Percent == 100 )
      {
          ui->PercentSumTextEdit->clear();
          ui->PercentSumTextEdit->setTextColor(QColor("green"));
          ui->GenrateButton->setEnabled(1);
      }

      QString PercentSumStr = QString::number(Percent);

      QTableWidgetItem *Param = new QTableWidgetItem(Parameters);
      ui->tableWidget->setItem(row,0,Param);

      QTableWidgetItem *Perc = new QTableWidgetItem(PercentStr);
      ui->tableWidget->setItem(row,1,Perc);

      ui->PercentSumTextEdit->clear();
      ui->PercentSumTextEdit->insertPlainText(PercentSumStr);


}
