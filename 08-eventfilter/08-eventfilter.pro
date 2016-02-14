#-------------------------------------------------
#
# Project created by QtCreator 2016-02-07T13:55:19
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 08-eventfilter
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    keysfilter.cpp \
    countedtextedit.cpp

HEADERS  += mainwindow.h \
    keysfilter.h \
    countedtextedit.h

FORMS    += mainwindow.ui \
    countedtextedit.ui
