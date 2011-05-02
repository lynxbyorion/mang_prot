#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>

class QString;

class MainForm: public QWidget
{
    Q_OBJECT
public:
    explicit MainForm(QWidget *parent = 0);

private:
    QString str;
};

#endif //MAINFORM_H
