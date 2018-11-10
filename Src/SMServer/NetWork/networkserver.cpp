#include "networkserver.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

NetWorkServer::NetWorkServer(QObject *parent) : QObject(parent)
{
    server = new QTcpServer;
    connect(server,SIGNAL(newConnection()),
            this,SLOT(newConnectionSlot()));
}

NetWorkServer *NetWorkServer::getObject()
{
    static NetWorkServer nws;
    return &nws;
}

bool NetWorkServer::startNetWork(quint16 port)
{
    if(server->isListening())
    {
        server->close();
        for(int i = 0; i < clientList.length(); i++)
        {
            //解绑信号与槽
            disconnect(clientList.at(i)->socket,0,0,0);
            clientList.at(i)->socket->abort();
            delete clientList.at(i);
        }
        clientList.clear();
    }
    return server->listen(QHostAddress::AnyIPv4,port);
}

void NetWorkServer::sendDataToDevice(int deviceID, QJsonObject obj)
{
    int index = getIndexOfClientList(deviceID);
    if(index == -1)
        return;
    clientList.at(index)->socket->write(QJsonDocument(obj).toJson());
}

bool NetWorkServer::getDataFromDevice(int deviceID, QJsonObject *data)
{
    int index = getIndexOfClientList(deviceID);
    if(index == -1)
        return false;
    *data = clientList.at(index)->sensingData;
    return true;
}

void NetWorkServer::newConnectionSlot()
{
    QTcpSocket *socket = server->nextPendingConnection();

    connect(socket,SIGNAL(disconnected()),
            this,SLOT(disconnectedSlot()));
    connect(socket,SIGNAL(readyRead()),
            this,SLOT(readyReadSlot()));

    ClientInfo *info = new ClientInfo;
    info->braNum = 0;
    info->lastChar = ' ';
    info->readBuffer.clear();
    info->socket = socket;
    info->deviceID = 0;
    clientList.append(info);
}

void NetWorkServer::disconnectedSlot()
{
    QTcpSocket *socket = (QTcpSocket *)sender();
    for(int i = 0; i < clientList.length(); i++)
    {
        if(clientList.at(i)->socket == socket)
        {
            delete clientList.at(i);
            clientList.removeAt(i);
            return;
        }
    }
}

void NetWorkServer::readyReadSlot()
{
    QTcpSocket *socket = (QTcpSocket *)sender();
    int index =  getIndexOfClientList(socket);
    if(index == -1)
        return;
    QByteArray data = socket->readAll();
    ClientInfo *info = clientList.at(index);
    for(qint64 i = 0; i < data.length(); i++)
    {
        if(info->readBuffer.length() > 0 && data.at(i) == '{'
                && info->lastChar != ':' && info->lastChar != '['
                && info->lastChar != ',')
        {
            //接收到开头，之前的数据不完整丢弃
            info->readBuffer.clear();
            info->readBuffer.append(data.at(i));
            info->lastChar = data.at(i);
            info->braNum = 1;
            continue;
        }
        if(data.at(i) == '{')
        {
            info->braNum++;
            info->readBuffer.append(data.at(i));
            info->lastChar = '{';
            continue;
        }
        else if(data.at(i) == '}')
        {
            info->braNum--;
            info->readBuffer.append(data.at(i));
            info->lastChar = '}';
            if(info->braNum == 0)
            {
                //一条完整数据
                QJsonObject obj = QJsonDocument::fromJson(info->readBuffer)
                        .object();
                //数据处理
                if(obj.value("type").toString() == "sensingData")
                {
                    info->deviceID = obj.value("id").toInt();
                    info->sensingData = obj;
                }
                //数据清空
                info->readBuffer.clear();
                info->braNum = 0;
            }
            continue;
        }
        else
        {
            info->readBuffer.append(data.at(i));
            if(data.at(i) != ' ' && data.at(i) != '\n'
               && data.at(i) != '\t' && data.at(i) != 0x0a)
                info->lastChar = data.at(i);
            continue;
        }
    }
}

int NetWorkServer::getIndexOfClientList(QTcpSocket *s)
{
    for(int i = 0; i < clientList.length(); i++)
    {
        if(clientList.at(i)->socket == s)
            return i;
    }
    return -1;
}

int NetWorkServer::getIndexOfClientList(int deviceID)
{
    for(int i = 0; i < clientList.length(); i++)
    {
        if(clientList.at(i)->deviceID == deviceID)
            return i;
    }
    return -1;
}
