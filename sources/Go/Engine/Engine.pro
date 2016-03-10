#-------------------------------------------------
#
# Project created by QtCreator 2016-03-10T21:04:05
#
#-------------------------------------------------

QT       -= gui

TARGET = Engine
TEMPLATE = lib
CONFIG += staticlib

SOURCES += engine.cpp

HEADERS += engine.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
