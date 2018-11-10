#ifndef NETWORKDEV_H
#define NETWORKDEV_H

#include <QObject>
#include <QTcpSocket>

class NetWorkDev : public QObject
{
    Q_OBJECT
private:
    explicit NetWorkDev(QObject *parent = nullptr);

public:
    static NetWorkDev * getObject();
    //连接服务器
    //@param ip IP地址
    //@param port 端口
    void connectToServer(QString ip,int port);
    //向服务器发送数据
    //@param data 要发送的数据
    //@return bool 发送结果
    bool sendData(const QByteArray &data);

signals:
    //接收到数据信号
    //@param data 接收到的数据
    void readData(const QByteArray &data);
    //成功连接
    void connected();
    //与服务器断开连接
    void disconnected();

protected slots:
    void readyReadSlot();
    void connectedSlot();
    void disconnectedSlot();

protected:
    bool getNetWorkStatus();

    QTcpSocket *socket;

};









#endif // NETWORKDEV_H
