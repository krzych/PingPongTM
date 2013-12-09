#ifndef ADDNEWPROFILE_H
#define ADDNEWPROFILE_H
#include <QDialog>
#include <QMainWindow>

namespace Ui {
class AddNewProfile;
}
QT_BEGIN_NAMESPACE
class QSqlTableModel;
QT_END_NAMESPACE

class AddNewProfile : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddNewProfile(QWidget *parent = 0);
    ~AddNewProfile();

private slots:
    void on_positionSlider_valueChanged(int value);

    void on_PositionSpinBox_valueChanged(int arg1);

    void on_angleSlider_valueChanged(int value);

    void on_AngleSpinBox_valueChanged(int arg1);

    void on_AddButton_clicked();

private:
    int Percent;
    Ui::AddNewProfile *ui;
    QSqlTableModel *model;
};

#endif // ADDNEWPROFILE_H
