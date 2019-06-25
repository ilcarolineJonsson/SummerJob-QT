#include "udp.h"

// myudp.cpp

#include "udp.h"

#include <dos.h> //for delay
#include <conio.h> //for getch()


UDP::UDP(QObject *parent) :
    QObject(parent)
{

    // create a QUDP socket
    socket = new QUdpSocket(this);

    // The most common way to use QUdpSocket class is
    // to bind to an address and port using bind()
    // bool QAbstractSocket::bind(const QHostAddress & address,
    //     quint16 port = 0, BindMode mode = DefaultForPlatform)
    socket->bind(QHostAddress::Any, 1234);

    connect(socket, SIGNAL(readyRead()), this, SLOT(listening()));
}


void UDP::dataUDP()
{
    QByteArray Data,Data1,Data2;

    Data.append("150");
    socket->writeDatagram(Data, QHostAddress::LocalHost, 1234);
    Data1.append("80");
    //socket->writeDatagram(Data1, QHostAddress::LocalHost, 1234);
    Data2.append("20");
    //socket->writeDatagram(Data2, QHostAddress::LocalHost, 1234);



}

qint64 UDP::round(double rounder){

    qint64 roundedValue = qRound64(rounder);
    return roundedValue;
}



void UDP::data2UDP()
{
    QByteArray Data;

    Data.append("80");
    socket->writeDatagram(Data, QHostAddress::LocalHost, 1234);



}

void UDP::listening()
{
                QByteArray buffer;
                buffer.resize(socket->pendingDatagramSize());
               //buffer.resize(8192);
                socket->readDatagram(buffer.data(), buffer.size());
                qDebug() << "Message Received";
                //qDebug() << "Message: " << buffer;
                double datapackage = buffer.toDouble();
                qDebug() << datapackage;
                setMeasurement(datapackage);



}

void UDP:: setMeasurement(double ms){
    meas=ms;
    emit measurementChanged();
}


bool UDP::recieved(bool r){

    return r;
}

void UDP::readyRead()
{
    // when data comes in
    QByteArray buffer;
    buffer.resize(socket->pendingDatagramSize());

    QHostAddress sender;
    quint16 senderPort;

    // qint64 QUdpSocket::readDatagram(char * data, qint64 maxSize,
    //                 QHostAddress * address = 0, quint16 * port = 0)
    // Receives a datagram no larger than maxSize bytes and stores it in data.
    // The sender's host address and port is stored in *address and *port
    // (unless the pointers are 0).

    socket->readDatagram(buffer.data(), buffer.size(),
                         &sender, &senderPort);


    qDebug() << "Message from: " << sender.toString();
    qDebug() << "Message port: " << senderPort;
    qDebug() << "Message: " << buffer;
}

