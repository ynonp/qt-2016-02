#-------------------------------------------------
#
# Project created by QtCreator 2016-02-17T10:28:23
#
#-------------------------------------------------

QT       += core gui

CONFIG += c++11


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mymodels
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    numbersmodel.cpp

HEADERS  += mainwindow.h \
    numbersmodel.h

FORMS    += mainwindow.ui
