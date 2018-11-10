#include "mainpage.h"
#include <QApplication>
#include "serialportdev.h"
#include "serialportprotocol.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SerialPortDev::getObject();
    SerialPortProtocol::getObject();

    MainPage w;
    w.show();

    return a.exec();
}
