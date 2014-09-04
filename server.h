#ifndef SERVER_H
#define SERVER_H

#include <QtCore/QCoreApplication>
#include "qtservice.h"

class Server : public QtService<QCoreApplication>
{
public:
    Server(int argc, char *argv[]);
protected:
    void start();
    void stop();
};


#endif // SERVER_H
