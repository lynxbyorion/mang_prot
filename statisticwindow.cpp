#include <QtGui>

#include "statisticwindow.h"

StatisticWindow::StatisticWindow()
{
    QLabel *prosthesis = new QLabel(tr("Протез: "));

    QLabel *karset = new QLabel(tr("Карсет: "));

    QLabel *splint = new QLabel(tr("Тутор: "));

    QLabel *bandage = new QLabel(tr("Бандаж: "));

    QLabel *knee = new QLabel(tr("Наколенники: "));

    QLabel *trussAntral = new QLabel(tr("Грыжевой бандаж (антральная грыжа): "));

    QLabel *truss = new QLabel(tr("Грыжевой бандаж (паховая грыжа): "));

    QLabel *orthopedicShoes = new QLabel(tr("Ортопедическая обувь: "));

    QLabel *breast = new QLabel(tr("Протез молочной железы: "));

    QLabel *headholder = new QLabel(tr("Головодержатель: "));

    pbPrint = new QPushButton(tr("Печать"));
    pbPrint->setEnabled(false); // FIXME

    pbClose = new QPushButton(tr("Закрыть"));
    connect(pbClose, SIGNAL(clicked()), this, SLOT(close()));

    QVBoxLayout *articleLayout = new QVBoxLayout;
    articleLayout->addWidget(prosthesis);
    articleLayout->addWidget(karset);
    articleLayout->addWidget(splint);
    articleLayout->addWidget(bandage);
    articleLayout->addWidget(knee);
    articleLayout->addWidget(trussAntral);
    articleLayout->addWidget(truss);
    articleLayout->addWidget(orthopedicShoes);
    articleLayout->addWidget(breast);
    articleLayout->addWidget(headholder);

    QHBoxLayout *buttonLyaout = new QHBoxLayout;
    buttonLyaout->addStretch();
    buttonLyaout->addWidget(pbPrint);
    buttonLyaout->addWidget(pbClose);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(articleLayout);
    mainLayout->addLayout(buttonLyaout);

    setLayout(mainLayout);

    setWindowTitle(tr("Статистика"));
    setFixedSize(600,400);

}
