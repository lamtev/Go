#-------------------------------------------------
#
# Project created by QtCreator 2016-03-10T21:04:05
#
#-------------------------------------------------

QT       -= gui

QMAKE_CXXFLAGS += -std=c++11

TARGET = GoEngine
TEMPLATE = lib
CONFIG += staticlib

SOURCES += GoEngineInterface.cpp \
           Stone.cpp \
           Board.cpp


HEADERS += GoEngineInterface.h \
           enums.h \
           Stone.h \
           Board.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
