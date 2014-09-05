#include "router.h"
#include "static.h"
#include "twitter.h"
#include <QVariant>
#include <QDateTime>

Router::Router(QObject* parent)
    :HttpRequestHandler(parent)
{
    Twitter twitter;
    twitter.authorize();
}

void Router::service(HttpRequest& request, HttpResponse& response) {
    QByteArray path=request.getPath();
    qDebug("RequestMapper: path=%s",path.data());

    response.setHeader("Content-Type", "text/html; charset=ISO-8859-1");
    response.write("<html><body>Sup</body></html>");

    qDebug("RequestMapper: finished request");
}
