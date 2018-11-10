#include "networkprotocol.h"
#include "networkdev.h"
#include <QJsonObject>
#include <QJsonDocument>
#include "serialportprotocol.h"
#include "config.h"

NetWorkProtocol::NetWorkProtocol(QObject *parent) : QObject(parent)
{
    readBuffer.clear();
    updateTimer = new QTimer;

    connect(updateTimer,SIGNAL(timeout()),
            this,SLOT(updateTimerTimeoutSlot()));

    updateTimer->start(5000);

    connect(NetWorkDev::getObject(),
            SIGNAL(readData(QByteArray)),
            this,
            SLOT(readDataSlot(QByteArray)));
}

NetWorkProtocol *NetWorkProtocol::getObject()
{
    static NetWorkProtocol nwp;
    return &nwp;
}

void NetWorkProtocol::sendSensingData(QJsonObject obj)
{
    obj.insert("type","sensingData");
    obj.insert("id",DEVICEID);
    NetWorkDev::getObject()->sendData(QJsonDocument(obj).toJson());
}

void NetWorkProtocol::readDataSlot(const QByteArray &data)
{
    //解析连续字符串中的多个JSON数据包
    for(qint64 i = 0; i < data.length(); i++)
    {
        if(readBuffer.length() > 0 && data.at(i) == '{'
                && lastChar != ':' && lastChar != '['
                && lastChar != ',')
        {
            //接收到开头，之前的数据不完整丢弃
            readBuffer.clear();
            readBuffer.append(data.at(i));
            lastChar = data.at(i);
            braNum = 1;
            continue;
        }
        if(data.at(i) == '{')
        {
            braNum++;
            readBuffer.append(data.at(i));
            lastChar = '{';
            continue;
        }
        else if(data.at(i) == '}')
        {
            braNum--;
            readBuffer.append(data.at(i));
            lastChar = '}';
            if(braNum == 0)
            {
                //一条完整数据
                QJsonObject obj = QJsonDocument::fromJson(readBuffer)
                        .object();
                //数据处理
                handleData(obj);
                //数据清空
                readBuffer.clear();
                braNum = 0;
            }
            continue;
        }
        else
        {
            readBuffer.append(data.at(i));
            if(data.at(i) != ' ' && data.at(i) != '\n'
               && data.at(i) != '\t' && data.at(i) != 0x0a)
                lastChar = data.at(i);
            continue;
        }
    }
}

void NetWorkProtocol::updateTimerTimeoutSlot()
{
    QJsonObject obj;
    obj.insert("te1",SerialPortProtocol::getObject()->te1);
    obj.insert("hu1",SerialPortProtocol::getObject()->hu1);
    obj.insert("light1",SerialPortProtocol::getObject()->light1);
    obj.insert("uv1",SerialPortProtocol::getObject()->uv1);
    obj.insert("co21",SerialPortProtocol::getObject()->co21);
    obj.insert("pm251",SerialPortProtocol::getObject()->pm251);
    obj.insert("pm101",SerialPortProtocol::getObject()->pm101);
    obj.insert("atmospheric1",SerialPortProtocol::getObject()->atmospheric1);
    obj.insert("iReserve1",SerialPortProtocol::getObject()->iReserve1);
    obj.insert("iReserve2",SerialPortProtocol::getObject()->iReserve2);
    obj.insert("fire1",SerialPortProtocol::getObject()->fire1);
    obj.insert("mq21",SerialPortProtocol::getObject()->mq21);
    obj.insert("mq51",SerialPortProtocol::getObject()->mq51);
    obj.insert("os1",SerialPortProtocol::getObject()->os1);
    obj.insert("re1",SerialPortProtocol::getObject()->re1);
    obj.insert("bReserve1",SerialPortProtocol::getObject()->bReserve1);
    obj.insert("bReserve2",SerialPortProtocol::getObject()->bReserve2);
    obj.insert("bReserve3",SerialPortProtocol::getObject()->bReserve3);
    obj.insert("bReserve4",SerialPortProtocol::getObject()->bReserve4);
    obj.insert("bReserve5",SerialPortProtocol::getObject()->bReserve5);
    sendSensingData(obj);
}

void NetWorkProtocol::handleData(const QJsonObject &obj)
{
    //网关接收到服务器发送的命令，解析之后通过串口发送给设备
    QString type = obj.value("type").toString();
    if(type == "openAir")   //空调
    {
        int index = obj.value("index").toInt();
        int modle = obj.value("modle").toInt();
        int te = obj.value("te").toInt();
        int fun = obj.value("fun").toInt();
        SerialPortProtocol::getObject()->setAir(index,modle,te,fun);
    }
    else if(type == "openLed")   //LED
    {
        int index = obj.value("index").toInt();
        int b = obj.value("b").toInt();
        SerialPortProtocol::getObject()->setLed(index,b);
    }
    else if(type == "openHeart")   //热水器
    {
        int index = obj.value("index").toInt();
        int te = obj.value("te").toInt();
        SerialPortProtocol::getObject()->setHeart(index,te);
    }
    else if(type == "openCurtains")   //窗帘
    {
        int index = obj.value("index").toInt();
        int pos = obj.value("pos").toInt();
        SerialPortProtocol::getObject()->setCurtains(index,pos);
    }
}
