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

private:
    Ui::ConfigureTraining *ui;
};

#endif // CONFIGURETRAINING_H
