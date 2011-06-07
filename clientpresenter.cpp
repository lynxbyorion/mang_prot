#include <QMessageBox>

#include "clientpresenter.h"
#include "iviewform.h"

#include <QDebug>

ClientPreseter::ClientPreseter(IViewForm *view, QObject *perent)
    :QObject(perent), m_client(new Client), m_view(view)
{
    QObject* view_obj = dynamic_cast<QObject*>(view);
    QObject::connect(view_obj, SIGNAL(actionFindClient()),
            this, SLOT(identificationClient()));

    dbManager = new DataBaseManager();
    if (!dbManager->dbOpen())
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Ошибка!");
        msgBox.setText("Не могу подключиться к базе данных.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.exec();
        exit(1);

    }
}

void ClientPreseter::refreshView()
{
}

//! slots
void ClientPreseter::identificationClient()
{
    qWarning() << "in the slot identification";
}

