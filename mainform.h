#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include "iviewform.h"

class QLineEdit;
class QLabel;
class QComboBox;
class QTextEdit;
class QPushButton;

class MainForm: public QWidget, public IViewForm
{
    Q_OBJECT
public:
    explicit MainForm(QWidget *parent = 0);

    QString getName() const;
    QString getSurname() const;
    QString getPatronymic() const;
    Client::Disability getDisability() const;
    Client::Group getGroup() const;
    QString getAddress() const;

public slots:
    void activeSearch();

private:
    QComboBox *cbYear;
    QLineEdit *leSurname;
    QLineEdit *leName;
    QLineEdit *lePatronymic;
    QComboBox *cbDisability;
    QComboBox *cbCotegory;
    QTextEdit *teAddress;
    QPushButton *pbSearch;

};

#endif //MAINFORM_H
