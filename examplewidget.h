/*
** File:   examplewidget.h
** Class:  ExampleWidget
** Author: Krzysztof Sas
** Date:   2013-12-04
******************************/

#ifndef EXAMPLEWIDGET_H
#define EXAMPLEWIDGET_H

#include <QWidget>

namespace Ui {
    class ExampleWidget;
}

class ExampleWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ExampleWidget(QWidget *parent = 0);
    ~ExampleWidget();

private:
    Ui::ExampleWidget *ui;
};

#endif // EXAMPLEWIDGET_H
