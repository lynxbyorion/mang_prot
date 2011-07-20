#include <QtGui>

#include "statisticwindow.h"
#include "databasemanager.h"

StatisticWindow::StatisticWindow()
{
    db = DataBaseManager::getInstance();

    QLabel *prosthesis = new QLabel(tr("Протез: "));
    countProsthesis = new QLabel(QString::number(getCoutArticle(0)));

    QLabel *karset = new QLabel(tr("Карсет: "));
    countKarset = new QLabel(QString::number(getCoutArticle(1)));

    QLabel *splint = new QLabel(tr("Тутор: "));
    countSplint = new QLabel(QString::number(getCoutArticle(2)));

    QLabel *bandage = new QLabel(tr("Бандаж: "));
    countBandage = new QLabel(QString::number(getCoutArticle(3)));

    QLabel *knee = new QLabel(tr("Наколенники: "));
    countKnee = new QLabel(QString::number(getCoutArticle(4)));

    QLabel *trussAntral = new QLabel(tr("Грыжевой бандаж (антральная грыжа): "));
    countTrussAntral = new QLabel(QString::number(getCoutArticle(5)));

    QLabel *truss = new QLabel(tr("Грыжевой бандаж (паховая грыжа): "));
    countTruss = new QLabel(QString::number(getCoutArticle(6)));

    QLabel *orthopedicShoes = new QLabel(tr("Ортопедическая обувь: "));
    countShoes = new QLabel(QString::number(getCoutArticle(7)));

    QLabel *breast = new QLabel(tr("Протез молочной железы: "));
    countBreast = new QLabel(QString::number(getCoutArticle(8)));

    QLabel *headholder = new QLabel(tr("Головодержатель: "));
    countHeadholder = new QLabel(QString::number(getCoutArticle(9)));

    beginDate = new QDateEdit();

    endDate = new QDateEdit(QDate::currentDate());

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

    QVBoxLayout *countLayout = new QVBoxLayout;
    countLayout->addWidget(countProsthesis);
    countLayout->addWidget(countKarset);
    countLayout->addWidget(countSplint);
    countLayout->addWidget(countBandage);
    countLayout->addWidget(countKnee);
    countLayout->addWidget(countTrussAntral);
    countLayout->addWidget(countTruss);
    countLayout->addWidget(countShoes);
    countLayout->addWidget(countBreast);
    countLayout->addWidget(countHeadholder);

    QHBoxLayout *topLayout = new QHBoxLayout;
    topLayout->addLayout(articleLayout);
    topLayout->addLayout(countLayout);

    QHBoxLayout *dateLayout = new QHBoxLayout;
    dateLayout->addStretch();
    dateLayout->addWidget(beginDate);
    dateLayout->addWidget(endDate);

    QHBoxLayout *buttonLyaout = new QHBoxLayout;
    buttonLyaout->addStretch();
    buttonLyaout->addWidget(pbPrint);
    buttonLyaout->addWidget(pbClose);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(topLayout);
    mainLayout->addLayout(dateLayout);
    mainLayout->addLayout(buttonLyaout);

    setLayout(mainLayout);

    setWindowTitle(tr("Статистика"));
    //setFixedSize(600,400);
}

// slots
int StatisticWindow::getCoutArticle(int article)
{
    QString query;
    query = QString("SELECT COUNT(*) FROM clientorder WHERE article = %1 "
            "AND deliverydate > '%2' AND deliverydate < '%3'")
        .arg(article).arg("1970-01-02").arg("2000-11-01");

    return db->getCountArticle(query);
}
