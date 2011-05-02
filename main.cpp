#include <QApplication>
#include <QTextCodec>
#include "mainform.h"

void initCodec(const char *codecName)
{
    QTextCodec *codec = QTextCodec::codecForName(codecName);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForTr(codec);
}

int main( int argc, char *argv[] )
{
    initCodec("UTF-8");
    QApplication app(argc, argv);

    MainForm mw;
    mw.show();

    return app.exec();
}
