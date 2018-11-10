QT -= gui

TARGET = SMGateway

CONFIG += c++11 console
CONFIG -= app_bundle

include(SerialPort/serialport.pri)
include(NetWork/network.pri)

SOURCES += \
        main.cpp  

HEADERS += \
        config.h

RC_FILE += \
        version.rc
