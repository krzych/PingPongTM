#include "profilemanagement.h"
#include "ui_profilemanagement.h"
#include "addnewprofile.h"

ProfileManagement::ProfileManagement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProfileManagement)
{
    ui->setupUi(this);
}

ProfileManagement::~ProfileManagement()
{
    delete ui;
}

void ProfileManagement::on_AddNewProfileButton_clicked()
{
    AddNewProfile * NewProfile = new AddNewProfile(this);
    NewProfile->show();

}
