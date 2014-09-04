#include "static.h"
#include "server.h"
#include "httplistener.h"
#include "router.h"
#include <QDir>

#define APPNAME "CWebServer"
#define ORGANISATION "Obihann"
#define DESCRIPTION "Web service based on Qt"

HttpListener* listener;


void Server::start() {
    QCoreApplication* app = application();
    app->setApplicationName(APPNAME);
    app->setOrganizationName(ORGANISATION);
    QString configFileName=Static::getConfigDir()+"/"+QCoreApplication::applicationName()+".ini";

    qDebug("ServiceHelper: Starting service");
    QSettings* listenerSettings=new QSettings(configFileName,QSettings::IniFormat,app);
    listenerSettings->beginGroup("listener");
    listener=new HttpListener(listenerSettings,new Router(app),app);

    qWarning("ServiceHelper: Service has started");
}

void Server::stop() {
    delete listener;

    qWarning("ServiceHelper: Service has been stopped");
}

Server::Server(int argc, char *argv[])
    : QtService<QCoreApplication>(argc, argv, APPNAME)
{
    setServiceDescription(DESCRIPTION);
}
