QT       += core gui widgets

TARGET = SMDeviceAnalog
TEMPLATE = app

include(SerialPort/serialport.pri)
include(ProgressBar/progressbar.pri)

SOURCES += \
        main.cpp \
        mainpage.cpp

HEADERS += \
        mainpage.h

FORMS += \
        mainpage.ui    

RESOURCES += \
        images.qrc

RC_FILE += \
        version.rc
