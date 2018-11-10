QT -= gui

TARGET      = SMServer

CONFIG += c++11 console
CONFIG -= app_bundle

include(NetWork/network.pri)

SOURCES += \
        main.cpp

RC_FILE += \
        version.rc
