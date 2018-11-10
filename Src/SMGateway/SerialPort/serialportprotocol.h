/*
 * ClassName: SerialPortProtocol
 * Description: 串口协议类
 *
 * Author: Albert
 * Version: V0.1
 * Date: 2018.09.20
 * Version Description:
 *          【2018.09.27】 V0.1
 *              1.创建该类。
 *              2.更改该类为单例类。
 */
#ifndef SERIALPORTPROTOCOL_H
#define SERIALPORTPROTOCOL_H

#include <QObject>
#include <QTimer>
#define FRAMEDATAMAXLEN 1024

typedef struct
{
    quint8 head[2];
    quint8 retain[3];
    quint8 len;
    quint8 deviceID;
    quint8 data[FRAMEDATAMAXLEN];
    quint8 foot;
}Frame;

class SerialPortProtocol : public QObject
{
    Q_OBJECT
private:
    explicit SerialPortProtocol(QObject *parent = nullptr);

public:
    static SerialPortProtocol * getObject();

    void setAir(int index,int modle,int te,int fun);
    void setLed(int index,int b);
    void setHeart(int index,int te);
    void setCurtains(int index,int pos);

    void getTemperatureSensorData();
    void getHumiditySensorData();
    void getLightIntensitySensorData();
    void getUltravioletSensorData();
    void getCo2ConcentrationSensorData();
    void getPm25ConcentrationSensorData();
    void getPm10ConcentrationSensorData();
    void getAtmosphereSensorData();
    void getIntReserve1SensorData();
    void getIntReserve2SensorData();

    void getFire1SensorData();
    void getMq51SensorData();
    void getMq21SensorData();
    void getOs1SensorData();
    void getRe1SensorData();
    void getBoolReserve1SensorData();
    void getBoolReserve2SensorData();
    void getBoolReserve3SensorData();
    void getBoolReserve4SensorData();
    void getBoolReserve5SensorData();

    double te1 = 0;
    double hu1 = 0;
    int light1 = 0;
    int uv1 = 0;
    int co21 = 0;
    int pm251 = 0;
    int pm101 = 0;
    int atmospheric1 = 0;
    int iReserve1 = 0;
    int iReserve2 = 0;

    bool fire1 = true;
    bool mq51 = true;
    bool mq21 = true;
    bool os1 = true;
    bool re1 = true;
    bool bReserve1 = true;
    bool bReserve2 = true;
    bool bReserve3 = true;
    bool bReserve4 = true;
    bool bReserve5 = true;

protected slots:
    void readFromSerialSlot(const QByteArray &data);
    void updateTimerTimeoutSlot();

protected:
    void sendDataToSerialPort();
    void oneFrameReadData();
    void handleReadData();

    Frame sendData;
    Frame readData;
    quint8 tempData[FRAMEDATAMAXLEN+8];
    int readLen = 0;
    QTimer *updateTimer;

};

#endif // SERIALPORTPROTOCOL_H
