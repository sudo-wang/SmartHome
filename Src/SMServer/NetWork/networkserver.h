#ifndef NETWORKSERVER_H
#define NETWORKSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QJsonObject>
#include <QList>

//用来管理连接到该服务器的网关的信息
typedef struct
{
    QTcpSocket *socket;

    //从字符流中解析出JSON数据的中间变量
    int braNum;
    char lastChar;
    QByteArray readBuffer;

    //将解析到的网关发送的数据存储在每个网关的结构体中
    QJsonObject sensingData;
    int deviceID;
}ClientInfo;

class NetWorkServer : public QObject
{
    Q_OBJECT
private:
    explicit NetWorkServer(QObject *parent = nullptr);

public:
    static NetWorkServer * getObject();
    //监听对应端口，启动网络服务
    bool startNetWork(quint16 port);

    void sendDataToDevice(int deviceID,QJsonObject obj);
    bool getDataFromDevice(int deviceID,QJsonObject *data);

protected slots:
    void newConnectionSlot();
    void disconnectedSlot();
    void readyReadSlot();


protected:
    int getIndexOfClientList(QTcpSocket *s);
    int getIndexOfClientList(int deviceID);

    QTcpServer *server;
    QList<ClientInfo *> clientList;
};

#endif // NETWORKSERVER_H
