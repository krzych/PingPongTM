/*
** File:   mainwindow.h
** Class:  MainWindow
** Author: Krzysztof Sas
** Date:   2013-12-04
******************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void button1Clicked();
    void button2Clicked();
    void button3Clicked();

private:
    void clearLayout(QLayout* lay);

private:
    Ui::MainWindow *ui;

    QGridLayout *m_mainFrameLayout;
};

#endif // MAINWINDOW_H
