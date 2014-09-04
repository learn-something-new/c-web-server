#include "router.h"
#include "static.h"
#include <QVariant>
#include <QDateTime>

Router::Router(QObject* parent)
    :HttpRequestHandler(parent) {}

void Router::service(HttpRequest& request, HttpResponse& response) {
    QByteArray path=request.getPath();
    qDebug("RequestMapper: path=%s",path.data());

    response.setHeader("Content-Type", "text/html; charset=ISO-8859-1");
    HttpSession session=Static::sessionStore->getSession(request,response);
    if (!session.contains("startTime")) {
        response.write("<html><body>New session started. Reload this page now.</body></html>");
        session.set("startTime",QDateTime::currentDateTime());
    }

    else {
        QDateTime startTime=session.get("startTime").toDateTime();
        response.write("<html><body>Your session started ");
        response.write(startTime.toString().toLatin1());
        response.write("</body></html>");
    }

    qDebug("RequestMapper: finished request");
}
