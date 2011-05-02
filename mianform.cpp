#include <QtGui>
#include "mainform.h"

MainForm::MainForm(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *bt = new QPushButton("OK");

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(bt);

    setLayout(layout);
}
