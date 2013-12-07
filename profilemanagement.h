#ifndef PROFILEMANAGEMENT_H
#define PROFILEMANAGEMENT_H

#include <QWidget>

namespace Ui {
class ProfileManagement;
}

class ProfileManagement : public QWidget
{
    Q_OBJECT

public:
    explicit ProfileManagement(QWidget *parent = 0);
    ~ProfileManagement();

private slots:
    void on_AddNewProfileButton_clicked();

private:
    Ui::ProfileManagement *ui;
};

#endif // PROFILEMANAGEMENT_H
