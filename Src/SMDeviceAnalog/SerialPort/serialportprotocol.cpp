#include <QDebug>
#include "serialportprotocol.h"
#include "serialportdev.h"

SerialPortProtocol::SerialPortProtocol(QObject *parent) : QObject(parent)
{
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

void SerialPortProtocol::sendTemperatureSensorData(double temperature)
{
    sendData.len = 8+3;
    sendData.deviceID = 0x80;
    int integer = temperature;
    int decimal = (temperature - integer) * 100;
    sendData.data[0] = 0x01;     //序号
    sendData.data[1] = integer;
    sendData.data[2] = decimal;
    sendDataToSerialPort();
}

void SerialPortProtocol::sendHumiditySensorData(double humidity)
{
    sendData.len = 8+3;
    sendData.deviceID = 0x81;
    int integer = humidity;
    int decimal = (humidity - (double)integer) * 100;
    sendData.data[0] = 0x01;     //序号
    sendData.data[1] = integer;
    sendData.data[2] = decimal;
    sendDataToSerialPort();
}

void SerialPortProtocol::sendLightIntensitySensorData(int intensity)
{
    sendData.len = 8+3;
    sendData.deviceID = 0x82;
    sendData.data[0] = 0x01;
    sendData.data[1] = intensity >> 8;
    sendData.data[2] = intensity;
    sendDataToSerialPort();
}

void SerialPortProtocol::sendUltravioletSensorData(int ultraviolet)
{
    sendData.len = 8+2;
    sendData.deviceID = 0x83;
    sendData.data[0] = 0x01;
    sendData.data[1] = ultraviolet;
    sendDataToSerialPort();
}

void SerialPortProtocol::sendCo2ConcentrationSensorData(int concentration)
{
    sendData.len = 8+3;
    sendData.deviceID = 0x84;
    sendData.data[0] = 0x01;
    sendData.data[1] = concentration >> 8;
    sendData.data[2] = concentration;
    sendDataToSerialPort();
}

void SerialPortProtocol::sendPm25ConcentrationSensorData(int concentration)
{
    sendData.len = 8+3;
    sendData.deviceID = 0x85;
    sendData.data[0] = 0x01;
    sendData.data[1] = concentration >> 8;
    sendData.data[2] = concentration;
    sendDataToSerialPort();
}

void SerialPortProtocol::sendPm10ConcentrationSensorData(int concentration)
{
    sendData.len = 8+3;
    sendData.deviceID = 0x86;
    sendData.data[0] = 0x01;
    sendData.data[1] = concentration >> 8;
    sendData.data[2] = concentration;
    sendDataToSerialPort();
}

void SerialPortProtocol::sendAtmosphereSensorData(int atmosphere)
{
    sendData.len = 8+2;
    sendData.deviceID = 0x87;
    sendData.data[0] = 0x01;
    sendData.data[1] = atmosphere;
    sendDataToSerialPort();
}

void SerialPortProtocol::sendIntReserve1SensorData(int value)
{
    sendData.len = 8+2;
    sendData.deviceID = 0x88;
    sendData.data[0] = 0x01;
    sendData.data[1] = value;
    sendDataToSerialPort();
}

void SerialPortProtocol::sendIntReserve2SensorData(int value)
{
    sendData.len = 8+2;
    sendData.deviceID = 0x89;
    sendData.data[0] = 0x01;
    sendData.data[1] = value;
    sendDataToSerialPort();
}

void SerialPortProtocol::sendFire1SensorData(bool isAbnormal)
{
    sendData.len = 8+2;
    sendData.deviceID = 0xA0;
    sendData.data[0] = 0x01;
    sendData.data[1] = isAbnormal ? 0x01 : 0x00;
    sendDataToSerialPort();
}

void SerialPortProtocol::sendMq51SensorData(bool isAbnormal)
{
    sendData.len = 8+2;
    sendData.deviceID = 0xA1;
    sendData.data[0] = 0x01;
    sendData.data[1] = isAbnormal ? 0x01 : 0x00;
    sendDataToSerialPort();
}

void SerialPortProtocol::sendMq21SensorData(bool isAbnormal)
{
    sendData.len = 8+2;
    sendData.deviceID = 0xA2;
    sendData.data[0] = 0x01;
    sendData.data[1] = isAbnormal ? 0x01 : 0x00;
    sendDataToSerialPort();
}

void SerialPortProtocol::sendOs1SensorData(bool isAbnormal)
{
    sendData.len = 8+2;
    sendData.deviceID = 0xA3;
    sendData.data[0] = 0x01;
    sendData.data[1] = isAbnormal ? 0x01 : 0x00;
    sendDataToSerialPort();
}

void SerialPortProtocol::sendRe1SensorData(bool isAbnormal)
{
    sendData.len = 8+2;
    sendData.deviceID = 0xA4;
    sendData.data[0] = 0x01;
    sendData.data[1] = isAbnormal ? 0x01 : 0x00;
    sendDataToSerialPort();
}

void SerialPortProtocol::sendBoolReserve1SensorData(bool isAbnormal)
{
    sendData.len = 8+2;
    sendData.deviceID = 0xA5;
    sendData.data[0] = 0x01;
    sendData.data[1] = isAbnormal ? 0x01 : 0x00;
    sendDataToSerialPort();
}

void SerialPortProtocol::sendBoolReserve2SensorData(bool isAbnormal)
{
    sendData.len = 8+2;
    sendData.deviceID = 0xA6;
    sendData.data[0] = 0x01;
    sendData.data[1] = isAbnormal ? 0x01 : 0x00;
    sendDataToSerialPort();
}

void SerialPortProtocol::sendBoolReserve3SensorData(bool isAbnormal)
{
    sendData.len = 8+2;
    sendData.deviceID = 0xA7;
    sendData.data[0] = 0x01;
    sendData.data[1] = isAbnormal ? 0x01 : 0x00;
    sendDataToSerialPort();
}

void SerialPortProtocol::sendBoolReserve4SensorData(bool isAbnormal)
{
    sendData.len = 8+2;
    sendData.deviceID = 0xA8;
    sendData.data[0] = 0x01;
    sendData.data[1] = isAbnormal ? 0x01 : 0x00;
    sendDataToSerialPort();
}

void SerialPortProtocol::sendBoolReserve5SensorData(bool isAbnormal)
{
    sendData.len = 8+2;
    sendData.deviceID = 0xA9;
    sendData.data[0] = 0x01;
    sendData.data[1] = isAbnormal ? 0x01 : 0x00;
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
    case 0x01:
        //空调
        if(readData.len - 8 != 4)
            break;
        emit newAirConditionerControl(readData.data[0],readData.data[1],readData.data[2],readData.data[3]);
        break;
    case 0x02:
        if(readData.len - 8 != 2)
            break;
        emit newLedControl(readData.data[0],readData.data[1]);
        break;
    case 0x04:
        if(readData.len - 8 != 2)
            break;
        emit newHeaterControl(readData.data[0],readData.data[1]);
        break;
    case 0x06:
        if(readData.len - 8 != 2)
            break;
        emit newCurtainsControl(readData.data[0],readData.data[1]);
        break;
    case 0x80:
        if(readData.data[0] == 0x01)
            sendTemperatureSensorData(te1);
        break;
    case 0x81:
        if(readData.data[0] == 0x01)
            sendHumiditySensorData(hu1);
        break;
    case 0x82:
        if(readData.data[0] == 0x01)
            sendLightIntensitySensorData(light1);
        break;
    case 0x83:
        if(readData.data[0] == 0x01)
            sendUltravioletSensorData(uv1);
        break;
    case 0x84:
        if(readData.data[0] == 0x01)
            sendCo2ConcentrationSensorData(co21);
        break;
    case 0x85:
        if(readData.data[0] == 0x01)
            sendPm25ConcentrationSensorData(pm251);
        break;
    case 0x86:
        if(readData.data[0] == 0x01)
            sendPm10ConcentrationSensorData(pm101);
        break;
    case 0x87:
        if(readData.data[0] == 0x01)
            sendAtmosphereSensorData(atmospheric1);
        break;
    case 0x88:
        if(readData.data[0] == 0x01)
            sendIntReserve1SensorData(iReserve1);
        break;
    case 0x89:
        if(readData.data[0] == 0x01)
            sendIntReserve2SensorData(iReserve2);
        break;

    case 0xA0:
        if(readData.data[0] == 0x01)
            sendFire1SensorData(fire1);
        break;
    case 0xA1:
        if(readData.data[0] == 0x01)
            sendMq51SensorData(mq51);
        break;
    case 0xA2:
        if(readData.data[0] == 0x01)
            sendMq21SensorData(mq21);
        break;
    case 0xA3:
        if(readData.data[0] == 0x01)
            sendOs1SensorData(os1);
        break;
    case 0xA4:
        if(readData.data[0] == 0x01)
            sendRe1SensorData(re1);
        break;
    case 0xA5:
        if(readData.data[0] == 0x01)
            sendBoolReserve1SensorData(bReserve1);
        break;
    case 0xA6:
        if(readData.data[0] == 0x01)
            sendBoolReserve2SensorData(bReserve2);
        break;
    case 0xA7:
        if(readData.data[0] == 0x01)
            sendBoolReserve3SensorData(bReserve3);
        break;
    case 0xA8:
        if(readData.data[0] == 0x01)
            sendBoolReserve4SensorData(bReserve4);
        break;
    case 0xA9:
        if(readData.data[0] == 0x01)
            sendBoolReserve5SensorData(bReserve5);
        break;
    default:
        break;
    }
}
