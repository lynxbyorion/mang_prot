#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>

class QLineEdit;
class QLabel;
class QComboBox;
class QTextEdit;
class QPushButton;

class MainForm: public QWidget
{
    Q_OBJECT
public:
    explicit MainForm(QWidget *parent = 0);

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
