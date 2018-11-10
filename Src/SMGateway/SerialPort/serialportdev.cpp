#include <QSerialPort>
#include <QSerialPortInfo>
#include "serialportdev.h"

SerialPortDev::SerialPortDev(QObject *parent) : QObject(parent)
{
    serial = new QSerialPort;

    connect(serial,SIGNAL(readyRead()),
            this,SLOT(serialReadyReadSlot()));

}

SerialPortDev *SerialPortDev::getObject()
{
    static SerialPortDev spd;
    return &spd;
}

bool SerialPortDev::openSerial(const QString &portName, quint16 baudRate)
{
    closeSerial();
    serial->setPortName(portName);
    serial->setBaudRate(baudRate);
    serial->setDataBits(QSerialPort::Data8);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setParity(QSerialPort::NoParity);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    return serial->open(QIODevice::ReadWrite);
}

void SerialPortDev::closeSerial()
{
    if(serial->isOpen())
        serial->close();
}

bool SerialPortDev::writeToSerial(const QByteArray &data)
{
    if( !getSerialState() )
        return false;
    qint64 len = serial->write(data);
    if(len == -1)
        return false;
    return true;
}

bool SerialPortDev::getSerialState()
{
    return serial->isOpen();
}

void SerialPortDev::serialReadyReadSlot()
{
    QByteArray data = serial->readAll();
    emit readFromSerial(data);
}
