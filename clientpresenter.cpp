#include "clientpresenter.h"
#include "iviewform.h"

#include <QDebug>

ClientPreseter::ClientPreseter(IViewForm *view, QObject *perent)
    :QObject(perent), m_client(new Client), m_view(view)
{
    QObject* view_obj = dynamic_cast<QObject*>(view);
    QObject::connect(view_obj, SIGNAL(actionFindClient()),
            this, SLOT(identificationClient()));
}

void ClientPreseter::refreshView()
{
}

void ClientPreseter::identificationClient()
{
    qWarning() << "in the slot identification";
}

