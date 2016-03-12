#-------------------------------------------------
#
# Project created by QtCreator 2016-03-10T21:07:03
#
#-------------------------------------------------

QT       -= core gui

QMAKE_CXXFLAGS += -std=c++11

TARGET = AI
TEMPLATE = lib
CONFIG += staticlib

SOURCES += ai.cpp

HEADERS += ai.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
