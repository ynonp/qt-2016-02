#-------------------------------------------------
#
# Project created by QtCreator 2016-02-14T13:10:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 16-threads
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    producer.cpp \
    consumer.cpp

HEADERS  += mainwindow.h \
    producer.h \
    consumer.h

FORMS    += mainwindow.ui
