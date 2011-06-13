#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>

#include "iviewform.h"

class QLineEdit;
class QLabel;
class QComboBox;
class QTextEdit;
class QPushButton;
class QListView;
class QModelIndex;

class MainForm: public QWidget, public IViewForm
{
    Q_OBJECT
  public:
    explicit MainForm(QWidget *parent = 0);

    void setName(QString);
    QString getName() const;
    QString getLastName() const;
    QString getPatronymic() const;
    int getYear() const;
    QString getAddress() const;
    Client::Disability getDisability() const;
    Client::Group getGroup() const;

    void setList( QStringList );

  signals:
    void actionFindClient();
    void actionAddClient();
    void actionReturnIndex(const int index);

  private slots:
    void activeSearch();
    void activeAddition();
    void activeClickOnItemList(const QModelIndex &);

  private:
    QComboBox *cbYear;      // год рождения
    QLineEdit *leLastName;   // 
    QLineEdit *leName;
    QLineEdit *lePatronymic;
    QComboBox *cbDisability;
    QComboBox *cbCotegory;
    QTextEdit *teAddress;
    QPushButton *pbAdd;
    QListView *listClient;

};

#endif //MAINFORM_H
