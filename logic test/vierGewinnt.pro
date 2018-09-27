#-------------------------------------------------
#
# Project created by QtCreator 2018-09-20T18:56:30
#
#-------------------------------------------------

QT       += core gui widgets network

TARGET = test4
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++14

SOURCES += \
        main.cpp \
        dialog.cpp \
    mainwindow.cpp \
    client.cpp \
    manager.cpp \
    mytcpserver.cpp \
    spiel.cpp \
    connector.cpp \
    gridcontainer.cpp \
    stone.cpp

HEADERS += \
        dialog.h \
    mainwindow.h \
    dialog.h \
    ../manager.hpp \
    client.h \
    manager.hpp \
    mytcpserver.h \
    spiel.hpp \
    connector.hpp \
    gridcontainer.h \
    stone.h

FORMS += \
        dialog.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
