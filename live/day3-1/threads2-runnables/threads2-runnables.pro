#-------------------------------------------------
#
# Project created by QtCreator 2016-02-18T09:57:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = threads2-runnables
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mytask.cpp \
    counter.cpp \
    countertask.cpp

HEADERS  += mainwindow.h \
    mytask.h \
    counter.h \
    countertask.h

FORMS    += mainwindow.ui
