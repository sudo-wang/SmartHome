#include <QCoreApplication>
#include <QDebug>
#include "networkserver.h"
#include "networkuserserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if(NetWorkServer::getObject()->startNetWork(10086))
        qDebug() << "Device server start...";
    else
        qDebug() << "Device server start error!";

    if(NetWorkUserServer::getObject()->startNetWork(10010))
        qDebug() << "User server start...";
    else
        qDebug() << "User server start error!";

    return a.exec();
}
