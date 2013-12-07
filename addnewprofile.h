#ifndef ADDNEWPROFILE_H
#define ADDNEWPROFILE_H

#include <QMainWindow>

namespace Ui {
class AddNewProfile;
}

class AddNewProfile : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddNewProfile(QWidget *parent = 0);
    ~AddNewProfile();

private:
    Ui::AddNewProfile *ui;
};

#endif // ADDNEWPROFILE_H
