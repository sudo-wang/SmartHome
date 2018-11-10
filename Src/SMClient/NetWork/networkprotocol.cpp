#include "networkprotocol.h"
#include "networkdev.h"
#include <QJsonObject>
#include <QJsonDocument>
#include "config.h"
#include <QDebug>

NetWorkProtocol::NetWorkProtocol(QObject *parent) : QObject(parent)
{
    readBuffer.clear();
    time = new QTimer;
    connect(time,SIGNAL(timeout()),this,SLOT(timeoutSlot()));
    time->start(3000);
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
//可调用请求数据接口
void NetWorkProtocol::requestSensingData(int id)
{
    QJsonObject obj;
    obj.insert("type","requestData");
    obj.insert("id",id);
    sendData(obj);
}
//可调用操作空调函数
void NetWorkProtocol::setAir(int id, int index, Modules modules, Fun fun, int te)
{
    QJsonObject obj;
    obj.insert("type","openAir");
    obj.insert("id",id);
    obj.insert("index",index);
    obj.insert("te",te);
    obj.insert("modle",modules);
    obj.insert("fun",fun);
    sendData(obj);
}
//调用操作热水器函数
void NetWorkProtocol::setHeart(int id, int index, int te)
{
    QJsonObject obj;
    obj.insert("type","openHeart");
    obj.insert("id",id);
    obj.insert("index",index);//序号
    obj.insert("te",te);
    sendData(obj);
}
//操作LED
void NetWorkProtocol::setLed(int id, int index, int b)
{
    QJsonObject obj;
    obj.insert("type","openLed");
    obj.insert("id",id);
    obj.insert("index",index);//序号
    obj.insert("b",b);
    sendData(obj);
}
//操作窗帘
void NetWorkProtocol::setCurtains(int id, int index, int pos)
{
    QJsonObject obj;
    obj.insert("type","openCurtains");
    obj.insert("id",id);
    obj.insert("index",index);//窗帘序号
    obj.insert("pos",pos);//距离
    sendData(obj);
}

void NetWorkProtocol::readDataSlot(const QByteArray &data)
{
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

void NetWorkProtocol::timeoutSlot()
{
    requestSensingData(1001);
}

void NetWorkProtocol::handleData(const QJsonObject &obj)
{
    QString type = obj.value("type").toString();
    if(type == "sensingData")   //传感数据
    {
        int id = obj.value("id").toInt();
        emit newSensingData(id,obj);
        qDebug() << obj;
        bReserve1 = obj.value("bReserve1").toBool();
        qDebug() << "bReserve1"<<bReserve1;
        bReserve2 = obj.value("bReserve2").toBool();
        qDebug() << " bReserve2"<< bReserve2;
        bReserve3 = obj.value("bReserve3").toBool();
        qDebug() << " bReserve3"<< bReserve3;
        bReserve4 = obj.value("bReserve4").toBool();
        qDebug() << " bReserve4"<< bReserve4;
        bReserve5 = obj.value("bReserve5").toBool();
        qDebug() << " bReserve5"<<bReserve5;
        atmospheric1 = obj.value("atmospheric1").toInt();
        qDebug() << " atmospheric1"<< atmospheric1;
        co21 = obj.value("co21").toInt();
        qDebug() << "co21"<< co21;
        fire1 = obj.value("fire1").toBool();
        qDebug() << " fire1"<< fire1;
        hu1 = obj.value("hu1").toInt();
        qDebug() << " hu1"<< hu1;
        iReserve1 = obj.value("iReserve1").toInt();
        qDebug() << " iReserve1"<< iReserve1;
        iReserve2 = obj.value("iReserve2").toInt();
        qDebug() << " iReserve2 "<<iReserve2 ;
        light1 = obj.value("light1").toInt();
        qDebug() << " light1"<< light1;
        mq21 = obj.value("mq21").toBool();
        qDebug() << " mq21 "<< mq21 ;
        mq51 = obj.value("mq51").toBool();
        qDebug() << "mq51"<< mq51;
        os1 = obj.value("os1").toBool();
        qDebug() << " os1"<<os1;
        pm101 = obj.value(" pm101").toInt();
        qDebug() << "  pm101"<<  pm101;
        pm251 = obj.value(" pm251").toInt();
        qDebug() << " pm251"<< pm251;
        re1 = obj.value("re1").toBool();
        qDebug() << "re1"<< re1;
        te1 = obj.value("te1").toDouble();
        qDebug() << " te1 "<<te1 ;
        uv1 = obj.value("uv1").toDouble();
        qDebug() << "uv1"<< uv1;

    }

}

void NetWorkProtocol::sendData(const QJsonObject &obj)
{
    NetWorkDev::getObject()->sendData(QJsonDocument(obj).toJson());
}
