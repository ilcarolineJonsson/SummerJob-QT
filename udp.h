#ifndef UDP_H
#define UDP_H

#include <QObject>
#include <QUdpSocket>

class UDP : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double measurement READ measurement WRITE setMeasurement NOTIFY measurementChanged)

public:
    explicit UDP(QObject *parent = 0);
    Q_INVOKABLE void dataUDP();
    Q_INVOKABLE void data2UDP();
    Q_INVOKABLE qint64 round(double rounder);
    double measurement(){return meas;}
    void setMeasurement(double ms);

signals:

    void packageRecieved(double ma);
    void measurementChanged();

public slots:
    void readyRead();
    void listening();
    bool recieved(bool r);

private:
    QUdpSocket *socket;
    double meas;
};

#endif // UDP_H
