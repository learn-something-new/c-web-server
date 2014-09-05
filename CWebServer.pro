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
    sessioncontroller.h \
    twitter.h

SOURCES += \
    main.cpp \
    server.cpp \
    static.cpp \
    router.cpp \
    sessioncontroller.cpp \
    twitter.cpp

OTHER_FILES += \
    etc/CWebServer.ini

unix: LIBS += -L$$PWD/../../../../usr/local/lib/ -loauth

INCLUDEPATH += $$PWD/../../../../usr/local/include
DEPENDPATH += $$PWD/../../../../usr/local/include

unix: PRE_TARGETDEPS += $$PWD/../../../../usr/local/lib/liboauth.a

unix: LIBS += -L$$PWD/../../../../usr/local/Cellar/curl/7.37.1/lib/ -lcurl

INCLUDEPATH += $$PWD/../../../../usr/local/Cellar/curl/7.37.1/include
DEPENDPATH += $$PWD/../../../../usr/local/Cellar/curl/7.37.1/include

unix: PRE_TARGETDEPS += $$PWD/../../../../usr/local/Cellar/curl/7.37.1/lib/libcurl.a
