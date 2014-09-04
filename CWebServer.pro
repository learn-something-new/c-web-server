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
CONFIG += x86_64
CONFIG -= i386

TEMPLATE = app

include(bfHttpServer/src/bfHttpServer.pri)
include(qtservice/src/qtservice.pri)
include(bfLogging/src/bfLogging.pri)
include(bfTemplateEngine/src/bfTemplateEngine.pri)

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
    etc/QtWebApp.ini
