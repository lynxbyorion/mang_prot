#include <QtGui>
#include "mainform.h"
#include "defandpar.h"

MainForm::MainForm(QWidget *parent)
    : QWidget(parent)
{
    QLabel *lbLastName = new QLabel("Фамилия");
    leLastName = new QLineEdit();
    QLabel *lbName = new QLabel("Имя");
    leName = new QLineEdit();
    QLabel *lbPatronymic = new QLabel("Отчество");
    lePatronymic = new QLineEdit();


    connect(leLastName, SIGNAL(textChanged(const QString &)), this,
            SLOT(activeSearch()));
    connect(leName, SIGNAL(textChanged(const QString &)), this,
            SLOT(activeSearch()));
    connect(lePatronymic, SIGNAL(textChanged(const QString &)), this,
            SLOT(activeSearch()));

    QLabel *lbYear = new QLabel("Год рождения:");
    cbYear = new QComboBox;
    for(int year = MIN_YEAR; year < MAX_YEAR; year++)
        cbYear->addItem(QString::number(year));
    cbYear->setCurrentIndex(60);

    QLabel *lbDis = new QLabel("Инвалид");
    cbDisability = new QComboBox;
    QStringList listDisability(QStringList() << "войны"
            << "детства" << "труда" << "общего заболевания");
    cbDisability->addItems(listDisability);
    cbCotegory = new QComboBox;
    QStringList listCotegory(QStringList() << "III" << "II" << "I");
    cbCotegory->addItems(listCotegory);
    cbCotegory->setFixedWidth(50);
    QLabel *lbGroup = new QLabel("группы");

    QLabel *lbAddress = new QLabel("Адрес:");
    teAddress = new QTextEdit;

    pbSearch = new QPushButton("Найти");
    connect(pbSearch, SIGNAL(pressed()), this, SLOT(activeSearch()));

    // name label layout
    QHBoxLayout *lbLayout = new QHBoxLayout;
    lbLayout->addWidget(lbLastName);
    lbLayout->addWidget(lbName);
    lbLayout->addWidget(lbPatronymic);

    // name layout
    QHBoxLayout *leLayout = new QHBoxLayout;
    leLayout->addWidget(leLastName);
    leLayout->addWidget(leName);
    leLayout->addWidget(lePatronymic);

    // year layout
    QHBoxLayout *yearLayout = new QHBoxLayout;
    yearLayout->addWidget(lbYear);
    yearLayout->addWidget(cbYear);
    yearLayout->addStretch();

    // disability layout
    QHBoxLayout *disLayout = new QHBoxLayout;
    disLayout->addWidget(lbDis);
    disLayout->addWidget(cbDisability);
    disLayout->addWidget(cbCotegory);
    disLayout->addWidget(lbGroup);
    disLayout->addStretch();

    QVBoxLayout *adrLayout = new QVBoxLayout;
    adrLayout->addWidget(lbAddress);
    adrLayout->addWidget(teAddress);

    // button layout
    QHBoxLayout *pbLayout = new QHBoxLayout;
    pbLayout->addStretch();
    pbLayout->addWidget(pbSearch);

    // left layout
    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addLayout(lbLayout);
    leftLayout->addLayout(leLayout);
    leftLayout->addLayout(yearLayout);
    leftLayout->addLayout(disLayout);
    leftLayout->addLayout(adrLayout);
    leftLayout->addLayout(pbLayout);

    listClient = new QListView;

    // right layout
    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(listClient);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);

    setLayout(mainLayout);
    setWindowTitle("Клиентская база");
}

// interface implementation

void MainForm::setName(QString name)
{
    leName->setText(name);
}

QString MainForm::getName() const
{
    return leName->text();
}

QString MainForm::getLastName() const
{
    return leLastName->text();
}

QString MainForm::getPatronymic() const
{
    return lePatronymic->text();
}

Client::Disability MainForm::getDisability() const
{
    switch(cbDisability->currentIndex()) {
        case 0:
            return Client::War;
        case 1:
            return Client::Infancy;
        case 2:
            return Client::Work;
        case 3:
            return Client::General;
        default:
            qWarning() << "cbDisability is not identified";
            return Client::General;
    }
}

Client::Group MainForm::getGroup() const
{
    switch(cbCotegory->currentIndex()) {
        case 0:
            return Client::GroupIII;
        case 1:
            return Client::GroupII;
        case 2:
            return Client::GroupI;
        default:
            qWarning() << "cbCotegory is not identified";
            return Client::GroupI;
    }
}

QString MainForm::getAddress() const
{
    return QString("cap");
}

void MainForm::setList( QStringList list )
{
    listClient->setModel( new QStringListModel(list) );
}


//! slots
void MainForm::activeSearch()
{
    qWarning() << "in slot activeSearch";
    emit actionFindClient();
}

