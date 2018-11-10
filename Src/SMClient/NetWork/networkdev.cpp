#include "networkdev.h"
#include <QDebug>

NetWorkDev::NetWorkDev(QObject *parent) : QObject(parent)
{
    socket = new QTcpSocket;
    connect(socket,SIGNAL(connected()),
            this,SIGNAL(connected()));
    connect(socket,SIGNAL(connected()),
            this,SLOT(connectedSlot()));
    connect(socket,SIGNAL(disconnected()),
            this,SIGNAL(disconnected()));
    connect(socket,SIGNAL(disconnected()),
            this,SLOT(disconnectedSlot()));
    connect(socket,SIGNAL(readyRead()),
            this,SLOT(readyReadSlot()));
}

NetWorkDev *NetWorkDev::getObject()
{
    static NetWorkDev nwd;
    return &nwd;
}

void NetWorkDev::connectToServer(QString ip, int port)
{
    if( getNetWorkStatus() )
        socket->abort();
    socket->connectToHost(ip,port);
}

bool NetWorkDev::sendData(const QByteArray &data)
{
    bool ok = false;
    if(getNetWorkStatus())
    {
        qint64 len = socket->write(data);
        if(len != -1)
            ok = true;
    }
    return ok;
}

void NetWorkDev::readyReadSlot()
{
    QByteArray data;
    data = socket->readAll();
    emit readData(data);
}

void NetWorkDev::connectedSlot()
{
    qDebug() << "connect to server successful!";
}

void NetWorkDev::disconnectedSlot()
{
    qDebug() << "network disconnected!";
}

bool NetWorkDev::getNetWorkStatus()
{
    if(socket->state() ==
            QTcpSocket::ConnectedState)
        return true;
    return false;
}
