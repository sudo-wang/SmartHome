#ifndef NETWORKPROTOCOL_H
#define NETWORKPROTOCOL_H

#include <QObject>
#include <QTimer>

class NetWorkProtocol : public QObject
{
    Q_OBJECT
private:
    explicit NetWorkProtocol(QObject *parent = nullptr);

public:
    static NetWorkProtocol *getObject();
    void sendSensingData(QJsonObject obj);

protected slots:
    void readDataSlot(const QByteArray &data);
    void updateTimerTimeoutSlot();

protected:
    void handleData(const QJsonObject &obj);

    int braNum = 0;
    char lastChar = ' ';
    QByteArray readBuffer;
    QTimer *updateTimer;
};

#endif // NETWORKPROTOCOL_H
