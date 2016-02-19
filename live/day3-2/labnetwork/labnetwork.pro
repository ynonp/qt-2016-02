#-------------------------------------------------
#
# Project created by QtCreator 2016-02-18T14:43:12
#
#-------------------------------------------------

QT       += core gui network quick qml widgets

CONFIG += c++11

TARGET = labnetwork
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    omdbapi.cpp

HEADERS  += mainwindow.h \
    omdbapi.h

FORMS    += mainwindow.ui

DISTFILES += \
    main.qml

RESOURCES += \
    main.qrc
