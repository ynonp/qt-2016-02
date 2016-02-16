#-------------------------------------------------
#
# Project created by QtCreator 2016-02-16T13:47:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = customwidgets
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    counter.cpp \
    mylabel.cpp \
    filechooser.cpp \
    mypainteditem.cpp \
    lightbulb.cpp

HEADERS  += mainwindow.h \
    counter.h \
    mylabel.h \
    filechooser.h \
    mypainteditem.h \
    lightbulb.h

FORMS    += mainwindow.ui \
    counter.ui \
    filechooser.ui
