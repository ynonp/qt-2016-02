QT += core network
QT -= gui

TARGET = netdemo1
CONFIG += console c++11
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    omdbapi.cpp

HEADERS += \
    omdbapi.h

