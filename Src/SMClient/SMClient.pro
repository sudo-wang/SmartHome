#-------------------------------------------------
#
# Project created by QtCreator 2018-10-26T18:40:31
#
#-------------------------------------------------

QT          += core gui widgets

TARGET      = SMClient
TEMPLATE    = app

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

include(NetWork/network.pri)

SOURCES     += \
            main.cpp \
            mainpage.cpp \
    loginpage.cpp \
    appinit.cpp \
    iconhelper.cpp

HEADERS     += \
            mainpage.h \
            config.h \
    loginpage.h \
    appinit.h \
    iconhelper.h

FORMS       += \
            mainpage.ui \
    loginpage.ui

RC_FILE += \
            version.rc

RESOURCES += \
    images.qrc \
    images.qrc
