#-------------------------------------------------
#
# Project created by QtCreator 2014-09-04T11:39:10
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = CWebServer
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

macx {
    CONFIG += c++11
}
else {
    QMAKE_CXXFLAGS += -std=c++11
}


include(bfHttpServer/src/bfHttpServer.pri)
include(qtservice/src/qtservice.pri)
include(bfLogging/src/bfLogging.pri)
include(bfTemplateEngine/src/bfTemplateEngine.pri)

HEADERS += \
    requerstmapper.h \
    server.h \
    static.h \
    router.h \
    sessioncontroller.h

SOURCES += \
    requerstmapper.cpp \
    main.cpp \
    server.cpp \
    static.cpp \
    router.cpp \
    sessioncontroller.cpp
