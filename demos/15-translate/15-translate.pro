#-------------------------------------------------
#
# Project created by QtCreator 2016-02-14T11:53:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 15-translate
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui


TRANSLATIONS += app_he.ts
CODECFORTR = UTF-8

RESOURCES += \
    app.qrc
