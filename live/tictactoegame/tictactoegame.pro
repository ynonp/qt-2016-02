TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    tictactoegame.cpp \
    tictactoegameengine.cpp \
    tictactoegamelist.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    tictactoegame.h \
    tictactoegameengine.h \
    tictactoegamelist.h

CONFIG += c++11
