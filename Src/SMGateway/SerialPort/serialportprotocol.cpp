#include <QDebug>
#include "serialportprotocol.h"
#include "serialportdev.h"

SerialPortProtocol::SerialPortProtocol(QObject *parent) : QObject(parent)
{
    updateTimer = new QTimer;
    connect(updateTimer,SIGNAL(timeout()),
            this,SLOT(updateTimerTimeoutSlot()));
    updateTimer->start(200);

    sendData.head[0] = 0xFE;
    sendData.head[1] = 0xFE;
    sendData.retain[0] = 0x00;
    sendData.retain[1] = 0x00;
    sendData.retain[2] = 0x00;
    sendData.foot = 0xFF;

    connect(SerialPortDev::getObject(),
            SIGNAL(readFromSerial(QByteArray)),
            this,
            SLOT(readFromSerialSlot(QByteArray)));
}

SerialPortProtocol *SerialPortProtocol::getObject()
{
    static SerialPortProtocol spp;
    return &spp;
}

void SerialPortProtocol::setAir(int index, int modle, int te, int fun)
{
    sendData.len = 8+4;
    sendData.deviceID = 0x01;
    sendData.data[0] = index;
    sendData.data[1] = modle;
    sendData.data[2] = te;
    sendData.data[3] = fun;
    sendDataToSerialPort();
}

void SerialPortProtocol::setLed(int index, int b)
{
    sendData.len = 8+2;
    sendData.deviceID = 0x02;
    sendData.data[0] = index;
    sendData.data[1] = b;
    sendDataToSerialPort();
}

void SerialPortProtocol::setHeart(int index, int te)
{
    sendData.len = 8+2;
    sendData.deviceID = 0x04;
    sendData.data[0] = index;
    sendData.data[1] = te;
    sendDataToSerialPort();
}

void SerialPortProtocol::setCurtains(int index, int pos)
{
    sendData.len = 8+2;
    sendData.deviceID = 0x06;
    sendData.data[0] = index;
    sendData.data[1] = pos;
    sendDataToSerialPort();
}

void SerialPortProtocol::getTemperatureSensorData()
{
    sendData.len = 8+1;
    sendData.deviceID = 0x80;
    sendData.data[0] = 0x01;
    sendDataToSerialPort();
}

void SerialPortProtocol::getHumiditySensorData()
{
    sendData.len = 8+1;
    sendData.deviceID = 0x81;
    sendData.data[0] = 0x01;
    sendDataToSerialPort();
}

void SerialPortProtocol::getLightIntensitySensorData()
{
    sendData.len = 8+1;
    sendData.deviceID = 0x82;
    sendData.data[0] = 0x01;
    sendDataToSerialPort();
}

void SerialPortProtocol::getUltravioletSensorData()
{
    sendData.len = 8+1;
    sendData.deviceID = 0x83;
    sendData.data[0] = 0x01;
    sendDataToSerialPort();
}

void SerialPortProtocol::getCo2ConcentrationSensorData()
{
    sendData.len = 8+1;
    sendData.deviceID = 0x84;
    sendData.data[0] = 0x01;
    sendDataToSerialPort();
}

void SerialPortProtocol::getPm25ConcentrationSensorData()
{
    sendData.len = 8+1;
    sendData.deviceID = 0x85;
    sendData.data[0] = 0x01;
    sendDataToSerialPort();
}

void SerialPortProtocol::getPm10ConcentrationSensorData()
{
    sendData.len = 8+1;
    sendData.deviceID = 0x86;
    sendData.data[0] = 0x01;
    sendDataToSerialPort();
}

void SerialPortProtocol::getAtmosphereSensorData()
{
    sendData.len = 8+1;
    sendData.deviceID = 0x87;
    sendData.data[0] = 0x01;
    sendDataToSerialPort();
}

void SerialPortProtocol::getIntReserve1SensorData()
{
    sendData.len = 8+1;
    sendData.deviceID = 0x88;
    sendData.data[0] = 0x01;
    sendDataToSerialPort();
}

void SerialPortProtocol::getIntReserve2SensorData()
{
    sendData.len = 8+1;
    sendData.deviceID = 0x89;
    sendData.data[0] = 0x01;
    sendDataToSerialPort();
}

void SerialPortProtocol::getFire1SensorData()
{
    sendData.len = 8+1;
    sendData.deviceID = 0xA0;
    sendData.data[0] = 0x01;
    sendDataToSerialPort();
}

void SerialPortProtocol::getMq51SensorData()
{
    sendData.len = 8+1;
    sendData.deviceID = 0xA1;
    sendData.data[0] = 0x01;
    sendDataToSerialPort();
}

void SerialPortProtocol::getMq21SensorData()
{
    sendData.len = 8+1;
    sendData.deviceID = 0xA2;
    sendData.data[0] = 0x01;
    sendDataToSerialPort();
}

void SerialPortProtocol::getOs1SensorData()
{
    sendData.len = 8+1;
    sendData.deviceID = 0xA3;
    sendData.data[0] = 0x01;
    sendDataToSerialPort();
}

void SerialPortProtocol::getRe1SensorData()
{
    sendData.len = 8+1;
    sendData.deviceID = 0xA4;
    sendData.data[0] = 0x01;
    sendDataToSerialPort();
}

void SerialPortProtocol::getBoolReserve1SensorData()
{
    sendData.len = 8+1;
    sendData.deviceID = 0xA5;
    sendData.data[0] = 0x01;
    sendDataToSerialPort();
}

void SerialPortProtocol::getBoolReserve2SensorData()
{
    sendData.len = 8+1;
    sendData.deviceID = 0xA6;
    sendData.data[0] = 0x01;
    sendDataToSerialPort();
}

void SerialPortProtocol::getBoolReserve3SensorData()
{
    sendData.len = 8+1;
    sendData.deviceID = 0xA7;
    sendData.data[0] = 0x01;
    sendDataToSerialPort();
}

void SerialPortProtocol::getBoolReserve4SensorData()
{
    sendData.len = 8+1;
    sendData.deviceID = 0xA8;
    sendData.data[0] = 0x01;
    sendDataToSerialPort();
}

void SerialPortProtocol::getBoolReserve5SensorData()
{
    sendData.len = 8+1;
    sendData.deviceID = 0xA9;
    sendData.data[0] = 0x01;
    sendDataToSerialPort();
}

void SerialPortProtocol::readFromSerialSlot(const QByteArray &data)
{
    for(int i = 0; i < data.length(); i++)
    {
        //帧头
        if((unsigned char)data.at(i) == 0xFE && readLen > 0)
        {
            if(tempData[readLen-1] == 0xFE)
            {
                tempData[0] = 0xFE;
                tempData[1] = 0xFE;
                readLen = 2;
                continue;
            }
        }
        //帧尾
        if(readLen >= 8 && readLen+1 == tempData[5]
                && (unsigned char)data.at(i) == 0xFF)
        {
            tempData[readLen++] = 0xFF;
            //一帧完整的数据接收成功
            oneFrameReadData();
            readLen = 0;
            return;
        }
        //普通数据
        tempData[readLen++] = data.at(i);
    }
}

//网关定时向设备请求传感数据
void SerialPortProtocol::updateTimerTimeoutSlot()
{
    static int getSensingDataIndex = 0;
    switch (getSensingDataIndex) {
    case 0:
        getTemperatureSensorData();
        getSensingDataIndex++;
        break;
    case 1:
        getHumiditySensorData();
        getSensingDataIndex++;
        break;
    case 2:
        getLightIntensitySensorData();
        getSensingDataIndex++;
        break;
    case 3:
        getUltravioletSensorData();
        getSensingDataIndex++;
        break;
    case 4:
        getCo2ConcentrationSensorData();
        getSensingDataIndex++;
        break;
    case 5:
        getPm25ConcentrationSensorData();
        getSensingDataIndex++;
        break;
    case 6:
        getPm10ConcentrationSensorData();
        getSensingDataIndex++;
        break;
    case 7:
        getAtmosphereSensorData();
        getSensingDataIndex++;
        break;
    case 8:
        getIntReserve1SensorData();
        getSensingDataIndex++;
        break;
    case 9:
        getIntReserve2SensorData();
        getSensingDataIndex++;
        break;
    case 10:
        getFire1SensorData();
        getSensingDataIndex++;
        break;
    case 11:
        getMq51SensorData();
        getSensingDataIndex++;
        break;
    case 12:
        getMq21SensorData();
        getSensingDataIndex++;
        break;
    case 13:
        getOs1SensorData();
        getSensingDataIndex++;
        break;
    case 14:
        getRe1SensorData();
        getSensingDataIndex++;
        break;
    case 15:
        getBoolReserve1SensorData();
        getSensingDataIndex++;
        break;
    case 16:
        getBoolReserve2SensorData();
        getSensingDataIndex++;
        break;
    case 17:
        getBoolReserve3SensorData();
        getSensingDataIndex++;
        break;
    case 18:
        getBoolReserve4SensorData();
        getSensingDataIndex++;
        break;
    case 19:
        getBoolReserve5SensorData();
        getSensingDataIndex++;
        break;
    default:
        getSensingDataIndex=0;
        break;
    }
}

void SerialPortProtocol::sendDataToSerialPort()
{
    QByteArray data;
    data.append((char *)sendData.head,2);
    data.append((char *)sendData.retain,3);
    data.append(sendData.len);
    data.append(sendData.deviceID);
    data.append((char *)sendData.data,sendData.len-8);
    data.append(sendData.foot);
    SerialPortDev::getObject()->writeToSerial(data);
}

void SerialPortProtocol::oneFrameReadData()
{
    readData.head[0] = tempData[0];
    readData.head[1] = tempData[1];
    readData.retain[0] = tempData[2];
    readData.retain[1] = tempData[3];
    readData.retain[2] = tempData[4];
    readData.len = tempData[5];
    readData.deviceID = tempData[6];
    for(int i = 7; i < readData.len - 1; i++)
    {
        readData.data[i-7] = tempData[i];
    }
    readData.foot = 0xFF;
    handleReadData();
}

void SerialPortProtocol::handleReadData()
{
    switch (readData.deviceID) {
    case 0x80:
        if(readData.data[0] == 0x01)
            te1 = readData.data[1] + (double)readData.data[2] / 100.0;
        break;
    case 0x81:
        if(readData.data[0] == 0x01)
            hu1 = readData.data[1] + (double)readData.data[2] / 100.0;
        break;
    case 0x82:
        if(readData.data[0] == 0x01)
            light1 = readData.data[1] << 8 | readData.data[2];
        break;
    case 0x83:
        if(readData.data[0] == 0x01)
            uv1 = readData.data[1];
        break;
    case 0x84:
        if(readData.data[0] == 0x01)
            co21 = readData.data[1] << 8 | readData.data[2];
        break;
    case 0x85:
        if(readData.data[0] == 0x01)
            pm251 = readData.data[1] << 8 | readData.data[2];
        break;
    case 0x86:
        if(readData.data[0] == 0x01)
            pm101 = readData.data[1] << 8 | readData.data[2];
        break;
    case 0x87:
        if(readData.data[0] == 0x01)
            atmospheric1 = readData.data[1];
        break;
    case 0x88:
        if(readData.data[0] == 0x01)
            iReserve1 = readData.data[1];
        break;
    case 0x89:
        if(readData.data[0] == 0x01)
            iReserve2 = readData.data[1];
        break;

    case 0xA0:
        if(readData.data[0] == 0x01)
            fire1 = readData.data[1] == 0x01 ? true : false;
        break;
    case 0xA1:
        if(readData.data[0] == 0x01)
            mq51 = readData.data[1] == 0x01 ? true : false;
        break;
    case 0xA2:
        if(readData.data[0] == 0x01)
            mq21 = readData.data[1] == 0x01 ? true : false;
        break;
    case 0xA3:
        if(readData.data[0] == 0x01)
            os1 = readData.data[1] == 0x01 ? true : false;
        break;
    case 0xA4:
        if(readData.data[0] == 0x01)
            re1 = readData.data[1] == 0x01 ? true : false;
        break;
    case 0xA5:
        if(readData.data[0] == 0x01)
            bReserve1 = readData.data[1] == 0x01 ? true : false;
        break;
    case 0xA6:
        if(readData.data[0] == 0x01)
            bReserve2 = readData.data[1] == 0x01 ? true : false;
        break;
    case 0xA7:
        if(readData.data[0] == 0x01)
            bReserve3 = readData.data[1] == 0x01 ? true : false;
        break;
    case 0xA8:
        if(readData.data[0] == 0x01)
            bReserve4 = readData.data[1] == 0x01 ? true : false;
        break;
    case 0xA9:
        if(readData.data[0] == 0x01)
            bReserve5 = readData.data[1] == 0x01 ? true : false;
        break;
    default:
        break;
    }
}
