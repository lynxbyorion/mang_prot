#include <QtGui>
#include "mainform.h"
#include "defandpar.h"

MainForm::MainForm(QWidget *parent)
    : QWidget(parent)
{
    QLabel *lbSurname = new QLabel("Фамилия");
    leSurname = new QLineEdit();
    QLabel *lbName = new QLabel("Имя");
    leName = new QLineEdit();
    QLabel *lbPatronymic = new QLabel("Отчество");
    lePatronymic = new QLineEdit();

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

    // name label layout
    QHBoxLayout *lbLayout = new QHBoxLayout;
    lbLayout->addWidget(lbSurname);
    lbLayout->addWidget(lbName);
    lbLayout->addWidget(lbPatronymic);

    // name layout
    QHBoxLayout *leLayout = new QHBoxLayout;
    leLayout->addWidget(leSurname);
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

    // main layout
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(lbLayout);
    mainLayout->addLayout(leLayout);
    mainLayout->addLayout(yearLayout);
    mainLayout->addLayout(disLayout);
    mainLayout->addLayout(adrLayout);
    mainLayout->addLayout(pbLayout);

    setLayout(mainLayout);
    setWindowTitle("Клиентская база");
}

void MainForm::activeSearch()
{
}

