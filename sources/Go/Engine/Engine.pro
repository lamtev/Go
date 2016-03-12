#-------------------------------------------------
#
# Project created by QtCreator 2016-03-10T21:04:05
#
#-------------------------------------------------

QT       -= gui

QMAKE_CXXFLAGS += -std=c++11

TARGET = Engine
TEMPLATE = lib
CONFIG += staticlib

SOURCES += api.cpp


HEADERS += api.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
