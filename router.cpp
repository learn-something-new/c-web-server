#include "router.h"
#include "static.h"
#include <QVariant>
#include <QDateTime>

Router::Router(QObject* parent)
    :HttpRequestHandler(parent)
{
}

void Router::service(HttpRequest& request, HttpResponse& response) {

    response.setHeader("Content-Type", "text/html; charset=ISO-8859-1");
    response.write("<html><body>");
    response.write("Hello World");
    //response.write(results.toLocal8Bit().data());
    response.write("</body></html>");

    qDebug("RequestMapper: finished request");
}
