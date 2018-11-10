#ifndef NETWORKPROTOCOL_H
#define NETWORKPROTOCOL_H

#include <QObject>
#include <QJsonObject>
#include <QTimer>
typedef enum {
    Heating,
    Refrigeration,
    Dehumidification,
    AirSupply,
    _close
}Modules;

typedef enum {
    Auto,
    One,
    Two,
    Three,
    Four,
    Five
}Fun;

class NetWorkProtocol : public QObject
{
    Q_OBJECT
private:
    explicit NetWorkProtocol(QObject *parent = nullptr);

public:
    //各种传感器数据
    bool bReserve1;
    int atmospheric1;
    bool bReserve2;
    bool bReserve3;
    bool bReserve4;
    bool bReserve5;
    int co21;
    bool fire1;
    int hu1;
    bool iReserve1;
    int iReserve2;
    int light1;
    bool mq21;
    bool mq51;
    bool os1;
    int pm101;
    int pm251;
    bool re1;
    double te1;
    double uv1;
    QTimer *time;
    static NetWorkProtocol *getObject();
    //请求设备传感数据
    void requestSensingData(int id);

    //设置下位机设备的接口
    void setAir(int id,int index,Modules modules,Fun fun,int te);
    void setHeart(int id,int index,int te);
    void setLed(int id,int index,int b);
    void setCurtains(int id,int index,int pos);

signals:
    void newSensingData(int id,QJsonObject data);

protected slots:
    void readDataSlot(const QByteArray &data);
    //定时器溢出时的槽函数
    void timeoutSlot();

protected:
    void handleData(const QJsonObject &obj);
    void sendData(const QJsonObject &obj);

    int braNum = 0;
    char lastChar = ' ';
    QByteArray readBuffer;
};

#endif // NETWORKPROTOCOL_H
