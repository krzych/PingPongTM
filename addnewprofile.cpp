#include "addnewprofile.h"
#include "ui_addnewprofile.h"

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
