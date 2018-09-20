QT += core network
QT -= gui

TARGET = Network
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    client.cpp \
    mytcpserver.cpp

HEADERS += \
    client.h \
    mytcpserver.h
QMAKE_CXXFLAGS += -std=c++14
