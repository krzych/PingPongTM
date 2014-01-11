#ifndef CONFIGURETRAINING_H
#define CONFIGURETRAINING_H

#include <QWidget>
#include "hit.h"
#include "training.h"

namespace Ui {
class ConfigureTraining;
}

class ConfigureTraining : public QWidget
{
    Q_OBJECT

public:
    explicit ConfigureTraining(QWidget *parent = 0);
    ~ConfigureTraining();
    Training *training;

    void show();
    //void show(Training training);

    //friend QDataStream &operator <<(QDataStream &out, const QList<Hit> *hits);
    //friend QDataStream &operator >>(QDataStream &out, QList<Hit> *hits);

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



    void on_mixButton_clicked();

    void on_loadButton_clicked();

private:
    Ui::ConfigureTraining *ui;
};

#endif // CONFIGURETRAINING_H
