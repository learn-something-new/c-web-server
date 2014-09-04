#ifndef ROUTER_H
#define ROUTER_H

#include "httprequesthandler.h"

class Router : public HttpRequestHandler {
    Q_OBJECT
    Q_DISABLE_COPY(Router)
public:
    Router(QObject* parent=0);
    void service(HttpRequest& request, HttpResponse& response);
};

#endif // ROUTER_H
