#ifndef NETWORKUSERSERVER_H
#define NETWORKUSERSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QJsonObject>
#include <QList>

typedef struct
{
    QTcpSocket *socket;
    int braNum;
    char lastChar;
    QByteArray readBuffer;
}UserClientInfo;

class NetWorkUserServer : public QObject
{
    Q_OBJECT
private:
    explicit NetWorkUserServer(QObject *parent = nullptr);

public:
    static NetWorkUserServer * getObject();
    //监听对应端口，启动网络服务
    bool startNetWork(quint16 port);

protected slots:
    void newConnectionSlot();
    void disconnectedSlot();
    void readyReadSlot();


protected:
    int getIndexOfClientList(QTcpSocket *s);

    QTcpServer *server;
    QList<UserClientInfo *> clientList;
};

#endif // NETWORKUSERSERVER_H
