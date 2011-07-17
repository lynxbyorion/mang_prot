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
    cbYear->setCurrentIndex(-1);
    connect(cbYear, SIGNAL(activated(const QString &)),
                this, SLOT(activeSearch()));

    QLabel *lbDis = new QLabel("Инвалид");
    cbDisability = new QComboBox;
    QStringList listDisability(QStringList() << tr("неизвестно") << "войны"
            << "детства" << "труда" << "общего заболевания");
    cbDisability->addItems(listDisability);
    cbDisability->setCurrentIndex(-1);
    connect(cbDisability, SIGNAL(activated(const QString &)),
                this, SLOT(activeSearch()));

    cbCotegory = new QComboBox;
    QStringList listCotegory(QStringList() << tr("Неизвестно")
            << "III" << "II" << "I");
    cbCotegory->addItems(listCotegory);
    cbCotegory->setCurrentIndex(-1);
    cbCotegory->setFixedWidth(50);
    connect(cbCotegory, SIGNAL(activated(const QString &)),
                this, SLOT(activeSearch()));
    QLabel *lbGroup = new QLabel("группы");

    QLabel *lbAddress = new QLabel("Адрес:");
    teAddress = new QTextEdit;

    pbAdd = new QPushButton("Добавить");
    connect(pbAdd, SIGNAL(pressed()), this, SLOT(activeAddition()));

    pbRemoveClient = new QPushButton(tr("Удалить"));
    connect(pbRemoveClient, SIGNAL(clicked()), this, SLOT(removeClient()));

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
    pbLayout->addWidget(pbAdd);
    pbLayout->addWidget(pbRemoveClient);

    // left layout
    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addLayout(lbLayout);
    leftLayout->addLayout(leLayout);
    leftLayout->addLayout(yearLayout);
    leftLayout->addLayout(disLayout);
    leftLayout->addLayout(adrLayout);
    leftLayout->addLayout(pbLayout);

    listClient = new QListView;
    connect(listClient, SIGNAL(doubleClicked(const QModelIndex &)),
            this, SLOT(activeClickOnItemList(const QModelIndex &)));
    listClient->setSelectionMode(QAbstractItemView::NoSelection);

    // right layout
    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(listClient);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);

    QWidget *widget = new QWidget();
    setCentralWidget(widget);
    widget-> setLayout(mainLayout);
    setWindowTitle("Клиентская база");
}

// interface implementation

void MainForm::refresh()
{
    leLastName->setText(tr(""));
    leName->setText(tr(""));
    lePatronymic->setText(tr(""));
    cbYear->setCurrentIndex(-1);
    cbDisability->setCurrentIndex(-1);
    cbCotegory->setCurrentIndex(-1);
    teAddress->setText(tr(""));

}

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

int MainForm::getYear() const
{
    return cbYear->currentText().toInt();
}

Client::Disability MainForm::getDisability() const
{
    switch(cbDisability->currentIndex()) {
        case 1:
            return Client::War;
        case 2:
            return Client::Infancy;
        case 3:
            return Client::Work;
        case 4:
            return Client::General;
        default:
            return Client::EmptyDisability;
    }
}

Client::Group MainForm::getGroup() const
{
    switch(cbCotegory->currentIndex()) {
        case 1:
            return Client::GroupIII;
        case 2:
            return Client::GroupII;
        case 3:
            return Client::GroupI;
        default:
            qWarning() << "cbCotegory is not identified";
            return Client::EmptyGroup;
    }
}

QString MainForm::getAddress() const
{
    return teAddress->toPlainText();
}

void MainForm::setList( QStringList list )
{
    listClient->setModel( new QStringListModel(list) );
}


//! slots
void MainForm::activeSearch()
{
    emit actionFindClient();
}

void MainForm::activeAddition()
{
    if( leLastName->text() == 0 || leName->text() == 0
            || lePatronymic->text() == 0)
    {
        QMessageBox::warning(this, tr("Ошибка"),
                tr("Введите полностью Ф.И.О."), QMessageBox::Ok);
        return;
    }
    emit actionAddClient();
}

void MainForm::activeClickOnItemList(const QModelIndex &index)
{
    emit actionReturnIndex(index.row());
}

void MainForm::removeClient()
{
    emit(actionRemoveClient(listClient->currentIndex().row()));
}
