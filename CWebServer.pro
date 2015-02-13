QT = core network
TARGET = CWebServer
TEMPLATE = app
CONFIG   += console
CONFIG   -= app_bundle

include(bfHttpServer/src/bfHttpServer.pri)
include(qtservice/src/qtservice.pri)

HEADERS += \
    server.h \
    static.h \
    router.h \
    sessioncontroller.h

SOURCES += \
    main.cpp \
    server.cpp \
    static.cpp \
    router.cpp \
    sessioncontroller.cpp

OTHER_FILES += \
    etc/CWebServer.ini
