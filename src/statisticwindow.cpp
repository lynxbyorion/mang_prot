#include <QtGui>

#include "statisticwindow.h"
#include "databasemanager.h"

StatisticWindow::StatisticWindow()
{
    db = DataBaseManager::getInstance();
    allCount = 0;

    QLabel *prosthesis = new QLabel(tr("Протез: "));
    countProsthesis = new QLabel();

    QLabel *karset = new QLabel(tr("Карсет: "));
    countKarset = new QLabel();

    QLabel *splint = new QLabel(tr("Тутор: "));
    countSplint = new QLabel();

    QLabel *bandage = new QLabel(tr("Бандаж: "));
    countBandage = new QLabel();

    QLabel *knee = new QLabel(tr("Наколенники: "));
    countKnee = new QLabel();

    QLabel *trussAntral = new QLabel(tr("Грыжевой бандаж (антральная грыжа): "));
    countTrussAntral = new QLabel();

    QLabel *truss = new QLabel(tr("Грыжевой бандаж (паховая грыжа): "));
    countTruss = new QLabel();

    QLabel *orthopedicShoes = new QLabel(tr("Ортопедическая обувь: "));
    countShoes = new QLabel();

    QLabel *breast = new QLabel(tr("Протез молочной железы: "));
    countBreast = new QLabel();

    QLabel *headholder = new QLabel(tr("Головодержатель: "));
    countHeadholder = new QLabel();

    QLabel *all = new QLabel(tr("Общее колличество заказов: "));
    lbAllCount = new QLabel();

    beginDate = new QDateEdit();
    beginDate->setDisplayFormat("dd.MM.yyyy");
    connect(beginDate, SIGNAL(dateChanged(const QDate &)),
                this, SLOT(refresh()));

    endDate = new QDateEdit(QDate::currentDate());
    endDate->setDisplayFormat("dd.MM.yyyy");
    connect(endDate, SIGNAL(dateChanged(const QDate &)),
                this, SLOT(refresh()));

    refresh();

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
    articleLayout->addStrut(3);
    articleLayout->addWidget(all);

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
    countLayout->addWidget(lbAllCount);

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
    setFixedSize(600,400);
}

// slots
int StatisticWindow::getCoutArticle(int article)
{
    QString query;
    query = QString("SELECT COUNT(*) FROM clientorder WHERE article = %1 "
            "AND deliverydate > '%2' AND deliverydate < '%3'")
        .arg(article).arg(beginDate->date().toString("yyyy-MM-dd"))
        .arg(endDate->date().toString("yyyy-MM-dd"));

    int count =  db->getCountArticle(query);

    allCount += count;

    return count;
}

void StatisticWindow::refresh()
{
    allCount = 0;

    countProsthesis->setText(QString::number(getCoutArticle(0)));
    countKarset->setText(QString::number(getCoutArticle(1)));
    countSplint->setText(QString::number(getCoutArticle(2)));
    countBandage->setText(QString::number(getCoutArticle(3)));
    countKnee->setText(QString::number(getCoutArticle(4)));
    countTrussAntral->setText(QString::number(getCoutArticle(5)));
    countTruss->setText(QString::number(getCoutArticle(6)));
    countShoes->setText(QString::number(getCoutArticle(7)));
    countBreast->setText(QString::number(getCoutArticle(8)));
    countHeadholder->setText(QString::number(getCoutArticle(9)));

    lbAllCount->setText(QString::number(allCount));
}

