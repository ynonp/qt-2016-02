TEMPLATE = app

QT += qml quick widgets

SOURCES += src/main.cpp \
    src/startup.cpp \
    src/mainviewmgr.cpp

CONFIG += c++11

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    src/startup.h \
    src/mainviewmgr.h

DISTFILES +=

