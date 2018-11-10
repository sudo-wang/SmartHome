#include "networkuserserver.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include "networkserver.h"

NetWorkUserServer::NetWorkUserServer(QObject *parent) : QObject(parent)
{
    server = new QTcpServer;
    connect(server,SIGNAL(newConnection()),
            this,SLOT(newConnectionSlot()));
}

NetWorkUserServer *NetWorkUserServer::getObject()
{
    static NetWorkUserServer nws;
    return &nws;
}

bool NetWorkUserServer::startNetWork(quint16 port)
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

void NetWorkUserServer::newConnectionSlot()
{
    QTcpSocket *socket = server->nextPendingConnection();

    connect(socket,SIGNAL(disconnected()),
            this,SLOT(disconnectedSlot()));
    connect(socket,SIGNAL(readyRead()),
            this,SLOT(readyReadSlot()));

    UserClientInfo *info = new UserClientInfo;
    info->braNum = 0;
    info->lastChar = ' ';
    info->readBuffer.clear();
    info->socket = socket;
    clientList.append(info);
}

void NetWorkUserServer::disconnectedSlot()
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

void NetWorkUserServer::readyReadSlot()
{
    QTcpSocket *socket = (QTcpSocket *)sender();
    int index =  getIndexOfClientList(socket);
    if(index == -1)
        return;
    QByteArray data = socket->readAll();
    UserClientInfo *info = clientList.at(index);
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
                QString type = obj.value("type").toString();
                int id = obj.value("id").toInt();
                if(type == "requestData")
                {
                    QJsonObject data;
                    if(NetWorkServer::getObject()->getDataFromDevice(id,&data))
                    {
                        socket->write(QJsonDocument(data).toJson());
                    }
                }
                else
                {
                    NetWorkServer::getObject()->sendDataToDevice(id,obj);
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

int NetWorkUserServer::getIndexOfClientList(QTcpSocket *s)
{
    for(int i = 0; i < clientList.length(); i++)
    {
        if(clientList.at(i)->socket == s)
            return i;
    }
    return -1;
}
