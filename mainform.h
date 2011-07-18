#ifndef MAINFORM_H
#define MAINFORM_H

#include <QMainWindow>

#include "iviewform.h"

class QMenu;
class QAction;
class QLineEdit;
class QLabel;
class QComboBox;
class QTextEdit;
class QPushButton;
class QListView;
class QModelIndex;

class StatisticWindow;

class MainForm: public QMainWindow, public IViewForm
{
    Q_OBJECT
  public:
    explicit MainForm();

    void refresh();

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
    void actionRemoveClient(const int index);
    void actionReturnIndex(const int index);

  private slots:
    void activeSearch();
    void activeAddition();
    void activeClickOnItemList(const QModelIndex &);
    void removeClient();
    void createStatisticWindow();
    void about();

  private:
    void createMenu();
    void createActions();

  private:
    QMenu *fileMenu;
    QMenu *helpMenu;
    QAction *actStatistics;
    QAction *actAbout;

    QComboBox *cbYear;      // год рождения
    QLineEdit *leLastName;   // 
    QLineEdit *leName;
    QLineEdit *lePatronymic;
    QComboBox *cbDisability;
    QComboBox *cbCotegory;
    QTextEdit *teAddress;
    QPushButton *pbAdd;
    QPushButton *pbRemoveClient;
    QListView *listClient;

};

#endif //MAINFORM_H
