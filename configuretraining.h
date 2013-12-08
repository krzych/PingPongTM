#ifndef CONFIGURETRAINING_H
#define CONFIGURETRAINING_H

#include <QWidget>

namespace Ui {
class ConfigureTraining;
}

class ConfigureTraining : public QWidget
{
    Q_OBJECT

public:
    explicit ConfigureTraining(QWidget *parent = 0);
    ~ConfigureTraining();

private slots:
    void on_addButton_clicked();

    void on_powerSlider_valueChanged(int value);

    void on_powerSpinBox_valueChanged(int arg1);

    void on_angleSlider_valueChanged(int value);

    void on_angleSpinBox_valueChanged(int arg1);

    void on_positionSlider_valueChanged(int value);

    void on_positionSpinBox_valueChanged(int arg1);

    void on_generateButton_clicked();

    void on_deleteButton_clicked();

private:
    Ui::ConfigureTraining *ui;
};

#endif // CONFIGURETRAINING_H
