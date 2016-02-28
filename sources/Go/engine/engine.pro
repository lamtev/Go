#-------------------------------------------------
#
# Project created by QtCreator 2016-02-28T20:00:14
#
#-------------------------------------------------

QT       -= core gui

TARGET = engine
TEMPLATE = lib
CONFIG += staticlib

QMAKE_CXXFLAGS += -std=c++11

SOURCES +=

HEADERS +=
unix {
    target.path = /usr/lib
    INSTALLS += target
}
