/*
 * ClassName: SerialPortDev
 * Description: 串口驱动类
 *
 * Author: Albert
 * Version: V0.1
 * Date: 2018.09.20
 * Version Description:
 *          【2018.09.20】 V0.1
 *              1.创建该类。
 *              2.更改该类为单例类。
 *              3.打开指定串口
 *              4.关闭串口
 *              5.发送数据
 *              6.获取串口状态
 *              7.接收数据
 */
#ifndef SERIALPORTDEV_H
#define SERIALPORTDEV_H

#include <QObject>

class QSerialPort;

class SerialPortDev : public QObject
{
    Q_OBJECT
private:
    explicit SerialPortDev(QObject *parent = nullptr);

public:
    //[static]获取单例类
    //@return SerialPortDev * 获取到的单例类
    static SerialPortDev *getObject();
    //打开串口
    //@param portName 串口名称
    //@param baudRate 波特率
    //@return bool 打开结果
    bool openSerial(const QString &portName,quint16 baudRate);
    //关闭串口2
    void closeSerial();
    //向串口发送数据
    //@param data 要发送的数据
    //@return bool 发送的结果
    bool writeToSerial(const QByteArray &data);
    //获取串口的状态
    //@return bool 连接状态
    bool getSerialState();

signals:
    //从串口接收到数据
    //@param data 接收到的数据
    void readFromSerial(const QByteArray &data);

protected slots:
    void serialReadyReadSlot();

protected:
    QSerialPort *serial;
};

#endif // SERIALPORTDEV_H
