#include <QApplication>
#include <QTextCodec>

#include "mainform.h"
#include "mainpresenter.h"

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

    MainForm* mainWindow = new MainForm();
    MainPresenter* presenter = new MainPresenter(mainWindow);
    Q_UNUSED(presenter);
    mainWindow->show();

    return app.exec();
}
