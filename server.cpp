#include "static.h"
#include "server.h"
#include "httplistener.h"
#include "router.h"
#include "staticfilecontroller.h"
#include <iostream>
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

    QSettings* fileSettings=new QSettings(configFileName,QSettings::IniFormat,app);
    fileSettings->beginGroup("docroot");
    Static::staticFileController=new StaticFileController(fileSettings,app);

    QSettings* sessionSettings=new QSettings(configFileName,QSettings::IniFormat,app);
    sessionSettings->beginGroup("sessions");
    Static::sessionStore=new HttpSessionStore(sessionSettings,app);

    qDebug("ServiceHelper: Starting service");
    QSettings* listenerSettings=new QSettings(configFileName,QSettings::IniFormat,app);
    listenerSettings->beginGroup("listener");
    listener=new HttpListener(listenerSettings,new Router(app),app);

    qWarning("ServiceHelper: Service has started");

    std::cout.flush();
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
