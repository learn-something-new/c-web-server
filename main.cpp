#include "server.h"
#include "httplistener.h"

#include <QtCore/QCoreApplication>
#include <QtCore/QSettings>
#include <QtCore/QDir>
#include <QtCore/QString>

int main(int argc, char *argv[])
{
    Server server(argc, argv);
    return server.exec();
}
